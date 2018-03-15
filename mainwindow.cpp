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
    double R = ui->lineRad->text().toDouble();
    Roll roll(
                R,
                ui->rho_v_edit->text().toDouble(),
                ui->c_v_edit->text().toDouble(),
                ui->lambda_v_edit->text().toDouble()
              );

    double h_b = ui->editH_b->text().toDouble();
    double h_a = ui->editH_a->text().toDouble();
    double h = ui->hStep->text().toDouble();
    double theta_step = ui->thetaStep->text().toDouble();
    double initF = ui->fValue->text().toDouble();
    double initQ = ui->qValue->text().toDouble();
    Focus focus(h_b, h_a, roll);

    diffEquation de(
                h,
                theta_step,
                focus,
                ui->lambda_p_edit->text().toDouble(),
                ui->rho_p_edit->text().toDouble(),
                ui->c_p_edit->text().toDouble(),
                initF,
                initQ
                );
    de.solve();
    QVector<QVector<double>> res = de.getResult();

    int _i, _j;
    double angle = 0;


//    ui->tableWidget->setColumnCount(res.size());
//    ui->tableWidget->setRowCount(res[0].size());

    //вывод в таблицу
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(res.size());
    ui->tableWidget->setColumnCount(de.Mmax);
    QTableWidgetItem *newItem;
    int M = de.MUpdate(de.beta, h), Mcont = de.MUpdate(0, h)-1, Mcur = 0; // число шагов по x и точка контакта
    QString bepis = "";
    for(int i = 0; i < res.size(); i++){
        angle = i*theta_step;
        Mcur = de.MUpdate(angle, h);
        bepis+="phi = " + QString::number(angle) + "рад. / " + QString::number(angle*180/M_PI) + "°\t r = " +QString::number(de.maxR(angle))+ ";\n";
        //Mcur = res[i].size();
        for(int j = 0; j < Mcur; j++){
            newItem = new QTableWidgetItem(QString::number(res[i][j]));
            ui->tableWidget->setItem(i, j, newItem);
            if(j > Mcont+1)
                ui->tableWidget->item(i, j)->setBackground(Qt::red);
            else if (j==Mcont || j==Mcont+1)
                ui->tableWidget->item(i, j)->setBackground(Qt::yellow);
            else
                ui->tableWidget->item(i, j)->setBackground(Qt::cyan);
            if(i == qRound(de.beta/theta_step))
                ui->tableWidget->item(i, j)->setBackground(Qt::green);
        }
    }

    //график радиуса
//    QVector<double> x(5000), y(5000); //Массивы координат точек
//    ui->widget->clearGraphs();
//    for (int i = 0; i < 5000; i++){
//        angle = (double)(i*phi_max)/5000;
//        curRmax = de.hUpdate(angle, 1);
//        //x[i] = it;
//        //y[i] = curRmax;
//        y[i] = Y(curRmax, angle);
//        x[i] = X(curRmax, angle);
//    }
//    ui->widget->xAxis->setRange(X(R, 0), 2*X(r_max, phi_max));//Для оси Ox
//    ui->widget->yAxis->setRange(Y(R, 0), Y(r_max, phi_max));//Для оси Oy
//    ui->widget->addGraph();
//    ui->widget->graph(0)->setData(x, y);
//    ui->widget->replot();

    QImage heatGraph(QSize(ui->labelforpicture->width(),ui->labelforpicture->height()), QImage::Format_RGB32);
    double val = 0;

    double max = res[0][0], min = res[0][0];
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            if(max < res[i][j]) max = res[i][j];
            if(min > res[i][j]) min = res[i][j];
        }
    }
    double Xc, Yc;

    //картинка в полярных координатах
//    QColor color;
//    for (int i = 0; i < heatGraph.width(); i++){
//        _i = (double)(i*res.size())/heatGraph.width();
//        angle = (double)(i*de.phi_max)/heatGraph.width();

//        for (int j = 0; j < heatGraph.height(); j++){
//            _j = (double)(j*de.MUpdate(angle, h))/heatGraph.height();
//            val = (res[_i][_j] - min)/(max - min);
//            Yc = Y((_j*h)*((double)heatGraph.height()/de.r_max), angle-de.phi_max)+qSqrt(R*(h_b-h_a) - (h_b-h_a)*(h_b-h_a)/4)*((double)heatGraph.height()/de.r_max);;
//            Xc = X((_j*h)*((double)heatGraph.height()/de.r_max), angle-de.phi_max);
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

//    QColor color;
//    double h_v = h, h_p;
//    for (int i = 0; i < heatGraph.width(); i++){
//        _i = (double)(i*res.size())/heatGraph.width();
//        angle = (double)(i*de.phi_max)/heatGraph.width();
//        h_p = (de.maxR(angle) - R)/(M - Mcont);
//        for (int j = 0; j < heatGraph.height(); j++){
//            _j = (double)(j*res[_i].size())/heatGraph.height();
//            val = (res[_i][_j] - min)/(max - min);
//            if(_j > Mcont){
//                h = h_p;
//            } else {
//                h = h_v;
//            }
//            Yc = Y((qMin(Mcont, _j)*h_v + (_j>Mcont?(M - _j):0)*h)*((double)heatGraph.width()/de.r_max), angle);
//            Xc = X((qMin(Mcont, _j)*h_v + (_j>Mcont?(M - _j):0)*h)*((double)heatGraph.height()/de.r_max), angle);
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
    //ui->labelforpicture->setPixmap(QPixmap::fromImage(heatGraph));

    QMessageBox msgBox;

    msgBox.setText("Посчиталось!");
    msgBox.setStyleSheet("QLabel{min-width: 300px;}");

    msgBox.setInformativeText("phi ∈ [0; " + QString::number(de.phi_max) +"] рад.\n"+
                              "phi ∈ [0; " + QString::number(de.phi_max*180/M_PI) +"] °");
    msgBox.setDetailedText(bepis);
    msgBox.setWhatsThis("bepis");
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
