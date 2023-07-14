#ifndef CELL_BORROWINGRECORD_H
#define CELL_BORROWINGRECORD_H

#include <QWidget>
#include <QStandardItemModel>
#include <lib/sqlmanager.h>
#include "dlg_deleterecord.h"

namespace Ui {
class Cell_BorrowingRecord;
}

class Cell_BorrowingRecord : public QWidget
{
    Q_OBJECT

public:
    explicit Cell_BorrowingRecord(QWidget *parent = nullptr);

    void refreshTabel();

    ~Cell_BorrowingRecord();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Cell_BorrowingRecord *ui;
    QStandardItemModel m_model;
};

#endif // CELL_BORROWINGRECORD_H
