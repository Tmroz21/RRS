#include "mainwindow.h"
#include "addtrainwindow.h"
#include "dbmanager.h"
#include "ui_mainwindow.h"

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

}

void MainWindow::AddTrainToScroll(int id)
{

   // QPushButton *button = new QPushButton(db.printToTableByID(id));
  //  QObject::connect(button, &QPushButton::clicked,this,&MainWindow::on_button_clicked);
   // lay->addWidget(button);
    //ui->scrollContent->setLayout(lay);
            ui->tableWidget_Trains->insertRow(ui->tableWidget_Trains->rowCount());
            QTableWidgetItem *newTrainCode  = new QTableWidgetItem(db.printCodeToTableByID(id));
            QTableWidgetItem *newTrainFrom = new QTableWidgetItem(db.printFromToTableByID(id));
            QTableWidgetItem *newTrainTo = new QTableWidgetItem(db.printToToTableByID(id));
            QTableWidgetItem *newTrainAVS = new QTableWidgetItem(QString::number(db.printSeatsToTableByID(id)));
            ui->tableWidget_Trains->setItem(ui->tableWidget_Trains->rowCount()-1,0,newTrainCode);
            ui->tableWidget_Trains->setItem(ui->tableWidget_Trains->rowCount()-1,1,newTrainTo);
            ui->tableWidget_Trains->setItem(ui->tableWidget_Trains->rowCount()-1,2,newTrainFrom);
            ui->tableWidget_Trains->setItem(ui->tableWidget_Trains->rowCount()-1,3,newTrainAVS);

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


void MainWindow::on_actionUsu_triggered()
{
    db.removeAllTrain();
}


