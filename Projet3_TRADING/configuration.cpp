#include "configuration.h"


#include <QXmlStreamWriter>

Configuration::Configuration()
{

    QSettings::Format XmlFormat = QSettings::registerFormat("xml", readXmlFile, writeXmlFile);
    QSettings settings(XmlFormat, QSettings::UserScope, "Organisation", "Name");


}

Configuration::~Configuration()
{

}

bool Configuration::readXmlFile(QIODevice &device, QSettings::SettingsMap &map) {
  QXmlStreamReader xmlReader(&device);
  QStringList elements;

  //Tant que la fin ne est pas atteint et aucune erreur ne s'est produite
  while (!xmlReader.atEnd() && !xmlReader.hasError()) {
    // lecture du prochain noeud
    xmlReader.readNext();


    if (xmlReader.isStartElement() && xmlReader.name() != "Settings") {

      elements.append(xmlReader.name().toString());

    } else if (xmlReader.isEndElement()) {

      if(!elements.isEmpty()) elements.removeLast();

    } else if (xmlReader.isCharacters() && !xmlReader.isWhitespace()) {
      QString key;


      for(int i = 0; i < elements.size(); i++) {
        if(i != 0) key += "/";
        key += elements.at(i);
      }


      map[key] = xmlReader.text().toString();
    }
  }

   if (xmlReader.hasError()) {
    qWarning() << xmlReader.errorString();
    return false;
  }

  return true;
}

bool Configuration::writeXmlFile(QIODevice &device, const QSettings::SettingsMap &map) {
  QXmlStreamWriter xmlWriter(&device);

  xmlWriter.setAutoFormatting(true);
  xmlWriter.writeStartDocument();
  xmlWriter.writeStartElement("Settings");

  QStringList prev_elements;
  QSettings::SettingsMap::ConstIterator map_i;

  // Alle Elemente der Map durchlaufen
  for (map_i = map.begin(); map_i != map.end(); map_i++) {

    QStringList elements = map_i.key().split("/");

    int x = 0;
    // Zu schließende Elemente ermitteln
    while(x < prev_elements.size() && elements.at(x) == prev_elements.at(x)) {
      x++;
    }

    // Elemente schließen
    for(int i = prev_elements.size() - 1; i >= x; i--) {
      xmlWriter.writeEndElement();
    }

    // Elemente öffnen
    for (int i = x; i < elements.size(); i++) {
      xmlWriter.writeStartElement(elements.at(i));
    }

    // Wert eintragen
    xmlWriter.writeCharacters(map_i.value().toString());

    prev_elements = elements;
  }

  // Noch offene Elemente schließen
  for(int i = 0; i < prev_elements.size(); i++) {
    xmlWriter.writeEndElement();
  }

  xmlWriter.writeEndElement();
  xmlWriter.writeEndDocument();

  return true;
}
