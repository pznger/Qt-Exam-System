/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLabel *imgLoginLabel;
    QLabel *label_2;
    QLineEdit *accountEdit;
    QLineEdit *codeEdit;
    QPushButton *LoginButton;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QPushButton *LoginButton_2;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(478, 380);
        imgLoginLabel = new QLabel(LoginDialog);
        imgLoginLabel->setObjectName(QString::fromUtf8("imgLoginLabel"));
        imgLoginLabel->setGeometry(QRect(0, 0, 481, 381));
        imgLoginLabel->setPixmap(QPixmap(QString::fromUtf8(":/ikun.png")));
        label_2 = new QLabel(LoginDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 220, 72, 21));
        accountEdit = new QLineEdit(LoginDialog);
        accountEdit->setObjectName(QString::fromUtf8("accountEdit"));
        accountEdit->setGeometry(QRect(180, 170, 151, 31));
        codeEdit = new QLineEdit(LoginDialog);
        codeEdit->setObjectName(QString::fromUtf8("codeEdit"));
        codeEdit->setGeometry(QRect(180, 210, 151, 31));
        codeEdit->setEchoMode(QLineEdit::Password);
        LoginButton = new QPushButton(LoginDialog);
        LoginButton->setObjectName(QString::fromUtf8("LoginButton"));
        LoginButton->setGeometry(QRect(130, 270, 93, 28));
        pushButton_2 = new QPushButton(LoginDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 270, 93, 28));
        label_3 = new QLabel(LoginDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(120, 170, 61, 31));
        label = new QLabel(LoginDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 80, 381, 61));
        label->setStyleSheet(QString::fromUtf8("font: 36pt \"Agency FB\";\n"
"font: 16pt \"Agency FB\";"));
        label_4 = new QLabel(LoginDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 330, 381, 20));
        label_4->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\271\274\345\234\206\";"));
        label_5 = new QLabel(LoginDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 0, 91, 91));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/sdust.png")));
        label_5->setScaledContents(true);
        label_7 = new QLabel(LoginDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(200, 140, 211, 16));
        label_7->setStyleSheet(QString::fromUtf8("font: 9pt \"Times New Roman\";"));
        LoginButton_2 = new QPushButton(LoginDialog);
        LoginButton_2->setObjectName(QString::fromUtf8("LoginButton_2"));
        LoginButton_2->setGeometry(QRect(320, 10, 151, 41));

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "LoginDialog", nullptr));
        imgLoginLabel->setText(QString());
        label_2->setText(QCoreApplication::translate("LoginDialog", "\345\257\206\347\240\201", nullptr));
        LoginButton->setText(QCoreApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
        pushButton_2->setText(QCoreApplication::translate("LoginDialog", "\351\200\200\345\207\272", nullptr));
        label_3->setText(QCoreApplication::translate("LoginDialog", "\350\264\246\345\217\267", nullptr));
        label->setText(QCoreApplication::translate("LoginDialog", "\350\256\241\347\256\227\346\234\272\347\275\221\347\273\234\345\244\215\344\271\240\347\263\273\347\273\237", nullptr));
        label_4->setText(QCoreApplication::translate("LoginDialog", "\346\217\220\347\244\272\357\274\232\350\264\246\345\217\267\344\270\272\351\202\256\347\256\261\345\234\260\345\235\200\357\274\214\351\246\226\346\254\241\347\231\273\351\231\206\345\257\206\347\240\201\351\273\230\350\256\244\344\270\272666666", nullptr));
        label_5->setText(QString());
        label_7->setText(QCoreApplication::translate("LoginDialog", "\344\275\234\350\200\205\357\274\232pznger", nullptr));
        LoginButton_2->setText(QCoreApplication::translate("LoginDialog", "\344\270\215\350\276\223\345\205\245\345\257\206\347\240\201\347\233\264\346\216\245\350\277\233\345\205\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
