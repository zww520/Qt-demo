#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

using uint = unsigned int;
/**********************
 * group:widget
 * description:标识
 * version:1.0.0
 **********************/
class IndicatorWidget : public QWidget
{
    Q_OBJECT
public:
    enum SHAPE
    {
        Rect,
        Round
    };
    enum COLOR
    {
        Success,     // #2EA44F
        Warnning,    // #E6A23C
        Error,       // #F56C6C
        Disable,     // #F4F4F5
        Common       // #409EFF
    };
public:
    IndicatorWidget(QWidget *parent = nullptr);
public:
    void setColor(COLOR color);
    void setShape(SHAPE shape);
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    uint m_color;  // 颜色
    SHAPE m_shape;
};
#endif // WIDGET_H
