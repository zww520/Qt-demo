#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "maskwidget.h"

#include <QPushButton>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MaskWidget *w = new MaskWidget;
    QPushButton *btn = new QPushButton("button",this);
    btn->move(40,40);
    connect(btn,&QPushButton::clicked,[=](){
        w->show();
        w->move(mapToGlobal(QPoint(50,50)));
    });
    connect(w,&MaskWidget::signal_on_confirmed,[](int id){
        qDebug()<<"clicked on:"<<id;
    });
    setStyleSheet("background-color : #efefe3");
}

MainWindow::~MainWindow()
{
    delete ui;
}

