#include "worker.h"
#include "messager.h"

#include <QDebug>
#include <QTimer>
#include <QThread>

Worker::Worker(QObject *parent) : QObject(parent)
{

}

Worker::~Worker()
{
    qDebug()<<"delete worker";
}

void Worker::slot_dowork()
{
    qDebug()<<"worker do work";
    QTimer::singleShot(1000,[](){
       qDebug()<<"worker"<<QThread::currentThreadId();
       Messager *messager = Messager::getInstance();
       messager->setData(4100);
    });
}
