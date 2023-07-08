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
}

Cell_Main::~Cell_Main()
{
    delete ui;
}

