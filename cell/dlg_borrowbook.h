#ifndef DLG_BORROWBOOK_H
#define DLG_BORROWBOOK_H

#include <QDialog>
#include <QMessageBox>
#include <lib/sqlmanager.h>


namespace Ui {
class Dlg_BorrowBook;
}

class Dlg_BorrowBook : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_BorrowBook(QWidget *parent = nullptr);
    ~Dlg_BorrowBook();

private slots:

    //确认键槽函数
    void on_btn_confirm_clicked();

    //取消键槽函数
    void on_btn_cancel_clicked();

private:
    Ui::Dlg_BorrowBook *ui;
};

#endif // DLG_BORROWBOOK_H
