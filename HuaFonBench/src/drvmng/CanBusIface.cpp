#include "CanBusIface.h"

CanBusIface::CanBusIface(QString IP, int32_t Port) :CommonIface(NULL)
{
	mEXT = 1; // 1:扩展
	MyCANControlThread = new Thread; //定义类对象// MyCANControlThread//就是分配内存空间
	connect(MyCANControlThread, SIGNAL(RecStandFrame_signal(QString, QByteArray)), this, SLOT(deal_can_rec(QString, QByteArray)));
}
CanBusIface::CanBusIface(QObject* parent)
	: CommonIface(parent)
{
	//MyCANControlThread = new Thread; //定义类对象// MyCANControlThread//就是分配内存空间
	//connect(MyCANControlThread, SIGNAL(RecStandFrame_signal(QString, QByteArray)), this, SLOT(deal_can_rec(QString, QByteArray)));
}

CanBusIface::~CanBusIface()
{

}

bool CanBusIface::open()
{
	mbaud = 3;
	MyCANControlThread->Reset();
	MyCANControlThread->OpenCANThread(mbaud,0);
	MyCANControlThread->start();//启动子线程//间接调用了run()函数//即接收数据
	if (MyCANControlThread->isRunning())
	{
		MyCANControlThread->IsOpenFlag = true;
	}
	if (false == MyCANControlThread->IsOpenFlag)//启动设备失败
	{
		MyCANControlThread->Reset();
		mconnect = false;
	}
	else//启动设备成功
	{
		mconnect = true;
	}
	return mconnect;
}

void CanBusIface::write(QByteArray& data)
{
	//QByteArray byteArray;
	//can_frame_t *snddata  = (can_frame_t*)data.data();
	// MyCANControlThread->TransmitCANThread(snddata->canId, (unsigned char*)snddata->data, mEXT, 0, 8);
}




void CanBusIface::close()
{
}

bool CanBusIface::readCheck(QByteArray arr)
{
	bool rc = false;
	can_frame_t* canfram = (can_frame_t*)arr.data();
	if ((canfram->canId& 0x1800e200) != 0x1800e200)
	{
		return rc;
	}
	can_sf_frame2_t type;
	type.All = canfram->data[0];
	switch (type.Bits.type)
	{
	case CAN_SF:
		rc = true;
		break;
	case CAN_FF:
		rc = true;
		break;
	case CAN_CF:
		rc = true;
		break;
	case CAN_FC:
		rc = true;
		break;
	default:
		rc= false;
		break;
	}
	return rc;
}

QByteArray CanBusIface::ota_update_request(uint8_t serverAddress)
{
	QByteArray byteArray ;
	 DstdevId = serverAddress;
	 can_ota_update_request_t pMess;
	 pMess.Cmd = _OTA_CmdCode_Request;
	 can_multi_frame_sendFrame(CAN_OTA_CMD_ID | (DstdevId << 8) | SRC_DEVID, (uint8_t*)&pMess,sizeof(can_ota_update_request_t));
	 byteArray.append(reinterpret_cast<char*>(&pMess), sizeof(can_ota_update_request_t));
	 return byteArray ;
}

QByteArray CanBusIface::ota_version_snd(uint8_t serverAddress, OTA_File_Head file_head)
{
	QByteArray byteArray;
	can_ota_version_snd_t pMess;
	pMess.Cmd = _OTA_CmdCode_Version;
	memcpy(&pMess.file_head, &file_head, sizeof(OTA_File_Head));
	DstdevId = serverAddress;
	can_multi_frame_sendFrame(CAN_OTA_CMD_ID | (DstdevId << 8) | SRC_DEVID, (uint8_t*)&pMess, sizeof(can_ota_version_snd_t));
	byteArray.append(reinterpret_cast<char*>(&pMess), sizeof(can_ota_version_snd_t));
	return byteArray;
}

QByteArray CanBusIface::ota_version_get(uint8_t serverAddress)
{
	QByteArray byteArray;
	DstdevId = serverAddress;
	can_ota_version_get_t pMess;
	pMess.Cmd = _OTA_ComCode_VersionGet;
	can_multi_frame_sendFrame(CAN_OTA_CMD_ID | (DstdevId << 8) | SRC_DEVID, (uint8_t*)&pMess, sizeof(can_ota_version_get_t));
	byteArray.append(reinterpret_cast<char*>(&pMess), sizeof(can_ota_version_get_t));
	return byteArray;
}

QByteArray CanBusIface::ota_commite_request(uint8_t serverAddress, uint16_t file_crc)
{
	return QByteArray();
}

QByteArray CanBusIface::ota_complete_request(uint8_t serverAddress)
{
	return QByteArray();
}

QByteArray CanBusIface::data_ota_download(uint8_t serverAddress)
{
	return QByteArray();
}

QByteArray CanBusIface::writeDatagram(uint8_t serverAddress, uint16_t DataNo, char* tx_buf, int Len)
{

	QByteArray byteArray;
	can_ota_write_data_t pMess;
	uint8_t* pData;

	pMess.Cmd = _OTA_CmdCode_Data;
	pMess.DataNo = DataNo;
	memcpy(&pMess.data[0], tx_buf, Len);
	//DstdevId = serverAddress;
	//malloc
	can_multi_frame_sendFrame(CAN_OTA_CMD_ID | (DstdevId << 8) | SRC_DEVID, (uint8_t*)&pMess, Len +3);
	byteArray.append(reinterpret_cast<char*>(&pMess), sizeof(can_ota_version_snd_t));
	return byteArray;

}

OTA_Data_Head CanBusIface::readDataCmd(QByteArray arr)
{
	OTA_Data_Head msg;
	can_frame_t* canfram = (can_frame_t*)arr.data();
	can_sf_frame2_t type;
	type.All = canfram->data[0];
	msg.serverAddress = canfram->canId & 0xff;
	switch (type.Bits.type)
	{
	case CAN_SF:
		msg.FunCode = OTA_FunCode;
		msg.CmdCode = canfram->data[1];
		break;
	case CAN_FF:
		msg.FunCode = OTA_FunCode;
		msg.CmdCode = canfram->data[1];
		break;
	case CAN_CF:
		msg.FunCode = OTA_FunCode;
		msg.CmdCode = canfram->data[1];
		break;
	case CAN_FC:
		msg.FunCode = OTA_FunCode;
		msg.CmdCode = canfram->data[1];
		break;
	default:
		break;
	}
	return msg;
}
void CanBusIface::can_sendSingleFrame(uint32_t can_id, uint8_t* data, uint8_t len)
{
	uint8_t message[8] = { 0 };
	can_sf_frame_t* pMess = (can_sf_frame_t*)message;
	pMess->type = CAN_SF;
	pMess->len = len;
	memcpy(&message[1], data, len);
	MyCANControlThread->TransmitCANThread(can_id, (unsigned char*)message, mEXT, 0, len + 1);
//	can_send_transparent_data(can_id, message, len + 1);
}
void CanBusIface::can_send_FF_Frame(uint32_t can_id, uint8_t* data, uint32_t len)
{
	uint8_t message[8] = { 0 };
	can_ff_frame_t* pMess = (can_ff_frame_t*)message;

	pMess->type = CAN_FF;
	pMess->len_h = len >> 8;
	pMess->len_l = len % 0xff;
	memcpy(pMess->data, data, 6);
	MyCANControlThread->TransmitCANThread(can_id, (unsigned char*)message, mEXT, 0, 8);
	//can_send_transparent_data(can_id, message, 8);
}
void CanBusIface::can_send_CF_Frame(uint32_t can_id, uint8_t packno, uint8_t* data, uint8_t len)
{
	uint8_t message[8] = { 0 };
	can_cf_frame_t* pMess = (can_cf_frame_t*)message;

	pMess->type = CAN_CF;
	pMess->packno = packno & 0x0F;
	memcpy(pMess->data, data, len);
	MyCANControlThread->TransmitCANThread(can_id, (unsigned char*)message, mEXT, 0, len + 1);
	//can_send_transparent_data(can_id, message, len + 1);
}

/* 以ISO15765-2 单帧和多帧发送 */
void CanBusIface::can_multi_frame_sendFrame(uint32_t can_id, uint8_t* data, uint32_t len)
{
	uint32_t offset = 0;
	uint8_t packno = 1;
	uint8_t numBytesToSend = 0;
	if (len < 8) {
		can_sendSingleFrame(can_id, data, len);
	}
	else {
		can_send_FF_Frame(can_id, data, len);
		for (offset = 6; offset < len; offset += 7) {
			if (len > offset + 7) {
				numBytesToSend = 7;
			}
			else {
				numBytesToSend = len - offset;
			}
			Thread::msleep(10);
			can_send_CF_Frame(can_id, packno, data + offset, numBytesToSend);
			packno++;
		}
	}
}

QByteArray CanBusIface::read()
{
	return  Recdata;
}



void CanBusIface::deal_can_rec(QString str, QByteArray data)
{
	emit signalUpMsg();
	if (str == "CanRec")
	{
		Recdata= data;
		return;
	}

}