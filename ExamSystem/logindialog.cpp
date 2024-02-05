#include "logindialog.h"
#include "ui_logindialog.h"
#include <qmessagebox.h>
#include <qfile.h>
#include <QTextStream>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->imgLoginLabel->setScaledContents(true);
    this->resize(ui->imgLoginLabel->width(),ui->imgLoginLabel->height());
    setFixedSize(width(),height());
    this->setWindowTitle("计算机网络系统");
    this->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButton_clicked()
{

}

void LoginDialog::on_LoginButton_clicked()
{
    //利用正则表达式判断邮箱地址的合法性 用户名@域名
    QRegExp rx("^[A-Za-z0-9]+([\\_\\.][A-Za-z0-9]+)*@([A-Za-z0-9\\-]+\\.)+[A-Za-z]{2,6}$");
    bool res=rx.exactMatch(ui->accountEdit->text());
    if(!res)
    {
        QMessageBox::information(this,"提示","请确保账号为合法邮箱地址后重新输入");
        ui->accountEdit->clear();
        ui->accountEdit->setFocus();
        return ;
    }
    else
    {
        QString filename;
        QString strAccount;
        QString strCode;
        QString strLine;
        QStringList strlist;

        filename="account.txt";
        strAccount=ui->accountEdit->text();
        strCode=ui->codeEdit->text();

        QFile file(filename);
        QTextStream stream(&file);
        if(file.open(QIODevice::ReadOnly|QIODevice::Text))
        {
            while(!stream.atEnd())
            {

                strLine=stream.readLine();
                strlist=strLine.split(",");
                if(strAccount==strlist.at(0))
                {
                    if(strCode==strlist.at(1))
                    {
                        QMessageBox::information(this,"提示","登陆成功！");
                        done(Accepted);
                        return;
                    }
                    else
                    {
                        QMessageBox::information(this,"提示","您输入的密码错误，请重新输入");
                        ui->codeEdit->clear();
                        ui->codeEdit->setFocus();
                        file.close();
                        return;
                    }
                }

            }
            QMessageBox::information(this,"提示","账号不存在");
            ui->accountEdit->clear();
            ui->codeEdit->clear();
            ui->accountEdit->setFocus();
            file.close();

            return;
        }
        else
        {
            QMessageBox::information(this,"提示","读取文件失败");
            return ;
        }
    }
}

void LoginDialog::on_pushButton_2_clicked()
{
    done(Rejected);
}

void LoginDialog::on_label_5_linkActivated(const QString &link)
{

}

void LoginDialog::on_LoginButton_2_clicked()
{
    QMessageBox::information(this,"提示","欢迎使用！");
    done(Accepted);
    return;
}
