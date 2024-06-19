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
    typedef enum
    {
        NO_Alarm=0,
        Alarm_MOL =1,
        Alarm_MSL =2,
        Alarm_RSL =3,
    }T_Alarm_Type;
    T_Alarm_Type m_alarm_type = NO_Alarm;
    _BCUCAN_SysInfo_Module_DoDiStatus Data = { 0 };
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
  // UINT64  NewErrorBit[7] = { 0 };
   uint16_t  NewErrorBit[9] = { 0 };
   QLabel* labelStsIP;            // 版本信息
   QString statusTip = "";
   QMap<uint16_t, QString> bmsMasterSatusMap;
   QMap<uint16_t, QString> bmsSubSatusMap;
   QMap<uint16_t, QString> sysMasterSatusMap;
   QMap<uint16_t, QString> sysSubSatusMap;
   QMap<uint16_t, QString> errorReasonMap;
   QMap<uint16_t, QString> chgdhgStatusMap;
   QMap<uint16_t, QString> errorInfoMap;
   QMap<uint16_t, QString> errorActioMap;
   QMap<uint16_t, QString> errorItemInfoMap;
   bool  DataBaseEnable = false;
   QString uuid;
private slots:
     void SlotsCanUpBCUMsg(uint Address, QByteArray val);
	 void SlotsUpMBShowBcu(uint startAddress, QVector<quint16> val);
     void SlotsAlarmSetMenu(uint startAddress);
     void SlotsResetMenu(uint startAddress);
     void SlotsOpenFANMenu(uint startAddress);
   public:
   //  virtual void mousePressEvent(QMouseEvent* event);
signals:
    //向上层传送消息
    void signalAlarmLogInfoProcess(uint16_t alarm[3],uint16_t error[9]);
private:
	Ui::ShowBCUClass ui;
};
extern _BCUDetailInfoST     g_BCUDetailInfoST;
#endif