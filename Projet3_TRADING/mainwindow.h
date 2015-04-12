#ifndef MAINWINDOW_H
#define MAINWINDOW_H
///!********************************************************************************
///!
///                         CLASS MAINWINDOW
/// Fenêtre principale
///
///
///
///
///
/// *********************************************************************************
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
    static QSqlDatabase* connectToDB( QString dbName ); // connection SQLITE
    static void createTable(QSqlDatabase* db);         //  création de la table
    QString loadPaires(); // charge les couples ds le fichier ini
    void setHeaderTable();// fonction qui renomme le texte des header de la tableView

    Ui::MainWindow *ui;
    QSqlDatabase* db;

private slots:
    void on_actionCours_devises_triggered(); // Show/Hide cotatations en direct
    void reloadTableView(); // rafraichit le tableView
    void on_comboBox_currentTextChanged(const QString &arg1);//event sur le comboBox
    void on_btn_valider_date_clicked(); // validatoin de la date, lancement de la requête
    void on_actionGraphique_triggered();//Affichage du graphique
    void statutDataSAved(); // affichage du statut du backup
    void on_action_Rafraichir_triggered();//rafraichit le webview / enregistre les données
    void on_actionAbout_triggered(); // affichage de l'about

private:
    QSqlTableModel* model;
    CotationsView* cotes;


};

#endif // MAINWINDOW_H
