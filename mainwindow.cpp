#include "mainwindow.h"
#include "addtrainwindow.h"
#include "ui_mainwindow.h"
//#include "train.h"
//#include "train.cpp"

#include <QMessageBox>

 //QString code;
// QString from;
// QString to;
// int seats;
// QVector<Train> trainList;

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


void MainWindow::on_actionDodaj_poloczenie_triggered()
{
    addTrainW->show();
}


void MainWindow::on_actionTworcy_triggered()
{
    QMessageBox msgBoxTworcy;
}

