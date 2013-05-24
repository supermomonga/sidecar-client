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
        //
        w.setImage(a.arguments().first());
    }
    w.setImage("/Users/momonga/Desktop/uji.jpg");
    w.setImage("/Users/momonga/Desktop/zimbu.jpg");

    return a.exec();
}
