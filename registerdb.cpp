#include "registerdb.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

RegisterDb::RegisterDb(const QString& path)
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

RegisterDb::~RegisterDb()
    {
        if (r_db.isOpen())
        {
            r_db.close();
        }
    }
bool RegisterDb::isOpen() const
    {
        return r_db.isOpen();
    }

bool RegisterDb::createTable()
    {
        bool success = false;

        QSqlQuery query;
        query.prepare("CREATE TABLE users(id INTEGER PRIMARY KEY, username TEXT, password TEXT);");

        if (!query.exec())
        {
            qDebug() << "Couldn't create the table 'registration': one might already exist.";
            success = false;
        }

        return success;
    }
bool RegisterDb::userAdd(const QString& username, const QString& password)
    {
        bool success = false;

        if (!username.isEmpty())
        {
            QSqlQuery queryAdd;
            queryAdd.prepare("INSERT INTO users (username, password) VALUES (:username, :password)");
            queryAdd.bindValue(":username", username);
            queryAdd.bindValue(":password", password);

            if(queryAdd.exec())
            {
                success = true;
            }
            else
            {
                qDebug() << "add User failed: " << queryAdd.lastError();
            }
        }
        else
        {
            qDebug() << "add User failed: name cannot be empty";
        }

        return success;
}
bool RegisterDb::userExists(const QString& username) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT username FROM users WHERE username = (:username)");
    checkQuery.bindValue(":username", username);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
            qDebug() << "User exists";
        }
    }
    else
    {
        qDebug() << "User exists failed: " << checkQuery.lastError();
    }

    return exists;
}

QString RegisterDb::userPassword(QString username)
{
    QSqlQuery queryPrint;
    queryPrint.prepare("SELECT password FROM users WHERE username = (:username)");
    queryPrint.bindValue(":username", username);
    if(queryPrint.exec())
    {
        while (queryPrint.next())
        {
            return queryPrint.value(0).toString();
        }
    }
    else
    {
        qDebug() << queryPrint.lastError();
    }
    return 0;
}
