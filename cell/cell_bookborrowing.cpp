#include "cell_bookborrowing.h"
#include "ui_cell_bookborrowing.h"

Cell_BookBorrowing::Cell_BookBorrowing(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cell_BookBorrowing)
{
    ui->setupUi(this);
    ui->tableView->setModel(&m_model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_model.setHorizontalHeaderLabels(QStringList{"图书id", "书名", "作者", "库存", "出版社", "类型1", "类型2", "类型3"});
    //将图书数据添加到ui界面
    QVector<QStringList> vec = SqlManager::getInstance()->getBooks();
    for (const QStringList& row : vec) {
        QList<QStandardItem*> items;
        for (const QString& value : row) {
            items.append(new QStandardItem(value));
        }
        m_model.appendRow(items);
    }
}

Cell_BookBorrowing::~Cell_BookBorrowing()
{
    delete ui;
}
