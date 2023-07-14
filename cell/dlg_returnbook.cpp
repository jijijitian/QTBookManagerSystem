#include "dlg_returnbook.h"
#include "ui_dlg_returnbook.h"

Dlg_ReturnBook::Dlg_ReturnBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_ReturnBook)
{
    ui->setupUi(this);
    QString condition = QString("WHERE record.userid = %1 AND record.returnTime IS NULL").arg(SqlManager::getInstance()->getUserid());
    QVector<QStringList> vec = SqlManager::getInstance()->getBorrowingBooks(condition);
    for(auto str : vec)
    {
        ui->cb->addItem(str[0]);
    }
}

Dlg_ReturnBook::~Dlg_ReturnBook()
{
    delete ui;
}

void Dlg_ReturnBook::on_btn_confirm_clicked()
{
    QString condition = QString("WHERE title = '%1'").arg(ui->cb->currentText());

    //获取图书id
    QString bookId = SqlManager::getInstance()->getBooks(condition)[0][0];

    //归还图书
    bool ret = SqlManager::getInstance()->returnbook(bookId);
    if(ret)
    {
        QMessageBox::information(this,"归还成功", "    归还成功！    ");
        setResult(1);
        hide();
    }
    else
    {
        QMessageBox::warning(this, "归还失败", "    请联系管理员    ");
        setResult(0);
        hide();
    }
}


void Dlg_ReturnBook::on_btn_cancel_clicked()
{
    setResult(0);
    hide();
}

