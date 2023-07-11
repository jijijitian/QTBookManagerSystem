#include "cell_main.h"
#include "cell_studentmain.h"

#include <QApplication>
#include <QtDebug>

#include "dlg_login.h"
#include "lib/sqlmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SqlManager::getInstance()->init();

    Dlg_Login dlg;

    int ret = dlg.exec();

    if(ret == 1)
    {
        if(SqlManager::getInstance()->getAuthority() == "administrator")
        {
            Cell_Main w;
            w.show();
            return a.exec();
        }
        else if(SqlManager::getInstance()->getAuthority() == "student")
        {
            Cell_StudentMain w;
            w.show();
            return a.exec();
        }
    }
    else if(ret == 0)
    {
        exit(0);
        return 0;
    }
    return 0;
}
