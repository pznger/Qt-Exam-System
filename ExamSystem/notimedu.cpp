#include "notimedu.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QApplication>
#include <QPushButton>
#include <QStandardPaths>
#include <QDateTime>
#include <QSet>
#include <QList>
notimeExamDu::notimeExamDu(QWidget*parent):QDialog(parent)
{
    QFont font;
    font.setPointSize(12);
    this->setFont(font);

    setPalette(QPalette(QColor(209,215,255)));


    resize(800,900);

    setWindowFlags(Qt::Dialog|Qt::WindowCloseButtonHint);

    initLayout();
    if(!initTextEdit())
    {
        QMessageBox::information(this,"提示","题库初始化失败");
        QTimer::singleShot(0,qApp,SLOT(quit()));
    }

    initButtons();
    show();
}

notimeExamDu::notimeExamDu(int n, QWidget *parent):QDialog(parent)
{
    num=n;

    QFont font;
    font.setPointSize(12);
    this->setFont(font);

    setPalette(QPalette(QColor(209,215,255)));


    resize(800,900);

    setWindowFlags(Qt::Dialog|Qt::WindowCloseButtonHint);

    initLayout();
    if(!initTextEdit())
    {
        QMessageBox::information(this,"提示","题库初始化失败");
        QTimer::singleShot(0,qApp,SLOT(quit()));
    }

    initButtons();
    show();
}
void notimeExamDu::initUI()
{
    num+=1;

    for(int i=0;i<40;i++)
    {
        m_checkBtns[i]->setChecked(false);
    }
    m_textEdit->clear();
}

void notimeExamDu::initLayout()
{
    m_layout=new QGridLayout(this);
    m_layout->setSpacing(10);//设置控件间的间距
    m_layout->setMargin(20);//设置窗体与控件之间的间隙

}

bool notimeExamDu::initTextEdit()
{
    QString strline;//保存文件读取的数据
    QStringList strlist;//保存文件读取的答案
    QString xxx=QString::number(num);
    QString fileName("du"+xxx+".txt");
    QFile file(fileName);
    QTextStream stream(&file);
    stream.setCodec("UTF-8");
    m_answerList.clear(); // 清空正确答案列表

    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        m_textEdit=new QTextEdit(this);
        m_textEdit->setReadOnly(true);
        QString strText;
        int nLines=0;
        while(!stream.atEnd())
        {
            if(nLines==0)
            {
                stream.readLine();
                nLines++;
                continue;
            }
            if((nLines>=6&&nLines<=6*10&&(nLines%6==0)))
            {
                strline=stream.readLine();
                strlist=strline.split(" ");
                m_answerList.append(strlist.at(1));
                strText+="\n";
                nLines++;
            }
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

void notimeExamDu::initButtons()
{
    QStringList strList={"A","B","C","D"};

    for(int i=0;i<10;i++)
    {
        m_titleLables[i]=new QLabel(this);
        m_titleLables[i]->setText("第"+QString::number(i+1)+"题");
        m_layout->addWidget(m_titleLables[i],1,i);

        for(int j=0;j<4;j++)
        {
            m_checkBtns[4*i+j]=new QCheckBox(this);
            m_checkBtns[4*i+j]->setText(strList.at(j));
            m_layout->addWidget(m_checkBtns[4*i+j],2+j,i);
        }
    }

    QPushButton *submitBtn=new QPushButton(this);
    submitBtn->setText("提交");
    submitBtn->setFixedSize(100,35);

    connect(submitBtn,SIGNAL(clicked(bool)),this,SLOT(getScore()));

    m_layout->addWidget(submitBtn,6,9);

}

bool notimeExamDu::hasNoSelect()
{
    for(int i=0;i<10;i++)
    {
        int checkSelects=0;
        for(int j=0;j<4;j++)
        {
            if(m_checkBtns[4*i+j]->isChecked())
            {
                checkSelects++;
            }
        }
        if(checkSelects==0||checkSelects==1)
        {
            return true;
        }
    }
    return false;
}
void notimeExamDu::getScore()
{
    if(hasNoSelect())
    {
        QMessageBox::information(this,"提示","您有未完成的题目，请继续作答");
        return ;
    }

    m_wrongList.clear(); // 清空错题列表
    QHash<QString, QString> questionMap; // 保存题目内容和正确答案的映射
    QSet<QString> wrongSet; // 保存每道错误题目的题目内容、正确答案和用户答案的组合

    int scores=0;
    for(int i=0;i<10;i++)
    {

            int flag=0;

            QString answer = m_answerList.at(i);
            bool hasA=false;
            bool hasB=false;
            bool hasC=false;
            bool hasD=false;

            if(answer.contains("A"))
            {
                hasA=true;
            }
            if(answer.contains("B"))
            {
               hasB=true;
            }
            if(answer.contains("C"))
            {
               hasC=true;
            }
            if(answer.contains("D"))
            {
                hasD=true;
            }

            bool checkA=m_checkBtns[4*i+0]->checkState();
            bool checkB=m_checkBtns[4*i+1]->checkState();
            bool checkC=m_checkBtns[4*i+2]->checkState();
            bool checkD=m_checkBtns[4*i+3]->checkState();

            if(hasA!=checkA)
            {
                flag =1;
            }
            if(hasB!=checkB)
            {
                flag =1;
            }
            if(hasC!=checkC)
            {
                flag =1;
            }
            if(hasD!=checkD)
            {
                flag =1;
            }

            if(flag==0)
            {
                scores+=10;
            }
            else
            {
                QString question = m_textEdit->toPlainText().split("\n\n").at(i);   // 获取错题内容
                QString correctAnswer = "(正确答案：" + m_answerList.at(i) + ")";   // 获取正确答案
                QString userAnswer = "(您的答案：";
                if(checkA)
                {
                    userAnswer += "A";
                }
                if(checkB)
                {
                    userAnswer += "B";
                }
                if(checkC)
                {
                    userAnswer += "C";
                }
                if(checkD)
                {
                    userAnswer += "D";
                }
                userAnswer += ")"; // 获取用户选择的答案
                // 将题目内容和正确答案组成一个唯一的键值，然后将其加入到SET中
                QString wrongKey = question + correctAnswer;
                wrongSet.insert(wrongKey + userAnswer);
                m_wrongList.append(i+1); // 添加错题题号
            }

    }
    // 显示分数和错题列表
    QString str="您的分数为"+QString::number(scores)+"分(总分：100分)\n(选择No开始下一套题，选择Yes重新作答)\n";
    if(!m_wrongList.isEmpty())
    {
        // 拼接错题题号字符串
        QString wrongStr = "以下为错题题号：\n";
        for(int i=0; i<m_wrongList.count(); i++)
        {
            wrongStr += QString::number(m_wrongList.at(i)) + " ";
        }
        str += wrongStr;
    }
    int res=QMessageBox::information(this,"提示",str,QMessageBox::Yes|QMessageBox::No);
    if(res==QMessageBox::Yes)
    {
        return ;
    }
    else
    {
        initUI(); // 清空答案和界面
        if(!initTextEdit()) // 重新加载新的一套题目
        {
            QMessageBox::information(this,"提示","题库初始化失败");
            QTimer::singleShot(0,qApp,SLOT(quit()));
        }
    }
    // 生成错题文件
    if (!wrongSet.isEmpty())
    {
        QList<QString> wrongList = wrongSet.toList();
        QString fileName = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/" + "第"+QString::number(num-1)+"套题目，生成时间："+QDateTime::currentDateTime().toString("yyyyMMdd") + ".txt";   // 在桌面创建一个以时间戳为文件名的文件
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream stream(&file);
            stream.setCodec("UTF-8");
            for (int i = 0; i < wrongList.count(); i++)
            {
                stream << wrongList.at(i) << endl;
            }
            file.close();
        }

    }
    m_wrongList.clear();
    wrongSet.clear();
}
