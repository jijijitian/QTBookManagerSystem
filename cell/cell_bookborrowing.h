#ifndef CELL_BOOKBORROWING_H
#define CELL_BOOKBORROWING_H

#include <QWidget>
#include <QStandardItemModel>
#include <lib/sqlmanager.h>
#include "dlg_borrowbook.h"
#include "dlg_returnbook.h"

namespace Ui {
class Cell_BookBorrowing;
}

class Cell_BookBorrowing : public QWidget
{
    Q_OBJECT

public:
    explicit Cell_BookBorrowing(QWidget *parent = nullptr);

    void refreshTable();

    ~Cell_BookBorrowing();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_btn_search_clicked();

private:
    Ui::Cell_BookBorrowing *ui;
    QStandardItemModel m_model;
};

#endif // CELL_BOOKBORROWING_H
