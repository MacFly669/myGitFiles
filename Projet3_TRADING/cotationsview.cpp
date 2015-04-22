///!
///!
///                              CLASS COTATIONSVIEW
///
/// \file cotationsView.cpp
/// \author HENQUEZ
/// \version 1.0
/// \date Avril 2015
/// \details
///  Cette class utilise un webView pour afficher les cotations devises via l'url générée
/// sur le site de Forex.
/// Le constructeur prend en paramètre une base SQLITE , la paire sous forme d'id stocké
/// en QString.
///
/// Les méthodes :
/// \fn setUrl() \def permet de mettre à jour l'url passé en paramètre au format QUrl
/// \fn setPaires() \def permet de mettre à jour la variable qui stocke les id à afficher
/// \fn getPaires() \def renvoi un QString retournant le ou les id contenu dans la variable.
/// \fn saveData()  \def sauvegarde les données dans la base. Prend un tableau string en paramètre.
///
/// Les signaux:
/// dataSaved() emis lors de l'insertion réussie des données
///
/// Les slots:
/// updateUrl() recharge la page
/// loadData() charge les données et les stocke dans un tableau
/// afficheProprietes() ouvre la boite de dialogue de sélection des couples
///
///
///
#include "cotationsview.h"
#include "ui_cotationsview.h"
#include "optiondialog.h"
#include "xml.h"
#include <QWebElementCollection>
#include <QWebElement>
#include <QWebFrame>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSettings>
#include <QMessageBox>
#include <QTimer>

//!
//! \brief CotationsView::CotationsView \n
//! Class qui affiche et sauvegarde les cotations des devises FOREX. L'affichage en direct dans un webView et le stockage des données
//! réceptionner dans la base de données SQLITE
//!
//! \param db Objet QSqlDatabase : connection à la base de données
//! \param _paires QString contient les paires d'id des couples à sauvegarder \example "1;10", il seront par la même occasion afficher dans le webView caché (hide) au démarrage.
//! \param parent QWidget dans lequel sera afficher le Widget CotationsView instancié.
//!
//!
//!
//!
//!
CotationsView::CotationsView(QSqlDatabase* db, QString* _paires, QWidget *parent): QWidget(parent),m_paires(_paires),db(db), ui(new Ui::CotationsView)
{
    ui->setupUi(this);
    initMain();

    if(!db) dlg->exec();

    ui->webView->move(50,0);

    // Signal attend le fin du chargement de la page web puis appelle la fonctin loadData()
    /*!  SIGNAL  loadFinished(bool) emit quand le QWebView à terminer de charge la page
     *   renvoi vers le SLOT loadData() qui récupère les données de cette page.
     *
    */
   connect(ui->webView, SIGNAL(loadFinished(bool)), this, SLOT(loadData()));
   /*!  SIGNAL emis lors de la modification des couples à afficher dans le QDialog des options
    * Le SLOT connecté est \fn updateUrl()  */
   connect( dlg, SIGNAL(acceptedOptionDevises()),this, SLOT(updateUrl()));
}

void CotationsView::initMain()
{
    XmlFormat = QSettings::registerFormat("xml", readXmlFile, writeXmlFile);
    QSettings::Format XmlFormat = QSettings::registerFormat("xml", readXmlFile, writeXmlFile);
    QSettings settings(XmlFormat, QSettings::UserScope, "CCI", "Projet3");
    *m_paires = settings.value("pairs", "1;10;").toString();
    url = settings.value("UrlForex/url").toString();

     dlg = new OptionDialog( this ) ; //déclaration de la boite de dialogue

}

//!
//! \brief CotationsView::~CotationsView
//!
//! Destructeur de CotationsView
//!
CotationsView::~CotationsView()
{
    delete ui;
}

//!
//! \brief CotationsView::setUrl
//!
//! Fonction membre setUrl() se charge de changer l'url du QTableView
//! \param url  nouvelle adresse contenant les modifications apporter aux paires dans la configuration
//!
void CotationsView::setUrl(QUrl &url)
{
       ui->webView->setUrl(url);
}

// fonction rafraichissement du webView
//!
//! \brief CotationsView::reload
//!
//!Fonction appelée pour le rechargement du QWebview : ui->webView
//!
void CotationsView::reload()
{
    this->ui->webView->reload();
}
// Mise à jour de l'url
//!
//! \brief CotationsView::updateUrl
//!
//! Rechargement du QWebview après changement d'url.
//! Cette fonction est appelée quand on modifie l'url dans la boite de dialogue 'Options'
//!
void CotationsView::updateUrl()
{
    QSettings::Format XmlFormat = QSettings::registerFormat("xml", readXmlFile, writeXmlFile);
    QSettings settings(XmlFormat, QSettings::UserScope, "CCI", "Projet3");

    url = settings.value("UrlForex/url").toString();
    QString pairs = getPaires();

    this->ui->webView->setUrl(QUrl( url + "&pairs_ids="+ pairs +"&bid=show&ask=show&last=show&change=hide&last_update=show"));
    this->ui->webView->update();

    emit emitReloadCombo();
}

// fonction qui récupére les datas du webView
//!
//! \brief CotationsView::loadData
//!
//! Fonction qui récupère les données afficher dans le webView pour ensuite les transmettre à la \fn  CotationsView::saveData(QVector<QString> table)
//!
//! On déclare un QWebFrame qui se charge de récupérer le mainFrame. On déclare ensuite un QWebElement qui va récupérer le balisage html du mainFrame, on a alors
//! toute la page html.\n
//! Dans un QWebElementCollection nous aloons récupérer tous les <tr> réprésentant les lignes qui nous intéresse.
//! Ensuite à l'aide d'une boucle nous allons récupérer les <td> de chaque lignes et les stocker dans un QVector.
//! Ces <td> contiennent les valeurs à sauvegarder; le tableau est ensuite envoyé à la \fn saveData(QVector<QString> table)
//!
//!
void CotationsView::loadData(){

    QVector<QString> tdTable(0,"");
    QWebFrame *frame = ui->webView->page()->mainFrame();
    QWebElement document = frame->documentElement();
    QWebElementCollection trCollection = document.findAll("tr"); // liste des <tr>

    QString valeur;
    int lignes = trCollection.count();// nombre de ligne du webView

    for (int i=1; i<lignes; i++ ) // Pour chaque lignes
    {
       QWebElementCollection tdCollection;

        tdCollection.append(trCollection.at(i).findAll("td")); // on récupére les <td>

               foreach (QWebElement elem, tdCollection) //Pour chaque <td>
               {

                   valeur = elem.toPlainText();
                   valeur = valeur.simplified();
                   valeur.replace(",",".").remove(" ");
                   tdTable.append(valeur);              // on stocke la valeur dans un tableau
              }
    }

               saveData(tdTable); // on envoi le tableau pour la sauvegarde DB

}
//!
//! \brief CotationsView::saveData
//!
//! Fonction qui récupère le tableau des datas en paramètre pour les sauvegarder dans la base de données.
//! Les données ont été récupérer de WebView via la \fn CotationsView::loadData()
//!
//! \param table QVector<QString> tableau contenant les valeurs à sauvegarder dans la base de données.
//!
void CotationsView::saveData(QVector<QString> table){ // sauvegarde des datas ds la DB


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
        emit dataSaved();

}
//!
//! \brief CotationsView::afficheProprietes
//!
//!
//! \fn  CotationsView::afficheProprietes() ouvre la boite de dialogue proposant les diverses options
//!
//!
void CotationsView::afficheProprietes()
{

   dlg->exec() ;
}

//!
//! \brief CotationsView::on_pushButton_clicked
//!
//! Bouton rafraichir à coté du WebView permet de recherger la page
//!
void CotationsView::on_pushButton_clicked()
{
    this->ui->webView->reload();
}


