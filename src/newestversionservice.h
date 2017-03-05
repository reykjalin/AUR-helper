#ifndef NEWESTVERSIONSERVICE_H
#define NEWESTVERSIONSERVICE_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QByteArray>
#include <QDebug>
#include <QRegExp>

#include "errorcodes.h"

class NewestVersionService : public QObject
{
    Q_OBJECT
    public:
        NewestVersionService() { }

        int fetchNewestVrsn(QString pkgName);

    public slots:
        void on_readyRead();
        void on_loadFinished();

    private:
        QNetworkAccessManager *man;
        QNetworkReply *reply;
        QByteArray data;
        QString DOM;
};

#endif // NEWESTVERSIONSERVICE_H
