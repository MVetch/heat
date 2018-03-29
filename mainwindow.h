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
    const QVector<QColor>* colors = new QVector<QColor>({
                Qt::red,
                Qt::cyan,
                Qt::green,
                Qt::black,
                Qt::yellow,
                Qt::darkMagenta,
                Qt::darkBlue,
                Qt::lightGray,
                Qt::darkCyan
    });
};

#endif // MAINWINDOW_H
