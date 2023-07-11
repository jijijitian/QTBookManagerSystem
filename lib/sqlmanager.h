#ifndef SQLMANAGER_H
#define SQLMANAGER_H

#include <QString>
#include <QSqlDatabase>
#include <QCoreApplication>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QtDebug>
#include <QSqlError>

class SqlManager
{
public:
    SqlManager();

    static SqlManager* instance;

    //单例模式
    static SqlManager* getInstance();

    //初始化
    void init();

    //获取用户id
    QString getUserid();

    //获取用户权限
    QString getAuthority();

    //登录
    bool login(QString userName, QString password);

    //获取用户（条件默认为空）
    QVector<QStringList> getUsers(QString condition="");

    //添加用户
    bool addUsers(QVector<QStringList> students);

    //删除用户
    bool deleteUser(QString userId);

    //获取图书
    QVector<QStringList> getBooks(QString condition="");

    //增加图书
    void addBooks(QVector<QString>);

    //删除图书
    void deleteBook(QString bookId);

    //修改图书
    void changeBook(QString bookId);

    //图书借阅
    QString borrowBook(QString bookId);

    //图书归还
    QString returnbook(QString userId, QString bookId);

    //获取借阅记录
    QVector<QStringList> getRecords(QString condition="");

    //删除借阅记录
    QString clearRecord();

    //获取账户信息
    QStringList getAccount();

    ~SqlManager();
private:
    QSqlDatabase m_db;
    QString id;
    QString authority;
};

#endif // SQLMANAGER_H
