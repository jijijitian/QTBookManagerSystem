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
                if(i != 2)
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

bool SqlManager::changePassword(QString userId, QString password)
{
    QSqlQuery q(m_db);

    // 开始一个事务
    m_db.transaction();

    // 更新用户密码
    QString strSql = QString("UPDATE user SET password = '%1' WHERE id = '%2'")
                         .arg(password).arg(userId);

    if (!q.exec(strSql)) {
        qDebug() << q.lastError().text();
        m_db.rollback();
        return false;
    }

    // 如果没有任何行受到影响，说明用户id不存在，回滚事务并返回false
    if (q.numRowsAffected() <= 0) {
        m_db.rollback();
        return false;
    }

    // 如果所有操作都成功，我们就提交事务
    m_db.commit();

    return true;
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
    QSqlQuery q(m_db);

    // 开始一个事务
    m_db.transaction();

    // 删除用户
    QString strSql = QString("DELETE FROM user WHERE id = '%1'").arg(userId);
    bool success = q.exec(strSql);
    if (!success) {
        qDebug() << q.lastError().text();
    }

    // 如果删除操作成功，我们就提交事务，否则我们就回滚事务
    if (success) {
        m_db.commit();
    } else {
        m_db.rollback();
    }

    return success;
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
                l << q.value(i).toString();
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

bool SqlManager::addBooks(QStringList book)
{
    QSqlQuery q(m_db);

    // 开始一个事务
    m_db.transaction();

    bool success = true;

    // 添加书籍
    QString strSql = QString("INSERT INTO book VALUES(NULL, '%1', '%2', '%3', '%4', '%5', '%6', '%7')")
                         .arg(book[0]).arg(book[1]).arg(book[2]).arg(book[3]).arg(book[4]).arg(book[5]).arg(book[6]);
    if (!q.exec(strSql)) {
        qDebug() << q.lastError().text();
        success = false;
    }

    // 如果所有插入操作都成功，我们就提交事务，否则我们就回滚事务
    if (success) {
        m_db.commit();
    } else {
        m_db.rollback();
    }

    return success;
}

bool SqlManager::deleteBook(QString bookId)
{
    QSqlQuery q(m_db);

    // 开始一个事务
    m_db.transaction();

    // 删除用户
    QString strSql = QString("DELETE FROM book WHERE id = '%1'").arg(bookId);
    bool success = q.exec(strSql);
    if (!success) {
        qDebug() << q.lastError().text();
    }

    // 如果删除操作成功，我们就提交事务，否则我们就回滚事务
    if (success) {
        m_db.commit();
    } else {
        m_db.rollback();
    }

    return success;
}

bool SqlManager::changeBook(QString bookId, QStringList book)
{
    QSqlQuery q(m_db);

    // 开始一个事务
    m_db.transaction();

    QString strSql = QString("UPDATE book SET title = '%1', author = '%2', inventory = '%3', press = '%4', type1 = '%5', type2 = '%6', type3 = '%7',  WHERE id = '%8'")
                         .arg(book[0]).arg(book[1]).arg(book[2]).arg(book[3]).arg(book[4]).arg(book[5]).arg(book[6]).arg(bookId);

    bool success = q.exec(strSql);

    if (!success) {
        qDebug() << q.lastError().text();
    }

    // 如果修改操作成功，我们就提交事务，否则我们就回滚事务
    if (success) {
        m_db.commit();
    } else {
        m_db.rollback();
    }

    return success;
}


bool SqlManager::borrowBook(QString userId, QString bookId)
{
    QSqlQuery q(m_db);

    // 开始一个事务
    m_db.transaction();

    // 检查书籍库存
    QString strCheck = QString("SELECT inventory FROM book WHERE id = '%1'").arg(bookId);
    if (!q.exec(strCheck)) {
        qDebug() << q.lastError().text();
        m_db.rollback();
        return false;
    }

    if (!q.next() || q.value(0).toInt() <= 0) {
        m_db.rollback();
        return false;
    }

    // 获取当前时间
    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

    // 插入借阅记录
    QString strSql = QString("INSERT INTO record(borrowingTime, returnTime, userid, bookid) VALUES('%1', NULL, '%2', '%3')")
                         .arg(currentTime).arg(userId).arg(bookId);
    if (!q.exec(strSql)) {
        qDebug() << q.lastError().text();
        m_db.rollback();
        return false;
    }

    // 更新书籍库存
    QString strUpdate = QString("UPDATE book SET inventory = inventory - 1 WHERE id = '%1'").arg(bookId);
    if (!q.exec(strUpdate)) {
        qDebug() << q.lastError().text();
        m_db.rollback();
        return false;
    }

    // 如果所有操作都成功，我们就提交事务
    m_db.commit();

    return true;
}

bool SqlManager::returnbook(QString userId, QString bookId)
{
    QSqlQuery q(m_db);

    // 开始一个事务
    m_db.transaction();

    // 检查用户是否已借阅该书籍
    QString strCheck = QString("SELECT id FROM record WHERE userid = '%1' AND bookid = '%2' AND returnTime IS NULL")
                           .arg(userId).arg(bookId);
    if (!q.exec(strCheck)) {
        qDebug() << q.lastError().text();
        m_db.rollback();
        return false;
    }

    if (!q.next()) {
        m_db.rollback();
        return false;
    }

    QString borrowId = q.value(0).toString();

    // 获取当前时间
    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

    // 更新借阅记录的返回时间
    QString strSql = QString("UPDATE borrow_table SET returnTime = '%1' WHERE id = '%2'")
                         .arg(currentTime).arg(borrowId);
    if (!q.exec(strSql)) {
        qDebug() << q.lastError().text();
        m_db.rollback();
        return false;
    }

    // 更新书籍库存
    QString strUpdate = QString("UPDATE book SET inventory = inventory + 1 WHERE id = '%1'").arg(bookId);
    if (!q.exec(strUpdate)) {
        qDebug() << q.lastError().text();
        m_db.rollback();
        return false;
    }

    // 如果所有操作都成功，我们就提交事务
    m_db.commit();

    return true;
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
                l << q.value(i).toString();
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

bool SqlManager::clearRecord()
{
    QSqlQuery q(m_db);

    // 开始一个事务
    m_db.transaction();

    // 删除所有已归还的借阅记录
    QString strSql = "DELETE FROM borrow_table WHERE returnTime IS NOT NULL";

    if (!q.exec(strSql)) {
        qDebug() << q.lastError().text();
        m_db.rollback();
        return false;
    }

    // 如果所有操作都成功，我们就提交事务
    m_db.commit();

    return true;
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
