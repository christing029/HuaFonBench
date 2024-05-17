
#ifndef CanBusIface_H
#define CanBusIface_H
#define LibECanVci "ECanVci"
#include <QThread>
#include <QFileDialog>
#include "can.h"
#include "ECanVci.h"
#include <src/drvmng/CommonIface.h>
class CanBusIface : public CommonIface
{
#pragma pack(1)
    #define SRC_DEVID (0xE2) //上位机ID
    #define CAN_RCV_MAX_LEN 256
    #define RS485_RSP_MAX_DATA 16
	typedef enum {
		CAN_SF = 0x00,
		CAN_FF = 0x01,
		CAN_CF = 0x02,
		CAN_FC = 0x03,
	} can_multi_frame_flag_t;
	typedef enum {
		CAN_OTA_CMD_ID = 0x18000000,
	} ext_can_id_t;
	typedef struct {
		uint8_t func_code; // 对应功能码
		uint8_t slave_addr;
	} inter_can_cmd_t;

	typedef struct {
		uint8_t len : 4;
		uint8_t type : 4;
		uint8_t data[];
	} can_sf_frame_t;
	typedef union {
		uint8_t All;
		struct
		{
			uint8_t len : 4;
			uint8_t type : 4;
		}Bits;
	}can_sf_frame2_t;

	typedef struct {
		uint8_t len_h : 4;
		uint8_t type : 4;
		uint8_t len_l;
		uint8_t data[];
	} can_ff_frame_t;

	typedef struct {
		uint8_t packno : 4;
		uint8_t type : 4;
		uint8_t data[];
	} can_cf_frame_t;

	typedef struct {
		uint32_t canId;
		uint8_t data[8];
	} can_frame_t;

	typedef struct {
		uint8_t packno;
		uint16_t whole_len;
		uint16_t rcv_len;
	} can_multi_frame_info_t;

	/// <summary>
	/// OTA 发送指令的数据结构
	/// </summary>
	typedef struct {
		uint8_t Cmd;
	} can_ota_update_request_t;

	typedef struct {
		uint8_t Cmd;
		OTA_File_Head file_head;
	} can_ota_version_snd_t;

	typedef struct {
		uint8_t Cmd;
		uint16_t DataNo;
	//	uint16_t length;
		uint8_t data[128];
	} can_ota_write_data_t;

	typedef struct {
		uint8_t Cmd;
		uint16_t filecrc;
	} can_ota_commite_request_t;

	typedef struct {
		uint8_t Cmd;
	} can_ota_version_get_t;

	typedef struct {
		uint8_t Cmd;
	} can_ota_download_t;

#pragma pack()
	Q_OBJECT
public:
	CanBusIface(QObject* parent);
	~CanBusIface();
	CanBusIface(QString IP, int32_t Port);
public:
	bool open();
	void write(QByteArray& data);
	void close();
	QByteArray read();
	bool readCheck(QByteArray arr);
	QByteArray ota_update_request(uint8_t serverAddress);
	QByteArray ota_version_snd(uint8_t serverAddress, OTA_File_Head file_head);
	QByteArray ota_version_get(uint8_t serverAddress);
	QByteArray ota_commite_request(uint8_t serverAddress, uint16_t file_crc);
	QByteArray ota_complete_request(uint8_t serverAddress);
	//QByteArray ota_reply_process(uint8_t serverAddress, QByteArray byteArray);
	QByteArray data_ota_download(uint8_t serverAddress);
	QByteArray writeDatagram(uint8_t serverAddress, uint16_t DataNo, char* tx_buf, int Len);
	OTA_Data_Head readDataCmd(QByteArray arr);
private:
	Thread* MyCANControlThread;
	unsigned int mconnect = false;
	unsigned short mbaud;
	unsigned short mRTR;
	byte mEXT = 0;
	uint SynFrameId = 0x100;
	bool  IsOpenFlag = false;
	UINT16 DstdevId = 0x1;
	can_frame_t canframe = { 0 };
	QByteArray Recdata;
signals:
		//向上层传送消息
		void signalUpMsg();
private:
	void can_sendSingleFrame(uint32_t can_id, uint8_t* data, uint8_t len);
	void can_send_FF_Frame(uint32_t can_id, uint8_t* data, uint32_t len);
	void can_send_CF_Frame(uint32_t can_id, uint8_t packno, uint8_t* data, uint8_t len);
	void can_multi_frame_sendFrame(uint32_t can_id, uint8_t* data, uint32_t len);
private slots:
	void deal_can_rec(QString str, QByteArray);
};
#endif