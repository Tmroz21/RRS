#ifndef TRAIN_H
#define TRAIN_H


#include <qstring.h>
#include <string>
class Train
{
private:
    QString fFrom;
    QString fTo;
    QString fCode;
    int fAvSeats;
    QString fSAvSeats = QString::number(fAvSeats);

public:
    Train();
    Train(QString from,QString to,QString code,int avSeats):fFrom(from),fTo(to),fCode(code),fAvSeats(avSeats){};

    QString ShowTrainInfo(){
        return "Code: "+ fCode+" From: "+fFrom+" To "+fTo;
    }
    QString GetCode(void) const  {return fCode;}
    QString GetTo(void) const  {return fTo;}
    QString GetFrom(void) const  {return fFrom;}
    QString GetSAvSeats(void) const  {return fSAvSeats;}
    int GetAvSeats(void) const {return fAvSeats;}

};

bool operator== (const Train& lhs,const Train& rhs)
{
    return lhs.GetCode() == rhs.GetCode();
}

#endif // TRAIN_H
