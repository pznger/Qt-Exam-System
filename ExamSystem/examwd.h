#ifndef EXAMWD_H
#define EXAMWD_H
#include <QDialog>
#include <QTimer>
#include <QTextEdit>
#include <QLabel>
#include <QRadioButton>
#include <QCheckBox>
#include <QGridLayout>
#include <QButtonGroup>
#include <QMainWindow>
#include <QSharedDataPointer>
#include <QWidget>
#include <QObject>


class ExamWd : public QDialog
{
    Q_OBJECT
public:
    int num=0;
    int dayornight=0;
    ExamWd(QWidget* parent=0);
    ExamWd(int m,int n,QWidget* parent=0);
    void initTimer();//初始化计时器
    void initLayout();//初始化布局管理器
    bool initTextEdit();//初始化文本编辑器
    void initUI();
    void freshTime();
private:
    QTimer *m_timer;//计时器
    int m_timeGo;//考试已用时
    QTextEdit *m_textEdit;//考试题库显示
    QGridLayout *m_layout;//布局管理器


};

#endif // EXAMWD_H
