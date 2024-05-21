#include "SwitchControl.h"

#include <QPainter>
#include <QMouseEvent>

SwitchControl::SwitchControl(QWidget* parent)
    : QWidget(parent),
    m_bChecked(false),
    m_background(Qt::black),
    m_checkedColor(QColor(0, 150, 136)),
    m_disabledColor(QColor(190, 190, 190)),
    m_thumbColor(Qt::white),
    m_radius(16.0),
    m_nHeight(16),
    m_nMargin(0)
{
    // 鼠标滑过光标形状 - 手型
    setCursor(Qt::PointingHandCursor);
    setFixedSize(m_nHeight * 3, m_nHeight);


    // 连接信号槽
   connect(&m_timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
}


// 绘制开关
void SwitchControl::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setRenderHint(QPainter::Antialiasing);


    QPainterPath path;
    QColor background;
    QColor thumbColor;
    qreal dOpacity;
    QString stateStr;
    QRectF rect;
    QPen pen(QBrush(QColor(255, 255, 255)), 1);
    QFont font("黑体", 10, QFont::Normal);

    if (isEnabled()) { // 可用状态


        if (m_bChecked) { // 打开状态
            background = m_checkedColor;
            thumbColor = m_checkedColor;
            dOpacity = 0.600;
            stateStr = QString("闭合");
            QFontMetrics fmt(font);
            int textWidth = fmt.horizontalAdvance(stateStr);
            int textHeight = fmt.height();
            rect = QRectF(height() * 0.3, height() * 0.1, textWidth, textHeight);


        }
        else { //关闭状态
            background = m_background;
            thumbColor = m_thumbColor;
            dOpacity = 0.800;
            stateStr = QString("断开");
            QFontMetrics fmt(font);
            int textWidth = fmt.horizontalAdvance(stateStr);
            int textHeight = fmt.height();
            rect = QRectF(height() * 1.3, height() * 0.1, textWidth, textHeight);


        }
    }
    else {  // 不可用状态
        background = m_background;
        dOpacity = 0.260;
        thumbColor = m_disabledColor;
    }
    // 绘制大椭圆
    painter.setBrush(background);
    painter.setOpacity(dOpacity);
    path.addRoundedRect(QRectF(m_nMargin, m_nMargin, width() - 2 * m_nMargin, height() - 2 * m_nMargin), m_radius, m_radius);
    painter.drawPath(path.simplified());
    qDebug("x:%d, y:%d, w:%d, h:%d\n", m_nMargin, m_nMargin, width() - 2 * m_nMargin, height() - 2 * m_nMargin);


    // 绘制小椭圆
    painter.setBrush(thumbColor);
    painter.setOpacity(1.0);
    painter.drawEllipse(QRectF(m_nX - (m_nHeight / 2), m_nY - (m_nHeight / 2), height(), height()));


    painter.setPen(pen);
    painter.setFont(font);
    painter.drawText(rect, Qt::AlignCenter, stateStr);
}


// 鼠标按下事件
void SwitchControl::mousePressEvent(QMouseEvent* event)
{
    if (isEnabled()) {
        if (event->buttons() & Qt::LeftButton) {
            event->accept();
        }
        else {
            event->ignore();
        }
    }
}


// 鼠标释放事件 - 切换开关状态、发射toggled()信号
void SwitchControl::mouseReleaseEvent(QMouseEvent* event)
{
    return;
    if (isEnabled()) {
        if ((event->type() == QMouseEvent::MouseButtonRelease) && (event->button() == Qt::LeftButton)) {
            event->accept();
            m_bChecked = !m_bChecked;
            emit toggled(m_bChecked);
            m_timer.start(3);
        }
        else {
            event->ignore();
        }
    }
}


// 大小改变事件
void SwitchControl::resizeEvent(QResizeEvent* event)
{
    m_nX = m_nHeight / 2;
    m_nY = m_nHeight / 2;
    QWidget::resizeEvent(event);
}




// 切换状态 - 滑动
void SwitchControl::onTimeout()
{
    if (m_bChecked) {
        m_nX += 1;
        if (m_nX >= width() - m_nHeight / 2)
            m_timer.stop();
    }
    else {
        m_nX -= 1;
        if (m_nX <= m_nHeight / 2)
            m_timer.stop();
    }
    update();
}


// 返回开关状态 - 打开：true 关闭：false
bool SwitchControl::isToggled() const
{
    return m_bChecked;
}


// 设置开关状态
void SwitchControl::setToggle(bool checked)
{
    m_bChecked = checked;
    if (checked!= isToggled())
    m_timer.start(10);
}


// 设置背景颜色
void SwitchControl::setBackgroundColor(QColor color)
{
    m_background = color;
}


// 设置选中颜色
void SwitchControl::setCheckedColor(QColor color)
{
    m_checkedColor = color;
}


// 设置不可用颜色
void SwitchControl::setDisbaledColor(QColor color)
{
    m_disabledColor = color;
}
