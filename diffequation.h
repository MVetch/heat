#ifndef DIFFEQUATION_H
#define DIFFEQUATION_H

#include <QTime>
#include "focus.h"
#include "roll.h"
#include "injector.h"
#include "qmath.h"
#include "qvector.h"

class diffEquation
{
public:
    diffEquation();
    diffEquation(int M, int N, Focus focus, QVector<Injector> injectors);
    diffEquation(const diffEquation& other);
    ~diffEquation();
    void solveFocus();
    void solveNonFocus(int zone, int NStart, int NPart);
    double **getResult();
    double *getResult(int i);
    double getResult(int i, int j);
    Focus getFocus();
    void setFocus(Focus& focus);
    Roll getRoll();
    QVector<Injector> getInjectors();
    int MUpdate(double angle, double rstep);
    double q(int i);
    double f(int i);
    double Kdef(double phi);

    int M, N, Nnonfocus, Mcont;
    int NBack, NForward, Nneutr;
    double* tauContAbs;
    double* tauShear;
    double* tauCont;
    double h;
    double theta;
    double* px0;
    double* px1;
    double* pxCont;
    double* fValue;
    double* qValue;
    double beta1, beta2, beta3, beta4;

private:
    Focus focus;
    QVector<Injector> injectors;
    //QVector<QVector<double>> u;
    double **u;
};

#endif // DIFFEQUATION_H
