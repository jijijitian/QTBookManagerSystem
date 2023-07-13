#include "cell_studentborrowing.h"
#include "ui_cell_studentborrowing.h"

Cell_StudentBorrowing::Cell_StudentBorrowing(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cell_StudentBorrowing)
{
    ui->setupUi(this);
    ui->tableView->setModel(&m_model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_model.setHorizontalHeaderLabels(QStringList{"借阅id", "借阅时间", "归还时间", "用户id", "图书id"});
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

Cell_StudentBorrowing::~Cell_StudentBorrowing()
{
    delete ui;
}
