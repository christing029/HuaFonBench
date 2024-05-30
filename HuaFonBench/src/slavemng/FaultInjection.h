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
	void bmbcufaultSet(QString name,int currentRow,uint16_t type, uint16_t val);
	void bmbcuVTFaultSet(QString name, int currentRow, uint16_t type, uint16_t val);
	void ethbmuVTFaultSet(QString name, int currentRow, uint16_t type, uint16_t val);
	//void canbmufaultSet(QString name, int currentRow, UINT16 type, QString val);
private:
	_FaulltDataST volttable[16];
	_FaulltDataST temptable[16];
	QTableWidget* volttableWidget;
	QTableWidget* temptableWidget;
    QTableWidget*  bcutableWidget;
protected slots:
	void on_button_clicked();
	void on_bcubutton_clicked();
	void on_cBDeviceType_currentTextChanged(const QString &arg1);
private:
	Ui::FaultInjectionClass ui;
};
