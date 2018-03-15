#ifndef FOCUS_H
#define FOCUS_H

#include "qmath.h"
#include "roll.h"

class Focus
{
public:
    Focus();
    Focus(qreal, qreal, Roll);
    Roll getRoll();
    qreal getHBefore();
    qreal getHAfter();
private:
    qreal h_b;
    qreal h_a;
    Roll roll;
};

#endif // FOCUS_H
