#ifndef SLAVEITEMINFO_H
#define SLAVEITEMINFO_H

#include <QWidget>

#include <QLineSeries>
#include <QChart>
#include <QDateTimeAxis>
#include <QSplineSeries>
#include <qvalueaxis.h>
#include <QtCharts/QChartGlobal>
#include <src/public/ChartView.h>
#include <src/public/callout.h>
#include <QTimer>

#include <QSqlQuery>
#include <QTableWidget>
#include <qsql.h>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlError>

#include <QDebug>
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


namespace Ui {
class SlaveItemInfo;
}

class SlaveItemInfo : public QWidget
{
    Q_OBJECT
#define  AXIS_MAX_Y      50000000000
#define  AXIS_MIN_Y      -50000000000
#define  AXIS_MAX_X     POINT_NUMBER
#define  AXIS_STEP_Y     (1)
#define CHANNEL_NUMBER          (2)
#define POINT_NUMBER            (100)
public:
    explicit SlaveItemInfo(QWidget *parent = nullptr);
    ~SlaveItemInfo();
    virtual void mousePressEvent(QMouseEvent* event);

private:
    Ui::SlaveItemInfo *ui;
    void  InitUi();
    void  InitChart();
private:
    int m_listCount;
    qreal      yMin;
    qreal      yMax;
    FILE *f;
    QStringList FileDataList;
    //  QSplineSeries m_series[CHANNEL_NUMBER];     //创建平滑曲线 CH1
    QLineSeries m_series[CHANNEL_NUMBER];
    QPen spline[CHANNEL_NUMBER];                //折线
    QValueAxis X_axis;                          //QChart X坐标
    QValueAxis Y_axis;                          //QChart Y坐标
    QChart *m_chart;
    ChartView *m_chartView;
    QList<QPointF> pointlist;
    Callout *tip;
    QString chart_title;
    int count = 0;
    uint16_t VoltNum =12;
    uint16_t TempNum=4;
    uint16_t slaveItemID =0;

    uint16_t RealtimeDataType = 0;
    uint16_t  RealtimeDataId = 0;
    //测试菜单

    QMenu* m_pMenuRD;
    QAction* m_pMenuTest;

private:
    // BMU数据库操作
    void RealtimeDataSlot(int16_t chlData);
    void CreateMenu();

public:
    QString   m_channID;
    void     LableInfoShow(int Id, uint16_t voltNum, uint16_t tempNum);
    bool     isShowFlag = false;
    void LableInfoShow(int Id);
    void ShowVoltInfo(uint16_t *Volt);
    void ShowtTempInfo(int16_t *Temp);
    void ShowSatusInfo(uint8_t Blance[16],uint8_t CnnStatus[16]);
private slots:
    void showPointData(QPointF position, bool isHovering);
    void on_tableWidget_itemClicked(QTableWidgetItem* item);
private slots:
    void UpdateItemUi();
    void SlotMenuClicked(QAction*);

};

#endif // SLAVEITEMINFO_H
