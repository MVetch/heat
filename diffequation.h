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
    diffEquation(qreal h, qreal tau, Focus focus, qreal lambda, qreal rho, qreal c, qreal initF, qreal initQ);
    ~diffEquation();
    void solve();
    QVector<QVector<double>> getResult();
    double getResult(int i, int j);
    Focus getFocus();
    int MUpdate(double,double);
    double maxR(double);
    double X(double, double);
    double Y(double, double);
    double q(double);
    double f(double);
    int Mmax;
    double phi_max, r_max, alpha, beta, length;

private:
    qreal h;
    qreal theta;
    qreal initF;
    qreal initQ;
    bool qSpread;
    qreal lambda_p;
    qreal rho_p;
    qreal c_p;
    Focus focus;
    QVector<QVector<qreal>> u;
};

#endif // DIFFEQUATION_H
