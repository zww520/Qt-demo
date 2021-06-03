#include "controller.h"
#include "messager.h"

#include <QCoreApplication>
#include <QDebug>
#include <QEvent>
#include <QTimer>

Controller::Controller(QObject *parent) : QObject(parent)
{
    init();
    setConnection();
}

Controller::~Controller()
{
    qDebug()<<"delete controller";
    thread->exit();
    thread->wait();

    delete worker;
    delete thread;
    delete app;
}

void Controller::run()
{
    app->run();
}

void Controller::init()
{
    app = new Application;
    worker = new Worker;
    thread = new QThread;
    worker->moveToThread(thread);
    thread->start();

}

void Controller::setConnection()
{
    qDebug()<<"controller main"<<QThread::currentThreadId();
    connect(app,&Application::signal_do_work,worker,&Worker::slot_dowork);
    connect(Messager::getInstance(),&Messager::signal_send_data,this,&Controller::slot_re_data);
//    connect(Messager::getInstance(),&Messager::signal_send_data,[=](int data){
//        qDebug()<<"123231213"<<data;
//        slot_re_data(data);
//    });
}

//bool Controller::event(QEvent *event)
//{
//    switch (event->type())
//    {
//        case QEvent::KeyPress:
//            qDebug()<<"key press";
//        break;
//        default:
//            break;
//    }
//    qDebug()<<"type:"<<event->type();
//    return true;
//}

//void Controller::timerEvent(QTimerEvent *event)
//{
//    qDebug()<<"timer:"<<event->timerId();
//}

void Controller::slot_exit()
{
    QCoreApplication::instance()->exit(0);
}

void Controller::slot_re_data(int data)
{
    qDebug()<<"132132"<<data<<QThread::currentThreadId();
}
