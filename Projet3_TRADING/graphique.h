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
  //  void GraphiquePointLigne(QString &_gPairs);
   // void updateGraph();

private:
    Ui::Graphique *ui;
    QSqlDatabase* db;
    QVector<double>* my;
    QVector<double>* mx;
    QString gPairs;

protected slots:

   // void collectePoints();


};

#endif // GRAPHIQUE_H
