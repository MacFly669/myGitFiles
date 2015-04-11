#ifndef OPTIONDIALOG_H
#define OPTIONDIALOG_H
#include "cotationsview.h"
#include <QCheckBox>
#include <QDialog>
#include <QLineEdit>


namespace Ui {
class OptionDialog;
}

class OptionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OptionDialog(CotationsView* _cotations, QWidget *parent = 0);
    ~OptionDialog();

    void OptionDialog::chargerOptions();
    void setChemin(QString _chemin){ chemin->setText( _chemin); }
    QVariant getChemin(){ return chemin->text();}


private:
    Ui::OptionDialog *ui;
    CotationsView* cotations;
    QList<QCheckBox*> *checkListDevises;
    QList<QString> number;
    QList<QString> coupleId;
    QList<QString> coupleName;
    QPushButton* parcourir;
    QLineEdit *nomDB ;
    QLineEdit *chemin;
    QString* dossier;
    QCheckBox* tmpCheckBox;
    QString newPairs;
    QStringList pairsList;

signals:

    void acceptedOptionDevises();

public slots:

    void checkboxClicked(int i);
    void choisirDossier();
    void accept();

};

#endif // OPTIONDIALOG_H