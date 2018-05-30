#ifndef MAINCALCULATOR_H
#define MAINCALCULATOR_H

#include <QObject>
#include <QProgressBar>
#include <QJsonObject>
#include <QVector>
#include "focus.h"
#include "diffequation.h"
#include "settings.h"
#include "roll.h"

class MainCalculator : public QObject
{
    Q_OBJECT
public:
    MainCalculator();
    ~MainCalculator();
    diffEquation *de;
    QJsonObject settings;
    QJsonObject loadSettings();
    bool loaded = true;

public slots:
    void calc();

signals:
    void finished();
    void progress(int);
    void sendMaxValue(int);
    void toOutput(diffEquation*);
    void error(QString);
};

#endif // MAINCALCULATOR_H
