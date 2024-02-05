#include "logindialog.h"
#include <QApplication>
#include <examdialog.h>
#include "examdx.h"
#include "examdu.h"
#include "exampd.h"
#include "moudledialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog w;
    int res=w.exec();
    if(res==QDialog::Accepted)
    {
        MoudleDialog *q;
        q=new MoudleDialog;
        q->show();
        return a.exec();
    }
    else
    {
        return 0;
    }
//  exam q;
//  q.show();
}
