#ifndef DIFFEQUATION_H
#define DIFFEQUATION_H

#include <QTime>
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
    double q(int i);
    double f(double);
    double Kdef(double phi);
    int M, N, Mcont;
    int NBack, NForward, Nneutr;
    QVector<double> tauContAbs, tauShear, tauCont;
    qreal h;
    qreal theta;
    QVector<double> px0;
    QVector<double> px1;
    QVector<double> pxCont;

private:
    Focus focus;
    QVector<QVector<qreal>> u;
};

#endif // DIFFEQUATION_H
