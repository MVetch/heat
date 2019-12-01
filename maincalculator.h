#ifndef MAINCALCULATOR_H
#define MAINCALCULATOR_H

#include <QObject>
#include <QApplication>
#include <QProgressBar>
#include <QJsonObject>
#include <QVector>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include "focus.h"
#include "diffequation.h"
#include "settings.h"
#include "roll.h"

class MainCalculator : public QObject
{
    Q_OBJECT
private:
    bool counting = false;
    bool counted = false;
    bool stopped = false;

public:
    MainCalculator();
    ~MainCalculator();
    void load();
    diffEquation *de;
    QJsonObject settings;
    QJsonObject loadSettings();
    bool isCounting();
    bool isStopped();
    void setStopped(bool);
    bool hasCounted();
    bool loaded = true;

public slots:
    void calc();
    void finish();
    void stop();

signals:
    void finished();
    void progress(int);
    void sendMaxValue(int);
    void setUpGraphSlider(int);
    void toOutput();
    void error(QString);
};

#endif // MAINCALCULATOR_H
