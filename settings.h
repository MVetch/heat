#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();
    static QString saveFileName;
    Ui::Settings *ui;
    void writeFocus(QJsonObject &json);
    void load(QString filename);
    void loadLocal();
    void saveLocal();
    static int amountOfSettings;

private slots:
    void on_pushButton_clicked();
    void on_lineRad_valueChanged(double arg1);
    void on_editH_b_valueChanged(double arg1);
public slots:
    void on_pushButton_2_clicked();
};

#endif // SETTINGS_H
