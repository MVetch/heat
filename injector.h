#ifndef INJECTOR_H
#define INJECTOR_H

#include "math.h"

class Injector
{
public:
    Injector(double density,
             double angleStart,
             double angleSize,
             double T_w,
             double viscosity_w = 1.006,
             double lambda_w = 0.599,
             double rho_w = 998.2,
             double c_w = 4183);
    Injector();
    double getDensity();
    double getAngleStart(bool degrees = false);
    double getAngleSize(bool degrees = false);
    double getRho();
    double getLambda();
    double getC();
    double getViscosity();
    double getT();

private:
    double density;
    double angleStart;
    double angleSize;
    double rho_w;
    double lambda_w;
    double c_w;
    double viscosity_w;
    double T_w;
};

#endif // INJECTOR_H
