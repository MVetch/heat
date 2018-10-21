#include "maincalculator.h"

MainCalculator::MainCalculator()
{
    settings = loadSettings();
    if(settings.size() < Settings::amountOfSettings) {
        loaded = false;
        return;
    }
    double R = settings.value("R").toDouble();
    Roll roll(
                R,
                settings.value("rho_v").toDouble(),
                settings.value("c_v").toDouble(),
                settings.value("lambda_v").toDouble(),
                settings.value("vSpin").toDouble() / 60,
                settings.value("mmToHeat").toDouble() / 1000
              );

    double h_b = settings.value("h_b").toDouble();
    double h_a = settings.value("h_a").toDouble();

    int M = settings.value("M").toInt();
    int N = settings.value("N").toInt();

    roll.setInitT(QVector<double>(M, 20));

    Strip strip(1.357,
                settings.value("lambda_p").toDouble(),
                settings.value("rho_p").toDouble(),
                settings.value("c_p").toDouble()
                );
    Focus focus(h_b, h_a, roll, strip, 0.000025, 2.0);
    QVector<Injector> injs;
    QJsonArray injectors = settings.value("injectors").toArray();
    for(int i = 0; i < injectors.size(); i++){
        injs.push_back(Injector(
                                injectors[i].toObject()["density"].toDouble(),
                                injectors[i].toObject()["angleStart"].toDouble(),
                                injectors[i].toObject()["angleSize"].toDouble(),
                                settings.value("waterT").toDouble()
                               )
        );
    }

    this->de = new diffEquation (M, N, focus, injs);
    this->settings = settings;
}

MainCalculator::~MainCalculator()
{
    if(loaded)
        delete this->de;
}

QJsonObject MainCalculator::loadSettings()
{
    QFile fsettigs(Settings::saveFileName);
    fsettigs.open(QIODevice::ReadOnly);
    return QJsonDocument(QJsonDocument::fromJson(fsettigs.readAll())).object();
}

void MainCalculator::calc()
{
    if(!loaded) {
        emit error("Настройки не загружены!");
        return;
    }
    QVector<double> TRoll;
    Focus focus = de->getFocus();
    int N = de->N + de->Nnonfocus;
    int rollRounds = settings.value("timeToModel").toDouble() * settings.value("vSpin").toDouble();
    emit sendMaxValue(rollRounds);

    QFile fileEdge("outputEdge.csv");
    fileEdge.open(QIODevice::WriteOnly|QFile::Truncate);
    QTextStream streamEdge(&fileEdge);
    streamEdge.setLocale(QLocale(QLocale::Russian));

    QFile fileCenter("outputCenter.csv");
    fileCenter.open(QIODevice::WriteOnly|QFile::Truncate);
    QTextStream streamCenter(&fileCenter);
    streamCenter.setLocale(QLocale(QLocale::Russian));

    QString delim = ";";

    int parts = (2 * de->getInjectors().size() + 1);
    int NGone = 0;
    int *NParts = new int[parts];
    for(int i = 0; i < parts-1; i++){
        NParts[i] = i % 2 == 0 ? (de->getInjectors()[qFloor(i / 2)].getAngleStart() - (i == 0 ? 0 : de->getInjectors()[qFloor(i / 2) - 1].getAngleSize() + de->getInjectors()[qFloor(i / 2) - 1].getAngleStart())) / de->theta : de->getInjectors()[qFloor(i / 2)].getAngleSize() / de->theta;
    }
    for(int round = 0; round < rollRounds; round++)
    {
        NGone = 0;
        de->setFocus(focus);
        de->solveFocus();
        for(int j = 0; j < parts - 1; j++){
            de->solveNonFocus(j, NGone, NParts[j]);
            NGone += NParts[j];
        }
        de->solveNonFocus(parts - 1, NGone, de->Nnonfocus - NGone);//в последний кусок кладем все оставшиеся точки

        TRoll.clear();
        std::copy(de->getResult(N), de->getResult(N) + de->Mcont, std::back_inserter(TRoll));
        focus.getRoll().setInitT(TRoll);

        streamEdge << de->getResult(N, de->Mcont) << delim;
        streamCenter << de->getResult(N, 0) << delim;
        emit progress(round + 1);
    }
    delete[] NParts;
    fileEdge.close();
    fileCenter.close();
    emit toOutput(this->de);
}

void MainCalculator::finish()
{
    emit finished();
}
