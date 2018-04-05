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
    int MUpdate(double angle, double rstep);
    double q(int i);
    double f(int i, int j);
    double Kdef(double phi);
    int M, N, Mcont;
    int NBack, NForward, Nneutr;
    QVector<double> tauContAbs, tauShear, tauCont;
    qreal h;
    qreal theta;
    QVector<double> px0;
    QVector<double> px1;
    QVector<double> pxCont;
    double beta1, beta2, beta3, beta4;

private:
    Focus focus;
    QVector<QVector<qreal>> u;
};

#endif // DIFFEQUATION_H
