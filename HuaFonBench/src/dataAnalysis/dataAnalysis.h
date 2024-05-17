#pragma once


#include "ui_dataAnalysis.h"


#include <QLineSeries>
#include <QWidget>
#include <QChart>
#include <QDateTimeAxis>
#include <QSplineSeries>
#include <qvalueaxis.h>
#include <QtCharts/QChartGlobal>
#include <src/public/ChartView.h>
#include <src/public/callout.h>
#include <QTimer>
#include <QDateTimeAxis>
#include <QLineSeries>
#include <QSplineSeries>
#include <QSqlQuery>
#include <QTableWidget>
#include <qvalueaxis.h>
#include <qsql.h>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlError>
#include <QTimer>

#include <QMessageBox>


QT_BEGIN_NAMESPACE
class QComboBox;
class QCheckBox;
class Ui_ThemeWidgetForm;
QT_END_NAMESPACE

QT_CHARTS_BEGIN_NAMESPACE
class QChartView;
class QChart;
QT_CHARTS_END_NAMESPACE


class dataAnalysis : public QWidget
{
	Q_OBJECT

   //定义一个结构体
    typedef struct func
    {
        QVariant Time;
        QVariant Val;
    }mapping_func;

#define  AXIS_MAX_Y      5000
#define  AXIS_MIN_Y      -0
#define  AXIS_MAX_X     POINT_NUMBER
#define  AXIS_STEP_Y     (1)
#define CHANNEL_NUMBER          (2)
#define POINT_NUMBER            (100)
public:
	dataAnalysis(QWidget *parent = nullptr);
	~dataAnalysis();
private:
	void  InitChart();
    void  InitUi();
    void  LoadBmuDB();
    void  StartAnalysis();
    void  RealtimeDataSlot(int16_t  chlData);
private:
    QStringList FileDataList;
    //  QSplineSeries m_series[CHANNEL_NUMBER];     //创建平滑曲线 CH1
    QLineSeries m_series[CHANNEL_NUMBER];
    QPen spline[CHANNEL_NUMBER];                //折线
    QValueAxis X_axis;                          //QChart X坐标
    QValueAxis Y_axis;                          //QChart Y坐标
    QChart* m_chart;
    ChartView* m_chartView;
    QList<QPointF> pointlist;
    Callout* tip;
private:
    QString BMU_TableName = "Temputure";
    QString BMU_ID = "0";
    QString BMU_Item = "T1";
    QList<QVariant> Val;
    QList<mapping_func> list;
    QTimer* timer;

    uint16_t IntervalTime =1000;
    uint16_t PlaySpeed = 1;
private slots:
    void on_StartPb_clicked();
    void on_FastPb_clicked();
    void on_SlowPb_clicked();
    void updateValue();
private:
	Ui::dataAnalysisClass ui;
};
