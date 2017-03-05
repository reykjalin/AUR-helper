#include "versiontable.h"

VersionTable::VersionTable(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi();
}
