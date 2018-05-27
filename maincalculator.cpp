#include "maincalculator.h"

MainCalculator::MainCalculator()
{
    settings = loadSettings();
    if(settings.size() < Settings::amountOfSettings) {
        //QMessageBox::critical(this, "Ошибка!", "Настройки не загружены!");
        emit error("Настройки не загружены!");
        return;
    }
    double R = settings.value("R").toDouble();
    Roll roll(
                R,
                settings.value("rho_v").toDouble(),
                settings.value("c_v").toDouble(),
                settings.value("lambda_v").toDouble()
              );

    double h_b = settings.value("h_b").toDouble();
    double h_a = settings.value("h_a").toDouble();

    int M = settings.value("M").toInt();
    int N = settings.value("N").toInt();

    roll.setInitT(QVector<double>(M, 70));

    Strip strip(1.357,
                settings.value("lambda_p").toDouble(),
                settings.value("rho_p").toDouble(),
                settings.value("c_p").toDouble()
                );
    Focus focus(h_b, h_a, roll, strip, 0.000025, 2.0);

    this->de = new diffEquation (M, N, focus);
    this->settings = settings;
}

MainCalculator::~MainCalculator()
{
    //delete de;
}

QJsonObject MainCalculator::loadSettings()
{
    QFile fsettigs(Settings::saveFileName);
    fsettigs.open(QIODevice::ReadOnly);
    return QJsonDocument(QJsonDocument::fromJson(fsettigs.readAll())).object();
}

void MainCalculator::calc()
{
    QVector<double> TRoll;
    Focus focus = de->getFocus();
    int N = de->N + de->Nnonfocus;
    int rollRounds = settings.value("timeToModel").toDouble() * settings.value("vSpin").toDouble();
    emit sendMaxValue(rollRounds);

    for(int round = 0; round < rollRounds; round++)
    {
        de->setFocus(focus);
        de->solveFocus();
        de->solveNonFocus(settings.value("airT").toDouble());

        TRoll.clear();
        std::copy(de->getResult(N), de->getResult(N) + de->Mcont, std::back_inserter(TRoll));
        focus.getRoll().setInitT(TRoll);

        emit progress(round + 1);
    }
    emit toOutput(this->de);
    emit finished();
}
