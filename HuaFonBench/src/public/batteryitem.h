#ifndef BATTERYITEM_H
#define BATTERYITEM_H
#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QPropertyAnimation>
#include "qpainter.h"
#include "qtimer.h"
#include "qdebug.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <src/public/ToolTip/CuteToolTip.h>
/**
 * 电池电量控件 
 * 1:可设置电池电量,动态切换电池电量变化
 * 2:可设置电池电量警戒值
 * 3:可设置电池电量正常颜色和报警颜色
 * 4:可设置边框渐变颜色
 * 5:可设置电量变化时每次移动的步长
 * 6:可设置边框圆角角度/背景进度圆角角度/头部圆角角度
 */

namespace Ui {
class BatteryItem;
}

class BatteryItem : public QWidget
{
    Q_OBJECT
    enum _EBatteryStyle
    {
        ClassASlaveStyle = 0,
        ClassBMasterStyle,//节点的展示模式
        ClassCMasterStyle,//节点的数据来源
    };
    enum _EAnimationStyle
    {
        AnimationNo = 0,//节点的数据来源
        AnimationCharge ,
        AnimationDisCharge,//节点的展示模式
        AnimationAlarm,//节点的数据来源

    };
        Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
        Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
        Q_PROPERTY(double value READ getValue WRITE setValue)
        Q_PROPERTY(double alarmValue READ getAlarmValue WRITE setAlarmValue)

        Q_PROPERTY(double step READ getStep WRITE setStep)
        Q_PROPERTY(int borderRadius READ getBorderRadius WRITE setBorderRadius)
        Q_PROPERTY(int bgRadius READ getBgRadius WRITE setBgRadius)
        Q_PROPERTY(int headRadius READ getHeadRadius WRITE setHeadRadius)

        Q_PROPERTY(QColor borderColorStart READ getBorderColorStart WRITE setBorderColorStart)
        Q_PROPERTY(QColor borderColorEnd READ getBorderColorEnd WRITE setBorderColorEnd)

        Q_PROPERTY(QColor alarmColorStart READ getAlarmColorStart WRITE setAlarmColorStart)
        Q_PROPERTY(QColor alarmColorEnd READ getAlarmColorEnd WRITE setAlarmColorEnd)

        Q_PROPERTY(QColor normalColorStart READ getNormalColorStart WRITE setNormalColorStart)
        Q_PROPERTY(QColor normalColorEnd READ getNormalColorEnd WRITE setNormalColorEnd)
public:
    explicit BatteryItem(QWidget *parent = nullptr);
    ~BatteryItem();
private:
    Ui::BatteryItem *ui;
#if 0
public:
    void setCurPower(int powerVal); // 设置当前电量
    int getCurPower() const;
    void setWarnPower(int warnVal); // 设置低电量警示值
    int getWarnPower() const;
    void setBatteryStyle(_EBatteryStyle style); // 设置低电量警示值
    void actionChargeStart();
    void actionDisChargeStart();
protected:
    virtual void paintEvent(QPaintEvent * event) override;

signals:
    void sendCurPowerChange(int pow);
private:
    QColor bgColor = Qt::white; // 背景颜色
    QColor borderColor = Qt::black; // 电池边框颜色
    QColor colPowerColor = Qt::green;   // 电池柱颜色
    QColor lowPowerColor = Qt::red; // 低电量颜色
    int curPowerLevel;
    int warnPowerLevel;

#endif
protected:
    void paintEvent(QPaintEvent*);
    void drawBorder(QPainter* painter);
    void drawBg(QPainter* painter);
    void drawHead(QPainter* painter);
    void drawText(QPainter* painter);
private slots:
    void updateValue();
    void ChargeAnimation();
private:
    double minValue;                //最小值
    double maxValue;                //最大值
    double value;                   //目标电量
    double alarmValue;              //电池电量警戒值

    double step;                    //每次移动的步长
    int borderRadius;               //边框圆角角度
    int bgRadius;                   //背景进度圆角角度
    int headRadius;                 //头部圆角角度

    QColor borderColorStart;        //边框渐变开始颜色
    QColor borderColorEnd;          //边框渐变结束颜色

    QColor alarmColorStart;         //电池低电量时的渐变开始颜色
    QColor alarmColorEnd;           //电池低电量时的渐变结束颜色

    QColor normalColorStart;        //电池正常电量时的渐变开始颜色
    QColor normalColorEnd;          //电池正常电量时的渐变结束颜色

    bool isForward;                 //是否往前移
    double currentValue;            //当前电量
    QRectF batteryRect;             //电池主体区域
    QTimer* timer;                  //绘制定时器
    QTimer* Annaiotimer;            //动画绘制定时器
    CuteToolTip* tip_b;
    QString tipMessage="";
    _EAnimationStyle BatterStatys = AnimationAlarm;
public:
    double getMinValue()            const;
    double getMaxValue()            const;
    double getValue()               const;
    double getAlarmValue()          const;

    double getStep()                const;
    int getBorderRadius()           const;
    int getBgRadius()               const;
    int getHeadRadius()             const;

    QColor getBorderColorStart()    const;
    QColor getBorderColorEnd()      const;

    QColor getAlarmColorStart()     const;
    QColor getAlarmColorEnd()       const;

    QColor getNormalColorStart()    const;
    QColor getNormalColorEnd()      const;

    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;
    void SetTip(QString TipMessage) { tipMessage = TipMessage; }
    void SetBatteryStatus(uint16_t status) { BatterStatys = (_EAnimationStyle)status; }
    public Q_SLOTS:
        //设置范围值
        void setRange(double minValue, double maxValue);
        void setRange(int minValue, int maxValue);

        //设置最大最小值
        void setMinValue(double minValue);
        void setMaxValue(double maxValue);

        //设置电池电量值
        void setValue(double value);
        void setValue(int value);

        //设置电池电量警戒值
        void setAlarmValue(double alarmValue);
        void setAlarmValue(int alarmValue);

        //设置步长
        void setStep(double step);
        void setStep(int step);

        //设置边框圆角角度
        void setBorderRadius(int borderRadius);
        //设置背景圆角角度
        void setBgRadius(int bgRadius);
        //设置头部圆角角度
        void setHeadRadius(int headRadius);

        //设置边框渐变颜色
        void setBorderColorStart(const QColor& borderColorStart);
        void setBorderColorEnd(const QColor& borderColorEnd);

        //设置电池电量报警时的渐变颜色
        void setAlarmColorStart(const QColor& alarmColorStart);
        void setAlarmColorEnd(const QColor& alarmColorEnd);

        //设置电池电量正常时的渐变颜色
        void setNormalColorStart(const QColor& normalColorStart);
        void setNormalColorEnd(const QColor& normalColorEnd);

Q_SIGNALS:
    void valueChanged(double value);
    // 悬浮提升
    private:
        //QLabel* labelIcon;
        //QLabel* labelName;
        //QLabel* labelInfo;
        //QHBoxLayout* horLayout;
        //QVBoxLayout* verlayout;
       void doMouseTrackTip();
   protected:
       bool event(QEvent* e);
};
#endif // BATTERYITEM_H