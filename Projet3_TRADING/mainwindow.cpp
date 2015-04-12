/*****************************************************************************************************************


        Class MainWindow - Feneêtre principale de l'application





*/

// class
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cotationsview.h"
#include "graphique.h"
#include "aboutdialog.h"
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
    ui->frame->hide();
    QGridLayout *layoutPrincipale = new QGridLayout;
    QHBoxLayout *layout = new QHBoxLayout;
    QDate date;
    // couple EUR/CHF par défaut
    QString m_paires = loadPaires();//charge les paires

    // instanciation d'un fenêtre de cotations webView
    cotes = new CotationsView(db,&m_paires,this->ui->frame);
    cotes->move(0,0);

    // Passage de l'URL
    cotes->setUrl(QUrl("http://fxrates.fr.forexprostools.com/index.php?force_lang=5&pairs_ids="+ m_paires +"&bid=show&ask=show&last=show&change=hide&last_update=show"));


    //layoutPrincipale->addWidget(cotes,1,1,2,4);
    layoutPrincipale->addLayout(layout,2,1,2,4);
    // Initialisation des widgets dateEdit
    ui->dateDebut->setDate(date.currentDate());
    ui->dateFin->setDate(date.currentDate());
    //this->setLayout(layoutPrincipale);

    if( db )
    {   // création de la table s'il n'existe pas
        MainWindow::createTable(db);
        // création du model d'affichage
        model = new QSqlTableModel( NULL, *db ) ;
        model->setTable( "couples" ) ;
        model->setFilter("nom like '%" + ui->comboBox->currentText()+ "'");
        model->select() ;
        setHeaderTable();
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

       layout->addWidget(ui->tableView);

    }

    connect(ui->action_Rafraichir, SIGNAL(triggered()),cotes, SLOT(update()));
    connect(ui->action_Rafraichir, SIGNAL(triggered()) ,this, SLOT( reloadTableView()));
    connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionOptions, SIGNAL(triggered()),cotes,SLOT(afficheProprietes()));

}

void MainWindow::setHeaderTable()
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

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{

    model->setFilter("nom like '%" + arg1 + "'");
    model->select() ;

    ui->statusBar->showMessage( ( "Affichage de la paire " + arg1  ),2000);

}

void MainWindow::reloadTableView() // Rafraichit l'affichage de la TableView
{
    model->setTable( "couples" ) ;
    model->setFilter("nom like '%" + ui->comboBox->currentText()+ "'");

    setHeaderTable();
    ui->statusBar->showMessage(tr("Mise à jour du tableau"),1000);
}

QString MainWindow::loadPaires()
{

    QSettings settings("../mesoptions.ini", QSettings::IniFormat);
    QString valueReturn = settings.value("pairs", "1;10").toString();

    return valueReturn;

}

void MainWindow::on_btn_valider_date_clicked()
{


        QString debut = ui->dateDebut->date().toString("dd.MM.yyyy"); // récupération de la date QDateEdit : date de début
        QString fin = ui->dateFin->date().toString("dd.MM.yyyy");    //  récupération de la date QDateEdit : date de fin

        if(ui->dateDebut->date() > ui->dateFin->date())
        {
            ui->statusBar->showMessage("Vous avez saisie une date de début supérieure à la date de fin"); // si début > fin

            return;
       }
        else
       {

       // Filtre le Table view en fonction des dates de début et de fin.
        model->setFilter("date <= '" + fin + "' AND date >= '" + debut + "' AND nom like '%" + ui->comboBox->currentText()+ "'"); // SELECT WHERE debut < date < fin
        bool ok = model->select() ;
        if(!ok) ui->statusBar->showMessage("Aucun enregistrements trouvé !", 2000);
        else ui->statusBar->showMessage( ui->comboBox->currentText() + " du " + ui->dateDebut->date().toString("dd.MM.yyyy") + " au " + ui->dateFin->date().toString("dd.MM.yyyy"),2000);

        QString s = QString::number(ok);

        qDebug() << "bool Ok : " << s ;

        }

}

void MainWindow::on_actionGraphique_triggered()
{

    Graphique* graph = new Graphique(db);

    graph->show();

}

void MainWindow::on_action_Rafraichir_triggered()// Bouton Refresh de la ToolBar
{
    ui->statusBar->showMessage(tr("Rafraîchissement manuel de la page"),2000);
}

 void MainWindow::statutDataSAved() // SLOT du SIGNAL dataSaved envoyé lors de l'insert des données
 {

     ui->statusBar->showMessage(tr("Données sauvegardées avec succès !"),2000);
 }



void MainWindow::on_actionAbout_triggered()
{
    AboutDialog* about = new AboutDialog;
    about->show();
}
