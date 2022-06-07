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
    qDebug() << db.countAllTrain();
}

void MainWindow::AddTrainToScroll()
{

   // QPushButton *button = new QPushButton(db.printToTable());
    //lay->addWidget(button);
    //ui->scrollContent->setLayout(lay);

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

