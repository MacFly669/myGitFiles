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
    void saveData(QVector<QString> table); /*! enregistrement DB !*/
    void initMain(); /*! initialisation du constructeur !*/
    void setUrl(QUrl &url);/*! /Mise à jour de l'URL du webView !*/
    void setPaires(QString &_paires){ m_paires = &_paires;} /*! Getter/Setter !*/

    QString getPaires(){ return *m_paires;} /*! renvoi les id à afficher et sauvegarder !*/
    OptionDialog* dlg;


private:
    Ui::CotationsView *ui;
    QSqlDatabase* db;
    QString *m_paires, url;

    QSettings::Format XmlFormat;

signals:
    void dataSaved(); /*! Signal emis lorsque la sauvegarde vers la base de données esst passée !*/
    void erreurConDb();
    void emitReloadCombo();
public slots:
       void reload();
       void updateUrl();
       void loadData();



private slots:
      // void on_pushButton_clicked();
       void afficheProprietes();
       void on_pushButton_clicked();
};

#endif // COTATIONSVIEW_H
