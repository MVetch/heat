#include "focus.h"

Focus::Focus()
{

}

Focus::Focus(qreal hb, qreal ha, Roll r)
{
    this->h_b = hb;
    this->h_a = ha;
    this->roll = r;
}

Roll Focus::getRoll()
{
    return this->roll;
}

qreal Focus::getHBefore()
{
    return this->h_b;
}

qreal Focus::getHAfter()
{
    return this->h_a;
}
