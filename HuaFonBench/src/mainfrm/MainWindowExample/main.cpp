#include "MainWindow.h"
#include <QApplication>
#include <QElapsedTimer>
#include <QDebug>
#include "../../mastermng/masterfrm.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QElapsedTimer cost;
    cost.start();
     masterfrm mw;
        mw.show();

//    MainWindow w;
//    qDebug() <<"window build cost:"<<cost.elapsed()<<" ms";
//    w.show();

    return a.exec();
}
