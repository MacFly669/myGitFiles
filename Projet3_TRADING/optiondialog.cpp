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

#define FR_URL "http://fxrates.fr.forexprostools.com/index.php?force_lang=5"
#define EN_URL "http://fxrates.investing.com/index.php?force_lang=1"


//!
//! \brief OptionDialog::OptionDialog
//! \n Boite de dialogue contenant les options : \li Couples devises \li OPtions bases de donnée
//! \param _cotations Pointeur vers la fenetre CotationsView
//! \param parent Widget parent
//!
//!
//!
OptionDialog::OptionDialog(CotationsView *_cotations, QWidget *parent) : QDialog(parent), ui(new Ui::OptionDialog)
{
    ui->setupUi(this);

    mapList = MainWindow::getMap(); // Récupération de la QMap NomCouple/Id ex: "EUR/CHF","10"

    this->cotations = _cotations;
    tmpCheckBox = 0; // poiteur pour création dynamique des CheckBox
    checkListDevises = new QList<QCheckBox*>;
    dbDataChanged = false;
    QString newPairs = "";
    XmlFormat = QSettings::registerFormat("xml", readXmlFile, writeXmlFile);

    QVBoxLayout *layoutPrincipale = new QVBoxLayout;
    QHBoxLayout *layout = new QHBoxLayout;

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
     //ui->groupBase->setGeometry(10,100,850,125);

     layoutPrincipale->addWidget(ui->buttonBox);
    // layoutPrincipale->addWidget(parcourir);
     this->setLayout(layoutPrincipale);


    //Création d'un signal mapper
    QSignalMapper* mapper = new QSignalMapper(this);

    // Boucle qui créée les checkBox, ajoute le nom du couple, connection au QSignalMapper ...
    QMapIterator<QString, QString> j(mapList);
    int i(0);
        while (j.hasNext())
        {
            j.next();

             tmpCheckBox = new QCheckBox( j.key() );
             checkListDevises->append(tmpCheckBox); // on stocke les checkBox dans un Qlist
             layout->addWidget(tmpCheckBox); // on ajoute les widgets au layout
             connect(tmpCheckBox, SIGNAL( stateChanged(int) ), mapper, SLOT(map()));
             mapper->setMapping(tmpCheckBox, j.value().toInt());

            qDebug() << j.key() << ": " << j.value() << checkListDevises->at(i)->text();
            i++;
        }

    ui->groupCheck->setLayout(layout);
    ui->groupCheck->setGeometry(5,250,850,50);
    layoutPrincipale->addWidget(ui->buttonBox);
    layoutPrincipale->addLayout(layout);

    chargerOptions(); // charge les options du fichier ini


     connect(mapper, SIGNAL(mapped(int)), this, SLOT(checkboxClicked(int)));// récupération du signal stateChange sur les checkBox
     connect(parcourir, SIGNAL(clicked()), this, SLOT(selectionBase()));
     connect(nomDB, SIGNAL(editingFinished()), this, SLOT(alertDbName()));
     connect(chemin, SIGNAL(editingFinished()), this, SLOT(alertDbName()));
     connect(urlBase, SIGNAL(editingFinished()), this, SLOT(alertDbName()));
     connect(userBase, SIGNAL(editingFinished()), this, SLOT(alertDbName()));
     connect(pwdBase, SIGNAL(editingFinished()), this, SLOT(alertDbName()));
     connect(nomDB, SIGNAL(returnPressed()), this, SLOT(selectionBase()));

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


//!
//! \brief OptionDialog::checkboxClicked
//! \param i renvoi l'index de la checkBox cochée ou décochée.
//!
//! \def Enregistre le statut de la checBox dnas le fichiers settings XML
//!
void OptionDialog::checkboxClicked(int i)
{

    QString idChecked = QString::number(i);

    int x(0);

    QMapIterator<QString, QString> j(mapList);
    while (j.hasNext()) {
        j.next();

        if(j.value() == idChecked)
               {
                 QSettings settings(XmlFormat, QSettings::UserScope, "CCI", "Projet3");
                 settings.setValue("Checkbox/cb" + QString::number(x),checkListDevises->at(x)->isChecked());// enregistrement de l'id et de l'état de la checkBox
               }
        x++;
    }

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
       checkListDevises->at(i)->setChecked(settings.value("Checkbox/cb" + QString::number(i), "false").toBool()) ; // false par défaut si pas de valeur

    }

    nomDB->setText(settings.value("OptionBase/nomBase", "Projet3.db").toString()) ;
    chemin->setText(settings.value("OptionBase/chemin").toString());
    urlBase->setText(settings.value("OptionBase/serveur", "localhost").toString()) ;
    userBase->setText(settings.value("OptionBase/user").toString());
    pwdBase->setText(settings.value("OptionBase/password").toString());
    ui->radioSiteEn->setChecked(settings.value("UrlForex/radioBoutonEn").toBool());
    ui->radioSiteFr->setChecked(settings.value("UrlForex/radioBoutonFr").toBool());
    ui->radioUrlPerso->setChecked(settings.value("UrlForex/radioBoutonPerso").toBool());
}

void OptionDialog::accept(){


    QSettings::Format XmlFormat = QSettings::registerFormat("xml", readXmlFile, writeXmlFile);
    QSettings settings(XmlFormat, QSettings::UserScope, "CCI", "Projet3");

    settings.beginGroup("OptionBase");
    settings.setValue("nomBase", nomDB->text());
    settings.setValue("chemin", chemin->text());
    settings.setValue("serveur", urlBase->text());
    settings.setValue("user", userBase->text());
    settings.setValue("password", pwdBase->text());
    settings.endGroup();
    newPairs = "";

    // Boucle sur le fichier XML, controle la valeur bool de la CheckBox, si true ont ajoute son id à la chaine newPaires
        for ( int i(0); i <12; i++ )
        {
          if (settings.value("Checkbox/cb" + QString::number(i)) == "true")
           {
               newPairs += mapList.value( checkListDevises->at(i)->text()) + ";";  // Récupère l'id dans le QMap
           }

        }

        if(newPairs.endsWith(";")) { // on retire le dernier caractère si ';'
            newPairs.chop(1);
        }

    settings.setValue("pairs", newPairs); // sauvegarde de la chaine d'id dans le fichier settings XML
    cotations->setPaires(newPairs); // on initialise l'attribut membre m_paires avec la méthode setPaires() de la class CotationsView

    settings.beginGroup("UrlForex");
    settings.setValue("radioBoutonFr",ui->radioSiteFr->isChecked());
    settings.setValue("radioBoutonEn", ui->radioSiteEn->isChecked());
    settings.setValue("radioBourtonPerso", ui->radioUrlPerso->isChecked());
    settings.setValue("url",ui->lineUrlPerso->text());
    settings.endGroup();

    emit acceptedOptionDevises(); /** signal \fn acceptedOptionDevises() déclenche un reload du QWebView suite au \fn  cotations->setPaires(newPairs) qui réinitialise les couples devises à afficher **/

    // ***********************************************************************************
    //    Si variables de connection modifiées propose un redémarrage de l'application
    // ***********************************************************************************
    if( dbDataChanged == true )
    {

        QMessageBox CancelmsgBox;
        CancelmsgBox.setWindowTitle(tr("Redémarrage requis"));
        CancelmsgBox.setText(tr("Les modifications ont bien été sauvegardées mais prendront effet après redémmarrage de l\'application !" ));
        CancelmsgBox.setInformativeText(tr("Redémarrage de l'application requis"));


        QMessageBox msgBox;
        msgBox.setWindowTitle("Modification de la DB");
        msgBox.setText("Le nom de la base semble avoir été modifié." );
        msgBox.setInformativeText("Vous devez redémarrer l'application");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Cancel);
        int ret = msgBox.exec();

        // restart de l'application
        switch (ret) {

        case QMessageBox::Ok:

            emit restartMyApp();
            qApp->quit();
            QProcess::startDetached(qApp->arguments()[0], qApp->arguments());

            break;

        case QMessageBox::Cancel:

            CancelmsgBox.exec();
            break;

        default:
                return;
                        break;
        }

    }

     QDialog::accept() ;

}
//!
//! \brief OptionDialog::selectionBase
//!
//! \fn selectionBase() ouvre l'explorateur de fichiers pour la sélection de la base de donnée \n
//! Récupère le nom et le chemin absolue du fichier sélectionner le stock dans le fichier settings XML
//! \n Met la valeur de \variable dbDataChanged à true pour redémarrage.
//!
void OptionDialog::selectionBase()
{
   // Sélection de la base d données / récupération filename et path
    QString  fileName = QFileDialog::getOpenFileName(this,
          tr("Choisir la base"), "/home/", tr("Database Files (*.db *.ocdb *.sqlite)"));

    nomDB->setText(QFileInfo(fileName).fileName());
    chemin->setText(QFileInfo(fileName).path());

    QSettings::Format XmlFormat = QSettings::registerFormat("xml", readXmlFile, writeXmlFile);
    QSettings settings(XmlFormat, QSettings::UserScope, "CCI", "Projet3");
    settings.beginGroup("OptionBase");
    settings.setValue("chemin", QVariant(getChemin()));
    settings.setValue("nomBase", nomDB->text());
    settings.endGroup();


    dbDataChanged = true;

}

void OptionDialog::alertDbName()
{

    dbDataChanged = true;

}




void OptionDialog::on_btnCocher_clicked()
{
    for ( int i(0); i <12; i++ )
    {
           checkListDevises->at(i)->setChecked(true);
   }
}

void OptionDialog::on_btnDecocher_clicked()
{
    for ( int i(0); i <12; i++ )
    {
           checkListDevises->at(i)->setChecked(false);
   }
}

void OptionDialog::on_radioSiteFr_toggled(bool checked)
{
    if(checked) ui->lineUrlPerso->setText(FR_URL);
}

void OptionDialog::on_radioSiteEn_toggled(bool checked)
{
    if(checked) ui->lineUrlPerso->setText(EN_URL);
}

void OptionDialog::on_radioUrlPerso_toggled(bool checked)
{
     if(checked) ui->lineUrlPerso->setText("");
}
