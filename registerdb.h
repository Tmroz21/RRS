#ifndef REGISTERDB_H
#define REGISTERDB_H
#include <QString>
#include <qsqldatabase.h>

class RegisterDb
{
public:
    RegisterDb(const QString& path);

    ~RegisterDb();

    bool isOpen() const;

    bool createTable();

    bool userAdd(const QString& userName, const QString& password);

    bool userExists(const QString& userName) const;

private:
    QSqlDatabase r_db;
};
#endif // REGISTERDB_H
