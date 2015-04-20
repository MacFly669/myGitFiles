#ifndef PERIODEDIALOG_H
#define PERIODEDIALOG_H

#include <QDialog>

class QSqlTableModel;
class QSqlDatabase;

namespace Ui {
class PeriodeDialog;
}

class PeriodeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PeriodeDialog(QSqlDatabase* _db = 0, QWidget *parent = 0);
    ~PeriodeDialog();
    void initGui();

private slots:
    void comboBoxChanged(QString arg1);
    void on_btn_valider_date_clicked();

private:
    Ui::PeriodeDialog *ui;
    QSqlDatabase* db;
    QSqlTableModel* pmodel;
};

#endif // PERIODEDIALOG_H
