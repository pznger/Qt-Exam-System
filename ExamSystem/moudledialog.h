#ifndef MOUDLEDIALOG_H
#define MOUDLEDIALOG_H

#include <qmessagebox.h>
#include <qfile.h>
#include <QTextStream>
#include <QDialog>

namespace Ui {
class MoudleDialog;
}

class MoudleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MoudleDialog(QWidget *parent = 0);
    ~MoudleDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_fontComboBox_activated(const QString &arg1);

    void on_checkBox_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MoudleDialog *ui;
};

#endif // MOUDLEDIALOG_H
