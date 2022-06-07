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

    bool addPerson(const QString& name, const QString& code, const QString &to);

    bool removePerson(const QString& name);

    bool personExists(const QString& name) const;

    void printAllPersons() const;

    QString printToTable();

    bool removeAllPersons();
private:
    QSqlDatabase m_db;

};

#endif // DBMANAGER_H
