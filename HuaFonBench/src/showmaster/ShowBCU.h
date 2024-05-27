#ifndef _SHOW_BCU_H
#define _SHOW_BCU_H

#include <QMainWindow>
#include "ui_ShowBCU.h"
#include <QLabel>
#include <QFile>
#include "src/drvmng/StantCan_params.h"
class ShowBCU : public QMainWindow
{
	Q_OBJECT
public:
	ShowBCU(QWidget *parent = nullptr);
	~ShowBCU();
private:
   void UpdataAlarmMSLTable(uint32_t FaultData,uint32_t alarmLevel_H, uint32_t alarmLevel_M);
   void UpdataDODIStatusTable(_BCUCAN_SysInfo_Module_DoDiStatus *Data);
   void UpdataDIStatusTable(uint32_t Data);
   void UpdataSYSStatus(MOBUS_RUN_STATE_BASE_s_2 holding_reg_params2);
   void UpdateRunstatus(MOBUS_RUN_STATE_BASE_s holding_reg_params);
   void UpdateSystemBase(DEV_INFO_s  version_params);
   void InitMap(void);
private:
   uint32_t AlarmBit = 0;
   uint16_t ErrorBit[6] = { 0 };
   QLabel* labelStsIP;            // 版本信息
   QString statusTip = "";

   QMap<uint16_t, QString> bmsMasterSatusMap;
   QMap<uint16_t, QString> bmsSubSatusMap;
   QMap<uint16_t, QString> sysMasterSatusMap;
   QMap<uint16_t, QString> sysSubSatusMap;
   QMap<uint16_t, QString> errorReasonMap;
   QMap<uint16_t, QString> chgdhgStatusMap;


   /// <summary>
   /// 电池包过/欠 压 ----无？
   /// </summary>
   /// 缺----端子温度过高告警
   /// 缺----并机通讯告警 确认
   QList<QString>   alarmBitsList={
       "电芯过压",\
       "电芯欠压", \
       "电池包过压",
       "电池包欠压", \
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
       "soc低"};

   /** data block struct of error flags */
   typedef struct {                                       
       bool cellOverVoltageLimitError;
       bool cellUnderVoltageLimitError;
       bool envUnderTemperatureError;
       bool envOverTemperatureError;
       bool connectorBatteryMinusTemperatureError;
       bool connectorBatteryPlusTemperatureError;
       bool connectorPackMinusTemperatureError;
       bool connectorPackPlusTemperatureError;
       bool currentSensorTemperatureError;
       bool bcuPcbTemperatureError;
       bool bmuPcbTemperatureError;
       bool cellTemperatureSensorOpenError;
       bool cellTemperatureSensorShortError;
       bool pcbTemperatureSensorOpenError;
       bool pcbTemperatureSensorShortError;
       bool balanceTemperatureSensorOpenError;
       bool balanceTemperatureSensorShortError;
       bool bcuPower24VOverVoltageError;
       bool bcuPower24VUnderVoltageError;
       bool bcuPower5VOverVoltageError;
       bool bcuPower5VUnderVoltageError;
       bool balanceOverTemperatureError;
       bool balanceOpenError;
       bool balanceShortError;
       bool afeCommunicationError;                     /*!< false -> no error, true -> error */
       bool redundancyCellVoltageMeasurementTimeoutError;                  /*!< false -> no error, true -> error */
       bool redundancyCellTemperatureMeasurementTimeoutError;              /*!< false -> no error, true -> error */
       bool currentMeasurementTimeoutError;               /*!< false -> no error, true -> error */
       bool currentMeasurementInvalidError;               /*!< false -> no error, true -> error */
       bool fuseError;                              /*!< false -> fuse ok,  true -> fuse tripped */
       bool openWireDetectedError;                        /*!< false -> no error, true -> error */
       bool canRxQueueFullError;                                            /*!< false -> no error, true -> error */
       bool canTxQueueFullError;                                            /*!< false -> no error, true -> error */
       bool flashChecksumError;
       bool plausibilityCheckstringVoltageError;            /*!< false -> no error, true -> error */
       bool plausibilityCheckCellVoltageError;            /*!< false -> no error, true -> error */
       bool plausibilityCheckCellTemperatureError;        /*!< false -> no error, true -> error */
       bool currentSensorNotRespondingError;              /*!< false -> no error, true -> error */
       bool contactorMinusOpenError;                      /*!< false -> no error, true -> error */
       bool contactorPlusOpenError;                       /*!< false -> no error, true -> error */
       bool contactorMinusCloseError;                     /*!< false -> no error, true -> error */
       bool contactorPlusCloseError;                      /*!< false -> no error, true -> error */
       bool contactorPrechargeOpenError;                  /*!< false -> no error, true -> error */
       bool contactorChargeOpenError;                     /*!< false -> no error, true -> error */
       bool contactorPrechargeCloseError;                 /*!< false -> no error, true -> error */
       bool contactorChargeCloseError;                    /*!< false -> no error, true -> error */
       bool contactorIsoSwitchOpenError;
       bool contactorOverLoad;
       bool insulationMeasurementInvalidError;                              /*!< false -> no error, true -> error */
       bool prechargeFail;     /*!< false -> no error, true -> error */
       bool interlockOpenedError;
       bool faultLockError;
       bool lowSoh;
       bool i2cAdcError;
       bool i2cRtcError;                       /*!< problem in I2C communication with RTC */
       bool framCrcError;                  /*!< false if read CRC matches with CRC of read data, true otherwise */
       bool i2cFramError;                  /*!< false if read CRC matches with CRC of read data, true otherwise */
       bool rtcBatteryLowError;                /*!< RTC battery voltage is low */
       bool spiFlashError;
       bool spiCanError;
       bool bmuAddrError;
       bool bmuComError;
       bool adcRefError;
       bool bmuOffline;
       bool bmuModuleFanError;
       bool canBus;
       bool acCommunicationError;
       bool acStatusError;
       bool pcsCommunicationError;
       bool pcsStatusError;
       bool stopSwitch;
       bool waterIn;
       bool stringSmoke;
       bool stringWarm;
       bool stringFire;
       bool modlueFire;
       bool limitSwitch;
       bool taskEngineTimingViolationError;    /*!< timing violation in engine task */
       bool task1msTimingViolationError;       /*!< timing violation in 1ms task */
       bool task10msTimingViolationError;      /*!< timing violation in 10ms task */
       bool task100msTimingViolationError;     /*!< timing violation in 100ms task */
       bool task100msAlgoTimingViolationError; /*!< timing violation in 100ms algorithm task */
       bool phyInitError;
       bool exAdcRefError;
       bool bmuAddrAllocError;                 /*!< BMU address allocation error */
       bool redundancyHvMeasurementTimeoutError;
       bool cellCountDismatched;
       bool bmuBatPlusTemperatureError;
       bool bmuBatMinusTemperatureError;
       bool bmuBatPlusTemperatureOpenError;
       bool bmuBatPlusTemperatureShortError;
       bool bmuBatMinusTemperatureOpenError;
       bool bmuBatMinusTemperatureShortError;
       bool contactorTripOpenError;
   } DATA_BLOCK_ERROR_STATE_s;



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
       "PACK电压不合理",\
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
      "PCS通信故障（CAN）",       \
      "PCS状态故障（CAN）",              \
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