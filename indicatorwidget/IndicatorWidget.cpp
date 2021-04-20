#include "IndicatorWidget.h"

#include <QPainter>
IndicatorWidget::IndicatorWidget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(8,8);
    m_color =  0x409EFF;
    m_shape = SHAPE::Round;
    setAttribute(Qt::WA_AlwaysShowToolTips,true);
}

void IndicatorWidget::setColor(IndicatorWidget::COLOR color)
{
    switch (color)
    {
        case COLOR::Success:
            m_color = 0x2EA44F;
            break;
        case COLOR::Warnning:
            m_color = 0xE6A23C;
            break;
        case COLOR::Error:
            m_color = 0xF56C6C;
            break;
        case COLOR::Disable:
            m_color = 0xF4F4F5;
            break;
        default:
            m_color = 0x409EFF;
            break;
    }
    update();
}

void IndicatorWidget::setShape(IndicatorWidget::SHAPE shape)
{
    m_shape = shape;
    update();
}


void IndicatorWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(m_color);
    painter.setBrush(QBrush(QColor(m_color)));
    switch (m_shape)
    {
        case SHAPE::Rect:
            painter.drawRect(rect());
            break;
        default:
            painter.drawEllipse(QRect(0,0,width(),height()));
    }
    painter.end();
}

