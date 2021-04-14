#ifndef MASKWIDGET_H
#define MASKWIDGET_H

#include <QWidget>

class MaskWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MaskWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

signals:
    void signal_on_confirmed(int id);
public slots:
};

#endif // MASKWIDGET_H
