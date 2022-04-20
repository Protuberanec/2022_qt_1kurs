#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <iostream>
#include <QImage>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MobPhone : public QObject {
    Q_OBJECT

private :
    char* mobilePhone;
public :
    MobPhone() {
        mobilePhone = new char [9];
    }
    ~MobPhone() {
        delete [] mobilePhone;
    }

public slots :

    void slot_Answer(int idClient);


};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer* timerCall;
    MobPhone* mbPhone;

    void initTable();



public slots :
    void slot_ProcessBtn();


signals :
    void sig_Call(int idClient);





};
#endif // MAINWINDOW_H
