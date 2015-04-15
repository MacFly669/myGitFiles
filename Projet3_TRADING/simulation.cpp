#include "simulation.h"
#include "ui_simulation.h"

Simulation::Simulation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Simulation)
{
    ui->setupUi(this);
}

Simulation::~Simulation()
{
    delete ui;
}
