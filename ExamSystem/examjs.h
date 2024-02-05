#ifndef EXAMJS_H
#define EXAMJS_H

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


class ExamJs : public QDialog
{
    Q_OBJECT
public:
    int num=0;
    int dayornight=0;
    ExamJs(QWidget* parent=0);
    ExamJs(int m,int n,QWidget* parent=0);
    void initTimer();//初始化计时器
    void initLayout();//初始化布局管理器
    bool initTextEdit();//初始化文本编辑器
    void initButtons();//初始化按钮及标签
    bool hasNoSelect();//有无未完成题目
    void initUI();
private:
    QTimer *m_timer;//计时器
    int m_timeGo;//考试已用时
    QTextEdit *m_textEdit;//考试题库显示
    QLabel *m_titleLables[11];//提目标签
    QRadioButton *m_radioBtns[40];//单选题按钮
    QGridLayout *m_layout;//布局管理器
    QStringList m_answerList;//答案列表
    QButtonGroup *m_btnGroups[11];//按钮分组
    QList<int> m_wrongList;
    QList<QString> m_wrongAnswerList;
    QList<int> uniqueWrongList;

private slots:
    void freshTime();//刷新考试时间





};
#endif // EXAMJS_H
