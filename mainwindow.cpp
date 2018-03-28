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


//    ui->tableWidget->setColumnCount(res.size());
//    ui->tableWidget->setRowCount(res[0].size());

    //вывод в таблицу
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

    //график q();
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
                QVector<Plot>(1, Plot(x, y, QString("Тепловой поток"))),
                QPair<double, double>(0, de.N-1),
                QPair<double, double>(minY, maxY),
                QString("Номер точки  по длине очага"),
                QString("Вт/м^2")
                );

    //график px();
    x.resize(de.N), y.resize(de.N); //Массивы координат точек
    ui->widget_px->clearGraphs();
    maxY = 0, minY = 1e90;

    for (int i = 0; i < de.N; i++){
        x[i] = i;
        y[i] = de.pxCont[i];
        if(y[i] > maxY) maxY = y[i];
        if(y[i] < minY) minY = y[i];
    }
    ui->widget_px->xAxis->setRange(0, res.size());//Для оси Ox
    ui->widget_px->yAxis->setRange(minY/2, maxY*1.2);//Для оси Oy
    ui->widget_px->xAxis->setLabel("Номер точки  по длине очага");
    ui->widget_px->yAxis->setLabel("МН/м^2");
    ui->widget_px->addGraph();
    ui->widget_px->graph(0)->setData(x, y);
    ui->widget_px->graph(0)->setPen(QPen(Qt::red));
    ui->widget_px->graph(0)->setBrush(QBrush(QColor(255, 0, 0, 70)));
    ui->widget_px->graph(0)->setName("Нормальное давление");

    ui->widget_px->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);


    ui->widget_px->legend->setVisible(true);
    ui->widget_px->legend->setBrush(QBrush(QColor(255,255,255,150)));
    ui->widget_px->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignLeft|Qt::AlignTop);

    ui->widget_px->replot();

    //график KDef;
    x.resize(de.N), y.resize(de.N); //Массивы координат точек
    ui->widget_KDef->clearGraphs();
    maxY = 0, minY = 1e90;

    for (int i = 0; i < de.N; i++){
        x[i] = i;
        y[i] = de.Kdef(i * de.theta);
        if(y[i] > maxY) maxY = y[i];
        if(y[i] < minY) minY = y[i];
    }
    ui->widget_KDef->xAxis->setRange(0, res.size());//Для оси Ox
    ui->widget_KDef->yAxis->setRange(minY/2, maxY*1.2);//Для оси Oy
    ui->widget_KDef->xAxis->setLabel("Номер точки  по длине очага");
    ui->widget_KDef->yAxis->setLabel("МН/м^2");
    ui->widget_KDef->addGraph();
    ui->widget_KDef->graph(0)->setData(x, y);
    ui->widget_KDef->graph(0)->setPen(QPen(Qt::red));
    ui->widget_KDef->graph(0)->setBrush(QBrush(QColor(255, 0, 0, 70)));
    ui->widget_KDef->graph(0)->setName("Сопротивление деформации");

    ui->widget_KDef->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    ui->widget_KDef->legend->setVisible(true);
    ui->widget_KDef->legend->setBrush(QBrush(QColor(255,255,255,150)));
    ui->widget_KDef->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignLeft|Qt::AlignTop);

    ui->widget_KDef->replot();

    //график tauCont;
    x.resize(de.N), y.resize(de.N); //Массивы координат точек
    ui->widget_tauCont->clearGraphs();
    maxY = 0, minY = 1e90;

    for (int i = 0; i < de.N; i++){
        x[i] = i;
        y[i] = de.tauContAbs[i];
        if(y[i] > maxY) maxY = y[i];
        if(y[i] < minY) minY = y[i];
    }
    ui->widget_tauCont->xAxis->setRange(0, res.size());//Для оси Ox
    ui->widget_tauCont->yAxis->setRange(minY/2, maxY*1.2);//Для оси Oy
    ui->widget_tauCont->xAxis->setLabel("Номер точки  по длине очага");
    ui->widget_tauCont->yAxis->setLabel("МН/м^2");
    ui->widget_tauCont->addGraph();
    ui->widget_tauCont->graph(0)->setData(x, y);
    ui->widget_tauCont->graph(0)->setPen(QPen(Qt::red));
    ui->widget_tauCont->graph(0)->setBrush(QBrush(QColor(255, 0, 0, 70)));
    ui->widget_tauCont->graph(0)->setName("Касательное давление");

    for (int i = 0; i < de.N; i++){
        x[i] = i;
        y[i] = de.tauShear[i];
        if(y[i] > maxY) maxY = y[i];
        if(y[i] < minY) minY = y[i];
    }
    ui->widget_tauCont->addGraph();
    ui->widget_tauCont->graph(1)->setData(x, y);
    ui->widget_tauCont->graph(1)->setPen(QPen(Qt::cyan));
    ui->widget_tauCont->graph(1)->setBrush(QBrush(QColor(0, 255, 255, 70)));
    ui->widget_tauCont->graph(1)->setName("Предел текучести");

    ui->widget_tauCont->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    ui->widget_tauCont->legend->setVisible(true);
    ui->widget_tauCont->legend->setBrush(QBrush(QColor(255,255,255,150)));
    ui->widget_tauCont->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignLeft|Qt::AlignTop);

    ui->widget_tauCont->replot();

    //график температуры
    int index = res.size() - 1, Mlast = de.MUpdate(de.getFocus().phi_max, de.h);
    x.resize(de.Mcont+1);
    y.resize(de.Mcont+1);
    ui->widget_T->clearGraphs();
    maxY = 0, minY = 1e90;
    for (int i = 0; i <= de.Mcont; i++){
        x[i] = i;
        y[i] = res[index][i];
        if(y[i] > maxY) maxY = y[i];
        if(y[i] < minY) minY = y[i];
    }
    ui->widget_T->addGraph();
    ui->widget_T->graph(0)->setData(x, y);
    ui->widget_T->graph(0)->setPen(QPen(Qt::cyan));
    ui->widget_T->graph(0)->setBrush(QBrush(QColor(0, 255, 255, 70)));
    ui->widget_T->graph(0)->setName("Валок");

    x.resize(Mlast - de.Mcont);
    y.resize(Mlast - de.Mcont);
    for (int i = 0; i < Mlast - de.Mcont; i++){
        x[i] = i + de.Mcont;
        y[i] = res[index][i + de.Mcont];
        if(y[i] > maxY) maxY = y[i];
        if(y[i] < minY) minY = y[i];
    }
    ui->widget_T->addGraph();
    ui->widget_T->graph(1)->setData(x, y);
    ui->widget_T->graph(1)->setPen(QPen(Qt::red));
    ui->widget_T->graph(1)->setBrush(QBrush(QColor(255, 0, 0, 70)));
    ui->widget_T->graph(1)->setName("Полоса");

    ui->widget_T->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    ui->widget_T->legend->setVisible(true);
    ui->widget_T->legend->setBrush(QBrush(QColor(255,255,255,150)));
    ui->widget_T->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignLeft|Qt::AlignTop);

    ui->widget_T->xAxis->setRange(0, Mlast);//Для оси Ox
    ui->widget_T->yAxis->setRange(minY/2, maxY*1.2);//Для оси Oy
    ui->widget_T->xAxis->setLabel("Номер точки в глубину");
    ui->widget_T->yAxis->setLabel("°C");
    ui->widget_T->replot();

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
        widget.graph(i)->setPen(QPen(colors[i % 9]));
        widget.graph(i)->setBrush(QBrush(
                                        QColor(
                                            colors[i % 9].red(),
                                            colors[i % 9].green(),
                                            colors[i % 9].blue(),
                                            70
                                        )
                                      )
                                  );
        widget.graph(i)->setName(plots[i].name);
    }

    widget.setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    widget.legend->setVisible(true);
    widget.legend->setBrush(QBrush(QColor(255,255,255,150)));
    widget.axisRect()->insetLayout()->setInsetAlignment(0, legendAlignLeft?Qt::AlignRight:Qt::AlignRight|legendAlignTop?Qt::AlignTop:Qt::AlignBottom);

    widget.replot();
}
