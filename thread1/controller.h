#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "application.h"
#include "worker.h"

#include <QThread>
#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller() override;

public:
    void run();

private:
    void init();
    void setConnection();

private:
    Application *app;
    Worker *worker;
    QThread *thread;

protected:
//    bool event(QEvent *event) override;
//    void timerEvent(QTimerEvent *event) override;
signals:

public slots:
    void slot_exit();
    void slot_re_data(int data);
};

#endif // CONTROLLER_H
