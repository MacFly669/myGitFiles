#include "mainwindow.h"
//import de la class MainWindow
#include "mainwindow.h"
#include <QApplication>
#include <QSettings>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QSettings::Format XmlFormat = QSettings::registerFormat("xml", readXmlFile, writeXmlFile);
    QSettings settings(XmlFormat, QSettings::UserScope, "CCI", "Projet3");

    QString nomBase = settings.value("OptionBase/nomBase", "Projet3_Trading.db").toString();
    QString chemin = settings.value("OptionBase/chemin").toString();
    QString server = settings.value("OptionBase/serveur", "127.0.0.1").toString();// récupération des valeurs sauvegardées pour la connection à la base de données.
    QString user = settings.value("OptionBase/user", "admin").toString();
    QString pass = settings.value("OptionBase/password","").toString();
    QString dbName = chemin + "/" + nomBase;
    QSqlDatabase* db = MainWindow::connectToDB( dbName, server, user , pass ) ;

    MainWindow w(db);
    w.show();
    w.setFixedSize(900,400);

    return a.exec();

}
