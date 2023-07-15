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
    m_model.setHorizontalHeaderLabels(QStringList{"书名", "借阅时间", "借阅状态", "归还时间"});
    //将借阅数据添加到ui界面
    QString condition = QString("WHERE record.userid = %1").arg(SqlManager::getInstance()->getUserid());
    QVector<QStringList> vec = SqlManager::getInstance()->getBorrowingBooks(condition);
    for (const QStringList& row : vec) {
        QList<QStandardItem*> items;
        for (const QString& value : row) {
            items.append(new QStandardItem(value));
        }
        m_model.appendRow(items);
    }
}

void Cell_StudentBorrowing::refreshTabel()
{
    m_model.clear();
    m_model.setHorizontalHeaderLabels(QStringList{"书名", "借阅时间", "借阅状态", "归还时间"});
    //将借阅数据添加到ui界面
    QString condition = QString("WHERE record.userid = %1").arg(SqlManager::getInstance()->getUserid());
    QVector<QStringList> vec = SqlManager::getInstance()->getBorrowingBooks(condition);
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

void Cell_StudentBorrowing::on_pushButton_clicked()
{
    this->refreshTabel();
}

