#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QDateTime>
#include <QTimer>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    currentTimeLabel = new QLabel;
    currentMode = new QLabel;
    currentMode->setText("Encryption mode");
    ui->statusbar->addWidget(currentTimeLabel);
    ui->statusbar->addWidget(currentMode);
    QTimer *timer = new QTimer(this);
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(time_update()));
    isEncrypt = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::stringProcess(QString input)
{
    QString output="";
    for (int i=0;i<input.length();i++)
    {
        if (input[i]>='a'&&input[i]<='z')
        {
            output+=input[i];
        }
        else if (input[i]>='A'&&input[i]<='Z')
        {
            output+=input[i].toLower();
        }
    }
    return output;
}


void MainWindow::time_update()
{
    QDateTime current_time = QDateTime::currentDateTime();
    QString timestr = current_time.toString("yyyy年MM月dd日 hh:mm:ss");
    currentTimeLabel->setText(timestr);
}

void MainWindow::on_pushButton_clicked()
{
    if (isEncrypt)
    {
        QString input = ui->textBrowser->toPlainText();
        if (input.length()==0)
        {
            QMessageBox::information(this, "hint", "Please enter something then click the button!");
        }
        else
        {
            pt = stringProcess(input);
            QString t_pt = col_permute(pt, 5);

            QFile file("./key.txt");
            if (!file.open(QIODevice::ReadOnly))
            {
                QMessageBox::information(0, "info", file.errorString());
            }
            QTextStream in(&file);
            QString text = in.readAll();
            file.close();

            keyText = "";
            for (int i=0;i<text.length();i++)
            {
                if (text[i]>='a'&&text[i]<='z')
                {
                    keyText+=text[i];
                }
                else if (text[i]>='A'&&text[i]<='Z')
                {
                    keyText+=text[i].toLower();
                }
            }

            ct = generate_ct(t_pt, keyText);

            qDebug()<<"Encrypting:";
            qDebug()<<"Plaintext: "<<pt;
            qDebug()<<"Key: "<<keyText;
            qDebug()<<"Cyphertext: "<<ct;

            ui->textBrowser_2->setText(ct);
        }
    }
    else if (!isEncrypt)
    {
        QString input = ui->textBrowser_2->toPlainText();
        if (input.length()==0)
        {
            QMessageBox::information(this, "hint", "Please enter something then click the button!");
        }
        else
        {
            ct = stringProcess(input);

            QFile file("./key.txt");
            if (!file.open(QIODevice::ReadOnly))
            {
                QMessageBox::information(0, "info", file.errorString());
            }
            QTextStream in(&file);
            QString text = in.readAll();
            file.close();

            keyText = stringProcess(text);

            QString pt_t = decode(ct, keyText);
            pt = col_permute(pt_t, pt_t.length()/5);
            ui->textBrowser->setText(pt);

            qDebug()<<"Decrypting:";
            qDebug()<<"Cyphertext: "<<ct;
            qDebug()<<"Key: "<<keyText;
            qDebug()<<"Plaintext: "<<pt;

        }
    }
    else
    {
        QMessageBox::warning(this, "Error", "Error when selecting mode...");
    }
}

void MainWindow::on_radioButton_clicked()
{
    isEncrypt = true;
    ui->pushButton->setText("ENCRYPT");
    ui->textBrowser->setReadOnly(false);
    ui->textBrowser_2->setReadOnly(true);
    ui->textBrowser->setText("");
    ui->textBrowser_2->setText("");
}

void MainWindow::on_radioButton_2_clicked()
{
    isEncrypt = false;
    ui->pushButton->setText("DECRYPT");
    this->currentMode->setText("Decryption mode");
    ui->textBrowser->setReadOnly(true);
    ui->textBrowser_2->setReadOnly(false);
    ui->textBrowser->setText("");
    ui->textBrowser_2->setText("");
}

QString MainWindow::col_permute(QString input, int col)
{
    QString x="x";
    while(input.length()%col!=0)
    {
        input+=x;
    }
    int row=input.length()/col;
    char tbl[row][col];
    int i,j;
    int cnt=0;
    for (i=0;i<row;i++)
    {
        for (j=0;j<col;j++)
        {
            tbl[i][j]=input[cnt++].toLatin1();
        }
    }
    cnt=0;
    for (i=0;i<col;i++)
    {
        for (j=0;j<row;j++)
        {
            input[cnt++]=tbl[j][i];
        }
    }
    return input;
}

void MainWindow::on_pushButton_2_clicked()
{
    keyDialog = new key(this);
    keyDialog->show();
}

QString MainWindow::generate_ct(QString pt, QString key)
{
    QString key1="";
    while (key1.length()<pt.length())
    {
        key1+=key;
    }
    QString ct = "";
    for (int i=0;i<pt.length();i++)
    {
        int offset = key1[i].toLatin1() - 'a';
        if (int(pt[i].toLatin1()+offset) > 122)
        {
            offset -= 26;
        }
        ct += QChar(int(pt[i].toLatin1()+offset));
    }
    return ct;
}

QString MainWindow::decode(QString ct, QString key)
{
    QString key1="";
    while (key1.length()<ct.length())
    {
        key1+=key;
    }
    QString out = "";
    for (int i=0;i<ct.length();i++)
    {
        int offset = key1[i].toLatin1() - 'a';
        if (int(ct[i].toLatin1()-offset) < 97)
        {
            offset -= 26;
        }
        out += QChar(int(ct[i].toLatin1()-offset));
    }
    return out;
}

