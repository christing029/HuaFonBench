#pragma once

#include <QWidget>
#include "ui_QtWidgetsFan.h"
#include <QTimer>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QMenu>
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

private:
	QTimer* tim;
	int checkrat;//�жϷ��ȴ򿪻��ǹر�
private:
	Ui::QtWidgetsFanClass ui;
};
