#ifndef EXAMDU_H
#define EXAMDU_H

#include <QMainWindow>
#include <QObject>
#include <QSharedDataPointer>
#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QApplication>
#include <QPushButton>
#include <QStandardPaths>
#include <QDateTime>
#include <QSet>
#include <QList>
#include <QDialog>
#include <QTimer>
#include <QTextEdit>
#include <QLabel>
#include <QRadioButton>
#include <QCheckBox>
#include <QGridLayout>
#include <QButtonGroup>

class notimeExamDu : public QDialog
{
    Q_OBJECT
public:
    int num=0;
    notimeExamDu(QWidget* parent=0);
    notimeExamDu(int n,QWidget* parent=0);
    void initLayout();//初始化布局管理器
    bool initTextEdit();//初始化文本编辑器
    void initButtons();//初始化按钮及标签
    bool hasNoSelect();//有无未完成题目
    void initUI();

private:
    QTextEdit *m_textEdit;//考试题库显示
    QCheckBox *m_checkBtns[41];//多选题按钮
    QLabel *m_titleLables[11];//提目标签
    QGridLayout *m_layout;//布局管理器
    QStringList m_answerList;//答案列表
    QList<int> m_wrongList;
    QList<QString> m_wrongAnswerList;
    QList<int> uniqueWrongList;

private slots:
    void getScore();//获取考试成绩
};

#endif // EXAMDU_H
