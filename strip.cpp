#include "strip.h"

Strip::Strip(double width, double lambda, double rho, double c)
{
    this->width = width;
    this->rho = rho;
    this->c = c;
    this->lambda = lambda;
}
Strip::Strip()
{

}

double Strip::getRho(double T)
{
    if(T < 100) T = 101.0;
    QVector<double> l({7871, 7846, 7814, 7781, 7745, 7708, 7668, 7628, 7598, 7602, 7550, 7495});
    double temp = (((int)T/100)*100 - ((int)T/100 - 1)*100) / (T - ((int)T/100 - 1)*100);
    double t = (l[T/100] - l[T/100 - 1]) * temp + l[T/100 - 1];
    return t;
}
double Strip::getC(double T)
{
    //750: 1105
    //850: 795
    if(T < 100) T = 101.0;
    QVector<double> l({481, 481, 519, 553, 595, 662, 754, 829, 875, 795, 849, 669, 669, 669});
    double temp = (((int)T/100)*100 - ((int)T/100 - 1)*100) / (T - ((int)T/100 - 1)*100);
    double t = (l[T/100] - l[T/100 - 1]) * temp + l[T/100 - 1];
    return t;
}
double Strip::getLambda(double T)
{
    if(T < 100) T = 101.0;
    QVector<double> l({65.1, 60.2, 55.6, 50.9, 46.5, 41.0, 37.4, 34.0, 30.1, 27.2, 27.7, 28.5, 29.8});
    double temp = (((int)T/100)*100 - ((int)T/100 - 1)*100) / (T - ((int)T/100 - 1)*100);
    double t = (l[T/100] - l[T/100 - 1]) * temp + l[T/100 - 1];
    return t;
}

double Strip::initT(double r)
{
    return 1000;
}
