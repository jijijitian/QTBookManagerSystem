#ifndef DLG_DELETERECORD_H
#define DLG_DELETERECORD_H

#include <QDialog>
#include <QMessageBox>
#include <lib/sqlmanager.h>

namespace Ui {
class Dlg_DeleteRecord;
}

class Dlg_DeleteRecord : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_DeleteRecord(QWidget *parent = nullptr);
    ~Dlg_DeleteRecord();

private slots:
    void on_btn_confirm_clicked();

    void on_btn_cancel_clicked();

private:
    Ui::Dlg_DeleteRecord *ui;
};

#endif // DLG_DELETERECORD_H
