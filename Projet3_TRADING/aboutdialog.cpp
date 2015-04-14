#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#include <QDesktopServices>
//!
//! \author HENQUEZ
//! \file aboutdialog.cpp
//! \brief AboutDialog::AboutDialog
//! Class de la boite d'info Abo
//!
//! \param parent
//! \date Avril 2015
//!
//! \details
//! Génére la \e boite de dialogue About avec
//! les infos de la société
//!
//!
//!

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    QTextCursor cursor( ui->textBrowser->textCursor() );

    QTextCharFormat format;
    format.setFontWeight( QFont::DemiBold );
    format.setForeground( QBrush( QColor( "black" ) ) );
    ui->textBrowser->setFontWeight(20);

    ui->textBrowser->setFontFamily("Arial");
    ui->textBrowser->setFontPointSize(2);

//    ui->textBrowser->append("Trading Plus est une application conçu par DevHopla société de dévelopement de logiciels informatiques.<br />");
//    ui->textBrowser->append("Pour de plus amples informations veuillez consulter les <a href=\"file:///conditions.pdf\">conditions générales</a>.<br />");
//    ui->textBrowser->append("Vous pouve également consulter la  <a href=\"file:///doc.pdf\">documentation</a> en anglais.");
//    ui->textBrowser->append("Si vous avec des problèmes ou des questions concernant nos produits, vous pouvez nous écrire à <a href=\"mailto:www.info@devhopla.com\">www.info@devhopla.com</a>");
    ui->textBrowser->setOpenLinks(false);


    connect(ui->textBrowser, SIGNAL(anchorClicked(QUrl)),this, SLOT(lienHypertexte(const QUrl &)));
    connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(close()));
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
void AboutDialog::lienHypertexte(const QUrl &lien){
    QDesktopServices::openUrl(lien);
}
