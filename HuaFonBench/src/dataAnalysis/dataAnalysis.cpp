#include "dataAnalysis.h"
#include <QTreeWidget>
#include <QtGui/qstandarditemmodel.h>


dataAnalysis::dataAnalysis(QWidget *parent)
	: QWidget(parent)
{
    QFile file(":/qss/HF.qss");
    if (!file.open(QIODevice::ReadOnly))
    {
        qWarning("Can't open the style sheet file.");
        return;
    }
    QString qss = QLatin1String(file.readAll());
    this->setStyleSheet(qss);
	ui.setupUi(this);
    InitUi();
    InitChart();
    LoadBmuDB();
}

dataAnalysis::~dataAnalysis()
{

}

void dataAnalysis::InitChart()
{
    // init chart
    spline[0].setColor(Qt::red);     //设置折线颜色
    spline[0].setWidth(2);           //设置折线宽度
    m_series[0].setPen(spline[0]);
    spline[1].setColor(Qt::blue);
    spline[1].setWidth(2);
    m_series[1].setPen(spline[1]);
    m_series[1].setPointLabelsVisible(false);
    m_series[0].setPointLabelsVisible(false);
    m_chart = new QChart();
    m_chart->setTheme(QChart::ChartThemeBlueCerulean); //设置系统主题
    m_chart->legend()->hide();                         //设置图例
    m_chart->setAnimationOptions(QChart::SeriesAnimations);// 设置曲线动画显示
    X_axis.setTitleText("采集时间");
    Y_axis.setTitleText("电池电压");
    for (int i = 0; i < CHANNEL_NUMBER; i++)
    {
        m_chart->addSeries(&m_series[i]);
        m_chart->setAxisX(&X_axis, &m_series[i]);
        m_chart->setAxisY(&Y_axis, &m_series[i]);

        for (int j = 0; j < POINT_NUMBER; j++)
        {
            //  m_series[i].append(j, 0);
        }
    }
    /// X轴参数设置
    X_axis.setRange(0, POINT_NUMBER);        //设置范围
    X_axis.setLabelFormat("%d");            //设置刻度的格式
    X_axis.setTickCount(20 + 1);              //设置X轴刻度线数目
    //X_axis.setTitleText("X");             //设置X轴的标题
    X_axis.setGridLineVisible(true);        //设置是否显示网格线
    X_axis.setLabelsVisible(true);          //设置刻度是否显示

    /// Y轴参数设置
    //   Y_axis.setRange(AXIS_MIN_Y,AXIS_MAX_Y);
    // Y_axis.setLabelFormat("%g");
    Y_axis.setLabelFormat("%.0f");
    Y_axis.setTickCount(15 + 1);             //设置Y轴刻度线数目
    Y_axis.setGridLineVisible(true);        //设置是否显示网格线
    Y_axis.setLabelsVisible(true);          //设置刻度是否显示
    Y_axis.setRange(AXIS_MIN_Y, AXIS_MAX_Y);
    m_chartView = new ChartView(m_chart);
   // ui.gridLayout->addWidget(m_chartView);             //将图表显示添加到layout控件
    m_chartView->setRenderHint(QPainter::Antialiasing);     //启动反走样 Antialiasing反混
    connect(&m_series[0], &QSplineSeries::pointAdded, [=](int index) {
        qreal y = m_series[0].at(index).y();
        if (y > Y_axis.max())
        {
            Y_axis.setMax(y + AXIS_STEP_Y);
        }
        if (y < Y_axis.min())
        {
            Y_axis.setMin(y - AXIS_STEP_Y);
        }
        }
    );
    connect(&m_series[0], SIGNAL(hovered(QPointF, bool)), this, SLOT(showPointData(QPointF, bool)));
    tip = new Callout(m_chart);
    tip->hide();
}

void dataAnalysis::InitUi()
{
    ui.FirstPage->setIcon(QIcon(":/icon/pause.ico"));
    ui.NextPage->setIcon(QIcon(":/icon/start.ico"));
    ui.PreviousPage->setIcon(QIcon(":/icon/startall.ico"));
    ui.LastPage->setIcon(QIcon(":/icon/startall.ico"));
    ui.StartPb->setIcon(QIcon(":/icon/start.ico"));
    ui.StopPb->setIcon(QIcon(":/icon/stopall.png"));
    ui.FastPb->setIcon(QIcon(":/icon/DoubleLast_32x32.png"));
    ui.SlowPb->setIcon(QIcon(":/icon/DoublePrev_32x32.png"));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateValue()));
    timer->stop();
    timer->setInterval(IntervalTime);

}

void dataAnalysis::updateValue()
{
    int rowCount = ui.tableWidget->rowCount();
    ui.tableWidget->insertRow(rowCount);
    ui.tableWidget->setItem(rowCount, 0, new QTableWidgetItem(list[rowCount].Time.toString()));
    ui.tableWidget->setItem(rowCount, 3, new QTableWidgetItem(list[rowCount].Val.toString()));
    RealtimeDataSlot(list[rowCount].Val.toInt());
    ui.tableWidget->setAutoScroll(true);
}
void dataAnalysis::on_Clear_clicked()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("bcudb.db");
    QString  sql = " delete from BCUInfoBase";
    QSqlQuery query;
    QString err_info;
    QString a;
    if (!mydb.open()) //如果数据库打开失败，会弹出一个警告窗口
    {
        QMessageBox::warning(this, "警告", "数据库打开失败");
    }
    else
    {
        //  qDebug()<<"时间测试数据库打开";
    }

    if (!query.exec(sql)) //执行插入操作
    {
        QString err_info = tr("数据库失败[%1]").arg(query.lastError().text());
    }
     sql = " delete from BCUAlarmInfo";
    if (!query.exec(sql)) //执行插入操作
    {
        QString err_info = tr("数据库失败[%1]").arg(query.lastError().text());
    }
    mydb.setDatabaseName("bmudb.db");
    if (!mydb.open()) //如果数据库打开失败，会弹出一个警告窗口
    {
        QMessageBox::warning(this, "警告", "数据库打开失败");
    }
    else
    {
        QMessageBox::warning(this, "警告", "删除BMU成功");
    }
    sql = " delete from Temputure";
    if (!query.exec(sql)) //执行插入操作
    {
        QString err_info = tr("数据库失败[%1]").arg(query.lastError().text());
    }
    sql = " delete from Volatage";

    if (!query.exec(sql)) //执行插入操作
    {
        QString err_info = tr("数据库失败[%1]").arg(query.lastError().text());
    }
    else
    {
        QMessageBox::warning(this, "警告", "删除BCU成功");
    }

}
void dataAnalysis::on_PbReadData_clicked()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    QString  sql = "";
    QSqlQuery query;
    QString err_info;
    QString a;
    QStringList  headlist;
    if (ui.comboBox_2->currentText().contains("温度数据"))
    {
        mydb.setDatabaseName("bmudb.db");
        mydb.open();
        sql = QString("SELECT * FROM Temputure WHERE ID= %1").arg(ui.comboBox->currentIndex());
    
        if (!query.exec(sql)) //执行插入操作
        {
            QString err_info = tr("数据库失败[%1]").arg(query.lastError().text());
        }
        else
        {
            headlist << "BMU_ID" << "温度1" << "温度2" << "温度3" << "温度4" << "温度5" << "温度6" << "温度7" \
                << "温度8" << "温度9" << "温度10" << "温度11" << "温度12" << "温度13" << "温度14" << "温度15" << "温度16" << "时间";
            ui.tableWidget->setColumnCount(headlist.count());
            ui.tableWidget->setHorizontalHeaderLabels(headlist);
            populateTableWidget(query);
            //QMessageBox::warning(this, "警告", "温度数据成功");

        }
    }
    else  if (ui.comboBox_2->currentText().contains("电压数据"))
    {
        mydb.setDatabaseName("bmudb.db");
        mydb.open();
        sql = QString("SELECT * FROM Volatage WHERE ID= %1").arg(ui.comboBox->currentIndex());
        if (!query.exec(sql)) //执行插入操作
        {
            QString err_info = tr("数据库失败[%1]").arg(query.lastError().text());
        }
        else
        {
            headlist << "BMU_ID" << "电压1" << "电压2" << "电压3" << "电压4" << "电压5" << "电压6" << "电压7" \
                << "电压8" << "电压9" << "电压10" << "电压11" << "电压12" << "电压13" << "电压14" << "电压15" << "电压16" << "时间";
            ui.tableWidget->setColumnCount(headlist.count());
            ui.tableWidget->setHorizontalHeaderLabels(headlist);
            populateTableWidget(query);
            QMessageBox::warning(this, "警告", "Volatage");
        }
    }
    else  if (ui.comboBox_2->currentText().contains("状态数据"))
    {
        mydb.setDatabaseName("bcudb.db");
        mydb.open();
        sql = "SELECT * FROM BCUInfoBase";
        if (!query.exec(sql)) //执行插入操作
        {
            QString err_info = tr("数据库失败[%1]").arg(query.lastError().text());
        }
        else
        {
            headlist << "时间" << "总电压" << "总电流" << "接触器状态" << "电池状态" << "SOC" << "SOH" << "SOE" \
                << "最大单体电压" << "最小单体电压" << "平均单体电压" << "最大单体温度" << "最小单体温度" << "平均单体温度" << "P正总压"\
                << "绝缘状态字" << "正母线电阻" << "负母线电阻";
            ui.tableWidget->setColumnCount(headlist.count());
            ui.tableWidget->setHorizontalHeaderLabels(headlist);
            populateTableWidget(query);
            QMessageBox::warning(this, "警告", "BCUInfoBase");
        }
    }
    else  if (ui.comboBox_2->currentText().contains("告警数据"))
    {
        mydb.setDatabaseName("bcudb.db");
        mydb.open();
        sql = "SELECT * FROM BCUAlarmInfo";
        headlist << "时间" << "一级报警" << "二级报警低" << "三级报警低" << "ALARM_ERROR_I" << "ALARM_ERROR_II" << "ALARM_ERROR_III" << "ALARM_ERROR_IV" \
            << "ALARM_ERROR_V" << "ALARM_ERROR_VI" << "BMS_STATE" << "SYS_STATE" << "CHG_DHG_POWER" << "ERROR_REASON";
        ui.tableWidget->setColumnCount(headlist.count());
        ui.tableWidget->setHorizontalHeaderLabels(headlist);
        if (!query.exec(sql)) //执行插入操作
        {
            QString err_info = tr("数据库失败[%1]").arg(query.lastError().text());
        }
        else
        {
            populateTableWidget(query);
            QMessageBox::warning(this, "警告", "BCUAlarmInfo");
        }
    }

}
void dataAnalysis::RealtimeDataSlot(int16_t chlData)
{
    /*****************************************************************/
    static int count = 0;
    if (count > AXIS_MAX_X)
    {
        m_series->remove(0);
        m_chart->axisX()->setMin(count - AXIS_MAX_X);
        m_chart->axisX()->setMax(count);                    // 更新X轴范围
    }
    m_series->append(QPointF(count, chlData));  // 更新显示（随机生成10以内的一个数）
    count++;
}

void dataAnalysis::LoadBmuDB()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("bmudb.db");
    if (!mydb.open()) //如果数据库打开失败，会弹出一个警告窗口
    {
         QMessageBox::warning(this, "警告", "数据库打开失败");
    }
    else
    {
        //  qDebug()<<"时间测试数据库打开";
    }
}

void dataAnalysis::StartAnalysis()
{


}

void dataAnalysis::on_StartPb_clicked()
{
    QString  sql = " SELECT * FROM Temputure WHERE ID = 0";
    QSqlQuery query;
    QString err_info;
    QString a;
    Val.clear();
    m_series[0].clear();
    if (!query.exec(sql)) //执行插入操作
    {
        QString err_info = tr("数据库失败[%1]").arg(query.lastError().text());
    }
    func tmpfunc;
    while (query.next())
    {
     //   Val.push_back(query.value(1));
        tmpfunc.Time = query.value(17);
        tmpfunc.Val = query.value(1);
        list << tmpfunc;
    }
    timer->setInterval(IntervalTime);
    timer->start();
}

void dataAnalysis::populateTableWidget(QSqlQuery  query)
{
    int row =0;

    int columnCount = query.record().count();
    ui.tableWidget->setColumnCount(columnCount);
    while (query.next()) {
        ui.tableWidget->setRowCount(row+1);
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem* item = new QTableWidgetItem(query.value(col).toString());
            ui.tableWidget->setItem(row, col, item);
        }
        ++row;      
    }
}

void dataAnalysis::on_FastPb_clicked()
{
    IntervalTime = IntervalTime / 2;
    timer->setInterval(IntervalTime);
    PlaySpeed = PlaySpeed * 2;
    ui.label_6->setText("X "+QString::number(PlaySpeed, 10));
}

void dataAnalysis::on_SlowPb_clicked()
{
    IntervalTime = IntervalTime * 2;
    timer->setInterval(IntervalTime);
    PlaySpeed = PlaySpeed / 2;
    ui.label_6->setText("X " + QString::number(PlaySpeed, 10));
}