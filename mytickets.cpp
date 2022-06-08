#include "mytickets.h"
#include "qboxlayout.h"
#include "qpushbutton.h"
#include "ui_mytickets.h"
#include "userdb.h"

static const QString path = "database.db";

MyTickets::MyTickets(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyTickets)
{
    ui->setupUi(this);
}

MyTickets::~MyTickets()
{
    delete ui;
}

void MyTickets::drawScrollSArea(){
    //QVBoxLayout * lay = new QVBoxLayout(this);
    //userdb udb(path);
    //QPushButton *button = new QPushButton(udb.);

}
