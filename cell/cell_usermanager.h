#ifndef CELL_USERMANAGER_H
#define CELL_USERMANAGER_H

#include <QWidget>
#include <QStandardItemModel>
#include <QFileDialog>
#include <lib/sqlmanager.h>
#include "dlg_deleteuser.h"

namespace Ui {
class Cell_UserManager;
}

class Cell_UserManager : public QWidget
{
    Q_OBJECT

public:
    explicit Cell_UserManager(QWidget *parent = nullptr);
    ~Cell_UserManager();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void refreshTabel();

private:
    Ui::Cell_UserManager *ui;
    QStandardItemModel m_model;
};

#endif // CELL_USERMANAGER_H
