#pragma once
#include <QWidget>
#include "ui_SlaveItemWidget.h"

class SlaveItemWidget : public QWidget
{
	Q_OBJECT

public:
	SlaveItemWidget(QWidget *parent = nullptr);
	~SlaveItemWidget();

private:
	Ui::SlaveItemWidgetClass ui;
protected:
	//bool event(QEvent* e);
	//virtual void mousePressEvent(QMouseEvent* event);
	//virtual void enterEvent(QMouseEvent* event);
	//virtual void leaveEvent(QMouseEvent* event);
};
