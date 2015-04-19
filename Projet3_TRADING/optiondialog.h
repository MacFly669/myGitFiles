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
    void initGui();
    QVariant getChemin(){ return chemin->text();}


private:
    Ui::OptionDialog *ui;
    QMap<QString, QString> mapList;
    CotationsView* cotations;
    QList<QCheckBox*> *checkListDevises;
    QPushButton* parcourir;
    QLineEdit *nomDB ;
    QLineEdit *chemin;
    QLineEdit *urlBase ;
    QLineEdit *userBase;
    QLineEdit *pwdBase;
    QString* dossier;
    QCheckBox* tmpCheckBox;
    QString newPairs;

    QSettings::Format XmlFormat;
    bool dbDataChanged;

signals:

    void acceptedOptionDevises();
    void restartMyApp();

public slots:



private slots:
    void checkboxClicked(int i);
    void selectionBase();
    void accept();
    void alertDbName();
    void on_btnCocher_clicked();
    void on_btnDecocher_clicked();
};

#endif // OPTIONDIALOG_H
