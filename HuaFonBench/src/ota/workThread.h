#pragma once

#include <QObject>

class workThread  : public QObject
{
	Q_OBJECT

public:
	workThread(QObject *parent=nullptr);
	~workThread();

public slots:
	void start1();
	void doWork();
signals:
	void workFinished();
	void workStart();
};
