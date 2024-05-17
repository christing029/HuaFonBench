#include "AirFlowWidget.h"

AirFlowWidget::AirFlowWidget(QWidget *parent)
	: QWidget(parent)
{
	ui->setupUi(this);
    setFixedSize(300, 300);
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [=]() {
        m_angle += 10;
        update();
        });

    timer->start(50);
}

AirFlowWidget::~AirFlowWidget()
{
    delete ui;
}

void AirFlowWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    // 绘制背景色
    painter.fillRect(rect(), Qt::white);

    // 设置画笔颜色和线宽度
    QPen pen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap);
    painter.setPen(pen);

    // 绘制圆形
    QRectF circleRect(50, 50, 200, 200);
    painter.drawEllipse(circleRect);

    // 计算三角形顶点位置
    QPointF centerPoint = circleRect.center();
    qreal radius = circleRect.width() / 2 - 10;

    QPointF topPoint(centerPoint.x(), centerPoint.y() - radius - 20);

    qreal angleInRadians = (m_angle + 90) * 3.14156 / 180.0;

    QPointF leftPoint(centerPoint.x() - radius * cos(angleInRadians),
        centerPoint.y() + radius * sin(angleInRadians));

    QPointF rightPoint(centerPoint.x() + radius * cos(angleInRadians),
        centerPoint.y() + radius * sin(angleInRadians));

    // 绘制两个三角形
    QPolygonF triangle1;
    triangle1 << centerPoint << topPoint << leftPoint;
    painter.drawPolygon(triangle1);

    QPolygonF triangle2;
    triangle2 << centerPoint << topPoint << rightPoint;
    painter.drawPolygon(triangle2);

}
