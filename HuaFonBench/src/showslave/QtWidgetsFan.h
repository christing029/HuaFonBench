#pragma once

#include <QWidget>
#include "ui_QtWidgetsFan.h"
#include <QTimer>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QMenu>
#include <src/public/ToolTip/CuteToolTip.h>
class QtWidgetsFan : public QWidget
{
	Q_OBJECT

public:
	QtWidgetsFan(QWidget *parent = nullptr);
	~QtWidgetsFan();
	void paintEvent(QPaintEvent*);
	void start();
	void stop();
	void speedset(uint16_t speed) { tim->start(speed); };
	void SetTip(QString TipMessage) { tipMessage = TipMessage; }
private:
	QTimer* tim;
	int checkrat;//�жϷ��ȴ򿪻��ǹر�
	CuteToolTip* tip_b;
	QString tipMessage = "";
Q_SIGNALS:
	void valueChanged(double value);
	// ��������
protected:
	bool event(QEvent* e);
private:
	Ui::QtWidgetsFanClass ui;
};
