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
    ui->widget_q->clearGraphs();
    double maxY = 0, minY = 1e90;

    for (int i = 0; i < de.N; i++){
        x[i] = i;
        y[i] = de.q(i);
        if(y[i] > maxY) maxY = y[i];
        if(y[i] < minY) minY = y[i];
    }
    ui->widget_q->xAxis->setRange(0, res.size());//Для оси Ox
    ui->widget_q->yAxis->setRange(minY/2, maxY*1.2);//Для оси Oy
    ui->widget_q->xAxis->setLabel("Номер точки  по длине очага");
    ui->widget_q->yAxis->setLabel("Вт/м^2");
    ui->widget_q->addGraph();
    ui->widget_q->graph(0)->setData(x, y);
    ui->widget_q->graph(0)->setPen(QPen(Qt::red));
    ui->widget_q->graph(0)->setBrush(QBrush(QColor(255, 0, 0, 70)));
    ui->widget_q->graph(0)->setName("Тепловой поток");

    ui->widget_q->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    //ui->widget_q->axisRects().at(0)->setRangeDrag(Qt::Vertical);

    ui->widget_q->legend->setVisible(true);
    ui->widget_q->legend->setBrush(QBrush(QColor(255,255,255,150)));
    ui->widget_q->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignRight|Qt::AlignTop);

    ui->widget_q->replot();

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

//    QImage heatGraph(QSize(ui->labelforpicture->width(),ui->labelforpicture->height()), QImage::Format_RGB32);
//    double val = 0;

//    double max = res[0][0], min = res[0][0];
//    for(int i = 0; i < res.size(); i++){
//        for(int j = 0; j < res[i].size(); j++){
//            if(max < res[i][j]) max = res[i][j];
//            if(min > res[i][j]) min = res[i][j];
//        }
//    }
//    double Xc, Yc;

//    int _i, _j;
//    //double h = de.h;
//    //картинка в полярных координатах
//    QColor color;
//    double r_max = (focus.r_max - R + focus.getRoll().countmmToHeat());
//    for (int i = 0; i < heatGraph.width(); i++){
//        _i = (double)(i*res.size())/heatGraph.width();
//        angle = (double)(i*focus.phi_max)/heatGraph.width();
//        //r_max = focus.maxR(angle) - R + focus.getRoll().countmmToHeat();

//        for (int j = 0; j < heatGraph.height(); j++){
//            _j =  (double)(j*de.MUpdate(angle, de.h))/heatGraph.height();
//            val = (res[_i][_j] - min)/(max - min);
//            Yc = Y((_j*de.h + R - focus.getRoll().countmmToHeat())*((double)heatGraph.width() /focus.r_max), angle-focus.phi_max)+focus.length*((double)heatGraph.height()/focus.r_max);
//            Xc = X((_j*de.h + R - focus.getRoll().countmmToHeat())*((double)heatGraph.height()/focus.r_max), angle-focus.phi_max);
//            color = QColor(255*val,//255*val,
//                           0,
//                           255*(1-val),
//                           255
//                          );
//            heatGraph.setPixelColor(Yc,Xc,color);
//            heatGraph.setPixelColor(qMax(Yc-1,0.0),Xc,color);
//            heatGraph.setPixelColor(Yc,qMax(Xc-1,0.0),color);
//            heatGraph.setPixelColor(qMin(Yc+1,(double)heatGraph.width()),Xc,color);
//            heatGraph.setPixelColor(Yc,qMin(Xc,(double)heatGraph.height()),color);
//        }
//    }

//    ui->labelforpicture->setPixmap(QPixmap::fromImage(heatGraph));

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
