#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    if(a.arguments().length() > 1) {
        w.setImage(a.arguments().first());
    }

    return a.exec();
}
