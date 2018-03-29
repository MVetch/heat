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
    double mu = 0.23;
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
    double lambda_v = focus.getRoll().getLambda();
    double rho_v = focus.getRoll().getRho();
    double c_v = focus.getRoll().getC();

    double lambda_s = focus.getStrip().getLambda();
    double rho_s = focus.getStrip().getRho();
    double c_s = focus.getStrip().getC();

    double a_v = lambda_v/(rho_v*c_v);
    double a_s = lambda_s/(rho_s*c_s);
    double lambda_sc = 2;
    double a_sc = lambda_sc/(rho_s*c_s);

    u.resize(N+1);
    QVector<double> d(M-1), c(M-1), b(M-1), lambda(M-1), delta(M-1), r(M-1);
    double a = 0;
    u[0].resize(M);
    double angle = 0;
    double Mcur = 0;
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
        u[i+1].resize(M);
        Mcur = qMax(MUpdate(angle, h)-1, Mcont+1);

        // граничные условия
        u[i+1][0] = focus.getRoll().initT(0); //температура в центре валка
        for(int j = Mcur; j < M; j++){
            u[i+1][j] = focus.getStrip().initT(j * h);
        }
        for(int j = 0; j < Mcur; j++){
            if(j > Mcont){
                a = a_s;
                r[j] = u[i][j] + theta*f(angle);//расчет правой части СЛАУ
            }
            else if(j == Mcont){
                a = (a_s + a_v)/2;
                r[j] = u[i][j];
            }
            else if(j == Mcont+1 && i > 0){
                a = a_sc;
                r[j] = u[i][j];
            }
            else{
                a = a_v;
                r[j] = u[i][j];
            }
            //расчет коэффициентов в матрице

            b[j] = - theta * a / (h*h);
            c[j] = 1 + 2 * theta * a / (h*h);
            d[j] = - theta * a / (h*h);
        }
        r[Mcont] += q(i)*theta*(a_s + a_v)/2 / (h*(lambda_s+lambda_v)/2);
        //r[Mcont+1] += theta*a_s / (h * lambda_s / 2);
        //c[Mcont] = 0;
        //c[Mcont+1] = 0;

        b[0] = 0;
        d[Mcur-1] = 0;
        r[0] += theta * a_v / (h*h) * focus.getRoll().initT(0); //умножить на t в центре валка

        if(angle < focus.beta)
            r[Mcur-1] += theta*a_s*u[0][Mcur-1]/(h*h);//умножить на начальное значение температуры в глубину полосы
        else
            c[Mcur-1] = 1 + theta * a_s / (h*h);

        for(int j = 0; j < Mcur; j++){
            delta[j] = - d[j]/ (c[j] + b[j]* (j==0?0:delta[j-1]));
            lambda[j] = (r[j] - b[j]* (j==0?0:lambda[j-1]))/ (c[j] + b[j] * (j==0?0:delta[j-1]));
        }

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
