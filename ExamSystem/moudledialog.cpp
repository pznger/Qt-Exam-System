#include "moudledialog.h"
#include "ui_moudledialog.h"
#include "examdu.h"
#include "examdx.h"
#include "exampd.h"
#include "examwd.h"
#include "examjs.h"
#include <qmessagebox.h>
#include <qfile.h>
#include <QTextStream>
#include <QTextBrowser>

MoudleDialog::MoudleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MoudleDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("题目选择");
}

MoudleDialog::~MoudleDialog()
{
    delete ui;
}

void MoudleDialog::on_pushButton_clicked()
{
    QString Dxnum=ui->lineEdit->text();
    int nu=Dxnum.toInt();
    if(nu<=0||nu>20)
    {
        QMessageBox::information(this,"提示","单选只有20套题，请输入数字1-20");
        ui->lineEdit->clear();
        ui->lineEdit->setFocus();
        return ;
    }
    ExamDx *p;

    if(ui->checkBox_2->isChecked())p=new ExamDx(1,nu);
    else p=new ExamDx(0,nu);
}

void MoudleDialog::on_pushButton_2_clicked()
{
    QString Dunum=ui->lineEdit_2->text();
    int nu=Dunum.toInt();
    if(nu<=0||nu>10)
    {
        QMessageBox::information(this,"提示","多选只有10套题，请输入数字1-10");
        ui->lineEdit_2->clear();
        ui->lineEdit_2->setFocus();
        return ;
    }
    ExamDu *p;
    if(ui->checkBox_2->isChecked())p=new ExamDu(1,nu);
    else p=new ExamDu(0,nu);
}

void MoudleDialog::on_pushButton_3_clicked()
{
    int randnum=rand()%2+1;
    if(randnum==1)
    {
        int nu=rand()%20+1;
        ExamDx *p;
        if(ui->checkBox_2->isChecked())p=new ExamDx(1,nu);
        else p=new ExamDx(0,nu);
    }
    else if(randnum==2)
    {
        int nu=rand()%10+1;
        ExamDu *p;
        if(ui->checkBox_2->isChecked())p=new ExamDu(1,nu);
        else p=new ExamDu(0,nu);
    }
}

void MoudleDialog::on_fontComboBox_activated(const QString &arg1)
{

}

void MoudleDialog::on_checkBox_2_clicked()
{

}

void MoudleDialog::on_pushButton_4_clicked()
{
    QString Dxnum=ui->lineEdit_4->text();
    int nu=Dxnum.toInt();
    if(nu<=0||nu>5)
    {
        QMessageBox::information(this,"提示","判断只有5套题，请输入数字1-5");
        ui->lineEdit_4->clear();
        ui->lineEdit_4->setFocus();
        return ;
    }
    ExamPd *p;

    if(ui->checkBox_2->isChecked())p=new ExamPd(1,nu);
    else p=new ExamPd(0,nu);
}

void MoudleDialog::on_pushButton_5_clicked()
{
    QString Dxnum=ui->lineEdit_5->text();
    int nu=Dxnum.toInt();
    if(nu<=0||nu>5)
    {
        QMessageBox::information(this,"提示","问答只有5套题，请输入数字1-5");
        ui->lineEdit_5->clear();
        ui->lineEdit_5->setFocus();
        return ;
    }
    ExamWd *p;

    if(ui->checkBox_2->isChecked())p=new ExamWd(1,nu);
    else p=new ExamWd(0,nu);
}

void MoudleDialog::on_pushButton_6_clicked()
{
    QString Dxnum=ui->lineEdit_6->text();
    int nu=Dxnum.toInt();
    if(nu<=0||nu>5)
    {
        QMessageBox::information(this,"提示","计算只有5套题，请输入数字1-5");
        ui->lineEdit_6->clear();
        ui->lineEdit_6->setFocus();
        return ;
    }
    ExamJs *p;

    if(ui->checkBox_2->isChecked())p=new ExamJs(1,nu);
    else p=new ExamJs(0,nu);
}

void MoudleDialog::on_pushButton_7_clicked()
{
    QTextBrowser *textBrowser = new QTextBrowser;
    textBrowser->setOpenExternalLinks(true); // 允许打开外部链接
    textBrowser->setHtml("<a href=\"https://www.bilibili.com/video/BV1c4411d7jb/?spm_id_from=333.337.search-card.all.click\">湖科大</a><br>"
                         "<a href=\"https://www.bilibili.com/video/BV19E411D78Q/?spm_id_from=333.337.search-card.all.click\">王道</a><br>"
                         "<a href=\"https://blog.csdn.net/qq_51604330/article/details/122645061?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522170254653316800215021154%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=170254653316800215021154&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_click~default-2-122645061-null-null.142^v96^pc_search_result_base8&utm_term=%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BD%91%E7%BB%9C%E7%AC%94%E8%AE%B0&spm=1018.2226.3001.4187\">计算机网络笔记</a><br>"
                         "<a href=\"https://blog.csdn.net/qq_56919740/article/details/128188774\">课后题答案</a>");
    textBrowser->show();
}



