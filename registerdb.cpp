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
        query.prepare("CREATE TABLE registration(id INTEGER PRIMARY KEY, UserName TEXT, Password TEXT);");

        if (!query.exec())
        {
            qDebug() << "Couldn't create the table 'registration': one might already exist.";
            success = false;
        }

        return success;
    }
bool RegisterDb::userAdd(const QString& UserName, const QString& Password)
    {
        bool success = false;

        if (!UserName.isEmpty())
        {
            QSqlQuery queryAdd;
            queryAdd.prepare("INSERT INTO registration (UserName, Password) VALUES (:UserName, :Password)");
            queryAdd.bindValue(":UserName", UserName);
            queryAdd.bindValue(":UserName", Password);

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
bool RegisterDb::userExists(const QString& userName) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT userName FROM registration WHERE userName = (:userName)");
    checkQuery.bindValue(":userName", userName);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "User exists failed: " << checkQuery.lastError();
    }

    return exists;
}
