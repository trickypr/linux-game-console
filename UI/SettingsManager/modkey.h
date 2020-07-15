#ifndef MODKEY_H
#define MODKEY_H

#include <QStringList>

class ModKey
{
public:
    ModKey();

    static QStringList keys;

    static QString applySettings(QString modKey);
};

#endif // MODKEY_H
