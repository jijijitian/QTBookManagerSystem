#include "cell_usermanager.h"
#include "ui_cell_usermanager.h"

Cell_UserManager::Cell_UserManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cell_UserManager)
{
    ui->setupUi(this);
}

Cell_UserManager::~Cell_UserManager()
{
    delete ui;
}
