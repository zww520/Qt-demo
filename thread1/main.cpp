#include "controller.h"

#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Controller controller;
    controller.run();
    QObject::connect(QCoreApplication::instance(),&QCoreApplication::aboutToQuit,[](){
       qDebug()<<"quit";
    });
    return a.exec();
}
