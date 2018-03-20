#ifndef DIFFEQUATION_H
#define DIFFEQUATION_H

#include "focus.h"
#include "roll.h"
#include "qmath.h"
#include "qvector.h"
#include "mainwindow.h"

class diffEquation
{
public:
    diffEquation(int M, int N, Focus focus);
    ~diffEquation();
    void solve();
    QVector<QVector<double>> getResult();
    double getResult(int i, int j);
    Focus getFocus();
    int MUpdate(double,double);
    double X(double, double);
    double Y(double, double);
    double q(int i);
    double f(double);
    double Kdef();
    int M, N, Mcont;
    qreal h;
    qreal theta;

private:
    Focus focus;
    QVector<QVector<qreal>> u;
};

#endif // DIFFEQUATION_H
