#include "injector.h"

Injector::Injector(
        double density,
        double angleStart,
        double angleSize,
        double T_w,
        double viscosity_w,
        double lambda_w,
        double rho_w,
        double c_w
)
{
    this->density = density;
    this->angleStart = angleStart;
    this->angleSize = angleSize;
    this->lambda_w = lambda_w;
    this->rho_w = rho_w;
    this->c_w = c_w;
    this->viscosity_w = viscosity_w;
    this->T_w = T_w;
}

Injector::Injector()
{

}

double Injector::getDensity()
{
    return this->density;
}

double Injector::getAngleStart(bool degrees)
{
    return this->angleStart * (degrees ? 1 : M_PI / 180);
}

double Injector::getAngleSize(bool degrees)
{
    return this->angleSize * (degrees ? 1 : M_PI / 180);
}

double Injector::getRho()
{
    return this->rho_w;
}

double Injector::getLambda()
{
    return this->lambda_w;
}

double Injector::getC()
{
    return this->c_w;
}

double Injector::getViscosity()
{
    return this->viscosity_w;
}

double Injector::getT()
{
    return this->T_w;
}
