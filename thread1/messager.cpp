#include "messager.h"

#include <QThread>
#include <QDebug>

Messager::Messager(QObject *parent) : QObject(parent)
{

}

Messager *&Messager::getInstance()
{
    static Messager *messager = new Messager;
    return messager;
}

void Messager::setData(int data)
{
    qDebug()<<data<<"commit data";
    qDebug()<<"woker thread"<<QThread::currentThreadId();
    emit signal_send_data(data);
}
