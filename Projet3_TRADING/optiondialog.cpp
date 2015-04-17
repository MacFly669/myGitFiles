#include "optiondialog.h"
#include "ui_optiondialog.h"
#include "cotationsview.h"
#include "mainwindow.h"
//#include "xml.h"
#include <QDebug>
#include <QFormLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QSettings>
#include <QSignalMapper>
#include <QFileDialog>
#include <QMessageBox>
#include <QPointer>
#include <QProcess>

OptionDialog::OptionDialog(CotationsView *_cotations, QWidget *parent) : QDialog(parent), ui(new Ui::OptionDialog)
{
    ui->setupUi(this);

    this->cotations = _cotations;

    tmpCheckBox = 0; // poiteur pour création dynamique des CheckBox
    dbDataChanged = false;
    XmlFormat = QSettings::registerFormat("xml", readXmlFile, writeXmlFile);
    QString newPairs = "";
    QVBoxLayout *layoutPrincipale = new QVBoxLayout;
    QVBoxLayout *layoutDistant = new QVBoxLayout;
    QHBoxLayout *layout = new QHBoxLayout;
    initLists(); // initialisation des listes
    initGui(); // Initialisation de l'affichage

    dossier = new QString;

    QFormLayout *formLayout = new QFormLayout;
     formLayout->addRow(tr("Nom de la base de données :"), nomDB);
     formLayout->addRow(tr("Chemin"), chemin);
     formLayout->addWidget(parcourir);
     formLayout->setVerticalSpacing(10);
     layoutPrincipale->addLayout(formLayout);

    QFormLayout *formLayoutDistant = new QFormLayout;
     formLayoutDistant->addRow(tr("URL du serveur :"), urlBase);
     formLayoutDistant->addRow(tr("Utilisateur"), userBase);
     formLayoutDistant->addRow(tr("Mot de passe"), pwdBase);
     formLayoutDistant->setVerticalSpacing(10);

      ui->groupBase->setLayout(formLayoutDistant);
      ui->groupBase->setGeometry(10,100,850,125);

     layoutPrincipale->addWidget(ui->buttonBox);
    // layoutPrincipale->addWidget(parcourir);
     this->setLayout(layoutPrincipale);


    //Création d'un signal mapper
    QSignalMapper* mapper = new QSignalMapper(this);

    // Boucle qui créée les checkBox, ajoute le nom du couple ...
        for(int i=0; i<12; i++)
        {
            tmpCheckBox = new QCheckBox(coupleName[i]);
            checkListDevises->append(tmpCheckBox); // on stocke les checkBox dans un Qlist
            layout->addWidget(tmpCheckBox); // on ajoute les widgets au layout

            connect(tmpCheckBox, SIGNAL( stateChanged(int) ), mapper, SLOT(map()));
            mapper->setMapping(tmpCheckBox, i);
        }

    ui->groupCheck->setLayout(layout);
    ui->groupCheck->setGeometry(5,250,850,50);
    layoutPrincipale->addWidget(ui->buttonBox);
    layoutPrincipale->addLayout(layout);

    chargerOptions(); // charge les options du fichier ini

     // récupération du signal stateChange sur les checkBox
     connect(mapper, SIGNAL(mapped(int)), this, SLOT(checkboxClicked(int)));
     connect(parcourir, SIGNAL(clicked()), this, SLOT(choisirDossier()));
     connect(nomDB, SIGNAL(editingFinished()), this, SLOT(alertDbName()));
     connect(chemin, SIGNAL(editingFinished()), this, SLOT(alertDbName()));
     connect(urlBase, SIGNAL(editingFinished()), this, SLOT(alertDbName()));
     connect(userBase, SIGNAL(editingFinished()), this, SLOT(alertDbName()));
     connect(pwdBase, SIGNAL(editingFinished()), this, SLOT(alertDbName()));

}

void OptionDialog::initGui()
{

    nomDB = new QLineEdit;
    nomDB->setFixedWidth(200);
    chemin = new QLineEdit;
    parcourir = new QPushButton("Parcourir");
    urlBase = new QLineEdit;
    urlBase->setFixedWidth(200);
    userBase = new QLineEdit;
    userBase->setFixedWidth(200);
    pwdBase = new QLineEdit;
    pwdBase->setFixedWidth(200);
    pwdBase->setEchoMode(QLineEdit::Password);
    parcourir->setFixedSize(200,20);
    chemin->setFixedSize(700,20);
}

void OptionDialog::initLists()
{
    coupleName << "EUR/USD" << "EUR/CHF" << "EUR/GBP" << "EUR/JPY" << "USD/CAD" << "USD/CHF" << "GBP/USD" << "USD/JPY" <<  "AUD/USD" << "AUD/JPY" << "NZD/USD" << "GBP/JPY";
    coupleId << "1" << "10" << "6" << "9" << "7" << "4" << "2" << "3" << "5" << "49" << "8" << "11";
    number  << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "10" << "11" << "12";
    checkListDevises = new QList<QCheckBox*>;
}

void OptionDialog::checkboxClicked(int i)
{
    QSettings settings(XmlFormat, QSettings::UserScope, "CCI", "Projet3");
    settings.setValue("Checkbox/cb" + number[i],checkListDevises->at(i)->isChecked());// enregistrement de l'id et de l'état de la checkBox
}

OptionDialog::~OptionDialog()
{
    delete ui;
}

void OptionDialog::chargerOptions()
{

   // QSettings settings("../mesoptions.ini", QSettings::IniFormat);
    QSettings::Format XmlFormat = QSettings::registerFormat("xml", readXmlFile, writeXmlFile);
    QSettings settings(XmlFormat, QSettings::UserScope, "CCI", "Projet3");

    // Boucle la Liste de CheckBox et mets true ou false a la méthode setChecked de la class QCheckBox
    for (int i=0; i<11;i++)
    {
       checkListDevises->at(i)->setChecked(settings.value("Checkbox/cb" + number[i], "false").toBool()) ; // false par défaut si pas de valeur

    }

    nomDB->setText(settings.value("OptionBase/nomBase", "Projet3.db").toString()) ;
    chemin->setText(settings.value("OptionBase/chemin").toString());
    urlBase->setText(settings.value("OptionBase/serveur", "localhost").toString()) ;
    userBase->setText(settings.value("OptionBase/user").toString());
    pwdBase->setText(settings.value("OptionBase/password").toString());
}

void OptionDialog::accept(){


   // QSettings settings("../mesoptions.ini", QSettings::IniFormat);
    QSettings::Format XmlFormat = QSettings::registerFormat("xml", readXmlFile, writeXmlFile);
    QSettings settings(XmlFormat, QSettings::UserScope, "CCI", "Projet3");

    coupleId << "1" << "10" << "6" << "9" << "7" << "4" << "2" << "3" << "5" << "49" << "8" << "11";
    settings.beginGroup("OptionBase");
    settings.setValue("nomBase", nomDB->text());
    settings.setValue("chemin", chemin->text());
    settings.setValue("serveur", urlBase->text());
    settings.setValue("user", userBase->text());
    settings.setValue("password", pwdBase->text());
    settings.endGroup();
    newPairs = "";

    int taille = checkListDevises->size();

    qDebug() << "taille : " + QString::number(taille);

    // Boucle la Liste de CheckBox et mets true ou false a la méthode setChecked de la class QCheckBox
    for ( int i(0); i <12; i++ )
    {
      if (settings.value("Checkbox/cb" + number[i]) == "true")
       {

          qDebug() << "coupleId : " << coupleId[1] ;
           newPairs += coupleId[i] + ";";
           qDebug() << newPairs;
       }

    // checkListDevises->at(i)->setChecked(settings.value("Checkbox/cb" + number[i], "false").toBool()) ;


    }
    settings.setValue("pairs", newPairs);

    cotations->setPaires(newPairs);

    emit acceptedOptionDevises();

    qDebug() << "emit accept...." ;
    // *********************************************************************************

    if( dbDataChanged == true )
    {


        QMessageBox msgBox;
        msgBox.setWindowTitle("Modification de la DB");
        msgBox.setText("Le nom de la base semble avoir été modifié." );
        msgBox.setInformativeText("Vous devez redémarrer l'application");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Cancel);
        int ret = msgBox.exec();
        // restart:


        switch (ret) {
          case QMessageBox::Ok:
              // todo
                emit restartMyApp();
            settings.beginGroup("OptionBase");
            settings.setValue("nomBase", nomDB->text());
            settings.endGroup();

            qApp->quit();
            QProcess::startDetached(qApp->arguments()[0], qApp->arguments());


              break;
          case QMessageBox::Cancel:
              // todo
              break;
          default:

              break;
        }

    }






     QDialog::accept() ;


}

void OptionDialog::choisirDossier()
{
   // QSettings settings("../mesoptions.ini", QSettings::IniFormat);
    QSettings::Format XmlFormat = QSettings::registerFormat("xml", readXmlFile, writeXmlFile);
    QSettings settings(XmlFormat, QSettings::UserScope, "CCI", "Projet3");

    dossier->append(QFileDialog::getExistingDirectory(this));

    chemin->setText(*dossier);
    settings.beginGroup("OptionBase");
    settings.setValue("chemin", QVariant(getChemin()));
    settings.setValue("nomBase", nomDB->text());
    settings.endGroup();
}

void OptionDialog::alertDbName()
{

    dbDataChanged = true;

}


