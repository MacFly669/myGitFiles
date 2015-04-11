#include "cotationsview.h"
#include "ui_cotationsview.h"
#include "optionsdialog.h"

#include <QWebElementCollection>
#include <QWebElement>
#include <QWebFrame>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QDate>
#include <QTime>

CotationsView::CotationsView(QSqlDatabase* db, QString _paires, QWidget *parent): QWidget(parent),m_paires(_paires),db(db), ui(new Ui::CotationsView)
{
    ui->setupUi(this);

    //tdTable = new QVector<QString>(0);
    m_paires = "1;10";

    connect(ui->webView, SIGNAL(loadFinished(bool)), this, SLOT(loadData()));


}

CotationsView::~CotationsView()
{
    delete ui;
}

// fonction de mise à jour de l'URL
void CotationsView::setUrl(QUrl &url)
{
    ui->webView->setUrl(url);
}

// fonction rafraichissement du webView
void CotationsView::rafraichirPage()
{
    ui->webView->reload();
}

void CotationsView::reloadTableView(){

    ui->tableView->reset();
}

// Récupération des données
void CotationsView::loadData()
{

    QVector<QString> tdTable(0,"");
    QWebFrame* frame = ui->webView->page()->mainFrame();
    QWebElement document = frame->documentElement();
    QWebElementCollection trCollection = document.findAll("tr");


    int trSize = trCollection.count();
    QString valeur;

    for(int i(1); i<trSize; i++)
    {
        QWebElementCollection tdCollection;
        tdCollection.append(trCollection.at(i).findAll("td"));

        foreach (QWebElement elem, tdCollection) //Pour chaque <td>
        {
               //on stocke la valeur dans un tableau
            valeur = elem.toPlainText();
            valeur = valeur.simplified();
            valeur.replace(",",".").remove(" ");
        //  qDebug() << "valeur : " << valeur;
            tdTable.append(valeur);              // on stocke la valeur dans un tableau
       }


    }

    qDebug() << "send to db" ;
    saveData(tdTable);
}

void CotationsView::saveData(QVector<QString> &table)
{

    // récupération de la date du jour + formatage
    QDate date;
    QString strDate = date.currentDate().toString("dd.MM.yyyy");
    // fabrication d'un timestamp utilisé pour le classement ds le TableView
    QTime time;
          time = time.currentTime();
    QDateTime startDate(QDate(1970,1,1) , QTime(0, 0, 0));
    QDateTime endDate(date.currentDate(), time);
    // initialisation de la varaible timeStamp qui sera stockée.
    int timeStamp = startDate.secsTo(endDate);
     qDebug() << "table size : " + table.size();
    // calcul du nombre de lignes
    int lignes = table.size()/9;

    qDebug() << "lignes : " + lignes;

    if (!db) {

       // TODO QMessageBox
        return;
    }

    qDebug() << "Connecté" << lignes;

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

        qDebug() << "Query last errror : " << query.lastError();

    }



}

void CotationsView::afficheProprietes()
{
   OptionsDialog* dlg = new OptionsDialog( this ) ;
    dlg->exec() ;
}
