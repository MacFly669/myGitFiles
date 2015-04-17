#ifndef OPTIONDIALOG_H
#define OPTIONDIALOG_H
#include "cotationsview.h"
#include <QCheckBox>
#include <QDialog>
#include <QLineEdit>
#include <QSettings>

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
    void initLists();
    void initGui();
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
    QLineEdit *urlBase ;
    QLineEdit *userBase;
    QLineEdit *pwdBase;
    QString* dossier;
    QCheckBox* tmpCheckBox;
    QString newPairs;
    QStringList pairsList;
    QSettings::Format XmlFormat;
    bool dbDataChanged;

signals:

    void acceptedOptionDevises();
    void restartMyApp();

public slots:

    void checkboxClicked(int i);
    void choisirDossier();
    void accept();
    void alertDbName();

private slots:

};

#endif // OPTIONDIALOG_H
