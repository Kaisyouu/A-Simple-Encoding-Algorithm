#include "key.h"
#include "ui_key.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>
#include <QCoreApplication>

key::key(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::key)
{
    ui->setupUi(this);

    QFile file("./key.txt");
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0, "info", file.errorString());
    }
    QTextStream in(&file);
    ui->textBrowser->setText(file.readAll());
    file.close();
}

key::~key()
{
    delete ui;
}

void key::on_pushButton_2_clicked()
{
    this->close();
}

void key::on_pushButton_clicked()
{
    QFile file("./key.txt");
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::information(0, "info", file.errorString());
    }
    QString keyText = ui->textBrowser->toPlainText();
    file.write(keyText.toStdString().data());
    file.close();
    QMessageBox::information(0, "info", "Saved");
}
