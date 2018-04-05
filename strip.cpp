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

double Lagrange(double x, QVector<double> yvals){
    double l_i = 1;
    double ret = 0;
    for(int i = 0; i < yvals.size(); i++){
        l_i = 1;
        for(int j = 0; j < yvals.size(); j++){
            if(j != i) l_i *= ((x - j * 100)/(i * 100 - j * 100));
        }
        ret += yvals[i] * l_i;
    }
    return ret;
}
double Strip::getRho()
{
//    QVector<double> values({7871, 7846, 7814, 7781, 7745, 7708, 7668, 7628, 7598, 7602, 7550, 7495, 7495});

//    return Lagrange(T, values);
    return this->rho;
}
double Strip::getC()
{
//    //750: 1105
//    //850: 795
//    QVector<double> values({481, 481, 519, 553, 595, 662, 754, 829, 875, 795, 849, 669, 669, 669});

//    return Lagrange(T, values);
    return this->c;
}
double Strip::getLambda()
{
//    QVector<double> values({65.1, 60.2, 55.6, 50.9, 46.5, 41.0, 37.4, 34.0, 30.1, 27.2, 27.7, 28.5, 29.8});

//    return Lagrange(T, values);
    return this->lambda;
}

double Strip::initT(double r)
{
    return 1000;
}
