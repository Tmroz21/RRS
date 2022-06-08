#include "mainwindow.h"
#include "addtrainwindow.h"
#include "dbmanager.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>

 QVBoxLayout * lay = new QVBoxLayout();
 static const QString path = "trains.db";
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

    QPushButton *button = new QPushButton(db.printToTableByID(id));
    QObject::connect(button, &QPushButton::clicked,this,&MainWindow::on_button_clicked);
    lay->addWidget(button);
    ui->scrollContent->setLayout(lay);

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

void MainWindow::on_button_clicked()
{
    qDebug() << "text";


}

