#ifndef SIMULATION_H
#define SIMULATION_H

#include <QDialog>

namespace Ui {
class Simulation;
}

class Simulation : public QDialog
{
    Q_OBJECT

public:
    explicit Simulation(QWidget *parent = 0);
    ~Simulation();

private:
    Ui::Simulation *ui;
};

#endif // SIMULATION_H
