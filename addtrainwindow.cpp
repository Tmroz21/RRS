#include "addtrainwindow.h"
#include "ui_addtrainwindow.h"
#include "mainwindow.h"

AddTrainWindow::AddTrainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddTrainWindow)
{
    ui->setupUi(this);
}

AddTrainWindow::~AddTrainWindow()
{
    delete ui;
}

void AddTrainWindow::on_actionStrona_Glowna_triggered()
{

    this->hide();
}

