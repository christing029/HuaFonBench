#include "thermometredlg.h"
#include <QDebug>

/*********************************************************************
*     function:thermometreDlg
*  Description:构造函数
*        Input:
*       Output:
*       Return:true
*       Others:
*       Auther:lcc
*  Create Time:2022-08-18
*---------------------------------------------------------------------
*  Modify
*  Version       Author        Date            Modification
*  V0.00         lcc           2022-08-18      构造函数
*
**********************************************************************/
thermometreDlg::thermometreDlg(QWidget* parent) : QWidget(parent)
{
    m_bgColor = QColor(54, 54, 54);
    m_barBgColor = Qt::white;
    m_lineColor = Qt::white;
    m_barColor = Qt::red;
    m_fontColor = Qt::white;
    m_space = 20;
    m_radius = 40;
    m_longStep = 20;
    m_shortStep = 2;

    m_minValue = 0;
    m_maxValue = 100;
    m_barWidth = 10;
   // test 
    set_nowValue(50);
    set_barWidth(40);
    this->setMinimumSize(5, 200);
    update();
}

/*********************************************************************
*     function:paintEvent
*  Description:重绘
*        Input:
*       Output:
*       Return:true
*       Others:
*       Auther:lcc
*  Create Time:2022-08-18
*---------------------------------------------------------------------
*  Modify
*  Version       Author        Date            Modification
*  V0.00         lcc           2022-08-18      重绘
*
**********************************************************************/
void thermometreDlg::paintEvent(QPaintEvent* e)
{
    //超界的数强制等于临界值
    this->Fun_changeValue(m_nowValue);

    //绘制准备工作,启用反锯齿
    QPainter painter(this);


    //painter.translate(this->width()/2, this->height()/2);  //坐标轴移动到中心点
    painter.setRenderHints(QPainter::TextAntialiasing | QPainter::Antialiasing);  // 启用反锯齿



    //绘制背景
    this->Fun_Draw_Blackground(&painter);

    //绘制水银柱
    this->Fun_Draw_shuiyingzhu(&painter);

    //绘制标尺及刻度尺
    this->Fun_Draw_Ruler(&painter);

    //绘制当前水银柱,包含水银柱底部圆
    this->Fun_Draw_Now_shuiyingzhu(&painter);

    //绘制当前温度计值
    this->Fun_Draw_Value(&painter);


    QWidget::paintEvent(e);
}

/*********************************************************************
*     function:Fun_Draw_Blackground
*  Description:绘制背景
*        Input:
*       Output:
*       Return:true
*       Others:
*       Auther:lcc
*  Create Time:2022-08-18
*---------------------------------------------------------------------
*  Modify
*  Version       Author        Date            Modification
*  V0.00         lcc           2022-08-18      绘制背景
*
**********************************************************************/
bool thermometreDlg::Fun_Draw_Blackground(QPainter* painter)
{
    //保存当前Painter状态
    painter->save();

    painter->setPen(Qt::NoPen);

    painter->setBrush(m_bgColor);
    //绘制矩形
    painter->drawRect(rect());

    //恢复上面保存的状态
    painter->restore();

    return true;
}

/*********************************************************************
*     function:Fun_Draw_shuiyingzhu
*  Description:绘制水银柱
*        Input:
*       Output:
*       Return:true
*       Others:
*       Auther:lcc
*  Create Time:2022-08-18
*---------------------------------------------------------------------
*  Modify
*  Version       Author        Date            Modification
*  V0.00         lcc           2022-08-18      绘制水银柱
*
**********************************************************************/
bool thermometreDlg::Fun_Draw_shuiyingzhu(QPainter* painter)
{

    //保存当前Painter状态
    painter->save();

    painter->setPen(Qt::NoPen);
    painter->setBrush(m_barBgColor);

    painter->translate(this->width() / 2, 0);  //坐标轴移动

    //圆心距离矩形的距离
    double radius_rect_len = sqrt((double)((m_radius * m_radius) - ((m_barWidth / 2) * (m_barWidth / 2))));

    m_barHeight = this->height() - 2 * m_space - m_radius - radius_rect_len;

    QRectF barRect(-(m_barWidth / 2), m_space, m_barWidth, m_barHeight);

    painter->drawRect(barRect);

    painter->drawEllipse(QPoint(0, m_barHeight + radius_rect_len), m_radius, m_radius);


    //恢复上面保存的状态
    painter->restore();
    return true;
}

/*********************************************************************
*     function:Fun_Draw_Ruler
*  Description:绘制标尺及刻度尺
*        Input:
*       Output:
*       Return:true
*       Others:
*       Auther:lcc
*  Create Time:2022-08-18
*---------------------------------------------------------------------
*  Modify
*  Version       Author        Date            Modification
*  V0.00         lcc           2022-08-18      绘制标尺及刻度尺
*
**********************************************************************/
bool thermometreDlg::Fun_Draw_Ruler(QPainter* painter)
{
    //保存当前Painter状态
    painter->save();

    painter->setPen(QPen(m_lineColor, 2));

    //长线条短线条长度
    int longLineLen = 10;
    int shortLineLen = 7;

    //刻度线距水银柱偏移量
    int offset = 10;

    //Y值：移动1格
    double Y_offset = (double)(m_barHeight - offset - m_space) / (m_maxValue - m_minValue);


    painter->translate(this->width() / 2, 0);  //坐标轴

    //左刻度线
    painter->drawLine(-(m_barWidth / 2) - offset, m_space, -(m_barWidth / 2) - offset, m_barHeight - offset);
    //右刻度线
    painter->drawLine((m_barWidth / 2) + offset, m_space, (m_barWidth / 2) + offset, m_barHeight - offset);

    //标尺线
    for (int i = m_maxValue; i >= m_minValue; i = i - m_shortStep)
    {
        //长标尺线
        if (i % m_longStep == 0 || (-i) % m_longStep == 0)
        {
            //左长标尺线
            QPointF L_leftPot(-(m_barWidth / 2) - offset - longLineLen, m_space + Y_offset * (i - m_minValue));
            QPointF L_rightPot(-(m_barWidth / 2) - offset, m_space + Y_offset * (i - m_minValue));
            painter->drawLine(L_leftPot, L_rightPot);
            //右长标尺线
            QPointF R_leftPot((m_barWidth / 2) + offset, m_space + Y_offset * (i - m_minValue));
            QPointF R_rightPot((m_barWidth / 2) + offset + longLineLen, m_space + Y_offset * (i - m_minValue));
            painter->drawLine(R_leftPot, R_rightPot);

            //绘制左边文字
            QString L_strValue = QString("%1").arg((double)(-(i - m_maxValue - m_minValue)));
            QRect L_textRect(-(m_barWidth / 2) - offset - longLineLen - 30, m_space + Y_offset * (i - m_minValue) - 8, 25, 16);
            painter->setFont(QFont("Microsoft YaHei", 10));
            painter->drawText(L_textRect, Qt::AlignRight, L_strValue);

            //绘制右边文字
            QString R_strValue = QString("%1").arg((double)(-(i - m_maxValue - m_minValue)));
            QRect R_textRect((m_barWidth / 2) + offset + longLineLen + 5, m_space + Y_offset * (i - m_minValue) - 8, 25, 16);
            painter->setFont(QFont("Microsoft YaHei", 10));
            painter->drawText(R_textRect, Qt::AlignLeft, R_strValue);

        }
        //短标尺线
        else
        {
            //左短标尺线
            QPointF L_leftPot(-(m_barWidth / 2) - offset - shortLineLen, m_space + Y_offset * (i - m_minValue));
            QPointF L_rightPot(-(m_barWidth / 2) - offset, m_space + Y_offset * (i - m_minValue));
            painter->drawLine(L_leftPot, L_rightPot);
            //右短标尺线
            QPointF R_leftPot((m_barWidth / 2) + offset, m_space + Y_offset * (i - m_minValue));
            QPointF R_rightPot((m_barWidth / 2) + offset + shortLineLen, m_space + Y_offset * (i - m_minValue));
            painter->drawLine(R_leftPot, R_rightPot);

        }

    }


    //恢复上面保存的状态
    painter->restore();

    return true;
}

/*********************************************************************
*     function:Fun_Draw_Now_shuiyingzhu
*  Description:绘制当前水银柱,包含水银柱底部圆
*        Input:
*       Output:
*       Return:true
*       Others:
*       Auther:lcc
*  Create Time:2022-08-18
*---------------------------------------------------------------------
*  Modify
*  Version       Author        Date            Modification
*  V0.00         lcc           2022-08-18      绘制当前水银柱,包含水银柱底部圆
*
**********************************************************************/
bool thermometreDlg::Fun_Draw_Now_shuiyingzhu(QPainter* painter)
{
    //保存当前Painter状态
    painter->save();

    painter->setPen(Qt::NoPen);
    painter->setBrush(m_barColor);

    painter->translate(this->width() / 2, 0);  //坐标轴移动

    //当前水银柱距矩形框距离
    int bar_offset = 4;
    //圆心距离矩形的距离
    double radius_rect_len = sqrt((double)((m_radius * m_radius) - ((m_barWidth / 2) * (m_barWidth / 2))));

    m_barHeight = this->height() - 2 * m_space - m_radius - radius_rect_len;

    painter->drawEllipse(QPoint(0, m_barHeight + radius_rect_len), m_radius - bar_offset, m_radius - bar_offset);


    //Y值：移动1格 （偏移10，好看）
    double Y_offset = (double)(m_barHeight - 10 - m_space) / (m_maxValue - m_minValue);



    QRectF barRect(-(m_barWidth / 2) + bar_offset, m_space + Y_offset * (-m_nowValue + m_maxValue), m_barWidth - 2 * bar_offset, m_barHeight - Y_offset * (-m_nowValue + m_maxValue));

    painter->drawRect(barRect);


    //恢复上面保存的状态
    painter->restore();

    return true;
}


/*********************************************************************
*     function:Fun_Draw_Value
*  Description:绘制当前温度计值
*        Input:
*       Output:
*       Return:true
*       Others:
*       Auther:lcc
*  Create Time:2022-08-18
*---------------------------------------------------------------------
*  Modify
*  Version       Author        Date            Modification
*  V0.00         lcc           2022-08-18      绘制当前温度计值
*
**********************************************************************/
bool thermometreDlg::Fun_Draw_Value(QPainter* painter)
{
    //保存当前Painter状态
    painter->save();
    painter->setPen(QPen(m_fontColor, 2));


    painter->translate(this->width() / 2 - 2 * m_space, this->height() - 2 * m_space - 2 * m_radius);  //坐标轴移动


    QRect textRect(0, 0, m_radius * 2, m_radius * 2);
    painter->setFont(QFont("Microsoft YaHei", 15));
    painter->drawText(textRect, Qt::AlignCenter, QString::number(m_nowValue));




    //恢复上面保存的状态
    painter->restore();

    return true;
}

/*********************************************************************
*     function:Fun_changeValue
*  Description:超界的数强制等于临界值
*        Input:p_value
*       Output:
*       Return:true
*       Others:
*       Auther:lcc
*  Create Time:2022-08-18
*---------------------------------------------------------------------
*  Modify
*  Version       Author        Date            Modification
*  V0.00         lcc           2022-08-18      超界的数强制等于临界值
*
**********************************************************************/
bool thermometreDlg::Fun_changeValue(int p_value)
{
    if (p_value > m_maxValue)
    {
        p_value = m_maxValue;
    }
    if (p_value < m_minValue)
    {
        p_value = m_minValue;
    }
    m_nowValue = p_value;

    return true;
}

/*********************************************************************
*     function:get_bgColor
*  Description:获取背景颜色
*        Input:
*       Output:
*       Return:QColor
*       Others:
*       Auther:lcc
*  Create Time:2022-08-18
*---------------------------------------------------------------------
*  Modify
*  Version       Author        Date            Modification
*  V0.00         lcc           2022-08-18      获取背景颜色
*
**********************************************************************/
QColor thermometreDlg::get_bgColor()
{
    return m_bgColor;
}

/*********************************************************************
*     function:set_bgColor
*  Description:设置背景颜色
*        Input:bgColor
*       Output:
*       Return:true
*       Others:
*       Auther:lcc
*  Create Time:2022-08-18
*---------------------------------------------------------------------
*  Modify
*  Version       Author        Date            Modification
*  V0.00         lcc           2022-08-18      设置背景颜色
*
**********************************************************************/
void thermometreDlg::set_bgColor(QColor& p_bgColor)
{
    m_bgColor = p_bgColor;
}
/*********************************************************************
*     function:get_barBgColor
*  Description:获取水银柱背景颜色
*        Input:
*       Output:m_barBgColor
*       Return:true
*       Others:
*       Auther:lcc
*  Create Time:2022-08-18
*---------------------------------------------------------------------
*  Modify
*  Version       Author        Date            Modification
*  V0.00         lcc           2022-08-18      获取水银柱背景颜色
*
**********************************************************************/
QColor thermometreDlg::get_barBgColor()
{
    return m_barBgColor;
}
/*********************************************************************
*     function:set_barBgColor
*  Description:设置水银柱背景颜色
*        Input:p_barBgColor
*       Output:
*       Return:true
*       Others:
*       Auther:lcc
*  Create Time:2022-08-18
*---------------------------------------------------------------------
*  Modify
*  Version       Author        Date            Modification
*  V0.00         lcc           2022-08-18      设置水银柱背景颜色
*
**********************************************************************/
void thermometreDlg::set_barBgColor(QColor& p_barBgColor)
{
    m_barBgColor = p_barBgColor;
}
/*********************************************************************
*     function:set_barBgColor
*  Description:获取水银柱宽度
*        Input:
*       Output:m_barWidth
*       Return:true
*       Others:
*       Auther:lcc
*  Create Time:2022-08-18
*---------------------------------------------------------------------
*  Modify
*  Version       Author        Date            Modification
*  V0.00         lcc           2022-08-18      获取水银柱宽度
*
**********************************************************************/
int thermometreDlg::get_barWidth()
{
    return m_barWidth;
}
/*********************************************************************
*     function:set_barBgColor
*  Description:设置水银柱宽度
*        Input:p_barWidth
*       Output:
*       Return:true
*       Others:
*       Auther:lcc
*  Create Time:2022-08-18
*---------------------------------------------------------------------
*  Modify
*  Version       Author        Date            Modification
*  V0.00         lcc           2022-08-18      设置水银柱宽度
*
**********************************************************************/
void thermometreDlg::set_barWidth(int p_barWidth)
{
    m_barWidth = p_barWidth;
}
/*********************************************************************
*     function:get_nowValue
*  Description:获取当前温度计值
*        Input:
*       Output:m_nowValue
*       Return:true
*       Others:
*       Auther:lcc
*  Create Time:2022-08-18
*---------------------------------------------------------------------
*  Modify
*  Version       Author        Date            Modification
*  V0.00         lcc           2022-08-18      获取当前温度计值
*
**********************************************************************/
int thermometreDlg::get_nowValue()
{
    return m_nowValue;
}
/*********************************************************************
*     function:set_nowValue
*  Description:设置当前温度计值
*        Input:p_nowValue
*       Output:
*       Return:true
*       Others:
*       Auther:lcc
*  Create Time:2022-08-18
*---------------------------------------------------------------------
*  Modify
*  Version       Author        Date            Modification
*  V0.00         lcc           2022-08-18      设置当前温度计值
*
**********************************************************************/
void thermometreDlg::set_nowValue(int p_nowValue)
{
    m_nowValue = p_nowValue;
}
/*********************************************************************
*     function:get_maxValue
*  Description:获取最大温度计值
*        Input:
*       Output:m_maxValue
*       Return:true
*       Others:
*       Auther:lcc
*  Create Time:2022-08-18
*---------------------------------------------------------------------
*  Modify
*  Version       Author        Date            Modification
*  V0.00         lcc           2022-08-18      获取最大温度计值
*
**********************************************************************/
int thermometreDlg::get_maxValue()
{
    return m_maxValue;
}
/*********************************************************************
*     function:set_maxValue
*  Description:设置最大温度计值
*        Input:p_maxValue
*       Output:
*       Return:true
*       Others:
*       Auther:lcc
*  Create Time:2022-08-18
*---------------------------------------------------------------------
*  Modify
*  Version       Author        Date            Modification
*  V0.00         lcc           2022-08-18      设置最大温度计值
*
**********************************************************************/
void thermometreDlg::set_maxValue(int p_maxValue)
{
    m_maxValue = p_maxValue;
}
/*********************************************************************
*     function:get_minValue
*  Description:获取最小温度计值
*        Input:
*       Output:m_minValue
*       Return:true
*       Others:
*       Auther:lcc
*  Create Time:2022-08-18
*---------------------------------------------------------------------
*  Modify
*  Version       Author        Date            Modification
*  V0.00         lcc           2022-08-18      获取最小温度计值
*
**********************************************************************/
int thermometreDlg::get_minValue()
{
    return m_minValue;
}
/*********************************************************************
*     function:set_minValue
*  Description:设置最小温度计值
*        Input:p_minValue
*       Output:
*       Return:true
*       Others:
*       Auther:lcc
*  Create Time:2022-08-18
*---------------------------------------------------------------------
*  Modify
*  Version       Author        Date            Modification
*  V0.00         lcc           2022-08-18      设置最小温度计值
*
**********************************************************************/
void thermometreDlg::set_minValue(int p_minValue)
{
    m_minValue = p_minValue;
}