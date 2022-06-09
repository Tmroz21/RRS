#include "mytickets.h"
#include <QBoxLayout>
#include <QPushButton>
#include "ui_mytickets.h"
#include "userdb.h"
#include "user.h"

static const QString path = "database.db";

userdb udb(path);
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

void MyTickets::drawScrollSArea( QVBoxLayout * lay){
   // ui->scrollAreaWidgetContents->layout()->removeItem(lay);
    udb.countUsersRecords(getUserID());
    std::vector<QString> ticks = returnMyTicketsV();
    for(int i=0;i < ticks.size();i++)
    {
        QPushButton *button = new QPushButton(ticks[i]);
        qDebug() << ticks[i];
        lay->addWidget(button);
    }
    ui->scrollAreaWidgetContents->setLayout(lay);
}

void MyTickets::on_pushButton_clicked()
{
    QVBoxLayout *lay = new QVBoxLayout(this);
    drawScrollSArea(lay);

}

