#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "addtrainwindow.h"
#include "qpushbutton.h"
#include "qtablewidget.h"
#include <QMainWindow>

//QString userid;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT
      AddTrainWindow *addTrainW = new AddTrainWindow();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void AddTrainToScroll(int id);

private slots:

    void on_actionDodaj_poloczenie_triggered();

    void on_actionTworcy_triggered();

    void on_actionUsu_triggered();

    void on_pushButton_clicked();

    void on_tableWidget_Trains_cellClicked(int row, int column);

    void on_pushButton_reservation_clicked();

    void updateTable();

    void on_actionMoje_Bilety_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
