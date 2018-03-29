#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onClick()));
    //this->setStyleSheet("*{font-size:10px;}");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onClick(){
    double R = ui->lineRad->text().toDouble()/1000;
    Roll roll(
                R,
                ui->rho_v_edit->text().toDouble(),
                ui->c_v_edit->text().toDouble(),
                ui->lambda_v_edit->text().toDouble()
              );

    double h_b = ui->editH_b->text().toDouble()/1000;
    double h_a = ui->editH_a->text().toDouble()/1000;
    double M = ui->hStep->text().toInt();
    double N = ui->thetaStep->text().toInt();
    Strip strip(1.357,
                ui->lambda_p_edit->text().toDouble(),
                ui->rho_p_edit->text().toDouble(),
                ui->c_p_edit->text().toDouble()
                );
    Focus focus(h_b, h_a, roll, strip);

    diffEquation de(
                M,
                N,
                focus
                );
    de.solve();
    QVector<QVector<double>> res = de.getResult();

    double angle = 0;

    //===============================вывод в таблицу===============================
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(res.size());
    ui->tableWidget->setColumnCount(de.M);
    QTableWidgetItem *newItem;
    int Mcur = 0; // число шагов по x и точка контакта
    QString info = "";
    for(int i = 0; i < res.size(); i++){
        angle = i*de.theta;
        Mcur = de.MUpdate(angle, de.h);
        info+="phi = " + QString::number(angle, 'f', 5) + "рад. / " +
                         QString::number(angle*180/M_PI, 'f', 5) + "°\t r = " +
                         QString::number(focus.maxR(angle), 'f', 5)+ ";\n";
        //Mcur = res[i].size();
        for(int j = 0; j < Mcur; j++){
            newItem = new QTableWidgetItem(QString::number(res[i][j]));
            ui->tableWidget->setItem(i, j, newItem);
            if(j > de.Mcont+1)
                ui->tableWidget->item(i, j)->setBackground(Qt::red);
            else if (j==de.Mcont)
                ui->tableWidget->item(i, j)->setBackground(Qt::yellow);
            else if (j==de.Mcont+1)
                ui->tableWidget->item(i, j)->setBackground(Qt::darkMagenta);
            else
                ui->tableWidget->item(i, j)->setBackground(Qt::cyan);
            if(i == qRound(focus.beta/de.theta))
                ui->tableWidget->item(i, j)->setBackground(Qt::green);
        }
    }
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->setHorizontalHeaderItem(de.Mcont, new QTableWidgetItem("Стык"));
    ui->tableWidget->setHorizontalHeaderItem(de.Mcont + 1, new QTableWidgetItem("Окалина"));

    //===============================график q()===============================
    QVector<double> x(de.N), y(de.N); //Массивы координат точек
    double maxY = 0, minY = 1e90;

    for (int i = 0; i < de.N; i++){
        x[i] = i;
        y[i] = de.q(i);
        if(y[i] > maxY) maxY = y[i];
        if(y[i] < minY) minY = y[i];
    }
    buildPlot(
                *ui->widget_q,
                QVector<Plot>({Plot(x, y, QString("Тепловой поток"))}),
                QPair<double, double>(0, de.N-1),
                QPair<double, double>(minY, maxY),
                QString("Номер точки  по длине очага"),
                QString("Вт/м^2")
                );

    //===============================график px()===============================
    maxY = 0, minY = 1e90;

    for (int i = 0; i < de.N; i++){
        y[i] = de.pxCont[i];
        if(y[i] > maxY) maxY = y[i];
        if(y[i] < minY) minY = y[i];
    }
    buildPlot(
                *ui->widget_px,
                QVector<Plot>({Plot(x, y, QString("Нормальное давление"))}),
                QPair<double, double>(0, de.N-1),
                QPair<double, double>(minY/2, maxY*1.2),
                QString("Номер точки  по длине очага"),
                QString("МН/м^2")
                );

    //===============================график KDef===============================
    maxY = 0, minY = 1e90;

    for (int i = 0; i < de.N; i++){
        y[i] = de.Kdef(i * de.theta);
        if(y[i] > maxY) maxY = y[i];
        if(y[i] < minY) minY = y[i];
    }
    buildPlot(
                *ui->widget_KDef,
                QVector<Plot>({Plot(x, y, QString("Сопротивление деформации"))}),
                QPair<double, double>(0, de.N-1),
                QPair<double, double>(minY/2, maxY*1.2),
                QString("Номер точки  по длине очага"),
                QString("МН/м^2")
                );

    //===============================график tauCont===============================
    maxY = 0, minY = 1e90;
    for (int i = 0; i < de.N; i++){
        if(de.tauContAbs[i] > maxY) maxY = de.tauContAbs[i];
        if(de.tauContAbs[i] < minY) minY = de.tauContAbs[i];
    }// c tauShear не сверяю, потому что область показа функции все равно определяет только tauContAbs
    buildPlot(
                *ui->widget_tauCont,
                QVector<Plot>({Plot(x, de.tauContAbs, QString("Касательное давление")), Plot(x, de.tauShear, QString("Предел текучести"))}),
                QPair<double, double>(0, de.N-1),
                QPair<double, double>(minY/2, maxY*1.2),
                QString("Номер точки  по длине очага"),
                QString("МН/м^2")
                );

    //===============================график температуры===============================
    int index = res.size() - 1;
    x.resize(de.Mcont+1);
    y.resize(de.Mcont+1);
    maxY = 0, minY = 1e90;
    for (int i = 0; i <= de.Mcont; i++){
        x[i] = i;
        y[i] = res[index][i];
        if(y[i] > maxY) maxY = y[i];
        if(y[i] < minY) minY = y[i];
    }
    QVector<Plot> plotsTemp({Plot(x, y, QString("Валок"))});

    x.resize(de.M - de.Mcont);
    y.resize(de.M - de.Mcont);
    for (int i = 0; i < de.M - de.Mcont; i++){
        x[i] = i + de.Mcont;
        y[i] = res[index][i + de.Mcont];
        if(y[i] > maxY) maxY = y[i];
        if(y[i] < minY) minY = y[i];
    }
    plotsTemp.push_back(Plot(x, y, QString("Полоса")));
    buildPlot(
                *ui->widget_T,
                plotsTemp,
                QPair<double, double>(0, de.M),
                QPair<double, double>(minY/2, maxY*1.2),
                QString("Номер точки в глубину"),
                QString("°C")
                );
    //===============================Сообщение в конце===============================
    QMessageBox msgBox;

    msgBox.setText("Посчиталось!");
    msgBox.setStyleSheet("QLabel{min-width: 300px;}");

    msgBox.setInformativeText("phi ∈ [0; " + QString::number(focus.phi_max) +"] рад.\n"+
                              "phi ∈ [0; " + QString::number(focus.phi_max*180/M_PI) +"] °\n"+
                              "t ∈ [0; " + QString::number(focus.phi_max / focus.getRoll().getR() / 73 * 60) +"] c\n"+
                              "Номер точки стыка: " + QString::number(de.Mcont + 1)+"\n"+
                              "Шаг по r: " + QString::number(de.h)+"\n"+
                              "Шаг по phi: " + QString::number(de.theta)
                              );
    msgBox.setDetailedText(info);
    msgBox.setStandardButtons(QMessageBox::Close);
    msgBox.exec();
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
    widget.axisRect()->insetLayout()->setInsetAlignment(0, legendAlignLeft?Qt::AlignLeft:Qt::AlignRight|legendAlignTop?Qt::AlignTop:Qt::AlignBottom);

    widget.replot();
}
