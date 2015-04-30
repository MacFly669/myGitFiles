#ifndef CONNECTIONBASE_H
#define CONNECTIONBASE_H

#include <QIODevice>
#include <QString>
#include <QSettings>

class QSqlDatabase;

class ConnectionBase
{
public:
    ConnectionBase();
    ~ConnectionBase();

    /*! Fonction static de connection  à la base SQLITE  */
       static QSqlDatabase* ouvreConnex(QString dbName , QString server, QString user, QString pass);
   /*!  Création de la table si elle n'existe pas  */
       static void createTableSqlite(QSqlDatabase* db);
       static void createTableMySql(QSqlDatabase* db);
       /*! enregistrement DB */
      static void saveData(QSqlDatabase *db, QVector<QString> table);



   private:
       static QSqlDatabase* db;


};

bool readXmlFile( QIODevice& device, QSettings::SettingsMap& map );
bool writeXmlFile( QIODevice& device, const QSettings::SettingsMap& map );
#endif // CONNECTIONBASE_H
