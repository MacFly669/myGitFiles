#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H
//!
//!**********************************************************************************
//!
//!
//!
//! test bourricot
//!
//!
//!
//!**********************************************************************************
//!
#include <QDialog>

namespace Ui {
class AboutDialog;
}

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent = 0);
    ~AboutDialog();

private:
    Ui::AboutDialog *ui;

private slots:

    void lienHypertexte(const QUrl &lien);


};

#endif // ABOUTDIALOG_H

