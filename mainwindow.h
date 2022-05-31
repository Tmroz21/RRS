#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Add_clicked();

    void on_lineEdit_Code_textChanged(const QString &arg1);

    void on_lineEdit_To_textChanged(const QString &arg1);

    void on_lineEdit_From_textChanged(const QString &arg1);

    void on_spinBox_Seats_valueChanged(int arg1);

    void on_listView_TrainList_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H