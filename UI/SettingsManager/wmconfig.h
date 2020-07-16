#ifndef WMCONFIG_H
#define WMCONFIG_H

#include <QStringList>

class WMConfig
{
public:
    WMConfig();

    static QStringList keys;

    static void applySettings(QString modKey, QStringList autoStartApps);
};

#endif // WMCONFIG_H
