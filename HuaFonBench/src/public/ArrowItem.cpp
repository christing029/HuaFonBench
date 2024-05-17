#include "ArrowItem.h"

//ArrowItem::ArrowItem(QWidget *parent)
//	: QGraphicsItem(parent)
//{
//	ui.setupUi(this);
//}

ArrowItem::~ArrowItem()
{}

ArrowItem::ArrowItem(QPointF start, QPointF end, QGraphicsItem * parent)
{
    m_start=  start;
    m_end= end;

}

QRectF ArrowItem::boundingRect() const
{
	return QRectF(m_start, m_end).normalized();
}

void ArrowItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    // 绘制箭头
    painter->setPen(QPen(Qt::black, 2));
    painter->drawLine(m_start, m_end);
    QPointF arrowHead = m_end - m_start;
    arrowHead /= arrowHead.manhattanLength();
    arrowHead *= 20;
    QPointF arrowLeft(-arrowHead.y(), arrowHead.x());
    QPointF arrowRight(arrowHead.y(), -arrowHead.x());
    QVector<QPointF> points;
    points << m_end << m_end - arrowLeft << m_end + arrowRight;
    painter->setBrush(Qt::black);
    painter->drawPolygon(points);

}
