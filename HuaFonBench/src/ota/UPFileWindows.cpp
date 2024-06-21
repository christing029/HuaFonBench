#include "UPFileWindows.h"
#include <QFile>
#include <QLabel>
#include <QThread>
#include <QFileDialog>
#include "QDateTime"
#include "QFuture"
#include <src/ota/workThread.h>

const static int PACKET_SIZE = 128;//每次发送的字节数
const static int PACKET_HEAD_SIZE = 0;  //协议字节数
// CRC_16高8位数据区
const static uint8_t auchCRCHi[] = {
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
    0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
    0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
    0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
    0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
    0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
    0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40 };
// CRC低位字节值表
const static uint8_t auchCRCLo[] = { // CRC_16低8位数据区
    0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06,
    0x07, 0xC7, 0x05, 0xC5, 0xC4, 0x04, 0xCC, 0x0C, 0x0D, 0xCD,
    0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09,
    0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A,
    0x1E, 0xDE, 0xDF, 0x1F, 0xDD, 0x1D, 0x1C, 0xDC, 0x14, 0xD4,
    0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3,
    0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3,
    0xF2, 0x32, 0x36, 0xF6, 0xF7, 0x37, 0xF5, 0x35, 0x34, 0xF4,
    0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A,
    0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29,
    0xEB, 0x2B, 0x2A, 0xEA, 0xEE, 0x2E, 0x2F, 0xEF, 0x2D, 0xED,
    0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26,
    0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60,
    0x61, 0xA1, 0x63, 0xA3, 0xA2, 0x62, 0x66, 0xA6, 0xA7, 0x67,
    0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F,
    0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68,
    0x78, 0xB8, 0xB9, 0x79, 0xBB, 0x7B, 0x7A, 0xBA, 0xBE, 0x7E,
    0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5,
    0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71,
    0x70, 0xB0, 0x50, 0x90, 0x91, 0x51, 0x93, 0x53, 0x52, 0x92,
    0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C,
    0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B,
    0x99, 0x59, 0x58, 0x98, 0x88, 0x48, 0x49, 0x89, 0x4B, 0x8B,
    0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C,
    0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42,
    0x43, 0x83, 0x41, 0x81, 0x80, 0x40 };
/*CRC16查表计算函数*/
static uint16_t GenerateCRC16CheckCode(uint8_t* puckMsg, uint32_t usDataLen);
/*函数功能：CRC校验码生成
输入参数：puchMsgg是要进行CRC校验的消息，usDataLen是消息中字节数
函数输出：计算出来的CRC校验码
GenerateCRC16CheckCode查表计算函数*/
static uint16_t GenerateCRC16CheckCode(uint8_t* puckMsg, uint32_t usDataLen)
{
    uint8_t uchCRCHi = 0xFF; // 高CRC字节初始化
    uint8_t uchCRCLo = 0xFF; // 低CRC 字节初始化
    uint32_t uIndex;         // CRC循环中的索引
    // 传输消息缓冲区
    while (usDataLen--)
    {
        // 计算CRC
        uIndex = uchCRCLo ^ *puckMsg++;
        uchCRCLo = uchCRCHi ^ auchCRCHi[uIndex];
        uchCRCHi = auchCRCLo[uIndex];
    }
    // 返回结果，高位在前
    return (uchCRCLo << 8 | uchCRCHi);
}

UPFileWindows::UPFileWindows(QWidget *parent)
	: QMainWindow(parent)
{
    QFile file(":/qss/HF.qss");
    if (!file.open(QIODevice::ReadOnly))
    {
        qWarning("Can't open the style sheet file.");
        return;
    }
    QString qss = QLatin1String(file.readAll());
    this->setStyleSheet(qss);
	ui.setupUi(this);
    this->setWindowTitle("华峰储能设备升级界面");
    QPixmap*  disconnectIco = new QPixmap(":/icon/globes_red.png");
    labelStsIco = new QLabel();
    labelStsStatus = new QLabel();
	ui.statusBar->showMessage("浙江华峰储能科技有限公司");
    QFont font("Microsoft YaHei", 8);
    labelStsStatus->setMinimumWidth(120);
    labelStsStatus->setText(("升级准备"));
    labelStsStatus->setFont(font);
    ui.statusBar->addPermanentWidget(labelStsStatus);
    labelStsIco = new QLabel();
    labelStsIco->setMaximumSize(16, 16);
    labelStsIco->setScaledContents(true);
    labelStsIco->setPixmap(*disconnectIco);
    ui.statusBar->addPermanentWidget(labelStsIco);
    scanSerialPort();  
    //加载文件
    connect(ui.bt_loadfile, &QPushButton::clicked, this, [=]() {
        onBrowserBtnClicked();
        });
    // 版本查询
    connect(ui.bt_version_get, &QPushButton::clicked, this, [=]() {
        // 版本查询
        serverAddress = deviceAddress_get();
        ota_version_get();
        });
    // 模式改变
    connect(ui.rB_BMode, &QRadioButton::toggled,[=](bool checked) {
        // 升级模式
        if (checked)
        {
            ota_mode= _OTA_BroadCast_Mode;
            ui.checkBox_IDALL->setChecked(true);
        }
        else
        {
            ota_mode = _OTA_P2P_Mode;
            ui.checkBox_IDALL->setChecked(false);
        }
        ui.textEdit->append(QString("OTA_Mode %1").arg(ota_mode));
        }
    );
    connect(ui.rb_TypeBCU, &QRadioButton::toggled, [=](bool checked) {
        // 升级模式
        serverAddress=   deviceAddress_get();
     //   ui.textEdit->append(QString("serverAddress %1").arg(serverAddress));
        }
    );
    connect(ui.rb_TypeBMU, &QRadioButton::toggled, [=](bool checked) {
        // 升级模式
        serverAddress = deviceAddress_get();
       // ui.textEdit->append(QString("serverAddress %1").arg(serverAddress));
        }
    );
   connect(ui.checkBox_IDALL, &QCheckBox::stateChanged, [&]() {
        if (ui.checkBox_IDALL->isChecked())
        {
            ui.checkBox_ID1->setCheckState(Qt::CheckState::Checked);
            ui.checkBox_ID2->setCheckState(Qt::CheckState::Checked);
            ui.checkBox_ID3->setCheckState(Qt::CheckState::Checked);
            ui.checkBox_ID4->setCheckState(Qt::CheckState::Checked);
            ui.checkBox_ID5->setCheckState(Qt::CheckState::Checked);
            ui.checkBox_ID6->setCheckState(Qt::CheckState::Checked);
            ui.checkBox_ID7->setCheckState(Qt::CheckState::Checked);
            ui.checkBox_ID8->setCheckState(Qt::CheckState::Checked);
        }
        else
        {
            ui.checkBox_ID1->setCheckState(Qt::CheckState::Unchecked);
            ui.checkBox_ID2->setCheckState(Qt::CheckState::Unchecked);
            ui.checkBox_ID3->setCheckState(Qt::CheckState::Unchecked);
            ui.checkBox_ID4->setCheckState(Qt::CheckState::Unchecked);
            ui.checkBox_ID5->setCheckState(Qt::CheckState::Unchecked);
            ui.checkBox_ID6->setCheckState(Qt::CheckState::Unchecked);
            ui.checkBox_ID7->setCheckState(Qt::CheckState::Unchecked);
            ui.checkBox_ID8->setCheckState(Qt::CheckState::Unchecked);
        }
        });
   ui.bt_loadfile->setEnabled(true);
   ui.bt_download->setEnabled(true);
   this->setAttribute(Qt::WA_DeleteOnClose);
    settings = new QSettings("setting.ini", QSettings::IniFormat);
    ui.IPEdit->setText(settings->value("IPSetting/IP").toString());
    ui.PortEdit->setText(settings->value("IPSetting/Port").toString());
    qDebug() << QCoreApplication::applicationDirPath();

    // 在你的函数或者某个类的成员函数中设置定时器和lambda

    connect(&timeoutTimer, &QTimer::timeout, this, &UPFileWindows::onTimeout);
    HelloTimer = new QTimer(this);
    connect(HelloTimer, &QTimer::timeout, this, [this]() {
        // 在这个lambda表达式中实现你的定时任务
        // 使用this来访问类的成员，如果在类的成员函数中
        if (m_ota_step != _OTA_CmdCode_Data)
        {
          //  pIface->mb_additional_overlength_requeset(MODBUS_BATTERY_BASE + 0xa, 1);
        }
        });
    HelloTimer->setInterval(1000);
    HelloTimer->stop();
    timer = new  QTimer(this);
    connect(timer, &QTimer::timeout, this, &UPFileWindows::timerSend);
    timer->stop();
    connect(this, SIGNAL(viewTransmitData(int,int)), this, SLOT(slotviewTransmitData(int,int)));
}

UPFileWindows::~UPFileWindows()
{
    deleteLater();
}


void UPFileWindows::addbmuNumShow()
{

    for (int i = 0; i < SlaveCount; i++)
    {
        QCheckBox* checkBox_ID1 = new QCheckBox(ui.centralWidget);
        ui.horizontalLayout_9->addWidget(checkBox_ID1);
    }
}

void UPFileWindows::data_ota_download()
{
    ui.textEdit->append(QString("设备地址下发: 0x%1").arg(serverAddress,0,16));
    QString dig = QString("正在升级, 预计 %1 分钟").arg(sendTotalCnt* ui.cb_downspeed->currentText().toInt()/60000);
    QProgressDialog dialog((dig), ("取消"), 0, sendTotalCnt, this);
    dialog.setWindowTitle(("进度"));
    dialog.setWindowModality(Qt::WindowModal);
    dialog.show();
    QFile file;
    file.setFileName(filePath);
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream dataStream(&file);
        char* pBuf = new char[fileLen];
        memset(pBuf, 0, fileLen);
        dataStream.readRawData(pBuf, fileLen);
             for (int i = 0; i < sendTotalCnt; i++) {
            QCoreApplication::processEvents();
          //  QThread::msleep(ui.cb_downspeed->currentText().toInt());
            Delay_Msec(ui.cb_downspeed->currentText().toInt());
            dialog.setValue(i);
          if (dialog.wasCanceled())
            {
                break;
            }
          if (ota_err_status)
          {
              ui.textEdit->append(QString("ota_err_status: 0x%1").arg(serverAddress, 0, 16));
              break;
          }
            if (i != sendTotalCnt - 1) {

                const int PACKET_LEN = PACKET_SIZE;
                QString text = QString("---%1----PACKET_LEN: %2").arg(i).arg(PACKET_LEN);
                ui.textEdit->append(text);
                //数据填充---------------------------------------------------
                char tx_buf[PACKET_LEN] = { 0 };
                memcpy(tx_buf, pBuf + i * PACKET_SIZE, PACKET_SIZE);
                text = QString("%1").arg(sizeof(pBuf));
                ui.textEdit->append(text);
                //---------------------------------------------------------
                timeoutTimer.start(timeoutMilliseconds);
                 writeDatagram(i,tx_buf, PACKET_LEN);
                 if (ota_mode == _OTA_P2P_Mode)
                 {
                     ota_err_status = true;
                 }
            }
            else {//最后一次发送
                QThread::msleep(ui.cb_downspeed->currentText().toInt());
                int PACKET_LEN = PACKET_HEAD_SIZE + lastLen;
                ui.textEdit->append(QString(" ----%1----LAST PACKET_LEN: %2").arg(sendTotalCnt - 1).arg(lastLen));
                //数据填充---------------------------------------------------
                char* tx_buf = new char[PACKET_LEN];
                memset(tx_buf, 0, PACKET_LEN);
                memcpy(tx_buf, pBuf + i * PACKET_SIZE, lastLen);
                //---------------------------------------------------------
                timeoutTimer.start(timeoutMilliseconds);
               writeDatagram(sendTotalCnt-1,tx_buf, PACKET_LEN);
                delete[]tx_buf;
                QMessageBox messageBox(QMessageBox::NoIcon, "升级状态", "下载完成", QMessageBox::Yes, NULL);
                messageBox.setWindowFlag(Qt::WindowStaysOnTopHint);
                m_ota_step = _OTA_ComCode_Complete;
                int reply = messageBox.exec();
                // 
                if (reply == QMessageBox::Yes)
                {
                    ota_commite_request();
                }
            }
            ui.textEdit->moveCursor(QTextCursor::End);
            QDateTime endtime;
            endtime = QDateTime::currentDateTime();
            labelStsStatus->setText("正在升级   " + QString::number(startDate.secsTo(endtime), 10) + "   秒"); 

        }
        delete[]pBuf;
    }
    file.close();
}


uint8_t UPFileWindows::deviceAddress_get()
{
    uint8_t add = 0;

    if (ui.rb_TypeBAC->isChecked())
    {
        add = 0xe1;
    }
    else if (ui.rb_TypeBMU->isChecked())
    {
        add = 0x1;
    }
    else if (ui.rb_TypeBCU->isChecked())
    {
        add = 0xa1;
    }
    add = add + ui.Cb_DeviceID->currentIndex();
    if ((ota_mode == _OTA_BroadCast_Mode)&& ui.rb_TypeBMU->isChecked())
    {
        add = 0;
    }
    if ((ota_mode == _OTA_BroadCast_Mode) && ui.rb_TypeBCU->isChecked())
    {
        add = 0xa0;
    }
    return add;
}

void UPFileWindows::scanSerialPort()
{
    QStringList   serialNamePort;
    foreach(const QSerialPortInfo & info, QSerialPortInfo::availablePorts())
    {
        serialNamePort << info.portName();
    }
    ui.serialCb->addItems(serialNamePort);
}

/// <summary>
///  以下为操作的升级API
/// </summary>
/// <param name="DataNo"></param>
/// <param name="tx_buf"></param>
/// <param name="Len"></param>
void UPFileWindows::writeDatagram(uint16_t DataNo,char* tx_buf, int Len)
{
    QByteArray byteArray;
    byteArray= pIface->writeDatagram(serverAddress, DataNo, tx_buf, Len);
     pIface->write(byteArray);
#if 1//debug out
    QString strAll;
    for (int k = 0; k < byteArray.length(); k++) {
        strAll += QString::asprintf("%02X ", (uint8_t)byteArray[k]);
    }
    ui.textEdit->append(QString("%1").arg(strAll));
#endif
}

void UPFileWindows::Delay_Msec(uint msec)
{
        QTime _Timer = QTime::currentTime().addMSecs(msec);
        while (QTime::currentTime() < _Timer)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void UPFileWindows::ota_update_request()
{
    QCoreApplication::processEvents();
    QByteArray byteArray;
    byteArray = pIface->ota_update_request(serverAddress);
    pIface->write(byteArray);
    ui.textEdit->append("ota_update_request OK");
    ui.bt_download->setEnabled(true);
    QString strAll;
    for (int k = 0; k < byteArray.size(); k++) {
        strAll += QString::asprintf("%02X ", (uint8_t)byteArray[k]);
    }
    ui.textEdit->append("Snd:");
    ui.textEdit->append(QString("%1").arg(strAll));
}
void UPFileWindows::ota_version_snd()
{
    QByteArray byteArray;
    file_head.appSize = fileLen;
    if (ui.checkBox_force->isChecked())
    {
        file_head.softversion[0] = 0xff;
        file_head.softversion[1] = 0xff;
        file_head.softversion[2] = 0xff;
        file_head.softversion[3] = 0xff;
    }
    byteArray = pIface->ota_version_snd(serverAddress, file_head);
    pIface->write(byteArray);
    QString strAll;
    for (int k = 0; k < byteArray.size(); k++) {
        strAll += QString::asprintf("%02X ", (uint8_t)byteArray[k]);
    }
    ui.textEdit->append("Snd:");
    ui.textEdit->append(QString("%1").arg(strAll));
}

void UPFileWindows::ota_version_get()
{
    if (ota_mode == _OTA_P2P_Mode)
    {
        QByteArray byteArray;
        byteArray=  pIface->ota_version_get(serverAddress);
        pIface->write(byteArray);
        QString strAll;
        for (int k = 0; k < byteArray.size(); k++) {
            strAll += QString::asprintf("%02X ", (uint8_t)byteArray[k]);
        }
        ui.textEdit->append("Snd:");
        ui.textEdit->append(QString("%1").arg(strAll));
    }
    else if (ota_mode == _OTA_BroadCast_Mode)
    {
        uint8_t addre = 0;
        if (ui.rb_TypeBMU->isChecked())
        {
            addre = 0;
        }
        if (ui.rb_TypeBCU->isChecked())
        {
            addre = 0xa0;
        }
        for (int i = addre+1; i < addre+8; i++)
        {
            QCoreApplication::processEvents();
            QByteArray byteArray;
            byteArray = pIface->ota_version_get(i);
            pIface->write(byteArray);
                    QString strAll;
        for (int k = 0; k < byteArray.size(); k++) {
            strAll += QString::asprintf("%02X ", (uint8_t)byteArray[k]);
        }
        ui.textEdit->append("Snd:");
        ui.textEdit->append(QString("%1").arg(strAll));
            QThread::sleep(1);
        }
    }
}
void UPFileWindows::ota_commite_request()
{
    QByteArray byteArray;
    byteArray = pIface->ota_commite_request(serverAddress, file_crc);
    pIface->write(byteArray);
    QString strAll;
    for (int k = 0; k < byteArray.size(); k++) {
        strAll += QString::asprintf("%02X ", (uint8_t)byteArray[k]);
    }
    ui.textEdit->append("Snd:");
    ui.textEdit->append(QString("%1").arg(strAll));
}
void UPFileWindows::ota_complete_request()
{
    QByteArray byteArray;
    byteArray = pIface->ota_complete_request(serverAddress);
    pIface->write(byteArray);
}
void UPFileWindows::ota_reply_process(QByteArray byteArray)
{
    OTA_Data_Head getMsg = pIface->readDataCmd(byteArray);
    uint8_t code = 0;
    //ui.textEdit->append(QString("OTA_Mode Process %1").arg(ota_mode));
    if (ota_mode == _OTA_BroadCast_Mode)
    {
      //  ui.textEdit->append(QString("OTA_BroadCast_Mode %1").arg(ota_mode));
    }
    else if (getMsg.serverAddress != serverAddress)
    {
        qDebug() << "serverAddress err :"<< getMsg.serverAddress;
        return;
    }
    switch (getMsg.FunCode)
    {
    case OTA_FunCode:
        switch (getMsg.CmdCode)
        {
        case _OTA_CmdCode_Request:
            ui.textEdit->append("_OTA_CmdCode_Reply OK");
            // 下发版本
            ota_version_snd();
            break;
        case _OTA_CmdCode_Version:
            ui.textEdit->append("_OTA_CmdCode_Version_Reply OK");
            // 开启下载按钮
           // data_ota_download();
            FiledataTimeLoad();
            break;
        case _OTA_CmdCode_Data:
            ota_err_status = false;
            ui.textEdit->append(QString("%1,%2:%3").arg(QTime::currentTime().toString("HH:mm:ss")).arg("DataReply").arg(nextValue-1));
            nextValue++;
            // 收到最后一包后下方 升级成功指令
            if (m_ota_step == _OTA_ComCode_Complete)
            {
                ui.textEdit->append("ota_commite_request OK");
                ota_commite_request();
            }
            timeoutTimer.stop();
            break;
        case _OTA_CmdCode_Start:
            break;
        case _OTA_ComCode_VersionGet:
            ui.textEdit->append("_OTA_ComCode_VersionGet OK");
            break;
        case _OTA_ComCode_Complete:
            break;
        default:
            break;
        }
        break;
    case  OTA_ERR_FunCode:
        ota_err_status = true;
        resultValue = 1; //收到错误包
        ui.textEdit->append(QString("OTA_ERR_FunCode ERRCmd %1 ").arg(getMsg.CmdCode));
        code = byteArray[9];
        ui.textEdit->append(QString("OTA_ERR_FunCode ERRCode %1 ").arg(code));
        break;
    case  Special_ERR_FunCode:
        break;
    case 0x41:
        if (SlaveCount == 0)
        {
         //   ui.textEdit->append(QString("从机数量 %1").arg(byteArray[11]));
        }
        SlaveCount = byteArray[11];
        ui.textEdit->append(QString("从机数量 %1").arg(SlaveCount));
        break;
    default:
        break;
    }
}

void UPFileWindows::slot_stateChanged(QAbstractSocket::SocketState stat)
{

    QPixmap* disconnectIco = new QPixmap(":/icon/globes_red.png"); 
    ui.bt_open->setText("打开");
    CnnStat = false;
    HelloTimer->stop(); // 设置定时器每隔100毫秒触发一次
    switch (stat)
    {
    case  QAbstractSocket::SocketState::UnconnectedState:
        ui.textEdit->append("UnconnectedState");

        if (ui.bt_open->text() == "打开")
        {
            connect(pIface, SIGNAL(signalstateChanged(QAbstractSocket::SocketState)), this, SLOT(slot_stateChanged(QAbstractSocket::SocketState)));
        }
        break;
    case  QAbstractSocket::SocketState::HostLookupState:
        ui.textEdit->append("HostLookupState");
        break;
    case  QAbstractSocket::SocketState::ConnectingState:
        ui.textEdit->append("ConnectingState");
        break;
    case  QAbstractSocket::SocketState::ConnectedState:
        disconnectIco = new QPixmap(":/icon/globes_green.png");
        HelloTimer->start(); // 设置定时器每隔100毫秒触发一次
        ui.bt_open->setText("断开");
        CnnStat = true;
        break;
    case  QAbstractSocket::SocketState::BoundState:
        ui.textEdit->append("BoundState");
        break;
    case  QAbstractSocket::SocketState::ListeningState:
        ui.textEdit->append("ListeningState");
        break;
    case  QAbstractSocket::SocketState::ClosingState:
        disconnectIco = new QPixmap(":/icon/globes_red.png");
        ui.textEdit->append("ClosingState");
        break;
    default:
        break;
    }
    labelStsIco->setPixmap(*disconnectIco);
    delete disconnectIco;
}


void UPFileWindows::on_bt_open_clicked()
{
    QCoreApplication::processEvents();
    settings->setValue("IPSetting/IP", ui.IPEdit->text());
    settings->setValue("IPSetting/Port", ui.PortEdit->text());
    if (!CnnStat)
    {
        if (ui.rB_Eth->isChecked())
        {
            pIface = new TCPClientBusIface(ui.IPEdit->text(), ui.PortEdit->text().toInt());
            connect(pIface, SIGNAL(signalstateChanged(QAbstractSocket::SocketState)), this, SLOT(slot_stateChanged(QAbstractSocket::SocketState)));
        }
        else if(ui.rB_Uart->isChecked())
        {
            pIface = new UartBusIface(ui.serialCb->currentText(), 115200);
        }
        else if (ui.rb_Can->isChecked())
        {
           // pIface = new CanBusIface(ui.serialCb->currentText(), 115200);
        }

        if (pIface->open())
        {
            ui.bt_open->setText("断开");
            ui.bt_loadfile->setEnabled(true);
            QPixmap* disconnectIco = new QPixmap(":/icon/globes_green.png");
            labelStsIco->setPixmap(*disconnectIco);
            CnnStat = true;
        }
        connect(pIface, SIGNAL(signalUpMsg()), this, SLOT(ReadData()));
    }
    else
    {
        QPixmap* disconnectIco = new QPixmap(":/icon/globes_red.png");
        labelStsIco->setPixmap(*disconnectIco);
        pIface->close();
        ui.bt_open->setText("打开");
        CnnStat = false;
    }
}

void UPFileWindows::on_bt_clear_clicked()
{
  //  pIface->mb_additional_overlength_requeset(0x4000, 400);
   // addbmuNumShow();
    ui.textEdit->clear();
}

void UPFileWindows::on_bt_download_clicked()
{
    // 开始升级时间


    ota_err_status = false;
    m_ota_step = _OTA_CmdCode_Request;
    startDate = QDateTime::currentDateTime();
    if (pIface == NULL)
        return;
    if (pIface->open() == false)
        return;
    serverAddress = deviceAddress_get();
    ota_update_request();
    updateDataInit();
    if (ota_mode == _OTA_BroadCast_Mode)
    {
        QCoreApplication::processEvents();
        QThread::msleep(500);
        ota_version_snd();
        QCoreApplication::processEvents();
        QThread::msleep(500);
        FiledataTimeLoad();
    }  
}

void UPFileWindows::ReadData()
{
    QCoreApplication::processEvents();
    QByteArray arr;
    arr = pIface->read();
    QString strAll;
#if 1
    for (int k = 0; k < arr.size(); k++) {
        strAll += QString::asprintf("%02X ", (uint8_t)arr[k]);
    }
    ui.textEdit->append("Rec:");
    ui.textEdit->append(QString("%1").arg(strAll));
#endif
    ota_err_status = false;
    if (pIface->readCheck(arr))
    {
    //    ui.textEdit->append("Rec:CRC OK:");
        ota_reply_process(arr);
    }
    else
    {
        ui.textEdit->append("Rec:CRC ERR:");
    }
}



void UPFileWindows::onTimeout() {

    // Timeout logic here
   // emit communicationTimeout();
}

/********************************以下为定时器发送机制****************************************/
/**
 * @brief UpdateWidget::onBrowserBtnClicked
 */
void UPFileWindows::onBrowserBtnClicked()
{
    qDebug() << "onBrowserBtnClicked";
    QFileDialog dlg;
    QStringList filters;
    QByteArray byteArray;
    QFile file;
  QString FilePath  =settings->value("/file/addr").toString();
    //获取用户选择文件，显示路径
    fileName = QFileDialog::getOpenFileName(this, ("打开文档文件"), QString(FilePath), tr("文档后缀(*.bin)"));
    qDebug() << fileName;
    QLabel* label_selepath = new QLabel();
    label_selepath->clear();
    label_selepath->setText(fileName);
    ui.textEdit->append(QString("%1,%2:%3").arg(QTime::currentTime().toString("HH:mm:ss")).arg("已选择文件").arg(fileName));
    ui.lineEdit->setText(fileName);
    //获取并显示文件大小
    QFileInfo* pcsfileInfo = new QFileInfo(fileName);
    fileLen = pcsfileInfo->size();
    sendTotalCnt = (int)ceil(fileLen / (PACKET_SIZE * 1.0));//发送次数
    ui.textEdit->append(QString("%1,%2:%3,%4:%5").arg(QTime::currentTime().toString("HH:mm:ss")).arg("文件大小").arg(fileLen).arg("发送次数").arg(sendTotalCnt));
    file.setFileName(fileName);
    if (file.open(QIODevice::ReadOnly))
    {
        QDataStream dataStream(&file);
        pFileBuf = new char[fileLen];
        memset(pFileBuf, 0, fileLen);
        dataStream.readRawData(pFileBuf, fileLen);
        file_crc = GenerateCRC16CheckCode((uint8_t*)pFileBuf, fileLen);
        memcpy(&file_head, pFileBuf, sizeof(file_head));
        byteArray.append(reinterpret_cast<char*>(pFileBuf), fileLen);
        settings->setValue("/file/addr", FilePath);
    }
    lastLen = fileLen % PACKET_SIZE;//最后一次发送的大小
    if (0 == lastLen) {//恰巧是PACKET_SIZE的整数倍
        lastLen = PACKET_SIZE;
    }
    // 软件版本显示
    QString  Ver = QString::number(file_head.softversion[3], 16) + "." + QString::number(file_head.softversion[2], 16) + "." + QString::number(file_head.softversion[1], 16);
    ui.lineEdit_3->setText("V" + Ver);
    // 硬件版本显示
    Ver = QString::number(file_head.hardversion[3], 16) + "." + QString::number(file_head.hardversion[2], 16) + "." + QString::number(file_head.hardversion[1], 16);
    ui.lineEdit_2->setText("V" + Ver);
  //  ui.textEdit->append("File CRC:" + QString::number(file_crc, 16));
    file.close();
    ota_err_status = false;
  //  QString str7(file_head.hardversion);
    QString str8 = QString::fromLocal8Bit((char*)&file_head.FactoryID[0], 4);
    if (str8.contains("BCU"))
    {
        ui.rb_TypeBCU->setChecked(true);
        ui.textEdit->append(QString("%1,%2:%3").arg(QTime::currentTime().toString("HH:mm:ss")).arg("选择目标").arg("BCU"));
    }
    else if(str8.contains ("BMU"))
    {
        ui.rb_TypeBMU->setChecked(true);
        ui.textEdit->append(QString("%1,%2:%3").arg(QTime::currentTime().toString("HH:mm:ss")).arg("选择目标").arg("BMU"));
    }
    else if (str8.contains("BAU"))
    {
        ui.rb_TypeBAC->setChecked(true);
        ui.textEdit->append(QString("%1,%2:%3").arg(QTime::currentTime().toString("HH:mm:ss")).arg("选择文件").arg("BAU"));
    }
    else
    {
        ui.textEdit->append(QString("%1,%2:%3").arg(QTime::currentTime().toString("HH:mm:ss")).arg("文件有误").arg(fileName));
        ui.bt_download->setEnabled(false);
    }

    deviceAddress_get();
    ui.bt_download->setEnabled(true);
    updateDataInit();
}


/**
 * @brief UpdateWidget::onBtnLoadClicked
 */
void UPFileWindows::FiledataTimeLoad()
{
    m_ota_step == _OTA_CmdCode_Data;
    QCoreApplication::processEvents();
    if (fileName.isEmpty())
    {
        ui.textEdit->append(QString("%1,%2").arg(QTime::currentTime().toString("HH:mm:ss")).arg("请先选择文件！"));
    }
    else
    {
        ui.textEdit->append(QString("%1,%2").arg(QTime::currentTime().toString("HH:mm:ss")).arg("开始下载！"));
        startDate = QDateTime::currentDateTime();
        QString dig;
        if(ota_mode== _OTA_BroadCast_Mode)
        {
            dig = QString("正在升级, 预计 %1 分钟").arg(sendTotalCnt * ui.cb_downspeed->currentText().toInt() / 60000);
            timer->start(ui.cb_downspeed->currentText().toInt()); //打开定时器     
        }
        else
        {
            dig = QString("正在升级, 预计 %1 分钟").arg(sendTotalCnt *50 / 60000);
            timer->start(100);
        }
        DLoadBar = new QProgressDialog((dig), ("取消"), 0, sendTotalCnt, this);
        DLoadBar->setWindowTitle(("进度"));
        DLoadBar->setWindowModality(Qt::WindowModal);
        DLoadBar->show();
       }
}
void UPFileWindows::updateDataInit()
{
     retryNum = 0;
     signalType = 0;
     resultValue = 0;
     seqValue = 0;
     nextValue = 1;
     sendHistory = 0;
   //  m_ota_step = _OTA_CmdCode_Request;
     timer->stop();
}

void UPFileWindows::slotviewTransmitData(int seq,int len)
{
    char tx_buf[PACKET_SIZE] = { 0 };
    memcpy(tx_buf, pFileBuf + seq * PACKET_SIZE, len);
    writeDatagram(seq, tx_buf, len);
    ui.textEdit->append(QString("%1,%2:%3").arg(QTime::currentTime().toString("HH:mm:ss")).arg("DataSnd").arg(seq));
}

void UPFileWindows::timerSend()
{
    QCoreApplication::processEvents();
    int PACKET_LEN = PACKET_SIZE;
    if (DLoadBar->wasCanceled())
    {
        timer->stop(); 
        return;
    }
    //3 判断对方上一个包回复结果，决定是否发送当前包
    if ((resultValue == 0 && nextValue == seqValue + 1) ||(ota_mode == _OTA_BroadCast_Mode))// 3.1 收到正常回复，继续判断是否发送下一个包
    {
        m_ota_step = _OTA_CmdCode_Data;
        signalType = 0;
        if (seqValue < sendTotalCnt) // 发送未结束，发送下一个包
        {
            if (seqValue != sendTotalCnt - 1) {
                viewTransmitData(seqValue, PACKET_LEN);
                DLoadBar->setValue(seqValue); //设置当前进度条值        
           }
            else //最后一次发送
            {
                PACKET_LEN = PACKET_HEAD_SIZE + lastLen;
                viewTransmitData(seqValue, PACKET_LEN);
                DLoadBar->setValue(seqValue); //设置当前进度条值 
                m_ota_step = _OTA_ComCode_Complete;
            }
            seqValue++; // 包序号增加
        }
        else  // 发送完成，更新状态，停止发送
        {
            DLoadBar->setValue(sendTotalCnt); //设置当前进度条值  
            seqValue = 1;
            retryNum = 0;
            timer->stop();
            if(ota_mode== _OTA_BroadCast_Mode)
            {
                ota_commite_request();
            }
            QMessageBox messageBox(QMessageBox::NoIcon, "升级状态", "下载完成", QMessageBox::Yes, NULL);
            messageBox.setWindowFlag(Qt::WindowStaysOnTopHint);
            m_ota_step = _OTA_ComCode_Complete;
            int reply = messageBox.exec();
            // 
            if (reply == QMessageBox::Yes)
            {
                //  ota_commite_request();
            }
        }
        QDateTime endtime;
        endtime = QDateTime::currentDateTime();
        labelStsStatus->setText("正在升级   " + QString::number(startDate.secsTo(endtime), 10) + "   秒");
    }
    else if (resultValue == 1) //3.2 设备处理结果为“失败”
    {
        ui.textEdit->append(QString("%1,%2").arg(QTime::currentTime().toString("HH:mm:ss")).arg("接收设备处理数据包失败，终止下载！"));
        timer->stop();
        updateDataInit();
        return;
    }
    if (signalType ==5) //3.3 接收回复超时处理,signalType为超时标志位
    {
        //判断是否为当前包超时，是当前包则继续计数，不是当前包则重新计数
        if (retryNum <3 )
        {
            retryNum++;
            ui.textEdit->append(QString("%1,当前包回复超时次数：%2").arg(QTime::currentTime().toString("HH:mm:ss")).arg(retryNum));
            ui.textEdit->append(QString("%1,%2:%3").arg(QTime::currentTime().toString("HH:mm:ss")).arg("重发数据序号:").arg(nextValue-1));
            viewTransmitData(nextValue-1, PACKET_SIZE);
            signalType = 0;
        }
        //判断当前包超时次数，超过3次则放弃下载
        else 
        {
            ui.textEdit->append(QString("%1,%2").arg(QTime::currentTime().toString("HH:mm:ss")).arg("对方无回复，终止下载！"));
            retryNum = 0;
            timer->stop();
            return;
        }
    }
    else
    {
        signalType++;
    }
    ui.textEdit->moveCursor(QTextCursor::End);
}