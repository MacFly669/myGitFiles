#include "graphique.h"
#include "ui_graphique.h"

//!
//! \brief Graphique::Graphique
//!
//! Class qui affiche des graphiques de cotations de devises FOREX.
//! Un simple QWebView avec l'adresse de l'outils webmaster proposé par le site
//! investing.com
//!
//!  \param parent
//!
//!
Graphique::Graphique(QWidget *parent) : QDialog(parent), ui(new Ui::Graphique)
{
    ui->setupUi(this);

    ui->webView->load(QUrl("http://charts.fr.forexprostools.com/index.php?pair_ID=1"));
}

Graphique::~Graphique()
{
    delete ui;
}

