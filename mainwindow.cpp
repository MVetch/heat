#include "mainwindow.h"
//#include "ui_mainwindowphone.h"
#include "ui_mainwindow.h"
#include <algorithm>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,   SIGNAL(clicked()),   this, SLOT(onClick()));
    connect(ui->action_Qt,    SIGNAL(triggered()), this, SLOT(aboutQt()));
    connect(ui->openSettings, SIGNAL(triggered()), this, SLOT(on_openSettings_tiggered()));
    //this->setStyleSheet("*{font-size:10px;}");

}

MainWindow::~MainWindow()
{
    delete ui;
    delete colors;
    //delete de;
}

QJsonObject MainWindow::loadSettings()
{
    QFile fsettigs(Settings::saveFileName);
    fsettigs.open(QIODevice::ReadOnly);
    return QJsonDocument(QJsonDocument::fromJson(fsettigs.readAll())).object();
}

void MainWindow::aboutQt(){
    QMessageBox::aboutQt(this);
}

void MainWindow::clean()
{
    delete thread;
    delete calculator;
}

void MainWindow::output(diffEquation *de)
{
    int N = de->N + de->Nnonfocus;
    int M = de->M;

    double angle = 0;
    QVector<QVector<double>> res;
    res.resize(N + 1);
    for(int i = 0; i < N + 1; i++)
        std::copy(de->getResult(i), de->getResult(i) + (i > de->N?de->Mcont:de->M - 2), std::back_inserter(res[i]));

    //===============================вывод в таблицу===============================

    int Mcur = 0;
    QString info = "";

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(N+1);
    ui->tableWidget->setColumnCount(M);

    for(int j = 0; j < de->Mcont; j++){
        ui->tableWidget->setItem(0, j, new QTableWidgetItem(QString::number(res[0][j])));
        ui->tableWidget->item(0, j)->setBackground(Qt::cyan);
        ui->tableWidget->setColumnWidth(j, 50);
    }
    for(int j = de->Mcont; j < de->M; j++){
        ui->tableWidget->setColumnWidth(j, 50);
    }
    for(int i = 1; i < de->N; i++){
        angle = (i - 1) * de->theta;
        Mcur = qMax(de->MUpdate(angle, de->h) - 1 - 2, de->Mcont);
        info+="phi = " + QString::number(angle, 'f', 5) + "рад. / " +
                         QString::number(angle*180/M_PI, 'f', 5) + "°\t r = " +
                         QString::number(de->getFocus().maxR(angle), 'f', 5)+ ";\n";
        for(int j = 0; j < de->Mcont; j++){
            ui->tableWidget->setItem(i, j, new QTableWidgetItem(QString::number(res[i][j])));
            if((i-1 == qRound(de->getFocus().beta/de->theta)))
                ui->tableWidget->item(i, j)->setBackground(Qt::green);
            else
                ui->tableWidget->item(i, j)->setBackground(Qt::cyan);
        }

        ui->tableWidget->setItem(i, de->Mcont,     new QTableWidgetItem(QString::number(
                                                                            de->beta1 / (1 - de->beta2 * de->beta3) * res[i][de->Mcont - 1] +
                                                                            de->beta2 * de->beta4 / (1 - de->beta2 * de->beta3) * res[i][de->Mcont] +
                                                                            de->q(i-1) * de->getFocus().getScale().thickness * de->h / (de->getFocus().getRoll().getLambda() * de->getFocus().getScale().thickness + de->getFocus().getScale().lambda * de->h)
                                                                           )));
        ui->tableWidget->item(i, de->Mcont)->setBackground(Qt::yellow);

        ui->tableWidget->setItem(i, de->Mcont + 1, new QTableWidgetItem(QString::number(
                                                                           de->beta1 * de->beta3 / (1 - de->beta2 * de->beta3) * res[i][de->Mcont - 1] +
                                                                           de->beta4 / (1 - de->beta2 * de->beta3) * res[i][de->Mcont] +
                                                                           de->q(i-1) * de->getFocus().getScale().thickness * de->h * de->beta3 / ((de->getFocus().getRoll().getLambda() * de->getFocus().getScale().thickness + de->getFocus().getScale().lambda * de->h) * (1 - de->beta2 * de->beta3))
                                                                       )));
        ui->tableWidget->item(i, de->Mcont + 1)->setBackground(Qt::darkMagenta);

        for(int j = de->Mcont; j <= Mcur; j++){
            ui->tableWidget->setItem(i, j + 2, new QTableWidgetItem(QString::number(res[i][j])));
            if((i-1 == qRound(de->getFocus().beta/de->theta)))
                ui->tableWidget->item(i, j + 2)->setBackground(Qt::green);
            else
                ui->tableWidget->item(i, j + 2)->setBackground(Qt::red);
        }
    }

    for(int i = de->N; i < N + 1; i++){
        for(int j = 0; j < de->Mcont; j++){
            ui->tableWidget->setItem(i, j, new QTableWidgetItem(QString::number(res[i][j])));
            ui->tableWidget->item(i, j)->setBackground(Qt::cyan);
        }
    }
    ui->tableWidget->setHorizontalHeaderItem(de->Mcont,     new QTableWidgetItem("Стык"));
    ui->tableWidget->setHorizontalHeaderItem(de->Mcont + 1, new QTableWidgetItem("Окалина"));

    //===============================график q()===============================
    QVector<double> x(de->N), y(de->N); //Массивы координат точек
    double maxY = 0, minY = 1e90;

    for (int i = 0; i < de->N; i++){
        x[i] = i;
        y[i] = de->q(i);
        if(y[i] > maxY) maxY = y[i];
        if(y[i] < minY) minY = y[i];
    }
    buildPlot(
                *ui->widget_q,
                QVector<Plot>({Plot(x, y, QString("Тепловой поток"))}),
                QPair<double, double>(0, de->N-1),
                QPair<double, double>(minY, maxY),
                QString("Номер точки  по длине очага"),
                QString("Вт/м^2")
                );

    //===============================график px()===============================
    maxY = 0, minY = 1e90;

    for (int i = 0; i < de->N; i++){
        if(de->pxCont[i] > maxY) maxY = de->pxCont[i];
        if(de->pxCont[i] < minY) minY = de->pxCont[i];
    }
    buildPlot(
                *ui->widget_px,
                QVector<Plot>({Plot(x, de->pxCont, QString("Нормальное давление"))}),
                QPair<double, double>(0, de->N-1),
                QPair<double, double>(minY/2, maxY*1.2),
                QString("Номер точки  по длине очага"),
                QString("МН/м^2"),
                true
                );

    //===============================график KDef===============================
    maxY = 0, minY = 1e90;

    for (int i = 0; i < de->N; i++){
        y[i] = de->Kdef(i * de->theta);
        if(y[i] > maxY) maxY = y[i];
        if(y[i] < minY) minY = y[i];
    }
    buildPlot(
                *ui->widget_KDef,
                QVector<Plot>({Plot(x, y, QString("Сопротивление деформации"))}),
                QPair<double, double>(0, de->N-1),
                QPair<double, double>(minY/2, maxY*1.2),
                QString("Номер точки  по длине очага"),
                QString("МН/м^2")
                );

    //===============================график tauCont===============================
    maxY = 0, minY = 1e90;
    for (int i = 0; i < de->N; i++){
        if(de->tauContAbs[i] > maxY) maxY = de->tauContAbs[i];
        if(de->tauContAbs[i] < minY) minY = de->tauContAbs[i];
    }// c tauShear не сверяю, потому что область показа функции все равно определяет только tauContAbs
    buildPlot(
                *ui->widget_tauCont,
                QVector<Plot>({Plot(x, de->tauContAbs, QString("Касательное давление")), Plot(x, de->tauShear, QString("Предел текучести"))}),
                QPair<double, double>(0, de->N-1),
                QPair<double, double>(minY/2, maxY*1.2),
                QString("Номер точки  по длине очага"),
                QString("МН/м^2"),
                true
                );

    //===============================график температуры===============================

    maxY = 0, minY = 1e90;
    x.resize(de->MUpdate(de->getFocus().phi_max, de->h)-2 - de->Mcont);
    y.resize(de->MUpdate(de->getFocus().phi_max, de->h)-2 - de->Mcont);
    int index = de->N - 1;
    for (int i = 0; i < x.size(); i++){
        x[i] = i + de->Mcont;
        y[i] = res[index][i + de->Mcont];
        if(y[i] > maxY) maxY = y[i];
    }
    QVector<Plot> plotsTemp({Plot(x, y, QString("Полоса"))});

    x.resize(de->Mcont+1);
    y.resize(de->Mcont+1);
    for (int i = 0; i <= de->Mcont; i++){
        x[i] = i;
        y[i] = res[index][i];
        if(y[i] < minY) minY = y[i];
    }
    plotsTemp.push_back(Plot(x, y, QString("Валок")));


    buildPlot(
                *ui->widget_T,
                plotsTemp,
                QPair<double, double>(0, de->MUpdate(de->getFocus().phi_max, de->h)-2),
                QPair<double, double>(minY/2, maxY*1.2),
                QString("Номер точки в глубину"),
                QString("°C"),
                true
                );


//    for(int i = 0; i < de->N + de->Nnonfocus + 1; i++){
//        delete[] res[i];
//    }

    //===============================Сообщение в конце===============================
    QMessageBox msgBox;

    msgBox.setText("Посчиталось!");
    msgBox.setStyleSheet("QLabel{min-width: 300px;}");

    msgBox.setInformativeText("phi ∈ [0; " + QString::number(de->getFocus().phi_max) +"] рад.\n"+
                              "phi ∈ [0; " + QString::number(de->getFocus().phi_max*180/M_PI) +"] °\n"+
                              "t ∈ [0; " + QString::number(de->getFocus().phi_max / de->getFocus().getRoll().getR() / 73 * 60) +"] c\n"+
                              "Номер точки стыка: " + QString::number(de->Mcont + 1)+"\n"+
                              "Шаг по r: " + QString::number(de->h)+"\n"+
                              "Шаг по phi: " + QString::number(de->theta)+"\n"+
                              "Считалось " + QString::number((double)time.elapsed()/1000) + "c."+"\n"//+
                              //"Решалось " + QString::number(timeDifur) + "c."+"\n"+
                              //"Решалось2 " + QString::number(timeDifur2) + "c."
                              );
    //msgBox.setDetailedText(info);
    msgBox.setStandardButtons(QMessageBox::Close);
    msgBox.exec();

    delete de;
    ui->pushButton->setEnabled(true);
}

void MainWindow::showError(QString err)
{
    QMessageBox::critical(this, "Ошибка!", err);
}

void MainWindow::updateProgressBar(int value)
{
    ui->progressBar->setValue(value);
    ui->progressBar->update();
}

void MainWindow::updateProgressBarMaxValue(int value)
{
    ui->progressBar->setMaximum(value);
}

void MainWindow::onClick(){
    time.start();

    calculator = new MainCalculator();
    thread = new QThread;
    calculator->moveToThread(thread);

    connect(calculator, SIGNAL (error(QString)),          this, SLOT (showError(QString)));
    connect(calculator, SIGNAL (sendMaxValue(int)),       this, SLOT (updateProgressBarMaxValue(int)));
    connect(calculator, SIGNAL (toOutput(diffEquation*)), this, SLOT (output(diffEquation*)));
    connect(calculator, SIGNAL (progress(int)),           this, SLOT (updateProgressBar(int)));
    connect(thread,     SIGNAL (started()),  calculator, SLOT (calc()));
    connect(calculator, SIGNAL (finished()), thread,     SLOT (quit()));
    connect(thread,     SIGNAL (finished()), this,       SLOT (clean()));
    connect(calculator, SIGNAL (finished()), calculator, SLOT (deleteLater()));
    connect(thread,     SIGNAL (finished()), thread,     SLOT (deleteLater()));

    //calculator->settings = loadSettings();
    //calculator->moveToThread(thread);
    thread->start();

    ui->pushButton->setEnabled(false);
}

double MainWindow::X(double r, double phi){
    return r*qCos(phi);
}
double MainWindow::Y(double r, double phi){
    return r*qSin(phi);
}

void MainWindow::on_pushButton_clicked()
{

}
void MainWindow::buildPlot(
        QCustomPlot& widget,
        QVector<Plot> plots,
        QPair<double, double> rx,
        QPair<double, double> ry,
        QString lx,
        QString ly,
        bool legendAlignLeft,
        bool legendAlignTop
        )
{
    widget.clearGraphs();
    widget.xAxis->setRange(rx.first, rx.second);//Для оси Ox
    widget.yAxis->setRange(ry.first, ry.second);//Для оси Oy
    widget.xAxis->setLabel(lx);
    widget.yAxis->setLabel(ly);
    for(int i = 0; i < plots.size(); i++){
        widget.addGraph();
        widget.graph(i)->setData(plots[i].x, plots[i].y);
        widget.graph(i)->setPen(QPen(colors->at(i % colors->size())));
        widget.graph(i)->setBrush(QBrush(
                                        QColor(
                                            colors->at(i % colors->size()).red(),
                                            colors->at(i % colors->size()).green(),
                                            colors->at(i % colors->size()).blue(),
                                            70
                                        )
                                      )
                                  );
        widget.graph(i)->setName(plots[i].name);
    }

    widget.setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    widget.legend->setVisible(true);
    widget.legend->setBrush(QBrush(QColor(255,255,255,150)));
    widget.axisRect()->insetLayout()->setInsetAlignment(0,
                                                        (legendAlignLeft?
                                                            Qt::AlignLeft:
                                                            Qt::AlignRight)|
                                                                (legendAlignTop?
                                                                Qt::AlignTop:
                                                                Qt::AlignBottom)
                                                        );

    widget.replot();
}

void MainWindow::on_openSettings_tiggered()
{
    Settings *settings = new Settings();
    settings->setModal(true);
    settings->load();
    settings->show();

}
