#include "ModbusPoll.h"
#include "QTimer"
#include "QDebug"
ModbusPoll::ModbusPoll(QObject *parent)
	: QObject(parent)
{
	QTimer* mstimer = new QTimer(this);

    mstimer = new QTimer(this);
    mstimer->stop();//…Ë÷√∂® ±∆˜1000ms;
    connect(mstimer, SIGNAL(timeout()), this, SLOT(timer1000ms()));
    //connect(mstimer, SIGNAL(timeout()), this,SLOT(timer100ms()));
     m_tcpModbus=  modbus_new_tcp("192.168.2.241",9030);

    if (modbus_connect(m_tcpModbus) == -1)
    {
      //  emit connectionError(tr("Could not connect to TCP/IP port!"));
        releaseTcpModbus();
		m_tcpActive = false;
    }
	else
	{
		m_tcpActive = true;
	}
  //  modbus_set_response_timeout(ctx, t_modbus.sec, t_modbus.usec);
}

ModbusPoll::~ModbusPoll()
{
}

bool ModbusPoll::tcpConnect(QString ip, quint16 port)
{
	m_tcpModbus = modbus_new_tcp(ip.toStdString().c_str(), 9030);
    if (modbus_connect(m_tcpModbus) == -1)
    {
        //emit connectionError(tr("Could not connect to TCP/IP port!"));
        releaseTcpModbus();
        m_tcpActive = false;
    }
    m_tcpActive = true;
	return m_tcpActive;
}

bool ModbusPoll::modbus_read_holding(quint8 slaveId, quint16 readStartAddr, quint16 readNum)
{
	if (!m_tcpActive)
	{
		return false;
	}
	if (m_tcpModbus == NULL)
	{
		return false;
	}
	const int slave = 1;
	const int func = MODBUS_FC_READ_HOLDING_REGISTERS;
	const int addr = 0;
	uint8_t dest[1024];
	uint16_t* dest16 = (uint16_t*)dest;
	memset(dest, 0, 1024);
	int ret = -1;
	bool is16Bit = false;
	bool writeAccess = false;
	uint8_t* data = new uint8_t[readNum];
	modbus_set_slave(m_tcpModbus, slave);
	ret = modbus_read_registers(m_tcpModbus, addr, readNum, dest16);
	is16Bit = true;
	if (ret == readNum)
	{
			QString qs_num;
			QVector<quint16>   vdata;
			for (int i = 0; i < readNum; ++i)
			{
				int data = is16Bit ? dest16[i] : dest[i];
				vdata.append(data);
			}
			qDebug() << "mb£∫" << vdata;
			//ui->regTable->resizeColumnToContents(0);
			return true;
	}
	else
	{
		QString err;

		if (ret < 0)
		{
			if (
#ifdef WIN32
				errno == WSAETIMEDOUT ||
#endif
				errno == EIO
				)
			{
				err += tr("I/O error");
				err += ": ";
				err += tr("did not receive any data from slave.");
			}
			else
			{
				err += tr("Protocol error");
				err += ": ";
				err += tr("Slave threw exception '");
				err += modbus_strerror(errno);
				err += tr("' or function not implemented.");
			}
		}
		else
		{
			err += tr("Protocol error");
			err += ": ";
			err += tr("Number of registers returned does not "
				"match number of registers requested!");
		}

		if (err.size() > 0)
			err += ": ";
	}

	return false;
}





void ModbusPoll::sendModbusRequest(void)
{
    if (!m_tcpActive)
    {
        return;
    }
    if (m_tcpModbus == NULL)
    {   
        return;
    }
    const int slave =1;
    const int func = MODBUS_FC_READ_HOLDING_REGISTERS;
    const int addr =0;
    int num = 100;
    uint8_t dest[1024];
    uint16_t* dest16 = (uint16_t*)dest;
    memset(dest, 0, 1024);
    int ret = -1;
    bool is16Bit = false;
    bool writeAccess = false;
	uint8_t* data = new uint8_t[num];
    modbus_set_slave(m_tcpModbus, slave);

	switch (func)
	{
	case MODBUS_FC_READ_COILS:
		ret = modbus_read_bits(m_tcpModbus, addr, num, dest);
		break;
	case MODBUS_FC_READ_DISCRETE_INPUTS:
		ret = modbus_read_input_bits(m_tcpModbus, addr, num, dest);
		break;
	case MODBUS_FC_READ_HOLDING_REGISTERS:
		ret = modbus_read_registers(m_tcpModbus, addr, num, dest16);
		is16Bit = true;
		break;
	case MODBUS_FC_READ_INPUT_REGISTERS:
		ret = modbus_read_input_registers(m_tcpModbus, addr, num, dest16);
		is16Bit = true;
		break;
	case MODBUS_FC_WRITE_SINGLE_COIL:

		ret = modbus_write_bits(m_tcpModbus, addr, num, data);
		writeAccess = true;
		num = 1;
		break;
	case MODBUS_FC_WRITE_SINGLE_REGISTER:
		writeAccess = true;
		num = 1;
		break;
	case MODBUS_FC_WRITE_MULTIPLE_COILS:
	{	
		ret = modbus_write_bits(m_tcpModbus, addr, num, data);
		delete[] data;
		writeAccess = true;
		break;
	}
	case MODBUS_FC_WRITE_MULTIPLE_REGISTERS:
	{
		for (int i = 0; i < num; ++i)
		{
		
		}
	//	ret = modbus_write_registers(m_tcpModbus, addr, num, data);
		delete[] data;
		writeAccess = true;
		break;
	}

	default:
		break;
	}

	if (ret == num)
	{
		if (writeAccess)
		{
	/*		m_statusText->setText(
				tr("Values successfully sent"));
			m_statusInd->setStyleSheet("background: #0b0;");
			m_statusTimer->start(2000);*/
		}
		else
		{
			
			QString qs_num;
			QVector<quint16>   vdata;
			for (int i = 0; i < num; ++i)
			{
				int data = is16Bit ? dest16[i] : dest[i];
				vdata.append(data);
			}
			qDebug() << "mb£∫" << vdata;
			//ui->regTable->resizeColumnToContents(0);
		}
	}
	else
	{
		QString err;

		if (ret < 0)
		{
			if (
#ifdef WIN32
				errno == WSAETIMEDOUT ||
#endif
				errno == EIO
				)
			{
				err += tr("I/O error");
				err += ": ";
				err += tr("did not receive any data from slave.");
			}
			else
			{
				err += tr("Protocol error");
				err += ": ";
				err += tr("Slave threw exception '");
				err += modbus_strerror(errno);
				err += tr("' or function not implemented.");
			}
		}
		else
		{
			err += tr("Protocol error");
			err += ": ";
			err += tr("Number of registers returned does not "
				"match number of registers requested!");
		}

		if (err.size() > 0)
			err += ": ";
	}
}

void ModbusPoll::releaseTcpModbus()
{
    if (m_tcpModbus)
    {
        modbus_close(m_tcpModbus);
        modbus_free(m_tcpModbus);
        m_tcpModbus = NULL;
    }
}


void ModbusPoll::timer1000ms()
{
	sendModbusRequest();

}