#include "sourcewidget.h"
#include "ui_sourcewidget.h"

SourceWidget::SourceWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SourceWidget)
{
    ui->setupUi(this);
}

SourceWidget::~SourceWidget()
{
    delete ui;
}

void SourceWidget::setHtml(QString html)
{
    ui->plainTextEditSource->clear();
    ui->plainTextEditSource->appendPlainText(html);
}
