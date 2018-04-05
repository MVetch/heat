#ifndef STRIP_H
#define STRIP_H

#include <QVector>
class Strip
{
public:
    Strip();
    Strip(double width, double rho, double c, double lambda);
    double getC(double T);
    double getRho(double T);
    double getLambda(double T);
    double initT(double r);
private:
    double c;
    double rho;
    double lambda;
    double width;
};

#endif // STRIP_H
