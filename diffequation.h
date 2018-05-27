#ifndef DIFFEQUATION_H
#define DIFFEQUATION_H

#include <QTime>
#include "focus.h"
#include "roll.h"
#include "qmath.h"
#include "qvector.h"

class diffEquation
{
public:
    diffEquation();
    diffEquation(int M, int N, Focus focus);
    diffEquation(const diffEquation& other);
    ~diffEquation();
    void solveFocus();
    void solveNonFocus(double emulT);
    double **getResult();
    double *getResult(int i);
    double getResult(int i, int j);
    Focus getFocus();
    void setFocus(Focus& focus);
    Roll getRoll();
    int MUpdate(double angle, double rstep);
    double q(int i);
    double f(int i, int j);
    double Kdef(double phi);

    int M, N, Nnonfocus, Mcont;
    int NBack, NForward, Nneutr;
    QVector<double> tauContAbs, tauShear, tauCont;
    double h;
    double theta;
    QVector<double> px0;
    QVector<double> px1;
    QVector<double> pxCont;
    double beta1, beta2, beta3, beta4;

private:
    Focus focus;
    //QVector<QVector<double>> u;
    double **u;
};

#endif // DIFFEQUATION_H
