#ifndef CELL_STUDENTBORROWING_H
#define CELL_STUDENTBORROWING_H

#include <QWidget>
#include <QStandardItemModel>
#include <lib/sqlmanager.h>

namespace Ui {
class Cell_StudentBorrowing;
}

class Cell_StudentBorrowing : public QWidget
{
    Q_OBJECT

public:
    explicit Cell_StudentBorrowing(QWidget *parent = nullptr);
    ~Cell_StudentBorrowing();

private:
    Ui::Cell_StudentBorrowing *ui;
    QStandardItemModel m_model;
};

#endif // CELL_STUDENTBORROWING_H
