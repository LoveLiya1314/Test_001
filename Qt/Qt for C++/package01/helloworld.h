#ifndef HELLOWORLD_H
#define HELLOWORLD_H

#include <QDeclarativeItem>
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class HelloWorldData;

class HelloWorld
{
    Q_OBJECT
public:
    HelloWorld();
    HelloWorld(const HelloWorld &);
    HelloWorld &operator=(const HelloWorld &);
    ~HelloWorld();

private:
    QSharedDataPointer<HelloWorldData> data;
};

#endif // HELLOWORLD_H
