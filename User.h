#ifndef USER_H
#define USER_H

#include <QString>

void setStringUserid(QString user);

QString getUserID();

void pushToMyTicketsV(QString string);

void clearMyTicketsV();

std::vector<QString> returnMyTicketsV();

#endif // USER_H

