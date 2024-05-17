#ifndef TCPClientBusIface_H
#define TCPClientBusIface_H
#include <CommonIface.h>
#include <QTcpSocket>
class TCPClientBusIface : public CommonIface
{
	Q_OBJECT
public:
	TCPClientBusIface(QObject* parent);
	~TCPClientBusIface();
	TCPClientBusIface(QString IP, int32_t Port);
public:
		bool open();
		void write(QByteArray& data) ;
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
		QByteArray  mb_additional_overlength_requeset(uint16_t serverAddress, uint16_t regNum);
private:
	QTcpSocket* tcpsocket;
	QString ip = "127.0.0.1";
	uint port = 8000;
	QAbstractSocket::SocketState tcpstat;
	OTA_MBAP_Cmd  ota_mbtcp_cmd;
	HF_Modbus_TCP_Cmd       hf_cmd = {0};
private slots:
	// 构造函数中用connect绑定
	//void StartConnect();
	void connectSucc();
	void slot_ReadData();
	void slot_stateChanged(QAbstractSocket::SocketState stat);
	//void disConnect();
signals:
	//向上层传送消息
	void signalUpMsg();
	void signalstateChanged(QAbstractSocket::SocketState stat);
};
#endif