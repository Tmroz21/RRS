#ifndef USERDB_H
#define USERDB_H
#include <QString>
#include <qsqldatabase.h>


class userdb
{
public:
    userdb(const QString& path);

    ~userdb();

    bool isOpen() const;

    bool createTable();

    bool userAdd(const QString& userName, const QString& code, int tickets);

    bool userExists(const QString& username) const;

    void countUsersRecords(QString username);
private:
    QSqlDatabase r_db;
};

#endif // USERDB_H
