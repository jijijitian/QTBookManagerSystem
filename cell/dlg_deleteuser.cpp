#include "dlg_deleteuser.h"
#include "ui_dlg_deleteuser.h"

Dlg_DeleteUser::Dlg_DeleteUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_DeleteUser)
{
    ui->setupUi(this);
}

Dlg_DeleteUser::~Dlg_DeleteUser()
{
    delete ui;
}

void Dlg_DeleteUser::on_btn_confirm_clicked()
{
    QString userId = ui->le_userid->text();
    bool ret = SqlManager::getInstance()->deleteUser(userId);
    if(ret)
    {
        QMessageBox::information(this,"删除成功", "    删除成功！    ");
        setResult(1);
        hide();
    }
    else
    {
        QMessageBox::warning(this, "删除失败", "    请检查用户id    ");
        setResult(0);
        hide();
    }

}


void Dlg_DeleteUser::on_btn_cancel_clicked()
{
    setResult(0);
    hide();
}

