#include "cell_borrowingrecord.h"
#include "ui_cell_borrowingrecord.h"

Cell_BorrowingRecord::Cell_BorrowingRecord(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cell_BorrowingRecord)
{
    ui->setupUi(this);
}

Cell_BorrowingRecord::~Cell_BorrowingRecord()
{
    delete ui;
}
