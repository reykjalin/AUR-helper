#ifndef INSTALLEDVERSIONSERVICE_H
#define INSTALLEDVERSIONSERVICE_H

#include <QProcess>
#include <QStringList>
#include <QDebug>
#include <QRegExp>

#include "errorcodes.h"

class InstalledVersionService
{
    public:
        InstalledVersionService() { }

        bool isInstalled(QString pkgName);
        int getInstalledVrsn(QString pkgName, QString &vrsn);
    private:
};

#endif // INSTALLEDVERSIONSERVICE_H
