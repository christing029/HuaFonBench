#pragma once
#ifndef MODBUSCOMMIT_H
#define MODBUSCOMMIT_H
#include <QObject>
//#include <src/libmodbus/ModbusPoll.h>
#include "QModbusDevice"
#include <QModbusTcpClient>
#include <QModbusDataUnit>
#include <QModbusReply>
#include <QList>
#include <QEvent>

class ModbusTCP  : public QObject
{
	Q_OBJECT

public:
	ModbusTCP(QObject *parent);
	~ModbusTCP();

private:
    QModbusTcpClient* modbusClient = nullptr;


    QList<quint16> readCoilVal;
    QList<quint16> readHoldingVal;
    QList<quint16> readInputVal;
    QList<quint16> readDiscreteVal;
signals:
private slots:
    void state_change_slot(QModbusDevice::State state);//连接状态改变
    void error_occurred_slot(QModbusDevice::Error error);
    void readready_coils_slot();
    void readready_holding_slot();
    void readready_input_slot();
    void readready_discrete_slot();
    void writeready_coil_slot();
    void writeready_holding_slot();
    void writeready_input_slot();
public:
    bool modbus_connect(QString ip, quint16 port);
    bool modbus_disconnect();
    bool modbus_read_coils(quint8 slaveId, quint16 readStartAddr, quint16 readNum);
    bool modbus_read_holding(quint8 slaveId, quint16 readStartAddr, quint16 readNum);
    bool modbus_read_extending(quint8 slaveId, quint16 readStartAddr, quint16 readNum);
    bool modbus_read_input(quint8 slaveId, quint16 readStartAddr, quint16 readNum);
    bool modbus_read_discrete(quint8 slaveId, quint16 readStartAddr, quint16 readNum);
    bool modbus_write_coils(quint8 slaveId, quint16 writeStartAddr, quint16 writeNum, QVector<quint16> writeValue);
    bool modbus_write_holding(quint8 slaveId, quint16 writeStartAddr, quint16 writeNum, QVector<quint16> writeValue);
    bool modbus_write_input(quint8 slaveId, quint16 writeStartAddr, quint16 writeNum, QVector<quint16> writeValue);
signals:
    void modbus_state_change_signal(QModbusDevice::State state);
    void modbus_error_occurred_signal(QModbusDevice::Error state);
    void modbus_read_over_signal(QModbusDataUnit::RegisterType type, bool isErr, QList<quint16> readData);
    void modbus_write_res(QModbusDataUnit::RegisterType type, bool isErr);
    void modbus_read_input_unit(QModbusDataUnit unit);
    void modbus_read_holding_unit(QModbusDataUnit unit);
protected:
    bool event(QEvent* e) override {
        if (e->type() == QEvent::DeferredDelete) {
            // 当事件队列处理到删除事件时，此时 m_socket 上的所有连接都已被移除
            delete modbusClient; // 显式删除 m_socket 以避免内存泄漏
            return true;
        }
        return QObject::event(e);
    }


};


#endif