#include "cell_main.h"
#include "ui_cell_main.h"

Cell_Main::Cell_Main(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Cell_Main)
    ,m_userPage(nullptr)
    ,m_bookPage(nullptr)
    ,m_recordPage(nullptr)
{
    ui->setupUi(this);
    initPage();
}

void Cell_Main::initPage()
{
    m_userPage = new Cell_UserManager(this);
    m_bookPage = new Cell_BookManager(this);
    m_recordPage = new Cell_BorrowingRecord(this);
    ui->stackedWidget->addWidget(m_userPage);
    ui->stackedWidget->addWidget(m_bookPage);
    ui->stackedWidget->addWidget(m_recordPage);
    ui->stackedWidget->setCurrentIndex(0);

    auto l = ui->tool->children();
    for(auto it : l)
    {
        if(it->objectName().contains("btn"))
        {
            connect(static_cast<QPushButton*>(it), &QPushButton::clicked,this,&Cell_Main::dealMenu);
        }
    }
}

void Cell_Main::dealMenu()
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

Cell_Main::~Cell_Main()
{
    delete ui;
}

