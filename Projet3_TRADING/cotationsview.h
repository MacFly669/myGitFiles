#ifndef COTATIONSVIEW_H
#define COTATIONSVIEW_H

#include <QWidget>
#include <QUrl>
#include <QSqlDatabase>
#include <QSettings>
class QWebElement;
class OptionDialog;

namespace Ui {
class CotationsView;
}

class CotationsView : public QWidget
{
    Q_OBJECT

public:
    /*! initialisation du constructeur */
    explicit CotationsView(QSqlDatabase* _db =0, QString* _paires = 0, QWidget *parent = 0);
    ~CotationsView();
   /*! Mise à jour de l'URL du webView */
    void initMain();
    /*! Change l'url du QWebview */
    void setUrl(QUrl &url);
    /*! Setter :Modifie l'attribut membre m_paires, les id couple devise */
    void setPaires(QString &_paires){ m_paires = &_paires;} /*! Getter/Setter */
 /*! renvoi les id à afficher et sauvegarder */
    QString getPaires(){ return *m_paires;}
    /*! Objet de type QDialog */
    OptionDialog* dlg;

signals:
    void dataSaved(); /*! Signal emis lorsque la sauvegarde vers la base de données
                        est passée afin de lancer la rafraichissement de la table*/
    void erreurConDb();
    void emitReloadCombo();

public slots:
       /*: Recharge le QWebview, équivaut à un F5 dans le navigateur */
       void reload();
       /*! Mise à jour */
       void updateUrl();
       /*! Fonction qui charge les données les stocke dans un QVector avant de l'envoyer à) la base */
       void loadData();
       /*! Affiche la boite de dialogue des options utilisateurs */
       void afficheProprietes();


private slots:
        /*! action sur le bouton ui->btnRefresh */
       void on_btnRefresh_clicked();

private:
    Ui::CotationsView* ui;
    QSqlDatabase* db; /*! Pointeur vers l'instance QSqlDatabase */
    QString* m_paires; /*! id des paires à affichar ex: "1;10" */
    QString url; /*! requête http passée dans le QWebview */

    QSettings::Format XmlFormat;


};

#endif // COTATIONSVIEW_H
