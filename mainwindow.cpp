#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onClick()));
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
    ui->tableWidget->setHorizontalHeaderItem(de.Mcont, new QTableWidgetItem("Стык"));
    ui->tableWidget->setHorizontalHeaderItem(de.Mcont + 1, new QTableWidgetItem("Окалина"));

    //график радиуса
//    QVector<double> x(5000), y(5000); //Массивы координат точек
//    ui->widget->clearGraphs();
//    double curRmax;
//    for (int i = 0; i < 5000; i++){
//        angle = (double)(i*focus.phi_max)/5000;
//        curRmax = focus.maxR(angle);
//        //x[i] = it;
//        //y[i] = curRmax;
//        y[i] = Y(curRmax, angle);
//        x[i] = X(curRmax, angle);
//    }
//    ui->widget->xAxis->setRange(X(R, 0), 2*X(focus.r_max, focus.phi_max));//Для оси Ox
//    ui->widget->yAxis->setRange(Y(R, 0), Y(focus.r_max, focus.phi_max));//Для оси Oy
//    ui->widget->addGraph();
//    ui->widget->graph(0)->setData(x, y);
//    ui->widget->replot();


    //график q()
    QVector<double> x(res.size()), y(res.size()); //Массивы координат точек
    ui->widget->clearGraphs();
    double maxY = 0, minY = 1e90;
    for (int i = 0; i < res.size(); i++){
        x[i] = i;
        y[i] = de.q(i+1);
        if(y[i] > maxY) maxY = y[i];
        if(y[i] < minY) minY = y[i];
    }
    ui->widget->xAxis->setRange(0, res.size());//Для оси Ox
    ui->widget->yAxis->setRange(minY/2, maxY*1.2);//Для оси Oy
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);
    ui->widget->graph(0)->setPen(QPen(Qt::red));
    ui->widget->graph(0)->setBrush(QBrush(QColor(255, 0, 0, 20)));
    ui->widget->graph(0)->setName("Тепловой поток");

    ui->widget->setInteractions(QCP::iRangeDrag);
    ui->widget->axisRects().at(0)->setRangeDrag(Qt::Vertical);

    ui->widget->legend->setVisible(true);
    ui->widget->legend->setBrush(QBrush(QColor(255,255,255,150)));
    ui->widget->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignRight|Qt::AlignTop);

    ui->widget->replot();

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
