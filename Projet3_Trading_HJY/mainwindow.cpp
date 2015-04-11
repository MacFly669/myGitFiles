#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cotationsview.h"
//Debug
#include <QDebug>
// imports
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QTableView>
#include <QHBoxLayout>
#include <QSettings>
#include <QMdiArea>

MainWindow::MainWindow(QSqlDatabase* db,QWidget *parent): QMainWindow(parent),db(db), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // couple EUR/CHF par défaut
    QString m_paires = loadPaires();//charge les paires
    CotationsView* cotes = new CotationsView(db,m_paires,this);// instanciation d'une fenêtre de cotations webView
    cotes->move(0,100);
    // Passage de l'URL
    cotes->setUrl(QUrl("http://fxrates.fr.forexprostools.com/index.php?force_lang=5&pairs_ids="+ m_paires +"&bid=show&ask=show&last=show&change=hide&last_update=show"));

}

MainWindow::~MainWindow()
{
    delete ui;
}


QSqlDatabase* MainWindow::connectToDB(QString dbName)
{
    QSqlDatabase* db = new QSqlDatabase ;

   *db = QSqlDatabase::addDatabase( "QSQLITE" ) ;
    db->setDatabaseName( dbName );
    if( db->open()) return db ;
    // TODO MessageBox Error
    qDebug() << "Etat db open : " + db->isOpen();
    db->close();
    delete db ;
    return 0 ;
}

void MainWindow::createTable(QSqlDatabase* db){


    if(!db->isValid())
    {
        //TODO MessageBOx
        qDebug() << "Erreur lors de la tentative de connection à la base";
        return;
    }

    QString sql ;
    // Creation de la table if not exists
    sql = "create table if not exists couples (" ;
    sql += " id INTEGER PRIMARY KEY AUTOINCREMENT," ;
    sql += " nom varchar(50)," ;
    sql += " achat real," ;
    sql += " vente real," ;
    sql += " cours real," ;
    sql += " ouverture real," ;
    sql += " haut real," ;
    sql += " bas real," ;
    sql += " variation varchar(5)," ;
    sql += " heure numeric," ;
    sql += " date varchar(50),";
    sql += " timestamp INTEGER)";

    QSqlQuery result = db->exec( sql ) ;
    qDebug() << "Etat de la requête envoyée : " << result.lastError() ;

}


QString MainWindow::loadPaires(){

    QSettings settings("../mesoptions.ini", QSettings::IniFormat);
    QString valueReturn = settings.value("pairs", "1;10").toString();

    return valueReturn;

}


