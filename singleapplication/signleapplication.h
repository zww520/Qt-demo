#ifndef SIGNLEAPPLICATION_H
#define SIGNLEAPPLICATION_H

#include <QSharedMemory>
#include <QCoreApplication>

#if defined qApp
#undef qApp
#endif

#define qApp static_cast<SignleApplication*>(QCoreApplication::instance())

class SignleApplication : public QCoreApplication
{
    Q_OBJECT
public:
    explicit SignleApplication(int argc, char **argv);

public:
    bool isRunning();

private:
    QSharedMemory mem;

signals:

public slots:
};

#endif // SIGNLEAPPLICATION_H
