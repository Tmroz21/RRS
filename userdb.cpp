#include "userdb.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

userdb::userdb(const QString& path)
{
    r_db = QSqlDatabase::addDatabase("QSQLITE");
    r_db.setDatabaseName(path);

    if (!r_db.open())
    {
        qDebug() << "Error: connection with database failed";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

userdb::~userdb(){
    if (r_db.isOpen())
    {
        r_db.close();
    }
}

bool userdb::createTable()
{
    bool success = false;

    QSqlQuery query;
    query.prepare("CREATE TABLE userticket(id INTEGER PRIMARY KEY, username TEXT, code TEXT, tickets INT(255));");

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'registration': one might already exist.";
        success = false;
    }

    return success;
}

bool userdb::userAdd(const QString& username, const QString& code, int tickets)
{
    bool success = false;

    if (!code.isEmpty())
    {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO userticket (username, code, tickets) VALUES (:username, :code, :tickets)");
        queryAdd.bindValue(":username", username);
        queryAdd.bindValue(":code", code);
        queryAdd.bindValue(":tickets", tickets);

        if(queryAdd.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "add ticket failed: " << queryAdd.lastError();
        }
    }
    else
    {
        qDebug() << "add train failed: name cannot be empty";
    }

    return success;
}

int userdb::countUsersRecords(QString username){

    QSqlQuery query("SELECT COUNT(*) as cntt FROM userticket WHERE username = (:username)");
    query.bindValue(":username",username);
    qDebug() << "count error: " << query.lastError();
    if (query.next())
    {
        return query.value(0).toInt();
    }
    return 0;
}

