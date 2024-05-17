#pragma once

#include <QWidget>
#include "ui_AirFlowWidget.h"
#include <QPainter>
#include <QTimer>
#include <cmath>
class AirFlowWidget : public QWidget
{
	Q_OBJECT

public:
	AirFlowWidget(QWidget *parent = nullptr);
	~AirFlowWidget();

private:
	Ui::AirFlowWidgetClass *ui;
protected:
	void paintEvent(QPaintEvent* event) override;
private:
	int m_angle;
};
