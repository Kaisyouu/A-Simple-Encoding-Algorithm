/********************************************************************************
** Form generated from reading UI file 'key.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEY_H
#define UI_KEY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_key
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *key)
    {
        if (key->objectName().isEmpty())
            key->setObjectName(QString::fromUtf8("key"));
        key->resize(400, 300);
        verticalLayout = new QVBoxLayout(key);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(key);
        label->setObjectName(QString::fromUtf8("label"));
        label->setWordWrap(true);

        horizontalLayout->addWidget(label);

        pushButton = new QPushButton(key);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(key);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);

        textBrowser = new QTextBrowser(key);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setReadOnly(false);

        verticalLayout->addWidget(textBrowser);


        retranslateUi(key);

        QMetaObject::connectSlotsByName(key);
    } // setupUi

    void retranslateUi(QDialog *key)
    {
        key->setWindowTitle(QApplication::translate("key", "Dialog", nullptr));
        label->setText(QApplication::translate("key", "You can edit the KEY here, press 'Save' to make changes.", nullptr));
        pushButton->setText(QApplication::translate("key", "Save", nullptr));
        pushButton_2->setText(QApplication::translate("key", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class key: public Ui_key {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEY_H
