#ifndef MYTICKETS_H
#define MYTICKETS_H

#include <QWidget>

namespace Ui {
class MyTickets;
}

class MyTickets : public QWidget
{
    Q_OBJECT

public:
    explicit MyTickets(QWidget *parent = nullptr);
    ~MyTickets();

    void drawScrollSArea();

private:
    Ui::MyTickets *ui;
};

#endif // MYTICKETS_H
