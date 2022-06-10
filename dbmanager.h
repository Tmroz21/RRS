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

    bool addTrain(const QString& code, const QString& from, const QString &to, int seats);

    bool removeTrain(const QString& code);

    bool trainExists(const QString& code) const;

    void printAllTrains() const;

    QString printCodeToTableByID(int id);

    QString printFromToTableByID(int id);

    QString printToToTableByID(int id);

    int printSeatsToTableByID(int id);

    bool removeAllTrain();

    void updateSeatsNumber(int id, int seats);

    int printIDByCode(QString code);

    int countAllTrains();
private:
    QSqlDatabase m_db;

};

#endif // DBMANAGER_H
