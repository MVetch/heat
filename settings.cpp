#include "settings.h"
#include "ui_settings.h"

QString Settings::saveFileName = "settings.json";

int Settings::amountOfSettings = 15;

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

void Settings::writeFocus(QJsonObject &json)
{
    if (ui->lineRad->text() == "" ||
            ui->lambda_v_edit->text() == "" ||
            ui->rho_v_edit->text() == "" ||
            ui->c_v_edit->text() == "" ||
            ui->lambda_p_edit->text() == "" ||
            ui->rho_p_edit->text() == "" ||
            ui->c_p_edit->text() == "" ||
            ui->editH_b->text() == "" ||
            ui->editH_a->text() == "" ||
            ui->hStep->text() == "" ||
            ui->thetaStep->text() == "" ||
            ui->airT->text() == "" ||
            ui->waterT->text() == ""){
        QMessageBox::critical(this, "Ошибка!", "Не все поля заполнены!");
    } else {
        json["R"] = ui->lineRad->value()/1000;

        json["lambda_v"] = ui->lambda_v_edit->value();
        json["rho_v"] = ui->rho_v_edit->value();
        json["c_v"] = ui->c_v_edit->value();

        json["lambda_p"] = ui->lambda_p_edit->value();
        json["rho_p"] = ui->rho_p_edit->value();
        json["c_p"] = ui->c_p_edit->value();

        json["h_b"] = ui->editH_b->value()/1000;
        json["h_a"] = ui->editH_a->value()/1000;

        json["M"] = ui->hStep->value();
        json["N"] = ui->thetaStep->value();

        json["airT"] = ui->airT->value();
        json["waterT"] = ui->waterT->value();

        json["timeToModel"] = ui->timeToModel->value();
        json["vSpin"] = ui->vSpin->value();
    }
}

void Settings::load()
{
    QFile fsettigs(Settings::saveFileName);
    fsettigs.open(QIODevice::ReadOnly);
    QJsonObject fobj = QJsonDocument(QJsonDocument::fromJson(fsettigs.readAll())).object();
    if(!fobj.value("R").isUndefined()){
        ui->lineRad->setValue(fobj.value("R").toDouble() * 1000);
    }
    if(!fobj.value("lambda_v").isUndefined()){
        ui->lambda_v_edit->setValue(fobj.value("lambda_v").toDouble());
    }
    if(!fobj.value("rho_v").isUndefined()){
        ui->rho_v_edit->setValue(fobj.value("rho_v").toDouble());
    }
    if(!fobj.value("c_v").isUndefined()){
        ui->c_v_edit->setValue(fobj.value("c_v").toDouble());
    }
    if(!fobj.value("lambda_p").isUndefined()){
        ui->lambda_p_edit->setValue(fobj.value("lambda_p").toDouble());
    }
    if(!fobj.value("rho_p").isUndefined()){
        ui->rho_p_edit->setValue(fobj.value("rho_p").toDouble());
    }
    if(!fobj.value("c_p").isUndefined()){
        ui->c_p_edit->setValue(fobj.value("c_p").toDouble());
    }
    if(!fobj.value("h_b").isUndefined()){
        ui->editH_b->setValue(fobj.value("h_b").toDouble() * 1000);
    }
    if(!fobj.value("h_a").isUndefined()){
        ui->editH_a->setValue(fobj.value("h_a").toDouble() * 1000);
    }
    if(!fobj.value("M").isUndefined()){
        ui->hStep->setValue(fobj.value("M").toInt());
    }
    if(!fobj.value("N").isUndefined()){
        ui->thetaStep->setValue(fobj.value("N").toInt());
    }
    if(!fobj.value("airT").isUndefined()){
        ui->airT->setValue(fobj.value("airT").toDouble());
    }
    if(!fobj.value("waterT").isUndefined()){
        ui->waterT->setValue(fobj.value("waterT").toDouble());
    }
    if(!fobj.value("timeToModel").isUndefined()){
        ui->timeToModel->setValue(fobj.value("timeToModel").toDouble());
    }
    if(!fobj.value("vSpin").isUndefined()){
        ui->vSpin->setValue(fobj.value("vSpin").toDouble());
    }
}

void Settings::on_pushButton_clicked()
{
    QJsonObject settings;
    writeFocus(settings);
    if(!settings.empty())
    {
        QJsonDocument saveDoc(settings);
        QFile saveFile(saveFileName);
        saveFile.open(QIODevice::WriteOnly);
        saveFile.write(saveDoc.toJson());
    }
}
