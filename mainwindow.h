#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void setImage(QString path);
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
