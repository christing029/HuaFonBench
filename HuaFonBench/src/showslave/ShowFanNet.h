#pragma once

#include <QWidget>
#include "ui_ShowFanNet.h"

class ShowFanNet : public QWidget
{
	Q_OBJECT

public:
	ShowFanNet(QWidget *parent = nullptr);
	~ShowFanNet();
private slots:
	void UpdateItemUi();
private:
	Ui::ShowFanNetClass ui;
};
