#include "mainwindow.h"
//#include "ui_mainwindowphone.h"
#include "ui_mainwindow.h"
#include <algorithm>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    calculator = new MainCalculator();
    connect(calculator, SIGNAL (error(QString)),        this, SLOT (showError(QString)));
    connect(calculator, SIGNAL (sendMaxValue(int)),     this, SLOT (updateProgressBarMaxValue(int)));
    connect(calculator, SIGNAL (progress(int)),         this, SLOT (updateEveryStep(int)));
    connect(calculator, SIGNAL (toOutput()),            this, SLOT (output()));

    thread = new QThread;
    calculator->moveToThread(thread);

    connect(thread,     SIGNAL (started()),  calculator, SLOT (calc()));
    //connect(thread,     SIGNAL (finished()), this,       SLOT (clear()));

    connect(this,       SIGNAL (stopped()),  calculator, SLOT (stop()));
    connect(this,       SIGNAL (finished()), calculator, SLOT (finish()));
    connect(this,       SIGNAL (finished()), thread,     SLOT (quit()));

    ui->setupUi(this);
    ui->pushButton_stop->hide();
    ui->pushButton_stop->setEnabled(false);
    this->setUpGui();
    connect(ui->pushButton, SIGNAL(clicked()),   this, SLOT(onClick()));
    connect(ui->action_Qt,  SIGNAL(triggered()), this, SLOT(aboutQt()));
    connect(ui->callHelp,   SIGNAL(triggered()), this, SLOT(callHelp()));
    connect(ui->openSettingsButton,   SIGNAL(clicked()), this, SLOT(on_openSettings_triggered()));
    //this->setStyleSheet("*{font-size:10px;}");

}

void MainWindow::setUpGui()
{
    calculator->load();
    double r = calculator->settings.value("R").toDouble() * 1000;
    double step = r / calculator->de->Mcont;
    ui->sliderDeep->setMinimum(calculator->de->Mcont - qCeil(10 / step));
    ui->sliderDeep->setMaximum(calculator->de->Mcont);
    ui->label_deepStart->setText(QString::number(r - 10) + QString("мм"));
    ui->label_deepEnd->setText(QString::number(r) + QString("мм"));
    ui->label_deepMid->setText(QString::number(ui->sliderDeep->value() * step, 'f', 2) + QString("мм"));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete colors;
    delete calculator;
    delete thread;
}

void MainWindow::aboutQt(){
    QMessageBox::aboutQt(this);
}

void MainWindow::callHelp()
{
    QStringList nameFilter("*.chm");
    QDir directory;
    QStringList txtFilesAndDirectories = directory.entryList(nameFilter);
    if(txtFilesAndDirectories.isEmpty()){
        QMessageBox::critical(this, "Ошибка!", "Файл со справкой не найден!");
        return;
    }
    QDesktopServices::openUrl(QUrl(txtFilesAndDirectories[0]));
}

void MainWindow::clear()
{
    delete thread;
//    delete calculator;
}

void MainWindow::output()
{
    diffEquation* de = this->calculator->de;
    int N = de->N + de->Nnonfocus;
    int M = de->M;

    double angle = 0;
    QVector<QVector<double>> res;
    res.resize(N + 1);
    for(int i = 0; i < N + 1; i++)
        std::copy(de->getResult(i), de->getResult(i) + (i > de->N?de->Mcont + 1:de->M - 2), std::back_inserter(res[i]));

    //===============================вывод в таблицу===============================

    int Mcur = 0;
    int MCut = qMin(100, de->Mcont / 10);
    int Mmax = MCut * 2 + M - de->Mcont;
    QString info = "";

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(de->N + qMin(100, N / 10) + 1);
    ui->tableWidget->setColumnCount(Mmax + 1);

    for(int j = 0; j < MCut; j++){
        ui->tableWidget->setItem(0, j, new QTableWidgetItem(QString::number(res[0][j])));
        ui->tableWidget->item(0, j)->setBackground(Qt::cyan);
        ui->tableWidget->setColumnWidth(j, 50);
    }
    ui->tableWidget->setColumnWidth(MCut, 50);
    ui->tableWidget->setItem(0, MCut, new QTableWidgetItem());
    ui->tableWidget->item(0, MCut)->setBackground(Qt::black);//пропускаем столбец
    for(int j = MCut + 1, k = de->Mcont - 2 * MCut - 1; j < MCut * 2 + 1; j++){
        ui->tableWidget->setItem(0, j, new QTableWidgetItem(QString::number(res[0][j + k])));
        ui->tableWidget->item(0, j)->setBackground(Qt::cyan);
        ui->tableWidget->setColumnWidth(j, 50);
    }
    for(int j = MCut * 2; j < Mmax + 1; j++){
        ui->tableWidget->setColumnWidth(j, 50);
    }
    for(int i = 1; i < de->N + 1; i++){
        angle = (i - 1) * de->theta;
        Mcur = qMax(de->MUpdate(angle, de->h) - 1 - 2, de->Mcont);
        Mmax = MCut * 2 + Mcur - de->Mcont;
        info+="phi = " + QString::number(angle, 'f', 5) + "рад. / " +
                         QString::number(angle*180/M_PI, 'f', 5) + "°\t r = " +
                         QString::number(de->getFocus().maxR(angle), 'f', 5)+ ";\n";
        for(int j = 0; j < MCut; j++){
            ui->tableWidget->setItem(i, j, new QTableWidgetItem(QString::number(res[i][j])));
            ui->tableWidget->item(i, j)->setBackground(Qt::cyan);
        }
        ui->tableWidget->setItem(i, MCut, new QTableWidgetItem());
        ui->tableWidget->item(i, MCut)->setBackground(Qt::black);//пропускаем столбец
        for(int j = MCut + 1, k = de->Mcont - 2 * MCut - 1; j < MCut * 2 + 1; j++){
            ui->tableWidget->setItem(i, j, new QTableWidgetItem(QString::number(res[i][j + k])));
            ui->tableWidget->item(i, j)->setBackground(Qt::cyan);
        }

        ui->tableWidget->setItem(i, MCut * 2 + 1,     new QTableWidgetItem(QString::number(
                                                                            de->beta1 / (1 - de->beta2 * de->beta3) * res[i][de->Mcont - 1] +
                                                                            de->beta2 * de->beta4 / (1 - de->beta2 * de->beta3) * res[i][de->Mcont] +
                                                                            de->q(i-1) * de->getFocus().getScale().thickness * de->h / (de->getFocus().getRoll().getLambda() * de->getFocus().getScale().thickness + de->getFocus().getScale().lambda * de->h)
                                                                           )));
        ui->tableWidget->item(i, MCut * 2 + 1)->setBackground(Qt::yellow);

        ui->tableWidget->setItem(i, MCut * 2 + 1 + 1, new QTableWidgetItem(QString::number(
                                                                           de->beta1 * de->beta3 / (1 - de->beta2 * de->beta3) * res[i][de->Mcont - 1] +
                                                                           de->beta4 / (1 - de->beta2 * de->beta3) * res[i][de->Mcont] +
                                                                           de->q(i-1) * de->getFocus().getScale().thickness * de->h * de->beta3 / ((de->getFocus().getRoll().getLambda() * de->getFocus().getScale().thickness + de->getFocus().getScale().lambda * de->h) * (1 - de->beta2 * de->beta3))
                                                                       )));
        ui->tableWidget->item(i, MCut * 2 + 1 + 1)->setBackground(Qt::darkMagenta);

        for(int j = MCut * 2 + 1, k = de->Mcont - 2 * MCut - 1; j <= Mmax; j++){
            ui->tableWidget->setItem(i, j + 2, new QTableWidgetItem(QString::number(res[i][j + k])));
            ui->tableWidget->item(i, j + 2)->setBackground(Qt::red);
        }
    }

    for(int j = 0; j < MCut * 2 + 1 + 1; j++){//пропускаем строку
        ui->tableWidget->setItem(de->N + 1, j, new QTableWidgetItem());
        ui->tableWidget->item(de->N + 1, j)->setBackground(Qt::black);
    }

    for(int i = de->N + 1 + 1, l = N - de->N - qMin(100, N / 10); i < de->N + qMin(100, N / 10) + 1; i++){
        for(int j = 0; j < MCut; j++){
            ui->tableWidget->setItem(i, j, new QTableWidgetItem(QString::number(res[i + l][j])));
            ui->tableWidget->item(i, j)->setBackground(Qt::cyan);
        }
        ui->tableWidget->setItem(i, MCut, new QTableWidgetItem());
        ui->tableWidget->item(i, MCut)->setBackground(Qt::black);//пропускаем столбец
        for(int j = MCut + 1, k = de->Mcont - 2 * MCut - 1; j < MCut * 2 + 1 + 1; j++){
            ui->tableWidget->setItem(i, j, new QTableWidgetItem(QString::number(res[i + l][j + k])));
            ui->tableWidget->item(i, j)->setBackground(Qt::cyan);
        }
    }
    ui->tableWidget->setHorizontalHeaderItem(MCut * 2 + 1,     new QTableWidgetItem("Стык"));
    ui->tableWidget->setHorizontalHeaderItem(MCut * 2 + 1 + 1, new QTableWidgetItem("Окалина"));

    //===============================вывод в файл===============================
    QFile file("output.csv");
    file.open(QIODevice::WriteOnly|QFile::Truncate);
    QString delim = ";";
    QTextStream stream(&file);
    stream.setLocale(QLocale(QLocale::Russian));
    for(int j = 0; j < de->Mcont; j++){
        stream << res[0][j] << delim;
    }
    stream << endl;
    for(int i = 1; i < de->N + 1; i++){
        angle = (i - 1) * de->theta;
        Mcur = qMax(de->MUpdate(angle, de->h) - 1 - 2, de->Mcont);
        for(int j = 0; j < de->Mcont; j++){
            stream << res[i][j] << delim;
        }

        stream <<
                  de->beta1 / (1 - de->beta2 * de->beta3) * res[i][de->Mcont - 1] +
                  de->beta2 * de->beta4 / (1 - de->beta2 * de->beta3) * res[i][de->Mcont] +
                  de->q(i-1) * de->getFocus().getScale().thickness * de->h / (de->getFocus().getRoll().getLambda() * de->getFocus().getScale().thickness + de->getFocus().getScale().lambda * de->h)
                                                                           << delim;

        stream <<
                  de->beta1 * de->beta3 / (1 - de->beta2 * de->beta3) * res[i][de->Mcont - 1] +
                  de->beta4 / (1 - de->beta2 * de->beta3) * res[i][de->Mcont] +
                  de->q(i-1) * de->getFocus().getScale().thickness * de->h * de->beta3 / ((de->getFocus().getRoll().getLambda() * de->getFocus().getScale().thickness + de->getFocus().getScale().lambda * de->h) * (1 - de->beta2 * de->beta3))
                                                                        << delim;

        for(int j = de->Mcont; j <= Mcur; j++){
           stream << res[i][j] << delim;
        }
        stream << endl;
    }

    for(int i = de->N + 1; i < N+1; i++){
        for(int j = 0; j < de->Mcont + 1; j++){
            stream << res[i][j] << delim;
        }
        stream << endl;
    }
    file.close();

    //===============================график q()===============================
    N = de->N + 1;
    QVector<double> x(N), y(N); //Массивы координат точек
    double maxY = 0, minY = 1e90;

    for (int i = 0; i < N; i++){
        x[i] = i;
        y[i] = de->qValue[i];
        if(y[i] > maxY) maxY = y[i];
        if(y[i] < minY) minY = y[i];
    }
    buildPlot(
                *ui->widget_q,
                QVector<Plot>({Plot(x, y, QString("Тепловой поток"))}),
                QPair<double, double>(0, N-1),
                QPair<double, double>(minY, maxY),
                QString("Номер точки  по длине очага"),
                QString("Вт/м^2")
                );

    //===============================график px()===============================
//    maxY = 0, minY = 1e90;

//    for (int i = 0; i < N; i++){
//        y[i] = de->pxCont[i];
//        if(de->pxCont[i] > maxY) maxY = de->pxCont[i];
//        if(de->pxCont[i] < minY) minY = de->pxCont[i];
//    }
//    buildPlot(
//                *ui->widget_px,
//                QVector<Plot>({Plot(x, y, QString("Нормальное давление"))}),
//                QPair<double, double>(0, N-1),
//                QPair<double, double>(minY/2, maxY*1.2),
//                QString("Номер точки  по длине очага"),
//                QString("МН/м^2"),
//                true
//                );

    //===============================график KDef===============================
    maxY = 0, minY = 1e90;

    for (int i = 0; i < N; i++){
        y[i] = de->Kdef(i * de->theta);
        if(y[i] > maxY) maxY = y[i];
        if(y[i] < minY) minY = y[i];
    }
    buildPlot(
                *ui->widget_KDef,
                QVector<Plot>({Plot(x, y, QString("Сопротивление деформации"))}),
                QPair<double, double>(0, N-1),
                QPair<double, double>(minY/2, maxY*1.2),
                QString("Номер точки  по длине очага"),
                QString("МН/м^2")
                );

    //===============================график tauCont===============================
    maxY = 0, minY = 1e90;
    for (int i = 0; i < N; i++){
        y[i] = de->tauContAbs[i];
        if(de->tauContAbs[i] > maxY) maxY = de->tauContAbs[i];
        if(de->tauContAbs[i] < minY) minY = de->tauContAbs[i];
    }// c tauShear не сверяю, потому что область показа функции все равно определяет только tauContAbs
    QVector<Plot> plotsTemp({Plot(x, y, QString("Касательное давление"))});
    for (int i = 0; i < N; i++){
        y[i] = de->tauShear[i];
    }
    plotsTemp.push_back(Plot(x, y, QString("Предел текучести")));
    buildPlot(
                *ui->widget_tauCont,
                plotsTemp,
                QPair<double, double>(0, N-1),
                QPair<double, double>(minY/2, maxY*1.2),
                QString("Номер точки  по длине очага"),
                QString("МН/м^2"),
                true
                );
    plotsTemp.clear();
    //===============================график температуры===============================

    maxY = 0, minY = 1e90;
    x.resize(de->MUpdate(de->getFocus().phi_max, de->h)-2 - de->Mcont);
    y.resize(de->MUpdate(de->getFocus().phi_max, de->h)-2 - de->Mcont);
    int index = N - 1;
    for (int i = 0; i < x.size(); i++){
        x[i] = i + de->Mcont;
        y[i] = res[index][i + de->Mcont];
        if(y[i] > maxY) maxY = y[i];
    }
    plotsTemp.push_back(Plot(x, y, QString("Полоса")));

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



    //===============================График температуры в глубину===============================

    this->buildHeatDeepPlot(ui->sliderDeep->value());

    //===============================Сообщение в конце===============================
    QMessageBox msgBox;

    msgBox.setWindowTitle("Расчет завершен!");
    msgBox.setStyleSheet("QLabel{min-width: 250px;}");

    msgBox.setText("phi ∈ [0; " + QString::number(de->getFocus().phi_max) +"] рад.\n"+
                              "Угол ∈ [0; " + QString::number(de->getFocus().phi_max*180/M_PI) +"] °\n"+
                              "Время ∈ [0; " + QString::number(de->getFocus().phi_max / de->getFocus().getRoll().getR() / de->getFocus().getRoll().getSpeed()) +"] c\n"+
                              "Номер точки стыка: " + QString::number(de->Mcont + 1)+"\n"+
                              "Шаг по радиусу: " + QString::number(de->h)+"м.\n"+
                              "Шаг по углу: " + QString::number(de->theta)+" рад.\n"+
                              "Посчиталось за " + QString::number((double)time.elapsed()/1000) + "c."+"\n"//+
                              //"Решалось " + QString::number(timeDifur) + "c."+"\n"+
                              //"Решалось2 " + QString::number(timeDifur2) + "c."
                              );
    msgBox.setDetailedText(info);
    msgBox.setStandardButtons(QMessageBox::Close);
    msgBox.exec();

    ui->pushButton_stop->hide();
    ui->pushButton_stop->setEnabled(false);
    ui->pushButton->show();
    ui->pushButton->setEnabled(true);

    emit finished();
}

void MainWindow::showError(QString err)
{
    QMessageBox::critical(this, "Ошибка!", err);
    thread->quit();
    ui->pushButton->setEnabled(true);
}

void MainWindow::updateEveryStep(int value)
{
    if((value - 1) % 10 == 0){
        this->buildHeatDeepPlot(ui->sliderDeep->value());
    }
    ui->progressBar->setValue(value);
    ui->progressBar->update();
}

void MainWindow::updateProgressBarMaxValue(int value)
{
    ui->progressBar->setMaximum(value);
    ui->progressBar->setTextVisible(true);
}

void MainWindow::onClick(){
    time.start();

    //calculator = new MainCalculator();
    this->setUpGui();

//    connect(calculator, SIGNAL (finished()), calculator, SLOT (deleteLater()));
//    connect(thread,     SIGNAL (finished()), thread,     SLOT (deleteLater()));

    thread->start();

    ui->pushButton->hide();
    ui->pushButton->setEnabled(false);
    ui->pushButton_stop->show();
    ui->pushButton_stop->setEnabled(true);
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
    widget.axisRect(0)->setRangeZoomAxes(widget.xAxis, widget.yAxis2);

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

void MainWindow::on_openSettings_triggered()
{
    Settings *settings = new Settings();
    settings->setModal(true);
    //settings->setWindowModality(Qt::ApplicationModal);
    settings->loadLocal();
    settings->show();
}

void MainWindow::on_loadSettings_triggered()
{
    Settings *settings = new Settings();
    settings->on_pushButton_2_clicked();
    delete settings;
}

void MainWindow::buildHeatDeepPlot(int value)
{
    diffEquation* de = this->calculator->de;
    int N = de->N + de->Nnonfocus;

    QVector<QVector<double>> res;
    res.resize(N + 1);
    for(int i = 0; i < N + 1; i++){
        std::copy(de->getResult(i), de->getResult(i) + (i > de->N ? de->Mcont + 1:de->M - 2), std::back_inserter(res[i]));
    }

    int rIndex = qRound(((double)(de->Mcont - 1) / ui->sliderDeep->maximum()) * value);

    QVector<double> x(N), y(N); //Массивы координат точек
    double maxY = 0, minY = 1e90;

    for (int i = 0; i < N; i++){
        x[i] = i;
        y[i] = res[i][rIndex];
        if(y[i] > maxY) maxY = y[i];
        if(y[i] < minY) minY = y[i];
    }
    buildPlot(
                *ui->widget_TDeep,
                QVector<Plot>({Plot(x, y, QString("Температура"))}),
                QPair<double, double>(0, N-1),
                QPair<double, double>(minY/2, maxY*1.2),
                QString("Номер точки по окружности в глубине"),
                QString("°C")
                );
}

void MainWindow::on_sliderDeep_valueChanged(int value)
{
    double r = calculator->settings.value("R").toDouble() * 1000;
    double step = r / calculator->de->Mcont;
    ui->label_deepMid->setText(QString::number(value * step, 'f', 2) + QString("мм"));
}

void MainWindow::on_sliderDeep_sliderMoved(int value)
{
    if(this->calculator->hasCounted() || this->calculator->isCounting()){
        this->buildHeatDeepPlot(value);
    }
}

void MainWindow::on_pushButton_stop_clicked()
{
    if(!this->calculator->isCounting()){
        return;
    }
    qDebug() << "stop";
    emit stopped();
}
