#include <QString>
#include <vector>

static QString userID;

static std::vector<QString> myTicketsV;

void setStringUserid(QString user){
    userID = user;
}
QString getUserID(){
    return userID;
}

void clearMyTicketsV()
{
    myTicketsV.clear();
}

void pushToMyTicketsV(QString string)
{

    myTicketsV.push_back(string);
}

std::vector<QString> returnMyTicketsV()
{
    return myTicketsV;
}

