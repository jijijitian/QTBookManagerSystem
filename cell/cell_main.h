#ifndef CELL_MAIN_H
#define CELL_MAIN_H

#include <QMainWindow>
#include <QPushButton>
#include <qstring.h>
#include "cell_usermanager.h"
#include "cell_bookmanager.h"
#include "cell_borrowingrecord.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Cell_Main; }
QT_END_NAMESPACE

class Cell_Main : public QMainWindow
{
    Q_OBJECT

public:
    Cell_Main(QWidget *parent = nullptr);
    void initPage();
    void dealMenu();
    ~Cell_Main();

private:
    Ui::Cell_Main *ui;
    Cell_UserManager* m_userPage;
    Cell_BookManager* m_bookPage;
    Cell_BorrowingRecord* m_recordPage;
};
#endif // CELL_MAIN_H
