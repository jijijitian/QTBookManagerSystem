#include "cell_bookmanager.h"
#include "ui_cell_bookmanager.h"

Cell_BookManager::Cell_BookManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cell_BookManager)
{
    ui->setupUi(this);
}

Cell_BookManager::~Cell_BookManager()
{
    delete ui;
}
