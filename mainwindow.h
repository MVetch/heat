#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qmath.h>
#include <qmessagebox.h>
#include "diffequation.h"
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
};

#endif // MAINWINDOW_H
