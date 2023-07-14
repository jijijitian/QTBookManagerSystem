#include "dlg_changepassword.h"
#include "ui_dlg_changepassword.h"

Dlg_ChangePassword::Dlg_ChangePassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_ChangePassword)
{
    ui->setupUi(this);
}

Dlg_ChangePassword::~Dlg_ChangePassword()
{
    delete ui;
}

void Dlg_ChangePassword::on_btn_login_clicked()
{
    QString password = ui->le_password->text();
    QString password2 = ui->le_password_2->text();
    if(password != password2)
    {
        QMessageBox::warning(this, "修改失败", "    两次输入密码不一致，请重试！    ");
    }
    else
    {
        bool ret = SqlManager::getInstance()->changePassword(password);
        if(ret)
        {
            QMessageBox::information(this,"修改成功", "    修改成功！    ");
            setResult(1);
            hide();
        }
        else
        {
            QMessageBox::warning(this, "修改失败", "    请联系管理员    ");
            setResult(0);
            hide();
        }
    }
}


void Dlg_ChangePassword::on_btn_exit_clicked()
{
    setResult(0);
    hide();
}


void Dlg_ChangePassword::on_btn_cansel_clicked()
{
    setResult(0);
    hide();
}

