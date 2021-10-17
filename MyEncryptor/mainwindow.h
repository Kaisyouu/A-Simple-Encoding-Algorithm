#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDateTime>
#include <QLabel>
#include <stdio.h>
#include "key.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    key *keyDialog;
    QLabel *currentTimeLabel;
    QLabel *currentMode;
    bool isEncrypt;
    QString pt;
    QString ct;
    QString keyText;
    QString stringProcess(QString input);
    QString col_permute(QString input, int col);
    QString generate_ct(QString pt, QString key);
    QString decode(QString ct, QString key);

private slots:
    void time_update();
    void on_pushButton_clicked();
    void on_radioButton_clicked();
    void on_radioButton_2_clicked();
    void on_pushButton_2_clicked();
};
#endif // MAINWINDOW_H
