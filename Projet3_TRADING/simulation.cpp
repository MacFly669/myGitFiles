#include "simulation.h"
#include "ui_simulation.h"

//!
//! \brief Simulation::Simulation
//!
//! Constructeur de la fenêtre de simulation de profit.
//! Fenêtre de type QDialog contenant un QWebView pointant sur l'url http://tools.fr.forexprostools.com/profit-calculator/index.php?acc=17&pair=1
//!
//! \param parent
//!
//!
//!
//!
Simulation::Simulation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Simulation)
{
    ui->setupUi(this);

    ui->webView->load(QUrl("http://tools.fr.forexprostools.com/profit-calculator/index.php?acc=17&pair=1"));
}

Simulation::~Simulation()
{
    delete ui;
}

//!
//! \brief Simulation::on_pushButton_clicked
//!
//! Action sur le bouton Fermer.
//! Supprime l'objet.
//!
void Simulation::on_pushButton_clicked()
{
    delete this;

}
