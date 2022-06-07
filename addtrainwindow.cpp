#include "addtrainwindow.h"
#include "qmessagebox.h"
#include "qtablewidget.h"
#include "train.h"
#include "train.cpp"
#include "ui_addtrainwindow.h"
#include <fstream>
#include <iostream>
#include "dbmanager.h"
#include <mainwindow.h>


 QString code;
 QString from;
 QString to;
 int seats;
 QVector<Train> trainList;
 QVector<Train> trainRead;
 static const QString path = "trains.db";


AddTrainWindow::AddTrainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddTrainWindow)
{
    ui->setupUi(this);
}

AddTrainWindow::~AddTrainWindow()
{
    delete ui;
}

void AddTrainWindow::on_lineEdit_From_textChanged(const QString &arg1)
{
    from = arg1;
}


void AddTrainWindow::on_lineEdit_To_textChanged(const QString &arg1)
{
    to = arg1;
}


void AddTrainWindow::on_lineEdit_Code_textChanged(const QString &arg1)
{
    code = arg1;
}


void AddTrainWindow::on_spinBox_Seats_valueChanged(int arg1)
{
    seats = arg1;
}


void AddTrainWindow::on_pushButton_Add_clicked()
{   
    QMessageBox msgBox;
    QString info;
    DbManager db(path);

    if(db.personExists(code) == 0)
    {
        if (db.isOpen())
        {
            info = "Train successfully added";
            db.createTable();
            db.addPerson(code,from,to);
            db.printAllPersons();
        }
        else
        {
            qDebug() << "Database is not open!";
            info = "App can not connect to database.";
        }
        MainWindow window;
        //window.AddTrainToScroll(code,from,to);
        qDebug("Items in list: %lld", trainList.size());
        ui->tableWidget_Trains->insertRow(ui->tableWidget_Trains->rowCount());
        QTableWidgetItem *newTrainCode = new QTableWidgetItem(code);
        QTableWidgetItem *newTrainFrom = new QTableWidgetItem(from);
        QTableWidgetItem *newTrainTo = new QTableWidgetItem(to);
        QTableWidgetItem *newTrainAVS = new QTableWidgetItem(QString::number(seats));
        ui->tableWidget_Trains->setItem(ui->tableWidget_Trains->rowCount()-1,0,newTrainCode);
        ui->tableWidget_Trains->setItem(ui->tableWidget_Trains->rowCount()-1,1,newTrainTo);
        ui->tableWidget_Trains->setItem(ui->tableWidget_Trains->rowCount()-1,2,newTrainFrom);
        ui->tableWidget_Trains->setItem(ui->tableWidget_Trains->rowCount()-1,3,newTrainAVS);
        }
        else
        {
            info = "Train with this code already exist.";
        }
        msgBox.setText(info);
        msgBox.exec();
}

