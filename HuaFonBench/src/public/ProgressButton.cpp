#include "ProgressButton.h"
#include <QPainter>
ProgressButton::ProgressButton(QWidget *parent)
	
{
    timer = new QTimer();

}

ProgressButton::~ProgressButton()
{}

void ProgressButton::resizeEvent(QResizeEvent*)
{
}

void ProgressButton::mousePressEvent(QMouseEvent*)
{
}

void ProgressButton::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    if (1 == status) {
        //绘制当前进度
        drawProgress(&painter);
    }
    else {
        //绘制按钮背景
        drawBg(&painter);
    }
}

void ProgressButton::drawBg(QPainter* painter)
{
    painter->save();

    int width = this->width();
    int height = this->height();
    int side = qMin(width, height);

    QPen pen;
    pen.setWidth(borderWidth);
    pen.setColor(borderColor);
    painter->setPen(borderWidth > 0 ? pen : Qt::NoPen);
    painter->setBrush(bgColor);

    QRect rect(((width - tempWidth) / 2) + borderWidth, borderWidth, tempWidth - (borderWidth * 2), height - (borderWidth * 2));
    painter->drawRoundedRect(rect, borderRadius, borderRadius);

    QFont font;
    font.setPixelSize(side - 18);
    painter->setFont(font);
    painter->setPen(lineColor);
    painter->drawText(rect, Qt::AlignCenter, status == 2 ?"完 成" : "开 始");

    painter->restore();
}

void ProgressButton::drawProgress(QPainter* painter)
{
    painter->save();

    int width = this->width();
    int height = this->height();
    int side = qMin(width, height);
    int radius = 99 - borderWidth;

    //绘制外圆
    QPen pen;
    pen.setWidth(borderWidth);
    pen.setColor(borderColor);
    painter->setPen(borderWidth > 0 ? pen : Qt::NoPen);
    painter->setBrush(bgColor);

    //平移坐标轴中心,等比例缩放
    QRect rectCircle(-radius, -radius, radius * 2, radius * 2);
    painter->translate(width / 2, height / 2);
    painter->scale(side / 200.0, side / 200.0);
    painter->drawEllipse(rectCircle);

    //绘制圆弧进度
    pen.setWidth(lineWidth);
    pen.setColor(lineColor);
    painter->setPen(pen);

    int offset = radius - lineWidth - 5;
    QRectF rectArc(-offset, -offset, offset * 2, offset * 2);
    int startAngle = offset * 16;
    int spanAngle = -value * 16;
    painter->drawArc(rectArc, startAngle, spanAngle);

    //绘制进度文字
    QFont font;
    font.setPixelSize(offset - 15);
    painter->setFont(font);
    QString strValue = QString("%1%").arg((int)value * 100 / 360);
    painter->drawText(rectCircle, Qt::AlignCenter, strValue);

    painter->restore();

}

int ProgressButton::getLineWidth() const
{
    return this->lineWidth;
}
QColor ProgressButton::getLineColor() const
{
	return this->lineColor;
}

int ProgressButton::getBorderWidth() const
{
	return this->borderWidth;
}

QColor ProgressButton::getBorderColor() const
{
	return this->borderColor;
}

int ProgressButton::getBorderRadius() const
{
	return this->borderRadius;
}

QColor ProgressButton::getBgColor() const
{
	return this->bgColor;
}

QSize ProgressButton::sizeHint() const
{
	return QSize();
}

QSize ProgressButton::minimumSizeHint() const
{
	return QSize();
}

void ProgressButton::setLineColor(const QColor& lineColor)
{
    this->lineColor= lineColor;
}
void ProgressButton::setLineWidth(int lineWidth)
{
   this->lineWidth= lineWidth;
}

void ProgressButton::setBorderWidth(int borderWidth)
{
    this->borderWidth = borderWidth;
}


void ProgressButton::setBorderColor(const QColor& borderColor)
{
    this->borderColor = borderColor;
}

void ProgressButton::setBorderRadius(int borderRadius)
{
    this->borderRadius = borderRadius;
}

void ProgressButton::setBgColor(const QColor& bgColor)
{
    this->bgColor = bgColor;
}

void ProgressButton::progress()
{
    if (0 == status) {
        tempWidth -= 5;
        if (tempWidth < this->height() / 2) {
            tempWidth = this->height() / 2;
            status = 1;
        }
    }
    else if (1 == status) {
        value += 1.0;
        if (value >= 360) {
            value = 360.0;
            status = 2;
        }
    }
    else if (2 == status) {
        tempWidth += 5;
        if (tempWidth > this->width()) {
            tempWidth = this->width();
            timer->stop();
        }
    }

    this->update();
}