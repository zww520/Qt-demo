#ifndef WORKER_H
#define WORKER_H

#include <QObject>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
    ~Worker();

public slots:
    void slot_dowork();

signals:
    void signal_post_event(QEvent *e);
};

#endif // WORKER_H
