#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

#include <QWidget>
#include <QGraphicsObject>
#include <QSqlDatabase>

namespace Ui {
class Graphique;
}

class Graphique : public QWidget
{
    Q_OBJECT

public:
    explicit Graphique(QSqlDatabase* _db, QWidget *parent = 0);
    ~Graphique();

private:
    Ui::Graphique *ui;
    QSqlDatabase* db;

};

#endif // GRAPHIQUE_H
