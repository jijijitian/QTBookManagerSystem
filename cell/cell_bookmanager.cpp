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

Cell_BookManager::~Cell_BookManager()
{
    delete ui;
}

void Cell_BookManager::on_pushButton_clicked()
{
    Dlg_AddBook dlg;
    dlg.exec();
    this->refreshTable();
}


void Cell_BookManager::on_pushButton_3_clicked()
{
    Dlg_ChangeBook dlg;
    dlg.exec();
    this->refreshTable();
}


void Cell_BookManager::on_pushButton_2_clicked()
{
    Dlg_DeleteBook dlg;
    dlg.exec();
    this->refreshTable();
}

void Cell_BookManager::refreshTable()
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


void Cell_BookManager::on_pushButton_4_clicked()
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

