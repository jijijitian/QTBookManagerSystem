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

QString SqlManager::getUserid()
{
    return id;
}

QString SqlManager::getAuthority()
{
    return authority;
}

bool SqlManager::login(QString userName, QString password)
{
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM user WHERE userName = :username AND password = :password");
    query.bindValue(":username", userName);
    query.bindValue(":password", password);

    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        id = query.value(0).toString();
        authority = query.value(4).toString();
        return count > 0;  // 返回匹配行数是否大于 0，表示登录成功与否
    }

    return false;
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

bool SqlManager::addUsers(QVector<QStringList> students)
{
    QSqlQuery q(m_db);

    // 开始一个事务
    m_db.transaction();

    bool success = true;

    // 添加学生
    for(auto strList : students)
    {
        QString strSql = QString("INSERT into user VALUES(NULL, '%1', '%2', '%3', '%4', '%5', '%6', '%7')")
                             .arg(strList[1]).arg(strList[2]).arg(strList[3]).arg(strList[4]).arg(strList[5]).arg(strList[6]).arg(strList[7]);
        if (!q.exec(strSql)) {
            qDebug() << q.lastError().text();
            success = false;
            break;
        }
    }

    // 如果所有插入操作都成功，我们就提交事务，否则我们就回滚事务
    if (success) {
        m_db.commit();
    } else {
        m_db.rollback();
    }

    return success;
}

bool SqlManager::deleteUser(QString userId)
{

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

QString SqlManager::borrowBook(QString bookId)
{

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

QStringList SqlManager::getAccount()
{
    QSqlQuery q(m_db);

    QString strSql =QString("SELECT * FROM user where userid = %1").arg(id);
    QStringList account;
    bool ret = q.exec(strSql);
    if (ret && q.next())
    {
        account << q.value(1).toString();
        account << q.value(3).toString();
        account << q.value(5).toString();
        account << q.value(6).toString();
        account << q.value(7).toString();
    }
    else
    {
        qDebug() << q.lastError().text();
    }
    return account;
}

SqlManager::~SqlManager()
{

}
