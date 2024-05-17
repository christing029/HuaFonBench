#pragma once

#include <QGraphicsItem>
#include "ui_ArrowItem.h"
#include <QPainter>

class ArrowItem : public QGraphicsItem
{
public:
//	ArrowItem(QWidget *parent = nullptr);
	~ArrowItem();

private:
	Ui::ArrowItemClass ui;
public:
	ArrowItem(QPointF start, QPointF end, QGraphicsItem* parent = nullptr);
	QRectF boundingRect() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
private:
	QPointF m_start;
	QPointF m_end;

};
