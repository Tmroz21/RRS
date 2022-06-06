#ifndef ADDTRAINWINDOW_H
#define ADDTRAINWINDOW_H

#include <QWidget>

namespace Ui {
class AddTrainWindow;
}

class AddTrainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AddTrainWindow(QWidget *parent = nullptr);
    ~AddTrainWindow();

    int input();

private slots:
    void on_lineEdit_From_textChanged(const QString &arg1);

    void on_lineEdit_To_textChanged(const QString &arg1);

    void on_lineEdit_Code_textChanged(const QString &arg1);

    void on_spinBox_Seats_valueChanged(int arg1);

    void on_pushButton_Add_clicked();

    void ReadFromFile();

private:
    Ui::AddTrainWindow *ui;
};


#endif // ADDTRAINWINDOW_H
