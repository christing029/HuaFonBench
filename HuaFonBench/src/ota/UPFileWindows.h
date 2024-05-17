#ifndef UPFILE_H
#define UPFILE_H

#include <QMainWindow>
#include "ui_UPFileWindows.h"
#include <QMessageBox>
#include <QProgressDialog>
#include "QSerialPortInfo"
#include <QVariant>
#include <QSerialPort>
#include <QDebug>
#include "QTimer"
#include "QDateTime"
#include "UartBusIface.h"
#include "TCPClientBusIface.h"
#include "CanBusIface.h"
#include "CoreFactory.h"
#include <QSettings>
#include "modbus_params.h"
#include "ModbusTCP.h"
class UPFileWindows : public QMainWindow
{
	Q_OBJECT
public:
	UPFileWindows(QWidget *parent = nullptr);
	~UPFileWindows();
private:
	QDataStream fileStream;
	int sendTotalCnt =0;
	int	lastLen = 0;
	QString  filePath;
	QDateTime       startDate;
	QLabel* labelStsIco;           // 状态图标
	QLabel* labelStsStatus;           // 状态图标
	int fileLen=0;
	OTA_File_Head file_head = {0};
	bool   ota_err_status = false;
	uint16_t file_crc = 0;
	_OTA_Mode ota_mode = _OTA_P2P_Mode;
	_OTA_CmdCode      m_ota_step = _OTA_CmdCode_Request;
	uint8_t serverAddress = 0x1;
	CommonIface* pIface = nullptr;
	bool    CnnStat = false;
	bool validSignal = false;
	QTimer* data_timer = nullptr;
	bool mTimeout = false;
	QSettings* settings;
	uint8_t SlaveCount = 0;
	ModbusTCP* mbtcp;
private:
	// 串口实现OTA
	void scanSerialPort();
	void ota_update_request();
	void ota_version_snd();
	void ota_version_get();
	//void ota_data_request();
	void ota_commite_request();
	void ota_complete_request();
	void ota_reply_process(QByteArray byteArray);
	void data_ota_download();
	uint8_t deviceAddress_get();
	void writeDatagram(uint16_t DataNo, char* tx_buf, int Len);
	void Delay_Msec(uint msec);
	void loadfile();
	void  addbmuNumShow();

// 升级超时机制
private:
	QTimer timeoutTimer;
	QTimer* HelloTimer;
	int timeoutMilliseconds=1000;
private slots:
	void onTimeout();

	//void sendQuestion(const QString& question) {
	//	// Send question logic here (e.g., writing to a socket)
	//	emit questionAsked(question);
	//	timeoutTimer.start(timeoutMilliseconds);
	//}
private slots:
	void on_bt_open_clicked();
	void on_bt_clear_clicked();
	void on_bt_download_clicked();
	void ReadData();
	void slot_stateChanged(QAbstractSocket::SocketState stat);
signals:
	void workStart();
	void workFinished();
	void viewTransmitData(int seq,int len);
private:
	void onBrowserBtnClicked();
	void FiledataTimeLoad();
	void updateDataInit();
	QString fileName="";
	QTimer* timer;
	QFile *binFile;
	QByteArray allDataArray;
//	QStringList* loadStringList;
	int retryNum = 3;
	int signalType = 0;
	int resultValue = 0;
	int seqValue = 0;
	int nextValue = 1;
	QProgressDialog* DLoadBar;
	char* pFileBuf;
	int sendHistory = 0;
private slots:
	void timerSend();
	void slotviewTransmitData(int seq,int len);
private:
	Ui::UPFileWindowsClass ui;
};
#endif