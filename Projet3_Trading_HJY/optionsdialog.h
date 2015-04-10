#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QDialog>
#include <QCheckBox>
#include <QList>

#include "cotationsview.h"
namespace Ui {
class OptionsDialog;
}

class OptionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OptionsDialog(QWidget *parent = 0);
    ~OptionsDialog();
    void chargerOptions();
    void accept();

private:
    Ui::OptionsDialog *ui;
    CotationsView* cotations;
    QList<QCheckBox*> checkListDevises;
    QList<QString> number;
    QList<QString> coupleId;

public slots:

    void checkboxClicked(int checkboxId);
};

#endif // OPTIONSDIALOG_H
