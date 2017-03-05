#ifndef VERSIONTABLE_H
#define VERSIONTABLE_H

#include <QWidget>
#include <QTableView>
#include <QAbstractTableModel>

#include "versionlistmodel.h"

namespace Ui {
    class centralWidget;
}

class VersionTable : public QWidget
{
    Q_OBJECT

public:
    explicit VersionTable(QWidget *parent = 0);
    ~VersionTable();

private:
    Ui::MainWindow *ui;

    QAbstractTableModel *model;
};

#endif // VERSIONTABLE_H
