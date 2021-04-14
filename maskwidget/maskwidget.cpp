#include "maskwidget.h"

#include <QPushButton>
#include <QPainter>
#include <QHBoxLayout>
#include <QVector>
#include <QStyleOption>
#include <QStylePainter>
#include <QCheckBox>
#include <QButtonGroup>
MaskWidget::MaskWidget(QWidget *parent) : QWidget(parent,Qt::Popup)
{
    setFixedSize(120,120);
    QVector<QPoint> outline = {QPoint(0,30),QPoint(50,30),QPoint(60,0),
                               QPoint(70,30),QPoint(120,30),QPoint(120,120),QPoint(0,120)};
    setMask(QRegion(outline));

    QVBoxLayout *vlayout = new QVBoxLayout;
    QButtonGroup *group = new QButtonGroup(this);
    QCheckBox *box1 = new QCheckBox("选择一");
    QCheckBox *box2 = new QCheckBox("选择二");
    group->addButton(box1);
    group->addButton(box2);
    QPushButton *confirm_btn = new QPushButton("确定");
   // confirm_btn->setFlat(true);
    confirm_btn->setStyleSheet("background-color : #4E6EF2; color : #ffffff");

    vlayout->addSpacing(40);
    vlayout->addWidget(box1);
    vlayout->addWidget(box2);
    vlayout->addWidget(confirm_btn);
    connect(confirm_btn,&QPushButton::clicked,[=](){
        int id = group->checkedId();
        emit signal_on_confirmed(id);
        this->hide();
    });

    setLayout(vlayout);

    setStyleSheet("background-color : #FAFBFC");
}

void MaskWidget::paintEvent(QPaintEvent *event)
{
    QStylePainter painter(this);
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    QStyleOption option;
    option.initFrom(this);
    painter.drawPrimitive(QStyle::PE_Widget,option);

}
