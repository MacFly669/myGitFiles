#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

#include <QDialog>

namespace Ui {
class Graphique;
}

class Graphique : public QDialog
{
    Q_OBJECT

public:
    explicit Graphique(QWidget *parent = 0);
    ~Graphique();

    //void setUrl( QUrl &url);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Graphique *ui;


};

#endif // GRAPHIQUE_H
