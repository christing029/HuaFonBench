#include "SearchAnimationWidget.h"

SearchAnimationWidget::SearchAnimationWidget(QWidget *parent)
	: QWidget(parent)
{
	//ui.setupUi(this);
	timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &SearchAnimationWidget::onTimer);
	timer->start(50);  // ��ʱ�������Դ����ػ�
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

    // ��������ͼ���Բ������
    QRectF circleRect(center.x() - radius, center.y() - radius, 2 * radius, 2 * radius);
    painter.drawEllipse(circleRect);

    // ��������ͼ��İ��ֲ���
    QPoint handleCenter = center + QPoint(radius * cos(angle), radius * sin(angle));
    QPoint handleEnd = handleCenter + QPoint((radius / 2) * cos(angle), (radius / 2) * sin(angle));
    painter.drawLine(handleCenter, handleEnd);
}
