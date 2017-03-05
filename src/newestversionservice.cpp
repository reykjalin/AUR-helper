#include "newestversionservice.h"

int NewestVersionService::fetchNewestVrsn(QString pkgName) {
    man = new QNetworkAccessManager(this);
    reply = man->get(QNetworkRequest("https://aur.archlinux.org/packages/" + pkgName));

    // Connect signals
    QObject::connect(man, SIGNAL(finished(QNetworkReply*)), this, SLOT(on_loadFinished()));
    QObject::connect(reply, SIGNAL(readyRead()), this, SLOT(on_readyRead()));

    return 0;
}

void NewestVersionService::on_readyRead() {
    data.append(reply->readAll());
}

void NewestVersionService::on_loadFinished() {
    DOM = QString(data);

    QRegExp rx("<h2>Package Details: (.*)</h2>");
    DOM.remove(0, rx.indexIn(DOM));
    // -5 to remove </h2>
    DOM.remove(rx.matchedLength() - 5, DOM.length());
    DOM.remove(0, 4); // Remove <h2>

    QRegExp rxVrsn("(\\d+)(.\\d+)*(-\\d+)*(\\n)*");
    DOM.remove(0, rxVrsn.indexIn(DOM));
    DOM.remove(rx.matchedLength() - 1, DOM.length());

    qDebug() << "online version: " << DOM << endl;

    // CLEANUP
    reply->deleteLater();
    man->deleteLater();
    reply = NULL;
    man = NULL;
    data.clear();
}
