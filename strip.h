#ifndef STRIP_H
#define STRIP_H


class Strip
{
public:
    Strip();
    Strip(double width, double rho, double c, double lambda);
    double getC();
    double getRho();
    double getLambda();
    double initT(double r);
private:
    double c;
    double rho;
    double lambda;
    double width;
};

#endif // STRIP_H
