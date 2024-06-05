/*=====================================================================================
 * Description:
 *   The Modbus parameter structures used to define Modbus instances that
 *   can be addressed by Modbus protocol. Define these structures per your needs in
 *   your application. Below is just an example of possible parameters.
 *====================================================================================*/
#ifndef _DEVICE_PARAMS
#define _DEVICE_PARAMS
#include <QObject>
#include <stdarg.h>     /* Needed for the definition of va_list */

#define  MAX_BMU_NUM      (20)
#define  CALIBRATION_RANGE_MAX_COUNT  (10)
#define BS_NR_OF_MODULES_PER_STRING (12)  
#define BS_NR_OF_CELL_BLOCKS_PER_MODULE (16)
#define BS_NR_OF_TEMP_BLOCKS_PER_MODULE (16)
#define BS_NR_OF_STATUS_BLOCKS_PER_MODULE (sizeof(MODBUS_BMU_STATUS_s)/2)

#define BS_NR_OF_TEMP_SENSORS_PER_STRING (BS_NR_OF_MODULES_PER_STRING * BS_NR_OF_CELL_BLOCKS_PER_MODULE)
#define BS_NR_OF_CELL_BLOCKS_PER_STRING (BS_NR_OF_MODULES_PER_STRING * BS_NR_OF_CELL_BLOCKS_PER_MODULE)

#pragma pack(push)		// 保存原来的字节对齐方式
#pragma pack(1)		 	// 设置1字节对齐
typedef enum
{
	MBDG_TYPE_U8,
	MBDG_TYPE_S8,
	MBDG_TYPE_U16,
	MBDG_TYPE_S16,
	MBDG_TYPE_U32,
	MBDG_TYPE_STR,
}T_Data_Type;


typedef enum _Drv_Status
{
	_UnCnn = 0x0,//0x01：OTA升级请求
	_CanCnn = 0x1,//
	_EthCnn = 0x2,//
};
/* 读写属性定义 */
typedef enum
{
	READ_ONLY = 1,
	WRITE_ONLY,
	RW_BOTH,
}E_Attribute;
typedef struct
{
	uint16_t uRegAddr;
	uint16_t uRegLen;
	uint16_t uType;
	uint16_t uRate;
	uint16_t uAttr;
	void* pData;
	void (*pFunc)();
}T_MB_Para;
typedef enum {
	PAR_PERMS_READ ,                                   /**< the characteristic of the device are readable */
	PAR_PERMS_WRITE ,                                   /**< the characteristic of the device are writable*/
	PAR_PERMS_TRIGGER ,                                   /**< the characteristic of the device are triggerable */
	PAR_PERMS_READ_WRITE ,            /**< the characteristic of the device are readable & writable */
	PAR_PERMS_READ_TRIGGER ,          /**< the characteristic of the device are readable & triggerable */
	PAR_PERMS_WRITE_TRIGGER ,         /**< the characteristic of the device are writable & triggerable */
	PAR_PERMS_READ_WRITE_TRIGGER ,    /**< the characteristic of the device are readable & writable & triggerable */
} mb_param_perms_t;

typedef enum {
	PARAM_TYPE_U8 = 0x00,                   /*!< Unsigned 8 */
	PARAM_TYPE_U16 = 0x01,                  /*!< Unsigned 16 */
	PARAM_TYPE_U32 = 0x02,                  /*!< Unsigned 32 */
	PARAM_TYPE_FLOAT = 0x03,                /*!< Float type */
	PARAM_TYPE_ASCII = 0x04                 /*!< ASCII type */
} mb_descr_type_t;
typedef enum {
	PARAM_SIZE_U8 = 0x01,                   /*!< Unsigned 8 */
	PARAM_SIZE_U16 = 0x02,                  /*!< Unsigned 16 */
	PARAM_SIZE_U32 = 0x04,                  /*!< Unsigned 32 */
	PARAM_SIZE_FLOAT = 0x04,                /*!< Float size */
	PARAM_SIZE_ASCII = 0x08,                /*!< ASCII size */
	PARAM_SIZE_ASCII24 = 0x18,              /*!< ASCII24 size */
	PARAM_MAX_SIZE
} mb_descr_size_t;
typedef union {
	struct {
		int opt1;                         /*!< Parameter option1 */
		int opt2;                         /*!< Parameter option2 */
		int opt3;                         /*!< Parameter option3 */
	};
	struct {
		int min;                          /*!< Parameter minimum value */
		int max;                          /*!< Parameter maximum value */
		int step;                         /*!< Step of parameter change tracking */
	};
} mb_parameter_opt_t;
 // Enumeration of all supported CIDs for device (used in parameter definition table)
enum
{
	CID_HOLD_STA_REG = 0,
	CID_HOLD_VOLT_REG,
	CID_HOLD_TEMP_REG,
	CID_HOLD_SYS_REG,
	CID_HOLD_PROCTER_REG,
	CID_HOLD_ALARM_REG,
	CID_HOLD_RESET_CMD,
	CID_HOLD_SLEEPMODE_CMD,
	CID_HOLD_SLEEPTIME_CMD,
	CID_HOLD_TEMPMAXPROCT_CMD,
	CID_HOLD_SNSET_CMD,
	CID_HOLD_CLEAR_CFG,
};
enum
{
	MB_DEVICE_ADDR1 = 1 // Only one slave device used for the test (add other slave addresses here)
};

typedef struct {
#define MODBUS_SYSTEM_BASE                  (0x0000)
	uint8_t sn[16];               /* serial number */
	uint8_t uuid[16];             /* device type */
	uint8_t softwareVerion[6];   /* software version */
	uint8_t bootVerion[6];   /* hardware version */
	uint8_t hardwareVerion[6];   /* hardware version */
	uint8_t protocolVersion[6];   /* protocol version */
} DEV_INFO_s;

typedef struct
{
#define MODBUS_BMU_BASE           (0x100)
	uint16_t  UseBatCount;
	uint16_t  UseTempCount;
	uint8_t  SN[16];               /* serial number */
	uint8_t  UUID[16];             /* device type */
	uint8_t  SoftWareVerion[6];    /* software version */
	uint8_t  HardWareVerion[6];    /* hardware version */
	uint8_t  BootVersion[6];       /* Boot version*/
	uint8_t  ProtocolVersion[6];   /* protocol version*/
	uint8_t  Sum;
	uint8_t  Reserved;
}_BMU_DEV_INFO_s;

typedef struct {
#define MODBUS_COMM_BASE                    (0x500)
	uint16_t  can1Baudrate;
	uint16_t  can2Baudrate;
	uint16_t  can3Baudrate;
	uint16_t  rs485_1Baudrate;
	uint16_t  rs485_2Baudrate;
	uint16_t  rs485_3Baudrate;
} COM_CFG_s;

/* define net address type */
typedef struct {
	uint32_t addr;
	uint16_t port;
} NETADDR_s;
/* define ethernet config type */
typedef struct {
	uint32_t mode;        /* 0: dhcp; 1:static */
	uint32_t ip;
	uint32_t mask;
	uint32_t gateway;
	uint8_t  mac[6];
} NET_CFG_s;

/* define net parameter type */
typedef struct {
#define MODBUS_NET_BASE                     (0x550)
	/* local net configuration parameter */
	NET_CFG_s local;
	/* tcp server address */
	NETADDR_s tcphost;
	NETADDR_s udphost;
	/* udp multicast address */
	NETADDR_s multicast;
} NET_PARAM_s;

typedef struct {
#define MODBUS_SOC_BASE                     (0x580)
	uint16_t  socSetVoltage;
	uint16_t  socClearVoltage;
	uint16_t  socSetMinCurrent;
	uint16_t  socClearMinCurrent;
	uint16_t  socDynamicCorrectChargeSoc;
	uint16_t  socDynamicCorrectChargeCurrentDelayTime;
	uint16_t  socDynamicCorrectDischargeSoc;
	uint16_t  socDynamicCorrectDischargeCurrentDelayTime;
	uint32_t  socStaticCorrectIdleTime;
} SOC_CFG_s;

typedef struct {
#define MODBUS_BALANCE_BASE                 (0x600)
	uint16_t  balanceType;
	uint16_t  balanceAlgType;
	uint16_t  balanceMaxVoltage;
	uint16_t  balanceMinVoltage;
	uint16_t  balanceMaxCurrent;
	uint16_t  balanceOnVoltageDiff;
	uint16_t  balanceOffVoltageDiff;
} BALANCE_CFG_s;
/* define ethernet config type */

typedef struct {
#define MODBUS_SENSOR_BASE                  0x630
	uint16_t  currentSensorType;
	float_t  currentSensorFactor;
	uint16_t  voltageSensorType;
	float_t  voltageSensorFactor;
	uint16_t  temperatureSensorType;
} SENSOR_CFG_s;

typedef struct {
#define MODBUS_BATTERY_BASE                 (0x660)
	uint16_t  batteryType;
	uint16_t  batteryMaker;
	uint32_t  batteryRatedCapacity;
	uint32_t  batteryRatedEnergy;
	uint16_t  batteryRatedVoltage;
	uint16_t  cellsCountPerParallel;
	uint16_t  cellsCountPerModule;
	uint16_t  tempsCountPerModule;
	uint16_t  modulesCountPerString;
	uint16_t  chargeMaximumBatteryVoltage;
	uint16_t  chargeMaximumCellVoltage;
	uint16_t  dischargeMinimumBatteryVoltage;
	uint16_t  dischargeMinimumCellVoltage;
	uint16_t  dischargeMaximumCurrent;
	uint16_t  chargeMaximumCurrent;
	int16_t   dischargeMaximumTemperature;
	int16_t   dischargeMinimumTemperature;
	int16_t   chargeMaximumTemperature;
	int16_t   chargeMinimumTemperature;
} BATTERY_CFG_s;

typedef struct {
	//float_t  minimumValue;
	//float_t  maximumValue;
	//float_t  k;
	//float_t  b;
   uint32_t  minimumValue;
   uint32_t  maximumValue;
   uint32_t  k;
   uint32_t  b;
} CALIBRATION_RANGE_s;
typedef struct {
#define MODBUS_CALIBRATION_BASE             (0x1000)
	uint16_t currentMask;
	uint16_t batteryVoltageMask;
	uint16_t packVoltageMask;
	uint16_t temperatureCurrentSensorMask;
	uint16_t temperatureExternEnvMask;
	uint16_t temperaturePackMinusMask;
	uint16_t temperaturePackPlusMask;
	uint16_t temperatureBatteryMinusMask;
	uint16_t temperatureBatteryPlusMask;
	CALIBRATION_RANGE_s  current[CALIBRATION_RANGE_MAX_COUNT];
	CALIBRATION_RANGE_s  batteryVoltage[CALIBRATION_RANGE_MAX_COUNT];
	CALIBRATION_RANGE_s  packVoltage[CALIBRATION_RANGE_MAX_COUNT];
	CALIBRATION_RANGE_s  temperatureCurrentSensor[CALIBRATION_RANGE_MAX_COUNT];
	CALIBRATION_RANGE_s  temperatureExternEnv[CALIBRATION_RANGE_MAX_COUNT];
	CALIBRATION_RANGE_s  temperaturePackMinus[CALIBRATION_RANGE_MAX_COUNT];
	CALIBRATION_RANGE_s  temperaturePackPlus[CALIBRATION_RANGE_MAX_COUNT];
	CALIBRATION_RANGE_s  temperatureBatteryMinus[CALIBRATION_RANGE_MAX_COUNT];
	CALIBRATION_RANGE_s  temperatureBatteryPlus[CALIBRATION_RANGE_MAX_COUNT];
} SENSOR_CALIBRATION_s;



typedef struct {
	uint16_t  triggerThreshold;
	uint16_t  triggerFilterTimeMs;
	uint16_t  releaseThreshold;
	uint16_t  releaseFilterTimeMs;
} THRESHOLD_UINT16_s;

typedef struct {
	int16_t   triggerThreshold;
	uint16_t  triggerFilterTimeMs;
	uint16_t  releaseThreshold;
	uint16_t  releaseFilterTimeMs;
} THRESHOLD_INT16_s;

typedef struct {
	int32_t   triggerThreshold;
	uint16_t  triggerFilterTimeMs;
	int32_t  releaseThreshold;
	uint16_t  releaseFilterTimeMs;
} THRESHOLD_INT32_s;


typedef struct {
	uint32_t  triggerThreshold;
	uint16_t  triggerFilterTimeMs;
	uint32_t  releaseThreshold;
	uint16_t  releaseFilterTimeMs;
} THRESHOLD_UINT32_s;

typedef struct {
#define MODBUS_FAULTLIMIT_I_BASE            (0x2000)
  THRESHOLD_INT16_s  dischargeMaxTemperature;
  THRESHOLD_INT16_s  dischargeMinTemperature;
  THRESHOLD_INT16_s  chargeMaxTemperature;
  THRESHOLD_INT16_s  chargeMinTemperature;
  THRESHOLD_INT32_s  chargeMaxCurrent;
  THRESHOLD_INT32_s  dischargeMaxCurrent;
  THRESHOLD_UINT16_s diffTemperature;
  THRESHOLD_UINT16_s diffVoltage;
  THRESHOLD_UINT16_s riseTemperature;
  THRESHOLD_UINT16_s maxCellVoltage;
  THRESHOLD_UINT16_s minCellVoltage; 
  THRESHOLD_UINT16_s maxModuleVoltage;
  THRESHOLD_UINT16_s minModuleVoltage;
  THRESHOLD_UINT16_s maxBatteryVoltage;
  THRESHOLD_UINT16_s minBatteryVoltage;
  THRESHOLD_UINT16_s lowSoc;
  THRESHOLD_INT32_s  insulationResistance;
} MSL_CFG_s;
typedef struct {
#define MODBUS_FAULTLIMIT_II_BASE           (0x2200)
	THRESHOLD_INT16_s  dischargeMaxTemperature;
	THRESHOLD_INT16_s  dischargeMinTemperature;
	THRESHOLD_INT16_s  chargeMaxTemperature;
	THRESHOLD_INT16_s  chargeMinTemperature;
	THRESHOLD_INT32_s  chargeMaxCurrent;
	THRESHOLD_INT32_s  dischargeMaxCurrent;
	THRESHOLD_UINT16_s diffTemperature;
	THRESHOLD_UINT16_s diffVoltage;
	THRESHOLD_UINT16_s riseTemperature;
	THRESHOLD_UINT16_s maxCellVoltage;
	THRESHOLD_UINT16_s minCellVoltage;
	THRESHOLD_UINT16_s maxModuleVoltage;
	THRESHOLD_UINT16_s minModuleVoltage;
	THRESHOLD_UINT16_s maxBatteryVoltage;
	THRESHOLD_UINT16_s minBatteryVoltage;
	THRESHOLD_UINT16_s lowSoc;
	THRESHOLD_INT32_s  insulationResistance;
} RSL_CFG_s;
typedef struct {
    #define MODBUS_FAULTLIMIT_III_BASE          (0x2400)
	THRESHOLD_INT16_s  dischargeMaxTemperature;
	THRESHOLD_INT16_s  dischargeMinTemperature;
	THRESHOLD_INT16_s  chargeMaxTemperature;
	THRESHOLD_INT16_s  chargeMinTemperature;
	THRESHOLD_INT32_s  chargeMaxCurrent;
	THRESHOLD_INT32_s  dischargeMaxCurrent;
	THRESHOLD_UINT16_s diffTemperature;
	THRESHOLD_UINT16_s diffVoltage;
	THRESHOLD_UINT16_s riseTemperature;
	THRESHOLD_UINT16_s maxCellVoltage;
	THRESHOLD_UINT16_s minCellVoltage;
	THRESHOLD_UINT16_s maxModuleVoltage;
	THRESHOLD_UINT16_s minModuleVoltage;
	THRESHOLD_UINT16_s maxBatteryVoltage;
	THRESHOLD_UINT16_s minBatteryVoltage;
	THRESHOLD_UINT16_s lowSoc;
	THRESHOLD_INT32_s  insulationResistance;
} MOL_CFG_s;

typedef enum
{
	overCellVoltage = 0,
	underCellVoltage,
	overPackVoltage,
	underPackVoltage,
	overModuleVoltage,
	underModuleVoltage,
	overtemperatureCharge,
	overtemperatureDischarge,
	undertemperatureCharge,
	undertemperatureDischarge,
	cellChargeOvercurrent,
	cellDischargeOvercurrent,
	overtemperatureDiff,
	overcellVoltageDiff,
	overtemperatureRise,
	insulation_p,
	insulation_n,
	socLow
}Alarm_Bit;
/** data block struct of error flags */
# if 0
typedef enum {
	cellOverVoltageLimitError,
	cellUnderVoltageLimitError,
	envUnderTemperatureError,
	envOverTemperatureError,
	connectorBatteryMinusTemperatureError,
	connectorBatteryPlusTemperatureError,
	connectorPackMinusTemperatureError,
	connectorPackPlusTemperatureError,
	currentSensorTemperatureError,
	bcuPcbTemperatureError,
	bmuPcbTemperatureError,
	cellTemperatureSensorOpenError,
	cellTemperatureSensorShortError,
	pcbTemperatureSensorOpenError,
	pcbTemperatureSensorShortError,
	balanceTemperatureSensorOpenError,

	balanceTemperatureSensorShortError,
	bcuPower24VOverVoltageError,
	bcuPower24VUnderVoltageError,
	bcuPower5VOverVoltageError,
	bcuPower5VUnderVoltageError,
	balanceOverTemperatureError,
	balanceOpenError,
	balanceShortError,
	afeCommunicationError,                     /*!< false -> no error, true -> error */
	redundancyCellVoltageMeasurementTimeoutError,                  /*!< false -> no error, true -> error */
	redundancyCellTemperatureMeasurementTimeoutError,              /*!< false -> no error, true -> error */
	currentMeasurementTimeoutError,               /*!< false -> no error, true -> error */
	currentMeasurementInvalidError,               /*!< false -> no error, true -> error */
	fuseError,                              /*!< false -> fuse ok,  true -> fuse tripped */
	openWireDetectedError,                        /*!< false -> no error, true -> error */
	canRxQueueFullError,                                            /*!< false -> no error, true -> error */
	canTxQueueFullError,                                            /*!< false -> no error, true -> error */
	flashChecksumError,
	plausibilityCheckPackVoltageError,            /*!< false -> no error, true -> error */
	plausibilityCheckCellVoltageError,            /*!< false -> no error, true -> error */
	plausibilityCheckCellTemperatureError,        /*!< false -> no error, true -> error */
	currentSensorNotRespondingError,              /*!< false -> no error, true -> error */
	contactorMinusOpenError,                      /*!< false -> no error, true -> error */
	contactorPlusOpenError,                       /*!< false -> no error, true -> error */
	contactorMinusCloseError,                     /*!< false -> no error, true -> error */
	contactorPlusCloseError,                      /*!< false -> no error, true -> error */
	contactorPrechargeOpenError,                  /*!< false -> no error, true -> error */
	contactorChargeOpenError,                     /*!< false -> no error, true -> error */
	contactorPrechargeCloseError,                 /*!< false -> no error, true -> error */
	contactorChargeCloseError,                    /*!< false -> no error, true -> error */
	contactorIsoSwitchOpenError,
	contactorOverLoad,
	insulationMeasurementInvalidError,                              /*!< false -> no error, true -> error */
	prechargeFail,     /*!< false -> no error, true -> error */
	interlockOpenedError,
	faultLockError,
	lowSoh,
	i2cAdcError,
	i2cRtcError,                       /*!< problem in I2C communication with RTC */
	framCrcError,                  /*!< false if read CRC matches with CRC of read data, true otherwise */
	i2cFramError,                  /*!< false if read CRC matches with CRC of read data, true otherwise */
	rtcBatteryLowError,                /*!< RTC battery voltage is low */
	spiFlashError,
	spiCanError,
	bmuAddrError,
	bmuComError,
	adcRefError,
	bmuOffline,
	bmuModuleFanError,
	canBus,
	acCommunicationError,
	acStatusError,
	pcsCommunicationError,
	pcsStatusError,
	stopSwitch,
	waterIn,
	stringSmoke,
	stringWarm,
	stringFire,
	modlueFire,
	limitSwitch,
	taskEngineTimingViolationError,    /*!< timing violation in engine task */
	task1msTimingViolationError,       /*!< timing violation in 1ms task */
	task10msTimingViolationError,      /*!< timing violation in 10ms task */
	task100msTimingViolationError,     /*!< timing violation in 100ms task */
	task100msAlgoTimingViolationError, /*!< timing violation in 100ms algorithm task */
} Alarm_Error_Bit;
#endif
typedef struct {
#define MODBUS_FAULT_RECODE_FLAG               (0x2800)
	uint64_t forceLockError;
} FAULT_RECODE_FLAG_s;


typedef struct
{
	// 数据模拟
#define MODBUS_DATA_SIM               (0x2810)
	uint16_t modbusSimCurrentType;
	uint16_t modbusSimCurrent_A;
	uint16_t modbusSimInsulationType;
	uint16_t modbusSimInsulationkom;
	uint16_t modbusSimBcuTemperaturesType;
	int16_t modbusSimBcuTemperatures_ddegC;
	uint16_t modbus_SimCellVoltageType;
	uint16_t modbus_SimCellVoltageBmuIndex;
	uint16_t modbus_SimCellVoltageCellIndex;
	uint16_t modbus_SimCellVoltage_mv;
	uint16_t modbus_SimCellTemperatureType;
	uint16_t modbus_SimCellTemperatureBmuIndex;
	uint16_t modbus_SimCellTemperatureCellIndex;
	uint16_t modbus_SimCellTemperature_ddegC;
	uint16_t modbusSimStringVoltageType;
	uint16_t modbusSimStringVoltage_V;
	uint16_t modbusSimSoxType;
	uint16_t modbusSimSox;
} MODBUS_DATA_SIM_s;

typedef struct {
#define MODBUS_RUN_STATE_BASE               (0x3000)
	uint16_t	MODBUS_CLUSTER_VOLT;        /**< 总电压   0.1V */
	int16_t	    MODBUS_CLUSTER_CUR;                       /**< 电流    int16 0.1A*/
	uint16_t	MODBUS_BATTERY_STATE;                           /**< 电池状态"高8位：0-静止，1-放电，2-充电，3-故障 低8位：0-"*/
	uint16_t	MODBUS_CONTACTOR_STATE;                         /**< 接触器状态"：0-闭合，1-断开"*/
	uint16_t	MODBUS_INPUT_STATE;                             /**< 輸入信號状态"：0-闭合，1-断开"*/
	uint16_t	MODBUS_SOC;                                    /**< 0.01 */
	uint16_t	MODBUS_SOH;                                     /**< 0.01 */
	uint16_t	MODBUS_SOE;                                    /**< 0.01 */
	uint16_t	MODBUS_CYCLE;                                   /**< 循环次数 */
	uint16_t	MODBUS_MAX_CHG_VOLT;                            /**< 最大允许充电电压 0.1V */
	uint16_t	MODBUS_MIN_DHG_VOLT;                            /**< 最小允许放电电压 0.1V */
	uint16_t	MODBUS_MAX_CHG_CUR;                             /**< 最大允许充电电流 0.1A */
	uint16_t	MODBUS_MAX_DHG_CUR;                             /**< 最大允许放电电流 0.1A */
	uint16_t	MODBUS_MAX_S_VOLT;                              /**< 最大单体电压 mv */
	uint16_t	MODBUS_MIN_S_VOLT;                              /**< 最小单体电压 mv */
	uint16_t	MODBUS_AVERAGE_S_VOLT;                          /**< 平均单体电压 mv */
	int16_t	    MODBUS_MAX_S_TEMP;                             /**< 最大单体温度 0.1°C */
	int16_t	    MODBUS_MIN_S_TEMP;                              /**< 最小单体温度 0.1°C */
	uint16_t	MODBUS_AVERAGE_S_TEMP;                          /**< 平均单体温度 0.1°C */
	uint16_t	MODBUS_MAX_M_VOLT;                              /**< 最大模组电压 mv */
	uint16_t	MODBUS_MIN_M_VOLT;                              /**< 最小模组电压 mv */
	uint16_t	MODBUS_AVERAGE_M_VOLT;                          /**< 平均模组电压 mv */
	uint16_t	MODBUS_MAX_S_VOLT_M_ADDR;                       /**< 最大单体电压所在模组编号*/
	uint16_t	MODBUS_MAX_S_VOLT_CELL_ADDR;                    /**< 最大单体电压所在电芯编号 */
	uint16_t	MODBUS_MIN_S_VOLT_M_ADDR;                       /**< 最小单体电压所在模组编号 */
	uint16_t	MODBUS_MIN_S_VOLT_CELL_ADDR;                    /**< 最小单体电压所在电芯编号 */
	uint16_t	MODBUS_MAX_S_TEMP_M_ADDR;                       /**< 最大单体温度所在模组编号 */
	uint16_t	MODBUS_MAX_S_TEMP_CELL_ADDR;                    /**< 最大单体温度所在电芯编号 */
	uint16_t	MODBUS_MIN_S_TEMP_M_ADDR;                       /**< 最小单体温度所在模组编号 */
	uint16_t	MODBUS_MIN_S_TEMP_CELL_ADDR;                    /**< 最小单体温度所在电芯编号*/
	uint16_t	MODBUS_MAX_M_VOLT_ADDR;                         /**< 最大模组电压编号 */
	uint16_t	MODBUS_MIN_M_VOLT_ADDR;                         /**< 最小模组电压编号 */
	uint16_t	MODBUS_P_VOLT;                                  /**< P+总压 0.1V */
	uint16_t	MODBUS_INSULATION_STATE;                       /**< 绝缘状态字"：0-闭合，1-断开" */
	uint16_t	MODBUS_POSITIVE_BUS_RESISTANCE;                 /**< 正母线电阻 */
	uint16_t	MODBUS_NEGATIVE_BUS_RESISTANCE;                 /**< 负母线电阻 */
	uint32_t	MODBUS_ALL_CHG_AH_L;                            /**< 累计充电容量低16 0.1AH */
	uint32_t	MODBUS_ALL_DHG_AH_L;                            /**< 累计放电容量低16 0.1AH */
	uint32_t	MODBUS_ALL_CHG_KW_L;                            /**< 累计充电功率低16 0.1kw */
	uint32_t	MODBUS_ALL_DHG_KW_L;                            /**< 累计放电功率低16 0.1kw */
} MOBUS_RUN_STATE_BASE_s;

#define MODBUS_RUN_STATE_BASE_2               (MODBUS_RUN_STATE_BASE + sizeof(MOBUS_RUN_STATE_BASE_s)/2)
typedef struct {
	uint32_t	MODBUS_ALARM_I_L;                              /**< 一级报警低16 */
	uint32_t	MODBUS_ALARM_II_L;                              /**< 二级报警低16 */
	uint32_t	MODBUS_ALARM_III_L;                             /**< 三级报警低16 */
	uint16_t	MODBUS_CURRENT_TEMP;                         /**< 电流温度 */
	uint16_t    MODBUS_PCB_TEMP;                             /**< PCB温度 */
	uint16_t	MODBUS_PACK_PLUS_TEMP;                       /**< PACK正温度 */
	uint16_t	MODBUS_PACK_MINUS_TEMP;                      /**< PACK负温度 */
	uint16_t	MODBUS_BATTERY_PLUS_TEMP;                    /**< 电池正温度 */
	uint16_t	MODBUS_BATTERY_MINUS_TEMP;                   /**< 电池负温度 */
	uint16_t	MODBUS_OUTPUT_STATE;                          /**< 輸出信號状态"：0-闭合，1-断开"*/
#if 1
	   //1.4 电池充电功率、放电功率限制为当前电芯能力的0%、断开接触器、切断直流断路器，切断交流断路器，且不可自恢复（系统锁死，需人工解锁）
	uint16_t MODBUS_ALARM_ERROR_I_I;
	uint16_t MODBUS_ALARM_ERROR_I_II;
	uint16_t	MODBUS_ALARM_ERROR_I_III;
	uint16_t	MODBUS_ALARM_ERROR_I_IV;
		//1.3 电池充电功率、放电功率限制为当前电芯能力的0%、断开接触器、切断直流断路器，切断交流断路器
		uint16_t	MODBUS_ALARM_ERROR_II_I;
		uint16_t	MODBUS_ALARM_ERROR_II_II;
		uint16_t	MODBUS_ALARM_ERROR_II_III;
		uint16_t	MODBUS_ALARM_ERROR_II_IV;
		//1.2 电池充电功率、放电功率限制为当前电芯能力的0%、断开接触器、切断直流断路器
		uint16_t		MODBUS_ALARM_ERROR_III_I;
		uint16_t	MODBUS_ALARM_ERROR_III_II;
		uint16_t	MODBUS_ALARM_ERROR_III_III;
		uint16_t	MODBUS_ALARM_ERROR_III_IV;
		//1.1 电池充电功率、放电功率限制为当前电芯能力的0%、断开接触器
		uint16_t	MODBUS_ALARM_ERROR_IV_I;
		uint16_t MODBUS_ALARM_ERROR_IV_II;
		uint16_t MODBUS_ALARM_ERROR_IV_III;
		uint16_t	MODBUS_ALARM_ERROR_IV_IV;
		/*
		2.1 电池充电功率限制为当前电芯能力的0%
		2.2 电池放电功率限制为当前电芯能力的0%
		2.3 电池充电功率、放电功率限制为当前电芯能力的0%
		*/
		uint16_t	MODBUS_ALARM_ERROR_V_I;
		uint16_t	MODBUS_ALARM_ERROR_V_II;
		uint16_t	MODBUS_ALARM_ERROR_V_III;
		uint16_t MODBUS_ALARM_ERROR_V_IV;
		/*
		3.2 电池充电功率限制为当前电芯能力的50%
		3.3 电池放电功率限制为当前电芯能力的50%
		3.4 电池充电功率限制、放电功率为当前电芯能力的50%
		*/
		uint16_t	MODBUS_ALARM_ERROR_VI_I;
		uint16_t	MODBUS_ALARM_ERROR_VI_II;
		uint16_t MODBUS_ALARM_ERROR_VI_III;
		uint16_t	MODBUS_ALARM_ERROR_VI_IV;
		//3.1 不处理
		uint16_t MODBUS_ALARM_ERROR_VII_I;
		uint16_t MODBUS_ALARM_ERROR_VII_II;
		uint16_t MODBUS_ALARM_ERROR_VII_III;
		uint16_t MODBUS_ALARM_ERROR_VII_IV;
#endif
	uint16_t	MODBUS_ALARM_ERROR_I;
	uint16_t	MODBUS_ALARM_ERROR_II;
	uint16_t	MODBUS_ALARM_ERROR_III;
	uint16_t	MODBUS_ALARM_ERROR_IV;
	uint16_t	MODBUS_ALARM_ERROR_V;
	uint16_t    MODBUS_ALARM_ERROR_VI;
	uint16_t    MODBUS_BMS_STATE;                              /**< BMS状态 首字节是主状态 BMS_STATEMACH_e，第二个字节是子状态 BMS_STATEMACH_SUB_e */
	uint16_t	MODBUS_SYS_STATE;                              /**< SYS状态 首字节是主状态 SYS_STATEMACH_e，第二个字节是子状态 SYS_STATEMACH_SUB_e*/
	uint16_t	MODBUS_CHG_DHG_POWER;                          /**< 充放电 状态 首字节是充电，第二个字节是放电 bit3:降功率；bit2:充放电禁止；bit1：接触器开路*/
	uint16_t   MODUBS_ERROR_REASON;                           /**< 错误原因  DIAG_ERROR_REASON_e*/
	uint16_t  MODBUS_AC_STATUS;
	uint16_t MODBUS_AC_WARNING_STATE;
	uint16_t MODBUS_AC_NEED_STATE;
	uint16_t MODBUS_RUN_STATE_MAX;
} MOBUS_RUN_STATE_BASE_s_2;


/** States of the SYS state machine */
typedef enum {
	/* Init-Sequence */
	BMS_STATEMACH_UNINITIALIZED,
	BMS_STATEMACH_INITIALIZATION,
	BMS_STATEMACH_INITIALIZED,
	BMS_STATEMACH_IDLE,
	BMS_STATEMACH_OPEN_CONTACTORS,
	BMS_STATEMACH_STANDBY,
	BMS_STATEMACH_PRECHARGE,
	BMS_STATEMACH_NORMAL,
	BMS_STATEMACH_DISCHARGE,
	BMS_STATEMACH_CHARGE,
	BMS_STATEMACH_ERROR,
	BMS_STATEMACH_POWEROFF,
	BMS_STATEMACH_OPEN_CONTACTORS_WITH_ERROR,
	BMS_STATEMACH_TEST,
	BMS_STATEMACH_RESERVED1,
}BMS_STATEMACH_e;

typedef enum {
	BMS_ENTRY,                        /*!< Substate entry state */
	BMS_CHECK_ERROR_FLAGS_INTERLOCK,  /*!< Substate check measurements after interlock closed */
	BMS_INTERLOCK_CHECKED,            /*!< Substate interlocked checked */
	BMS_CHECK_STATE_REQUESTS,         /*!< Substate check if there is a state request */
	BMS_CHECK_BALANCING_REQUESTS,     /*!< Substate check if there is a balancing request */
	BMS_CHECK_ERROR_FLAGS,            /*!< Substate check if any error flag set */
	BMS_CHECK_CONTACTOR_NORMAL_STATE, /*!< Substate in precharge, check if there contactors reached normal */
	BMS_CHECK_CONTACTOR_CHARGE_STATE, /*!< Substate in precharge, check if there contactors reached normal */
	BMS_PRECHARGE_CLOSE_MINUS,
	BMS_PRECHARGE_CHECK_MINUS_CLOSE,
	BMS_PRECHARGE_CLOSE_PRECHARGE,
	BMS_PRECHARGE_CHECK_PRECHARGE_CLOSE,
	BMS_PRECHARGE_CHECK_VOLTAGES,
	BMS_PRECHARGE_CHECK_PLUS_CLOSE,
	BMS_PRECHARGE_OPEN_PRECHARGE,
	BMS_PRECHARGE_CHECK_OPEN_PRECHARGE,
	BMS_OPEN_FIRST_CONTACTOR,
	BMS_OPEN_SECOND_CONTACTOR_MINUS,
	BMS_OPEN_SECOND_CONTACTOR_PLUS,
	BMS_CHECK_CLOSE_SECOND_STRING_CONTACTOR_PRECHARGE_STATE,
	BMS_CHECK_ERROR_FLAGS_PRECHARGE,
	BMS_CHECK_ERROR_FLAGS_PRECHARGE_FIRST_STRING,
	BMS_PRECHARGE_CLOSE_NEXT_STRING,
	BMS_CLOSE_SECOND_CONTACTOR_PLUS,
	BMS_CHECK_STRING_CLOSED,
	BMS_CHECK_ERROR_FLAGS_PRECHARGE_CLOSINGSTRINGS,
	BMS_CHECK_ERROR_FLAGS_CLOSINGPRECHARGE,
	BMS_NORMAL_CLOSE_NEXT_STRING,
	BMS_NORMAL_CLOSE_SECOND_STRING_CONTACTOR,
	BMS_NORMAL_CHECK_CONTACTOR_PLUS_OPEN,
	BMS_NORMAL_CHECK_CONTACTOR_PLUS_CLOSE,
	BMS_NORMAL_CHECK_CONTACTOR_CHARGE_OPEN,
	BMS_NORMAL_CHECK_CONTACTOR_CHARGE_CLOSE,
	BMS_OPEN_PRECHARGE,
	BMS_OPEN_PLUS_CONTACTOR,
	BMS_OPEN_MINUS_CONTACTOR,
	BMS_CHECK_MINUS_CONTACTOR,
	BMS_OPEN_EXIT
} BMS_STATEMACH_SUB_e;

typedef enum {
	/* Init-Sequence */
	SYS_STATEMACH_UNINITIALIZED,                 /*!<    */
	SYS_STATEMACH_INITIALIZATION,                /*!<    */
	SYS_STATEMACH_SYSTEM_BIST,                   /*!< run a built-in self-test */
	SYS_STATEMACH_INITIALIZED,                   /*!<    */
	SYS_STATEMACH_INITIALIZE_CAN,                /*!< initialize CAN module */
	SYS_STATEMACH_INITIALIZE_SELFCHECK,          /*!<    */
	SYS_STATEMACH_NODE_ID_ALLOC,                /*!<    */
	SYS_STATEMACH_INITIALIZE_CONTACTORS,         /*!<    */
	SYS_STATEMACH_INITIALIZE_BALANCING,          /*!<    */
	SYS_STATEMACH_INITIALIZE_BMS,                /*!<    */
	SYS_STATEMACH_RUNNING,                       /*!<    */
	SYS_STATEMACH_FIRST_MEASUREMENT_CYCLE,       /*!<    */
	SYS_STATEMACH_INITIALIZE_MISC,               /*!<    */
	SYS_STATEMACH_INITIALIZE_SE, /*!<    */
	SYS_STATEMACH_INITIALIZE_IMD,                /*!< initialize IMD module */
	SYS_STATEMACH_ERROR,                         /*!< Error-State */
}SYS_STATEMACH_e;

/** Substates of the SYS state machine */
typedef enum {
	SYS_ENTRY,                                  /*!< Substate entry state */
	SYS_CHECK_ERROR_FLAGS,                      /*!< Substate check if any error flag set */
	SYS_CHECK_STATE_REQUESTS,                   /*!< Substate check if there is a state request */
	SYS_WAIT_INITIALIZATION_SBC,                /*!< Substate to wait for initialization of the sbc state machine */
	SYS_WAIT_INITIALIZATION_INTERLOCK,          /*!< Substate to wait for initialization of the interlock state machine */
	SYS_WAIT_INITIALIZATION_CONT,               /*!< Substate to wait for initialization of the contactor state machine */
	SYS_WAIT_INITIALIZATION_BAL,                /*!< Substate to wait for initialization of the balancing state machine */
	SYS_WAIT_INITIALIZATION_BAL_GLOBAL_ENABLE, /*!< Substate to enable/disable balancing globally */
	SYS_WAIT_INITIALIZATION_IMD,               /*!< Substate to wait for initialization of the imd state machine */
	SYS_WAIT_INITIALIZATION_BMS,               /*!< Substate to wait for initialization of the bms state machine */
	SYS_WAIT_NODE_ADDR_OK,                          /*!< Substate to wait for first measurement cycle to complete */
	SYS_WAIT_DEV_INFO_RESP,                          /*!< Substate to wait for first measurement cycle to complete */
	SYS_WAIT_FIRST_MEASUREMENT_CYCLE,          /*!< Substate to wait for first measurement cycle to complete */
	SYS_WAIT_CURRENT_SENSOR_PRESENCE,          /*!< Substate to wait for first measurement cycle to complete */
	SYS_SBC_INITIALIZATION_ERROR,              /*!< Substate error of SBC initialization */
	SYS_CONT_INITIALIZATION_ERROR,             /*!< Substate error of contactor state machine initialization */
	SYS_BAL_INITIALIZATION_ERROR,              /*!< Substate error of balancing state machine initialization */
	SYS_ILCK_INITIALIZATION_ERROR,             /*!< Substate error of contactor state machine initialization */
	SYS_IMD_INITIALIZATION_ERROR,              /*!< Substate error of bms state machine initialization */
	SYS_BMS_INITIALIZATION_ERROR,              /*!< Substate error of bms state machine initialization */
	SYS_MEAS_INITIALIZATION_ERROR,             /*!< Substate error if first measurement cycle does not complete */
	SYS_CURRENT_SENSOR_PRESENCE_ERROR,         /*!< Substate error if first measurement cycle does not complete */
}SYS_STATEMACH_SUB_e;

typedef enum {					                 
	DIAG_ERR_REASON_NONE                                  = 0x0000,
	DIAG_ERR_REASON_FAULT_LOCK                            = 0x0065,
	DIAG_ERR_REASON_MACRO_TEST                            = 0x1010,
	DIAG_ERR_REASON_DB_TEST                               = 0x1011,
	DIAG_ERR_REASON_OS_TEST                               = 0x1012,
	DIAG_ERR_REASON_SAFTY_TEST                            = 0x1013,
	DIAG_ERR_REASON_HVADC_TEST                            = 0x1014,
	DIAG_ERR_REASON_MCUADC_TEST                           = 0x1015,
	DIAG_ERR_REASON_CONT_TEST                             = 0x1016,
	DIAG_ERR_REASON_ADDR_ALLOC                            = 0x1017,
	DIAG_ERR_REASON_STING_NO_MACTH                        = 0x1018,
	DIAG_ERR_REASON_CURRENT_SENSOR_NO_RESPOND             = 0x1019,
	DIAG_ERR_REASON_INSULATION_TEST                       = 0x101A,
	DIAG_ERR_REASON_BMS_INIT                              = 0x101B,
	DIAG_ERR_REASON_BMS_IDLE_ERROR                        = 0x101C,
	DIAG_ERR_REASON_BMS_STANDBY_ERROR                     = 0x101D,
	DIAG_ERR_REASON_BMS_PRECHARGE_ERROR                   = 0x101E,
	DIAG_ERR_REASON_BMS_PRECHARGE_MINUS_CLOSE_ERROR       = 0x101F,
	DIAG_ERR_REASON_BMS_PRECHARGE_PRECHARGE_CLOSE_ERROR   = 0x1020,
	DIAG_ERR_REASON_BMS_PRECHARGE_PRECHARGE_ERROR1        = 0x1021,
	DIAG_ERR_REASON_BMS_PRECHARGE_FAIL_ERROR              = 0x1022,
	DIAG_ERR_REASON_BMS_PRECHARGE_PLUS_CLOSE_ERROR        = 0x1023,
	DIAG_ERR_REASON_BMS_PRECHARGE_PRECHARGE_OPEN_ERROR    = 0x1024,
	DIAG_ERR_REASON_BMS_NORMAL_ERROR                      = 0x1025,
}DIAG_ERROR_REASON_e;


//#define MODBUS_FAULT_WITHOUT_RECOVERY_BASE  0x1800
#define MODBUS_S_VOLT_BASE                  0x4000
#define MODBUS_S_TEMP_BASE                  0x5000
#define MODBUS_S_BMU_STATUS                  0x6000
#define MODBUS_DEBUG_BASE                   0x8000

/**
 * @brief DEBUG cmd
 */
typedef enum
{
#define MODBUS_DEBUG_CMD                   0x7000
	MODBUS_RESET_CMD , /*reset*/
	MODBUS_RESTORE_PARAM_CMD, /*reset parameter*/
	MODBUS_SOC_CMD, /*set soc*/
	MODBUS_PRECHG_CONTACTOR_CMD, /*0 close;1 open */
	MODBUS_PLUS_CONTACTOR_CMD, /*0 close;1 open */
	MODBUS_MINUS_CONTACTOR_CMD, /*0 close;1 open */
	MODBUS_FORCE_FAN_CMD, /*风扇强制开关，0：关闭；1： 打开*/
} MODBUS_DEBUG_CMD_e;

typedef struct {
	int16_t  pcbTemperature_ddegC;                       /*!< unit: deci &deg;C */
	int16_t  balanceTemperature_ddegC;                   /*!< unit: deci &deg;C */                                           /*!< for future use */
	uint16_t errStatus;
	uint16_t doStatus;
	uint16_t diStatus;
	uint16_t balanceState4;                                        /*!< bitx 1 -> on, 0 -> off */
	uint16_t balanceState3;                                        /*!< bitx 1 -> on, 0 -> off */
	uint16_t balanceState2;                                        /*!< bitx 1 -> on, 0 -> off */
	uint16_t balanceState[4];                                        /*!< bitx 1 -> on, 0 -> off */
	uint16_t cellOpenWire[4]; /*!< bitx 1 -> open wire, 0 -> everything ok */
} MODBUS_BMU_STATUS_s;

typedef struct {
	uint8_t modbusNodeAddr;
} MODBUS_NODE_s;
typedef struct {
	MSL_CFG_s msl;
	RSL_CFG_s rsl;
	MOL_CFG_s mol;
}SAFETY_THRESHOLD_s;

typedef enum {
	SIM_CUR_DISABLE,
	SIM_CUR_ENABLE,
} MODBUS_DATA_SIM_Cur_e;

typedef enum {
	SIM_INSULATION_DISABLE = 0,
	SIM_INSULATION_N,
	SIM_INSULATION_P,
	SIM_INSULATION_ALL = 0xFF,
} MODBUS_DATA_SIM_Insulation_e;

typedef enum {
	SIM_CELL_VOLTAGE_DISABLE = 0,
	SIM_CELL_VOLTAGE_SINGLE,
	SIM_CELL_VOLTAGE_ALL = 0xFF,
} MODBUS_DATA_SIM_Cell_Voltage_e;


typedef enum {
	SIM_STRING_VOLTAGE_DISABLE = 0,
	SIM_STRING_VOLTAGE_BATTERY,
	SIM_STRING_VOLTAGE_STRING,
	SIM_STRING_VOLTAGE_ALL = 0xFF,
} MODBUS_DATA_SIM_String_Voltage_e;

typedef enum {
	SIM_BCU_TEMP_DISABLE = 0,
	SIM_BCU_TEMP_CURRENT,
	SIM_BCU_TEMP_PCB,
	SIM_BCU_TEMP_PACK_N,
	SIM_BCU_TEMP_PACK_P,
	SIM_BCU_TEMP_BATTERY_N,
	SIM_BCU_TEMP_BATTERY_P,
	SIM_BCU_TEMP_ALL = 0xFF,
} MODBUS_DATA_SIM_Temp_e;
typedef enum {
	MODBUS_DI_POWER_5V_GOOD,
	MODBUS_DI_POWER_24V_GOOD,
	MODBUS_DI_MCU_FTL1,
	MODBUS_DI_MCU_FTL2,
	MODBUS_DI_MCU_FTL3,
	MODBUS_DI_MCU_FTL4,
	MODBUS_DI_TEMP_SENSOR,
	MODBUS_DI_STOP_SENSOR,
	MODBUS_DI_WATER_SENSOR,
	MODBUS_DI_FIRE_SENSOR,
	MODBUS_DI_ENTRANCE_SENSOR,
	MODBUS_DI_SMOKE_SENSOR,
	MODBUS_DI_ADDR_ALLOC,
	MODBUS_DI_ALL = 0xFF,
} MODBUS_DATA_SIM_Di_e;
typedef enum {
 cellOverVoltageLimitError=0,
 cellUnderVoltageLimitError,
 prechargeFail,
 cellTemperatureSensorOpenError,
 cellTemperatureSensorShortError,
 openWireDetectedError,                        /*!< false -> no error, true -> error */
 stringSmoke,
 stringWarm,
 stringFire,
 moduleFire,
 faultLockError,

/*1.4 end*/
/*1.3 begin*/
 contactorTripSwitchOpenError,                 /* 脱扣器粘连*/
/*1.3 end*/
/*1.2 begin*/
 contactorMinusOpenError,                      /*!< false -> no error, true -> error */
 contactorPlusOpenError,                       /*!< false -> no error, true -> error */
 contactorMinusCloseError,                    /*!< false -> no error, true -> error */
 contactorPlusCloseError,                      /*!< false -> no error, true -> error */
 contactorPrechargeOpenError,                  /*!< false -> no error, true -> error */
 contactorChargeOpenError,                     /*!< false -> no error, true -> error */
 contactorPrechargeCloseError,                 /*!< false -> no error, true -> error */
 contactorChargeCloseError,                    /*!< false -> no error, true -> error */
 contactorTripOpenError,                                /* 脱扣器脱扣*/
/*1.2 end*/
/*1.1 begin*/
 bcuPcbTemperatureError,
 contactorOverLoad,
 bmuPcbTemperatureError,
 balanceOverTemperatureError,
 redundancyCellVoltageMeasurementTimeoutError,                  /*!< false -> no error, true -> error */
 currentMeasurementTimeoutError,               /*!< false -> no error, true -> error */
 afeCommunicationError,                     /*!< false -> no error, true -> error */
 i2cAdcError,
 i2cFramError,                  /*!< false if read CRC matches with CRC of read data, true otherwise */
 bmuComError,
 bmuOffline,
 spiCanError,
 phyInitError,
 bmuAddrAllocError,                /*!< BMU address allocation error */
 fuseError,                              /*!< false -> fuse ok,  true -> fuse tripped */
 bcuPower24VUnderVoltageError,
 exAdcRefError,
 adcRefError,
 cellCountDismatched,
 stopSwitch,
 waterIn,
 acCommunicationError,
 pcsCommunicationError,
 pcsStatusError,
/*1.1 end*/

/*2.3 begin*/

/*2.3 end*/

/*2.2 begin*/

/*2.2 end*/

/*2.1 begin*/

/*2.1 end*/
/*3.4 begin*/
 connectorBatteryMinusTemperatureError,
 connectorBatteryPlusTemperatureError,
 connectorPackMinusTemperatureError,
 connectorPackPlusTemperatureError,
 bmuBatPlusTemperatureError,
 bmuBatMinusTemperatureError,


/*3.1 begin*/
 envUnderTemperatureError,
 envOverTemperatureError,
 currentSensorTemperatureError,
 framCrcError,                  /*!< false if read CRC matches with CRC of read data, true otherwise */
 pcbTemperatureSensorOpenError,
 pcbTemperatureSensorShortError,
 balanceTemperatureSensorOpenError,
 balanceTemperatureSensorShortError,
 bcuPower24VOverVoltageError,
 bcuPower5VOverVoltageError,
 bcuPower5VUnderVoltageError,
 balanceOpenError,
 balanceShortError,
 redundancyCellTemperatureMeasurementTimeoutError,             /*!< false -> no error, true -> error */
 currentMeasurementInvalidError,               /*!< false -> no error, true -> error */
 canRxQueueFullError,                                            /*!< false -> no error, true -> error */
 canTxQueueFullError,                                            /*!< false -> no error, true -> error */
 flashChecksumError,
 plausibilityCheckstringVoltageError,            /*!< false -> no error, true -> error */
 plausibilityCheckCellVoltageError,            /*!< false -> no error, true -> error */
 plausibilityCheckCellTemperatureError,        /*!< false -> no error, true -> error */
 currentSensorNotRespondingError,             /*!< false -> no error, true -> error */
 insulationMeasurementInvalidError,                              /*!< false -> no error, true -> error */
 interlockOpenedError,
 lowSoh,
 i2cRtcError,                       /*!< problem in I2C communication with RTC */
 rtcBatteryLowError,                /*!< RTC battery voltage is low */
 spiFlashError,
 bmuAddrError,
 bmuModuleFanError,
 canBus,
 acStatusError,
 limitSwitch,
 taskEngineTimingViolationError,    /*!< timing violation in engine task */
 task1msTimingViolationError,       /*!< timing violation in 1ms task */
 task10msTimingViolationError,     /*!< timing violation in 10ms task */
 task100msTimingViolationError,    /*!< timing violation in 100ms task */
 task100msAlgoTimingViolationError, /*!< timing violation in 100ms algorithm task */
 redundancyHvMeasurementTimeoutError,
 bmuBatPlusTemperatureOpenError,
 bmuBatPlusTemperatureShortError,
 bmuBatMinusTemperatureOpenError,
 bmuBatMinusTemperatureShortError,
/*3.1 end*/
}DATA_BLOCK_ERROR_STATE_BitMap_E;//BALANCE_CFG_s* pBalanceConfigParam;















#pragma pack(pop)
#endif // !defined(_DEVICE_PARAMS)