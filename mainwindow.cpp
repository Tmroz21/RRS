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
    if(Train(from,to,code,seats)==trainList.last())
    {
         info = "Train with this code already exist.";
    }
    else
    {
         trainList.push_back(Train(from,to,code,seats));
         info = trainList.last().ShowTrainInfo();
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




