#include "plot.h"

Plot::Plot()
{
}
Plot::Plot(QVector<double> _x, QVector<double> _y, QString _name)
{
    x = _x;
    y = _y;
    name = _name;
}
Plot::Plot(Plot const& other){
    this->name = other.name;
    this->x = other.x;
    this->y = other.y;
}
