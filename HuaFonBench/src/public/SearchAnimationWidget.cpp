#include "SearchAnimationWidget.h"

SearchAnimationWidget::SearchAnimationWidget(QWidget *parent)
	: QWidget(parent)
{
	//ui.setupUi(this);
	timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &SearchAnimationWidget::onTimer);
	timer->start(50);  // 定时器，用以触发重绘
     angle=0;
}

SearchAnimationWidget::~SearchAnimationWidget()
{
}

void SearchAnimationWidget::onTimer() {
    angle -= qDegreesToRadians(5.0);
    if (angle < 0) {
        angle += 2 * M_PI;
    }
    update();
}
void SearchAnimationWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int side = qMin(width(), height());
    QPoint center(width() / 2, height() / 2);
    int radius = side / 4;

    // 绘制搜索图标的圆环部分
    QRectF circleRect(center.x() - radius, center.y() - radius, 2 * radius, 2 * radius);
    painter.drawEllipse(circleRect);

    // 绘制搜索图标的把手部分
    QPoint handleCenter = center + QPoint(radius * cos(angle), radius * sin(angle));
    QPoint handleEnd = handleCenter + QPoint((radius / 2) * cos(angle), (radius / 2) * sin(angle));
    painter.drawLine(handleCenter, handleEnd);
}
