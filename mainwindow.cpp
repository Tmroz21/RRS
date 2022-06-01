#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "train.h"
#include "train.cpp"

#include <QMessageBox>

 QString code;
 QString from;
 QString to;
 int seats;
 QVector<Train> trainList;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Add_clicked()
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


void MainWindow::on_lineEdit_Code_textChanged(const QString &arg1)
{
    code = arg1;
}


void MainWindow::on_lineEdit_To_textChanged(const QString &arg1)
{
    to = arg1;
}


void MainWindow::on_lineEdit_From_textChanged(const QString &arg1)
{
    from = arg1;
}


void MainWindow::on_spinBox_Seats_valueChanged(int arg1)
{
    seats = arg1;
}


void MainWindow::on_tableWidget_Trains_itemClicked(QTableWidgetItem *item)
{
    int row = item->row();
    qDebug("Item row: %d", row);
}

