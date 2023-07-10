#include "cell_usermanager.h"
#include "ui_cell_usermanager.h"

Cell_UserManager::Cell_UserManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cell_UserManager)
{
    ui->setupUi(this);
    ui->tableView->setModel(&m_model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_model.setHorizontalHeaderLabels(QStringList{"用户名","姓名","权限","部门","学号","信用"});
    //将用户数据添加到ui界面
    QVector<QStringList> vec = SqlManager::getInstance()->getUsers();
    for (const QStringList& row : vec) {
        QList<QStandardItem*> items;
        for (const QString& value : row) {
            items.append(new QStandardItem(value));
        }
        m_model.appendRow(items);
    }
}

Cell_UserManager::~Cell_UserManager()
{
    delete ui;
}
