#include "dlg_login.h"
#include "ui_dlg_login.h"

Dlg_Login::Dlg_Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_Login)
{
    ui->setupUi(this);
}

Dlg_Login::~Dlg_Login()
{
    delete ui;
}

void Dlg_Login::on_btn_login_clicked()
{
    QString userName = ui->le_userName->text();
    QString password = ui->le_password->text();
    bool ret = SqlManager::getInstance()->login(userName, password);
    if(ret)
    {
        setResult(1);
        hide();
    }
    else
    {
        QMessageBox::warning(this, "登陆失败", "    用户名或密码错误，请重试。    ");
    }
}


void Dlg_Login::on_btn_exit_clicked()
{
    setResult(0);
    hide();
}

