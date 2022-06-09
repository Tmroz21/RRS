#include "userdb.h"
#include "user.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <vector>

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

void userdb::countUsersRecords(QString username){

    QSqlQuery query;
    query.prepare("SELECT code, tickets FROM userticket WHERE username = (:username)");
    query.bindValue(":username",username);
    qDebug() << "count error: " << query.lastError();
    if(query.exec())
    {
        clearMyTicketsV();
        while (query.next())
        {
            QString info = " Linia: " + query.value(0).toString()+ " Bilety: " + query.value(1).toString();
            pushToMyTicketsV(info);
        }
    }
    else
    {
        qDebug() << query.lastError();
    }
}

