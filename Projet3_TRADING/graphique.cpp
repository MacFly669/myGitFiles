#include "graphique.h"
#include "ui_graphique.h"

Graphique::Graphique(QWidget *parent) : QDialog(parent), ui(new Ui::Graphique)
{
    ui->setupUi(this);

    ui->webView->load(QUrl("http://charts.fr.forexprostools.com/index.php?pair_ID=1"));
}

Graphique::~Graphique()
{
    delete ui;
}

