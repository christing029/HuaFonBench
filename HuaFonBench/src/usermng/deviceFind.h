#pragma once

#include <QWidget>
#include "ui_deviceFind.h"
#include <QUdpSocket>
#include <QTimer>

class deviceFind : public QWidget
{
	Q_OBJECT

public:
	deviceFind(QWidget *parent = nullptr);
	~deviceFind();
private:
	QTimer* timer;
	QUdpSocket* udpSocket;
	double rotation = 0;  // 用于动画的旋转角度
	qreal angle;
	QString UUID[10] = { "" };
	uint8_t deviceCount = 0;
private:
	void processDatagram(const QNetworkDatagram& datagram);

private slots:
	void updateSnd();
	void readPendingDatagrams();
private:
	Ui::deviceFindClass ui;
};
