#include "addtrainwindow.h"
#include "qmessagebox.h"
#include "train.h"
#include "train.cpp"
#include "ui_addtrainwindow.h"
#include <fstream>
#include <iostream>


 QString code;
 QString from;
 QString to;
 int seats;
 QVector<Train> trainList;
  QVector<Train> trainRead;


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
        bool isTrainInList = 0;
        for(int i=0;i<trainList.size();i++)
        {
            if(Train(from,to,code,seats)==trainList[i])
            {
                 info = "Train with this code already exist.";
                 isTrainInList = 1;
                 break;

            }
        }
        if(isTrainInList == 0)
        {
             trainList.push_back(Train(from,to,code,seats));
             qDebug("Items in list: %lld", trainList.size());
             info = trainList.last().ShowTrainInfo();
             std::ofstream fileObj;
             fileObj.open("Input.txt", std::ios::app);
             Train obj = Train(from,to,code,seats);;
            // obj.SetCode(obj.GetCode());
            // obj.SetTo(obj.GetTo());
            // obj.SetFrom(obj.GetFrom());
            // obj.SetAVS(obj.GetAvSeats());
             fileObj.write((char*)&obj,sizeof(obj));
             fileObj.close();
             Train obj2;
             trainList.push_back(obj2);
             trainList.last().outputTest();

             //ReadFromFile();

             //
             ui->tableWidget_Trains->insertRow(ui->tableWidget_Trains->rowCount());
             QTableWidgetItem *newTrainCode = new QTableWidgetItem(trainList.last().GetCode());
             QTableWidgetItem *newTrainFrom = new QTableWidgetItem(trainList.last().GetFrom());
             QTableWidgetItem *newTrainTo = new QTableWidgetItem(trainList.last().GetTo());
             QTableWidgetItem *newTrainAVS = new QTableWidgetItem(trainList.last().GetSAvSeats());
             ui->tableWidget_Trains->setItem(ui->tableWidget_Trains->rowCount()-1,0,newTrainCode);
             ui->tableWidget_Trains->setItem(ui->tableWidget_Trains->rowCount()-1,1,newTrainTo);
             ui->tableWidget_Trains->setItem(ui->tableWidget_Trains->rowCount()-1,2,newTrainFrom);
             ui->tableWidget_Trains->setItem(ui->tableWidget_Trains->rowCount()-1,3,newTrainAVS);
        }
        msgBox.setText(info);
        msgBox.exec();
}
void AddTrainWindow::ReadFromFile()
{
    std::ifstream file_obj;

    // Opening file in input mode
    file_obj.open("Input.txt", std::ios::in);

    // Object of class contestant to input data in file
    Train obj2;
    //obj.outputTest();
    //std::auto_ptr<Train> obj2(new Train);
    // Reading from file into object "obj"
    file_obj.read((char*)&obj2, sizeof(obj2));
    qDebug("seats: %d",obj2.GetAvSeats());
    qDebug()<<obj2.GetCode()<<"code";
    trainRead.push_back(obj2);
    qDebug()<<trainRead.last().GetCode()<<"code";
    qDebug("Items in list: %lld", trainRead.size());
    file_obj.close();
}

