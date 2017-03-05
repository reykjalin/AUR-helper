#include "installedversionservice.h"

// Return codes defined in errorcodes.h
int InstalledVersionService::getInstalledVrsn(QString pkgName, QString &vrsn) {
    QString     pacman = "pacman";
    QStringList args;
    args << "-Q" << pkgName;

    QProcess getPkgInfo;
    getPkgInfo.start(pacman, args);
    if(!getPkgInfo.waitForStarted())
        return START_ERROR;
    if(!getPkgInfo.waitForFinished())
        return FINISH_ERROR;

    // If exit code is non-zero pacman couldn't find package
    if(getPkgInfo.exitCode())
        return EXIT_CODE_ERROR;

    vrsn = QString(getPkgInfo.readAllStandardOutput());

    // Match version number
    QRegExp rx("(\\d+)(.\\d+)*(-\\d+)*(\\n)*$");
    vrsn.remove(0, rx.indexIn(vrsn));
    // -1 due to \n
    vrsn.remove(rx.matchedLength() - 1, vrsn.length());

    return SUCCESS;
}
