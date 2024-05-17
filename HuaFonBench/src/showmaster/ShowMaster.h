#pragma once

#include <QWidget>
#include "ui_ShowMaster.h"

class ShowMaster : public QWidget
{
	Q_OBJECT

public:
	ShowMaster(QWidget *parent = nullptr);
	~ShowMaster();

private:
	Ui::ShowMasterClass ui;
};
