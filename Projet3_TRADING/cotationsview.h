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
    explicit CotationsView(QSqlDatabase* db =0, QString *_paires = 0, QWidget *parent = 0);
    ~CotationsView();
    /*! enregistrement DB */
    void saveData(QVector<QString> table);
    /*! initialisation du constructeur */
    void initMain(); /*! Mise à jour de l'URL du webView */
    void setUrl(QUrl &url);
    /*! Setter :Modifie l'attribut membre m_paires, les id couple devise */
    void setPaires(QString &_paires){ m_paires = &_paires;} /*! Getter/Setter */
 /*! renvoi les id à afficher et sauvegarder */
    QString getPaires(){ return *m_paires;}
    /*! Objet de type QDialog */
    OptionDialog* dlg;


private:
    Ui::CotationsView* ui;
    QSqlDatabase* db;
    QString* m_paires, url;

    QSettings::Format XmlFormat;

signals:
    void dataSaved(); /*! Signal emis lorsque la sauvegarde vers la base de données esst passée */
    void erreurConDb();
    void emitReloadCombo();

public slots:
       void reload();
       void updateUrl();
       void loadData();
       void afficheProprietes();


private slots:
       void on_pushButton_clicked();
};

#endif // COTATIONSVIEW_H
