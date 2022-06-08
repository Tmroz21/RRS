#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>
#include "registerdb.h"

static const QString path = "database.db";
RegisterDb rdb(path);
LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(rdb.userPassword(username) == password) {
        QMessageBox::information(this, "Login", "Welcome!");
        m.show();
        this->hide();
    }
    else {
        QMessageBox::warning(this,"Login","Login and Password are not correct");
    }
}


void LoginWindow::on_pushButton_register_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(rdb.userExists(username) == false)
    {
        if (rdb.isOpen())
        {
            qDebug() << "User successfully added";
            rdb.createTable();
            rdb.userAdd(username,password);
            QMessageBox::information(this, "User", "user added");
        }
        else
        {
            qDebug() << "Database is not open!";
        }
    }
    else
    {
        QMessageBox::warning(this,"Registration","User with this username already exist");
    }
}

