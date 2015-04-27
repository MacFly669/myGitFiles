#ifndef MAINWINDOW_H
#define MAINWINDOW_H


///!********************************************************************************
///!
///                         CLASS MAINWINDOW
/// \brief Fenêtre principale
///
///
///
///
///
/// *********************************************************************************
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSettings>
#include <QTableView>

class CotationsView;
class QSqlTableModel;
class Graphique;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QSqlDatabase* _db =0, QWidget *parent = 0);
    ~MainWindow();
/*!  Fonction static qui renvoi un QMap avec en key le nom des paires, en valeur l'id de la paire  */
    static  QMap<QString, QString> getMap();
/*! \fn renomme le texte des header de la tableView **/
    static void setHeaderTable(QSqlTableModel &model, QTableView* tableView );


    QSettings::Format XmlFormat;

private:
    QSqlDatabase* db;
    void initGui();
    QSqlTableModel* model;
    CotationsView* cotes;
    Graphique* graph;
    Ui::MainWindow *ui;



signals:
    void erreurConDb();


private slots:
         void comboChanged(QString arg1);
         void statutDataSaved(); // affichage du statut du backup

private slots:
    void on_actionShowHideView_triggered(); // Show/Hide cotatations en direct
    void reloadTableView(); // rafraichit le tableView
    void on_actionGraphique_triggered();//Affichage du graphique
    void on_action_Rafraichir_triggered();//rafraichit le webview / enregistre les données
    void on_actionAbout_triggered(); // affichage de l'about
    void openSim();
    void initCombo();
    bool isChecked(QString str);

    void on_actionCalendrier_triggered();


};

bool readXmlFile( QIODevice& device, QSettings::SettingsMap& map );
bool writeXmlFile( QIODevice& device, const QSettings::SettingsMap& map );

#endif // MAINWINDOW_H
