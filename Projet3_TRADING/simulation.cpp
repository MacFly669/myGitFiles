#include "simulation.h"
#include "ui_simulation.h"

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
