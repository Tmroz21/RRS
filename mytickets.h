#ifndef MYTICKETS_H
#define MYTICKETS_H

#include "qboxlayout.h"
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

    void drawScrollSArea(QVBoxLayout *lay);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MyTickets *ui;
};

#endif // MYTICKETS_H
