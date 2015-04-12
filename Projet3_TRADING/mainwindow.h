#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>


class CotationsView;
class QSqlTableModel;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QSqlDatabase* db =0, QWidget *parent = 0);
    ~MainWindow();
    static QSqlDatabase* connectToDB( QString dbName ) ;
    static void createTable(QSqlDatabase* db);
    QString loadPaires(); // charge les couples ds le fichier ini
    void setHeaderTable();

    Ui::MainWindow *ui;
    QSqlDatabase* db;

private slots:
    void on_actionCours_devises_triggered();
    void reloadTableView();
    void on_comboBox_currentTextChanged(const QString &arg1);
    void on_btn_valider_date_clicked();
    void on_actionGraphique_triggered();
    void statutDataSAved();

    void on_action_Rafraichir_triggered();

    void on_actionAbout_triggered();

private:
    QSqlTableModel* model;
    CotationsView* cotes;


};

#endif // MAINWINDOW_H
