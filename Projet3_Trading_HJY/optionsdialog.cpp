#include "optionsdialog.h"
#include "ui_optionsdialog.h"
#include "cotationsview.h"
#include <QDebug>
#include <QFormLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QSettings>
#include <QSignalMapper>

OptionsDialog::OptionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsDialog)
{
    ui->setupUi(this);

    // QStringList pairs = cotations->getPaires().split(";", QString::SkipEmptyParts);
     QCheckBox* tmpCheckBox = 0; // poiteur pour création dynamique des CheckBox
     QList<QString> coupleName; // Liste des couples en string "EUR/USD" par exemple
     QList<QString> coupleId;  //  Liste des couples par ID

     QVBoxLayout *layoutPrincipale = new QVBoxLayout;
     QHBoxLayout *layout = new QHBoxLayout;
     QVBoxLayout *layoutCheck = new QVBoxLayout;
     QLineEdit *nomDB = new QLineEdit;
     QLineEdit *chemin = new QLineEdit;

     QFormLayout *formLayout = new QFormLayout;
     formLayout->addRow("Nom de la base de données :", nomDB);
     formLayout->addRow("Chemin", chemin);
     layout->addLayout(formLayout);

     //Création d'un signal mapper
     QSignalMapper* mapper = new QSignalMapper(this);

     // Boucle qui créée les checkBox, ajoute le nom du couple ...
         for(int i=0; i<12; i++)
         {

         tmpCheckBox = new QCheckBox(coupleName[i]);
         checkListDevises << tmpCheckBox; // on stocke les checkBox dans un Qlist
         layoutCheck->addWidget(tmpCheckBox); // on ajoute les widgets au layout

         connect(tmpCheckBox, SIGNAL( stateChanged(int) ), mapper, SLOT(map()));
         mapper->setMapping(tmpCheckBox, i);

         }

     layout->addLayout(layoutCheck);
     layoutPrincipale->addLayout(layout);
     layoutPrincipale->addWidget(ui->buttonBox);

     this->setLayout(layoutPrincipale);

     // Listes des devises
     coupleName << "EUR/USD" << "EUR/CHF" << "EUR/GBP" << "EUR/JPY" << "USD/CAD" << "USD/CHF" << "GBP/USD" << "USD/JPY" <<  "AUD/USD" << "AUD/JPY" << "NZD/USD" << "GBP/JPY";
     coupleId << "1" << "10" << "6" << "9" << "7" << "4" << "2" << "3" << "5" << "49" << "8" << "11";
     number << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "10" << "11" << "12";

     chargerOptions(); // charge les options du fichier ini
     // récupération du signal stateChange sur les checkBox
     connect(mapper, SIGNAL(mapped(int)), this, SLOT(checkboxClicked(int)));
}


void OptionsDialog::chargerOptions()
{
    // fichier setting ini
    QSettings settings("../mesoptions.ini", QSettings::IniFormat);
    // Boucle la Liste de CheckBox et mets true ou false a la méthode setChecked de la class QCheckBox
    for (int i=0; i<12;i++)
    {
       checkListDevises[i]->setChecked(settings.value("Checkbox/" + number[i], "false").toBool()) ; // false par défaut si pas de valeur
    }

}

void OptionsDialog::checkboxClicked(int checkboxId)
{   // fichier setting ini
    QSettings settings("../mesoptions.ini", QSettings::IniFormat);

    // enregistrement de l'id et de l'état de la checkBox
    settings.setValue("Checkbox/" + number[checkboxId],checkListDevises[checkboxId]->isChecked());
}


void OptionsDialog::accept()
{


}


OptionsDialog::~OptionsDialog()
{
    delete ui;
}
