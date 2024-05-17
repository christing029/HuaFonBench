#include <QWidget>
#include <QPropertyAnimation>
#include <QPainter>
#include <QTimer>
#include <qt_windows.h>

class thermometreDlg : public QWidget
{
    Q_OBJECT
        //声明属性
        Q_PROPERTY(QColor m_bgColor READ get_bgColor WRITE set_bgColor)

        Q_PROPERTY(QColor m_barBgColor READ get_barBgColor WRITE set_barBgColor)

        Q_PROPERTY(int m_barWidth READ get_barWidth WRITE set_barWidth)

        Q_PROPERTY(int m_nowValue READ get_nowValue WRITE set_nowValue)

        Q_PROPERTY(int m_maxValue READ get_maxValue WRITE set_maxValue)

        Q_PROPERTY(int m_minValue READ get_minValue WRITE set_minValue)



protected:
    void paintEvent(QPaintEvent* e);

public:
    explicit thermometreDlg(QWidget* parent = nullptr);

    //绘制背景
    bool Fun_Draw_Blackground(QPainter* painter);

    //绘制水印柱以及底部圆形
    bool Fun_Draw_shuiyingzhu(QPainter* painter);

    //绘制标尺及刻度尺
    bool Fun_Draw_Ruler(QPainter* painter);

    //绘制当前水银柱,包含水银柱底部圆
    bool Fun_Draw_Now_shuiyingzhu(QPainter* painter);

    //绘制当前温度计值
    bool Fun_Draw_Value(QPainter* painter);

    //超界的数强制等于临界值
    bool Fun_changeValue(int p_value);

public slots:



public:

    //水银柱宽度
    int m_barWidth;
    //水银柱高度
    int m_barHeight;
    //水银柱上下到边框的距离
    int m_space;
    //水银柱底圆形半径
    int m_radius;
    //刻度最大值
    int m_maxValue;
    //刻度最小值
    int m_minValue;
    //短线标
    int m_shortStep;
    //长线标
    int m_longStep;
    //当前温度值
    int m_nowValue;



    //背景颜色
    QColor m_bgColor;
    //水银柱背景色
    QColor m_barBgColor;
    //刻度线颜色
    QColor m_lineColor;
    //当前水银柱颜色
    QColor m_barColor;
    //当前水银柱球中的字体颜色
    QColor m_fontColor;

public:

    QColor get_bgColor();
    void set_bgColor(QColor& p_bgColor);

    QColor get_barBgColor();
    void set_barBgColor(QColor& p_barBgColor);

    int get_barWidth();
    void set_barWidth(int p_barWidth);

    int get_nowValue();
    void set_nowValue(int p_nowValue);

    int get_maxValue();
    void set_maxValue(int p_maxValue);

    int get_minValue();
    void set_minValue(int p_minValue);
};
