#include "mainwindow.h"
#include "addtrainwindow.h"
#include "dbmanager.h"
#include "mytickets.h"
#include "ui_mainwindow.h"
#include "User.h"
#include "userdb.h"

#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>

QVBoxLayout * lay = new QVBoxLayout();
static const QString path = "database.db";
DbManager db(path);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(int i=1;i<=db.countAllTrains();i++){
        AddTrainToScroll(i);
    }
    ui->groupBox->hide();

}

void MainWindow::AddTrainToScroll(int id)
{
            ui->tableWidget_Trains->insertRow(ui->tableWidget_Trains->rowCount());
            QTableWidgetItem *newTrainCode  = new QTableWidgetItem(db.printCodeToTableByID(id));
            QTableWidgetItem *newTrainFrom = new QTableWidgetItem(db.printFromToTableByID(id));
            QTableWidgetItem *newTrainTo = new QTableWidgetItem(db.printToToTableByID(id));
            QTableWidgetItem *newTrainAVS = new QTableWidgetItem(QString::number(db.printSeatsToTableByID(id)));
            ui->tableWidget_Trains->setItem(ui->tableWidget_Trains->rowCount()-1,0,newTrainCode);
            ui->tableWidget_Trains->setItem(ui->tableWidget_Trains->rowCount()-1,1,newTrainTo);
            ui->tableWidget_Trains->setItem(ui->tableWidget_Trains->rowCount()-1,2,newTrainFrom);
            ui->tableWidget_Trains->setItem(ui->tableWidget_Trains->rowCount()-1,3,newTrainAVS);
            ui->tableWidget_Trains->setColumnWidth(0, 30);
            ui->tableWidget_Trains->setColumnWidth(1, 120);
            ui->tableWidget_Trains->setColumnWidth(2, 120);
            ui->tableWidget_Trains->setColumnWidth(3, 55);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionDodaj_poloczenie_triggered()
{
    addTrainW->show();
}


void MainWindow::on_actionTworcy_triggered()
{
     QMessageBox::information(this, "Twórcy", "Twórcy: Tomasz Mróz, Jakub Domagała");
}


void MainWindow::on_actionUsu_triggered()
{
    db.removeAllTrain();
}


void MainWindow::on_pushButton_clicked()
{
    updateTable();
}


void MainWindow::on_tableWidget_Trains_cellClicked(int row, int column)
{
    DbManager db(path);
    ui->groupBox->show();
    ui->label_line->setText(db.printCodeToTableByID(row+1));
    ui->label_from->setText(db.printFromToTableByID(row+1));
    ui->label_to->setText(db.printToToTableByID(row+1));
    ui->label_seats->setText(QString::number(db.printSeatsToTableByID(row+1)));

}


void MainWindow::on_pushButton_reservation_clicked()
{
    DbManager db(path);
    userdb udb(path);
    udb.createTable();
    int trainID = db.printIDByCode(ui->label_line->text());
    qDebug() << trainID;
    int numberOfSeats = ui->spinBox_seats->value();
    int avalibleSeats = db.printSeatsToTableByID(trainID);
    if(numberOfSeats<avalibleSeats)
    {
        db.updateSeatsNumber(trainID,avalibleSeats-numberOfSeats);

        udb.userAdd(getUserID(),ui->label_line->text(),numberOfSeats);
        qDebug()<< getUserID()<< ui->label_line->text()<<numberOfSeats<<QString::number(udb.countUsersRecords(getUserID()));
        updateTable();


    }
}


void MainWindow::updateTable()
{
    DbManager db(path);
    for(int i=ui->tableWidget_Trains->rowCount()-1;i>=0;i--){
        ui->tableWidget_Trains->removeRow(i);
    }
    for(int i=1;i<=db.countAllTrains();i++){
        AddTrainToScroll(i);
    }
}


void MainWindow::on_actionMoje_Bilety_triggered()
{
    MyTickets m;
    m.show();
}

