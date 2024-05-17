#include "batteryitem.h"
#include "ui_batteryitem.h"

//#pragma execution_character_set("utf-8")
BatteryItem::BatteryItem(QWidget* parent) : QWidget(parent)
{
    minValue = 0;
    maxValue = 100;
    value = 0;
    alarmValue = 30;
    step = 0.5;

    borderRadius = 8;
    bgRadius = 5;
    headRadius = 3;
    borderColorStart = QColor(100, 100, 100);
    borderColorEnd = QColor(80, 80, 80);
    alarmColorStart = QColor(250, 118, 113);
    alarmColorEnd = QColor(204, 38, 38);
    normalColorStart = QColor(50, 205, 51);
    normalColorEnd = QColor(60, 179, 133);
    isForward = false;
    currentValue = 0;
    timer = new QTimer(this);
    timer->setInterval(10);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateValue()));
    // TEST
  //  setValue(qrand() % (0 - 100));
   // timer->stop();
    Annaiotimer = new QTimer(this);
    Annaiotimer->setInterval(50);
    Annaiotimer->start();
   // Annaiotimer->stop();
    connect(Annaiotimer, SIGNAL(timeout()), this, SLOT(ChargeAnimation()));


 //   setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setAttribute(Qt::WA_TranslucentBackground);
    setAutoFillBackground(true);
    setAttribute(Qt::WA_Hover, true);

    tip_b = new CuteToolTip("Tip B", this);
    tip_b->setObjectName("tipB");
    tip_b->anchorTarget(this);
    // 自适应的尺寸
    tip_b->setStyleSheet(R"(
    .CuteToolTip#tipB{
    qproperty-xOffset:"20";
    qproperty-yOffset:"3";
    }
    .CuteToolTip#tipB QLabel{
    padding:10px 30px;
    color:white;
    border:1px solid white;
    background-color:rgb(20,50,90);
    }
)");

    tip_b->setText("AAAAAAAAAAAAAAAAAAAA");
}

BatteryItem::~BatteryItem()
{
    if (timer->isActive()) {
        timer->stop();
    }
}

void BatteryItem::paintEvent(QPaintEvent*)
{
    //绘制准备工作,启用反锯齿
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    //painter.translate(width() / 2, height() / 2); // 将旋转中心移动到控件中心
    //painter.rotate(90); // 应用旋转变换
    //painter.translate(-width() / 2, -height() / 2);
    //绘制边框
    drawBorder(&painter);
    //绘制背景
    drawBg(&painter);
    //绘制头部
    drawHead(&painter);
    drawText(&painter);
}

void BatteryItem::drawBorder(QPainter* painter)
{
    painter->save();

    double headWidth = width() / 10;
    double batteryWidth = width() - headWidth;

    //绘制电池边框
    QPointF topLeft(5, 5);
    QPointF bottomRight(batteryWidth, height() - 5);
    batteryRect = QRectF(topLeft, bottomRight);

    painter->setPen(QPen(borderColorStart, 5));
    painter->setBrush(Qt::NoBrush);
    painter->drawRoundedRect(batteryRect, borderRadius, borderRadius);

    painter->restore();
}

void BatteryItem::drawBg(QPainter* painter)
{
    painter->save();

    QLinearGradient batteryGradient(QPointF(0, 0), QPointF(0, height()));
    if (currentValue <= alarmValue) {
        batteryGradient.setColorAt(0.0, alarmColorStart);
        batteryGradient.setColorAt(1.0, alarmColorEnd);
    }
    else {
        batteryGradient.setColorAt(0.0, normalColorStart);
        batteryGradient.setColorAt(1.0, normalColorEnd);
    }

    int margin = qMin(width(), height()) / 20;
    double unit = (batteryRect.width() - (margin * 2)) / 100;
    double width = currentValue * unit;
    QPointF topLeft(batteryRect.topLeft().x() + margin, batteryRect.topLeft().y() + margin);
    QPointF bottomRight(width + margin + 5, batteryRect.bottomRight().y() - margin);
    QRectF rect(topLeft, bottomRight);

    painter->setPen(Qt::NoPen);
    painter->setBrush(batteryGradient);
    painter->drawRoundedRect(rect, bgRadius, bgRadius);

    painter->restore();
}

void BatteryItem::drawHead(QPainter* painter)
{
    painter->save();

    QPointF headRectTopLeft(batteryRect.topRight().x(), height() / 3);
    QPointF headRectBottomRight(width(), height() - height() / 3);
    QRectF headRect(headRectTopLeft, headRectBottomRight);

    QLinearGradient headRectGradient(headRect.topLeft(), headRect.bottomLeft());
    headRectGradient.setColorAt(0.0, borderColorStart);
    headRectGradient.setColorAt(1.0, borderColorEnd);

    painter->setPen(Qt::NoPen);
    painter->setBrush(headRectGradient);
    painter->drawRoundedRect(headRect, headRadius, headRadius);

    painter->restore();
}

void BatteryItem::drawText(QPainter* painter)
{
    painter->save();
        // 绘制电量百分比文字
    QPen pen(borderColorStart, 100, Qt::SolidLine, Qt::FlatCap, Qt::BevelJoin);
    QFontMetrics textFont(this->font());
    QString powerStr = QString::asprintf("%.2f%%", getValue());
    QRect textRect = textFont.boundingRect(powerStr);
   // painter->setFont(this->font());
    painter->setFont((QFont("Microsoft YaHei", 15)));
    pen.setColor(borderColorStart);
    painter->setPen(pen);
    painter->drawText((148 - textRect.width()) / 2, (68 - textRect.height()), powerStr);
    painter->restore();

}

void BatteryItem::ChargeAnimation()
{
    //if (getValue()!= 0)
    //{
    //    setValue(0);
    //}
    //else
    //{
    //    setValue(100);;
    //}
    if (BatterStatys == AnimationNo)
    {
        //Annaiotimer->stop();
    }

    else if (BatterStatys == AnimationCharge)
    {
        if (currentValue > 50)
        {
            Annaiotimer->setInterval(40);
        }
        else
        {
            Annaiotimer->setInterval(20);
        }
        currentValue += step;
        if (currentValue >= 100) {
            currentValue = value;
        }
    }
    else if(BatterStatys == AnimationDisCharge)
    {
        currentValue -= step;
        if (currentValue <= 10) {
            currentValue = value;
        }
    }
    update();
}





void BatteryItem::updateValue()
{
    if (isForward) {
        currentValue -= step;

        if (currentValue <= value) {
            timer->stop();
        }
    }
    else {
        currentValue += step;

        if (currentValue >= value) {
            timer->stop();
        }
    }

    update();
}

double BatteryItem::getMinValue() const
{
    return this->minValue;
}

double BatteryItem::getMaxValue() const
{
    return this->maxValue;
}

double BatteryItem::getValue() const
{
    return this->value;
}

double BatteryItem::getAlarmValue() const
{
    return this->alarmValue;
}

double BatteryItem::getStep() const
{
    return this->step;
}

int BatteryItem::getBorderRadius() const
{
    return this->borderRadius;
}

int BatteryItem::getBgRadius() const
{
    return this->bgRadius;
}

int BatteryItem::getHeadRadius() const
{
    return this->headRadius;
}

QColor BatteryItem::getBorderColorStart() const
{
    return this->borderColorStart;
}

QColor BatteryItem::getBorderColorEnd() const
{
    return this->borderColorEnd;
}

QColor BatteryItem::getAlarmColorStart() const
{
    return this->alarmColorStart;
}

QColor BatteryItem::getAlarmColorEnd() const
{
    return this->alarmColorEnd;
}

QColor BatteryItem::getNormalColorStart() const
{
    return this->normalColorStart;
}

QColor BatteryItem::getNormalColorEnd() const
{
    return this->normalColorEnd;
}

QSize BatteryItem::sizeHint() const
{
    return QSize(150, 80);
}

QSize BatteryItem::minimumSizeHint() const
{
    return QSize(30, 10);
}

void BatteryItem::setRange(double minValue, double maxValue)
{
    //如果最小值大于或者等于最大值则不设置
    if (minValue >= maxValue) {
        return;
    }

    this->minValue = minValue;
    this->maxValue = maxValue;

    //如果目标值不在范围值内,则重新设置目标值
    if (value < minValue || value > maxValue) {
        setValue(value);
    }

    update();
}

void BatteryItem::setRange(int minValue, int maxValue)
{
    setRange((double)minValue, (double)maxValue);
}

void BatteryItem::setMinValue(double minValue)
{
    setRange(minValue, maxValue);
}

void BatteryItem::setMaxValue(double maxValue)
{
    setRange(minValue, maxValue);
}

void BatteryItem::setValue(double value)
{
    //值小于最小值或者值大于最大值或者值和当前值一致则无需处理
    if (value < minValue || value > maxValue || value == this->value) {
        return;
    }

    emit valueChanged(value);
    this->value = value;

    if (value > currentValue) {
        isForward = false;
    }
    else if (value < currentValue) {
        isForward = true;
    }
    else {
        return;
    }

    timer->start();
    update();
}

void BatteryItem::setValue(int value)
{
    setValue((double)value);
}

void BatteryItem::setAlarmValue(double alarmValue)
{
    if (this->alarmValue != alarmValue) {
        this->alarmValue = alarmValue;
        update();
    }
}

void BatteryItem::setAlarmValue(int alarmValue)
{
    setAlarmValue((double)alarmValue);
}

void BatteryItem::setStep(double step)
{
    if (this->step != step) {
        this->step = step;
        update();
    }
}

void BatteryItem::setStep(int step)
{
    setStep((double)step);
}

void BatteryItem::setBorderRadius(int borderRadius)
{
    if (this->borderRadius != borderRadius) {
        this->borderRadius = borderRadius;
        update();
    }
}

void BatteryItem::setBgRadius(int bgRadius)
{
    if (this->bgRadius != bgRadius) {
        this->bgRadius = bgRadius;
        update();
    }
}

void BatteryItem::setHeadRadius(int headRadius)
{
    if (this->headRadius != headRadius) {
        this->headRadius = headRadius;
        update();
    }
}

void BatteryItem::setBorderColorStart(const QColor& borderColorStart)
{
    if (this->borderColorStart != borderColorStart) {
        this->borderColorStart = borderColorStart;
        update();
    }
}

void BatteryItem::setBorderColorEnd(const QColor& borderColorEnd)
{
    if (this->borderColorEnd != borderColorEnd) {
        this->borderColorEnd = borderColorEnd;
        update();
    }
}

void BatteryItem::setAlarmColorStart(const QColor& alarmColorStart)
{
    if (this->alarmColorStart != alarmColorStart) {
        this->alarmColorStart = alarmColorStart;
        update();
    }
}

void BatteryItem::setAlarmColorEnd(const QColor& alarmColorEnd)
{
    if (this->alarmColorEnd != alarmColorEnd) {
        this->alarmColorEnd = alarmColorEnd;
        update();
    }
}

void BatteryItem::setNormalColorStart(const QColor& normalColorStart)
{
    if (this->normalColorStart != normalColorStart) {
        this->normalColorStart = normalColorStart;
        update();
    }
}

void BatteryItem::setNormalColorEnd(const QColor& normalColorEnd)
{
    if (this->normalColorEnd != normalColorEnd) {
        this->normalColorEnd = normalColorEnd;
        update();
    }
}

void BatteryItem::doMouseTrackTip()
{
}

bool BatteryItem::event(QEvent* e)
{
    if (e->type() == QEvent::HoverEnter || e->type() == QEvent::HoverLeave || e->type() == QEvent::HoverMove) 
    {
        //....一些操作
        setCursor(Qt::WhatsThisCursor);
       // tip_b->setText("从机1信息\n电压：59V\n温度：80°\n
        tip_b->setText(tipMessage);


    }
    return QWidget::event(e);
}







