#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QDateTime>
#include <QTimer>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    currentTimeLabel = new QLabel;
    ui->statusbar->addWidget(currentTimeLabel);
    QTimer *timer = new QTimer(this);
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(time_update()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::time_update()
{
    QDateTime current_time = QDateTime::currentDateTime();
    QString timestr = current_time.toString("yyyy年MM月dd日 hh:mm:ss");
    currentTimeLabel->setText(timestr);
}
