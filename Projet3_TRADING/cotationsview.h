#ifndef COTATIONSVIEW_H
#define COTATIONSVIEW_H
///!***************************************************************************************///
///                              CLASS COTATIONSVIEW
///
/// Cette class utilise un webView pour afficher les cotations devises via l'url générée
/// sur le site de Forex.
/// Le constructeur prend en paramètre une base SQLITE , la paire sous forme d'id stocké
/// en QString.
///
/// Les méthodes :
/// setUrl() permet de mettre à jour l'url passé en paramètre au format QUrl
/// setPaires() permet de mettre à jour la variable qui stocke les id à afficher
/// getPaires() renvoi un QString retournant le ou les id contenu dans la variable.
/// saveData sauvegarde les données dans la base. Prend un tableau string en paramètre.
///
/// Les signaux:
/// dataSaved() emis lors de l'insertion réussie des données
///
/// Les slots:
/// updateUrl() recharge la page
/// loadData() charge les données et les stocke dans un tableau
/// afficheProprietes() ouvre la boite de dialogue de sélection des couples
///
/// **************************************************************************************///
#include <QWidget>
#include <QUrl>
#include <QSqlDatabase>

class QWebElement;
class OptionDialog;

namespace Ui {
class CotationsView;
}

class CotationsView : public QWidget
{
    Q_OBJECT

public:
    explicit CotationsView(QSqlDatabase* db =0, QString *_paires = 0, QWidget *parent = 0);
    ~CotationsView();
    QString getPaires(){ return *m_paires;} // renvoi les id à afficher et sauvegarder
    void setUrl(QUrl &url);//Mise à jour de l'URL du webView
    void setPaires(QString &_paires){ m_paires = &_paires;} //Getter/Setter
    void saveData(QVector<QString> table); // enregistrement DB

private:
    Ui::CotationsView *ui;
    QSqlDatabase* db;
    QString *m_paires;
    OptionDialog* dlg;


signals:
    void dataSaved();

public slots:
       void reload();
       void updateUrl();
       void loadData();



private slots:
       void on_pushButton_clicked();
       void afficheProprietes();
};

#endif // COTATIONSVIEW_H
