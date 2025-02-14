#include "can.h"
#include <QThread>
#include <QModbusTcpClient>
Thread::Thread()//构造函数//初始化变量
{
	QLibrary lib("ECanVci64.dll");
	if (true == lib.load())
		qDebug() << "ECanVci64.dll load ok";
	pOpenDevice = (OpenDevice*)lib.resolve("OpenDevice");
	pCloseDevice = (CloseDevice*)lib.resolve("CloseDevice");
	pInitCAN = (InitCAN*)lib.resolve("InitCAN");
	pStartCAN = (StartCAN*)lib.resolve("StartCAN");
	pTransmitCAN = (Transmit*)lib.resolve("Transmit");
	pReceive = (Receive*)lib.resolve("Receive");
	pGetReceiveNum = (GetReceiveNum*)lib.resolve("GetReceiveNum");
	pClearBuffer = (ClearBuffer*)lib.resolve("ClearBuffer");
	pReadErrInfoCAN = (ReadErrInfo*)lib.resolve("ReadErrInfo");
	pResetCAN = (ResetCAN*)lib.resolve("ResetCAN");
	pSetReference = (SetReference*)lib.resolve("SetReference");
	pReadBoardInfo = (ReadBoardInfo*)lib.resolve("ReadBoardInfo");
	pReadCANStatus = (ReadCANStatus*)lib.resolve("ReadCANStatus");
}
Thread::~Thread()
{
	stopped = true;
	stop();
	this->deleteLater();
}
void Thread::run()
{
	if (IsOpenFlag == true)
	{
		while (!stopped)//死循环//
		{
			pause_mutex.lock();
			ReceiveCANThread();//接收数据
			msleep(100);
			pause_mutex.unlock();
		}
		stopped = false;
	}
}

void Thread::stop()
{
	stopped = true;
}

void Thread::Reset()
{
	pResetCAN(devtype, devind, canind);
	stopped = false;
}
void Thread::TestCanRec()
{
	StandFrame_Data  rec_standard_data;
	rec_standard_data.FrameId = 0x101100A1;
	rec_standard_data.Data[0] = 0xff;
	rec_standard_data.Data[1] = 0x0;
	rec_standard_data.Data[2] = 0x1;
	rec_standard_data.Data[3] = 0x2;
	rec_standard_data.Data[4] = 0x3;
	rec_standard_data.Data[5] = 0x5;
	rec_standard_data.Data[6] = 0x6;
	rec_standard_data.Data[7] = 0x8;
	QByteArray byteArray;
	byteArray.append(reinterpret_cast<char*>(&rec_standard_data), sizeof(StandFrame_Data));
	//	StandFrame_Data* getMsg = (StandFrame_Data*)byteArray.data();
	RecStandFrame_signal("CanRec", byteArray);
}

void Thread::ReceiveCANThread()//接收数据线程
{

	StandFrame_Data  rec_standard_data;
	bool ok;
	ERR_INFO vei;
	CAN_OBJ preceive[1000];
	CAN_OBJ psend;
	//    int baud=0x10000000;//参数有关数据缓冲区地址首指针
		//接收
	ULONG res = 10;
	res = pReceive(devtype, devind, canind, preceive, 50, 0);
	if (res == 0)
	{
		if (pReadErrInfoCAN(devtype, devind, canind, &vei) != STATUS_ERR)
		{
			if (vei.ErrCode != 0)
			{
				IsOpenFlag = false;
				qDebug() << "读取数据失败!" << "错误码为：" << QString::number(vei.ErrCode, 16);
			//	emit RecStandFrame_signal("CanDisCnn", 0);
			}
			else
			{
			//	pResetCAN(devtype, devind, canind);
				//sleep(1000);
			}
		}
	}

	//qDebug()<<"读取帧数："<<res;
	for (int i = 0; i < res; i++)
	{
		if (res == 4294967295)
		{
			if (pReadErrInfoCAN(devtype, devind, canind, &vei) != STATUS_ERR)
			{
				// qDebug()<<"读取数据失败!"<<"错误码为："<<QString::number(vei.ErrCode,16);
			}
		}
		QString receive_str = "接收";
		mrec++;
		receive_str.append(QString::number(mrec, 16));
		// receive_str.append("帧ID:");
		receive_str.append(QString::number(preceive[i].ID, 16));
		rec_standard_data.FrameId = preceive[i].ID;
		//   receive_str.append("    数据：");
		for (int a = 0; a < preceive[i].DataLen; a++)
		{
			rec_standard_data.Data[a] = preceive[i].Data[a];
		//	CanrecData[a] = preceive[a].Data[a];
			receive_str.append(QString::number(preceive[i].Data[a], 16));
			receive_str.append(" ");
		}
	//	emit my_signal(receive_str);//子线程处理完毕//触发自定义的信号
	//	emit RecStandFrame_signal(receive_str);//子线程处理完毕//触发自定义的信号
		QByteArray byteArray;
		byteArray.append(reinterpret_cast<char*>(&rec_standard_data), sizeof(StandFrame_Data));
	//	StandFrame_Data* getMsg = (StandFrame_Data*)byteArray.data();
		RecStandFrame_signal("CanRec", byteArray);
	}//for
	msleep(100);
}

void Thread::TransmitCANThread(unsigned int id, unsigned char* ch, bool EXT, bool RTR, unsigned int len)//发送数据线程
{
	CAN_OBJ psend;
	//发送
	ULONG Tr;
	psend.ID = id;//ID号//需要实际填写//
	psend.SendType = 0;
	psend.RemoteFlag = RTR;
	psend.ExternFlag = EXT;
	psend.DataLen = len;
	for (int i = 0; i < len; i++)
	{
		psend.Data[i] = ch[i];
	}
	Tr = pTransmitCAN(devtype, devind, canind, &psend, 1);//返回实际发送的帧数
   //devtype设备类型号//devind设备索引号//canind第几路CAN//&psend要发送的数据帧数组的首指针//1要发送的数据帧数组的长度//
	if (Tr != STATUS_ERR) {
	}
}

void Thread::OpenCANThread(byte baud, int id)//打开设备
{
	mrec = 0;
	bool ok;
	ERR_INFO vei;
	CAN_OBJ preceive[1000];
	//    CAN_OBJ psend;
	//    int baud=0x10000000;//参数有关数据缓冲区地址首指针
	//      int pdata=0x00;//参数有关数据缓冲区地址首指针
	   //打开设备
	canind = id;
	if (pOpenDevice(devtype, devind, res) == STATUS_ERR)//为1表示操作成功，0表示操作失败。
	{
		QThread::msleep(500);
		if (pReadErrInfoCAN(devtype, devind, canind, &vei) != STATUS_ERR)
		{
			    qDebug()<<"打开失败："<<QString::number(vei.ErrCode,16);
		}
		IsOpenFlag = false;
		return;
	}
	else
	{
		IsOpenFlag = true;
		//  qDebug()<<"open successed";
	}
	//初始化
	INIT_CONFIG init_config;//INIT_CONFIG
	//init_config.Mode=0;//0正常模式//1为只听模式//2为自发自收模式//
	init_config.Filter = 0;//滤波方式，单滤波
	switch (baud)
	{
	case 0: //1000

		init_config.Timing0 = 0;
		init_config.Timing1 = 0x14;
		break;
	case 1: //800

		init_config.Timing0 = 0;
		init_config.Timing1 = 0x16;
		break;
	case 2: //666

		init_config.Timing0 = 0x80;
		init_config.Timing1 = 0xb6;
		break;
	case 3: //500

		init_config.Timing0 = 0;
		init_config.Timing1 = 0x1c;
		break;
	case 4://400

		init_config.Timing0 = 0x80;
		init_config.Timing1 = 0xfa;
		break;
	case 5://250

		init_config.Timing0 = 0x01;
		init_config.Timing1 = 0x1c;
		break;
	case 6://200

		init_config.Timing0 = 0x81;
		init_config.Timing1 = 0xfa;
		break;
	case 7://125

		init_config.Timing0 = 0x03;
		init_config.Timing1 = 0x1c;
		break;
	case 8://100

		init_config.Timing0 = 0x04;
		init_config.Timing1 = 0x1c;
		break;
	case 9://80

		init_config.Timing0 = 0x83;
		init_config.Timing1 = 0xff;
		break;
	case 10://50

		init_config.Timing0 = 0x09;
		init_config.Timing1 = 0x1c;
		break;
	}

	init_config.AccCode = 0x000000;//验收码
	init_config.AccMask = 0xFFFFFF;//屏蔽码
	QThread::msleep(100);
	if (pInitCAN(devtype, devind, canind, &init_config) == STATUS_ERR)
	{
		IsOpenFlag = false;
		qDebug("Init Error");
		pCloseDevice(devtype, devind);
		return;
	}
	else
	{
		//qDebug()<<"Init successed";
		//qDebug()<<"定时器0："<<init_config.Timing0;
		//qDebug()<<"定时器1："<<init_config.Timing1;
	}

	if (pStartCAN(devtype, devind, canind) == STATUS_ERR) {
		qDebug() << "start fail";
		pCloseDevice(devtype, devind);
		IsOpenFlag = false;
		return;
	}
	else
	{
		qDebug() << "start successed";
		IsOpenFlag = true;
	}
}

void Thread::CloseCANThread()
{
	pCloseDevice(devtype, devind);
	IsOpenFlag = false;
	qDebug() << "closed";
}