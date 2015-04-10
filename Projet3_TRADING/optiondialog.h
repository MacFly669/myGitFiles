#ifndef OPTIONDIALOG_H
#define OPTIONDIALOG_H

#include <QCheckBox>
#include <QDialog>
#include "cotationsview.h"

namespace Ui {
class OptionDialog;
}

class OptionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OptionDialog(cotationsView* cotations, QWidget *parent = 0);
    ~OptionDialog();

    void OptionDialog::chargerOptions();
    void accept();

private:
    Ui::OptionDialog *ui;
    cotationsView* cotations;
    QList<QCheckBox*> checkListDevises;
    QList<QString> number;
    QList<QString> coupleId;

public slots:

    void checkboxClicked(int checkboxId);

};

#endif // OPTIONDIALOG_H
