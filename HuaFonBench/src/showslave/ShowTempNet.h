#pragma once

#include <QWidget>
#include "ui_ShowTempNet.h"

class ShowTempNet : public QWidget
{
	Q_OBJECT

public:
	ShowTempNet(uint16_t slaveNum, uint16_t ItemNum, QWidget *parent = nullptr);
	~ShowTempNet();
private:
	void InitUi();
private:
	uint8_t Num;
private slots:
	void UpdateItemUi();
private:
	Ui::ShowTempNetClass ui;
};
