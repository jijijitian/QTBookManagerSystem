#include "cell_borrowingrecord.h"
#include "ui_cell_borrowingrecord.h"

Cell_BorrowingRecord::Cell_BorrowingRecord(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cell_BorrowingRecord)
{
    ui->setupUi(this);
    ui->tableView->setModel(&m_model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_model.setHorizontalHeaderLabels(QStringList{"借阅时间","归还时间","用户id","图书id"});
    //将借阅数据添加到ui界面
    QVector<QStringList> vec = SqlManager::getInstance()->getRecords();
    for (const QStringList& row : vec) {
        QList<QStandardItem*> items;
        for (const QString& value : row) {
            items.append(new QStandardItem(value));
        }
        m_model.appendRow(items);
    }
}

Cell_BorrowingRecord::~Cell_BorrowingRecord()
{
    delete ui;
}
