#pragma once

#include <QWidget>
#include "ui_FaultInjection.h"
#include <QTableWidget>
#include <src/drvmng/StantCan_params.h>
class FaultInjection : public QWidget
{
	Q_OBJECT

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
	uint16_t m_bmuvolt_t[16][16];
	uint16_t temptable[16][16];
	QTableWidget* volttableWidget;
	QTableWidget* temptableWidget;
    QTableWidget*  bcutableWidget;
protected slots:
	void on_button_clicked();
	void on_bcubutton_clicked();
	void on_cBDeviceType_currentTextChanged(const QString &arg1);
	void updateUiData();
private:
	Ui::FaultInjectionClass ui;
};
extern _BCUDetailInfoST      g_BCUDetailInfoST;