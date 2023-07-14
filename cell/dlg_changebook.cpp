#include "dlg_changebook.h"
#include "ui_dlg_changebook.h"

Dlg_ChangeBook::Dlg_ChangeBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_ChangeBook)
{
    ui->setupUi(this);
}

Dlg_ChangeBook::~Dlg_ChangeBook()
{
    delete ui;
}

void Dlg_ChangeBook::on_btn_confirm_clicked()
{
    QStringList book;
    book << ui->le1->text()
         << ui->le2->text()
         << ui->le3->text()
         << ui->le4->text()
         << ui->le5->text()
         << ui->le6->text()
         << ui->le7->text();
    QString bookId = ui->le8->text();
    bool ret = SqlManager::getInstance()->changeBook(bookId, book);
    if(ret)
    {
        QMessageBox::information(this,"修改成功", "    修改成功！    ");
        setResult(1);
        hide();
    }
    else
    {
        QMessageBox::warning(this, "修改失败", "    修改失败，请重试！    ");
        setResult(0);
        hide();
    }
}


void Dlg_ChangeBook::on_btn_cansel_clicked()
{
    setResult(0);
    hide();
}

