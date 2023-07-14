#include "dlg_addbook.h"
#include "ui_dlg_addbook.h"

Dlg_AddBook::Dlg_AddBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_AddBook)
{
    ui->setupUi(this);
}

Dlg_AddBook::~Dlg_AddBook()
{
    delete ui;
}

void Dlg_AddBook::on_btn_confirm_clicked()
{
    QStringList book;
    book << ui->le1->text()
         << ui->le2->text()
         << ui->le3->text()
         << ui->le4->text()
         << ui->le5->text()
         << ui->le6->text()
         << ui->le7->text();
    bool ret = SqlManager::getInstance()->addBooks(book);
    if(ret)
    {
        QMessageBox::information(this,"添加成功", "    添加成功！    ");
        setResult(1);
        hide();
    }
    else
    {
        QMessageBox::warning(this, "添加失败", "    添加失败，请重试！    ");
        setResult(0);
        hide();
    }
}


void Dlg_AddBook::on_btn_cansel_clicked()
{
    setResult(0);
    hide();
}

