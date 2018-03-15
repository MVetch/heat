#include "diffequation.h"

diffEquation::diffEquation(
        double h,
        double theta,
        Focus f,
        double lambda_p,
        double rho_p,
        double c_p,
        double initF,
        double initQ
)
{
    this->h = h;
    this->theta = theta;
    this->focus = f;
    this->lambda_p = lambda_p;
    this->rho_p = rho_p;
    this->c_p = c_p;
    Mmax=0;

    double R = focus.getRoll().getR();
    double delta_h = focus.getHBefore() - focus.getHAfter();
    length = qSqrt(R*delta_h - delta_h*delta_h/4);
    phi_max = qAsin(length/R);
    alpha = qAtan(length/(focus.getHAfter()/2+R));
    beta = phi_max - alpha;
    r_max = qSqrt(R*R+(focus.getHBefore()*focus.getHBefore())/4+R*focus.getHBefore()*qCos(phi_max));
    this->initF = initF;
    this->initQ = initQ;
}

diffEquation::~diffEquation(){
}

double diffEquation::f(double phi){

    return initF;
}
double diffEquation::q(double phi){

    //return qMax(-phi*phi*initQ/((beta)*(beta)) + initQ, 0.0);
    return initQ;
}

int diffEquation::MUpdate(double phi, double h){
    return qCeil(maxR(phi)/h);
}

double diffEquation::maxR(double phi){
    double R = focus.getRoll().getR();
    double delta_h = focus.getHBefore() - focus.getHAfter();
    double t = qSqrt(R*delta_h - delta_h*delta_h/4);
    //return R;
    if(phi < phi_max-alpha)
        return t/qSin(phi_max-phi);
    else
        return (focus.getHAfter()/2+R)/qCos(phi_max-phi);
}

void diffEquation::solve(){
    double lambda_v = focus.getRoll().getLambda();
    double rho_v = focus.getRoll().getRho();
    double c_v = focus.getRoll().getC();

    double a_v = lambda_v/(rho_v*c_v);
    double a_p = lambda_p/(rho_p*c_p);
    double lambda_s = 2;
    double a_s = lambda_s/(rho_p*c_p);

    int M = MUpdate(beta, h), Mcont = MUpdate(0, h)-1, Mcur; // число шагов по x и точка контакта
    Mmax = M;
    int N = qRound(phi_max/theta); // число шагов по t

    u.resize(N+1);
    QVector<double> d(M-1), c(M-1), b(M-1), lambda(M-1), delta(M-1), r(M-1);
    double a = 0;
    u[0].resize(M);
    double angle = 0;
    double t_p = 1000;//температура в полосе

    for(int j = 0; j < M; j++) // значения на нулевом слое
    {
        if(j < Mcont+1)
            u[0][j] = focus.getRoll().initT(j*h);//температура вглубь валка
        else
            u[0][j] = t_p;//температура в полосе
    }
    u[0][Mcont] = (u[0][Mcont-1] + u[0][Mcont+1])/2;
    for(int i = 0; i < N; i++){ // значения на остальных слоях
        angle = i*theta;
        u[i+1].resize(M);
        Mcur = qMax(MUpdate(angle, h)-1, Mcont+1);

        // граничные условия
        u[i+1][0] = focus.getRoll().initT(0); //температура в центре валка
        for(int j = Mcur; j < M; j++){
            u[i+1][j] = t_p;
        }
        //if(angle < beta) u[i+1][Mcur-1] = 1000;//начальная температура в глубину полосы
        for(int j = 0; j < Mcur; j++){
            if(j > Mcont){
                a = a_p;
                r[j] = u[i][j] + theta*f(angle);//расчет правой части СЛАУ
            }
            else if(j == Mcont){
                a = (a_p + a_v)/2;
                r[j] = u[i][j];
            }
            else if(j == Mcont+1 && i > 0){
                a = a_s;
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
        r[Mcont] += q(angle)*theta*(a_p + a_v)/2 / (h*(lambda_p+lambda_v)/2);
        //r[Mcont+1] += theta*a_s / (h * lambda_s / 2);
        //c[Mcont] = 0;
        //c[Mcont+1] = 0;

        b[0] = 0;
        d[Mcur-1] = 0;
        r[0] += theta*a / (h*h) * focus.getRoll().initT(0); //умножить на t в центре валка

        if(angle < beta)
            r[Mcur-1] += theta*a*u[0][Mcur-1]/(h*h);//умножить на начальное значение температуры в глубину полосы
        else
            c[Mcur-1] = 1 + theta * a / (h*h);

        for(int j = 0; j < Mcur; j++){
            delta[j] = - d[j]/ (c[j] + b[j]* (j==0?0:delta[j-1]));
            lambda[j] = (r[j] - b[j]* (j==0?0:lambda[j-1]))/ (c[j] + b[j] * (j==0?0:delta[j-1]));
        }

        for(int j = Mcur-1; j > 0; j--){
            u[i+1][j] = delta[j] * u[i+1][j+1] + lambda[j];
        }
        if(angle >= beta)
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
