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
    m_model.setHorizontalHeaderLabels(QStringList{"用户id", "用户名", "姓名", "权限", "部门", "学号", "信用"});
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

void Cell_UserManager::on_pushButton_clicked()
{
    QString selectedFile = QFileDialog::getOpenFileName(this, "选择文件", "", "文本文件 (*.csv)");
    if (!selectedFile.isEmpty())
    {
        QFile file(selectedFile);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);
            QVector<QStringList> userList;

            while (!in.atEnd())
            {
                QString line = in.readLine();
                QStringList user = line.split(","); // CSV文件中每行用逗号分隔变量
                userList.append(user);
            }

            file.close();

            bool ret = SqlManager::getInstance()->addUsers(userList); // 调用添加用户到数据库的函数，传入读取的用户列表
            if(ret)
            {
                QMessageBox::information(this,"添加成功", "    添加成功！    ");
            }
            else
            {
                QMessageBox::warning(this, "添加失败", "    添加失败，请重试！    ");
            }
        }
    }
    else
        QMessageBox::warning(this, "添加失败", "    添加失败，请重试！    ");
    this->refreshTabel();
}


void Cell_UserManager::on_pushButton_2_clicked()
{
    Dlg_DeleteUser dlg;
    dlg.exec();
    this->refreshTabel();
}


void Cell_UserManager::on_pushButton_3_clicked()
{
    //搜索功能实现
    QString userName = ui->lineEdit->text();
    QString condition = QString("WHERE userName LIKE '%%1%'").arg(userName);
    m_model.clear();
    m_model.setHorizontalHeaderLabels(QStringList{"用户id", "用户名", "姓名", "权限", "部门", "学号", "信用"});
    //将用户数据添加到ui界面
    QVector<QStringList> vec = SqlManager::getInstance()->getUsers(condition);
    for (const QStringList& row : vec) {
        QList<QStandardItem*> items;
        for (const QString& value : row) {
            items.append(new QStandardItem(value));
        }
        m_model.appendRow(items);
    }
}

void Cell_UserManager::refreshTabel()
{
    //刷新窗口
    m_model.clear();
    m_model.setHorizontalHeaderLabels(QStringList{"用户id", "用户名", "姓名", "权限", "部门", "学号", "信用"});
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

