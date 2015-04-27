#ifndef CONNECTIONBASE_H
#define CONNECTIONBASE_H

#include <QString>


class QSqlDatabase;

class ConnectionBase
{
public:
    ConnectionBase();
    ~ConnectionBase();

    /*! Fonction static de connection  à la base SQLITE  */
       static QSqlDatabase* ouvreConnex(QString dbName , QString server, QString user, QString pass);
   /*!  Création de la table si elle n'existe pas  */
       static void createTable(QSqlDatabase* db);
       /*! enregistrement DB */
      static void saveData(QSqlDatabase *db, QVector<QString> table);



   private:
       static QSqlDatabase* db;

};

#endif // CONNECTIONBASE_H
