#ifndef CELL_USERMANAGER_H
#define CELL_USERMANAGER_H

#include <QWidget>
#include <QStandardItemModel>
#include "sqlmanager.h"

namespace Ui {
class Cell_UserManager;
}

class Cell_UserManager : public QWidget
{
    Q_OBJECT

public:
    explicit Cell_UserManager(QWidget *parent = nullptr);
    ~Cell_UserManager();

private:
    Ui::Cell_UserManager *ui;
    QStandardItemModel m_model;
};

#endif // CELL_USERMANAGER_H
