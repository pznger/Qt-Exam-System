#include "examwd.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QApplication>
#include <QPushButton>
#include <QStandardPaths>
#include <QDateTime>
#include <QSet>
#include <QList>
#include <QObject>

ExamWd::ExamWd(QWidget*parent):QDialog(parent)
{
    QFont font;
    font.setPointSize(12);
    this->setFont(font);

    setPalette(QPalette(QColor(0,0,0)));


    resize(800,900);
    setWindowTitle("考试已用时：0分0秒");

    setWindowFlags(Qt::Dialog|Qt::WindowCloseButtonHint);

    initTimer();
    initLayout();
    if(!initTextEdit())
    {
        QMessageBox::information(this,"提示","题库初始化失败");
        QTimer::singleShot(0,qApp,SLOT(quit()));
    }

    show();
}

ExamWd::ExamWd(int m,int n,QWidget*parent):
    QDialog(parent)
{
    num=n;
    dayornight=m;

    QFont font;
    font.setPointSize(12);
    this->setFont(font);


    if(!dayornight)setPalette(QPalette(QColor(150,200,255)));
    else setPalette(QPalette(QColor(0,0,0)));



    resize(800,900);
    setWindowTitle("考试已用时：0分0秒");

    setWindowFlags(Qt::Dialog|Qt::WindowCloseButtonHint);

    initTimer();
    initLayout();
    if(!initTextEdit())
    {
        QMessageBox::information(this,"提示","题库初始化失败");
        QTimer::singleShot(0,qApp,SLOT(quit()));
    }

    show();
}

void ExamWd::initUI()
{
    m_timeGo=0;
    num+=1;
    if(num!=3)
    {

    }
    else
    {
        QMessageBox::information(this,"提示","问答题只有3套题");
return;
    }

    setWindowTitle("考试已用时：0分0秒");
    m_textEdit->clear();
}
void ExamWd::initTimer()
{
    m_timeGo=0;
    m_timer=new QTimer(this);
    m_timer->setInterval(1000);
    m_timer->start();
    connect(m_timer,SIGNAL(timeout()),this,SLOT(freshTime()));
}

void ExamWd::initLayout()
{
    m_layout=new QGridLayout(this);
    m_layout->setSpacing(10);//设置控件间的间距
    m_layout->setMargin(20);//设置窗体与控件之间的间隙

}

bool ExamWd::initTextEdit()
{
    QString strline;//保存文件读取的数据
    QStringList strlist;//保存文件读取的答案
    QString xxx=QString::number(num);
    QString fileName("wd"+xxx+".txt");
    QFile file(fileName);
    QTextStream stream(&file);
    stream.setCodec("UTF-8");

    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        m_textEdit=new QTextEdit(this);
        m_textEdit->setReadOnly(true);
        QString strText;
        int nLines=0;
        while(!stream.atEnd())
        {
            strText+=stream.readLine();
            strText+="\n";
            nLines++;
        }
        m_textEdit->setText(strText);
        m_layout->addWidget(m_textEdit,0,0,1,10);
        file.close();
        return true;
    }
    else
    {
        return false;
    }
}


void ExamWd::freshTime()
{
    //刷新考试用时
    m_timeGo++;
    QString min=QString::number(m_timeGo/60);
    QString sec=QString::number(m_timeGo%60);
    setWindowTitle("考试已用时："+min+"分"+sec+"秒"+"(请在3分钟内完成作答)");

}

