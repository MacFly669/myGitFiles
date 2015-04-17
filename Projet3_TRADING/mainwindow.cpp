// class
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cotationsview.h"
#include "graphique.h"
#include "aboutdialog.h"
#include "savetoxml.h"
#include "simulation.h"
//Debug
#include <QDebug>
// imports
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QTableView>
#include <QXmlStreamReader>
#include <QDir>
#include <QMdiArea>
#include <QProcess>
//////////////////////////////////////////////////////////////////////////////////////////////
//!
//!         Class MainWindow - Fenêtre principale de l'application
//!
//! \file mainwindow.cpp
//! \author HENQUEZ
//! \version 1.0
//! \date Avril 2015
//! \brief Instancie une fenêtre principale.
//!
//!
//! \def Cette class créée une instance de MainWindow
//! Contient un menuBar , une statutBar , un ui->frame qui contiendra le webView de l'instance de la class cotationsView
//! Un ui->tableView pour afficher les enregistrements, une checkbox pour changer la devise et des QDateEDit pour le filtre par date
//!
//! \arg db est un paramètre de type QSqlDatabase
//! \arg parent
//!
//!
//!
//! \brief  Constructeur MainWindow::MainWindow
//!         Instancie une QMainWindowclass, la fenêter principale du programme.
//! \param db Objet de type QSqlDatabase* établit la connection à une base de données SQLITE
//! \param  Objet parent
//!
MainWindow::MainWindow(QSqlDatabase* db,QWidget *parent): QMainWindow(parent),db(db), ui(new Ui::MainWindow)
{
        ui->setupUi(this);



       XmlFormat = QSettings::registerFormat("xml", readXmlFile, writeXmlFile);/** Paramètre QSettings pour sortie XML **/
       QSettings::setPath(XmlFormat, QSettings::UserScope, QDir::currentPath()); /** Définit le répertoire de sortie du XML **/
       QSettings settings(XmlFormat, QSettings::UserScope, "CCI", "Projet3");

       QString server = settings.value("OptionBase/serveur", "127.0.0.1").toString();// récupération des valeurs sauvegardées pour la connection à la base de données.
       QString user = settings.value("OptionBase/user", "admin").toString();
       QString pass = settings.value("OptionBase/password","").toString();

        initGui(); // initialisation de l'ui

        QString m_paires = loadPaires();/** \fn loadPaires() charge les paires depuis le fichier de configuration XML  **/

        if(m_paires == "" || m_paires == NULL) return;
        /**
        instanciation d'un fenêtre de cotations webView (affichage de la page forex) dans le Widget frame de MainWindow
        \arg db soit l'Objet de type QSqlDatabase, la connection à la base de données
        \arg m_paires QString les id des paires de devises à afficher dans le webView et à sauvegarder dans la base.
        \arg this->ui->frame où le Widget parent de l'instance de CotationsView
        **/
        cotes = new CotationsView(db,&m_paires,this->ui->frame);

        cotes->move(0,0);  // Widget CotationsView à pour parent 'ui->frame', on le positionne à 0,0
        // Passage de l'URL
        cotes->setUrl(QUrl("http://fxrates.fr.forexprostools.com/index.php?force_lang=5&pairs_ids="+ m_paires +"&bid=show&ask=show&last=show&change=hide&last_update=show"));


    if( db )
    {
        MainWindow::createTable(db); /** \fn  static Création de la table si elle n'existe pas \arg db de type QSqlDaztabase **/
        // création du model d'affichage
        model = new QSqlTableModel( NULL, *db ) ;
        model->setTable( "couples" ) ;// séléction de la table à affiche dans le TableView
        model->setFilter("nom like '%" + ui->comboBox->currentText()+ "'");// Filtre de l'affiche en fonction de la sélection active de la comboBox
        model->select() ;
        setHeaderTable(); // Fonction qui renomme les headers
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
        // Bloc de connection des signaux
        connect(ui->action_Rafraichir, SIGNAL(triggered()),cotes, SLOT(reload())); // Rafraichit l'affichage du webView
        connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(close()));  // Quit l'application
        connect(ui->actionOptions, SIGNAL(triggered()),cotes,SLOT(afficheProprietes())); // affiche le boite d'options
        connect(ui->actionSimulation, SIGNAL(triggered()), this, SLOT(openSim()));
        connect(ui->actionGraphique, SIGNAL(triggered()), this, SLOT(on_actionGraphique_triggered()));
        connect(cotes, SIGNAL(dataSaved()), this, SLOT(statutDataSaved()));
}


//!
//! \brief MainWindow::initGui Initialise l'affichage : Masque le webView, initialise les QDateEdit
//!
//!
//!
void MainWindow::initGui() // initialisation affiche et dates des QDateEdit
{
    ui->frame->hide();

    QDate date;

    ui->dateDebut->setDate(date.currentDate());// Initialisation des widgets dateEdit
    ui->dateFin->setDate(date.currentDate());
}

//!
//! \brief MainWindow::openSim
//!
//!     \n ouverture du panneau de simulation
//!
//!

void MainWindow::openSim()
{
    Simulation* sim = new Simulation;
    sim->show();

}

//!
//! \brief MainWindow::setHeaderTable
//!
//! \n Renommage des entêtes de colonnes du tableau d'affichage des données \typedef QTableView
//!
//!
//!
void MainWindow::setHeaderTable() // Nomme les header du TableView
{
    model->setHeaderData(1, Qt::Horizontal, tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, tr("Achat"));
    model->setHeaderData(3, Qt::Horizontal, tr("Vente"));
    model->setHeaderData(4, Qt::Horizontal, tr("Cours"));
    model->setHeaderData(5, Qt::Horizontal, tr("Ouverture"));
    model->setHeaderData(6, Qt::Horizontal, tr("+Haut"));
    model->setHeaderData(7, Qt::Horizontal, tr("+Bas"));
    model->setHeaderData(8, Qt::Horizontal, tr("Var%"));
    model->setHeaderData(9, Qt::Horizontal, tr("Heure"));
    model->setHeaderData(10, Qt::Horizontal, tr("Date"));
    model->sort(11,Qt::DescendingOrder);

    ui->tableView->setModel( model );
    // Masquage des colonnes non désirées
    ui->tableView->hideColumn(0); // id
    ui->tableView->hideColumn(4); // cours
    ui->tableView->hideColumn(5); // ouverture
    ui->tableView->hideColumn(6); // haut
    ui->tableView->hideColumn(7); // bas
    ui->tableView->hideColumn(11); // timestamp

}

MainWindow::~MainWindow()
{
    delete ui;
}
//!
//! \brief  \fn MainWindow::connectToDB Fonction static qui créée une connection à la base de données
//! \param QString dbName \t Nom de la base de données
//! \return  Retourne un objet QSqlDatabase
//!
//!
//!
//!
QSqlDatabase* MainWindow::connectToDB(QString dbName, QString server, QString user, QString pass)// Création d'un connection à la base passée en paramètre
{

      qDebug() << dbName << server << user << pass;

    QSqlDatabase* db = new QSqlDatabase ;

   *db = QSqlDatabase::addDatabase( "QSQLITE" ) ;
    db->setHostName(server);
    db->setDatabaseName( dbName );
    db->setUserName(user);
    db->setPassword(pass);

    if( db->open()) return db ;
    // TODO MessageBox Error   
    db->close();
    delete db ;
    return 0 ;

}

//!
//! \brief MainWindow::createTable \n
//!
//!         Création de la table couples de la base de données
//!
//! \param db Pointeur Objet QSqlDatabase
//!
//!
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
}

//!
//! \brief MainWindow::on_actionCours_devises_triggered
//!
//!Affiche / Masque le webView
//!
void MainWindow::on_actionCours_devises_triggered()
{
    if(ui->frame->isHidden())
    {
        this->setFixedHeight(700);
        ui->frame->show();
        ui->statusBar->showMessage(tr("Affichage de la page cotations en direct"),2000);
    }

    else
    {
        ui->frame->hide();
        this->setFixedHeight(400);
        ui->statusBar->showMessage(tr("Fermeture de la page cotations en direct"),2000);
    }

}
//!
//! \brief MainWindow::on_comboBox_currentTextChanged
//!
//! Récupère le current text de la comboBox, filtre le tableView en fonction
//! \param arg1 Retourne la valeur du comboBox au format QSrting
//!
//!
void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{

    model->setFilter("nom like '%" + arg1 + "'");
    model->select() ;

    ui->statusBar->showMessage( ( "Affichage de la paire " + arg1  ),2000);

}
//!
//! \brief Rafraichit l'affichage du tableView \n
//!        Recharge le QTableView pour actualiser tout changement
//!
//! \fn MainWindow::reloadTableView
//!
//!
//!
void MainWindow::reloadTableView() // Rafraichit l'affichage de la TableView
{
    model->setTable( "couples" ) ;
    model->setFilter("nom like '%" + ui->comboBox->currentText()+ "'");

    setHeaderTable(); /** Appel de la \fn setHeaderTable() qui renomme les headers **/

    ui->statusBar->showMessage(tr("Mise à jour du tableau"),1000);
}

//!
//! \brief MainWindow::loadPaires Charge le ids de paires à afficher
//! \return  Retourne le contenu au format QString \n \example "1;10;" pour les pairs EUR/USD et EUR/CHF
//!
//!
QString MainWindow::loadPaires() // Charge les pairs à afficher dans les options sauvegarder par QSettings
{

    QSettings settings(XmlFormat, QSettings::UserScope, "CCI", "Projet3");
    QString valueReturn = settings.value("pairs", "1;10").toString();

    return valueReturn; // retourne un string ex: "1;10;"

}
//!
//! \brief MainWindow::on_btn_valider_date_clicked \n
//!
//! Action sur le bouton valider des champs dates\n
//!
//! Validation des dates pour lancement de la requêtes \n Filtre la devise sélectionnée en fonction de date début -> date fin
//! \n Permet d'afficher les enregistrements pour une période donnée
//!
void MainWindow::on_btn_valider_date_clicked() // validation des dates Début/Fin pour l'affichage dans le TableView
{
        QString debut = ui->dateDebut->date().toString("dd.MM.yyyy"); // récupération de la date QDateEdit : date de début
        QString fin = ui->dateFin->date().toString("dd.MM.yyyy");    //  récupération de la date QDateEdit : date de fin

                if(ui->dateDebut->date() > ui->dateFin->date())
                {
                    ui->statusBar->showMessage(tr("Vous avez saisie une date de début supérieure à la date de fin")); // si début > fin sortie de la fonction et avertissement dans la statut bar
                    return;
                }

               else // Filtre le Table view en fonction des dates de début et de fin.

               {
                    model->setFilter("date <= '" + fin + "' AND date >= '" + debut + "' AND nom like '%" + ui->comboBox->currentText()+ "'"); // SELECT WHERE debut < date < fin
                    model->select() ;

                             if( model->rowCount() == 0 ) ui->statusBar->showMessage(tr("Aucun enregistrements trouvé pour les dates sélectionées !"), 3000); // Si aucun enregistrements avertissement dazns la statut bar.

                             // affichage dans la statut bar du couple, de la période et du nombre d'enregistrements
                             else ui->statusBar->showMessage( ui->comboBox->currentText() + " du  " + ui->dateDebut->date().toString("dd.MM.yyyy") + "  au  " + ui->dateFin->date().toString("dd.MM.yyyy") + " : " + model->rowCount() + " enregistrements." ,2000);

                }

}
//!
//! \brief MainWindow::on_actionGraphique_triggered
//!
//! Affichage du graphique. \n
//! Widget de type QDialog contenant un webView qui charge l'url de l'outils
//! FOREX proposé par \a http://fr.investing.com/ et notammenent les liens
//! configurable de différents type de tableau
//!
void MainWindow::on_actionGraphique_triggered()
{
   graph = new Graphique(this);
   graph->show();
}

//!
//! \brief MainWindow::on_action_Rafraichir_triggered
//!
//!     \n Action sur le bouton Rafraîchissement de la table QTableView
//! \t Appel de la \fn reloadTableView()
//!
void MainWindow::on_action_Rafraichir_triggered()// Bouton Refresh de la ToolBar
{
    ui->statusBar->showMessage(tr("Rafraîchissement manuel de la page"),2000);
    reloadTableView();

}

//!
//! \brief MainWindow::statutDataSaved
//!
//! Affiche un message dans la statut bar quand les données sont correctement enregistrées.
//!
 void MainWindow::statutDataSaved() // SLOT du SIGNAL dataSaved envoyé lors de l'insert des données
 {

     qDebug() << "reception";
     ui->statusBar->showMessage(tr("Données sauvegardées avec succès !"),2000);
     reloadTableView();
 }
 //!
 //! \brief MainWindow::on_actionAbout_triggered
 //! Action sur le bouton 'About' -> affiche le widget About

 void MainWindow::on_actionAbout_triggered()
{
    AboutDialog* about = new AboutDialog;
    about->show();
}

