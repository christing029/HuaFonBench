#include "ShowBCU.h"
#include <src/drvmng/can.h>
#include <src/drvmng/modbus_params.h>
#include <src/drvmng/drvmng.h>
#define       V_Uint    " V"
#define       T_Uint    " °"
ShowBCU::ShowBCU(QWidget* parent)
	: QMainWindow(parent)
{
	QFile file(":/qss/HF.qss");
	if (!file.open(QIODevice::ReadOnly))
	{
		qWarning("Can't open the style sheet file.");
		//   return;
	}
	QString qss = QLatin1String(file.readAll());
	this->setStyleSheet(qss);
	file.close();
	ui.setupUi(this);
	labelStsIP = new QLabel();            // IP信息
	QFont font("Microsoft YaHei", 8);
	labelStsIP->setMinimumWidth(120);
	labelStsIP->setText("软件版本 V 1.0.0 硬件版本  V1.10  SN:01345678901112  UUID : 01345678901112");
	labelStsIP->setFont(font);
	labelStsIP->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	ui.statusBar->addPermanentWidget(labelStsIP);

	ui.lbMOL_P->setMaximumSize(32, 32);
	ui.lbMOL_P->setScaledContents(true);
	ui.lbMSL_P->setMaximumSize(32, 32);
	ui.lbMSL_P->setScaledContents(true);
	ui.lbRSL_P->setMaximumSize(32, 32);
	ui.lbRSL_P->setScaledContents(true);

	ui.lbDO_Status->setMaximumSize(32, 32);
	ui.lbDO_Status->setScaledContents(true);

	ui.lbDI_Status->setMaximumSize(32, 32);
	ui.lbDI_Status->setScaledContents(true);


	ui.lbMOL_P->setPixmap(QPixmap(":/icon/globes_grey.png"));
	ui.lbMSL_P->setPixmap(QPixmap(":/icon/globes_grey.png"));
	ui.lbRSL_P->setPixmap(QPixmap(":/icon/globes_grey.png"));
	ui.lbERROR_P->setMaximumSize(32, 32);
	ui.lbERROR_P->setScaledContents(true);
	ui.lbERROR_P->setPixmap(QPixmap(":/icon/globes_grey.png"));

	ui.lbDO_Status->setPixmap(QPixmap(":/icon/globes_grey.png"));
	ui.lbDI_Status->setPixmap(QPixmap(":/icon/globes_grey.png"));

	ui.lb_5V->setPixmap(QPixmap(":/icon/globes_grey.png"));
	ui.lb_5V->setMaximumSize(32, 32);
	ui.lb_5V->setScaledContents(true);

	ui.lb_24V->setPixmap(QPixmap(":/icon/globes_grey.png"));
	ui.lb_24V->setMaximumSize(32, 32);
	ui.lb_24V->setScaledContents(true);

	ui.lb_BUTTON->setPixmap(QPixmap(":/icon/globes_grey.png"));
	ui.lb_BUTTON->setMaximumSize(32, 32);
	ui.lb_BUTTON->setScaledContents(true);

	ui.lb_FTL1->setPixmap(QPixmap(":/icon/globes_grey.png"));
	ui.lb_FTL1->setMaximumSize(32, 32);
	ui.lb_FTL1->setScaledContents(true);

	ui.lb_FTL2->setPixmap(QPixmap(":/icon/globes_grey.png"));
	ui.lb_FTL2->setMaximumSize(32, 32);
	ui.lb_FTL2->setScaledContents(true);

	ui.lb_FTL3->setPixmap(QPixmap(":/icon/globes_grey.png"));
	ui.lb_FTL3->setMaximumSize(32, 32);
	ui.lb_FTL3->setScaledContents(true);

	ui.lb_FTL4->setPixmap(QPixmap(":/icon/globes_grey.png"));
	ui.lb_FTL4->setMaximumSize(32, 32);
	ui.lb_FTL4->setScaledContents(true);

	ui.lb_Stop->setPixmap(QPixmap(":/icon/globes_grey.png"));
	ui.lb_Stop->setMaximumSize(32, 32);
	ui.lb_Stop->setScaledContents(true);


	ui.lb_Water->setPixmap(QPixmap(":/icon/globes_grey.png"));
	ui.lb_Water->setMaximumSize(32, 32);
	ui.lb_Water->setScaledContents(true);


	ui.lb_HuSuo->setPixmap(QPixmap(":/icon/globes_grey.png"));
	ui.lb_HuSuo->setMaximumSize(32, 32);
	ui.lb_HuSuo->setScaledContents(true);


	ui.lb_Smoke->setPixmap(QPixmap(":/icon/globes_grey.png"));
	ui.lb_Smoke->setMaximumSize(32, 32);
	ui.lb_Smoke->setScaledContents(true);



	QStringList headlist;
	ui.tableWidget_MSL->insertRow(0);
	ui.tableWidget_MSL->setColumnCount(16);
	for (int k = 0; k < 16; k++)
	{
		headlist << "";
	}
	ui.tableWidget_MSL->setHorizontalHeaderLabels(headlist);

	QStringList headlist_DO;
	QStringList headlist_DI;
	headlist_DO << "负极接触器" << "预充接触器" << "正极接触器" << "断路器" << "消防使能" << "运行指示灯" <<
		"故障指示灯" << "LS8" <<"LS5" << "LS2" << "LS1" << "LE 锁存使能" << "风扇电源" << "24V" << "拨码输出";

	headlist_DI << "ADDR_IN" << "烟感" << "行程开关检测" << "消防" << "水侵" << "急停" <<
		"温感" << "FTL4" << "FTL3" << "FTL2" << "FTL1" << "从机24V" << "5V电状态";
	ui.tableWidget_DI->setColumnCount(headlist_DI.count());
	ui.tableWidget_DI->setHorizontalHeaderLabels(headlist_DI);
	ui.tableWidget_DI->setRowCount(1);
	for (int j = 0; j < headlist_DI.count(); j++)
	{
		ui.tableWidget_DI->setItem(0, j, new QTableWidgetItem("-"));
	}
	ui.tableWidget_DO->setColumnCount(headlist_DO.count());
	ui.tableWidget_DO->setHorizontalHeaderLabels(headlist_DO);
	ui.tableWidget_DO->setRowCount(1);
	for (int j = 0; j < headlist_DO.count(); j++)
	{
		ui.tableWidget_DO->setItem(0, j, new QTableWidgetItem("-"));
	}

	//ui.tableWidget_DO->setObjectName("table_header");
	//ui.tableWidget_DO->horizontalHeader()->setVisible(false);
	//ui.tableWidget_DO->verticalHeader()->setVisible(false);
	//ui.tableWidget_DO->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	//ui.tableWidget_DO->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	//ui.tableWidget_DO->setFrameShape(QFrame::NoFrame);
	//ui.tableWidget_DO->setFocusPolicy(Qt::NoFocus);
	//ui.tableWidget_DO->setEditTriggers(QAbstractItemView::NoEditTriggers);
	//ui.tableWidget_DO->setSelectionMode(QAbstractItemView::NoSelection);

	//ui.tableWidget_DO->setRowCount(3);

	//ui.tableWidget_DO->setColumnCount(headlist_DO.count() * 2);
	//for (int i = 0; i < headlist_DO.count(); i++)
	//{
	//	ui.tableWidget_DO->setSpan(0, i * 2, 1, 2);
	//	ui.tableWidget_DO->setItem(0, i * 2, new QTableWidgetItem(headlist_DO[i]));
	//	ui.tableWidget_DO->item(0, i * 2)->setTextAlignment(Qt::AlignCenter);
	//}
	//for (int i = 0; i < headlist_DO.count() * 2;)
	//{
	//	ui.tableWidget_DO->setItem(1, i, new QTableWidgetItem("状态"));
	//	ui.tableWidget_DO->setItem(2, i, new QTableWidgetItem("-"));
	//	ui.tableWidget_DO->item(1, i)->setTextAlignment(Qt::AlignCenter);
	//	ui.tableWidget_DO->item(2, i)->setTextAlignment(Qt::AlignCenter);
	//	i++;
	//	ui.tableWidget_DO->setItem(1, i, new QTableWidgetItem("反馈"));
	//	ui.tableWidget_DO->setItem(2, i, new QTableWidgetItem("-"));
	//	ui.tableWidget_DO->item(1, i)->setTextAlignment(Qt::AlignCenter);
	//	ui.tableWidget_DO->item(2, i)->setTextAlignment(Qt::AlignCenter);
	//	i++;
	//}
	ui.wd_Current->setMinValue(0);
	ui.wd_Current->setMaxValue(180);
	ui.wd_Current->setValuesUnit("%1A");
	ui.wd_Voltage->setCurrentValue(0);
	ui.wd_Voltage->setMinValue(0);
	ui.wd_Voltage->setMaxValue(1000);
	ui.wd_Voltage->label = "电压表";
	ui.wd_Current->label = "电流表/静置";


	QMenu* menu = new QMenu(this);
	menu->addAction(tr("测试模式"), this, &ShowBCU::SlotsAlarmSetMenu, 1);
	menu->addAction(tr("复位指令"), this, &ShowBCU::SlotsResetMenu, 1);
	menu->addAction(tr("风扇强制开启"), this, &ShowBCU::SlotsOpenFANMenu, 1);
	//menu->addAction(tr("测试模式"));
	//menu->addAction(tr("DB_TEST"));
	//menu->addAction(tr("OS_TEST"));
	menu->setStyleSheet("QMenu {background-color: #435; border: 1px solid #ccc;}");
	ui.wd_SOC->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(ui.wd_SOC, &QWidget::customContextMenuRequested, [this, menu](const QPoint& pos) {

		menu->exec(ui.wd_SOC->mapToGlobal(pos));
		}
	);
	InitMap();
	LoadBCUDB();
	
}

ShowBCU::~ShowBCU()
{
}

void ShowBCU::UpdataAlarmMSLTable(uint32_t FaultData, uint32_t alarmLevel_H, uint32_t alarmLevel_M)
{
	QStringList headlist;
	uint32_t bits;
	uint32_t bits1;
	uint32_t i;
	uint32_t lev_h;
	uint32_t lev_m;


	ui.tableWidget_MSL->clearContents();
	ui.tableWidget_MSL->clear();
	for (i = 0; i < 32; i++)
	{
		bits = (uint32_t)1 << i;
		bits1 = FaultData & bits;
		lev_h = alarmLevel_H & bits;
		lev_m = alarmLevel_M & bits;

		if (bits1 != 0)
		{
			headlist << alarmBitsList[i];
			ui.tableWidget_MSL->setHorizontalHeaderLabels(headlist);
			ui.tableWidget_MSL->setItem(0, headlist.count() - 1, new QTableWidgetItem(tr("%1").arg("*")));
			if (lev_h != 0)
			{
				ui.tableWidget_MSL->item(0, headlist.count() - 1)->setBackgroundColor(QColor(255, 0, 0));//设置整行的颜色为灰色
			}
			else if (lev_m != 0)
			{
				ui.tableWidget_MSL->item(0, headlist.count() - 1)->setBackgroundColor(QColor(255, 128, 128));//设置整行的颜色为灰色
			}
			else
			{
				ui.tableWidget_MSL->item(0, headlist.count() - 1)->setBackgroundColor(QColor(255, 255, 0));//设置整行的颜色为灰色
			}

		}
		else
		{
			//ui.tableWidget_MSL->insertColumn(1);
			//ui.tableWidget_MSL->setItem(0, i, new QTableWidgetItem(tr("%1").arg("*")));
			//ui.tableWidget_MSL->insertColumn(1);
			//ui.tableWidget_MSL->item(0, i)->setBackgroundColor(QColor(0, 255, 0));//设置整行的颜色为灰色
		}
	}
	for (int j = 0; j < 6; j++)
	{
		for (i = 0; i < 16; i++)
		{
			bits = (uint32_t)1 << i;
			bits1 = ErrorBit[j] & bits;
			if (bits1 != 0)
			{
				headlist << ErrorBitsList[j * 16 + i];
				ui.tableWidget_MSL->setHorizontalHeaderLabels(headlist);
				ui.tableWidget_MSL->setItem(0, headlist.count() - 1, new QTableWidgetItem(tr("%1").arg("*")));
				ui.tableWidget_MSL->item(0, headlist.count() - 1)->setBackgroundColor(QColor(255, 0, 0));//设置整行的颜色为灰色
			}
		}
	}
	// ui.tableWidget_MSL->insertColumn(1);
}


void ShowBCU::UpdataDODIStatusTable(_BCUCAN_SysInfo_Module_DoDiStatus* Data)
{

	ui.tableWidget_DO->item(0, 0)->setText(QString::number(Data->DOFbStatus.Bits.NegativeContactor));
	//ui.tableWidget_DO->item(0, 1)->setText(QString::number(Data->DOFbStatus.Bits.NegativeContactor));

	ui.tableWidget_DO->item(0, 1)->setText(QString::number(Data->DOFbStatus.Bits.PreChargeContactor));
	//ui.tableWidget_DO->item(0, 3)->setText(QString::number(Data->DOFbStatus.Bits.PreChargeContactor));

	ui.tableWidget_DO->item(0, 2)->setText(QString::number(Data->DOFbStatus.Bits.PosContactor));
	//ui.tableWidget_DO->item(0, 5)->setText(QString::number(Data->DOFbStatus.Bits.PosContactor));

	ui.tableWidget_DO->item(0, 3)->setText(QString::number(Data->DOFbStatus.Bits.DiscnnContactor));
	//ui.tableWidget_DO->item(0, 7)->setText(QString::number(Data->DOFbStatus.Bits.DiscnnContactor));


	ui.tableWidget_DO->item(0, 4)->setText(QString::number(Data->DOFbStatus.Bits.FireSensor));
	//ui.tableWidget_DO->item(0, 9)->setText(QString::number(Data->DOFbStatus.Bits.FireSensor));

	ui.tableWidget_DO->item(0, 5)->setText(QString::number(Data->DOFbStatus.Bits.RunLed));
	//ui.tableWidget_DO->item(0, 11)->setText(QString::number(Data->DOFbStatus.Bits.RunLed));

	ui.tableWidget_DO->item(0, 6)->setText(QString::number(Data->DOFbStatus.Bits.AlarmLed));
	//ui.tableWidget_DO->item(0, 13)->setText(QString::number(Data->DOFbStatus.Bits.AlarmLed));

	ui.tableWidget_DO->item(0, 7)->setText(QString::number(Data->DOFbStatus.Bits.LS8));
	//ui.tableWidget_DO->item(0, 15)->setText(QString::number(Data->DOFbStatus.Bits.LS8));

	ui.tableWidget_DO->item(0, 8)->setText(QString::number(Data->DOFbStatus.Bits.LS5));
	//ui.tableWidget_DO->item(0, 17)->setText(QString::number(Data->DOFbStatus.Bits.LS5));

	ui.tableWidget_DO->item(0, 9)->setText(QString::number(Data->DOFbStatus.Bits.LS2));
	//ui.tableWidget_DO->item(0, 19)->setText(QString::number(Data->DOFbStatus.Bits.LS2));

	ui.tableWidget_DO->item(0, 10)->setText(QString::number(Data->DOFbStatus.Bits.LS1));
	//ui.tableWidget_DO->item(0, 21)->setText(QString::number(Data->DOFbStatus.Bits.LS1));

	ui.tableWidget_DO->item(0, 11)->setText(QString::number(Data->DOFbStatus.Bits.LELock));
	//ui.tableWidget_DO->item(0, 23)->setText(QString::number(Data->DOFbStatus.Bits.LELock));


	ui.tableWidget_DO->item(0, 12)->setText(QString::number(Data->DOFbStatus.Bits.FanPower));
	//ui.tableWidget_DO->item(0, 25)->setText(QString::number(Data->DOFbStatus.Bits.FanPower));

	ui.tableWidget_DO->item(0, 13)->setText(QString::number(Data->DOFbStatus.Bits.V24));
	//ui.tableWidget_DO->item(0, 27)->setText(QString::number(Data->DOFbStatus.Bits.V24));


	ui.tableWidget_DO->item(0, 14)->setText(QString::number(Data->DOFbStatus.Bits.BmOUT));
	//ui.tableWidget_DO->item(0, 29)->setText(QString::number(Data->DOFbStatus.Bits.BmOUT));
	// DI
	ui.tableWidget_DI->item(0, 0)->setText(QString::number(Data->DIStatus.Bits.ADDR_IN));
	ui.tableWidget_DI->item(0, 1)->setText(QString::number(Data->DIStatus.Bits.SmokeSensor));
	ui.tableWidget_DI->item(0, 2)->setText(QString::number(Data->DIStatus.Bits.DistanceSensor));
	ui.tableWidget_DI->item(0, 3)->setText(QString::number(Data->DIStatus.Bits.FireSensor));
	ui.tableWidget_DI->item(0, 4)->setText(QString::number(Data->DIStatus.Bits.WaterSensor));
	ui.tableWidget_DI->item(0, 5)->setText(QString::number(Data->DIStatus.Bits.StopSensor));
	ui.tableWidget_DI->item(0, 6)->setText(QString::number(Data->DIStatus.Bits.TempSensor));
	ui.tableWidget_DI->item(0, 7)->setText(QString::number(Data->DIStatus.Bits.MCUFTL1));
	ui.tableWidget_DI->item(0, 8)->setText(QString::number(Data->DIStatus.Bits.MCUFTL2));
	ui.tableWidget_DI->item(0, 9)->setText(QString::number(Data->DIStatus.Bits.MCUFTL3));
	ui.tableWidget_DI->item(0, 10)->setText(QString::number(Data->DIStatus.Bits.MCUFTL4));
	ui.tableWidget_DI->item(0, 11)->setText(QString::number(Data->DIStatus.Bits.V_24));
	ui.tableWidget_DI->item(0, 12)->setText(QString::number(Data->DIStatus.Bits.V_5));
}

void ShowBCU::UpdataDIStatusTable(uint32_t Data)
{
	ui.tableWidget_DO->insertRow(0);
}

void ShowBCU::UpdataSYSStatus(MOBUS_RUN_STATE_BASE_s_2 holding_reg_params2)
{
	QString bmsMachStatus = "BMS主状态:" +bmsMasterSatusMap.value(holding_reg_params2.MODBUS_BMS_STATE >> 8)+"\r\n";
	QString bmsSubStatus =   "BMS次状态:"+ bmsSubSatusMap.value(holding_reg_params2.MODBUS_BMS_STATE & 0xff) + "\r\n";
	QString sysMachStatus =  "系统主状态:"+sysMasterSatusMap.value(holding_reg_params2.MODBUS_SYS_STATE >> 8) + "\r\n";
	QString sysSubStatus =   "系统次状态:" + sysSubSatusMap.value(holding_reg_params2.MODBUS_SYS_STATE & 0xff) + "\r\n";
	QString ErrorReason =    "错误原因:" + errorReasonMap.value(holding_reg_params2.MODUBS_ERROR_REASON ) + "\r\n";
	
	QString chgdhgStatus =   "充放电状态:" + chgdhgStatusMap.value(holding_reg_params2.MODBUS_CHG_DHG_POWER ) + "\r\n";


	ui.wd_SOC->SetTip(bmsMachStatus+ bmsSubStatus+ sysMachStatus+ sysSubStatus+ ErrorReason+ chgdhgStatus);

	if (holding_reg_params2.MODBUS_ALARM_I_L == 0)
	{
		ui.lbMOL_P->setPixmap(QPixmap(":/icon/globes_green.png"));
	}
	else
	{
		ui.lbMOL_P->setPixmap(QPixmap(":/icon/globes_red.png"));
	}

	if (holding_reg_params2.MODBUS_ALARM_II_L == 0)
	{
		ui.lbRSL_P->setPixmap(QPixmap(":/icon/globes_green.png"));
	}
	else
	{
		ui.lbRSL_P->setPixmap(QPixmap(":/icon/globes_red.png"));
	}

	if (holding_reg_params2.MODBUS_ALARM_III_L == 0)
	{
		ui.lbMSL_P->setPixmap(QPixmap(":/icon/globes_green.png"));
	}
	else
	{
		ui.lbMSL_P->setPixmap(QPixmap(":/icon/globes_red.png"));
	}

	if ((holding_reg_params2.MODBUS_ALARM_ERROR_I | holding_reg_params2.MODBUS_ALARM_ERROR_II \
		|holding_reg_params2.MODBUS_ALARM_ERROR_III| holding_reg_params2.MODBUS_ALARM_ERROR_IV \
		| holding_reg_params2.MODBUS_ALARM_ERROR_V \
		| holding_reg_params2.MODBUS_ALARM_ERROR_VI) == 0)
	{
		ui.lbERROR_P->setPixmap(QPixmap(":/icon/globes_green.png"));
	}
	else
	{
		ui.lbERROR_P->setPixmap(QPixmap(":/icon/globes_red.png"));
	}
	ErrorBit[0] = holding_reg_params2.MODBUS_ALARM_ERROR_I;
	ErrorBit[1] = holding_reg_params2.MODBUS_ALARM_ERROR_II;
	ErrorBit[2] = holding_reg_params2.MODBUS_ALARM_ERROR_III;
	ErrorBit[3] = holding_reg_params2.MODBUS_ALARM_ERROR_IV;
	ErrorBit[4] = holding_reg_params2.MODBUS_ALARM_ERROR_V;
	ErrorBit[5] = holding_reg_params2.MODBUS_ALARM_ERROR_VI;
	uint32_t Level_h = holding_reg_params2.MODBUS_ALARM_I_L & holding_reg_params2.MODBUS_ALARM_II_L & holding_reg_params2.MODBUS_ALARM_III_L;
	uint32_t Level_m = holding_reg_params2.MODBUS_ALARM_I_L & holding_reg_params2.MODBUS_ALARM_II_L;

	uint32_t alarm_data = holding_reg_params2.MODBUS_ALARM_I_L | holding_reg_params2.MODBUS_ALARM_II_L | holding_reg_params2.MODBUS_ALARM_III_L;

	UpdataAlarmMSLTable(alarm_data, Level_h, Level_m);



   ui.PCB_PTemp->setText(QString::number(holding_reg_params2.MODBUS_PCB_TEMP*0.1) + T_Uint);                         /**< 电流温度 */
   ui.P_PTemp->setText(QString::number(holding_reg_params2.MODBUS_PACK_PLUS_TEMP * 0.1) + T_Uint);
   ui.P_NTemp->setText(QString::number(holding_reg_params2.MODBUS_PACK_MINUS_TEMP * 0.1) + T_Uint);
   ui.B_PTemp->setText(QString::number(holding_reg_params2.MODBUS_BATTERY_PLUS_TEMP * 0.1) + T_Uint);
   ui.B_NTemp->setText(QString::number(holding_reg_params2.MODBUS_BATTERY_MINUS_TEMP * 0.1) + T_Uint);
   ui.BAT_Temp->setText(QString::number(holding_reg_params2.MODBUS_CURRENT_TEMP * 0.1) + T_Uint);

	Data.DOFbStatus.Bitmap = holding_reg_params2.MODBUS_OUTPUT_STATE;
	UpdataDODIStatusTable(&Data);
	
}

void ShowBCU::UpdateRunstatus(MOBUS_RUN_STATE_BASE_s holding_reg_params)
{
	// Fresh UI
	if ((holding_reg_params.MODBUS_CONTACTOR_STATE & 0x1) == 1)
	{

		ui.widget->setToggle(true);
	}
	else
	{
		ui.widget->setToggle(false);
	}
	if ((holding_reg_params.MODBUS_CONTACTOR_STATE & 0x2) == 0x2)
	{
		ui.widget_2->setToggle(true);
	}
	else
	{
		ui.widget_2->setToggle(false);
	}

	if ((holding_reg_params.MODBUS_CONTACTOR_STATE & 0x4) == 0x4)
	{
		ui.widget_3->setToggle(true);
	}
	else
	{
		ui.widget_3->setToggle(false);
	}


	if (holding_reg_params.MODBUS_INSULATION_STATE  == 0)
	{
		ui.widget_4->setToggle(true);
	}
	else
	{
		ui.widget_4->setToggle(false);
	}

	if ((holding_reg_params.MODBUS_CONTACTOR_STATE & 0x10) == 0x10)
	{
		ui.widget_5->setToggle(true);
	}
	else
	{
		ui.widget_5->setToggle(false);
	}
	ui.wd_SOC->setValue(holding_reg_params.MODBUS_SOC * 0.01);

	ui.wd_Voltage->setCurrentValue(holding_reg_params.MODBUS_CLUSTER_VOLT * 0.1);
	if (holding_reg_params.MODBUS_CLUSTER_CUR < 0)
	{
		//标签
		ui.wd_Current->label = "电流表/充电";
		// ui.wd_Current.label("%1A-充电");
	}
	else if (holding_reg_params.MODBUS_CLUSTER_CUR > 0)
	{
		ui.wd_Current->label = "电流表/放电";
		//ui.wd_Current->setValuesUnit("%1A-放电");
	}
	else
	{
		ui.wd_Current->label = "电流表/静置";
		//  ui.wd_Current->setValuesUnit("%1A");
	}
	ui.wd_Current->setCurrentValue(abs(holding_reg_params.MODBUS_CLUSTER_CUR * 0.1));
	ui.lESOH->setText(QString::number(holding_reg_params.MODBUS_SOH));
	ui.lESOE->setText(QString::number(holding_reg_params.MODBUS_SOE * 0.01));
	ui.lESOC->setText(QString::number(holding_reg_params.MODBUS_SOC * 0.01));
	ui.accChargeCapacity->setText(QString::number(holding_reg_params.MODBUS_ALL_CHG_AH_L));
	ui.accDischargeCapacity->setText(QString::number(holding_reg_params.MODBUS_ALL_DHG_AH_L));

	ui.factoryFullCapacity->setText("");
	ui.NEGATIVE_BUS_RESISTANCE->setText(QString::number(holding_reg_params.MODBUS_NEGATIVE_BUS_RESISTANCE));
	ui.POSITIVE_BUS_RESISTANCE->setText(QString::number(holding_reg_params.MODBUS_POSITIVE_BUS_RESISTANCE));
	if (holding_reg_params.MODBUS_CLUSTER_CUR == 0)
	{
		//statusTip = "停止";
		ui.wd_SOC->SetBatteryStatus(0);
	}
	else if (holding_reg_params.MODBUS_CLUSTER_CUR > 0)
	{
		// 放电
		//statusTip = "正在放电";
		ui.wd_SOC->SetBatteryStatus(2);
	}
	else if (holding_reg_params.MODBUS_CLUSTER_CUR < 0)
	{
		// 充电
		//statusTip = "正在充电";
		ui.wd_SOC->SetBatteryStatus(1);
	}
	else if (holding_reg_params.MODBUS_BATTERY_STATE & 0xe == 0xe)
	{
		// 故障
		//statusTip = "故障";
		ui.wd_SOC->SetBatteryStatus(3);
	}
	// 最大允许充电电压
	ui.MAX_CHG_VOLT->setText(QString::number(holding_reg_params.MODBUS_MAX_CHG_VOLT * 0.1) + V_Uint);
	ui.MAX_M_VOLT->setText(QString::number(holding_reg_params.MODBUS_MAX_M_VOLT * 0.1) + V_Uint);
	ui.MAX_M_VOLT_ADDR->setText(QString::number(holding_reg_params.MODBUS_MAX_M_VOLT_ADDR));
	ui.MAX_S_VOLT->setText(QString::number(holding_reg_params.MODBUS_MAX_S_VOLT * 0.001) + V_Uint);
	ui.MAX_S_VOLT_M_ADDR->setText(QString::number(holding_reg_params.MODBUS_MAX_S_VOLT_M_ADDR));
	ui.MAX_S_VOLT_CELL_ADDR->setText(QString::number(holding_reg_params.MODBUS_MAX_S_VOLT_CELL_ADDR));
	ui.AVERAGE_S_VOLT->setText(QString::number(holding_reg_params.MODBUS_AVERAGE_S_VOLT * 0.001) + V_Uint);
	ui.AVERAGE_S_VOLT_2->setText(QString::number(holding_reg_params.MODBUS_AVERAGE_M_VOLT * 0.001) + V_Uint);
	ui.MIN_DHG_VOLT->setText(QString::number(holding_reg_params.MODBUS_MIN_DHG_VOLT * 0.1) + V_Uint);
	ui.MIN_M_VOLT->setText(QString::number(holding_reg_params.MODBUS_MIN_M_VOLT * 0.1) + V_Uint);
	ui.MIN_M_VOLT_ADDR->setText(QString::number(holding_reg_params.MODBUS_MIN_M_VOLT_ADDR));
	ui.MIN_S_VOLT->setText(QString::number(holding_reg_params.MODBUS_MIN_S_VOLT * 0.001) + V_Uint);
	ui.MIN_S_VOLT_M_ADDR->setText(QString::number(holding_reg_params.MODBUS_MIN_S_VOLT_M_ADDR));
	ui.MIN_S_VOLT_CELL_ADDR->setText(QString::number(holding_reg_params.MODBUS_MIN_S_VOLT_CELL_ADDR));

	ui.lErecommendedContinuousChargeCurrent->setText(QString::number(holding_reg_params.MODBUS_MAX_CHG_CUR * 0.1));
	ui.lErecommendedContinuousDischargeCurrent->setText(QString::number(holding_reg_params.MODBUS_MAX_DHG_CUR * 0.1));

	ui.lEnrModuleMaximumTemperature->setText(QString::number(holding_reg_params.MODBUS_MAX_S_TEMP_M_ADDR));
	ui.lEnrSensorMaximumTemperature->setText(QString::number(holding_reg_params.MODBUS_MAX_S_TEMP_CELL_ADDR));
	ui.lEnrModuleMinimumTemperature->setText(QString::number(holding_reg_params.MODBUS_MIN_S_TEMP_M_ADDR));
	ui.lEnrSensorMinimumTemperature->setText(QString::number(holding_reg_params.MODBUS_MIN_S_TEMP_CELL_ADDR));
	ui.lEmaximumTemperature_ddegC->setText(QString::number(holding_reg_params.MODBUS_MAX_S_TEMP * 0.01) + T_Uint);
	ui.lEminimumTemperature_ddegC->setText(QString::number(holding_reg_params.MODBUS_MIN_S_TEMP * 0.01) + T_Uint);

	ui.lEaverageTemperature_ddegC->setText(QString::number(holding_reg_params.MODBUS_AVERAGE_S_TEMP * 0.01) + T_Uint);
	ui.TEMP_SUB->setText(QString::number((holding_reg_params.MODBUS_MAX_S_TEMP - holding_reg_params.MODBUS_MIN_S_TEMP) * 0.01) + T_Uint);
	ui.VOLT_SUB->setText(QString::number((holding_reg_params.MODBUS_MAX_S_VOLT - holding_reg_params.MODBUS_MIN_S_VOLT) * 0.001) + V_Uint);


	Data.DIStatus.Bitmap = holding_reg_params.MODBUS_INPUT_STATE;
	UpdataDODIStatusTable(&Data);
}

void ShowBCU::UpdateSystemBase(DEV_INFO_s version_params)
{
	  char arr[] = ""; // 定义字符数组
		QString uuid = QString::fromLocal8Bit((char*)&version_params.uuid[0], 16);
		QString softver;
		QString hwver;
		QString SnVer;
		for (int i = 0; i < 3; i++)
		{
			softver += QString::number(version_params.softwareVerion[i], 10);
			hwver += QString::number(version_params.hardwareVerion[i], 10);
		}
		softver += version_params.softwareVerion[3];
		for (int k = 0; k < 16; k++)
		{
			SnVer += QString::number(version_params.sn[k], 16);
		}
		labelStsIP->setText("软件版本: V " + softver + " 硬件版本: V " + hwver + " Sn: " + SnVer + " UUID: " + uuid);
}


void ShowBCU::InitMap(void)
{

	bmsMasterSatusMap.insert(BMS_STATEMACH_UNINITIALIZED, "未初始化");
	bmsMasterSatusMap.insert(BMS_STATEMACH_INITIALIZATION, "初始化");
	bmsMasterSatusMap.insert(BMS_STATEMACH_INITIALIZED, "初始化完成");
	bmsMasterSatusMap.insert(BMS_STATEMACH_IDLE, "空闲状态");
	bmsMasterSatusMap.insert(BMS_STATEMACH_OPEN_CONTACTORS, "开接触器");
	bmsMasterSatusMap.insert(BMS_STATEMACH_STANDBY, "STANDBY");
	bmsMasterSatusMap.insert(BMS_STATEMACH_PRECHARGE, "预充");
	bmsMasterSatusMap.insert(BMS_STATEMACH_NORMAL, "正常");
	bmsMasterSatusMap.insert(BMS_STATEMACH_DISCHARGE, "放电");
	bmsMasterSatusMap.insert(BMS_STATEMACH_CHARGE, "充电");
	bmsMasterSatusMap.insert(BMS_STATEMACH_ERROR, "错误");
	bmsMasterSatusMap.insert(BMS_STATEMACH_POWEROFF, "掉电");
	bmsMasterSatusMap.insert(BMS_STATEMACH_OPEN_CONTACTORS_WITH_ERROR, "OPEN_CONTACTORS_WITH_ERROR");
	bmsMasterSatusMap.insert(BMS_STATEMACH_TEST, "测试模式");


	bmsSubSatusMap.insert(BMS_ENTRY, "BMS_ENTRY");
	bmsSubSatusMap.insert(BMS_CHECK_ERROR_FLAGS_INTERLOCK, "CHECK_ERROR_FLAGS_INTERLOCK");
	bmsSubSatusMap.insert(BMS_INTERLOCK_CHECKED, "INTERLOCK_CHECKED");
	bmsSubSatusMap.insert(BMS_CHECK_STATE_REQUESTS, "CHECK_STATE_REQUESTS");
	bmsSubSatusMap.insert(BMS_CHECK_BALANCING_REQUESTS, "BALANCING_REQUESTS");
	bmsSubSatusMap.insert(BMS_CHECK_ERROR_FLAGS, "ERROR_FLAGS");
	bmsSubSatusMap.insert(BMS_CHECK_CONTACTOR_NORMAL_STATE, "CONTACTOR_NORMAL_STATE");
	bmsSubSatusMap.insert(BMS_CHECK_CONTACTOR_CHARGE_STATE, "CONTACTOR_CHARGE_STATE");
	bmsSubSatusMap.insert(BMS_PRECHARGE_CLOSE_MINUS, "PRECHARGE_CLOSE_MINUS");
	bmsSubSatusMap.insert(BMS_PRECHARGE_CHECK_MINUS_CLOSE, "PRECHARGE_CHECK_MINUS_CLOSE");
	bmsSubSatusMap.insert(BMS_PRECHARGE_CLOSE_PRECHARGE, "PRECHARGE_CLOSE_PRECHARGE");
	bmsSubSatusMap.insert(BMS_PRECHARGE_CHECK_PRECHARGE_CLOSE, "PRECHARGE_CHECK_PRECHARGE_CLOSE");
	bmsSubSatusMap.insert(BMS_PRECHARGE_CHECK_VOLTAGES, "PRECHARGE_CHECK_VOLTAGES");
	bmsSubSatusMap.insert(BMS_PRECHARGE_CHECK_PLUS_CLOSE, "PRECHARGE_CHECK_PLUS_CLOSE");
	bmsSubSatusMap.insert(BMS_PRECHARGE_OPEN_PRECHARGE, "PRECHARGE_OPEN_PRECHARGE");
	bmsSubSatusMap.insert(BMS_PRECHARGE_CHECK_OPEN_PRECHARGE, "PRECHARGE_CHECK_OPEN_PRECHARGE");
	bmsSubSatusMap.insert(BMS_OPEN_FIRST_CONTACTOR, "OPEN_FIRST_CONTACTOR");
	bmsSubSatusMap.insert(BMS_OPEN_SECOND_CONTACTOR_MINUS, "OPEN_SECOND_CONTACTOR_MINUS");
	bmsSubSatusMap.insert(BMS_OPEN_SECOND_CONTACTOR_PLUS, "OPEN_SECOND_CONTACTOR_PLUS");
	bmsSubSatusMap.insert(BMS_CHECK_CLOSE_SECOND_STRING_CONTACTOR_PRECHARGE_STATE, "CLOSE_SECOND_STRING_CONTACTOR_PRECHARGE_STATE");
	bmsSubSatusMap.insert(BMS_CHECK_ERROR_FLAGS_PRECHARGE, "ERROR_FLAGS_PRECHARGE");
	bmsSubSatusMap.insert(BMS_CHECK_ERROR_FLAGS_PRECHARGE_FIRST_STRING, "ERROR_FLAGS_PRECHARGE_FIRST_STRING");
	bmsSubSatusMap.insert(BMS_PRECHARGE_CLOSE_NEXT_STRING, "CLOSE_NEXT_STRING");
	bmsSubSatusMap.insert(BMS_CLOSE_SECOND_CONTACTOR_PLUS, "CLOSE_SECOND_CONTACTOR_PLUS");
	bmsSubSatusMap.insert(BMS_CHECK_STRING_CLOSED, "CHECK_STRING_CLOSED");
	bmsSubSatusMap.insert(BMS_CHECK_ERROR_FLAGS_PRECHARGE_CLOSINGSTRINGS, "ERROR_FLAGS_PRECHARGE_CLOSINGSTRINGS");
	bmsSubSatusMap.insert(BMS_CHECK_ERROR_FLAGS_CLOSINGPRECHARGE, "FLAGS_CLOSINGPRECHARGE");
	bmsSubSatusMap.insert(BMS_NORMAL_CLOSE_NEXT_STRING, "CLOSE_NEXT_STRING");
	bmsSubSatusMap.insert(BMS_NORMAL_CLOSE_SECOND_STRING_CONTACTOR, "CLOSE_SECOND_STRING_CONTACTO");
	bmsSubSatusMap.insert(BMS_NORMAL_CHECK_CONTACTOR_PLUS_OPEN, "CHECK_CONTACTOR_PLUS_OPEN");
	bmsSubSatusMap.insert(BMS_NORMAL_CHECK_CONTACTOR_PLUS_CLOSE, "CHECK_CONTACTOR_PLUS_CLOSE");
	bmsSubSatusMap.insert(BMS_NORMAL_CHECK_CONTACTOR_CHARGE_OPEN, "CHECK_CONTACTOR_CHARGE_OPEN");
	bmsSubSatusMap.insert(BMS_NORMAL_CHECK_CONTACTOR_CHARGE_CLOSE, "CHECK_CONTACTOR_CHARGE_CLOSE");
	bmsSubSatusMap.insert(BMS_OPEN_PRECHARGE, "OPEN_PRECHARGE");
	bmsSubSatusMap.insert(BMS_OPEN_PLUS_CONTACTOR, "OPEN_PLUS_CONTACTOR");
	bmsSubSatusMap.insert(BMS_OPEN_MINUS_CONTACTOR, "OPEN_MINUS_CONTACTOR");
	bmsSubSatusMap.insert(BMS_CHECK_MINUS_CONTACTOR, "CHECK_MINUS_CONTACTOR");
	bmsSubSatusMap.insert(BMS_OPEN_EXIT, "OPEN_EXIT");

	sysMasterSatusMap.insert(SYS_STATEMACH_UNINITIALIZED, "UNINITIALIZED");
	sysMasterSatusMap.insert(SYS_STATEMACH_INITIALIZATION, "INITIALIZATION");
	sysMasterSatusMap.insert(SYS_STATEMACH_SYSTEM_BIST, "SYSTEM_BIST");
	sysMasterSatusMap.insert(SYS_STATEMACH_INITIALIZED, "INITIALIZED");
	sysMasterSatusMap.insert(SYS_STATEMACH_INITIALIZE_CAN, "INITIALIZE_CAN");
	sysMasterSatusMap.insert(SYS_STATEMACH_INITIALIZE_SELFCHECK, "INITIALIZE_SELFCHECK");
	sysMasterSatusMap.insert(SYS_STATEMACH_NODE_ID_ALLOC, "NODE_ID_ALLOC");
	sysMasterSatusMap.insert(SYS_STATEMACH_INITIALIZE_CONTACTORS, "INITIALIZE_CONTACTORS");
	sysMasterSatusMap.insert(SYS_STATEMACH_INITIALIZE_BALANCING, "INITIALIZE_BALANCING");
	sysMasterSatusMap.insert(SYS_STATEMACH_INITIALIZE_BMS, "INITIALIZE_BMS");
	sysMasterSatusMap.insert(SYS_STATEMACH_RUNNING, "RUNNING");
	sysMasterSatusMap.insert(SYS_STATEMACH_FIRST_MEASUREMENT_CYCLE, "FIRST_MEASUREMENT_CYCLE");
	sysMasterSatusMap.insert(SYS_STATEMACH_INITIALIZE_MISC, "INITIALIZE_MISC");
	sysMasterSatusMap.insert(SYS_STATEMACH_INITIALIZE_SE, "INITIALIZE_SE");
	sysMasterSatusMap.insert(SYS_STATEMACH_INITIALIZE_IMD, "INITIALIZE_IMD");
	sysMasterSatusMap.insert(SYS_STATEMACH_ERROR, "ERROR");



	sysSubSatusMap.insert(SYS_ENTRY, "SYS_ENTRY");
	sysSubSatusMap.insert(SYS_CHECK_ERROR_FLAGS, "SYS_CHECK_ERROR_FLAGS");
	sysSubSatusMap.insert(SYS_CHECK_STATE_REQUESTS, "SYS_CHECK_STATE_REQUESTS");
	sysSubSatusMap.insert(SYS_WAIT_INITIALIZATION_SBC, "SYS_WAIT_INITIALIZATION_SBC");
	sysSubSatusMap.insert(SYS_WAIT_INITIALIZATION_INTERLOCK, "SYS_WAIT_INITIALIZATION_INTERLOCK");
	sysSubSatusMap.insert(SYS_WAIT_INITIALIZATION_CONT, "SYS_WAIT_INITIALIZATION_CONT");
	sysSubSatusMap.insert(SYS_WAIT_INITIALIZATION_BAL, "SYS_WAIT_INITIALIZATION_BAL");
	sysSubSatusMap.insert(SYS_WAIT_INITIALIZATION_BAL_GLOBAL_ENABLE, "SYS_WAIT_INITIALIZATION_BAL_GLOBAL_ENABLE");
	sysSubSatusMap.insert(SYS_WAIT_INITIALIZATION_IMD, "SYS_WAIT_INITIALIZATION_IMD");
	sysSubSatusMap.insert(SYS_WAIT_INITIALIZATION_BMS, "SYS_WAIT_INITIALIZATION_BMS");
	sysSubSatusMap.insert(SYS_WAIT_NODE_ADDR_OK, "SYS_WAIT_NODE_ADDR_OK");
	sysSubSatusMap.insert(SYS_WAIT_DEV_INFO_RESP, "SYS_WAIT_DEV_INFO_RESP");
	sysSubSatusMap.insert(SYS_WAIT_FIRST_MEASUREMENT_CYCLE, "SYS_WAIT_FIRST_MEASUREMENT_CYCLE");
	sysSubSatusMap.insert(SYS_WAIT_CURRENT_SENSOR_PRESENCE, "SYS_WAIT_CURRENT_SENSOR_PRESENCE");
	sysSubSatusMap.insert(SYS_SBC_INITIALIZATION_ERROR, "SYS_SBC_INITIALIZATION_ERROR");
	sysSubSatusMap.insert(SYS_CONT_INITIALIZATION_ERROR, "SYS_SBC_INITIALIZATION_ERROR");
	sysSubSatusMap.insert(SYS_BAL_INITIALIZATION_ERROR, "SYS_SBC_INITIALIZATION_ERROR");
	sysSubSatusMap.insert(SYS_ILCK_INITIALIZATION_ERROR, "ILCK_INITIALIZATION_ERROR");        
	sysSubSatusMap.insert(SYS_IMD_INITIALIZATION_ERROR, "INITIALIZATION_ERROR");              
	sysSubSatusMap.insert(SYS_BMS_INITIALIZATION_ERROR, "BMS_INITIALIZATION_ERROR");          
	sysSubSatusMap.insert(SYS_MEAS_INITIALIZATION_ERROR, "MEAS_INITIALIZATION_ERROR");        
	sysSubSatusMap.insert(SYS_CURRENT_SENSOR_PRESENCE_ERROR, "CURRENT_SENSOR_PRESENCE_ERROR");


	errorReasonMap.insert(DIAG_ERR_REASON_NONE, "无");
	errorReasonMap.insert(DIAG_ERR_REASON_FAULT_LOCK, "DIAG_ERR_REASON_FAULT_LOCK");
	errorReasonMap.insert(DIAG_ERR_REASON_MACRO_TEST, "MACRO_TEST");
	errorReasonMap.insert(DIAG_ERR_REASON_DB_TEST, "DB_TEST");
	errorReasonMap.insert(DIAG_ERR_REASON_OS_TEST, "OS_TEST");
	errorReasonMap.insert(DIAG_ERR_REASON_SAFTY_TEST, "SAFTY_TES");
	errorReasonMap.insert(DIAG_ERR_REASON_HVADC_TEST, "HVADC_TEST");
	errorReasonMap.insert(DIAG_ERR_REASON_MCUADC_TEST, "REASON_MCUADC_TEST");
	errorReasonMap.insert(DIAG_ERR_REASON_CONT_TEST, "CONT_TEST");
	errorReasonMap.insert(DIAG_ERR_REASON_ADDR_ALLOC, "ADDR_ALLOC");
	errorReasonMap.insert(DIAG_ERR_REASON_STING_NO_MACTH, "_STING_NO_MACTH");
	errorReasonMap.insert(DIAG_ERR_REASON_CURRENT_SENSOR_NO_RESPOND, "CURRENT_SENSOR_NO_RESPOND");
	errorReasonMap.insert(DIAG_ERR_REASON_INSULATION_TEST, "INSULATION_TEST");
	errorReasonMap.insert(DIAG_ERR_REASON_BMS_INIT, "BMS_INIT");
	errorReasonMap.insert(DIAG_ERR_REASON_BMS_IDLE_ERROR, "_BMS_IDLE_ERROR");
	errorReasonMap.insert(DIAG_ERR_REASON_BMS_STANDBY_ERROR, "BMS_STANDBY_ERROR");
	errorReasonMap.insert(DIAG_ERR_REASON_BMS_PRECHARGE_ERROR, "BMS_PRECHARGE_ERROR");
	errorReasonMap.insert(DIAG_ERR_REASON_BMS_PRECHARGE_MINUS_CLOSE_ERROR, "BMS_PRECHARGE_MINUS_CLOSE_ERROR");
	errorReasonMap.insert(DIAG_ERR_REASON_BMS_PRECHARGE_PRECHARGE_CLOSE_ERROR, "PRECHARGE_PRECHARGE_CLOSE_ERROR");
	errorReasonMap.insert(DIAG_ERR_REASON_BMS_PRECHARGE_PRECHARGE_ERROR1, "RECHARGE_PRECHARGE_ERROR1");
	errorReasonMap.insert(DIAG_ERR_REASON_BMS_PRECHARGE_FAIL_ERROR, "PRECHARGE_FAIL_ERROR");
	errorReasonMap.insert(DIAG_ERR_REASON_BMS_PRECHARGE_PLUS_CLOSE_ERROR, "PRECHARGE_PLUS_CLOSE_ERROR");
	errorReasonMap.insert(DIAG_ERR_REASON_BMS_PRECHARGE_PRECHARGE_OPEN_ERROR, "MS_PRECHARGE_PRECHARGE_OPEN_ERROR");


	chgdhgStatusMap.insert(0, "静置状态");
	chgdhgStatusMap.insert(0x0100, "充电状态");
	chgdhgStatusMap.insert(0x01, "放电状态");

}
void ShowBCU::LoadBCUDB()
{
	QSqlDatabase bmudb = QSqlDatabase::addDatabase("QSQLITE");
	bmudb.setDatabaseName("bcudb.db");
	if (!bmudb.open()) //如果数据库打开失败，会弹出一个警告窗口
	{
		QMessageBox::warning(this, "警告", "数据库打开失败");
	}
	else
	{
		  qDebug()<<"bcudb ok！";
	}
}
void ShowBCU::AddBCUStatusTable(MOBUS_RUN_STATE_BASE_s holding_reg_params)
{
	if (DataBaseEnable == false)
		return;
	LoadBCUDB();
	QDateTime time = QDateTime::currentDateTime();
	QString    curTime = time.toString("yyyy-MM-dd hh:mm:ss");
	int currentRow = 0;
	QString str = QString("insert into BCUInfoBase(Time,总电压,总电流,接触器状态,电池状态,SOC,SOH,SOE,最大单体电压,最小单体电压,\
                          平均单体电压,最大单体温度,最小单体温度,平均单体温度,P正总压,绝缘状态字,正母线电阻,负母线电阻) \
                         values('%1', '%2', '%3', '%4','%5','%6','%7', '%8', '%9', '%10','%11','\
		                 %12','%13', '%14', '%15', '%16','%17','%18')")\
		                .arg(curTime).arg(holding_reg_params.MODBUS_CLUSTER_VOLT).arg(holding_reg_params.MODBUS_CLUSTER_CUR).arg(holding_reg_params.MODBUS_CONTACTOR_STATE).arg(holding_reg_params.MODBUS_BATTERY_STATE)\
		                .arg(holding_reg_params.MODBUS_SOC).arg(holding_reg_params.MODBUS_SOH).arg(holding_reg_params.MODBUS_SOE)\
		                .arg(holding_reg_params.MODBUS_MAX_S_VOLT).arg(holding_reg_params.MODBUS_MIN_S_VOLT).arg(holding_reg_params.MODBUS_AVERAGE_S_VOLT)\
		                .arg(holding_reg_params.MODBUS_MAX_S_TEMP).arg(holding_reg_params.MODBUS_MIN_S_TEMP).arg(holding_reg_params.MODBUS_AVERAGE_S_TEMP).arg(holding_reg_params.MODBUS_P_VOLT)\
		               .arg(holding_reg_params.MODBUS_INSULATION_STATE).arg(holding_reg_params.MODBUS_POSITIVE_BUS_RESISTANCE).arg(holding_reg_params.MODBUS_NEGATIVE_BUS_RESISTANCE);
	QSqlQuery query;
	QString err_info;
	//str = QString("insert into BCUInfoBase(Time)values('%1')").arg(curTime);
	//bcudb->querying(str);
	//return;
	if (!query.exec(str)) //执行插入操作
	{
		QString err_info = tr("数据库失败[%1]").arg(query.lastError().text());
		qDebug() << str;
	}
}
void ShowBCU::AddBCUAlarmTable(MOBUS_RUN_STATE_BASE_s_2 holding_reg_params)
{
	if (DataBaseEnable == false)
		return;
	LoadBCUDB();
	QDateTime time = QDateTime::currentDateTime();
	QString    curTime = time.toString("yyyy-MM-dd hh:mm:ss");
	int currentRow = 0;
	QString str = QString("insert into BCUAlarmInfo(Time,一级报警低,二级报警低,三级报警低,ALARM_ERROR_I,ALARM_ERROR_II,ALARM_ERROR_III,ALARM_ERROR_IV,ALARM_ERROR_V,ALARM_ERROR_VI,\
                          BMS_STATE,SYS_STATE,CHG_DHG_POWER,ERROR_REASON) \
                          values('%1', '%2', '%3', '%4','%5','%6','%7', '%8', '%9', '%10','%11','\
		                  %12','%13', '%14')")\
		.arg(curTime).arg(holding_reg_params.MODBUS_ALARM_I_L).arg(holding_reg_params.MODBUS_ALARM_II_L).arg(holding_reg_params.MODBUS_ALARM_III_L).arg(holding_reg_params.MODBUS_ALARM_ERROR_I)\
		.arg(holding_reg_params.MODBUS_ALARM_ERROR_II).arg(holding_reg_params.MODBUS_ALARM_ERROR_III).arg(holding_reg_params.MODBUS_ALARM_ERROR_IV)\
		.arg(holding_reg_params.MODBUS_ALARM_ERROR_V).arg(holding_reg_params.MODBUS_ALARM_ERROR_VI).arg(holding_reg_params.MODBUS_BMS_STATE)\
		.arg(holding_reg_params.MODBUS_SYS_STATE).arg(holding_reg_params.MODBUS_CHG_DHG_POWER).arg(holding_reg_params.MODUBS_ERROR_REASON);
	QSqlQuery query;
	QString err_info;
	//str = QString("insert into BCUInfoBase(Time)values('%1')").arg(curTime);
	if (!query.exec(str)) //执行插入操作
	{
		QString err_info = tr("数据库失败[%1]").arg(query.lastError().text());
		qDebug() << str;
	}
}
void ShowBCU::SlotsUpMBShowBcu(uint startAddress, QVector<quint16> val)
{
	QVector<quint16> vAllData = val;
	DEV_INFO_s  version_params = { 0 };
	MOBUS_RUN_STATE_BASE_s_2  holding_reg_params2 = { 0 };
	MOBUS_RUN_STATE_BASE_s  holding_reg_params = { 0 };
	switch (startAddress)
	{
	case MODBUS_RUN_STATE_BASE_2:
		memcpy(&holding_reg_params2, (uint8_t*)&vAllData[0], val.count());
		UpdataSYSStatus(holding_reg_params2);
		AddBCUAlarmTable(holding_reg_params2);
		break;
	case MODBUS_SYSTEM_BASE:
		memcpy(&version_params, (uint8_t*)&vAllData[0], val.count());
		UpdateSystemBase(version_params);

		break;
	case MODBUS_RUN_STATE_BASE:
		memcpy(&holding_reg_params, (uint8_t*)&vAllData[0], val.count());
		UpdateRunstatus(holding_reg_params);
	    AddBCUStatusTable(holding_reg_params);
		break;
	default:
		break;
	}
}

void ShowBCU::SlotsAlarmSetMenu(uint startAddress)
{
	QVector<quint16> writeValue;
	writeValue.append(3);
	drvmng::getInstance().mb_downmsg_holding("Write",0x7007, writeValue);
	writeValue.clear();
	writeValue.append(4);
	drvmng::getInstance().mb_downmsg_holding("Write", 0x7007, writeValue);
	QMessageBox::information(this, "", "进入测试模式");
}

void ShowBCU::SlotsResetMenu(uint startAddress)
{
	QVector<quint16> writeValue;
	writeValue.append(1);
	drvmng::getInstance().mb_downmsg_holding("Write", 0x7000, writeValue);
	QMessageBox::information(this, "", "复位成功");
}
void ShowBCU::SlotsOpenFANMenu(uint startAddress)
{
	QVector<quint16> writeValue;
	writeValue.append(1);
	drvmng::getInstance().mb_downmsg_holding("Write", 7006, writeValue);
	QMessageBox::information(this, "", "风扇开启");
}

void ShowBCU::SlotsCanUpBCUMsg(uint Address, QByteArray val)
{
	Thread::StandFrame_Data* rec_standard_data = (Thread::StandFrame_Data*)val.data();
	UINT32 temp = 0;
	switch (Address)
	{
	case _BCU_SYSSYN_ID_:
		//_BCUCAN_SysSyn_* getMsgsyn = (_BCUCAN_SysSyn_*)rec_standard_data->Data;
		break;
	case _BCU_SYSInfo_ID_SN1:
	case _BCU_SYSInfo_ID_SN2:
		break;
	case _BCU_SYSInfo_ID_UUID1:
	case _BCU_SYSInfo_ID_UUID2:
		break;
	case _BCU_SYSInfo_ID_109:
		break;
	case _BCU_SYSInfo_ID_110:
	{
		_BCUCAN_SysInfo_Module_DoDiStatus* getMsg = (_BCUCAN_SysInfo_Module_DoDiStatus*)rec_standard_data->Data;
		UpdataDODIStatusTable(getMsg);
		if ((getMsg->DOStatus.Bitmap & 0x1f) != (getMsg->DOFbStatus.Bitmap & 0x1f))
		{
			ui.lbDO_Status->setPixmap(QPixmap(":/icon/globes_red.png"));

		}
		else
		{
			ui.lbDO_Status->setPixmap(QPixmap(":/icon/globes_green.png"));
		}
	}
	break;
	case _BCUCAN_RunInfo_Alarm_ID_111:
	{
		_BCUCAN_Alarm_Module_111* getMsg = (_BCUCAN_Alarm_Module_111*)rec_standard_data->Data;
		UpdataAlarmMSLTable(getMsg->MSL.All | getMsg->RSL.All | AlarmBit, getMsg->MSL.All & getMsg->RSL.All & AlarmBit, getMsg->MSL.All & getMsg->RSL.All);
		if (getMsg->MSL.All == 0)
		{
			ui.lbMSL_P->setPixmap(QPixmap(":/icon/globes_green.png"));
		}
		else
		{
			ui.lbMSL_P->setPixmap(QPixmap(":/icon/globes_red.png"));
		}

		if (getMsg->RSL.All == 0)
		{
			ui.lbRSL_P->setPixmap(QPixmap(":/icon/globes_green.png"));
		}
		else
		{
			ui.lbRSL_P->setPixmap(QPixmap(":/icon/globes_red.png"));
		}

	}
	break;
	case _BCUCAN_RunInfo_Alarm_ID_112:
	{
		_BCUCAN_Alarm_Module_112* getMsg = (_BCUCAN_Alarm_Module_112*)rec_standard_data->Data;
		AlarmBit = getMsg->MOL.All;
		if (getMsg->MOL.All == 0)
		{
			ui.lbMOL_P->setPixmap(QPixmap(":/icon/globes_green.png"));
		}
		else
		{
			ui.lbMOL_P->setPixmap(QPixmap(":/icon/globes_red.png"));
		}
		//  UpdataAlarmMSLTable(getMsg->MOL.All);
	}
	break;
	case _BCU_BatteryStatus_ID_113:
	{

		_BCUCAN_SysStatus_Module* getMsg = (_BCUCAN_SysStatus_Module*)rec_standard_data->Data;
		ui.wd_SOC->setValue(getMsg->showSoc);
		if (getMsg->packCurrent_A == 0)
		{
			statusTip = "停止";
			ui.wd_SOC->SetBatteryStatus(0);
		}
		else if (getMsg->packCurrent_A > 0)
		{
			// 放电
			statusTip += "正在放电";
			ui.wd_SOC->SetBatteryStatus(2);
		}
		else if (getMsg->packCurrent_A < 0)
		{
			// 充电
			statusTip += "正在充电";
			ui.wd_SOC->SetBatteryStatus(1);
		}
		else if (getMsg->batteryStatus.Bits.ChargeStatus & 0xe == 0xe)
		{
			// 故障
			statusTip += "故障";
			ui.wd_SOC->SetBatteryStatus(3);
		}

		ui.wd_Voltage->setCurrentValue(getMsg->batteryVoltage_V * 0.1);
		ui.wd_Current->setCurrentValue(getMsg->packCurrent_A * 0.1);
		ui.lESOH->setText(QString::number(getMsg->Soh));
		ui.lESOE->setText(QString::number(getMsg->Soe));
		ui.lESOC->setText(QString::number(getMsg->showSoc));
		ui.wd_SOC->SetTip("\n\r\t电池状态:" + statusTip + "\n\r\t充放电限制:可充可放\n\r\t");
	}
	break;
	case _BCU_BatteryRunInfo_ID_114:
	{
		_BCU_BatteryRunInfo_Module_114* getMsg = (_BCU_BatteryRunInfo_Module_114*)rec_standard_data->Data;
		ui.MAX_CHG_VOLT->setText(QString::number(getMsg->maxBatteryVoltageThreshold * 0.1));
		ui.MIN_DHG_VOLT->setText(QString::number(getMsg->minBatteryVoltageThreshold * 0.1));
		ui.lErecommendedContinuousChargeCurrent->setText(QString::number(getMsg->recommendedContinuousChargeCurrent * 0.1));
		ui.lErecommendedContinuousDischargeCurrent->setText(QString::number(getMsg->recommendedContinuousDischargeCurrent * 0.1));
	}
	break;
	case _BCU_BatteryRunInfo_ID_115:
	{
		_BCU_BatteryRunInfo_Module_115* getMsg = (_BCU_BatteryRunInfo_Module_115*)rec_standard_data->Data;
		ui.MAX_S_VOLT->setText(QString::number(getMsg->maximumCellVoltage_mV));
		ui.MIN_S_VOLT->setText(QString::number(getMsg->minimumCellVoltage_mV));
		ui.lEmaximumTemperature_ddegC->setText(QString::number(getMsg->maximumTemperature_ddegC * 0.1));
		ui.lEminimumTemperature_ddegC->setText(QString::number(getMsg->minimumTemperature_ddegC * 0.1));

	}
	break;
	case _BCU_BatteryRunInfo_ID_116:
	{
		_BCU_BatteryRunInfo_Module_116* getMsg = (_BCU_BatteryRunInfo_Module_116*)rec_standard_data->Data;
		ui.AVERAGE_S_VOLT->setText(QString::number(getMsg->averageCellVoltage_mV));
		ui.lEaverageTemperature_ddegC->setText(QString::number(getMsg->averageTemperature_ddegC * 0.1));
	}
	break;
	case _BCU_BatteryRunInfo_ID_118:
	{
		_BCU_BatteryRunInfo_Module_118* getMsg = (_BCU_BatteryRunInfo_Module_118*)rec_standard_data->Data;
		ui.MAX_S_VOLT_M_ADDR->setText(QString::number(getMsg->nrModuleMaximumCellVoltage));
		ui.MAX_S_VOLT_CELL_ADDR->setText(QString::number(getMsg->nrCellMaximumCellVoltage));
		ui.MIN_S_VOLT_M_ADDR->setText(QString::number(getMsg->nrModuleMinimumCellVoltage));
		ui.MIN_S_VOLT_CELL_ADDR->setText(QString::number(getMsg->nrCellMinimumCellVoltage));
		ui.lEnrModuleMaximumTemperature->setText(QString::number(getMsg->nrModuleMaximumTemperature));
		ui.lEnrSensorMaximumTemperature->setText(QString::number(getMsg->nrSensorMaximumTemperature));
		ui.lEnrModuleMinimumTemperature->setText(QString::number(getMsg->nrModuleMinimumTemperature));
		ui.lEnrSensorMinimumTemperature->setText(QString::number(getMsg->nrSensorMinimumTemperature));
	}
	break;
	case _BCUCAN_CapStatus_Module_ID_1A1:
	{
		_BCUCAN_CapStatus_Module_1A1* Msg = (_BCUCAN_CapStatus_Module_1A1*)rec_standard_data->Data;
		ui.accChargeCapacity->setText(QString::number(Msg->accChargeCapacity));
		ui.accDischargeCapacity->setText(QString::number(Msg->accDischargeCapacity));

	}
	break;
	case _BCUCAN_CapStatus_Module_ID_1A2:
	{
		_BCUCAN_CapStatus_Module_1A2* Msg = (_BCUCAN_CapStatus_Module_1A2*)rec_standard_data->Data;
		ui.factoryFullCapacity->setText(QString::number(Msg->factoryFullCapacity));
	}
	break;
	case _BCUCAN_HvStatus_Module_ID_1A3:
	{
		_BCUCAN_HvStatus_Module_1A3* Msg = (_BCUCAN_HvStatus_Module_1A3*)rec_standard_data->Data;
		temp = Msg->AccVoltage_V;
		temp = Msg->BVoltage_V;
		temp = Msg->current;
		temp = Msg->PVoltage_V;
	}
	break;
	case _BCUCAN_HvStatus_Module_ID_1A4:
	{
		_BCUCAN_HvStatus_Module_1A4* Msg = (_BCUCAN_HvStatus_Module_1A4*)rec_standard_data->Data;
		temp = Msg->insulationResistance_n_kOhm;
		temp = Msg->insulationResistance_p_kOhm;
		temp = Msg->isInsulationMeasurementValid;
	}
	break;
	default:
		break;
	}
}
//void ShowBCU::mousePressEvent(QMouseEvent* event)
//{
//    if (event->button() == Qt::RightButton)
//    {
//     
//        QMenu* menu = new QMenu(this);
//        menu->addAction(tr("电池组实时视图"), this, &ShowBCU::SlotMenuClicked);
//        menu->addAction(tr("电压数据视图"), this, &ShowBCU::SlotMenuClicked);
//        menu->addAction(tr("温度数据视图"), this, &ShowBCU::SlotMenuClicked);
//        menu->addAction(tr("电池组配置视图"), this, &ShowBCU::SlotMenuClicked);
//        menu->setStyleSheet("QMenu {background-color: #435; border: 1px solid #ccc;}");
//
//
//      //  QMenu* menu = new QMenu(this);
//
//
//        menu->exec(QCursor::pos());
//        // connect(m_pMenuRD, &QAction::triggered, this, &SlaveItemInfo::UpdateItemUi);
//        connect(menu, SIGNAL(triggered(QAction*)), this, SLOT(SlotMenuClicked(QAction*)));
//
//    }
//}