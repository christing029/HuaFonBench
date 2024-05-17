#include "workThread.h"

workThread::workThread(QObject *parent)
	: QObject(parent)
{}

workThread::~workThread()
{}

void workThread::start1()
{
    emit workStart();
    doWork();
}
void workThread::doWork()
{
    for (int i = 0; i < 1000000; i++)
    {
        i = i;
        //qDebug() << i << endl;
    }
    emit workFinished();
}
