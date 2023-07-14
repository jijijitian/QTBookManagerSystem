#include "dlg_deleterecord.h"
#include "ui_dlg_deleterecord.h"

Dlg_DeleteRecord::Dlg_DeleteRecord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_DeleteRecord)
{
    ui->setupUi(this);
}

Dlg_DeleteRecord::~Dlg_DeleteRecord()
{
    delete ui;
}

void Dlg_DeleteRecord::on_btn_confirm_clicked()
{
    bool ret = SqlManager::getInstance()->clearRecord();

    if(ret)
    {
        QMessageBox::information(this,"删除成功", "    删除成功！    ");
        setResult(1);
        hide();
    }
    else
    {
        QMessageBox::warning(this, "删除失败", "    请检查借阅列表    ");
        setResult(0);
        hide();
    }
}


void Dlg_DeleteRecord::on_btn_cancel_clicked()
{
    setResult(0);
    hide();
}

