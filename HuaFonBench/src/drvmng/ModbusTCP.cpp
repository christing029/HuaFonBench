#include "ModbusTCP.h"
#include "qdebug.h"
#include "QEventLoop"
#include <src/libmodbus/ModbusPoll.h>
ModbusPoll* mblib = nullptr;
ModbusTCP::ModbusTCP(QObject *parent)
	: QObject(parent)
{
    modbusClient = new QModbusTcpClient;
   // mblib = new ModbusPoll(nullptr);
    connect(modbusClient, &QModbusTcpClient::stateChanged, this, &ModbusTCP::state_change_slot);
   // connect(mblib, &ModbusPoll::stateChanged, this, &ModbusTCP::state_change_slot);

}

ModbusTCP::~ModbusTCP()
{
     if(modbusClient !=nullptr)
    {
        modbusClient->disconnectDevice();
        modbusClient->deleteLater();
        delete modbusClient;
    }
}
bool ModbusTCP::modbus_connect(QString ip, quint16 port)
{
    if (!modbusClient) {
        return false;
    }

 //   mblib->tcpConnect(ip,9030);


    QModbusDevice::State sta = modbusClient->state();
    if (modbusClient->state() != QModbusDevice::ConnectedState)
    {
        //配置modbus tcp的连接参数 IP + Port   modbus协议的端口号为502
        modbusClient->setConnectionParameter(QModbusDevice::NetworkAddressParameter, ip);
        modbusClient->setConnectionParameter(QModbusDevice::NetworkPortParameter, port);
        modbusClient->setTimeout(1000);
        modbusClient->setNumberOfRetries(3);
        //  return modbusClient->connectDevice();
        if (!modbusClient->connectDevice())
        {
            sta = modbusClient->state();
            qDebug() << "连接modbus设备失败";
            return false;
        }
        else {
            qDebug() << "成功连接到modbs设备";
            return true;
        }
    }
    else
    {
        modbusClient->disconnectDevice();
        return false;
    }
}
bool ModbusTCP::modbus_disconnect()
{
   uint sta=   modbusClient->state();
    if (modbusClient->state() == QModbusDevice::ConnectedState)
    {
        modbusClient->disconnectDevice();  
    }
    return true;
}
bool ModbusTCP::modbus_read_coils(quint8 slaveId, quint16 readStartAddr, quint16 readNum)
{
    if (modbusClient->state() != QModbusDevice::ConnectedState)
        return false;
    QModbusDataUnit readDataUnit;
    readDataUnit.setRegisterType(QModbusDataUnit::Coils);
    readDataUnit.setStartAddress(readStartAddr);
    readDataUnit.setValueCount(readNum);

    qDebug() << "配置ReadUnit完成";
    if (auto* reply = modbusClient->sendReadRequest(readDataUnit, slaveId))     //1是Server_ID
    {
        if (!reply->isFinished())
        {
            QObject::connect(reply, &QModbusReply::finished, this, &ModbusTCP::readready_coils_slot);
            return true;
        }
        else
        {
            delete reply;
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool ModbusTCP::modbus_read_holding(quint8 slaveId, quint16 readStartAddr, quint16 readNum)
{
 //   return mblib->modbus_read_holding(slaveId, readStartAddr, readNum);
    if (modbusClient->state() != QModbusDevice::ConnectedState)
        return false;
    //if (readNum>256)
    //    return false;
    QModbusDataUnit readDataUnit;
    readDataUnit.setRegisterType(QModbusDataUnit::HoldingRegisters);
    readDataUnit.setStartAddress(readStartAddr);
    readDataUnit.setValueCount(readNum);
#if 1
    if (auto* reply = modbusClient->sendReadRequest(readDataUnit, slaveId))     //1是Server_ID
    {
        if (!reply->isFinished())
        {
          //  QObject::connect(reply, &QModbusReply::finished, this, &ModbusTCP::readready_holding_slot);
            QEventLoop loop;
            connect(reply, &QModbusReply::finished, &loop, &QEventLoop::quit);
            loop.exec(); // 等待响应完成
            if (reply->error() == QModbusDevice::NoError) {
                // 处理寄存器数据
                const QModbusDataUnit unit = reply->result();
                emit modbus_read_holding_unit(unit);
                if (reply != nullptr)
                    reply->deleteLater();
                delete reply;
                return true;
            }
            else {
                qDebug() << "读取失败：" << reply->errorString();
            }
            if (reply != nullptr)
            reply->deleteLater();
            return true;
        }
        else
        {
            delete reply;
            return false;
        }
    }

#endif
}

bool ModbusTCP::modbus_read_extending(quint8 slaveId, quint16 readStartAddr, quint16 readNum)
{

    if (modbusClient->state() != QModbusDevice::ConnectedState)
        return false;
    //if (readNum>256)
    //    return false;
    QModbusDataUnit readDataUnit;
    readDataUnit.setRegisterType(QModbusDataUnit::ExtendRegisters);
    readDataUnit.setStartAddress(readStartAddr);
    readDataUnit.setValueCount(readNum);

    if (auto* reply = modbusClient->sendReadRequest(readDataUnit, slaveId))     //1是Server_ID
    {
        if (!reply->isFinished())
        {
            QObject::connect(reply, &QModbusReply::finished, this, &ModbusTCP::readready_holding_slot);
            return true;
        }
        else
        {
            delete reply;
            return false;
        }
    }
    else
        return false;
}

bool ModbusTCP::modbus_read_input(quint8 slaveId, quint16 readStartAddr, quint16 readNum)
{
    if (modbusClient->state() != QModbusDevice::ConnectedState)
        return false;
    QModbusDataUnit readDataUnit;
    readDataUnit.setRegisterType(QModbusDataUnit::InputRegisters);
    readDataUnit.setStartAddress(readStartAddr);
    readDataUnit.setValueCount(readNum);
    qDebug() << "配置ReadUnit完成";
    if (auto* reply = modbusClient->sendReadRequest(readDataUnit, slaveId))     //1是Server_ID
    {
        if (!reply->isFinished())
        {
            QObject::connect(reply, &QModbusReply::finished, this, &ModbusTCP::readready_input_slot);
            return true;
        }
        else
        {
            delete reply;
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool ModbusTCP::modbus_read_discrete(quint8 slaveId, quint16 readStartAddr, quint16 readNum)
{
    if (modbusClient->state() != QModbusDevice::ConnectedState)
        return false;
    QModbusDataUnit readDataUnit;
    readDataUnit.setRegisterType(QModbusDataUnit::DiscreteInputs);
    readDataUnit.setStartAddress(readStartAddr);
    readDataUnit.setValueCount(readNum);

    qDebug() << "配置ReadUnit完成";
    if (auto* reply = modbusClient->sendReadRequest(readDataUnit, slaveId))     //1是Server_ID
    {
        if (!reply->isFinished())
        {
            QObject::connect(reply, &QModbusReply::finished, this, &ModbusTCP::readready_input_slot);
            return true;
        }
        else
        {
            delete reply;
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool ModbusTCP::modbus_write_coils(quint8 slaveId, quint16 writeStartAddr, quint16 writeNum, QVector<quint16> writeValue)
{
    if (modbusClient->state() != QModbusDevice::ConnectedState)
        return false;
    QModbusDataUnit writeDataUnit;
    writeDataUnit.setRegisterType(QModbusDataUnit::DiscreteInputs);
    writeDataUnit.setStartAddress(writeStartAddr);
    writeDataUnit.setValueCount(writeNum);
    writeDataUnit.setValues(writeValue);
    if (auto* reply = modbusClient->sendWriteRequest(writeDataUnit, slaveId))
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, &ModbusTCP::writeready_coil_slot);
            return true;
        }
        else
        {
            if (reply != nullptr)
                reply->deleteLater();
            return false;
        }
    }
    else
    {
        return false;
    }
    return false;
}
bool ModbusTCP::modbus_write_holding(quint8 slaveId, quint16 writeStartAddr, quint16 writeNum, QVector<quint16> writeValue)
{
    if (modbusClient->state() != QModbusDevice::ConnectedState)
        return false;
    QModbusDataUnit writeDataUnit;
    writeDataUnit.setRegisterType(QModbusDataUnit::HoldingRegisters);
    writeDataUnit.setStartAddress(writeStartAddr);
    writeDataUnit.setValueCount(writeNum);
    writeDataUnit.setValues(writeValue);

    if (auto* reply = modbusClient->sendWriteRequest(writeDataUnit, slaveId))
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, &ModbusTCP::writeready_holding_slot);
            return true;
        }
        else
        {
            if (reply != nullptr)
                reply->deleteLater();
            return false;
        }
    }
    else
    {
        return false;
    }
    return false;
}
bool ModbusTCP::modbus_write_input(quint8 slaveId, quint16 writeStartAddr, quint16 writeNum, QVector<quint16> writeValue)
{
    if (modbusClient->state() != QModbusDevice::ConnectedState)
        return false;
    QModbusDataUnit writeDataUnit;
    writeDataUnit.setRegisterType(QModbusDataUnit::InputRegisters);
    writeDataUnit.setStartAddress(writeStartAddr);
    writeDataUnit.setValueCount(writeNum);
    writeDataUnit.setValues(writeValue);

    if (auto* reply = modbusClient->sendWriteRequest(writeDataUnit, slaveId))
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, &ModbusTCP::writeready_holding_slot);
            return true;
        }
        else
        {
            if (reply != nullptr)
                reply->deleteLater();
            return false;
        }
    }
    else
    {
        return false;
    }
    return false;
}


void ModbusTCP::state_change_slot(QModbusDevice::State state)
{
    emit modbus_state_change_signal(state);
}

void ModbusTCP::error_occurred_slot(QModbusDevice::Error error)
{
    emit modbus_error_occurred_signal(error);
}
void ModbusTCP::readready_coils_slot()
{
    QModbusReply* reply = qobject_cast<QModbusReply*>(sender());
    if (!reply)
    {
        emit modbus_read_over_signal(QModbusDataUnit::RegisterType::Coils, true, this->readCoilVal);
        return;
    }
    if (reply->error() == QModbusDevice::NoError)
    {
        const QModbusDataUnit unit = reply->result();
        //readCoilVal = unit.values();
        for (uint16_t i = 0; i < unit.valueCount(); )
        {
            readCoilVal.push_back(unit.value(i));
            i++;
        }
        emit modbus_read_over_signal(QModbusDataUnit::RegisterType::Coils, false, this->readCoilVal);
    }
    else
    {
        qDebug() << "coil read error:" << reply->error();
        emit modbus_read_over_signal(QModbusDataUnit::RegisterType::Coils, true, this->readCoilVal);
    }
    if (reply != nullptr)
        reply->deleteLater();
}
void ModbusTCP::readready_holding_slot()
{
    QModbusReply* reply = qobject_cast<QModbusReply*>(sender());
    QVector<quint16> vAllData;
    if (!reply)
    {
        emit modbus_read_over_signal(QModbusDataUnit::RegisterType::HoldingRegisters, true, this->readHoldingVal);
        return;
    }
    if (reply->error() == QModbusDevice::NoError)
    {
        const QModbusDataUnit unit = reply->result();
        vAllData = unit.values();
        for (uint16_t i = 0; i < unit.valueCount(); )
        {
            readCoilVal.push_back(unit.value(i));
            i++;
        }
        emit modbus_read_holding_unit(unit);
      //  emit modbus_read_over_signal(QModbusDataUnit::RegisterType::HoldingRegisters, false, this->readHoldingVal);.

    }
    else
    {
        qDebug() << "holding read error:" << reply->error();
        emit modbus_read_over_signal(QModbusDataUnit::RegisterType::HoldingRegisters, true, this->readHoldingVal);
    }
    if (reply != nullptr)
        reply->deleteLater();
}
void ModbusTCP::readready_input_slot()
{
    QModbusReply* reply = qobject_cast<QModbusReply*>(sender());
    if (!reply)
    {
        emit modbus_read_over_signal(QModbusDataUnit::RegisterType::InputRegisters, true, this->readInputVal);
        return;
    }
    if (reply->error() == QModbusDevice::NoError)
    {
        const QModbusDataUnit unit = reply->result();
      //  readInputVal = unit.values();
        for (uint16_t i = 0; i < unit.valueCount(); )
        {
            readInputVal.push_back(unit.value(i));
            i++;
        }
        emit modbus_read_input_unit(unit);
        emit modbus_read_over_signal(QModbusDataUnit::RegisterType::InputRegisters, false, this->readInputVal);
    }
    else
    {
        qDebug() << "input read error:" << reply->error();
        emit modbus_read_over_signal(QModbusDataUnit::RegisterType::InputRegisters, true, this->readInputVal);
    }
    if (reply != nullptr)
        reply->deleteLater();
}
void ModbusTCP::readready_discrete_slot()
{
    QModbusReply* reply = qobject_cast<QModbusReply*>(sender());
    if (!reply)
    {
        emit modbus_read_over_signal(QModbusDataUnit::RegisterType::DiscreteInputs, true, this->readDiscreteVal);
        return;
    }
    if (reply->error() == QModbusDevice::NoError)
    {
        const QModbusDataUnit unit = reply->result();
       // readDiscreteVal = unit.values();
        for (uint16_t i = 0; i < unit.valueCount(); )
        {
            readDiscreteVal.push_back(unit.value(i));
            i++;
        }
        emit modbus_read_over_signal(QModbusDataUnit::RegisterType::DiscreteInputs, false, this->readDiscreteVal);
    }
    else
    {
        qDebug() << "discrete read error:" << reply->error();
        emit modbus_read_over_signal(QModbusDataUnit::RegisterType::DiscreteInputs, true, this->readDiscreteVal);
    }
    if (reply != nullptr)
        reply->deleteLater();
}
void ModbusTCP::writeready_coil_slot()
{
    QModbusReply* reply = qobject_cast<QModbusReply*>(sender());
    if (!reply)
    {
        emit modbus_write_res(QModbusDataUnit::RegisterType::Coils, true);
        return;
    }
    if (reply->error() == QModbusDevice::NoError)
    {
        emit modbus_write_res(QModbusDataUnit::RegisterType::Coils, false);
    }
    else
    {
        qDebug() << "write holding error:" << reply->errorString() << "    " << reply->rawResult().exceptionCode();
        emit modbus_write_res(QModbusDataUnit::RegisterType::Coils, true);
    }
    if (reply != nullptr)
        reply->deleteLater();
}
void ModbusTCP::writeready_holding_slot()
{
    QModbusReply* reply = qobject_cast<QModbusReply*>(sender());
    if (!reply)
    {
        emit modbus_write_res(QModbusDataUnit::RegisterType::Coils, true);
        return;
    }
    if (reply->error() == QModbusDevice::NoError)
    {
        emit modbus_write_res(QModbusDataUnit::RegisterType::HoldingRegisters, false);
    }
    else
    {
        qDebug() << "write holding error:" << reply->errorString() << "    " << reply->rawResult().exceptionCode();
        emit modbus_write_res(QModbusDataUnit::RegisterType::HoldingRegisters, true);
    }
    if (reply != nullptr)
        reply->deleteLater();
}

void ModbusTCP::writeready_input_slot()
{
    QModbusReply* reply = qobject_cast<QModbusReply*>(sender());
    if (!reply)
    {
        emit modbus_write_res(QModbusDataUnit::RegisterType::InputRegisters, true);
        return;
    }
    if (reply->error() == QModbusDevice::NoError)
    {
        emit modbus_write_res(QModbusDataUnit::RegisterType::InputRegisters, false);
    }
    else
    {
        qDebug() << "write holding error:" << reply->errorString() << "    " << reply->rawResult().exceptionCode();
        emit modbus_write_res(QModbusDataUnit::RegisterType::HoldingRegisters, true);
    }
    if (reply != nullptr)
        reply->deleteLater();
}