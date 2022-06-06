#ifndef ACTIONSCHEDULER_H
#define ACTIONSCHEDULER_H

    #include "qmainwindow.h"


void OpenTrainAddWindow(QMainWindow window,QMainWindow thisw)
    {
        window.show();
        thisw.hide();
    }

#endif // ACTIONSCHEDULER_H
