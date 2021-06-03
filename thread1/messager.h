#ifndef MESSAGER_H
#define MESSAGER_H

#include <QObject>

class Messager : public QObject
{
    Q_OBJECT
public:
    explicit Messager(QObject *parent = nullptr);

public:
    static Messager* &getInstance();
    void setData(int data);

signals:
    void signal_send_data(int data);

};

#endif // MESSAGER_H
