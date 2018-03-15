#ifndef ROLL_H
#define ROLL_H

#include "qmath.h"

class Roll
{

public:
    Roll(qreal R,qreal rho,qreal c, qreal lambda);
    Roll();
    qreal getR();
    qreal getC();
    qreal getRho();
    qreal getLambda();
    double initT(qreal r);

private:
    qreal radius;
    double c;
    double rho;
    double lambda;
};

#endif // ROLL_H
