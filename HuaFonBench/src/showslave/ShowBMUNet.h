#pragma once

#include <QWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "ui_ShowBMUNet.h"
#include <src/showslave/ShowBMUNetItem.h>
#include "QtWidgetsFan.h"
#include <QMenu>
class ShowBMUNet : public QWidget
{
	Q_OBJECT

public:
	ShowBMUNet(QWidget *parent = nullptr);
	ShowBMUNet(uint8_t BmuId=0, QWidget* parent = nullptr);
	~ShowBMUNet();
	virtual void mousePressEvent(QMouseEvent* event);
private:
	Ui::ShowBMUNetClass ui;
private:
	uint8_t row = 0;
	QList<ShowBMUNetItem*> m_ItemList;
	uint8_t SlaveNum =20;
	uint8_t VoltSensorNum =16;
	uint8_t TemptureSensorNum =18;
	QLabel* lbv ;
	QLabel* lbpcbTemp;
	QLabel* lbblanceTemp;

	QLabel* BatPlusTemp;
	QLabel* BatMinusTemp;
	QLabel* CopperBarScrewTempI;
	QLabel* CopperBarSerewTempII;
	uint8_t SlectBmuID =0;
	QtWidgetsFan* fan;
	QMenu* m_pMenuRD;
	QAction* m_pMenuTest;
private:
	void SlaveItemInit();
	void VersionUpdate();
	void VoltageDataUpdate(uint16_t* volt);
	void TempDataUpdate(int16_t* Temp);
	//void BlanceStatusUpdate(bool Blance[54]);
	void BlanceStatusUpdate(uint64_t Blance);
	//void CnnStatusUpdate(bool Status[54]);
	void CnnStatusUpdate(uint64_t  Status);
	void CreatFanMenu(void);
	void SetFanCtl(uint8_t ctl);
	void SetFanSpeed(uint16_t speed);
	void SetFanType(uint16_t type);
	void SetLineStyle(uint16_t style);
	void SetTempChannelGPIOPort(uint16_t TempChannel,uint16_t GpioPort);

public:
	uint8_t Colunm = 4;
	void SetSlaveNum(uint8_t num) { SlaveNum = num; };
	void SetVoltNum(uint8_t num) { VoltSensorNum = num; };
	void SetTempNum(uint8_t num) { TemptureSensorNum = num; };
private slots:
	void UpdateBmuItemUi();
	void SlotMenuClicked(QAction*);
};
