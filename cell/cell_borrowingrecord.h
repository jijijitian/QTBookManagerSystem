#ifndef CELL_BORROWINGRECORD_H
#define CELL_BORROWINGRECORD_H

#include <QWidget>

namespace Ui {
class Cell_BorrowingRecord;
}

class Cell_BorrowingRecord : public QWidget
{
    Q_OBJECT

public:
    explicit Cell_BorrowingRecord(QWidget *parent = nullptr);
    ~Cell_BorrowingRecord();

private:
    Ui::Cell_BorrowingRecord *ui;
};

#endif // CELL_BORROWINGRECORD_H