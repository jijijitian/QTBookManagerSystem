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

void Cell_BookBorrowing::on_pushButton_clicked()
{
    //调用借阅窗口
    Dlg_BorrowBook dlg_borrow;
    dlg_borrow.exec();
    this->refreshTable();
}


void Cell_BookBorrowing::on_pushButton_3_clicked()
{
    //调用归还窗口
    Dlg_ReturnBook dlg_return;
    dlg_return.exec();
    this->refreshTable();
}


void Cell_BookBorrowing::on_btn_search_clicked()
{
    //搜索图书实现
    QString title = ui->lineEdit->text();
    QString condition = QString("WHERE title LIKE '%%1%'").arg(title);
    m_model.clear();
    m_model.setHorizontalHeaderLabels(QStringList{"图书id", "书名", "作者", "库存", "出版社", "类型1", "类型2", "类型3"});
    //将图书数据添加到ui界面
    QVector<QStringList> vec = SqlManager::getInstance()->getBooks(condition);
    for (const QStringList& row : vec) {
        QList<QStandardItem*> items;
        for (const QString& value : row) {
            items.append(new QStandardItem(value));
        }
        m_model.appendRow(items);
    }
}

void Cell_BookBorrowing::refreshTable()
{
    m_model.clear();
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

