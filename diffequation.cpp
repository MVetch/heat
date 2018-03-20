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
}

diffEquation::~diffEquation(){
    //delete u;
}

double diffEquation::f(double phi){
    return 1000000 * 0.85 / focus.getStrip().getC() / focus.getStrip().getRho() * Kdef() * qLn(focus.getHBefore() / focus.getHAfter());
}
double diffEquation::q(int i){
    double f_h = 0.000059;//метров
    double e_h = 1.72;
    double nu = 0.42;
    double F = 3.047;//килограмм-сила. в маткаде даны в тоннах-силе
    double W = 1.357;
    double k_f = Kdef();
    double lambda_com = (focus.getStrip().getLambda() * focus.getRoll().getLambda())/(focus.getStrip().getLambda() + focus.getRoll().getLambda());
    double hCond = lambda_com / f_h * qPow((F / (3 * W * focus.length * k_f)), e_h);
    double v_wr_in =  73.0  / 60.0;//метров в секунду
    double v_wr_out = 150.0 / 60.0;//метров в секунду
    double v_rel = v_wr_in - (v_wr_out * focus.getHAfter()) /
                             (qCos(i * theta) * (focus.getHAfter() +
                                                    2 * focus.getRoll().getR() * (1-qCos(i*theta))
                                                )
                              );
    double q_fric = nu * F/(W*focus.length) * qAbs(v_rel);
    double q_cond = hCond*(u[i-1][Mcont+10] - u[i-1][Mcont-10]);
    return q_cond - q_fric;
}

double diffEquation::Kdef(){
    double aSt = 0.124, bSt = 0.167, cSt = -2.54, sSt = 0.96;
    double deltaY0 = 90.7;
    double Ts = 1000;
    double v_wr_in =  73.0  / 60.0;//метров в секунду
    double u = 2.0 * v_wr_in * focus.length / (focus.getRoll().getR() * (focus.getHBefore() + focus.getHAfter()));
    return sSt * deltaY0 * qPow(u, aSt) * qPow((10 * (focus.getHBefore() - focus.getHAfter()) / focus.getHBefore()), bSt) * qPow(Ts/1000, cSt);
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
        //if(angle < beta) u[i+1][Mcur-1] = 1000;//начальная температура в глубину полосы
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
        r[Mcont] += q(i+1)*theta*(a_s + a_v)/2 / (h*(lambda_s+lambda_v)/2);
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

double diffEquation::X(double r, double phi){
    return r*qCos(phi);
}
double diffEquation::Y(double r, double phi){
    return r*qSin(phi);
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
