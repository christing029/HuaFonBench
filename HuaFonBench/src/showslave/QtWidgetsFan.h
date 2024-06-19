#pragma once

#include <QWidget>
#include "ui_QtWidgetsFan.h"
#include <QTimer>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QMenu>
#include "QPoint"
#include <src/public/ToolTip/CuteToolTip.h>
class QtWidgetsFan : public QWidget
{
	Q_OBJECT

public:
	QtWidgetsFan(QWidget *parent = nullptr);
	~QtWidgetsFan();

	void start();
	void stop();
	void speedset(uint16_t speed) { if (speed == 0) { stop(); } else { tim->start(speed * 50); start(); } };
	void SetTip(QString TipMessage) { tipMessage = TipMessage; }
private:
	QTimer* tim;
	int checkrat;//判断风扇打开还是关闭
	CuteToolTip* tip_b;
	QString tipMessage = "";
	void drawFan(QPainter* painter);
	int angle = 0;
	QPoint fanBlades[5]={QPoint(10, 50),QPoint(15, 90),QPoint(0, 100),QPoint(-15, 90),QPoint(-10, 50)};
Q_SIGNALS:
	void valueChanged(double value);
	// 悬浮提升
protected:
	bool event(QEvent* e);
	void paintEvent(QPaintEvent*) override;
private:
	Ui::QtWidgetsFanClass ui;
};
