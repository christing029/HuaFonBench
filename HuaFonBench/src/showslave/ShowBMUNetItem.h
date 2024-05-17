#pragma once

#include <QWidget>
#include "ui_ShowBMUNetItem.h"
class ShowBMUNetItem : public QWidget
{
	Q_OBJECT

public:
	ShowBMUNetItem(uint ID,QWidget *parent = nullptr);
	~ShowBMUNetItem();
private:
	Ui::ShowBMUNetItemClass ui;
private:
	bool MaxVolt = false;
	bool MinVolt = false;
	bool MaxTemp = false;
	bool MinTemp = false;
public:
	void SetVoltageVal(float val);
	void SetTempVal(float val);
	void SetCnnVal(bool val);
	void SetBlanceVal(bool val);
	void IsMaxVolt(bool Vaild) { MaxVolt = Vaild; };
	void IsMinVolt(bool Vaild) { MinVolt = Vaild; };
	void IsMaxTemp(bool Vaild) { MaxTemp = Vaild; };
	void IsMinTemp(bool Vaild) { MinTemp = Vaild; };
};