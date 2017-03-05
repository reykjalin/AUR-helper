#include "aurhelper.h"
#include "ui_aurhelper.h"

AurHelper::AurHelper(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    VersionListModel model(0);
    ui->tableView->setModel(&model);
}

AurHelper::~AurHelper()
{
    delete ui;
}

void AurHelper::close() {
    QApplication::exit();
}
