#ifndef COTATIONSVIEW_H
#define COTATIONSVIEW_H

#include <QWidget>
#include <QUrl>
#include <QVector>

class QSqlDatabase;

namespace Ui {
class CotationsView;
}

class CotationsView : public QWidget
{
    Q_OBJECT

public:
    explicit CotationsView(QSqlDatabase* db =0, QString _paires = "1;10", QWidget *parent = 0);
    ~CotationsView();

    void setUrl(QUrl &url); //Mise à jour de l'URL du webView
    void saveData(QVector<QString> &table);// enregistrement DB
    void setPaires(QString _paires){ m_paires = _paires;}//Setter
    QString getPaires(){ return m_paires;} //Getter



private:
    Ui::CotationsView *ui;
    QSqlDatabase* db;
    QString m_paires;
   // QVector<QString>* tdTable;


public slots:
       void rafraichirPage();
       void loadData();
       void afficheProprietes();
       void reloadTableView();
};

#endif // COTATIONSVIEW_H
