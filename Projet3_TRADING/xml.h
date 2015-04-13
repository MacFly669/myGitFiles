#ifndef XML
#define XML

#include <QXmlStreamReader>
#include <QSettings>
#include <QDebug>
//! \file  xml.h
//! \author Sven
//! \date 19.03.2011
//!
//!
//!
//!
//!
//!
//! \brief readXmlFile fonction de lecture du fichier xml de sauvegarde de configurtation
//! \param device  param de type QIODevice
//! \param map : Mapping de valeur de QSettings
//! \return  vrai ou false si erreur
//!
//!
//!
//!
//!
//!
//!
bool readXmlFile( QIODevice& device, QSettings::SettingsMap& map )
{
    QXmlStreamReader xmlReader(&device);
    QStringList elements;

    // Tant qu'on est pas à la fin
    while (!xmlReader.atEnd() && !xmlReader.hasError()) {
      // on avance la tête de lecture
      xmlReader.readNext();

      // Si début du document
      if (xmlReader.isStartElement() && xmlReader.name() != "Settings") {
        // Ajouter un article à la liste
        elements.append(xmlReader.name().toString());
      // if balise fermante
      } else if (xmlReader.isEndElement()) {
        // supprimer le dernier élément
        if(!elements.isEmpty()) elements.removeLast();
      // Si contient une valeur
      } else if (xmlReader.isCharacters() && !xmlReader.isWhitespace()) {
        QString key;

        // Ajouter les éléments
        for(int i = 0; i < elements.size(); i++) {
          if(i != 0) key += "/";
          key += elements.at(i);
        }

        // récupération de la valeur
        map[key] = xmlReader.text().toString();
      }
    }

    // Gestion d'erreur
    if (xmlReader.hasError()) {
      qWarning() << xmlReader.errorString();
      return false;
    }

    return true;
}
//!
//!
//! \brief writeXmlFile fonction qui écrit les configuration du QSettings au format XML
//! \param device  param de type QIODevice
//! \param map : Mapping de valeur de QSettings
//! \return  vrai ou false si erreur
//!
//!
//!
//!
//!
//!
bool writeXmlFile( QIODevice& device, const QSettings::SettingsMap& map )
{
    QXmlStreamWriter xmlWriter(&device);

     xmlWriter.setAutoFormatting(true);
     xmlWriter.writeStartDocument();
     xmlWriter.writeStartElement("Settings");

     QStringList prev_elements;
     QSettings::SettingsMap::ConstIterator map_i;

     // Boucle sur les élément de la Map
     for (map_i = map.begin(); map_i != map.end(); map_i++) {

       QStringList elements = map_i.key().split("/");

       int x = 0;
       // déterminer les éléments de fermeture
       while(x < prev_elements.size() && elements.at(x) == prev_elements.at(x)) {
         x++;
       }

       // Fermeture
       for(int i = prev_elements.size() - 1; i >= x; i--) {
         xmlWriter.writeEndElement();
       }

       // Ouverture
       for (int i = x; i < elements.size(); i++) {
         xmlWriter.writeStartElement(elements.at(i));
       }

       // écrire la valeur
       xmlWriter.writeCharacters(map_i.value().toString());

       prev_elements = elements;
     }

     // Fermer les éléments
     for(int i = 0; i < prev_elements.size(); i++) {
       xmlWriter.writeEndElement();
     }

     xmlWriter.writeEndElement();
     xmlWriter.writeEndDocument();

     return true;

}


#endif // XML


