#ifndef COTATIONSVIEW_H
#define COTATIONSVIEW_H

#include <QWidget>
#include <QUrl>
#include <QSqlDatabase>

class QWebElement;

namespace Ui {
class cotationsView;
}

class cotationsView : public QWidget
{
    Q_OBJECT

public:
    explicit cotationsView(QSqlDatabase* db =0, QString _paires = "1;10", QWidget *parent = 0);
    ~cotationsView();
    //Mise à jour de l'URL du webView
    void setUrl(QUrl &url);
    void setPaires(QString _paires){ m_paires = _paires;} //Getter/Setter
    QString getPaires(){ return m_paires;}
    // enregistrement DB
    void saveData(QVector<QString> table);

private:
    Ui::cotationsView *ui;
    QSqlDatabase* db;
    QString m_paires;
   // QVector<QString>* tdTable;
   // QMap<QString, QString>* coupleMap;


signals:
    void dataSaved();

public slots:
       void rafraichirPage();
       void loadData();
       void afficheProprietes();
};

#endif // COTATIONSVIEW_H
