#ifndef SAVETOXML_H
#define SAVETOXML_H

#include <QIODevice>
#include <QSettings>


class saveToXml
{
public:
    saveToXml();
    ~saveToXml();

    bool readXmlFile( QIODevice& device, QSettings::SettingsMap& map );
    bool writeXmlFile( QIODevice& device, const QSettings::SettingsMap& map );
};

#endif // SAVETOXML_H
