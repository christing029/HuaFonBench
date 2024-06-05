#ifndef _SHOW_BCU_H
#define _SHOW_BCU_H

#include <QMainWindow>
#include "ui_ShowBCU.h"
#include <QLabel>
#include <QFile>
#include "src/drvmng/StantCan_params.h"
#include <QSqlQuery>
#include <qsql.h>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlError>
#include <QMap>
class ShowBCU : public QMainWindow
{
	Q_OBJECT
        /// <summary>
/// 电池包过/欠 压 ----无？
/// </summary>
/// 缺----端子温度过高告警
/// 缺----并机通讯告警 确认
QList<QString>   alarmBitsList = {
    "电芯过压",\
    "电芯欠压", \
    "电池簇过压",
    "电池簇欠压", \
    "模组过压",\
    "模组欠压",\
    "充电过温",\
    "放电过温",\
    "充电欠温",
    "放电欠温",\
    "充电过流",\
    "放电过流",\
    "温差太大",\
    "压差太大",\
    "温升过大",\
    "绝缘P",\
    "绝缘N" ,\
    "soc低" };

    QList<QString>   ErrorBitsList = {
        "单体极限过压",\
        "单体极限低压",\
        "环境温度过低",\
        "环境温度过高",\
        "B-温度过高",\
        "B+温度过高",
        "P-温度过高",\
        "P+温度过高",
        "分流器温度过高",
        "BCU_PCB环境温度过高",
        "BMU_PCB过温",\
        "电芯温度开路",
        "电芯温度短路",
        "PCB温度开路",\
        "PCB温度短路",\
        "均衡温度开路 ",\
        /*


          */
               "均衡温度短路",\
               "24V_DCDC输出电压过高",\
               "24V_DCDC输出电压过低",\
               "5V输出电压过高",\
               "5V输出电压过低",\
               "均衡过温",\
               "均衡开路",\
               "均衡短路",\
               "AFE通信故障",\
               "单体电压测量超时",\
               "电芯温度测量超时",\
               "currentMeasurementInvalidError",\
               "currentMeasurementInvalidError",\
               "FUSE故障",\
               "采样断线",\
               "CAN接收故障",\


               "CAN发送故障",\
               "flash故障 ",\
               "簇电压不合理",\
               "单体电压不合理",\
               "单体温度不合理",\
               "电流传感器不响应 ", \
               "主负接触器粘连故障",\
               "主正(充电)接触器粘连故障 ",\
               "主负接触器闭合故障",\
               "主正(充电)接触器闭合故障", \
               "预充继电器粘连故障 ",\
               "放电接触器粘连故障",\
               "预充继电器闭合故障",\
               "放电接触器闭合故障",\
               "隔离开关粘连故障",\
               "接触器过载",\




               "绝缘计算无效",\
               "预充故障",\
               "高压互锁故障",\
               "不可恢复故障",\
               "SOH过低",\
               "I2C_ADC错误",\
               "I2CRtc错误",
               "CRC错误",               \
               "I2C错误",               \
              "RTC电压低",         \
              "SPIFLASH读写故障",              \
              "SPI转CAN读写故障",                \
              "BMU地址故障",               \
              "BMU通信故障",                \
              "ADC参考电压偏差大",                 \
              "BMU离线故障",                  \

              "Pack风扇故障",          \
              "CAN总线故障",                     \
              "空调通信故障",       \
              "空调状态故障",              \
              "PCS通信故障（Modbus）",      \
              "PCS状态故障（Modbus）",             \
              "急停开关触发",                 \
              "水浸故障",                    \
              "簇及烟雾触发故障",                \
              "簇及温感触发故障",                 \
              "簇及消防信号触发",                 \
              "Pack及消防信号触发",                 \
              "行程开关触发故障",
              "系统初始化任务故障",    \
              "1MS任务故障",       \
              "10MS任务故障",      \

              "100MS任务故障",     \
              "100MS算法任务故障",
               "phy初始化故障",
               "高压Adc参考故障",
               "bmu地址分配故障",                 /*!< BMU address allocation error */
               "redundancyHvMeasurementTimeoutError",
               "cellCountDismatched",
               "BMU电池正极温度故障",
               "BMU电池正极温度故障",
               "bmu电池P+温度开路故障",
               "bmu电池P+温度短路故障",
               "bmu电池P-温度开路故障",
               "bmu电池P-温度短路故障",
               "contactorTripOpenError",
    };
    _BCUCAN_SysInfo_Module_DoDiStatus Data = { 0 };

    typedef   struct
    {
        uint8_t ErrorBitMap;
        uint8_t ErrorLevel;
        QString Name;
        QString ErrorAction; // 
    }_BCUError_SysInfo_Struct;

    typedef   struct
    {
        uint16_t MODBUS_ALARM_ERROR_I;
        uint16_t MODBUS_ALARM_ERROR_II;
        uint16_t MODBUS_ALARM_ERROR_III;
        uint16_t MODBUS_ALARM_ERROR_IV;
    }_BCUError_Error_InfoList;

public:
	ShowBCU(QWidget *parent = nullptr);
	~ShowBCU();
    void BCULogEnable(bool enable) { DataBaseEnable = enable; };
private:
   void UpdataAlarmMSLTable(uint32_t FaultData,uint32_t alarmLevel_H, uint32_t alarmLevel_M);
   void UpdataDODIStatusTable(_BCUCAN_SysInfo_Module_DoDiStatus *Data);
   void UpdataDIStatusTable(uint32_t Data);
   void UpdataSYSStatus(MOBUS_RUN_STATE_BASE_s_2 holding_reg_params2);
   void UpdateRunstatus(MOBUS_RUN_STATE_BASE_s holding_reg_params);
   void UpdateSystemBase(DEV_INFO_s  version_params);
   void InitMap(void);
   void LoadBCUDB();
   void AddBCUStatusTable(MOBUS_RUN_STATE_BASE_s holding_reg_params);
   void AddBCUAlarmTable(MOBUS_RUN_STATE_BASE_s_2 holding_reg_params);
   void InintErrorMap();

private:
   uint32_t AlarmBit = 0;
   uint16_t ErrorBit[6] = { 0 };
   UINT64  NewErrorBit[7] = { 0 };
   QLabel* labelStsIP;            // 版本信息
   QString statusTip = "";
   QMap<uint16_t, QString> bmsMasterSatusMap;
   QMap<uint16_t, QString> bmsSubSatusMap;
   QMap<uint16_t, QString> sysMasterSatusMap;
   QMap<uint16_t, QString> sysSubSatusMap;
   QMap<uint16_t, QString> errorReasonMap;
   QMap<uint16_t, QString> chgdhgStatusMap;
   QMap<uint16_t, QString> errorInfoMap;
   bool  DataBaseEnable = false;
private slots:
     void SlotsCanUpBCUMsg(uint Address, QByteArray val);
	 void SlotsUpMBShowBcu(uint startAddress, QVector<quint16> val);
     void SlotsAlarmSetMenu(uint startAddress);
     void SlotsResetMenu(uint startAddress);
     void SlotsOpenFANMenu(uint startAddress);
   public:
   //  virtual void mousePressEvent(QMouseEvent* event);
 
private:
	Ui::ShowBCUClass ui;
};
#endif