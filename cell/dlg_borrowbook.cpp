#include "dlg_borrowbook.h"
#include "ui_dlg_borrowbook.h"

Dlg_BorrowBook::Dlg_BorrowBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_BorrowBook)
{
    ui->setupUi(this);
}

Dlg_BorrowBook::~Dlg_BorrowBook()
{
    delete ui;
}

void Dlg_BorrowBook::on_btn_confirm_clicked()
{
    QString bookId = ui->le_bookid->text();
    int ret = SqlManager::getInstance()->borrowBook(bookId);
    if(ret == 1)
    {
        QMessageBox::information(this,"借阅成功", "    借阅成功！    ");
        setResult(1);
        hide();
    }
    else if(ret == -1)
    {
        QMessageBox::warning(this, "借阅失败", "    请联系管理员    ");
        setResult(0);
        hide();
    }
    else if(ret == -2)
    {
        QMessageBox::warning(this, "借阅失败", "    最多只能借阅3本图书！    ");
        setResult(0);
        hide();
    }
    else if(ret == -3)
    {
        QMessageBox::warning(this, "借阅失败", "    本书已被您借阅！    ");
        setResult(0);
        hide();
    }
    else if(ret == -4)
    {
        QMessageBox::warning(this, "借阅失败", "    本书暂无库存    ");
        setResult(0);
        hide();
    }
}

void Dlg_BorrowBook::on_btn_cancel_clicked()
{
    setResult(0);
    hide();
}

