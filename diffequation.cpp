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
    double pXout = Kdef(focus.phi_max) - sigmaB * 9.8;
    double mu = 0.201;
    px0.push_back(pXin);
    for(int i = 1; i < N; i++){
        px0.push_back(
            px0[i-1] + (Kdef(i * theta) - Kdef((i - 1) * theta)) + Kdef((i - 1) * theta) * focus.epsH(
                                                                                    focus.curH((i - 1) * theta),
                                                                                    focus.curH(i * theta)
                                                                                   ) + mu * theta * px0[i-1] / focus.curH(i * theta)
        );
    }
    px1.push_back(pXout);
    for(int i = 1; i < N; i++){
        px1.push_back(
            px1[i-1] - (Kdef(i * theta) - Kdef((i - 1) * theta)) + Kdef((i - 1) * theta) * focus.epsH(
                                                                                    focus.curH((N - i + 1) * theta),
                                                                                    focus.curH((N - i) * theta)
                                                                                   ) + mu * theta * px1[i-1] / focus.curH((N - i) * theta)
        );
    }
    double temp = 0;
    Nneutr = 0;
    for(int i = 0; i < N; i++){
        temp = qMin(px0[i], px1[N - i - 1]);
        if(temp == px1[N - i - 1] && Nneutr == 0) Nneutr = i-1;

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
    for(int i = Nneutr; i < N; i++){
        temp = -qMin(tauContAbs[i], tauShear[i]);
        tauCont.push_back(-temp);
        if(temp == -tauContAbs[i] && NForward == 0) NForward = i-1;
    }
}

diffEquation::~diffEquation(){
    //delete u;
}

double diffEquation::f(double phi){
    return 1000000 * 0.85 / focus.getStrip().getC() / focus.getStrip().getRho() * Kdef(phi) * qLn(focus.getHBefore() / focus.getHAfter());
}
double diffEquation::q(int i){

    //if(i > NBack && i < NForward) return 0;
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

    double a_wr = lambda_wr/(rho_wr*c_wr);
    double a_s = lambda_s/(rho_s*c_s);
    double lambda_sc = focus.getScale().lambda;
    double a_sc = lambda_sc/(rho_s*c_s);

    u.resize(N+1);
    QVector<double> d(M-1), c(M-1), b(M-1), lambda(M-1), delta(M-1), r(M-1);
    double a = 0;
    u[0].resize(M);
    double angle = 0;
    double Mcur = 0;

    double beta1 = (lambda_wr/h)/(lambda_wr/h + lambda_sc/focus.getScale().thickness);
    double beta2 = (lambda_sc/focus.getScale().thickness)/(lambda_wr/h + lambda_sc/focus.getScale().thickness);
    double beta3 = (lambda_sc/focus.getScale().thickness)/(lambda_s /h + lambda_sc/focus.getScale().thickness);
    double beta4 = (lambda_s/h)/(lambda_s/h + lambda_sc/focus.getScale().thickness);

    double b_s = -theta * a_s / (h*h);
    double cm_s = 1 + 2 * theta * a_wr / (h*h);
    double d_s = -theta * a_s / (h*h);

    double b_wr = -theta * a_wr / (h*h);
    double cm_wr = 1 + 2 * theta * a_wr / (h*h);
    double d_wr = -theta * a_wr / (h*h);

    double b_mcontm1 = b_wr;
    double c_mcontm1 = c_wr - (theta * a_wr*beta1)/(h*h*(1-beta2*beta3));
    double d_mcontm1 = d_s * beta2 * beta4 / (h*h*(1-beta2*beta3));

    double b_mcontp2 = b_wr * beta1 * beta3 / (h*h*(1-beta2*beta3));
    double c_mcontp2 = c_s - (theta * a_s * beta4)/(h*h*(1-beta2*beta3));
    double d_mcontp2 = d_s;

    double b, cm, d;

    for(int j = 0; j < M; j++) // значения на нулевом слое
    {
        if(j < Mcont+1)
            u[0][j] = focus.getRoll().initT(j * h);//температура вглубь валка
        else
            u[0][j] = focus.getStrip().initT(j * h);//температура в полосе
    }
    u[0][Mcont] = (u[0][Mcont-1] + u[0][Mcont+1])/2;
    for(int i = 0; i < N; i++){ // значения на остальных слоях
        angle = i*theta;
        u[i+1].resize(M-2);
        Mcur = qMax(MUpdate(angle, h)-1, Mcont+1)-2;

        // граничные условия
        u[i+1][0] = focus.getRoll().initT(0); //температура в центре валка
        for(int j = Mcur; j < M-2; j++){
            u[i+1][j] = focus.getStrip().initT(j * h);
        }
        r[j] = u[i][j];
        for(int j = 0; j < Mcur; j++){
            if(j >= Mcont){
                r[j] += theta*f(angle);//расчет правой части СЛАУ
            }
        }
        r[Mcont - 1] += q(i) * theta * a_wr / (h * h);
        r[Mcont] += q(i) * theta * a_s * beta3 / (h * h * (1 - beta2 * beta3));
        //r[Mcont+1] += theta*a_s / (h * lambda_s / 2);
        //c[Mcont] = 0;
        //c[Mcont+1] = 0;

        r[0] += theta * a_wr / (h*h) * focus.getRoll().initT(0); //умножить на t в центре валка

        if(angle <= focus.beta)
            r[Mcur-1] += theta*a_s*u[0][Mcur-1]/(h*h);//умножить на начальное значение температуры в глубину полосы

        for(int j = 0; j < Mcur; j++){
            if(j < Mcont-1){
                b = b_wr;
                c = c_wr;
                d = d_wr;
            } else if (j == Mcont - 1) {
                b = b_mcontm1;
                c = c_mcontm1;
                d = d_mcontm1;
            } else if (j == Mcont) {
                b = b_mcontp2;
                c = c_mcontp2;
                d = d_mcontp2;
            } else {
                b = b_s;
                c = c_s;
                d = d_s;
            }
            delta[j] = - d / (c + b * (j==0?0:delta[j-1]));
            lambda[j] = (r - b * (j==0?0:lambda[j-1]))/ (c + b * (j==0?0:delta[j-1]));
        }
        delta[Mcur - 1] = 0;
        for(int j = Mcur-1; j > 0; j--){
            u[i+1][j] = delta[j] * u[i+1][j+1] + lambda[j];
        }
        if(angle >= focus.beta)
            u[i+1][Mcur] = u[i+1][Mcur-1];
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
