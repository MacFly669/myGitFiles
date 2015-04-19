#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#include <QDesktopServices>

AboutDialog::AboutDialog(QWidget *parent) : QDialog(parent), ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    QTextCursor cursor( ui->textBrowser->textCursor() );

    QTextCharFormat format;
    format.setFontWeight( QFont::DemiBold );
    format.setForeground( QBrush( QColor( "black" ) ) );
    ui->textBrowser->setFontWeight(10);
    ui->textBrowser->setFontFamily("Arial");
    ui->textBrowser->setFontPointSize(2);
    ui->textBrowser->setOpenLinks(false);


    connect(ui->textBrowser, SIGNAL(anchorClicked(QUrl)),this, SLOT(lienHypertexte(const QUrl &)));
    connect(ui->btnFermerAbout, SIGNAL(clicked()),this, SLOT(close()));
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::lienHypertexte(const QUrl &lien){
    QDesktopServices::openUrl(lien);
}
