#include "sqlmanager.h"

SqlManager::SqlManager()
{

}

SqlManager* SqlManager::instance = nullptr;

SqlManager* SqlManager::getInstance()
{
    if(instance == nullptr)
    {
        instance = new SqlManager();
    }
    return instance;
}

void SqlManager::init()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(QCoreApplication::applicationDirPath()+"/db/bookManager.db");
    m_db.open();
}

bool SqlManager::login(QString userName, QString password)
{
    QSqlQuery q(m_db);
    QString strSql = QString("select * from user where userName = %1 and password = %2").arg(userName).arg(password);
    bool ret = q.exec(strSql);
    return ret;
}

QVector<QStringList> SqlManager::getUsers(QString condition)
{
    QSqlQuery q(m_db);

    //获取用户列表（查询条件默认为空）
    QString strSql = QString("select * from user %1").arg(condition);
    bool ret = q.exec(strSql);
    QVector<QStringList> vec;

    if(ret)
    {
        int iCol = q.record().count();
        QStringList l;
        while(q.next())
        {
            l.clear();
            for(int i = 0; i < iCol; i++)
            {
                //默认不获取用户id与密码
                if(i != 0 && i != 2)
                {
                    l << q.value(i).toString();
                }
            }
            vec.push_back(l);
        }
    }
    else
    {
        //若打开失败，输出错误提示
        qDebug() << q.lastError().text();
    }
    return vec;
}

QVector<QStringList> SqlManager::getBooks(QString condition)
{
    QSqlQuery q(m_db);

    //获取书籍列表（查询条件默认为空）
    QString strSql = QString("select * from book %1").arg(condition);
    bool ret = q.exec(strSql);
    QVector<QStringList> vec;

    if(ret)
    {
        int iCol = q.record().count();
        QStringList l;
        while(q.next())
        {
            l.clear();
            for(int i = 0; i < iCol; i++)
            {
                if(i != 0)
                {
                    l << q.value(i).toString();
                }
            }
            vec.push_back(l);
        }
    }
    else
    {
        //若打开失败，输出错误提示
        qDebug() << q.lastError().text();
    }
    return vec;
}

QVector<QStringList> SqlManager::getRecords(QString condition)
{
    QSqlQuery q(m_db);

    //获取借阅列表（查询条件默认为空）
    QString strSql = QString("select * from record %1").arg(condition);
    bool ret = q.exec(strSql);
    QVector<QStringList> vec;

    if(ret)
    {
        int iCol = q.record().count();
        QStringList l;
        while(q.next())
        {
            l.clear();
            for(int i = 0; i < iCol; i++)
            {
                if(i != 0)
                {
                    l << q.value(i).toString();
                }
            }
            vec.push_back(l);
        }
    }
    else
    {
        //若打开失败，输出错误提示
        qDebug() << q.lastError().text();
    }
    return vec;
}

SqlManager::~SqlManager()
{

}
