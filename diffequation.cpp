#include "diffequation.h"

diffEquation::diffEquation(
        int M,
        int N,
        Focus f
)
{
    this->M = M;
    this->N = N;
    this->focus = f;

    this->h = (focus.r_max - focus.getRoll().getR() + focus.getRoll().countmmToHeat())/M;
    this->theta = focus.phi_max/N;
    this->Mcont = MUpdate(0, h);

    double sigmaF = 0.059;
    double sigmaB = 0.05;
    double pXin = Kdef(0) - sigmaB * 9.8;
    double pXout = Kdef(focus.phi_max) - sigmaF * 9.8;
    double mu = 0.24;
    px0.push_back(pXin);
    for(int i = 1; i <= N; i++){
        px0.push_back(
            px0[i-1] + (Kdef(i * theta) - Kdef((i - 1) * theta)) + Kdef((i - 1) * theta) * focus.epsH(
                                                                                    focus.curH((i - 1) * theta),
                                                                                    focus.curH(i * theta)
                                                                                   ) + mu * theta * px0[i-1] / focus.curH(i * theta)
        );
    }
    px1.push_back(pXout);
    for(int i = 1; i <= N; i++){
        px1.push_back(
            px1[i-1] - (Kdef(i * theta) - Kdef((i - 1) * theta)) + Kdef((i - 1) * theta) * focus.epsH(
                                                                                    focus.curH((N - (i - 1)) * theta),
                                                                                    focus.curH((N - i) * theta)
                                                                                   ) + mu * theta * px1[i-1] / focus.curH((N - i) * theta)
        );
    }
    double temp = 0;
    Nneutr = 0;
    for(int i = 0; i <= N; i++){
        temp = qMin(px0[i], px1[N - i]);
        if(temp == px1[N - i] && Nneutr == 0) Nneutr = i-1;

        pxCont.push_back(temp);
        tauContAbs.push_back(mu * pxCont[i]);
        tauShear.push_back(Kdef(i * theta) / 1.15 / 2);
    }
    NBack = 0, NForward = 0;
    for(int i = 0; i < Nneutr; i++){
        temp = qMin(tauContAbs[i], tauShear[i]);
        tauCont.push_back(temp);
        if(temp == tauShear[i] && NBack == 0) NBack = i-1;
    }
    for(int i = Nneutr; i <= N; i++){
        temp = -qMin(tauContAbs[i], tauShear[i]);
        tauCont.push_back(-temp);
        if(-temp == tauContAbs[i] && NForward == 0) NForward = i-1;
    }
}

diffEquation::~diffEquation(){
    //delete u;
}

double diffEquation::f(int i, int j){
    return 1000000 * 0.85 / focus.getStrip().getC() / focus.getStrip().getRho() * Kdef(i * theta) * qLn(focus.getHBefore() / focus.getHAfter());
}
double diffEquation::q(int i){

    if(i > NBack && i < NForward) return 0;
    double Vwr = 73.0 / 60.0;
    double omegaSlip = Vwr * (focus.curH(Nneutr * theta) / focus.curH(i * theta) - 1);

    /*должно быть tauCont1, которое высчитывается по странной формуле*/
    double q = qAbs(tauCont[i] * omegaSlip) * 1000000;
    return q;
}

double diffEquation::Kdef(double phi){
    double aSt = 0.124, bSt = 0.167, cSt = -2.54, sSt = 0.96;
    double deltaY0 = 90.7;
    double Ts = focus.getStrip().initT(0);
    double v_wr_in =  73.0  / 60.0;//метров в секунду
    double u = 2.0 * v_wr_in * focus.length / (focus.getRoll().getR() * (focus.getHBefore() + focus.getHAfter()));
    return sSt * deltaY0 * qPow(u, aSt) * qPow(10 * focus.epsH(focus.curH(phi), focus.getHBefore()), bSt) * qPow(Ts/1000, cSt);
}

int diffEquation::MUpdate(double phi, double h){
    return qCeil((focus.maxR(phi) - focus.getRoll().getR() + focus.getRoll().countmmToHeat())/h);
}

void diffEquation::solve(){
    double lambda_wr = focus.getRoll().getLambda();
    double rho_wr = focus.getRoll().getRho();
    double c_wr = focus.getRoll().getC();

    double lambda_s = focus.getStrip().getLambda();
    double rho_s = focus.getStrip().getRho();
    double c_s = focus.getStrip().getC();

    double a_wr = lambda_wr / (rho_wr * c_wr);
    double a_s  = lambda_s  / (rho_s  * c_s );
    double lambda_sc = focus.getScale().lambda;

    u.resize(N+1);
    QVector<double> lambda(M-3), delta(M-3), r(M-3);
    u[0].resize(M-2);
    double angle = 0;
    double Mcur = 0;

    beta1 = (lambda_wr * focus.getScale().thickness) / (lambda_wr * focus.getScale().thickness + lambda_sc * h);
    beta2 = (lambda_sc * h) / (lambda_wr * focus.getScale().thickness + lambda_sc * h);
    beta3 = (lambda_sc * h) / (lambda_s  * focus.getScale().thickness + lambda_sc * h);
    beta4 = (lambda_s  * focus.getScale().thickness) / (lambda_s  * focus.getScale().thickness + lambda_sc * h);

    double bm_s = -theta * a_s / (h * h);
    double cm_s1 = 1 +     theta * a_s / (h * h);
    double cm_s2 = 1 + 2 * theta * a_s / (h * h);
    double dm_s = -theta * a_s / (h * h);

    double bm_wr = -theta * a_wr / (h * h);
    double cm_wr = 1 + 2 * theta * a_wr / (h * h);
    double dm_wr = -theta * a_wr / (h * h);

    double bm_mcontm1 = bm_wr;
    double cm_mcontm1 = cm_wr - (theta * a_wr * beta1) / (h * h * (1 - beta2 * beta3));
    double dm_mcontm1 = dm_wr * beta2 * beta4 / (1 - beta2 * beta3);

    double bm_mcontp2 = bm_s  * beta1 * beta3 / (1 - beta2 * beta3);
    double cm_mcontp2 = cm_s2 - (theta * a_s * beta4) / (h * h * (1 - beta2 * beta3));
    double dm_mcontp2 = dm_s;

    for(int j = 0; j < M - 2; j++) // значения на нулевом слое
    {
        if(j < Mcont)
            u[0][j] = focus.getRoll ().initT(j * h);//температура вглубь валка
        else
            u[0][j] = focus.getStrip().initT((j + 2) * h);//температура в полосе
    }

    for(int i = 0; i < N; i++){ // значения на остальных слоях
        angle = i * theta;
        u[i+1].resize(M - 2);
        Mcur = qMax(MUpdate(angle, h) - 2 - 2, Mcont);//тут сразу отнимаем двойку, чтобы следовать размеру матрицы А

        // граничные условия
        u[i+1][0] = focus.getRoll().initT(0); //температура в центре валка
        for(int j = Mcur-1; j < M - 2; j++){
            u[i+1][j] = focus.getStrip().initT((j + 2) * h);
        }
        for(int j = 0; j < Mcur; j++){
            r[j] = u[i][j+1];
            if(j + 1 >= Mcont){
                r[j] += theta * f(i, j + 1);//расчет правой части СЛАУ
            }
        }
        //=========Mcont - 2==========//
        r[Mcont - 2] += q(i+1) * theta * a_wr * focus.getScale().thickness         / (h * (lambda_wr * focus.getScale().thickness + lambda_sc * h)                      );
        //=========/Mcont - 2==========//

        //=========Mcont - 1==========//
        r[Mcont - 1] += q(i+1) * theta * a_s  * focus.getScale().thickness * beta3 / (h * (lambda_s  * focus.getScale().thickness + lambda_sc * h) * (1 - beta2 * beta3));
        //=========/Mcont - 1==========//

        r[0] -= bm_wr * u[0][0]; //умножить на t в центре валка

        if(angle <= focus.beta && Mcur > Mcont-2)
            r[Mcur-1] -= dm_s * u[0][Mcur];//умножить на начальное значение температуры в глубину полосы

        delta [0] = -dm_wr / cm_wr;
        lambda[0] =   r[0] / cm_wr;

        for(int j = 1; j < Mcont-2; j++) {
            delta [j] = - dm_wr                      / (cm_wr + bm_wr * delta[j-1]);
            lambda[j] = (r[j] - bm_wr * lambda[j-1]) / (cm_wr + bm_wr * delta[j-1]);
        }

        delta [Mcont - 2] = - dm_mcontm1                                    / (cm_mcontm1 + bm_mcontm1 * delta[Mcont - 3]);
        lambda[Mcont - 2] = (r[Mcont - 2] - bm_mcontm1 * lambda[Mcont - 3]) / (cm_mcontm1 + bm_mcontm1 * delta[Mcont - 3]);

        delta [Mcont - 1] = - dm_mcontp2                                    / (cm_mcontp2 + bm_mcontp2 * delta[Mcont - 2]);
        lambda[Mcont - 1] = (r[Mcont - 1] - bm_mcontp2 * lambda[Mcont - 2]) / (cm_mcontp2 + bm_mcontp2 * delta[Mcont - 2]);

        for(int j = Mcont; j < Mcur - 1; j++) {
            delta [j] = - dm_s                      / (cm_s2 + bm_s * delta[j-1]);
            lambda[j] = (r[j] - bm_s * lambda[j-1]) / (cm_s2 + bm_s * delta[j-1]);
        }

        delta [Mcur - 1] = 0;
        if(angle <= focus.beta)
            lambda[Mcur - 1] = (r[Mcur - 1] - bm_s * lambda[Mcur - 2]) / (cm_s2 + bm_s * delta[Mcur - 2]);
        else
            lambda[Mcur - 1] = (r[Mcur - 1] - bm_s * lambda[Mcur - 2]) / (cm_s1 + bm_s * delta[Mcur - 2]);

        for(int j = Mcur; j > 0; j--){
            u[i+1][j] = delta[j-1] * u[i+1][j+1] + lambda[j-1];
        }
        if(angle >= focus.beta)
            u[i+1][Mcur + 1] = u[i+1][Mcur];
    }
}

QVector<QVector<qreal>> diffEquation::getResult()
{
    return this->u;
}

double diffEquation::getResult(int i, int j)
{
    return this->u[i][j];
}

Focus diffEquation::getFocus()
{
    return this->focus;
}
