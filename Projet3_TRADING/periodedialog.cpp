#include "periodedialog.h"
#include "ui_periodedialog.h"
#include "mainwindow.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
//!
//! \brief PeriodeDialog::PeriodeDialog
//!
//!
//! Class qui instancie une fenêtre contenant un QTableView relié à la base de donnée
//! Cette affichage permet de sélectionner des périodes d'enregistrements entre deux dates
//! personalisable
//!
//! \param _db renvoi un pointeur vers la connection à la base de donnée
//!
//!
//! \param parent
//!
//!
//!
//!
//!
//!
//!
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

    MainWindow::setHeaderTable(*pmodel, ui->ptableView); /*! Appel de la foinction static, fonction qui renomme les headers*/
    /*! Configuration diverses du TableView ex: non éditable */
    ui->ptableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->ptableView->setAlternatingRowColors(true);
    ui->ptableView->setStyleSheet("::item:hover { color:rgb(0,0,255) }");
    ui->ptableView->setModel(pmodel);

        /*! Bloc de connection des signaux*/
        connect(ui->comboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(comboBoxChanged(QString)));
        connect(ui->btnFermer, SIGNAL(clicked()), this, SLOT(close()));

}
//!
//! \brief PeriodeDialog::~PeriodeDialog
//!
//!
//!     Destructeur de PeriodeDialog
//!
PeriodeDialog::~PeriodeDialog()
{
    delete ui;
}

//!
//! \brief PeriodeDialog::initGui
//!
//!Initialisation de la date, de QDateEdit et création dynamique des items du comboBox
//!
//!
void PeriodeDialog::initGui()
{
    QDate date;
    ui->dateDebut->setDate(date.currentDate());// Initialisation des widgets dateEdit
    ui->dateFin->setDate(date.currentDate());

    QMapIterator<QString, QString> map( MainWindow::getMap() );
    while (map.hasNext()) {
        map.next();
        ui->comboBox->addItem(map.key());
    }
}

//!
//! \brief MainWindow::on_btn_valider_date_clicked \n
//!
//! Action sur le bouton valider des champs dates\n
//!
//! Validation des dates pour lancement de la requêtes \n Filtre la devise sélectionnée en fonction de date début -> date fin
//! \n Permet d'afficher les enregistrements pour une période donnée
//!
void PeriodeDialog::on_btn_valider_date_clicked()
{
    QString debut = ui->dateDebut->date().toString("dd.MM.yyyy"); // récupération de la date QDateEdit : date de début
    QString fin = ui->dateFin->date().toString("dd.MM.yyyy");    //  récupération de la date QDateEdit : date de fin

            if(ui->dateDebut->date() > ui->dateFin->date())
            {
                ui->labelMessage->setText(tr("Attention !!! Vous avez saisie une date de début supérieure à la date de fin, veuillez recommencer")); // si début > fin sortie de la fonction et avertissement dans la statut bar
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

//!
//! \brief PeriodeDialog::comboBoxChanged
//!
//! Actualise le QTableView en fonction de la sélection du comboBox
//!
//! \param arg1 QString retourne le text de l'index actif.
//!
//!
//!
void PeriodeDialog::comboBoxChanged(QString arg1)
{
    pmodel->setFilter("nom like '%" + arg1 + "'");
    pmodel->select() ;
    ui->labelMessage->setText( "Affichage de la paire " +  arg1 );
}
