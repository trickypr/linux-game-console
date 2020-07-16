#include <string>
#include <iostream>
#include <filesystem>

#include <QStringList>
#include <QDebug>

#include "desktopapps.h"

using namespace std;
namespace fs = filesystem;

string getFileName(fs::path path, bool withExtention = false)
{
    // Check if the file name should have an extention
    if (withExtention)
    {
        // Return the file path with an extention
        return path.filename().string();
    } else
    {
        // Check if the file has a stem (a filename with the extention removed)
        // If the file has a stem return it
        if (path.has_stem())
            return path.stem().string();

        // Otherwise return an empty string
        return "";
    }
}

string getFileName(string filePath, bool withExtention = false)
{
    // Converts string to path and passes it into the path version of the function
    return getFileName(fs::path(filePath), withExtention);
}

QStringList listInDir(string dir)
{
    QStringList dirs = {};

    // Check if the directory exists to prevent errors
    if (fs::exists(fs::path(dir)))
    {
        for (const auto & entry : fs::directory_iterator(dir))
                dirs << QString::fromStdString(getFileName(entry.path()));
    }

    return dirs;
}

QStringList DesktopApps()
{
    QStringList globalDir = listInDir("/usr/share/applications/");
    QStringList localDir  = listInDir("~/.local/share/applications");

    QStringList allApps = {};

    for (QString app : globalDir)
        allApps << app;

    for (QString app : localDir)
        allApps << app;

    return allApps;
}
