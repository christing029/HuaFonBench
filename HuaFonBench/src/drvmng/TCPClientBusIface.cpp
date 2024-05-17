#include "TCPClientBusIface.h"
TCPClientBusIface::TCPClientBusIface(QString IP, int32_t Port) :CommonIface(NULL)
{
	ip = IP;
	port = Port;
	tcpsocket = new QTcpSocket(this);
	tcpsocket->setSocketOption(QAbstractSocket::LowDelayOption,0);
	tcpsocket->setSocketOption(QAbstractSocket::KeepAliveOption, 1);
	tcpsocket->setSocketOption(QAbstractSocket::SendBufferSizeSocketOption, 128);
	//绑定客户端的连接信号与槽，便于在槽函数中书写逻辑
	connect(tcpsocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(slot_stateChanged(QAbstractSocket::SocketState)));
	connect(tcpsocket, SIGNAL(readyRead()), this, SLOT(slot_ReadData()));
	ota_mbtcp_cmd.mbap_header.TransactionID = 0;
}

TCPClientBusIface::TCPClientBusIface(QObject* parent)
	: CommonIface(parent)
{
	//tcpsocket = new QTcpSocket();
}

TCPClientBusIface::~TCPClientBusIface()
{

}
bool TCPClientBusIface::open()
{
	if (tcpsocket->state() == QAbstractSocket::UnconnectedState)
	{
		tcpsocket->connectToHost(ip, port);
		if (tcpsocket->waitForConnected(1000))
		{
			return true;
		}
		return false;
	}
	return true;
}

void TCPClientBusIface::write(QByteArray& data)
{
	tcpsocket->setSocketOption(QAbstractSocket::LowDelayOption, 1);
	//tcpsocket->setSocketOption(QAbstractSocket::KeepAliveOption, 1);
	//tcpsocket->setSocketOption(QAbstractSocket::SendBufferSizeSocketOption, 200);
	qint64 	len= tcpsocket->write(data);
	          tcpsocket->flush();
	qDebug() <<  "发送长度为：" << QString::number(len, 10);
}

void TCPClientBusIface::close()
{
	tcpsocket->disconnectFromHost();
	tcpsocket->close();
	tcpsocket = NULL;
}

QByteArray TCPClientBusIface::read()
{

	return  tcpsocket->readAll();
}

bool TCPClientBusIface::readCheck(QByteArray arr)
{
	return true;
}

QByteArray TCPClientBusIface::ota_update_request(uint8_t serverAddress)
{
	QByteArray byteArray;

	ota_mbtcp_cmd.mbap_header.TransactionID++;
	ota_mbtcp_cmd.mbap_header.ProtocolID = 0;
	ota_mbtcp_cmd.mbap_header.UnitID = serverAddress;
	ota_mbtcp_cmd.mbap_header.Length = 3;
	ota_mbtcp_cmd.FunCode = OTA_FunCode;
	ota_mbtcp_cmd.CmdCode = _OTA_CmdCode_Request;
	byteArray.append(reinterpret_cast<char*>(&ota_mbtcp_cmd), sizeof(OTA_MBAP_Cmd));
	return byteArray;
}

QByteArray TCPClientBusIface::ota_version_snd(uint8_t serverAddress, OTA_File_Head file_head)
{
	QByteArray byteArray;

	ota_mbtcp_cmd.mbap_header.TransactionID++;
	ota_mbtcp_cmd.mbap_header.ProtocolID = 0;
	ota_mbtcp_cmd.mbap_header.UnitID = serverAddress;
	ota_mbtcp_cmd.mbap_header.Length = 3+ sizeof(file_head);
	ota_mbtcp_cmd.FunCode = OTA_FunCode;
	ota_mbtcp_cmd.CmdCode = _OTA_CmdCode_Version;
	byteArray.append(reinterpret_cast<char*>(&ota_mbtcp_cmd), sizeof(OTA_MBAP_Cmd));
	byteArray.append(reinterpret_cast<char*>(&file_head), sizeof(OTA_File_Head));
	return byteArray;

}


QByteArray TCPClientBusIface::ota_version_get(uint8_t serverAddress)
{
	QByteArray byteArray;
	ota_mbtcp_cmd.mbap_header.TransactionID++;
	ota_mbtcp_cmd.mbap_header.ProtocolID = 0;
	ota_mbtcp_cmd.mbap_header.UnitID = serverAddress;
	ota_mbtcp_cmd.mbap_header.Length = 3;
	ota_mbtcp_cmd.FunCode = OTA_FunCode;
	ota_mbtcp_cmd.CmdCode = _OTA_ComCode_VersionGet;
	byteArray.append(reinterpret_cast<char*>(&ota_mbtcp_cmd), sizeof(OTA_MBAP_Cmd));
	return byteArray;


}

QByteArray TCPClientBusIface::ota_commite_request(uint8_t serverAddress, uint16_t file_crc)
{
	QByteArray byteArray;
	ota_mbtcp_cmd.mbap_header.TransactionID++;
	ota_mbtcp_cmd.mbap_header.ProtocolID = 0;
	ota_mbtcp_cmd.mbap_header.UnitID = serverAddress;
	ota_mbtcp_cmd.mbap_header.Length = 3+sizeof(uint16_t);
	ota_mbtcp_cmd.FunCode = OTA_FunCode;
	ota_mbtcp_cmd.CmdCode = _OTA_CmdCode_Start;
	byteArray.append(reinterpret_cast<char*>(&ota_mbtcp_cmd), sizeof(OTA_MBAP_Cmd));
	file_crc = file_crc >> 8 | file_crc << 8;
	byteArray.append(reinterpret_cast<char*>(&file_crc), sizeof(uint16_t));
	return byteArray;
}

QByteArray TCPClientBusIface::ota_complete_request(uint8_t serverAddress)
{
	return QByteArray();
}

QByteArray TCPClientBusIface::data_ota_download(uint8_t serverAddress)
{
	return QByteArray();
}

QByteArray TCPClientBusIface::writeDatagram(uint8_t serverAddress, uint16_t DataNo, char* tx_buf, int Len)
{
	QByteArray byteArray;
	ota_mbtcp_cmd.mbap_header.TransactionID++;
	ota_mbtcp_cmd.mbap_header.ProtocolID = 0;
	ota_mbtcp_cmd.mbap_header.UnitID = serverAddress;
	ota_mbtcp_cmd.mbap_header.Length = 3+ Len;
	ota_mbtcp_cmd.FunCode = OTA_FunCode;
	ota_mbtcp_cmd.CmdCode = _OTA_CmdCode_Data;
	byteArray.append(reinterpret_cast<char*>(&ota_mbtcp_cmd), sizeof(OTA_MBAP_Cmd));
	byteArray.append(reinterpret_cast<char*>(&DataNo), sizeof(uint16_t));
	byteArray.append(reinterpret_cast<char*>(tx_buf), Len);

	return byteArray;
}

OTA_Data_Head TCPClientBusIface::readDataCmd(QByteArray arr)
{
	OTA_Data_Head msg;
	OTA_MBAP_Cmd* mbap = (OTA_MBAP_Cmd*)arr.data();
	msg.serverAddress = mbap->mbap_header.UnitID;
	msg.FunCode = mbap->FunCode;
	msg.CmdCode = mbap->CmdCode;
	return msg;
}

QByteArray TCPClientBusIface::mb_additional_overlength_requeset(uint16_t serverAddress, uint16_t regNum)
{

	QByteArray byteArray;

	hf_cmd.mbap_header.TransactionID++;
	hf_cmd.mbap_header.ProtocolID = 0;
	hf_cmd.mbap_header.UnitID = 1;
	hf_cmd.mbap_header.Length = 4 + sizeof(uint16_t);
	hf_cmd.FunCode = OVERLENGTH_FunCode;
	hf_cmd.StartAddress_H = (serverAddress>>8)&0xff;
	hf_cmd.StartAddress_L = serverAddress&0xff;
	hf_cmd.RegNum_H = (regNum >> 8) & 0xff;
	hf_cmd.RegNum_L = regNum & 0xff;
	byteArray.append(reinterpret_cast<char*>(&hf_cmd), sizeof(HF_Modbus_TCP_Cmd));
	write(byteArray);
	return byteArray;
}



void TCPClientBusIface::slot_ReadData()
{
	emit signalUpMsg();
}

void TCPClientBusIface::connectSucc()
{

}

void TCPClientBusIface::slot_stateChanged(QAbstractSocket::SocketState stat)
{
	emit signalstateChanged(stat);
    tcpstat = stat;
}