#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qmath.h>
#include <QPair>
#include <qmessagebox.h>
#include "plot.h"
#include "diffequation.h"
#include "qcustomplot.h"
#include "roll.h"
#include "focus.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onClick();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    double X(qreal,qreal);
    double Y(qreal,qreal);
    void buildPlot(
            QCustomPlot& widget,
            QVector<Plot> plots,
            QPair<double, double> rx,
            QPair<double, double> ry,
            QString lx,
            QString ly,
            bool legendAlignLeft = false,
            bool legendAlignTop = true
            );
    const QColor* colors = new QColor [9]{
                QColor(Qt::red),
                QColor(Qt::cyan),
                QColor(Qt::green),
                QColor(Qt::black),
                QColor(Qt::yellow),
                QColor(Qt::darkMagenta),
                QColor(Qt::darkBlue),
                QColor(Qt::lightGray),
                QColor(Qt::darkCyan)
                };
};

#endif // MAINWINDOW_H
