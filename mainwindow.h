#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <sourcewidget.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void clearImages();
    void clearImages(int n);
    void addImage(QString path);
    void browserInitialize();
    void updateSource();
    void executeJavascript(QString js);
    void adjustPosition();
    void setWebviewSize();
    SourceWidget source_widget;
    
private slots:
    void on_pushButtonShowHTML_clicked();

    void on_webView_loadFinished(bool arg1);

    void adjustWindowSize(QSize);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
