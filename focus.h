#ifndef FOCUS_H
#define FOCUS_H

#include "qmath.h"
#include "roll.h"
#include "strip.h"
#include "scale.h"

class Focus
{
public:
    Focus();
    Focus(qreal, qreal, Roll, Strip, Scale);
    Focus(qreal, qreal, Roll, Strip, double sc_w,  double sc_lambda);
    Roll& getRoll();
    Strip& getStrip();
    Scale& getScale();
    double getHBefore();
    double getHAfter();
    double maxR(double phi);
    double epsH(double h, double h_max);
    double curH(double phi);
    double length;
    double phi_max, r_max, alpha, beta;
private:
    double h_b;
    double h_a;
    Roll roll;
    Strip strip;
    Scale scale;
};

#endif // FOCUS_H
