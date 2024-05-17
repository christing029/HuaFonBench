#ifndef UartBusIface_H
#define UartBusIface_H

#include <CommonIface.h>
#include <QSerialPort>

class UartBusIface  : public CommonIface
{
	Q_OBJECT
public:
	UartBusIface(QObject* parent);
	~UartBusIface();
	UartBusIface(QString PortName, qint32 BoudRate);
	//UartBusIface();
	//UartBusIface();
public:
	  bool  open();
	  void  write(QByteArray& data);
	  void  close();
	  QByteArray read();
	  bool readCheck(QByteArray arr);
	  QByteArray ota_update_request(uint8_t serverAddress);
	    QByteArray ota_version_snd(uint8_t serverAddress,  OTA_File_Head file_head) ;
	 	QByteArray ota_version_get(uint8_t serverAddress) ;
	 	QByteArray ota_commite_request(uint8_t serverAddress, uint16_t file_crc);
	 	QByteArray ota_complete_request(uint8_t serverAddress) ;
	 	//QByteArray ota_reply_process(uint8_t serverAddress, QByteArray byteArray);
	 	QByteArray data_ota_download(uint8_t serverAddress) ;
	 	QByteArray writeDatagram(uint8_t serverAddress, uint16_t DataNo, char* tx_buf, int Len) ;
		OTA_Data_Head readDataCmd(QByteArray arr);
		QByteArray  mb_additional_overlength_requeset(uint16_t serverAddress, uint16_t regNum);
private:
	QSerialPort* SerialPort;
	QString portName;
	qint32 boudRate;
	//向上层传送消息
//	void signalUpMsg();

private slots:
	void slot_ReadData();
signals:
	//向上层传送消息
	void signalUpMsg();
};
#endif