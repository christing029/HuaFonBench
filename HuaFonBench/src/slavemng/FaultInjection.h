#pragma once

#include <QWidget>
#include "ui_FaultInjection.h"
#include <QTableWidget>
class FaultInjection : public QWidget
{
	Q_OBJECT
typedef struct
	{
		QString  Name;
		bool	 Vaild;
		int      Value;
	} _FaulltDataST;
public:
	FaultInjection(QWidget *parent = nullptr);
	~FaultInjection();

private:
	void voltefaultshow();
	void tempfaultshow();
	void difaultshow();
	void currentfaultshow();
private:
	_FaulltDataST volttable[16];
	_FaulltDataST temptable[16];

	QTableWidget* volttableWidget;
	QTableWidget* temptableWidget;
protected slots:
	void on_button_clicked();
private:
	Ui::FaultInjectionClass ui;
};
