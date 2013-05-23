#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QImage>
#include <QPalette>
#include <QPixmap>
#include <QSizePolicy>
#include <QFileInfo>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setImage(QString path)
{
    QImage image(QFileInfo(path.replace("~", QDir::homePath())).absoluteFilePath());
    if(image.isNull()){
        ui->label->setText("そんな画像ないよ");
    }else{
        ui->label->setBackgroundRole(QPalette::Base);
        QPixmap pm = QPixmap::fromImage(image);
        ui->label->setPixmap(pm);
        ui->label->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        ui->label->setScaledContents(false);
        ui->label->adjustSize();
    }
}
