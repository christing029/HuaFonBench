#pragma once

#include <QObject>

class SlaveDataCanCmm : public QObject
{
	Q_OBJECT
    typedef struct
	{
		uint16_t  BatVols[48];
		int16_t	  BatTemps[24];
		uint16_t  BatTotalVolt;
		int16_t   BatCurrent;
		uint8_t   RelayStatus;
		uint8_t   SignalStatus;
		uint8_t   ErrTempCount;
		uint8_t   ErrVolCount;
		uint8_t   SWVersion;
		uint8_t   HWVersion;
		uint32_t  BalancePosition;
		uint8_t   DataReady;
	} PackInfoST;

	/// <summary>
	/// 
	/// </summary>
	enum CAN_SLAVE_SET_ID
	{
		CAN_SLAVE_SET_SLAVEID = 0x200,       //从机设置编号及机号ID
		CAN_SLAVE_SET_VOLT_TEMP = 0x201,//单次
		CAN_SLAVE_GET_CMD = 0x202,      //从机参数读取 
		CAN_SLAVE_GETACK_INFO = 0x203,  //从机返回参数信息
	};
	/// <summary>
	/// 从机设置的参数类型
	/// </summary>
	enum CAN_SLAVE_SET_TYPE
	{
		CAN_SLAVE_SET_ID = 0x200,       //从机设置编号及机号ID
		CAN_SLAVE_SET_PARAMETER = 0x201,//从机设置-电压温度跳节及采样补偿
		CAN_SLAVE_GET_PARAMETER_CMD = 0x202,      //从机参数读取 
		CAN_SLAVE_GET_PARAMETER_INFO = 0x203,  //从机返回参数信息
	};
	typedef struct
	{
		uint8_t   Type;//设置类型0x01
		uint8_t	  SlaveID_1;//从机编号1
		uint8_t  SlaveID_2;
		uint8_t   SlaveID_3;
		uint8_t   SlaveID_4;
		uint8_t   Bak1;
		uint8_t   Bak2;
		uint8_t   Bak3;
	} CAN_SLAVE_SET_ID_T;

	typedef struct
	{
		uint8_t  Type;//1：电压跳节；2：温度跳节；3：电压补偿；4：温度补偿。
		uint8_t	 SlaveID_1;//从机编号1
		uint8_t  Formate; //参数格式
		uint8_t  Val[4];
		uint8_t  Bak;
	} CAN_SLAVE_SET_PARAMETER_T;


	//主控发送从机的广播帧,从机定时器设定进行应答。
#define  Master_To_Slave_BroadCast (0x100)

public:
	SlaveDataCanCmm(QObject* parent);
	~SlaveDataCanCmm();

private:
	void M2SBroadCast_Req();

};
