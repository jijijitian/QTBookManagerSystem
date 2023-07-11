#ifndef CELL_STUDENTMAIN_H
#define CELL_STUDENTMAIN_H

#include <QMainWindow>
#include <QPushButton>
#include <qstring.h>
#include "cell_accountmanager.h"
#include "cell_bookmanager.h"
#include "cell_borrowingrecord.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Cell_StudentMain; }
QT_END_NAMESPACE

class Cell_StudentMain : public QMainWindow
{
    Q_OBJECT

public:
    Cell_StudentMain(QWidget *parent = nullptr);
    void initPage();
    void dealMenu();
    ~Cell_StudentMain();

private:
    Ui::Cell_StudentMain *ui;
    Cell_AccountManager* m_accountPage;
    Cell_BookManager* m_bookPage;
    Cell_BorrowingRecord* m_recordPage;
};
#endif // CELL_STUDENTMAIN_H
