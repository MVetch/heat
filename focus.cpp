#include "focus.h"

Focus::Focus()
{

}

Focus::Focus(qreal hb, qreal ha, Roll r, Strip s)
{
    this->h_b = hb;
    this->h_a = ha;
    this->roll = r;
    this->strip = s;
    double delta_h = h_b - h_a;
    length = qSqrt(r.getR()*delta_h - delta_h*delta_h/4);
    phi_max = qAsin(length/r.getR());
    alpha = qAtan(length/(h_a/2+r.getR()));
    beta = phi_max - alpha;
    r_max = qSqrt(r.getR()*r.getR()+(h_b*h_b)/4+r.getR()*h_b*qCos(phi_max));
}

Roll Focus::getRoll()
{
    return this->roll;
}

double Focus::epsH(double h, double h_max)
{
    return (h_max - h)/h_max;
}

double Focus::curH(double phi)
{
    return roll.getR() * (1 - qCos(phi_max - phi)) + h_a / 2;
}

Strip Focus::getStrip()
{
    return this->strip;
}

double Focus::getHBefore()
{
    return this->h_b;
}

double Focus::getHAfter()
{
    return this->h_a;
}

double Focus::maxR(double phi){
    if(phi < beta)
        return length/qSin(phi_max-phi);
    else
        return (h_a/2+roll.getR())/qCos(phi_max-phi);
}
