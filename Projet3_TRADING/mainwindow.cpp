// class
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cotationsview.h"
#include "graphique.h"
#include "aboutdialog.h"
#include "simulation.h"
#include "periodedialog.h"
#include "connectionbase.h"

//Debug
#include <QDebug>
// imports
#include <QMap>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QTableView>
#include <QXmlStreamReader>
#include <QDir>
#include <QMdiArea>
#include <QProcess>
#include <QTableWidgetItem>
#include <QTimer>

#define INDEXURL  "/index.php?force_lang="
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
//! Cette class créée une instance de MainWindow
//! Contient un menuBar , une statutBar , un ui->frame qui contiendra le webView de l'instance de la class cotationsView
//! Un ui->tableView pour afficher les enregistrements, une checkbox pour changer la devise et des QDateEDit pour le filtre par date
//!
//! \arg db est un paramètre de type QSqlDatabase
//! \arg parent



//!
//!
//! \brief  Constructeur MainWindow::MainWindow
//!         Instancie une MainWindow, la fenêtre principale du programme.
//!
//! \param db Objet de type QSqlDatabase* établit la connection à une base de données SQLITE
//! \param  Objet parent
//!
MainWindow::MainWindow(QSqlDatabase* db,QWidget *parent): QMainWindow(parent),db(db), ui(new Ui::MainWindow)
{
        ui->setupUi(this);

      //  qApp->setStyleSheet("QMainWindow { background-image: url(:/images/images/splash2.png) }");
        /** Chargement des infos paires, urlForex, lang depuis le fichier de configuration XML  **/
        XmlFormat = QSettings::registerFormat("xml", readXmlFile, writeXmlFile);
        QSettings::setPath(XmlFormat, QSettings::UserScope, QDir::currentPath() );
        QSettings settings(XmlFormat, QSettings::UserScope, "CCI", "Projet3");
        QString paires = settings.value("pairs", "1;10").toString();
        QString forexUrl = settings.value("UrlForex/url","http://fxrates.fr.forexprostools.com").toString();
        bool s_distant =   settings.value("OptionBase/distant").toBool();

        //QString langId = settings.value("UrlForex/lang","5").toString();

        //if(m_paires == "" || m_paires == NULL) m_paires = "1;10";


        /**
        instanciation d'un fenêtre de cotations webView (affichage de la page forex) dans le Widget frame de MainWindow
        \arg db soit l'Objet de type QSqlDatabase, la connection à la base de données
        \arg m_paires QString les id des paires de devises à afficher dans le webView et à sauvegarder dans la base.
        \arg this->ui->frame où le Widget parent de l'instance de CotationsView
        **/
        cotes = new CotationsView(db,&paires,this->ui->frame); /*! Widget CotationsView à pour parent 'ui->frame', on le positionne à 0,0 */
        cotes->move(0,5);
        cotes->setPaires(paires);
        /*! Création de l'url */
        QUrl url = forexUrl + INDEXURL +  "&pairs_ids=" + cotes->getPaires() + "&bid=show&ask=show&last=show&change=hide&last_update=show";
        cotes->setUrl( url ); // Passage de l'URL;

        initGui(); /*! \fn initGui s'occupe de l'initialisation de l'ui  */

    if( db && s_distant ) ConnectionBase::createTableMySql(db); /** \fn  ConnectionBase::createTable(db) static de création de la table si elle n'existe pas \arg db de type QSqlDaztabase **/
    else if ( db && !s_distant ) ConnectionBase::createTableSqlite(db);

        // création du model d'affichage
        model = new QSqlTableModel( NULL, *db ) ;
        model->setTable( "couples" ) ;// séléction de la table à affiche dans le TableView
        model->setFilter("nom like '%" + ui->comboDevises->currentText()+ "'");// Filtre de l'affiche en fonction de la sélection active de la comboBox
        model->select() ;
        setHeaderTable(*model, ui->tableView); // Fonction qui renomme les headers
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableView->setAlternatingRowColors(true);
        ui->tableView->setStyleSheet("::item:hover { color:rgb(0,0,255) }");

        /*! Bloc de connection des signaux  */
        connect(ui->action_Rafraichir, SIGNAL(triggered()),cotes, SLOT(reload())); // Rafraichit l'affichage du webView
        connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(close()));  // Quit l'application
        connect(ui->actionOptions, SIGNAL(triggered()),cotes,SLOT(afficheProprietes())); // affiche le boite d'options
        connect(ui->actionSimulation, SIGNAL(triggered()), this, SLOT(openSim()));
        connect(ui->actionGraphique, SIGNAL(triggered()), this, SLOT(on_actionGraphique_triggered()));
        connect(cotes, SIGNAL(dataSaved()), this, SLOT(statutDataSaved()));
        connect(ui->comboDevises, SIGNAL(currentTextChanged(QString)), this, SLOT(comboChanged(QString)));
        connect( cotes, SIGNAL(emitReloadCombo()),this, SLOT( initCombo() ) );

        /*! Timer qui recharge la page toutes les 10 secondes */
        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), cotes, SLOT(reload()));
        timer->start(10000);

}


//!
//! \brief MainWindow::initGui Initialise l'affichage : Masque le webView, initialise les QDateEdit
//!
//!
//!
void MainWindow::initGui() // initialisation affiche et dates des QDateEdit
{
        ui->frame->hide();
        ui->comboDevises->clear();
        bool ok = false;

        QMapIterator<QString, QString> map( MainWindow::getMap() );

             while (map.hasNext())
             {
                    map.next();
                    ok = isChecked(map.value());
                    if(ok) ui->comboDevises->addItem(map.key());
             }

       graph = new Graphique();
}

//!
//! \brief MainWindow::initCombo
//!
//! Initialise le contenu (Items) de le comboBox en fonction des checkBox cochées
//! Pour chaque couple contenu dans le QMap devises/id on envoi la map.valeur à la fonction \fn isChecked() qui renvoit true si la checkBox est cochée
//!
void MainWindow:: initCombo()
{

    bool ok = false;
    ui->comboDevises->clear();

    QMapIterator<QString, QString> map( MainWindow::getMap() );

            while (map.hasNext())
            {
                map.next();
                ok = isChecked(map.value());
                if( ok ) ui->comboDevises->addItem(map.key());
            }
}

//!
//! \brief MainWindow::isChecked
//!
//!     Fonction qui controle si la chackBox devise est cochée ou pas
//!
//!
//! \param str QString représente l'id du couple devise à vérifier
//!
//! \return  true si la checkBox est cochée
//!
//!
bool MainWindow::isChecked(QString str)
{

    QList<QString> ids = cotes->getPaires().split(";");

    for (int i(0); i< ids.size(); i++)
    {
        if(ids[i] == str) return true;

    }

    return false;
}


//!
//! \brief MainWindow::setHeaderTable
//!
//! \n Renommage des entêtes de colonnes du tableau d'affichage des données \typedef QTableView
//!
//!
//!
void MainWindow::setHeaderTable(QSqlTableModel &model, QTableView* tableView ) // Nomme les header du TableView
{

    model.setHeaderData(1, Qt::Horizontal, tr("Nom"));
    model.setHeaderData(2, Qt::Horizontal, tr("Achat"));
    model.setHeaderData(3, Qt::Horizontal, tr("Vente"));
    model.setHeaderData(4, Qt::Horizontal, tr("Cours"));
    model.setHeaderData(5, Qt::Horizontal, tr("Ouverture"));
    model.setHeaderData(6, Qt::Horizontal, tr("+Haut"));
    model.setHeaderData(7, Qt::Horizontal, tr("+Bas"));
    model.setHeaderData(8, Qt::Horizontal, tr("Var%"));
    model.setHeaderData(9, Qt::Horizontal, tr("Heure"));
    model.setHeaderData(10, Qt::Horizontal, tr("Date"));
    model.sort(11,Qt::DescendingOrder);

    tableView->setModel( &model );
    // Masquage des colonnes non désirées
    tableView->hideColumn(0); // id
    tableView->hideColumn(4); // cours
    tableView->hideColumn(5); // ouverture
    tableView->hideColumn(6); // haut
    tableView->hideColumn(7); // bas
    tableView->hideColumn(11); // timestamp

}
//!
//! \brief MainWindow::~MainWindow
//!
//!
//! Destructeur de la MainWindow
//!
MainWindow::~MainWindow()
{
    delete ui;
}




//!
//! \brief MainWindow::on_comboBox_currentTextChanged
//!
//! Récupère le current text de la comboBox, filtre le tableView en fonction
//! \param arg1 Retourne la valeur du comboBox au format QSrting
//!
//!
void MainWindow::comboChanged(QString arg1)
{

    model->setFilter("nom like '%" + arg1 + "'");
    model->select() ;

    ui->statusBar->showMessage( ( "Affichage de la paire "  ),2000);
}


//!
//! \brief Rafraichit l'affichage du tableView \n
//!        Recharge le QTableView pour actualiser tout changement
//!
//! \fn MainWindow::reloadTableView
//!
//!
//!
void MainWindow::reloadTableView() /*! Rafraichit l'affichage de la TableView */
{
    model->setTable( "couples" ) ;
    model->setFilter("nom like '%" + ui->comboDevises->currentText()+ "'");

    setHeaderTable(*model, ui->tableView); /** Appel de la \fn setHeaderTable() qui renomme les headers **/

    ui->statusBar->showMessage(tr("Mise à jour du tableau"),1000);
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

     ui->statusBar->showMessage(tr("Données sauvegardées avec succès !"),2000);
     reloadTableView();
 }
//!
//! \brief MainWindow::getMap
//!
//!     Fonction qui renvoi un QMap contenant en key le nom des devises (ex EUR/CHF) et en value les ids (ex: 10).
//!
//!  \return  Renvoi un QMap
//!
//!
//!
QMap<QString, QString> MainWindow::getMap()
 {
    QMap<QString, QString> map;
    //remplissage de map....
    map.insert("EUR/USD","1");
    map.insert("EUR/CHF","10");
    map.insert("EUR/GBP","6");
    map.insert("EUR/JPY","9");
    map.insert("USD/CAD","7");
    map.insert("USD/CHF","4");
    map.insert("GBP/USD","2");
    map.insert("USD/JPY","3");
    map.insert("AUD/USD","5");
    map.insert("AUD/JPY","49");
    map.insert("NZD/USD","8");
    map.insert("GBP/JPY","11");


    return(map);
 }
//!
//! \brief MainWindow::on_actionCalendrier_triggered
//!
//!     Ouvre la boite de dialog pour sélectionner les enregistrements de la base de données par périodes \n
//!     Offre la possibilité de trier la base entre deux dates.
//!
//!
void MainWindow::on_actionCalendrier_triggered()
{
    PeriodeDialog* wDate= new PeriodeDialog(db);

    wDate->show();
}
//!
//! \brief MainWindow::openSim
//!
//!     \n ouverture du panneau de simulation pour calculer les profits
//! Il s\'agit d'un webView qui appel l'url http://tools.fr.forexprostools.com/profit-calculator/index.php?acc=17&pair=1
//! Tools webmaster proposé par le sur \link http://www.investing.com
//!
//!
void MainWindow::openSim()
{
    Simulation* sim = new Simulation;
    sim->show();

}

//!
//! \brief MainWindow::on_actionAbout_triggered
//! Action sur le bouton 'About' -> affiche le widget About

void MainWindow::on_actionAbout_triggered()
{
   AboutDialog* about = new AboutDialog;
   about->show();
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
        graph->show();
}

//!
//! \brief MainWindow::on_actionShowHideView_triggered
//!
//!Affiche / Masque le webView
//!
void MainWindow::on_actionShowHideView_triggered()
{
    if(ui->frame->isHidden())
    {
        this->setFixedHeight(650);
        ui->frame->show();
        ui->statusBar->showMessage(tr("Affichage de la page cotations en direct"),2000);
    }
    else
    {
        ui->frame->hide();
        this->setFixedHeight(420);
        ui->statusBar->showMessage(tr("Fermeture de la page cotations en direct"),2000);
    }
}
