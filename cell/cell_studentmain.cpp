#include "cell_studentmain.h"
#include "ui_cell_studentmain.h"

Cell_StudentMain::Cell_StudentMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Cell_StudentMain)
    ,m_accountPage(nullptr)
    ,m_bookPage(nullptr)
    ,m_recordPage(nullptr)
{
    ui->setupUi(this);
    initPage();
}

void Cell_StudentMain::initPage()
{
    m_accountPage = new Cell_AccountManager(this);
    m_bookPage = new Cell_BookBorrowing(this);
    m_recordPage = new Cell_StudentBorrowing(this);
    ui->stackedWidget->addWidget(m_accountPage);
    ui->stackedWidget->addWidget(m_bookPage);
    ui->stackedWidget->addWidget(m_recordPage);
    ui->stackedWidget->setCurrentIndex(0);

    auto l = ui->tool->children();
    for(auto it : l)
    {
        if(it->objectName().contains("btn"))
        {
            connect(static_cast<QPushButton*>(it), &QPushButton::clicked,this,&Cell_StudentMain::dealMenu);
        }
    }
}

void Cell_StudentMain::dealMenu()
{
    QString str = sender()->objectName();
    do
    {
        if(str == "btn_user")
        {
            ui->stackedWidget->setCurrentIndex(0);
            break;
        }
        else if(str == "btn_book")
        {
            ui->stackedWidget->setCurrentIndex(1);
            break;
        }
        else if(str == "btn_record")
        {
            ui->stackedWidget->setCurrentIndex(2);
            break;
        }
    }while(false);
}

Cell_StudentMain::~Cell_StudentMain()
{
    delete ui;
}

