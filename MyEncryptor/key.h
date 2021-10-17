#ifndef KEY_H
#define KEY_H

#include <QDialog>

namespace Ui {
class key;
}

class key : public QDialog
{
    Q_OBJECT

public:
    explicit key(QWidget *parent = nullptr);
    ~key();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::key *ui;
};

#endif // KEY_H
