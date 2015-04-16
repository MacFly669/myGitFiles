#include "mainwindow.h"
//import de la class MainWindow
#include "mainwindow.h"
#include <QApplication>
#include <QSettings>
#include <QSqlDatabase>

#define QCUSTOMPLOT_COMPILE_LIBRARY

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QSettings::Format XmlFormat = QSettings::registerFormat("xml", readXmlFile, writeXmlFile);
    QSettings settings(XmlFormat, QSettings::UserScope, "CCI", "Projet3");

    QString nomBase = settings.value("OptionBase/nomBase", "Projet3_Trading.db").toString();

    QSqlDatabase* db = MainWindow::connectToDB( nomBase ) ;

    MainWindow w(db);
    w.show();
    w.setFixedSize(900,400);

    return a.exec();

}
