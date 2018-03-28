#ifndef PLOT_H
#define PLOT_H
#include <QVector>

class Plot
{
public:
    Plot();
    Plot(QVector<double> x, QVector<double> y, QString name);
    Plot(Plot const& other);
    QVector<double> x;
    QVector<double> y;
    QString name;
};

#endif // PLOT_H
