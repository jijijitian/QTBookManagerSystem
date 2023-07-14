#ifndef DLG_DELETEUSER_H
#define DLG_DELETEUSER_H

#include <QDialog>
#include <QMessageBox>
#include <lib/sqlmanager.h>

namespace Ui {
class Dlg_DeleteUser;
}

class Dlg_DeleteUser : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_DeleteUser(QWidget *parent = nullptr);
    ~Dlg_DeleteUser();

private slots:
    void on_btn_confirm_clicked();

    void on_btn_cancel_clicked();

private:
    Ui::Dlg_DeleteUser *ui;
};

#endif // DLG_DELETEUSER_H
