#include "settings.h"
#include "ui_settings.h"

QString Settings::saveFileName = "settings.json";

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::write(QJsonObject &json)
{
    json["R"] = ui->lineRad->text().toDouble()/1000;

    json["lambda_v"] = ui->lambda_v_edit->text().toDouble();
    json["rho_v"] = ui->rho_v_edit->text().toDouble();
    json["c_v"] = ui->c_v_edit->text().toDouble();

    json["lambda_p"] = ui->lambda_p_edit->text().toDouble();
    json["rho_p"] = ui->rho_p_edit->text().toDouble();
    json["c_p"] = ui->c_p_edit->text().toDouble();

    json["h_b"] = ui->editH_b->text().toDouble()/1000;
    json["h_a"] = ui->editH_a->text().toDouble()/1000;
    json["M"] = ui->hStep->text().toInt();
    json["N"] = ui->thetaStep->text().toInt();
}

void Settings::on_pushButton_clicked()
{
    QJsonObject settings;
    write(settings);
    QJsonDocument saveDoc(settings);
    QFile saveFile(saveFileName);
    saveFile.open(QIODevice::WriteOnly);
    saveFile.write(saveDoc.toJson());
}
