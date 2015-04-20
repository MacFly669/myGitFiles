#include "periodedialog.h"
#include "ui_periodedialog.h"
#include "mainwindow.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>

PeriodeDialog::PeriodeDialog(QSqlDatabase* _db, QWidget *parent) : QDialog(parent), ui(new Ui::PeriodeDialog)
{
    ui->setupUi(this);
    //qApp->setStyleSheet("PeriodeDialog { background-image: url(:/images/images/fond2.jpg) }");
    this->db = _db;
    initGui();

    pmodel = new QSqlTableModel;

    pmodel->setTable( "couples" ) ;// séléction de la table à affiche dans le TableView
    pmodel->setFilter("nom like '%" + ui->comboBox->currentText()+ "'");// Filtre de l'affiche en fonction de la sélection active de la comboBox
    pmodel->select() ;
    MainWindow::setHeaderTable(*pmodel, ui->ptableView); // Fonction qui renomme les headers
    ui->ptableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->ptableView->setAlternatingRowColors(true);
    ui->ptableView->setStyleSheet("::item:hover { color:rgb(0,0,255) }");
    ui->ptableView->setModel(pmodel);

        connect(ui->comboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(comboBoxChanged(QString)));
        connect(ui->btnFermer, SIGNAL(clicked()), this, SLOT(close()));

}

PeriodeDialog::~PeriodeDialog()
{
    delete ui;
}

void PeriodeDialog::initGui()
{
    QDate date;
    ui->dateDebut->setDate(date.currentDate());// Initialisation des widgets dateEdit
    ui->dateFin->setDate(date.currentDate());

    QMapIterator<QString, QString> i( MainWindow::getMap() );
    while (i.hasNext()) {
        i.next();
        ui->comboBox->addItem(i.key());
    }

}


void PeriodeDialog::on_btn_valider_date_clicked()
{
    QString debut = ui->dateDebut->date().toString("dd.MM.yyyy"); // récupération de la date QDateEdit : date de début
    QString fin = ui->dateFin->date().toString("dd.MM.yyyy");    //  récupération de la date QDateEdit : date de fin

            if(ui->dateDebut->date() > ui->dateFin->date())
            {
               // ui->statusBar->showMessage(tr("Vous avez saisie une date de début supérieure à la date de fin")); // si début > fin sortie de la fonction et avertissement dans la statut bar
                return;
            }

            else // Filtre le Table view en fonction des dates de début et de fin.

            {
                pmodel->setFilter("date <= '" + fin + "' AND date >= '" + debut + "' AND nom like '%" + ui->comboBox->currentText()+ "'"); // SELECT WHERE debut < date < fin
                pmodel->select() ;

                         if( pmodel->rowCount() == 0 ) ui->labelMessage->setText(tr("Aucun enregistrements trouvé pour les dates sélectionées !")); // Si aucun enregistrements avertissement dazns la statut bar.

                         // affichage dans la statut bar du couple, de la période et du nombre d'enregistrements
                         else ui->labelMessage->setText( ui->comboBox->currentText() + " du  " + ui->dateDebut->date().toString("dd.MM.yyyy") + "  au  " + ui->dateFin->date().toString("dd.MM.yyyy") + " : " + QString::number(pmodel->rowCount()) + " enregistrements." );

            }

}
void PeriodeDialog::comboBoxChanged(QString arg1)
{

    pmodel->setFilter("nom like '%" + arg1 + "'");
    pmodel->select() ;

    ui->labelMessage->setText( "Affichage de la paire " +  arg1 );

    qDebug() << "combo Cahnged !";

}
