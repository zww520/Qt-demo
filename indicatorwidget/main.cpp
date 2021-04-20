#include "IndicatorWidget.h"
#include <QLabel>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget widget;
    QLabel label("Indicator",&widget);
    label.setAlignment(Qt::AlignCenter);
    label.setSizePolicy(QSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed));
    label.move(64,34);
    IndicatorWidget w(&widget);
    w.move(40,40);
    widget.show();
    w.setColor(IndicatorWidget::Error);
    return a.exec();
}
