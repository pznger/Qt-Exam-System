#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;//与下面的LoginDialog不是一个类
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

private slots:
    void on_pushButton_clicked();

    void on_LoginButton_clicked();

    void on_pushButton_2_clicked();

    void on_label_5_linkActivated(const QString &link);

    void on_LoginButton_2_clicked();

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
