#ifndef COTATIONSVIEW_H
#define COTATIONSVIEW_H

//#include "optiondialog.h"

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
    //Mise à jour de l'URL du webView
    void setUrl(QUrl &url);
    void setPaires(QString &_paires){ m_paires = &_paires;} //Getter/Setter
    QString getPaires(){ return *m_paires;}
    // enregistrement DB
    void saveData(QVector<QString> table);

private:
    Ui::CotationsView *ui;
    QSqlDatabase* db;
    QString *m_paires;
    OptionDialog* dlg;
   // QVector<QString>* tdTable;
   // QMap<QString, QString>* coupleMap;


signals:
    void dataSaved();

public slots:
       void rafraichirPage();
       void loadData();
       void afficheProprietes();


private slots:
       void on_pushButton_clicked();
};

#endif // COTATIONSVIEW_H
