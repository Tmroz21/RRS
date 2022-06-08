#include <dbmanager.h>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

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
    query.prepare("CREATE TABLE trains(id INTEGER PRIMARY KEY, code TEXT, from_ TEXT, to_ TEXT, seats INT(255));");

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'trains': one might already exist.";
        success = false;
    }

    return success;
}

bool DbManager::addTrain(const QString& code, const QString& from , const QString& to, int seats)
{
    bool success = false;

    if (!code.isEmpty())
    {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO trains (code, from_, to_, seats) VALUES (:code, :from_, :to_, :seats)");
        queryAdd.bindValue(":code", code);
        queryAdd.bindValue(":from_", from);
        queryAdd.bindValue(":to_", to);
        queryAdd.bindValue(":seats", seats);

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
    qDebug() << idCode;
    int idFrom = query.record().indexOf("from_");
    qDebug() << idCode;
    int idTo = query.record().indexOf("to_");
    qDebug() << idCode;
    while (query.next())
    {
        QString code = query.value(idCode).toString();
        qDebug() << QString::number(idCode)+" code ID";
        QString from = query.value(idFrom).toString();
        qDebug() << QString::number(idCode)+" from ID";
        QString to = query.value(idTo).toString();
        qDebug() << QString::number(idCode)+" to ID";
        qDebug() << "===" << code << "==="<< from <<"==="<<to;
    }
}

QString DbManager::printCodeToTableByID(int id)
{
    QSqlQuery queryPrint;
    queryPrint.prepare("SELECT code FROM trains WHERE id = (:id)");
    queryPrint.bindValue(":id",id);
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

QString DbManager::printFromToTableByID(int id)
{
    QSqlQuery queryPrint;
    queryPrint.prepare("SELECT from_ FROM trains WHERE id = (:id)");
    queryPrint.bindValue(":id",id);
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

QString DbManager::printToToTableByID(int id)
{
    QSqlQuery queryPrint;
    queryPrint.prepare("SELECT to_ FROM trains WHERE id = (:id)");
    queryPrint.bindValue(":id",id);
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

int DbManager::printSeatsToTableByID(int id)
{
    QSqlQuery queryPrint;
    queryPrint.prepare("SELECT seats FROM trains WHERE id = (:id)");
    queryPrint.bindValue(":id",id);
    if(queryPrint.exec())
    {
        while (queryPrint.next())
        {
            return queryPrint.value(0).toInt();
        }
    }
    else
    {
        qDebug() << queryPrint.lastError();
    }
    return 0;
}

int DbManager::printIDByCode(QString code)
{
    QSqlQuery queryPrint;
    queryPrint.prepare("SELECT id FROM trains WHERE code = (:code)");
    queryPrint.bindValue(":code",code);
    if(queryPrint.exec())
    {
        while (queryPrint.next())
        {
            return queryPrint.value(0).toInt();
        }
    }
    else
    {
        qDebug() << queryPrint.lastError();
    }
    return 0;
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

int DbManager::countAllTrains()
{
    QSqlQuery query("SELECT COUNT(*) as cnt FROM trains");
    if (query.next())
    {
        return query.value(0).toInt();
    }
    return 0;
}

void DbManager::updateSeatsNumber(int id,int seats)
{
    QSqlQuery query;
    query.prepare("UPDATE trains SET seats = :seats WHERE id = (:id)");
    query.bindValue(":id",id);
    query.bindValue(":seats",seats);
    if (query.exec())
    {
        qDebug() << "updated";
    }
    else
    {
        qDebug() << "remove all trains failed: " << query.lastError();
    }
}
