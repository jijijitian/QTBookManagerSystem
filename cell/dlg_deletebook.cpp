#include "dlg_deletebook.h"
#include "ui_dlg_deletebook.h"

Dlg_DeleteBook::Dlg_DeleteBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_DeleteBook)
{
    ui->setupUi(this);
}

Dlg_DeleteBook::~Dlg_DeleteBook()
{
    delete ui;
}

void Dlg_DeleteBook::on_btn_confirm_clicked()
{
    QString bookId = ui->le_bookid->text();

    bool ret = SqlManager::getInstance()->deleteBook(bookId);

    if(ret)
    {
        QMessageBox::information(this,"删除成功", "    删除成功！    ");
        setResult(1);
        hide();
    }
    else
    {
        QMessageBox::warning(this, "删除失败", "    请检查图书id    ");
        setResult(0);
        hide();
    }
}


void Dlg_DeleteBook::on_btn_cancel_clicked()
{
    setResult(0);
    hide();
}

