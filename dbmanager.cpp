#include <dbmanager.h>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
int  count;
DbManager::DbManager(const QString& path)
{
   m_db = QSqlDatabase::addDatabase("QSQLITE");
   m_db.setDatabaseName(path);

   if (!m_db.open())
   {
      qDebug() << "Error: connection with database failed";
   }
   else
   {
      qDebug() << "Database: connection ok";
   }
}

DbManager::~DbManager()
{
    if (m_db.isOpen())
    {
        m_db.close();
    }
}

bool DbManager::isOpen() const
{
    return m_db.isOpen();
}

bool DbManager::createTable()
{
    bool success = false;

    QSqlQuery query;
    query.prepare("CREATE TABLE trains(id INTEGER PRIMARY KEY, code TEXT, from_ TEXT, to_ TEXT);");

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'trains': one might already exist.";
        success = false;
    }

    return success;
}

bool DbManager::addTrain(const QString& code, const QString& from , const QString& to)
{
    bool success = false;

    if (!code.isEmpty())
    {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO trains (code, from_, to_) VALUES (:code, :from_, :to_)");
        queryAdd.bindValue(":code", code);
        queryAdd.bindValue(":from_", from);
        queryAdd.bindValue(":to_", to);

        if(queryAdd.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "add train failed: " << queryAdd.lastError();
        }
    }
    else
    {
        qDebug() << "add train failed: name cannot be empty";
    }

    return success;
}

bool DbManager::removeTrain(const QString& code)
{
    bool success = false;

    if (trainExists(code))
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM trains WHERE code = (:code)");
        queryDelete.bindValue(":code", code);
        success = queryDelete.exec();

        if(!success)
        {
            qDebug() << "remove train failed: " << queryDelete.lastError();
        }
    }
    else
    {
        qDebug() << "remove train failed: train doesnt exist";
    }

    return success;
}

void DbManager::printAllTrains() const
{
    qDebug() << "Persons in db:";
    QSqlQuery query("SELECT * FROM trains");
    int idCode = query.record().indexOf("code");
    int idFrom = query.record().indexOf("from_");
    int idTo = query.record().indexOf("to_");
    int count = 0;
    while (query.next())
    {
        QString code = query.value(idCode).toString();
        QString from = query.value(idFrom).toString();
        QString to = query.value(idTo).toString();
        qDebug() << "===" << code << "==="<< from <<"==="<<to;
        count += 1;
    }
     qDebug() << QString::number(count);
}
void DbManager::printToTable() const
{
    QSqlQuery query("SELECT * FROM trains");
    int idCode = query.record().indexOf("code");
    int idFrom = query.record().indexOf("from_");
    int idTo = query.record().indexOf("to_");
    count = 0;
    while (query.next())
    {
        QString code = query.value(idCode).toString();
        QString from = query.value(idFrom).toString();
        QString to = query.value(idTo).toString();
        QString info =  "===" + code + "===" + from + "===";
        qDebug() << code;
        count += 1;
    }
    qDebug() << QString::number(count);
}
bool DbManager::trainExists(const QString& code) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT code FROM trains WHERE code = (:code)");
    checkQuery.bindValue(":code", code);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "person exists failed: " << checkQuery.lastError();
    }

    return exists;
}

bool DbManager::removeAllTrain()
{
    bool success = false;

    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM trains ");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "remove all trains failed: " << removeQuery.lastError();
    }

    return success;
}

int DbManager::countAllTrain()
{
    QSqlQuery query("SELECT COUNT(*) as cnt FROM trains");
    if (query.next())
    {
        return query.value(0).toInt();
    }
    return 0;
}
