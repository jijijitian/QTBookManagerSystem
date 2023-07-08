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
    setResult(1);
    hide();
}


void Dlg_Login::on_btn_exit_clicked()
{
    setResult(0);
    hide();
}

