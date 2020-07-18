#include <iostream>
#include <fstream>

#include "wmconfig.h"

using namespace std;

string qStringToStr(QString orig)
{
    return orig.toLocal8Bit().data();
}

WMConfig::WMConfig() {}

void WMConfig::applySettings(QString modKey, QStringList autoStartApps, QStringList screens)
{
    string autoStart = "";
    for (QString app : autoStartApps)
        autoStart = autoStart + "\"" + app.toStdString() + "\",";

    string configScreens = "";
    for (QString screen : screens)
        configScreens = configScreens + "\"" + screen.toStdString() + "\",";

    string fileContents =
            "-- This file has been overriden by the settings app. Do not edit \n"
            ""
            "local config = {} \n"
            ""
            "config.modkey = \"" + qStringToStr(modKey) + "\"\n"
            ""
            "config.screens = {" + configScreens + "} \n"
            ""
            "config.autoStart = {" + autoStart + "}\n"
            ""
            "return config";

    ofstream confFile;
    confFile.open("/etc/xdg/awesome/config.lua");
    confFile << fileContents;
    confFile.close();
}

QStringList WMConfig::keys = {
    "Any",
    "Mod1",
    "Mod2",
    "Mod3",
    "Mod4",
    "Mod5",
    "Shift",
    "Lock",
    "Control"
};

