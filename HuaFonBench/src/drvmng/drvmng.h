#ifndef CTRLOBJ_H
#define CTRLOBJ_H
#include <QMainWindow>
#include <QThread>
#include <QFileDialog>
#include "can.h"
#include "ECanVci.h"
#include "ModbusTCP.h"
#include "QList"
#include "modbus_params.h"
#include "TCPClientBusIface.h"
#include "StantCan_params.h"
#include <QSettings>
//#include <src/libmodbus/ModbusPoll.h>

namespace Ui {
class drvmng;
}
class drvmng : public QMainWindow
{
    Q_OBJECT
#define New_J1939
#define RESERVE0_PRIO     0
#define CONTROLO_PRIO     1
#define RESERVE2_PRIO     2
#define PARAMETER_PRIO    3
#define BCU_PRIO          4
#define BMU_PRIO          5
#define FILE_PRIO         6
#define RESERVE7_PRIO     7
#define BROADCAST_ADDR    0
#define BCU_ADDR          0xA1
#define HVM_ADDR          0xB1
#define RS485_ADDR        0xC1
#define NET_ADDR          0xD1
#define EMS_ADDR          0xE1
#define PC_ADDR           0xE2
#define BAU_ADDR          0xE3
public:
    explicit drvmng(QWidget* parent = nullptr);
    ~drvmng();
    drvmng(const drvmng& other); //拷贝构造函数
    drvmng& operator=(const drvmng& other); //赋值运算操作符
    static QMutex mutex;
    static drvmng* instance;   //singleton 全局唯一的变量
public:
    QString getInstanceName() const;
    static drvmng&  getInstance(); //获取singleton的唯一对象
    static void release();
    void Ipconnect(QString Ip, UINT16 port);
    void CanConnect(int CanID);
    void disConnect();
private:
    Ui::drvmng *ui;
private:
    unsigned int mconnect = false;
    unsigned short mbaud ;
    unsigned short mRTR;
    byte mEXT=1 ;
    uint SynFrameId = 0x100000A1;
    bool  IsOpenFlag =false;
    QString CnnName ="";
    TCPClientBusIface* pIface = nullptr;
    QString ipQstr;
    QString portQstr;
private slots:
    void deal_can_rec(QString str, QByteArray);
    void updateValue();
    void slot_stateChanged(QModbusDevice::State stat);
    void slot_read_holding(QModbusDataUnit DataUnit);
    void slot_read_dataunit(QModbusDataUnit DataUnit);
    void SlotsDownMsgComing(QString flag,uint address, QVector<quint16> val);
private:
    Thread *MyCANControlThread;
    QTimer* timer;
    ModbusTCP *mbtcp;
   // ModbusPoll* mblib;
    MOBUS_RUN_STATE_BASE_s holding_reg_params = { 0 };
    BATTERY_CFG_s      m_battery_base = { 0 };
    uint16_t SlaveCount = 15; //从机的个数
    uint16_t VoltCntPerSlave = 16; // 每一个从机有多少个电压
    uint16_t TempCntPerSlave = 8;  // 每一个从机有多少温度
    QSettings* settings;
public:
    void CanSnd(unsigned int id , unsigned char data_from_text[8], unsigned int len);
    void StopThread();
    void StartThread();
    void mb_downmsg_holding(QString flag, uint address, QVector<quint16> val);
    bool drv_connect_state();
public:
    void saveCfg();
    uint8_t dr_get_prio(uint32_t id);
    uint8_t dr_get_func(uint32_t id);
    uint8_t dr_get_dest(uint32_t id);
    uint8_t dr_get_src(uint32_t id);
    uint32_t dr_make_can_ID(uint32_t prio, uint32_t function, uint32_t destAddr, uint32_t srcAddr);

signals:
    //向上层传送消息
    void signalUpCanBMUMsg(QString, QByteArray);
    void signalUpCanBMUMngMsg(QString, QByteArray);
    void signalDebugMsg(QString, QByteArray);
    void signalUpMbMsg(QString flag, uint Address, QVector<quint16> val);
    void signalUpCanBCUMsg(uint , QByteArray );
    void signalUpReadHolding(uint startAddress, QVector<quint16> val);
    void signalUpTCPBCUMsg(uint startAddress, QVector<quint16> val);
    void signalUpTCPBMUMsg(uint startAddress, QVector<quint16> val);
    void signalDeviceCnnState(QString Name,bool CnnSat);
    void signalUpAlarmLogMsg(QString, QString,QVector<quint16> val);
}; 
extern MOBUS_RUN_STATE_BASE_s m_run_state_base;
#endif // CTRLOBJ_H