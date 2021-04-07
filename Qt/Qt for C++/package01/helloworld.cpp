#include "helloworld.h"
#include "iostream.h"
class HelloWorldData : public QSharedData
{
public:

};

HelloWorld::HelloWorld() : data(new HelloWorldData)
{

}

HelloWorld::HelloWorld(const HelloWorld &rhs) : data(rhs.data)
{

}

HelloWorld &HelloWorld::operator=(const HelloWorld &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

HelloWorld::~HelloWorld()
{

}


int main(){
    cout << "hello"<<endl;
    return 0;
}
