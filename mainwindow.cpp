#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QImage>
#include <QPalette>
#include <QPixmap>
#include <QSizePolicy>
#include <QFileInfo>
#include <QDir>
#include <QLabel>

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

void MainWindow::addImage(QString path)
{
    QLabel *label = new QLabel();
    QImage image(QFileInfo(path).absoluteFilePath());
    if(image.isNull()){
        label->setText("そんな画像ないよ");
    }else{
        label->setBackgroundRole(QPalette::Base);
        QPixmap pm = QPixmap::fromImage(image);
        label->setPixmap(pm);
        label->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        label->setScaledContents(false);
        label->adjustSize();
    }
    ui->verticalLayout_2->addWidget(label);
    label->show();
}

void MainWindow::clearImages()
{
    while (!ui->verticalLayout_2->isEmpty()) {
        QWidget* w = ui->verticalLayout_2->takeAt(0)->widget();
        w->setVisible(false);
        delete w;
    }
}
