#ifndef DLG_CHANGEBOOK_H
#define DLG_CHANGEBOOK_H

#include <QDialog>
#include <QMessageBox>
#include <lib/sqlmanager.h>

namespace Ui {
class Dlg_ChangeBook;
}

class Dlg_ChangeBook : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_ChangeBook(QWidget *parent = nullptr);
    ~Dlg_ChangeBook();

private slots:
    void on_btn_confirm_clicked();

    void on_btn_cansel_clicked();

private:
    Ui::Dlg_ChangeBook *ui;
};

#endif // DLG_CHANGEBOOK_H
