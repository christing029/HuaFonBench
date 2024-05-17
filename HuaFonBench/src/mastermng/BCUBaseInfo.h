#pragma once

#ifndef BCUBaseInfo_H
#define BCUBaseInfo_H

#include <QWidget>
#include "ui_BCUBaseInfo.h"

#include <QtCore/qmath.h>
#include <QLineSeries>
#include <QChart>
#include <QSplineSeries>
#include <QtCharts/QChartGlobal>
#include <src/public/ChartView.h>
#include <src/public/callout.h>
#include <src/drvmng/modbus_params.h>
#include <QValueAxis>

class BCUBaseInfo : public QWidget
{
	Q_OBJECT

public:
	BCUBaseInfo(QWidget *parent = nullptr);
	~BCUBaseInfo();

private:
	Ui::BCUBaseInfoClass ui;
};
#endif