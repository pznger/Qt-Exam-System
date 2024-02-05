#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QApplication>
#include <QPushButton>
#include <QStandardPaths>
#include <QDateTime>
#include <QSet>
#include <QList>
#include "examdialog2h.h"
ExamDialog2h::ExamDialog2h(QWidget*parent):QDialog(parent)
{
    QFont font;
    font.setPointSize(12);
    this->setFont(font);

    setPalette(QPalette(QColor(209,215,255)));


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

    initButtons();
    show();
}
void ExamDialog2h::initUI()
{
    m_timeGo=0;
    m_radioA->setChecked(false);
    m_radioB->setChecked(false);
    for(int i=0;i<8;i++)
    {
        m_btnGroups[i]->setExclusive(false);
        m_btnGroups[i]->checkedButton()->setChecked(false);
        m_btnGroups[i]->setExclusive(true);
    }
    for(int i=0;i<4;i++)
    {
        m_checkBtns[i]->setChecked(false);
    }
    m_btnGroups[8]->setExclusive(false);
    m_btnGroups[8]->checkedButton()->setChecked(false);
    m_btnGroups[8]->setExclusive(true);
    setWindowTitle("考试已用时：0分0秒");
    m_textEdit->clear();
}
void ExamDialog2h::initTimer()
{
    m_timeGo=0;
    m_timer=new QTimer(this);
    m_timer->setInterval(1000);
    m_timer->start();
    connect(m_timer,SIGNAL(timeout()),this,SLOT(freshTime()));
}

void ExamDialog2h::initLayout()
{
    m_layout=new QGridLayout(this);
    m_layout->setSpacing(10);//设置控件间的间距
    m_layout->setMargin(20);//设置窗体与控件之间的间隙

}

bool ExamDialog2h::initTextEdit()
{
    QString strline;//保存文件读取的数据
    QStringList strlist;//保存文件读取的答案
    QString xxx=QString::number(rand()%15+1);
    QString fileName("exam"+xxx+".txt");
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
            if(nLines==0)
            {
                stream.readLine();
                nLines++;
                continue;
            }
            if((nLines>=6&&nLines<=6*9&&(nLines%6==0))||
                    (nLines==6*9+4))
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

void ExamDialog2h::initButtons()
{
    QStringList strList={"A","B","C","D"};

    for(int i=0;i<10;i++)
    {
        m_titleLables[i]=new QLabel(this);
        m_titleLables[i]->setText("第"+QString::number(i+1)+"题");
        m_layout->addWidget(m_titleLables[i],1,i);

        if(i==9)
        {
            m_radioA=new QRadioButton(this);
            m_radioB=new QRadioButton(this);

            m_radioA->setText("正确");
            m_radioB->setText("错误");

            m_layout->addWidget(m_radioA,2,9);
            m_layout->addWidget(m_radioB,3,9);

            m_btnGroups[8]=new QButtonGroup(this);
            m_btnGroups[8]->addButton(m_radioA);
            m_btnGroups[8]->addButton(m_radioB);

            break;

        }

        if(i<8)m_btnGroups[i]=new QButtonGroup(this);

        for(int j=0;j<4;j++)
        {
            //多选题
            if(i==8)
            {
                m_checkBtns[j]=new QCheckBox(this);
                m_checkBtns[j]->setText(strList.at(j));
                m_layout->addWidget(m_checkBtns[j],2+j,8);
            }
            else
            {
                m_radioBtns[4*i+j]=new QRadioButton(this);
                m_radioBtns[4*i+j]->setText(strList.at(j));
                m_layout->addWidget(m_radioBtns[4*i+j],2+j,i);
                m_btnGroups[i]->addButton(m_radioBtns[4*i+j]);
            }
        }


    }

    QPushButton *submitBtn=new QPushButton(this);
    submitBtn->setText("提交");
    submitBtn->setFixedSize(100,35);

    connect(submitBtn,SIGNAL(clicked(bool)),this,SLOT(getScore()));

    m_layout->addWidget(submitBtn,6,9);

}

bool ExamDialog2h::hasNoSelect()
{
    int radioSelects=0;
    for(int i=0;i<8;i++)
    {
        if(m_btnGroups[i]->checkedButton())
        {
            radioSelects++;
        }
    }

    if(radioSelects!=8)
    {
        return true;
    }


    int checkSelects=0;
    for(int i=0;i<4;i++)
    {
        if(m_checkBtns[i]->isChecked())
        {
            checkSelects++;
        }
    }
    if(checkSelects==0||checkSelects==1)
    {
        return true;
    }
    if(!m_radioA->isChecked()&&!m_radioB->isChecked())
    {
        return true;
    }


    return false;
}

void ExamDialog2h::freshTime()
{
    //刷新考试用时
    m_timeGo++;
    QString min=QString::number(m_timeGo/60);
    QString sec=QString::number(m_timeGo%60);
    setWindowTitle("考试已用时："+min+"分"+sec+"秒"+"(请在5分钟内完成作答)");
}

void ExamDialog2h::getScore()
{
    if(hasNoSelect())
    {
        QMessageBox::information(this,"提示","您有未完成的题目，请继续作答");
        return ;
    }

    m_wrongList.clear(); // 清空错题列表

    int scores=0;
    for(int i=0;i<10;i++)
    {
        if(i<8)
        {
            if(m_btnGroups[i]->checkedButton()->text()==m_answerList.at(i))
            {
                scores+=10;
            }
            else
            {
                m_wrongList.append(i+1); // 添加错题题号
                // 添加错题信息
                if (!m_wrongList.isEmpty())
                {
                    QList<int> uniqueWrongList = m_wrongList.toSet().toList();   // 去重后的题号列表
                    for (int i = 0; i < uniqueWrongList.count(); i++)
                    {
                        int index = uniqueWrongList.at(i) - 1;   // 获取错题在题目数组中的下标
                        QString question = m_textEdit->toPlainText().split("\n\n").at(index + 1);   // 获取错题内容
                        QString correctAnswer = "(正确答案：" + m_answerList.at(index) + ")";   // 获取正确答案
                        QString userAnswer = "(您的答案：" + m_btnGroups[index]->checkedButton()->text() + ")";   // 获取用户选择的答案
                        QString wrongAnswer = "第" + QString::number(uniqueWrongList.at(i)) + "题：" + question + correctAnswer + userAnswer;   // 拼接错题信息字符串
                        if(!m_wrongAnswerList.contains(wrongAnswer))   // 如果错题列表中不存在该题目信息，则添加
                        {
                            m_wrongAnswerList.append(wrongAnswer);
                        }
                    }
                }

            }
        }
        else if(i==8)
        {
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

            bool checkA=m_checkBtns[0]->checkState();
            bool checkB=m_checkBtns[1]->checkState();
            bool checkC=m_checkBtns[2]->checkState();
            bool checkD=m_checkBtns[3]->checkState();

            if(hasA!=checkA)continue;
            if(hasB!=checkB)continue;
            if(hasC!=checkC)continue;
            if(hasD!=checkD)continue;

            scores+=10;
        }
        else if(i==9)
        {
            if(m_btnGroups[8]->checkedButton()->text()==m_answerList.at(i))
            {
                scores+=10;
            }
            else
            {
                m_wrongList.append(i+1); // 添加错题题号
                // 添加错题信息
                if (!m_wrongList.isEmpty())
                {
                    QList<int> uniqueWrongList = m_wrongList.toSet().toList();   // 去重后的题号列表
                    for (int i = 0; i < uniqueWrongList.count(); i++)
                    {
                        int index = uniqueWrongList.at(i) - 1;   // 获取错题在题目数组中的下标
                        QString question = m_textEdit->toPlainText().split("\n\n").at(index + 1);   // 获取错题内容
                        QString correctAnswer = "(正确答案：" + m_answerList.at(index) + ")";   // 获取正确答案
                        QString userAnswer = "(您的答案：" + m_btnGroups[index]->checkedButton()->text() + ")";   // 获取用户选择的答案
                        QString wrongAnswer = "第" + QString::number(uniqueWrongList.at(i)) + "题：" + question + correctAnswer + userAnswer;   // 拼接错题信息字符串
                        if(!m_wrongAnswerList.contains(wrongAnswer))   // 如果错题列表中不存在该题目信息，则添加
                        {
                            m_wrongAnswerList.append(wrongAnswer);
                        }
                    }
                }


            }
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
    if (!m_wrongAnswerList.isEmpty())
    {
        QString fileName = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/" + QDateTime::currentDateTime().toString("yyyyMMddhhmmss") + ".txt";   // 在桌面创建一个以时间戳为文件名的文件
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream stream(&file);
            stream.setCodec("UTF-8");
            for (int i = 0; i < m_wrongAnswerList.count(); i++)
            {
                stream << m_wrongAnswerList.at(i) << endl;
            }
            file.close();
        }
    }


}
