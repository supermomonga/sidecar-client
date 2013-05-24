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
#include <QRegExp>

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

void MainWindow::clearImages()
{
    clearImages(ui->verticalLayoutImages->count());
}

void MainWindow::clearImages(int n)
{
    int i = 0;
    while (!ui->verticalLayoutImages->isEmpty() && i < n) {
        QWidget* w = ui->verticalLayoutImages->takeAt(0)->widget();
        w->setVisible(false);
        delete w;
        i++;
    }
}

void MainWindow::setImage(QString path)
{
    QLabel *label = new QLabel();
    QRegExp remoteImage("https?.+(jpg|jpeg|gif|png)");
    if(remoteImage.indexIn(path) > 0)
    {
        QString html = "test:<img src=\"" + path + "\"/>";
        qDebug() << html;
        label->setTextFormat(Qt::RichText);
        label->setText(html);
    }else {
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
    }
    ui->verticalLayoutImages->addWidget(label);
    label->show();
}
