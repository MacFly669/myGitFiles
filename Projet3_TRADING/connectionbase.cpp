#include "connectionbase.h"
#include <QDate>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

//!
//! \brief ConnectionBase::ConnectionBase
//!
//!Class de gestion de connection base de données et création de table
//!
//!
//!
ConnectionBase::ConnectionBase()
{

}

ConnectionBase::~ConnectionBase()
{

}

//!
//! \brief ConnectionBase::ouvreConnex
//!
//! Cette fonction static établit une connection à une basee de données
//! \param dbName   Le nom de la base de données
//! \param server   L'adresse url du serveur distant
//! \param user     Le nom de l'utilisateur de la base de données
//! \param pass     Le mot de passe
//! \return         REtourne un objet de type QSqlDatabase*
//!
//!
//!
QSqlDatabase* ConnectionBase::ouvreConnex(QString dbName, QString server, QString user, QString pass)// Création d'un connection à la base passée en paramètre
{

    QSqlDatabase* db = new QSqlDatabase ;

   *db = QSqlDatabase::addDatabase( "QSQLITE" ) ;
    db->setHostName(server);
    db->setDatabaseName( dbName );
    db->setUserName(user);
    db->setPassword(pass);

    if(  db->open()) return db ;
    QMessageBox msgBox;
    msgBox.setText("Erreur lors de la tentative de création de la base de données \n Vérifiez le chemin de la base de données \n Ouvrez le panneau options pour reconfigurer vos paramètres");
    msgBox.exec();
    db->close();
    delete db ;
    return 0 ;

}


//!
//! \brief ConnectionBase::createTable
//!
//!Fonction static  de création de la table si elle n'existe pas.
//!
//!  \param db Pointeur vers la base d e données
//!
//!
//!
//!
void ConnectionBase::createTable(QSqlDatabase* db){

    if(!db)
    {
        /*! MessageBox si la connection n'est pas valide */
        QMessageBox msgBox;
        msgBox.setText("Erreur lors de la tentative de création de la table \n Vérifiez que vous avez accès à la base de données\n Ouvrez le panneau options pour reconfigurer vos paramètres");
        msgBox.exec();
        return;
    }

    QString sql ;
    /*! Creation de la table if not exists */
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
}

//!
//! \brief ConnectionBase::saveData
//!
//! Fonction qui récupère le tableau des datas en paramètre pour les sauvegarder dans la base de données.
//! Les données ont été récupérer de WebView via la \fn CotationsView::loadData()
//!
//! \param table QVector<QString> tableau contenant les valeurs à sauvegarder dans la base de données.
//!
void ConnectionBase::saveData(QSqlDatabase* db, QVector<QString> table){ // sauvegarde des datas ds la DB


    QDate date;// récupération de la date du jour + formatage
    QString strDate = date.currentDate().toString("dd.MM.yyyy");
    QTime time; // fabrication d'un timestamp utilisé pour le classement ds le TableView
          time = time.currentTime();
    QDateTime startDate(QDate(1970,1,1) , QTime(0, 0, 0));
    QDateTime endDate(date.currentDate(), time);

    int timeStamp = startDate.secsTo(endDate);// initialisation de la variable timeStamp qui sera stockée.

    // calcul du nombre de lignes
    int lignes = table.count()/9;

    if (!db) {

       // TODO QMessageBox
    //    QMessageBox("Erreur base de données","Erreur de connection à la base de données")
        return;
    }

    for(int i=0; i<lignes; i++){

        QSqlQuery query( *db ) ;
        query.prepare( "insert into couples(nom, achat, vente, cours, ouverture, haut, bas, variation, heure, date, timestamp) values( :nom, :achat, :vente, :cours, :ouverture, :haut, :bas, :variation, :heure, :date, :timestamp )") ;
        query.bindValue( ":nom", QVariant( table[i*9] ) );
        query.bindValue( ":achat", QVariant( table[i*9+1] ) );
        query.bindValue( ":vente", QVariant( table[i*9+2] ) );
        query.bindValue( ":cours", QVariant(  table[i*9+3] ) );
        query.bindValue( ":ouverture", QVariant( table[i*9+4] ) );
        query.bindValue( ":haut", QVariant( table[i*9+5] ) );
        query.bindValue( ":bas", QVariant(  table[i*9+6] ) );
        query.bindValue( ":variation", QVariant( table[i*9+7] ) );
        query.bindValue( ":heure", QVariant( table[i*9+8] ) );
        query.bindValue( ":date", QVariant(strDate) );
        query.bindValue( ":timestamp", QVariant( timeStamp ) );
        query.exec();



    }
     //emit dataSaved();

}
