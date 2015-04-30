#include "connectionbase.h"
//#include "xml.h"
//import de la class MainWindow
#include "mainwindow.h"
#include <QApplication>
#include <QSettings>
#include <QSqlDatabase>
#include <QStyleFactory>
#include <QSplashScreen>
#include <QTimer>
#include <QDir>



int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    /*! QSplashScreen : Splash à l'ouverture de l'application
     *  Récupération de l'url de la QResources splash2.png
     *
     * */
    QSplashScreen* splash = new QSplashScreen;

    splash->setPixmap(QPixmap(":/images/images/splash2.png")); //Splashscreen
    splash->show();

    /*! End SplashScreen */
    /*! Style de l'application */
    QApplication::setStyle(QStyleFactory::create("Fusion"));

    /*! Récupération de la configuration dans le fichier XML généré par QSettings */
    QSettings::Format XmlFormat = QSettings::registerFormat("xml", readXmlFile, writeXmlFile);
    QSettings::setPath(XmlFormat, QSettings::UserScope, QDir::currentPath() );
    QSettings settings(XmlFormat, QSettings::UserScope, "CCI", "Projet3");

    QString dbName = settings.value("OptionBase/nomBase", "Projet3_Trading.db").toString();
    QString chemin = settings.value("OptionBase/chemin", QDir::currentPath()).toString();
    QString server = settings.value("OptionBase/serveur", "127.0.0.1").toString();// récupération des valeurs sauvegardées pour la connection à la base de données.
    QString user = settings.value("OptionBase/user", "admin").toString();
    QString pass = settings.value("OptionBase/password","").toString();
   // QString nomBase = chemin + "/" + dbName;

     /*! Fin récupération de paramètres de l'application */

    /*! Appel de la fonction static de connection à la base de données */
    QSqlDatabase* db = ConnectionBase::ouvreConnex( dbName, server, user , pass ) ;

    /*! Instanciation de la class MainWindow avec la connection db en paramètre */
    MainWindow w(db);

    /*! Timer pour le QSplash et l'affichage de la MainWindow*/
    QTimer::singleShot(2500,splash,SLOT(close()));
    QTimer::singleShot(2500, &w, SLOT(show()));

    /*! On fixe la taille de la fenêtre MainWindow */
    w.setFixedSize(860,420);

    return a.exec();

}
