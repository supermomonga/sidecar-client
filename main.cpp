#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // Always has atleast one arg which is Application path.
    // So if args is two or more, it passed one or more args from user or another software.
    if(a.arguments().length() > 1) {
        w.clearImages();
        QStringList args = a.arguments();
        QStringList::const_iterator iter;
        for (iter = ++args.constBegin(); iter != args.constEnd();++iter){
            w.setImage(*iter);
        }
    }
#define DEBUG
#ifdef DEBUG
    w.setImage("/Users/momonga/Desktop/uji.jpg");
    w.setImage("https://dl.dropboxusercontent.com/u/330501/Screenshots/vim.png");
#endif

    return a.exec();
}
