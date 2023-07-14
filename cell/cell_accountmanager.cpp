#include "cell_accountmanager.h"
#include "ui_cell_accountmanager.h"

Cell_AccountManager::Cell_AccountManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cell_AccountManager)
{
    ui->setupUi(this);
    ui->tableView->setModel(&m_model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_model.setHorizontalHeaderLabels(QStringList{"用户名", "姓名", "部门", "学号", "信用"});

    //将用户数据添加到ui界面
    QStringList account = SqlManager::getInstance()->getAccount();
    QList<QStandardItem*> item;
    for (const QString& value : account) {
        item.append(new QStandardItem(value));
    }
    m_model.appendRow(item);
}

Cell_AccountManager::~Cell_AccountManager()
{
    delete ui;
}

void Cell_AccountManager::on_pushButton_clicked()
{
    Dlg_ChangePassword dlg;
    dlg.exec();
}

