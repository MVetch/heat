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

void Roll::setInitT(QVector<double> t)
{
    this->T = t;
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

double Roll::initT(int j)
{
    return this->T[j];
    //return 70;
}

double Roll::countmmToHeat()
{
    return 0.100;
}
