#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
//int main(){
//    using namespace std;
//    cout <<" hello "<<endl;
//    return 0;
//}