#ifndef _STANTCAN_PARAMS
#define _STANTCAN_PARAMS
#include <QObject>
#include <stdarg.h>     /* Needed for the definition of va_list */
#include "modbus_params.h"
#pragma pack(push)		// 保存原来的字节对齐方式
#pragma pack(1)		 	// 设置1字节对齐
typedef   struct
{
    uint32_t    FrameId;
    uint8_t Data[8]; // 数据
}_BCUCAN_RecData;
//#define 3.1.2 系统信息格式 ID:0x101-0x10F
typedef   struct
{
#define  _BCU_SYSSYN_ID_  (0x0)

    uint8_t Life; // 生命周期
    uint8_t BCUCtrlCmd; // 数据
    uint16_t BCUBlanceCmd; // 数据
    uint8_t BCUFanOpenTemp; // 数据
    uint8_t DOCmd; // 数据
    uint16_t Bak; // 数据
}_BCUCAN_SysSyn_;

typedef   struct
{
#define  _BCU_SYSInfo_ID_SN1  (0x1)
#define  _BCU_SYSInfo_ID_SN2  (0x2)
    uint8_t Sn1[8]; // 数据
    uint8_t Sn2[8]; // 数据
}_BCUCAN_SysInfo_SN;
typedef   struct
{
#define  _BCU_SYSInfo_ID_UUID1  (0x3)
#define  _BCU_SYSInfo_ID_UUID2  (0x4)
    uint8_t UUID1[8]; // 数据
    uint8_t UUID2[8]; // 数据
}_BCUCAN_SysInfo_UUID;
typedef   struct
{
#define  _BCU_SYSInfo_ID_PVersion  (0x5)
#define  _BCU_SYSInfo_ID_SVersion  (0x6)
    uint8_t ProtocolVerion[3]; // 协议版本号
    uint8_t SoftVerion[3]; // 协议版本号
    uint8_t BAK[2]; // 协议版本号
}_BCUCAN_SysInfo_SVersion;
typedef   struct
{
#define  _BCU_SYSInfo_ID_HBVersion  (0x7)
    uint8_t HwVerion[3]; // 协议版本号
    uint8_t BootVerion[3]; // 协议版本号
    uint8_t BAK[2]; // 协议版本号
}_BCUCAN_SysInfo_Hersion;

typedef   struct
{
 #define  _BCU_SYSInfo_ID_108 (0x8)
    uint8_t SystemBatteryType; // 系统电池类型
    uint8_t CellFactory; // 电芯厂家
    uint8_t Bak; // | 预留 |
    uint8_t ModuleToatalNum; // 模组数量
    uint8_t ModuleCellNum; // 模组单体个数
    uint8_t ModuleTempSensiorNum; // 模组单体个数
    uint16_t Bak1; // 预留
}_BCUCAN_SysInfo_ID_108;

typedef   struct
{
#define  _BCU_SYSInfo_ID_109 (0x9)
    uint32_t NominalEnergy; // 标称能量
    uint16_t NumCycle; // 循环次数
    uint16_t Bak; // 预留
}_BCUCAN_SysInfo_Module_109;

union _BCUCAN_DoStatus_Table {
    uint16_t Bitmap;
    struct {
        uint16_t NegativeContactor : 1;             //
        uint16_t PreChargeContactor : 1;             //
        uint16_t PosContactor : 1;             //
        uint16_t ChargeContactor : 1;            //
        uint16_t PowerContactor : 1;            //
        uint16_t HeartContactor : 1;            //
        uint16_t DryContact_1 : 1;            //
        uint16_t DryContact_2 : 1;            //
        uint16_t LS8 : 1;            //
        uint16_t LS5 : 1;
        uint16_t LS2 : 1;            //
        uint16_t LS1 : 1;
        uint16_t SlavePower : 1;            //
        uint16_t SlaveFan : 1;
        uint16_t V24 : 1;
        uint16_t BAK : 1;
    } Bits;
};

union _BCUCAN_DiStatus_Table {
    uint16_t Bitmap;
    struct {
        uint16_t ADDR_IN : 1;             //
        uint16_t SmokeSensor : 1;             //
        uint16_t EntranceSensor : 1;             //
        uint16_t HVLockSensor : 1;            //
        uint16_t WaterSensor : 1;            //
        uint16_t StopSensor : 1;            //
        uint16_t ButtonInput : 1;            //
        uint16_t MCUFTL4 : 1;
        uint16_t MCUFTL3 : 1;
        uint16_t MCUFTL2 : 1;
        uint16_t MCUFTL1 : 1;
        uint16_t bak : 5;
    } Bits;
};


typedef   struct
{
#define  _BCU_SYSInfo_ID_110 (0x10)
    _BCUCAN_DoStatus_Table DOStatus; // 
     uint8_t       bak;
    _BCUCAN_DoStatus_Table DOFbStatus; // 
     uint8_t       bak1;
    _BCUCAN_DiStatus_Table DIStatus; // 
}_BCUCAN_SysInfo_Module_DoDiStatus;
/** data block struct of the maximum safe limits */
union DATA_BLOCK_ALARM_FLAG_s {
    uint32_t All;
    struct {
        /* This struct needs to be at the beginning of every database entry. During
         * the initialization of a database struct, uniqueId must be set to the
         * respective database entry representation in enum DATA_BLOCK_ID_e. */
        uint32_t overCellVoltage : 1;                /*!< 0 -> MSL NOT violated, 1 -> MSL violated */
        uint32_t underCellVoltage : 1;               /*!< 0 -> MSL NOT violated, 1 -> MSL violated */
        uint32_t overPackVoltage : 1;                /*!< 0 -> MSL NOT violated, 1 -> MSL violated */
        uint32_t underPackVoltage : 1;               /*!< 0 -> MSL NOT violated, 1 -> MSL violated */
        uint32_t overModuleVoltage : 1;                /*!< 0 -> MSL NOT violated, 1 -> MSL violated */
        uint32_t underModuleVoltage : 1;               /*!< 0 -> MSL NOT violated, 1 -> MSL violated */
        uint32_t overtemperatureCharge : 1;      /*!< 0 -> MSL NOT violated, 1 -> MSL violated */
        uint32_t overtemperatureDischarge : 1;   /*!< 0 -> MSL NOT violated, 1 -> MSL violated */
        uint32_t undertemperatureCharge : 1;     /*!< 0 -> MSL NOT violated, 1 -> MSL violated */
        uint32_t undertemperatureDischarge : 1;  /*!< 0 -> MSL NOT violated, 1 -> MSL violated */
        uint32_t cellChargeOvercurrent : 1;      /*!< 0 -> MSL NOT violated, 1 -> MSL violated */
        uint32_t cellDischargeOvercurrent : 1;   /*!< 0 -> MSL NOT violated, 1 -> MSL violated */
        uint32_t overtemperatureDiff : 1; /*!< 0 -> MSL NOT violated, 1 -> MSL violated */
        uint32_t overcellVoltageDiff : 1; /*!< 0 -> MSL NOT violated, 1 -> MSL violated */
        uint32_t overtemperatureRise : 1; /*!< 0 -> MSL NOT violated, 1 -> MSL violated */
        uint32_t pcbOvertemperature : 1;         /*!< 0 -> MSL NOT violated, 1 -> MSL violated */
        uint32_t pcbUndertemperature : 1;        /*!< 0 -> MSL NOT violated, 1 -> MSL violated */
    }Bits;
} ;



typedef   struct
{
#define     _BCUCAN_RunInfo_Alarm_ID_111  (0x11)
    DATA_BLOCK_ALARM_FLAG_s MSL; // 标称能量
    DATA_BLOCK_ALARM_FLAG_s RSL;
}_BCUCAN_Alarm_Module_111;

typedef   struct
{
#define    _BCUCAN_RunInfo_Alarm_ID_112  (0x12)
    DATA_BLOCK_ALARM_FLAG_s MOL; // 标称能量
    uint32_t  Bak;
}_BCUCAN_Alarm_Module_112;


union _BCUCAN_BatteryStatus_Table {
    uint8_t All;
    struct {
        uint8_t ChargeStatus : 4;             //
        uint8_t IsCharge : 1;             //
        uint8_t IsDisCharge : 1;
        uint8_t ForceCharge : 1;
        uint8_t Bak : 1;            //
    } Bits;
};

typedef   struct
{
#define  _BCU_BatteryStatus_ID_113 (0x13)
    _BCUCAN_BatteryStatus_Table batteryStatus; // 
    uint16_t batteryVoltage_V; // 
    int16_t packCurrent_A; //
    uint8_t showSoc; // 
    uint8_t Soh; //
    uint8_t Soe; //
}_BCUCAN_SysStatus_Module;


typedef   struct
{
#define  _BCU_BatteryRunInfo_ID_114 (0x14)
    uint16_t maxBatteryVoltageThreshold; // 
    uint16_t minBatteryVoltageThreshold; // 
    uint16_t recommendedContinuousChargeCurrent; // 
    uint16_t recommendedContinuousDischargeCurrent; // 
}_BCU_BatteryRunInfo_Module_114;

typedef   struct
{
#define     _BCU_BatteryRunInfo_ID_115  (0x15)
    uint16_t maximumCellVoltage_mV; // 标称能量
    uint16_t minimumCellVoltage_mV; // 标称能量
    uint16_t maximumTemperature_ddegC; // 标称能量
    uint16_t minimumTemperature_ddegC; // 标称能量
}_BCU_BatteryRunInfo_Module_115;

typedef   struct
{
#define     _BCU_BatteryRunInfo_ID_116  (0x16)
    uint16_t averageCellVoltage_mV; // 平均单体电压 
    uint16_t averageTemperature_ddegC; // 平均单体温度
    uint32_t BAK; // 标称能量
}_BCU_BatteryRunInfo_Module_116;

typedef   struct
{
    #define  _BCU_BatteryRunInfo_ID_118  (0x18)
    uint8_t nrModuleMaximumCellVoltage; // 最大单体电压模组编号 
    uint8_t nrCellMaximumCellVoltage; // 最大单体电压模组内编号
    uint8_t nrModuleMinimumCellVoltage; // 最小单体电压模组编号
    uint8_t nrCellMinimumCellVoltage; // 最小单体电压模组内编号 
    uint8_t nrModuleMaximumTemperature; // 最大单体温度模组编号 
    uint8_t nrSensorMaximumTemperature; // 最大单体温度模组内编号
    uint8_t nrModuleMinimumTemperature; //最小单体温度模组编号
    uint8_t nrSensorMinimumTemperature;//最小单体温度模组内编号
}_BCU_BatteryRunInfo_Module_118;

typedef   struct
{
#define  _BCU_BatteryRunInfo_ID_119  (0x19)
    uint8_t errorStatus; // 最大单体电压模组编号 
}_BCU_BatteryRunInfo_Module_119;


typedef   struct
{
#define  _BCUCAN_CapStatus_Module_ID_1A1  (0xA1)
    uint32_t accChargeCapacity; // 累计充电容量
    uint32_t accDischargeCapacity; // 累计放电容量
}_BCUCAN_CapStatus_Module_1A1;


typedef   struct
{
#define  _BCUCAN_CapStatus_Module_ID_1A2  (0xA2)
    uint32_t factoryFullCapacity; // 系统总总容量
    uint8_t  errorStatus[4]; // 累计放电容量
}_BCUCAN_CapStatus_Module_1A2;

typedef   struct
{
#define  _BCUCAN_HvStatus_Module_ID_1A3  (0xA3)
    uint16_t current; // 系统总总容量
    uint16_t BVoltage_V;
    uint16_t PVoltage_V;
    uint16_t AccVoltage_V; // 累计放电容量
}_BCUCAN_HvStatus_Module_1A3;


typedef   struct
{
#define  _BCUCAN_HvStatus_Module_ID_1A4  (0xA4)
    uint16_t insulationResistance_n_kOhm; // B+绝缘等效电阻
    uint16_t insulationResistance_p_kOhm; //B-绝缘等效电阻
    uint8_t isInsulationMeasurementValid; // 可信度
    uint8_t BAK[3]; // 累计放电容量
}_BCUCAN_HvStatus_Module_1A4;

#define LECU_MAX_VOL (64)
#define LECU_MAX_TEMP (64)     
typedef   struct
{
    uint32_t FrameId;
    uint8_t SegmentIndex; //分段索引
    uint8_t Data[7]; // 数据
}BMU_CAN_RecData;

typedef   struct
{
    uint32_t FrameId;
    uint16_t SegmentIndex; //分段索引
    uint8_t length; // 数据
    uint8_t DataIndex; // 数据
    uint8_t Data[4]; // 数据
}BMU_CAN_RecMngData;

typedef   struct
{
    uint32_t FrameId;
    uint8_t SegmentIndex; //分段索引
    uint8_t Data[7]; // 数据

}BMU_CAN_RecMngData_Index;


typedef   struct
{
    uint32_t FrameId;
    uint16_t SegmentIndex; //分段索引
    uint8_t length; // 数据
    uint32_t Data; // 数据
}BMU_CAN_RecMngData_2;


typedef union {
    uint16_t bmu_volatge_map;
    struct {
        uint16_t volatage_val : 14;             //
        uint16_t blance : 1;             //
        uint16_t connsta : 1;             //
    } Val;
}bmu_volatge_t;
typedef  struct {
    bmu_volatge_t volt_1;
    bmu_volatge_t volt_2;
    bmu_volatge_t volt_3;
    uint8_t bak;
}bmu_volatge_segment;
typedef  struct {
    int16_t temp_1;
    int16_t temp_2;
    int16_t temp_3;
    uint8_t bak;
}bmu_temp_segment;
typedef  struct {
    uint16_t BatTotalVolt;
    int16_t BatCurrent;
    uint8_t DoStatus;
    uint8_t DiStatus;
    uint8_t ErrStatus;
}_A0packMinMaxInfo;

typedef  struct {
    uint16_t MaxCellVolt;
    uint16_t MinCellVolt;
    uint16_t AvgCellVolt;
    uint8_t StdDevVolt;
}_A1packMinMaxInfo;


typedef  struct {
    int16_t MaxCellTemp;
    int16_t MinCellTemp;
    int16_t AvgCellTemp;
    int8_t StdDevTemp;
}_A2packMinMaxInfo;

typedef  struct {
    uint8_t NrMaxCellVolt;
    uint8_t NrMinCellVolt;
    uint8_t NrMaxCellTemp;
    uint8_t NrMinCellTemp;
    uint8_t BalancePosition;
    uint8_t OpenWirePosition;
    uint8_t bak;
}_A3packMinMaxInfo;

typedef  struct {
    _A0packMinMaxInfo A0;
    _A1packMinMaxInfo A1;
    _A2packMinMaxInfo A2;
    _A3packMinMaxInfo A3;
}_RealpackMinMaxInfo;



typedef  struct {
    uint8_t UseBatCount;
    uint8_t UseTempCount;
    uint8_t SN[5];
}_F0Sn;


typedef  struct {
    uint8_t SN[7];
}_F1Sn;

typedef  struct {
    uint8_t SN[4];
    uint8_t UUID[3];
}_F2Sn_UUID;

typedef  struct {
    uint8_t UUID[7];
}_F3_UUID;

typedef  struct {
    uint8_t UUID[7];
}_F4UUID;

typedef  struct {
    uint8_t SoftWareVerion[6];
    uint8_t bak;
}_F5SoftWareVerion;

typedef  struct {
    uint8_t HardWareVerion[6];
    uint8_t bak;
}_F6HardWareVerion;

typedef  struct {
    uint8_t BootVersion[6];
    uint8_t bak;
}_F7BootVersion;

typedef  struct {
    uint8_t BootVersion[6];
    uint8_t bak;
}_F8ProtocolVersion;

typedef  struct {
    _F0Sn F0Sn;
    _F1Sn F1Sn;
    _F2Sn_UUID F2Sn_UUID;
    _F3_UUID F3_UUID;
    _F4UUID F4UUID;
    _F5SoftWareVerion F5SoftWareVerion;
    _F6HardWareVerion  F6HardWareVerion;
    _F7BootVersion F7BootVersion;
    _F8ProtocolVersion F8ProtocolVersion;
}_gDevInfo;

typedef  struct {
uint8_t  UseBatCount;
uint8_t  UseTempCount;
uint8_t  SN[16];               /* serial number */
uint8_t  UUID[16];             /* device type */
uint8_t  SoftWareVerion[6];    /* software version */
uint8_t  HardWareVerion[6];    /* hardware version */
uint8_t  BootVersion[6];       /* Boot version*/
uint8_t  ProtocolVersion[6];   /* protocol version*/
}_F0DevInfo;

typedef  struct {
    uint16_t  BatTotalVolt;
    uint16_t  BatCurrent;
    uint8_t   DoStatus;
    uint8_t   DiStatus;
    uint8_t   ErrStatus;
}_PackDetailStatus;

typedef struct
{
    bool      Vaild;
    uint16_t  Keeplive;
    uint16_t  Nowlive;
    uint16_t  BatVols[LECU_MAX_VOL];
    uint8_t   CellBlance[LECU_MAX_VOL];
    uint8_t   CellCnnStatus[LECU_MAX_VOL];
    int16_t   BatTemps[LECU_MAX_TEMP];
    _PackDetailStatus PackDetailStatus;
    MODBUS_BMU_STATUS_s BmuStatus;
    _BMU_DEV_INFO_s     BmuInfo;
}_PackDetailInfoST;

#pragma pack(pop)
#endif
