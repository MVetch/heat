#include "settings.h"
#include "ui_settings.h"

QString Settings::saveFileName = "settings/localSettings.hrp";

int Settings::amountOfSettings = 16;

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    this->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->ui->injectorsInfo->setColumnWidth(0, 170);
    this->ui->injectorsInfo->setColumnWidth(1, 80);
    this->ui->injectorsInfo->setColumnWidth(2, 90);
    for (int i = 0; i < ui->injectorsInfo->rowCount(); i++)
    {
        QDoubleSpinBox *sb = new QDoubleSpinBox(ui->injectorsInfo);
        sb->setMaximum(400);
        sb->setMinimum(10);
        sb->setSingleStep(0.1);
        sb->setDecimals(1);
        sb->setValue(ui->injectorsInfo->item(i, 0)->text().replace(",", ".").toDouble());
        ui->injectorsInfo->setCellWidget(i, 0, sb);

        sb = new QDoubleSpinBox(ui->injectorsInfo);
        sb->setMaximum(360);
        sb->setMinimum(10);
        sb->setSingleStep(0.1);
        sb->setDecimals(2);
        sb->setValue(ui->injectorsInfo->item(i, 1)->text().replace(",", ".").toDouble());
        ui->injectorsInfo->setCellWidget(i, 1, sb);

        sb = new QDoubleSpinBox(ui->injectorsInfo);
        sb->setMaximum(40);
        sb->setMinimum(1);
        sb->setSingleStep(0.01);
        sb->setDecimals(2);
        sb->setValue(ui->injectorsInfo->item(i, 2)->text().replace(",", ".").toDouble());
        ui->injectorsInfo->setCellWidget(i, 2, sb);
    }
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
            ui->waterT->text() == "" ||
            ui->timeToModel->text() == "" ||
            ui->vSpin->text() == "" ||
            ui->mmToHeat->text() == ""){
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

        json["waterT"] = ui->waterT->value();
        QJsonArray injDens;
        for (int i = 0; i < ui->injectorsInfo->rowCount(); i++)
        {
            QJsonObject temp;
            temp.insert(QStringLiteral("density"),    ((QDoubleSpinBox *)ui->injectorsInfo->cellWidget(i, 0))->value());
            temp.insert(QStringLiteral("angleStart"), ((QDoubleSpinBox *)ui->injectorsInfo->cellWidget(i, 1))->value());
            temp.insert(QStringLiteral("angleSize"),  ((QDoubleSpinBox *)ui->injectorsInfo->cellWidget(i, 2))->value());
            injDens.push_back(temp);
        }
        json["injectors"] = injDens;

        json["timeToModel"] = ui->timeToModel->value();
        json["vSpin"] = ui->vSpin->value();

        json["mmToHeat"] = ui->mmToHeat->value();
    }
}

void Settings::load(QString filename)
{
    QFile fsettigs(filename);
    fsettigs.open(QIODevice::ReadOnly);
    QJsonObject fobj = fsettigs.exists()?QJsonDocument(QJsonDocument::fromJson(fsettigs.readAll())).object():QJsonObject();
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
    if(!fobj.value("waterT").isUndefined()){
        ui->waterT->setValue(fobj.value("waterT").toDouble());
    }
    if(!fobj.value("injectors").isUndefined()){
        QJsonArray injectors = fobj.value("injectors").toArray();
        ui->injectorsCount->setValue(injectors.size());
        for (int i = 0; i < ui->injectorsCount->value(); i++)
        {
            QDoubleSpinBox *sb = new QDoubleSpinBox(ui->injectorsInfo);
            sb->setMaximum(400);
            sb->setMinimum(10);
            sb->setSingleStep(0.1);
            sb->setDecimals(1);
            sb->setValue(injectors[i].toObject()["density"].toDouble());
            ui->injectorsInfo->setCellWidget(i, 0, sb);

            sb = new QDoubleSpinBox(ui->injectorsInfo);
            sb->setMaximum(360);
            sb->setMinimum(10);
            sb->setSingleStep(0.1);
            sb->setDecimals(2);
            sb->setValue(injectors[i].toObject()["angleStart"].toDouble());
            ui->injectorsInfo->setCellWidget(i, 1, sb);

            sb = new QDoubleSpinBox(ui->injectorsInfo);
            sb->setMaximum(40);
            sb->setMinimum(1);
            sb->setSingleStep(0.01);
            sb->setDecimals(2);
            sb->setValue(injectors[i].toObject()["angleSize"].toDouble());
            ui->injectorsInfo->setCellWidget(i, 2, sb);
        }
    }
    if(!fobj.value("timeToModel").isUndefined()){
        ui->timeToModel->setValue(fobj.value("timeToModel").toDouble());
    }
    if(!fobj.value("vSpin").isUndefined()){
        ui->vSpin->setValue(fobj.value("vSpin").toDouble());
    }
    if(!fobj.value("mmToHeat").isUndefined()){
        ui->mmToHeat->setValue(fobj.value("mmToHeat").toDouble());
    }
}

void Settings::loadLocal()
{
    QDir dir("settings");
    if(!dir.exists()){
        dir.mkdir("../settings");
    }
    this->load(Settings::saveFileName);
}

void Settings::save(QString fn)
{
    QJsonObject settings;
    writeFocus(settings);
    if(!settings.empty())
    {
        QJsonDocument saveDoc(settings);
        QFile saveFile(fn);
        if(saveFile.open(QIODevice::WriteOnly))
            saveFile.write(saveDoc.toJson());
    }
}

void Settings::saveLocal()
{
    this->save(saveFileName);
}

void Settings::on_pushButton_clicked()
{
    this->saveLocal();
    QString fileName = QFileDialog::getSaveFileName(this,
                                                   tr("Сохранить параметры"), "",
                                                   tr("Файл параметров (*.hrp)"));
    if (!fileName.isEmpty())
    {
        this->save(fileName);
    }
    this->close();
}

void Settings::on_lineRad_valueChanged(double arg1)
{
    ui->mmToHeat->setMaximum((int)arg1);
}

void Settings::on_editH_b_valueChanged(double arg1)
{
    ui->editH_a->setMaximum(arg1-1);
}

void Settings::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Загрузить параметры"), "", tr("Файл параметров (*.hrp)"));
    if(!fileName.isEmpty()){
        this->load(fileName);
        this->saveLocal();
    }
}

void Settings::on_injectorsCount_valueChanged(int value)
{
    while (ui->injectorsInfo->rowCount() < value)
    {
        int rowcount = ui->injectorsInfo->rowCount();
        ui->injectorsInfo->setRowCount(rowcount + 1);
    }
    ui->injectorsInfo->setRowCount(value);

    for (int i = 0; i < ui->injectorsInfo->rowCount(); i++)
    {
        if (!(ui->injectorsInfo->item(i, 0)))
        {
            QDoubleSpinBox *sb = new QDoubleSpinBox(ui->injectorsInfo);
            sb->setMaximum(400);
            sb->setMinimum(10);
            sb->setSingleStep(0.1);
            sb->setDecimals(1);
            sb->setValue(100);
            ui->injectorsInfo->setCellWidget(i, 0, sb);

            sb = new QDoubleSpinBox(ui->injectorsInfo);
            sb->setMaximum(360);
            sb->setMinimum(10);
            sb->setSingleStep(0.1);
            sb->setDecimals(2);
            sb->setValue(10);
            ui->injectorsInfo->setCellWidget(i, 1, sb);

            sb = new QDoubleSpinBox(ui->injectorsInfo);
            sb->setMaximum(40);
            sb->setMinimum(1);
            sb->setSingleStep(0.01);
            sb->setDecimals(2);
            sb->setValue(5.5);
            ui->injectorsInfo->setCellWidget(i, 2, sb);
            //ui->injectorsInfo->setItem(i, 0, (new QTableWidgetItem(QString::number(100)))->setTextAlignment(););
        }
    }
}
