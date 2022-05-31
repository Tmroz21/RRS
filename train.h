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

public:
    Train();
    Train(QString from,QString to,QString code,int avSeats):fFrom(from),fTo(to),fCode(code),fAvSeats(avSeats){};

    QString ShowTrainInfo(){
        return "Code: "+ fCode+" From: "+fFrom+" To "+fTo;
    }
};

#endif // TRAIN_H
