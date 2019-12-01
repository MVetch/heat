#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qmath.h>
#include <QPair>
#include <qmessagebox.h>
#include <QFile>
#include <QString>
#include <QThread>
#include <QProcess>
#include <QDesktopServices>
#include "plot.h"
#include "diffequation.h"
#include "qcustomplot.h"
#include "roll.h"
#include "focus.h"
#include "settings.h"
#include "maincalculator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setUpGui();
    void buildHeatDeepPlot(int);

private slots:
    void onClick();
    void on_openSettings_triggered();
    void on_loadSettings_triggered();
    void aboutQt();
    void callHelp();
    void clear();
    void output();
    void showError(QString);
    void updateEveryStep(int);
    void updateProgressBarMaxValue(int);

    void on_sliderDeep_valueChanged(int value);

    void on_sliderDeep_sliderMoved(int position);

    void on_pushButton_stop_clicked();

signals:
    stopped();
    finished();

private:
    Ui::MainWindow *ui;
    MainCalculator *calculator;
    QThread *thread;
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
    QTime time;
};

#endif // MAINWINDOW_H
