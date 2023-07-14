#ifndef DLG_RETURNBOOK_H
#define DLG_RETURNBOOK_H

#include <QDialog>
#include <QMessageBox>
#include <lib/sqlmanager.h>

namespace Ui {
class Dlg_ReturnBook;
}

class Dlg_ReturnBook : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_ReturnBook(QWidget *parent = nullptr);
    ~Dlg_ReturnBook();

private slots:
    void on_btn_confirm_clicked();

    void on_btn_cancel_clicked();

private:
    Ui::Dlg_ReturnBook *ui;
};

#endif // DLG_RETURNBOOK_H
