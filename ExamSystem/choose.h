#ifndef CHOOSE_H
#define CHOOSE_H

#include <QDeclarativeItem>
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class chooseData;

class choose : public QDialog
{
public:
    choose();
    choose(const choose &);
    choose &operator=(const choose &);
    ~choose();

private:
    QSharedDataPointer<chooseData> data;
};

#endif // CHOOSE_H