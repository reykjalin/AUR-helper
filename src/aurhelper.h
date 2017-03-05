#ifndef AURHELPER_H
#define AURHELPER_H

#include <QMainWindow>
#include <QDebug>

#include "versionlistmodel.h"

namespace Ui {
class MainWindow;
}

class AurHelper : public QMainWindow
{
    Q_OBJECT

public:
    AurHelper(QWidget *parent = 0);
    ~AurHelper();

public slots:
    void close();

private:
    Ui::MainWindow *ui;
};

#endif // AURHELPER_H
