#pragma once

#include <QWidget>
#include "ui_ShowVoltageNet.h"

class ShowVoltageNet : public QWidget
{
	Q_OBJECT

public:
	ShowVoltageNet(uint16_t slaveNum, uint16_t ItemNum,QWidget *parent = nullptr);
	~ShowVoltageNet();
private:
	void InitUi();
	uint16_t slavenum;
	uint16_t VoltageNumPerpack;
private slots:
	void UpdateItemUi();
private:
	Ui::ShowVoltageNetClass ui;
};
