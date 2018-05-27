#ifndef ROLL_H
#define ROLL_H

#include "qmath.h"
#include <QVector>

class Roll
{

public:
    Roll(double R, double rho, double c, double lambda);
    Roll();
    double getR();
    double getC();
    double getRho();
    double getLambda();
    void setInitT(QVector<double> t);
    double initT(int j);
    double countmmToHeat();
    QVector<double> T;
    //double *T;

private:
    double radius;
    double c;
    double rho;
    double lambda;
    double mmToHeat;
};

#endif // ROLL_H
