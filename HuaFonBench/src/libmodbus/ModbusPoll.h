//#pragma once
#ifndef ModbusPoll_H
#define ModbusPoll_H

#include <QObject>
#include <QDate>
#include <QMessageBox>
#include <QElapsedTimer>
#include <QTime>
#include <QElapsedTimer>
#include <QTime>
#include "config.h"
#include <src/libmodbus/modbus.h>

class ModbusPoll  : public QObject
{
	Q_OBJECT

public:
	ModbusPoll(QObject *parent);
	~ModbusPoll();
private:
	modbus_t* m_tcpModbus;
	bool m_tcpActive;
	bool m_poll;
public:
	bool tcpConnect(QString ip, quint16 port);
	bool modbus_read_holding(quint8 slaveId, quint16 readStartAddr, quint16 readNum);

private:
	void sendModbusRequest(void);
protected:
	void releaseTcpModbus();
private slots:
	void timer1000ms();
};
#endif
