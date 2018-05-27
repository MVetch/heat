#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QString>
#include <QFile>
#include <QMessageBox>

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
    void load();
    static int amountOfSettings;

private slots:
    void on_pushButton_clicked();
};

#endif // SETTINGS_H
