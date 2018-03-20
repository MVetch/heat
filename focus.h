#ifndef FOCUS_H
#define FOCUS_H

#include "qmath.h"
#include "roll.h"
#include "strip.h"

class Focus
{
public:
    Focus();
    Focus(qreal, qreal, Roll, Strip);
    Roll getRoll();
    Strip getStrip();
    qreal getHBefore();
    qreal getHAfter();
    double maxR(double phi);
    double length;
    double phi_max, r_max, alpha, beta;
private:
    qreal h_b;
    qreal h_a;
    Roll roll;
    Strip strip;
};

#endif // FOCUS_H
