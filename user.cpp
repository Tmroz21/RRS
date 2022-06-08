#include <QString>

static QString userID;

void setStringUserid(QString user){
    userID = user;
}
QString getUserID(){
    return userID;
}
