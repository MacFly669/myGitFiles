#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

#include <QWidget>
#include <QGraphicsObject>


namespace Ui {
class Graphique;
}

class Graphique : public QWidget
{
    Q_OBJECT

public:
    explicit Graphique(QWidget *parent = 0);
    ~Graphique();

private:
    Ui::Graphique *ui;

};

#endif // GRAPHIQUE_H
