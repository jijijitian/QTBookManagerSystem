#include "cell_bookmanager.h"
#include "ui_cell_bookmanager.h"

Cell_BookManager::Cell_BookManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cell_BookManager)
{
    ui->setupUi(this);
    ui->tableView->setModel(&m_model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_model.setHorizontalHeaderLabels(QStringList{"书名","作者","库存","出版社","类型1","类型2","类型3"});
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

Cell_BookManager::~Cell_BookManager()
{
    delete ui;
}
