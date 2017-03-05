#include "aurhelper.h"
#include "installedversionservice.h"
#include "newestversionservice.h"

#include <QApplication>
#include <QSystemTrayIcon>
#include <QTableView>

#include "versionlistmodel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AurHelper w;

    QObject::connect(&w, SIGNAL(finished()), &a, SLOT(quit()));

    // QTimer for main function

    // Load icon
    QIcon icon = QIcon("/home/kristofer/Programs/qt-projects/AUR-helper/resources/aur-helper-icon.svg");
    QSystemTrayIcon trayIcon;
    trayIcon.setIcon(icon);
    trayIcon.setToolTip("No updates available");
    trayIcon.show();

    // Get package version
    InstalledVersionService service;
    QString enpassVrsn;
    if(!service.getInstalledVrsn("enpass-bin", enpassVrsn))
        qDebug() << "local version: " << enpassVrsn << endl;
    else
        qDebug() << "Package enpass-bin not found" << endl;

    NewestVersionService nService;
    nService.fetchNewestVrsn("enpass-bin");

    w.show();

    return a.exec();
}
