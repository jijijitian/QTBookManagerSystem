#ifndef CELL_BOOKMANAGER_H
#define CELL_BOOKMANAGER_H

#include <QWidget>
#include <QStandardItemModel>
#include <sqlmanager.h>

namespace Ui {
class Cell_BookManager;
}

class Cell_BookManager : public QWidget
{
    Q_OBJECT

public:
    explicit Cell_BookManager(QWidget *parent = nullptr);
    ~Cell_BookManager();

private:
    Ui::Cell_BookManager *ui;
    QStandardItemModel m_model;
};

#endif // CELL_BOOKMANAGER_H
