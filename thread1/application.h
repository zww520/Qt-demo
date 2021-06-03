#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>

class Application : public QObject
{
    Q_OBJECT
public:
    explicit Application(QObject *parent = nullptr);

public:
    void run();

signals:
    void signal_do_work();

};

#endif // APPLICATION_H
