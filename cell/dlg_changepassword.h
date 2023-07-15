#ifndef DLG_CHANGEPASSWORD_H
#define DLG_CHANGEPASSWORD_H

#include <QDialog>
#include <QMessageBox>
#include <lib/sqlmanager.h>

namespace Ui {
class Dlg_ChangePassword;
}

class Dlg_ChangePassword : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_ChangePassword(QWidget *parent = nullptr);
    ~Dlg_ChangePassword();

private slots:
    //登录按钮槽函数
    void on_btn_confirm_clicked();

    //取消按钮槽函数
    void on_btn_cansel_clicked();

private:
    Ui::Dlg_ChangePassword *ui;
};

#endif // DLG_CHANGEPASSWORD_H
