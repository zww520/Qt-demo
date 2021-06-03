#include "application.h"

#include <QDebug>
#include <QEvent>
#include <QThread>

Application::Application(QObject *parent) : QObject(parent)
{

}

void Application::run()
{
    emit signal_do_work();
    qDebug()<<"app"<<QThread::currentThreadId();
//    while(1);
    qDebug()<<"dowork";
}

