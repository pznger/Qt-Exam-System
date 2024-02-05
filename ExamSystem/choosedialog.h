#ifndef CHOOSEDIALOG_H
#define CHOOSEDIALOG_H

#include <QDeclarativeItem>
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class chooseDialogData;

class chooseDialog : public QDialog
{
public:
    chooseDialog();
    chooseDialog(const chooseDialog &);
    chooseDialog &operator=(const chooseDialog &);
    ~chooseDialog();

private:
    QSharedDataPointer<chooseDialogData> data;
};

#endif // CHOOSEDIALOG_H