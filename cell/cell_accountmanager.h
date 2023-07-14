#ifndef CELL_ACCOUNTMANAGER_H
#define CELL_ACCOUNTMANAGER_H

#include <QWidget>
#include <QStandardItemModel>
#include <lib/sqlmanager.h>
#include "dlg_changepassword.h"

namespace Ui {
class Cell_AccountManager;
}

class Cell_AccountManager : public QWidget
{
    Q_OBJECT

public:
    explicit Cell_AccountManager(QWidget *parent = nullptr);
    ~Cell_AccountManager();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Cell_AccountManager *ui;
    QStandardItemModel m_model;
};

#endif // CELL_ACCOUNTMANAGER_H
