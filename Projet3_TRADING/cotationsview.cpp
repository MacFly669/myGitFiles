#include "cotationsview.h"
#include "ui_cotationsview.h"

#include <QWebElementCollection>
#include <QWebElement>
#include <QWebFrame>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSettings>
#include "optiondialog.h"
#include "mainwindow.h"


CotationsView::CotationsView(QSqlDatabase* db, QString* _paires, QWidget *parent): QWidget(parent),m_paires(_paires),db(db), ui(new Ui::CotationsView)
{
    ui->setupUi(this);

    QSettings settings("../mesoptions.ini", QSettings::IniFormat);

    *m_paires = settings.value("pairs", "1;10;").toString();
    dlg = new OptionDialog( this ) ;

   // tdTable = new QVector<QString>(0);

    // Signal attend le fin du chargement de la page web puis appelle la fonctin loadData()
   connect(ui->webView, SIGNAL(loadFinished(bool)), this, SLOT(loadData()));
   connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(afficheProprietes()));
   connect(this, SIGNAL(dataSaved()), parent, SLOT(MainWindow::statutDataSaved()));
   connect( dlg, SIGNAL(acceptedOptionDevises()),this, SLOT(rafraichirPage()));

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

    qDebug() << "recieve signal ! " + *m_paires;
    this->ui->webView->setUrl(QUrl("http://fxrates.fr.forexprostools.com/index.php?force_lang=5&pairs_ids="+ *m_paires +"&bid=show&ask=show&last=show&change=hide&last_update=show"));
    qDebug() << "http://fxrates.fr.forexprostools.com/index.php?force_lang=5&pairs_ids="+ *m_paires +"&bid=show&ask=show&last=show&change=hide&last_update=show";
    this->ui->webView->update();
}

// fonction qui récupére les datas du webView
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
             //    qDebug() << "valeur : " << valeur;
                   tdTable.append(valeur);              // on stocke la valeur dans un tableau
              }
    }

               saveData(tdTable); // on envoi le tableau pour la sauvegarde DB

}

void CotationsView::saveData(QVector<QString> table){ // sauvegarde des datas ds la DB

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

    // calcul du nombre de lignes
    int lignes = table.count()/9;

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
        emit dataSaved();
}

void CotationsView::afficheProprietes()
{

    dlg->exec() ;
}

void CotationsView::on_pushButton_clicked()
{

}
