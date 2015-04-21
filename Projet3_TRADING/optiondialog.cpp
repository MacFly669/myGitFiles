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
        this->cotations = _cotations;
        XmlFormat = QSettings::registerFormat("xml", readXmlFile, writeXmlFile);
        mapList = MainWindow::getMap(); /*! Récupération de la QMap NomCouple/Id ex: "EUR/CHF","10" !*/
        tmpCheckBox = 0; // poiteur pour création dynamique des CheckBox
        checkListDevises = new QList<QCheckBox*>;
        dbDataChanged = false;
        QString newPairs = "";
        dossier = new QString;

        initGui(); // Initialisation de l'affichage

        chargerOptions(); // charge les options du fichier ini

        connect(mapper, SIGNAL(mapped(int)), this, SLOT(checkboxClicked(int)));// récupération du signal stateChange sur les checkBox
        connect(parcourir, SIGNAL(clicked()), this, SLOT(selectionBase()));
        connect(nomDB, SIGNAL(editingFinished()), this, SLOT(alertDbChange()));
        connect(chemin, SIGNAL(editingFinished()), this, SLOT(alertDbChange()));
        connect(urlBase, SIGNAL(editingFinished()), this, SLOT(alertDbChange()));
        connect(userBase, SIGNAL(editingFinished()), this, SLOT(alertDbChange()));
        connect(pwdBase, SIGNAL(editingFinished()), this, SLOT(alertDbChange()));
        connect(nomDB, SIGNAL(returnPressed()), this, SLOT(selectionBase()));

}

void OptionDialog::initGui()
{
    /*! Création des QlineEdit !*/
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

    /*! Création de Layout !*/
    QVBoxLayout *layoutPrincipale = new QVBoxLayout;
    QHBoxLayout *layout = new QHBoxLayout;

    /*! Création d'un FormLayout pour lmes champs texte des infos de la DB!*/
    QFormLayout *formLayout = new QFormLayout;
     formLayout->addRow(tr("Nom de la base de données :"), nomDB);
     formLayout->addRow(tr("Chemin"), chemin);
     formLayout->addWidget(parcourir);
     formLayout->setVerticalSpacing(10);
     layoutPrincipale->addLayout(formLayout);

     /*! Création d'un FormLayout pour lmes champs texte des infos du serveur de la DB!*/
    QFormLayout *formLayoutDistant = new QFormLayout;
     formLayoutDistant->addRow(tr("URL du serveur :"), urlBase);
     formLayoutDistant->addRow(tr("Utilisateur"), userBase);
     formLayoutDistant->addRow(tr("Mot de passe"), pwdBase);
     formLayoutDistant->setVerticalSpacing(10);
     /*! Le layout est ajouté au groupBox de l'ui!*/
     ui->groupBase->setLayout(formLayoutDistant);
     //ui->groupBase->setGeometry(10,100,850,125);

     layoutPrincipale->addWidget(ui->buttonBox);
    // layoutPrincipale->addWidget(parcourir);
    /*! On applique le Layout principale au QDialog !*/
     this->setLayout(layoutPrincipale);

     /*! Le Latyout contenant les checkBox ests ajoputé au groupBox de l'ui !*/
     ui->groupCheck->setLayout(layout);
     ui->groupCheck->setGeometry(5,250,850,50);
     layoutPrincipale->addWidget(ui->buttonBox);
     layoutPrincipale->addLayout(layout);

     //Création d'un signal mapper
     mapper = new QSignalMapper(this);

     /*! Boucle avec un QMap iterator, qui créée les checkBox dynamiquement, ajoute le nom du couple contenu dans le QMap,
      * puis connection des checkBox au QSignalMapper ...!*/
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
    QMapIterator<QString, QString> j(mapList);

    int x(0);
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

//!
//! \brief OptionDialog::chargerOptions
//!
//! Charge les dernières options enregistrées dans le fichier setting XML
//!
//!
//!
//!

void OptionDialog::chargerOptions()
{
    QSettings settings(XmlFormat, QSettings::UserScope, "CCI", "Projet3");

    // Boucle la Liste de CheckBox et mets true ou false a la méthode setChecked de la class QCheckBox
    for (int i=0; i<12;i++)
    {
       checkListDevises->at(i)->setChecked(settings.value("Checkbox/cb" + QString::number(i), "false").toBool()) ; // false par défaut si pas de valeur
    }
    // Récupération des options dans le XML
    nomDB->setText(settings.value("OptionBase/nomBase", "Projet3.db").toString()) ;
    chemin->setText(settings.value("OptionBase/chemin").toString());
    urlBase->setText(settings.value("OptionBase/serveur", "localhost").toString()) ;
    userBase->setText(settings.value("OptionBase/user").toString());
    pwdBase->setText(settings.value("OptionBase/password").toString());
    ui->radioSiteEn->setChecked(settings.value("UrlForex/radioBoutonEn").toBool());
    ui->radioSiteFr->setChecked(settings.value("UrlForex/radioBoutonFr").toBool());
    ui->radioUrlPerso->setChecked(settings.value("UrlForex/radioBoutonPerso").toBool());
}

//!
//! \brief OptionDialog::accept
//!
//!
//!Fonction après appui sur le bouton OK de la boite de dialogue des options
//! Sauvegarde des paramètres dans le fichier XMl
//!
//!
void OptionDialog::accept(){

    /*! Action valider la boite de dialogue des options. Sauvagarde dans le xml les options validées.
     * \li ids
     * \li nom base, chemin
     * \li url serveur base, user ,password
     * !*/

    QSettings settings(XmlFormat, QSettings::UserScope, "CCI", "Projet3");
    // inscription des options dans le xml
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

        if(newPairs.endsWith(";"))
        {
            newPairs.chop(1);/*! on retire le dernier caractère si ';'  !*/
        }

    cotations->setPaires(newPairs);

    settings.setValue("pairs", newPairs); // sauvegarde de la chaine d'id dans le fichier settings XML
    cotations->setPaires(newPairs); /*! on initialise l'attribut membre m_paires avec la méthode setPaires() de la class CotationsView !*/

    settings.beginGroup("UrlForex");
    settings.setValue("radioBoutonFr",ui->radioSiteFr->isChecked()); /*! sauvegarde de l'état des radio boutons !*/
    settings.setValue("radioBoutonEn", ui->radioSiteEn->isChecked());
    settings.setValue("radioBourtonPerso", ui->radioUrlPerso->isChecked());
    settings.setValue("url",ui->lineUrlPerso->text()); /*! sauvegarde de l'url di site forex!*/
    settings.endGroup();

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

        case QMessageBox::Ok: /*! Si OK on redémarre l'application !*/

            dbDataChanged = false;
            emit restartMyApp();
            qApp->quit();
            QProcess::startDetached(qApp->arguments()[0], qApp->arguments());

            break;

        case QMessageBox::Cancel:

            CancelmsgBox.exec();
            dbDataChanged = false;

            break;

        default:
                return;
                        break;
        }

    }

     emit acceptedOptionDevises(); /** signal \fn acceptedOptionDevises() déclenche un reload du QWebView suite au \fn  cotations->setPaires(newPairs) qui réinitialise les couples devises à afficher **/

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
   /*! Sélection de la base d données / récupération filename et path  !*/
    QString  fileName = QFileDialog::getOpenFileName(this,
          tr("Choisir la base"), "/home/", tr("Fichiers  (*.db *.ocdb *.sqlite)"));

    nomDB->setText(QFileInfo(fileName).fileName());
    chemin->setText(QFileInfo(fileName).path());

    QSettings settings(XmlFormat, QSettings::UserScope, "CCI", "Projet3");
    settings.beginGroup("OptionBase");
    settings.setValue("chemin", QVariant(getChemin()));
    settings.setValue("nomBase", nomDB->text());
    settings.endGroup();

    dbDataChanged = true;
}

//!
//! \brief OptionDialog::alertDbChange
//!
//!
//!
void OptionDialog::alertDbChange()
{
    dbDataChanged = true;
}

//!
//! \brief OptionDialog::on_btnCocher_clicked
//!
//!
//!Action sur le bouton Tout cocher. Coche toutes les checkBox
//!
void OptionDialog::on_btnCocher_clicked()
{

    QSettings settings(XmlFormat, QSettings::UserScope, "CCI", "Projet3");
    QString makePairs = "";

    for ( int i(0); i <12; i++ )
    {
        checkListDevises->at(i)->setChecked(true);
        settings.setValue("Checkbox/cb" + QString::number(i), "true");
        makePairs += mapList.value( checkListDevises->at(i)->text() ) + ";";  // Récupère l'id dans le QMap

    }

    cotations->setPaires(makePairs);
}

//!
//! \brief OptionDialog::on_btnDecocher_clicked
//!
//! Action sur le bouton Tout décocher. Décoche toute les checkBox
//!
//!
//!
void OptionDialog::on_btnDecocher_clicked()
{

    QSettings settings(XmlFormat, QSettings::UserScope, "CCI", "Projet3");
    QString pairVide = "";
    for ( int i(0); i <12; i++ )
    {
        checkListDevises->at(i)->setChecked(false);
        settings.setValue("Checkbox/cb" + QString::number(i), "false");
        cotations->setPaires(pairVide);
    }
}
//!
//! \brief OptionDialog::on_radioSiteFr_toggled
//!
//! Action si le radio bouton URL Fr est activé. Le QLineEdit prend la constante FR_URL
//! \param checked renvoi true si le radio bouton est coché, ou false si il est décoché
//!
//!
//!
void OptionDialog::on_radioSiteFr_toggled(bool checked)
{
    if(checked) ui->lineUrlPerso->setText(FR_URL);
}
//!
//! \brief OptionDialog::on_radioSiteEn_toggled
//!
//! Action si le radio bouton URL En est activé. Le QLineEdit prend la constante EN_URL
//! \param checked renvoi true si le radio bouton est coché, ou false si il est décoché
//!
//!
//!
void OptionDialog::on_radioSiteEn_toggled(bool checked)
{
    if(checked) ui->lineUrlPerso->setText(EN_URL);
}

//!
//! \brief OptionDialog::on_radioUrlPerso_toggled
//!
//! Vide le champ du QLineEdit à l'activation du radio bouton.
//!
//! \param checked renvoi true si le radio bouton est coché, ou false si il est décoché
//!
//!
void OptionDialog::on_radioUrlPerso_toggled(bool checked)
{
     if(checked) ui->lineUrlPerso->setText("");
}
