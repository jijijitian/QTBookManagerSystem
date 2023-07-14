#ifndef DLG_DELETEBOOK_H
#define DLG_DELETEBOOK_H

#include <QDialog>
#include <QMessageBox>
#include <lib/sqlmanager.h>

namespace Ui {
class Dlg_DeleteBook;
}

class Dlg_DeleteBook : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_DeleteBook(QWidget *parent = nullptr);
    ~Dlg_DeleteBook();

private slots:
    void on_btn_confirm_clicked();

    void on_btn_cancel_clicked();

private:
    Ui::Dlg_DeleteBook *ui;
};

#endif // DLG_DELETEBOOK_H
