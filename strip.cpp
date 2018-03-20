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

double Strip::getRho()
{
    return this->rho;
}
double Strip::getC()
{
    return this->c;
}
double Strip::getLambda()
{
    return this->lambda;
}

double Strip::initT(double r)
{
    return 1000;
}
