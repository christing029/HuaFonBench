
#ifndef BCUCalibration_H
#define BCUCalibration_H

#include <QWidget>
#include "ui_BCUCalibration.h"
#include <QtCore/qmath.h>
#include <QLineSeries>
#include <QChart>
#include <QSplineSeries>
#include <QtCharts/QChartGlobal>
#include <src/public/ChartView.h>
#include <src/public/callout.h>
#include <src/drvmng/modbus_params.h>
#include <QValueAxis>
//#include <QDateTimeAxis>

//QT_CHARTS_BEGIN_NAMESPACE
//class QChartView;
//class QChart;
//QT_CHARTS_END_NAMESPACE


class BCUCalibration : public QWidget
{
    Q_OBJECT
#define  AXIS_MAX_Y      5000
#define  AXIS_MIN_Y      0
#define  AXIS_MAX_X     POINT_NUMBER
#define  AXIS_STEP_Y     (1)
#define CHANNEL_NUMBER          (2)
#define POINT_NUMBER            (10)
#define GET_OFFSET(_type, _member) ((unsigned long)(&((_type *)0)->_member))

public:
    BCUCalibration(QWidget* parent = nullptr);
    ~BCUCalibration();

private:
    int m_listCount;
    qreal      yMin;
    qreal      yMax;
    FILE* f;
    QStringList FileDataList;
    QLineSeries m_series[CHANNEL_NUMBER];
    QPen spline[CHANNEL_NUMBER];                //折线
    QValueAxis X_axis;                          //QChart X坐标
    QValueAxis Y_axis;                          //QChart Y坐标
    QChart* m_chart;
    ChartView* m_chartView;
    QList<QPointF> pointlist;
    Callout* tip;
    QString chart_title;
    SENSOR_CALIBRATION_s    mb_cal_t;
private:
    uint16_t BitMap_StartAddress = 0x1000;
    uint16_t BitMap_Val = 0;

    uint16_t WriteData_StartAddress = 0x1012;
    QVector<quint16> writeDataValue;
    void Float_to_Byte(float f);
    void Uint_to_Byte(uint32_t f);
private:
    void  InitChart();
    void  UpDateChart(float startPoint, float endPoint, float K, float B);
private slots:
    void on_bt_add_clicked();
    void on_bt_clear_clicked();
    void on_bt_read_all_clicked();
    void on_bt_write_clicked();
signals:
    void signalDownMsg(QString  str, uint address, QVector<quint16> val);
private:
    Ui::BCUCalibrationClass ui;
};
#endif