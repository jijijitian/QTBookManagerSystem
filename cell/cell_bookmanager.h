#ifndef CELL_BOOKMANAGER_H
#define CELL_BOOKMANAGER_H

#include <QWidget>
#include <QStandardItemModel>
#include <lib/sqlmanager.h>
#include "dlg_addbook.h"
#include "dlg_changebook.h"
#include "dlg_deletebook.h"

namespace Ui {
class Cell_BookManager;
}

class Cell_BookManager : public QWidget
{
    Q_OBJECT

public:
    explicit Cell_BookManager(QWidget *parent = nullptr);

    void refreshTable();

    ~Cell_BookManager();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Cell_BookManager *ui;
    QStandardItemModel m_model;
};

#endif // CELL_BOOKMANAGER_H
