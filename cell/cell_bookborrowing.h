#ifndef CELL_BOOKBORROWING_H
#define CELL_BOOKBORROWING_H

#include <QWidget>
#include <QStandardItemModel>
#include <lib/sqlmanager.h>

namespace Ui {
class Cell_BookBorrowing;
}

class Cell_BookBorrowing : public QWidget
{
    Q_OBJECT

public:
    explicit Cell_BookBorrowing(QWidget *parent = nullptr);
    ~Cell_BookBorrowing();

private:
    Ui::Cell_BookBorrowing *ui;
    QStandardItemModel m_model;
};

#endif // CELL_BOOKBORROWING_H
