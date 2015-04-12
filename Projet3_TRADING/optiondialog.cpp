#include "optiondialog.h"
#include "ui_optiondialog.h"
#include "cotationsview.h"
#include <QDebug>
#include <QFormLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QSettings>
#include <QSignalMapper>
#include <QFileDialog>

OptionDialog::OptionDialog(CotationsView *_cotations, QWidget *parent) : QDialog(parent), ui(new Ui::OptionDialog)
{
    ui->setupUi(this);

    this->cotations = _cotations;

    pairsList = cotations->getPaires().split(";", QString::SkipEmptyParts);
    coupleName << "EUR/USD" << "EUR/CHF" << "EUR/GBP" << "EUR/JPY" << "USD/CAD" << "USD/CHF" << "GBP/USD" << "USD/JPY" <<  "AUD/USD" << "AUD/JPY" << "NZD/USD" << "GBP/JPY";
    coupleId << "1" << "10" << "6" << "9" << "7" << "4" << "2" << "3" << "5" << "49" << "8" << "11";
    number  << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "10" << "11" << "12";

    tmpCheckBox = 0; // poiteur pour création dynamique des CheckBox
/*    QList<QString> coupleName; // Liste des couples en string "EUR/USD" par exemple
    QList<QString> coupleId;*/  //  Liste des couples par ID
    checkListDevises = new QList<QCheckBox*>;
    QString newPairs = "";
    // Listes des devises

    QVBoxLayout *layoutPrincipale = new QVBoxLayout;
    QHBoxLayout *layout = new QHBoxLayout;

    nomDB = new QLineEdit;
    chemin = new QLineEdit;
    parcourir = new QPushButton("Parcourir");
    parcourir->setFixedSize(200,25);
    chemin->setFixedSize(700,25);

    dossier = new QString;

    QFormLayout *formLayout = new QFormLayout;
     formLayout->addRow("Nom de la base de données :", nomDB);
     formLayout->addRow("Chemin", chemin);
     formLayout->setVerticalSpacing(25);
     layoutPrincipale->addLayout(formLayout);

     layoutPrincipale->addWidget(ui->buttonBox);
     layoutPrincipale->addWidget(parcourir);
     this->setLayout(layoutPrincipale);


    //Création d'un signal mapper
    QSignalMapper* mapper = new QSignalMapper(this);

    // Boucle qui créée les checkBox, ajoute le nom du couple ...
    for(int i=0; i<12; i++)
    {
    tmpCheckBox = new QCheckBox(coupleName[i]);
    checkListDevises->append(tmpCheckBox); // on stocke les checkBox dans un Qlist
    layoutPrincipale->addWidget(tmpCheckBox); // on ajoute les widgets au layout

    connect(tmpCheckBox, SIGNAL( stateChanged(int) ), mapper, SLOT(map()));
    mapper->setMapping(tmpCheckBox, i);

    qDebug() << coupleId[i];
    }

    layoutPrincipale->addWidget(ui->buttonBox);
    layoutPrincipale->addLayout(layout);
    chargerOptions(); // charge les options du fichier ini

     // récupération du signal stateChange sur les checkBox
     connect(mapper, SIGNAL(mapped(int)), this, SLOT(checkboxClicked(int)));
     connect(parcourir, SIGNAL(clicked()), this, SLOT(choisirDossier()));

}

void OptionDialog::checkboxClicked(int i)
{   // fichier setting ini

    qDebug() << "checkboxClicked : " + QString::number(i);
   // qDebug() << "checkListDevises : " + checkListDevises.size();


    QSettings settings("../mesoptions.ini", QSettings::IniFormat);
   // enregistrement de l'id et de l'état de la checkBox
    settings.setValue("Checkbox/" + number[i],checkListDevises->at(i)->isChecked());

}


OptionDialog::~OptionDialog()
{
    delete ui;
}

void OptionDialog::chargerOptions()
{   // fichier setting ini

    QSettings settings("../mesoptions.ini", QSettings::IniFormat);

    // Boucle la Liste de CheckBox et mets true ou false a la méthode setChecked de la class QCheckBox
    for (int i=0; i<11;i++)
    {
       checkListDevises->at(i)->setChecked(settings.value("Checkbox/" + number[i], "false").toBool()) ; // false par défaut si pas de valeur

      // qDebug() << coupleId[i];
    }

    nomDB->setText(settings.value("nomBase", "Projet3.db").toString()) ;
    chemin->setText(settings.value("chemin").toString());

    qDebug() << "ChargerOptions terminer !! ";

}


void OptionDialog::accept(){


    QSettings settings("../mesoptions.ini", QSettings::IniFormat);

    coupleId << "1" << "10" << "6" << "9" << "7" << "4" << "2" << "3" << "5" << "49" << "8" << "11";
    settings.setValue("nomBase", nomDB->text());
    settings.setValue("chemin", chemin->text());
    newPairs = "";

    int taille = checkListDevises->size();

    qDebug() << "taille : " + QString::number(taille);

    // Boucle la Liste de CheckBox et mets true ou false a la méthode setChecked de la class QCheckBox
    for ( int i(0); i <12; i++ )
    {
      if (settings.value("Checkbox/" + number[i]) == "true")
       {

          qDebug() << "coupleId : " << coupleId[1] ;
           newPairs += coupleId[i] + ";";
           qDebug() << newPairs;
       }


    }
    settings.setValue("pairs", newPairs);

    cotations->setPaires(newPairs);

    emit acceptedOptionDevises();

    qDebug() << "emit accept...." ;

     QDialog::accept() ;


}

void OptionDialog::choisirDossier()
{
    QSettings settings("../mesoptions.ini", QSettings::IniFormat);

    dossier->append(QFileDialog::getExistingDirectory(this));

    chemin->setText(*dossier);

    settings.setValue("chemin", QVariant(getChemin()));
    settings.setValue("nomBase", nomDB->text());
}
