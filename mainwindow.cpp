#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initTable();


    connect(ui->pushButton, &QPushButton::clicked,
            this, &MainWindow::slot_ProcessBtn); //new 新
//    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(slot_ProcessBtn()));  //old 旧

    mbPhone = new MobPhone();
    connect(this, &MainWindow::sig_Call, mbPhone, &MobPhone::slot_Answer);

    timerCall = new QTimer();
    timerCall->setInterval(1000);
    timerCall->setSingleShot(false);


    connect(timerCall, &QTimer::timeout, this, [=]() {
        static int tempCount = 0;
//        emit sig_Call(tempCount++ % 10);
        std::cout << "slot Answer = " << tempCount << std::endl;
    });

    timerCall->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initTable()
{
    ui->tableWidget->setColumnCount(10);
    ui->tableWidget->setRowCount(10);

    QTableWidgetItem* item;

    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        for (int j = 0; j < ui->tableWidget->columnCount(); j++) {
            if (ui->tableWidget->item(i, j) == nullptr){
                item = new QTableWidgetItem(tr("%2 %1 %3").arg(i).arg(j, 5, 2, QLatin1Char('0')).arg("test"));
                ui->tableWidget->setItem(i, j, item);
            }

        }
    }
}

void MainWindow::slot_ProcessBtn()
{
    static int countPressed = 0;
    std::cout << "slot_ProcessBtn " << countPressed++ <<  std::endl;

    static int x = 0;
    static int y = 0;

    ui->tableWidget->item(y, x)->setText("fdsfafsfaf");
    if (++x > ui->tableWidget->columnCount() - 1) {
        y++;
        x = 0;
        if (y > ui->tableWidget->rowCount() - 1) {
            y = 0;
            x = 0;
        }
    }
}


void MobPhone::slot_Answer(int idClient)
{
    std::cout << "slot Answer = " << idClient << std::endl;
}
