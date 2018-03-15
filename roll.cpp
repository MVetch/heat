#include "roll.h"

Roll::Roll(qreal radius, qreal rho, qreal c, qreal lambda)
{
    this->radius = radius;
    this->rho = rho;
    this->c = c;
    this->lambda = lambda;
}
Roll::Roll()
{
}

qreal Roll::getR()
{
    return this->radius;
}
qreal Roll::getRho()
{
    return this->rho;
}
qreal Roll::getC()
{
    return this->c;
}
qreal Roll::getLambda()
{
    return this->lambda;
}

double Roll::initT(qreal r)
{
    return 70;
}
