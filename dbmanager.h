#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QString>
#include <qsqldatabase.h>

class DbManager
{
public:

    DbManager(const QString& path);

    ~DbManager();

    bool isOpen() const;

    bool createTable();

    bool addTrain(const QString& name, const QString& code, const QString &to);

    bool removeTrain(const QString& name);

    bool trainExists(const QString& name) const;

    void printAllTrains() const;

    QString printToTable();

    bool removeAllTrain();

    int countAllTrains();
private:
    QSqlDatabase m_db;

};

#endif // DBMANAGER_H
