#pragma once

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QtMath>
#include "ui_SearchAnimationWidget.h"

class SearchAnimationWidget : public QWidget
{
	Q_OBJECT

public:
	SearchAnimationWidget(QWidget *parent = nullptr);
	~SearchAnimationWidget();



private:
	QTimer* timer;
	qreal angle;
	void paintEvent(QPaintEvent* event) override;
private slots:
	void onTimer();
private:
	Ui::SearchAnimationWidgetClass ui;
};
