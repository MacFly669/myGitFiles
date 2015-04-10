#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include "optiondialog.h"
#include <QSettings>

class Configuration : public OptionDialog
{
public:
    Configuration();
    ~Configuration();
    bool readXmlFile(QIODevice &device, QSettings::SettingsMap &map);
    bool writeXmlFile(QIODevice &device, const QSettings::SettingsMap &map);
};

#endif // CONFIGURATION_H
