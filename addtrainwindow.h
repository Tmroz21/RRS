#ifndef ADDTRAINWINDOW_H
#define ADDTRAINWINDOW_H


#include <QMainWindow>
//#include <mainwindow.h>


namespace Ui { class AddTrainWindow;}

class AddTrainWindow : public QMainWindow
{
    Q_OBJECT

  //  MainWindow *mainW = new MainWindow();

public:
    explicit AddTrainWindow(QWidget *parent = nullptr);
    ~AddTrainWindow();

private slots:
    void on_actionStrona_Glowna_triggered();

private:
    Ui::AddTrainWindow *ui;
};

#endif // ADDTRAINWINDOW_H
