#ifndef SOURCEWIDGET_H
#define SOURCEWIDGET_H

#include <QWidget>

namespace Ui {
class SourceWidget;
}

class SourceWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit SourceWidget(QWidget *parent = 0);
    ~SourceWidget();
    void setHtml(QString);
    
private:
    Ui::SourceWidget *ui;
};

#endif // SOURCEWIDGET_H
