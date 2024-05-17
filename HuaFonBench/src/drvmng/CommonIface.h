#ifndef CommonIface_H
#define CommonIface_H

#include <QObject>
enum CORETYPE{ TypeCanBusIface , TypeEthBusIface, TypeUartBusIface};
#pragma pack(1) 
typedef   struct
{
	uint8_t serverAddress; //设备地址
	uint8_t FunCode; //功能码
	uint8_t CmdCode; //功能码
}OTA_Data_Head;

typedef   struct
{
	uint16_t TransactionID; //事务处理标识; //设备地址
	uint16_t ProtocolID; //00 00 代表modbus-Tcp
	uint16_t Length; //Unit长度 + PDU的长度
	uint8_t UnitID; //单元标识符
}MBAP_Header;

typedef   struct
{
	MBAP_Header mbap_header; //事务处理标识; //设备地址
	uint8_t FunCode; //
	uint8_t CmdCode; //
}OTA_MBAP_Cmd;



typedef   struct
{
	MBAP_Header mbap_header; //事务处理标识; //设备地址
	uint8_t FunCode; //
	uint8_t StartAddress_H; //
	uint8_t StartAddress_L; //
	uint8_t RegNum_H; //
	uint8_t RegNum_L; //
}HF_Modbus_TCP_Cmd;

typedef   struct
{
	uint8_t FactoryID[4];
	uint8_t manufacture[2];
	uint8_t hardversion[4];
	uint8_t softversion[4];
	uint32_t appSize;
}OTA_File_Head;
#pragma pack()
#define OTA_FunCode (0x31)
#define Special_FunCode (0x30)
//读大数据寄存器帧（功能码：0x41）
#define OVERLENGTH_FunCode (0x41)
#define OTA_ERR_FunCode (0xB1)
#define Special_ERR_FunCode (0xB0)

//0x01：OTA升级请求
//	0x02：OTA版本信息发送指令
//	0x03：OTA发送数据指令
//	0x04：OTA启动
//	0x05：查看版本信息
//	0x06：结束OTA升级（可选）
enum _OTA_CmdCode
{
	_OTA_CmdCode_Request = 0x1,//0x01：OTA升级请求
	_OTA_CmdCode_Version = 0x2,//
	_OTA_CmdCode_Data = 0x3,//
	_OTA_CmdCode_Start = 0x4,
	_OTA_ComCode_VersionGet = 0x5,
	_OTA_ComCode_Complete = 0x6,
	_OTA_ComCode_End = 0x7,
};
//"见异常功能码参数
//	0x10：需要升级，进入升级模式
//	0x11：不需要升级
//	0x12：擦除flash失败
//	0x13：模块异常，禁止升级"
enum _OTA_Version_ErrCode
{
	_OTA_Version_ErrCode_UpdateMode = 0x10,//0x01：OTA升级请求
	_OTA_Version_ErrCode_NoNeed = 0x11,//
	_OTA_Version_ErrCode_FlashErr = 0x12,//
	_OTA_Version_ErrCode_ModeErr = 0x13,
};

//"见异常功能码参数
//	0x11：块号重复
//	0x12：块号丢失
//	0x13：写入失败
//	0x14：模块异常，禁止升级
//	0x15：非升级状态"

enum _OTA_Data_ErrCode
{
	_OTA_Data_ErrCode_BlockDuplicate = 0x11,
	_OTA_Data_ErrCode_BlockLoss = 0x12,//
	_OTA_Data_ErrCode_BlockWriteErr = 0x13,//
	_OTA_Data_ErrCode_MoudleErr = 0x14,
	_OTA_Data_ErrCode_StatusErr = 0x15,
};
enum _Special_CmdCode
{
	_Special_Report = 0x0,//0x01：OTA升级请求
	_Special_SaveCfg = 0x1,//
	_Special_ForceCharge = 0x2,//
	_Special_Reset = 0x3,
};
enum _OTA_Mode
{
	_OTA_P2P_Mode = 0x1,//0x01：OTA升级请求
	_OTA_BroadCast_Mode = 0x2,//
};

typedef enum {
	OTA_SUCCESS = 0,
	OTA_STATE_ERR = 0x11,
	OTA_CONFIRM_DATA_SIZE_ERR = 0x12,
	OTA_FW_INFO_ERR = 0x13,
	OTA_FW_SAME_ERR = 0x14,
	OTA_FW_SIZE_ERR = 0x15,
	OTA_FLASH_ERASE_ERR = 0x16,
	OTA_RCV_DATA_SIZE_ERR = 0x17,
	OTA_PACKNO_ERR = 0x18,
	OTA_FW_WHOLE_SIZE_ERR = 0x19,
	OTA_FLASH_WRITE_ERR = 0x1A,
	OTA_CRC_SIZE_ERR = 0x1B,
	OTA_WHOLE_PACK_CRC_ERR = 0x1C,
	OTA_FLASH_CHECK_ERR = 0x1D,
	OTA_TIMEOUT = 0x1E,
	OTA_QUIT = 0x1F,
	OTA_MOVE_BIN_ERR = 0x20,
	OTA_CMD_CODE_ERR = 0x21,
	OTA_CMD_LEN_ERR = 0x22,
} ota_error_t;

/// Modbus
// 标准Modbus TCP头部
struct ModbusTCPHeader {
	quint16 transId;
	quint16 protoId;
	quint16 length;
	quint8 unitId;
};

// 扩展Modbus TCP读取请求
struct ExtModbusReadRequest {
	quint8 funcCode; // 0xF0
	quint16 startAddr;
	quint16 numRegs;
};

// 扩展Modbus TCP读取响应
struct ExtModbusReadResponse {
	quint8 funcCode; // 0xF0
	quint8 byteCount;
	QVector<quint16> data;
};








class CommonIface  : public QObject
{
	Q_OBJECT
public:
	CommonIface(QObject *parent);
	~CommonIface();
public:
	virtual bool open() = 0;
	virtual	void write(QByteArray& data) = 0;
	virtual	void close() = 0;
	virtual	QByteArray read() = 0;
	virtual OTA_Data_Head readDataCmd(QByteArray arr) = 0;
	virtual	bool readCheck(QByteArray arr) = 0;
	virtual	QByteArray ota_update_request(uint8_t serverAddress) = 0;
	virtual	QByteArray ota_version_snd(uint8_t serverAddress , OTA_File_Head file_head) = 0;
	virtual	QByteArray ota_version_get(uint8_t serverAddress) = 0;
	virtual	QByteArray ota_commite_request(uint8_t serverAddress, uint16_t file_crc) = 0;
	virtual	QByteArray ota_complete_request(uint8_t serverAddress) = 0;
	virtual	QByteArray data_ota_download(uint8_t serverAddress) = 0;
	virtual	QByteArray writeDatagram(uint8_t serverAddress,uint16_t DataNo, char* tx_buf, int Len) = 0;

	virtual QByteArray  mb_additional_overlength_requeset(uint16_t serverAddress, uint16_t regNum)=0;
};
#endif