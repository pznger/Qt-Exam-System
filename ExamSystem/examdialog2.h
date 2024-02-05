#ifndef EXAMDIALOG_H
#define EXAMDIALOG_H
#include <QDialog>
#include <QTimer>
#include <QTextEdit>
#include <QLabel>
#include <QRadioButton>
#include <QCheckBox>
#include <QGridLayout>
#include <QButtonGroup>

class ExamDialog2 : public QDialog
{
    Q_OBJECT
public:
    ExamDialog2(QWidget* parent=0);
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
    QRadioButton *m_radioBtns[32];//单选题按钮
    QCheckBox *m_checkBtns[4];//多选题按钮
    QRadioButton *m_radioA;//判断题A选项
    QRadioButton *m_radioB;//判断题B选项
    QGridLayout *m_layout;//布局管理器
    QStringList m_answerList;//答案列表
    QButtonGroup *m_btnGroups[9];//按钮分组
    QList<int> m_wrongList;
    QList<QString> m_wrongAnswerList;
    QList<int> uniqueWrongList;

private slots:
    void freshTime();//刷新考试时间
    void getScore();//获取考试成绩
};

#endif // EXAMDIALOG_H
