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
#include <QtWebKitWidgets/QWebView>
#include <QtWebKitWidgets/QWebPage>
#include <QtWebKitWidgets/QWebFrame>
#include <QSize>
#include <QFile>
#include <QIODevice>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setStyleSheet("background:transparent;");
    //setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint);
    adjunstPosition();
    browserInitialize();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::adjunstPosition()
{
    move(30,30);
}

void MainWindow::browserInitialize()
{
    QFile css;
    css.setFileName(":/css/init.css");
    css.open(QIODevice::ReadOnly);
    ui->webView->page()->mainFrame()->setHtml("<!DOCTYPE html><html lang=\"ja\"><head><meta charset=\"utf-8\"><style>" + css.readAll() + "</style><title></title></head><body><div id=\"multipleImages\"></div></body></html>");

    QFile jQuery;
    jQuery.setFileName(":/js/jquery-1.9.1.min.js");
    jQuery.open(QIODevice::ReadOnly);
    ui->webView->page()->mainFrame()->evaluateJavaScript(jQuery.readAll());
}

void MainWindow::clearImages()
{
    //clearImages(ui->verticalLayoutImages->count());
}

void MainWindow::clearImages(int n)
{

}

void MainWindow::addImage(QString path)
{
    QRegExp remoteImage("^https?.+(jpg|jpeg|gif|png)$");
    if(remoteImage.indexIn(path) == -1) {
        path = "file://" + path;
    }
    executeJavascript("$('#multipleImages').append('<img src=\"" + path + "\" />');");
}

void MainWindow::executeJavascript(QString js)
{
    ui->webView->page()->mainFrame()->evaluateJavaScript(js);
    updateSource();
}

void MainWindow::on_pushButtonShowHTML_clicked()
{
    this->source_widget.show();
    updateSource();
}

void MainWindow::on_webView_loadFinished(bool arg1)
{
    updateSource();
}

void MainWindow::updateSource()
{
    this->source_widget.setHtml(ui->webView->page()->currentFrame()->toHtml());
}

void MainWindow::on_pushButtonQuit_clicked()
{
    QApplication::quit();
}
