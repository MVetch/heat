#include "mainwindow.h"
#include "settings.h"
#include "diffequation.h"
#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>
typedef double qreal;

int main(int argc, char *argv[])
{
    qRegisterMetaType<QVector<QVector<double>>>("QVector<QVector<double>>");
    QStringList paths = QCoreApplication::libraryPaths();
    paths.append(".");
    paths.append("imageformats");
    paths.append("platforms");
    paths.append("sqldrivers");
    QCoreApplication::setLibraryPaths(paths);

    QApplication a(argc, argv);

    QTranslator qtTranslator;
    qtTranslator.load("qt_" + QLocale::system().name(),
            QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&qtTranslator);

    QTranslator myappTranslator;
    myappTranslator.load("myapp_" + QLocale::system().name());
    a.installTranslator(&myappTranslator);
    MainWindow w;
    w.show();


    return a.exec();
}
