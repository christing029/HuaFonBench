#include "dataAnalysis.h"
#include <QTreeWidget>
#include <QtGui/qstandarditemmodel.h>
#include  <QScrollBar>

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
    myWidget = new QTableWidget();
    myWidget->resizeColumnsToContents();
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
  /*  ui.StartPb->setIcon(QIcon(":/icon/start.ico"));
    ui.StopPb->setIcon(QIcon(":/icon/stopall.png"));
    ui.FastPb->setIcon(QIcon(":/icon/DoubleLast_32x32.png"));
    ui.SlowPb->setIcon(QIcon(":/icon/DoublePrev_32x32.png"));*/
    //timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()), this, SLOT(updateValue()));
    //timer->stop();
    //timer->setInterval(IntervalTime);

    QMenu* menu = new QMenu(this);
    menu->addAction(tr("该时刻详细电压"), this, &dataAnalysis::bmuCurrentTimeVoltage);
    menu->addAction(tr("该时刻详细温度"), this, &dataAnalysis::bmuCurrentTimeTemputure);
    menu->setStyleSheet("QMenu {background-color: #435; border: 1px solid #ccc;}");
    ui.tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(ui.tableWidget, &QTableWidget::customContextMenuRequested, [this, menu](const QPoint& pos) {
        QModelIndex index = ui.tableWidget->indexAt(pos);
        if (index.isValid()) {  
                   int   SlectId = index.row();
                   QTableWidgetItem *item=  ui.tableWidget->item(SlectId, 0);
                   SelectTime = item->text();
            menu->exec(ui.tableWidget->viewport()->mapToGlobal(pos));
        }
        });
    // 连接cellDoubleClicked信号到一个自定义槽函数
    QObject::connect(ui.tableWidget, &QTableWidget::cellDoubleClicked, [&](int row, int column) {
        // 这里处理双击事件，row是双击的行，column是双击的列
        // 例如，打印行和列的索引
        qDebug() << "Double clicked on row:" << row << "column:" << column;
        bmuSingleData(row, column);
        });
    ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui.tableWidget->horizontalHeader()->setSectionsClickable(true);
    ui.tableWidget->verticalHeader()->setSectionsClickable(true);
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

    QMessageBox messageBox(QMessageBox::NoIcon, "清除", "是否清除数据", QMessageBox::Yes | QMessageBox::No, NULL);
    messageBox.setWindowFlag(Qt::WindowStaysOnTopHint);
    int reply = messageBox.exec(); 
    if (reply == QMessageBox::No)
    {
        return;
    }
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
            headlist << "时间" << "BMU_ID" << "温度1" << "温度2" << "温度3" << "温度4" << "温度5" << "温度6" << "温度7" \
                << "温度8" << "温度9" << "温度10" << "温度11" << "温度12" << "温度13" << "温度14" << "温度15" << "温度16" ;
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
            headlist << "时间" << "BMU_ID" << "电压1" << "电压2" << "电压3" << "电压4" << "电压5" << "电压6" << "电压7" \
                << "电压8" << "电压9" << "电压10" << "电压11" << "电压12" << "电压13" << "电压14" << "电压15" << "电压16" ;
            ui.tableWidget->setColumnCount(headlist.count());
            ui.tableWidget->setHorizontalHeaderLabels(headlist);
            populateTableWidget(query);
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
        }
    }

}
void dataAnalysis::on_NextPage_clicked()
{
    int rowCount = ui.tableWidget->model()->rowCount();
    int rowHeight = ui.tableWidget->rowHeight(0);
    int tableViewHeight = ui.tableWidget->height();
    int rowCountPerPage = tableViewHeight / rowHeight - 1;
    int canNotViewCount = rowCount - rowCountPerPage;
    if (canNotViewCount == 0)
        return;
    int maxValue = ui.tableWidget->verticalScrollBar()->maximum();
    if (maxValue == 0)
        return;
    int pageValue = maxValue * rowCountPerPage / canNotViewCount;
    int nCurScroller = ui.tableWidget->verticalScrollBar()->value();

    if (nCurScroller < maxValue)
    {
        ui.tableWidget->verticalScrollBar()->setSliderPosition(nCurScroller + pageValue);
        CurrentPage ++;
    }
    else
    {
        QMessageBox::question(NULL, "提示信息", "已经到最后页了！");
        ui.tableWidget->verticalScrollBar()->setSliderPosition(0);
    }
    ui.PageNo->setText("当前页: "+QString::number(CurrentPage, 10));
}
void dataAnalysis::on_PreviousPage_clicked()
{
    int rowCount = ui.tableWidget->model()->rowCount();
    int rowHeight = ui.tableWidget->rowHeight(0);
    int tableViewHeight = ui.tableWidget->height();
    int rowCountPerPage = tableViewHeight / rowHeight - 1;
    int canNotViewCount = rowCount - rowCountPerPage;
    if (canNotViewCount == 0)
        return ;
    int maxValue = ui.tableWidget->verticalScrollBar()->maximum();
    if (maxValue == 0)
        return;
    int pageValue = maxValue * rowCountPerPage / canNotViewCount;
    int nCurScroller = ui.tableWidget->verticalScrollBar()->value();
    if (nCurScroller > 0)
    {
        ui.tableWidget->verticalScrollBar()->setSliderPosition(nCurScroller - pageValue);
        CurrentPage--;
    }
    else
    {
        CurrentPage = 1;
        QMessageBox::question(NULL, "提示信息", "已经到首页了！");
        ui.tableWidget->verticalScrollBar()->setSliderPosition(maxValue);
    }
    ui.PageNo->setText("当前页: "+QString::number(CurrentPage, 10));
}
void dataAnalysis::on_FirstPage_clicked()
{
    CurrentPage = 1;
    int maxValue = ui.tableWidget->verticalScrollBar()->maximum();
    if (maxValue == 0)
        return;
    ui.tableWidget->verticalScrollBar()->setSliderPosition(0);
    ui.PageNo->setText("当前页: " + QString::number(CurrentPage, 10));
    return;
}
void dataAnalysis::on_LastPage_clicked()
{

    int maxValue = ui.tableWidget->verticalScrollBar()->maximum();
    if (maxValue == 0)
        return;
    ui.tableWidget->verticalScrollBar()->setSliderPosition(maxValue);
    return;
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
    pageCount();
}

int dataAnalysis::pageCount()
{
    int rowCount = ui.tableWidget->model()->rowCount();
    int rowHeight = ui.tableWidget->rowHeight(0);
    if (rowHeight == 0)
        return 0;
    int tableViewHeight = ui.tableWidget->height();
    int rowCntPerPage = tableViewHeight/ rowHeight-1;
    int ret = rowCount / rowCntPerPage;
    int rem = rowCount % rowCntPerPage;
    if (rem != 0) ret++;
    ui.TotalPage->setText("总页数: "+ QString::number(ret,10));
    return ret;
}

void dataAnalysis::bmuCurrentTimeVoltage()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    QString  sql = "";
    QSqlQuery query;
    QStringList headlist;
    int row = 0;
    QDateTime datatime1 = QDateTime::fromString(SelectTime, "yyyy-MM-dd hh:mm:ss");

    mydb.setDatabaseName("bmudb.db");
    mydb.open();
    sql = QString("SELECT * FROM Volatage WHERE Time BETWEEN  '%1' AND  '%2'" ).arg(datatime1.addSecs(0).toString("yyyy-MM-dd hh:mm:ss")).arg(datatime1.addSecs(3).toString("yyyy-MM-dd hh:mm:ss"));
   // SELECT* FROM Temputure WHERE Time BETWEEN '2023-01-01' AND '2024-12-31'
    if (!query.exec(sql)) //执行插入操作
    {
        QString err_info = tr("数据库失败[%1]").arg(query.lastError().text());
        return;
    }

    headlist << "时间" << "BMU_ID" << "电压1" << "电压2" << "电压3" << "电压4" << "电压5" << "电压6" << "电压7" \
        << "电压8" << "电压9" << "电压10" << "电压11" << "电压12" << "电压13" << "电压14" << "电压15" << "电压16";
    int columnCount = query.record().count();
    myWidget->setColumnCount(columnCount);
    myWidget->setHorizontalHeaderLabels(headlist);
    while (query.next()) {
       myWidget->setRowCount(row + 1);
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem* item = new QTableWidgetItem(query.value(col).toString());
            myWidget->setItem(row, col, item);
        }
        ++row;
    }
    myWidget->resizeColumnsToContents();
    myWidget->show();
}

void dataAnalysis::bmuCurrentTimeTemputure()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    QString  sql = "";
    QSqlQuery query;
    QStringList headlist;
    mydb.setDatabaseName("bmudb.db");
    mydb.open();
    QDateTime datatime1 = QDateTime::fromString(SelectTime, "yyyy-MM-dd hh:mm:ss");
    sql = QString("SELECT * FROM Temputure WHERE Time BETWEEN  '%1' AND  '%2'").arg(datatime1.addSecs(0).toString("yyyy-MM-dd hh:mm:ss")).arg(datatime1.addSecs(3).toString("yyyy-MM-dd hh:mm:ss"));

    if (!query.exec(sql)) //执行插入操作
    {
        QString err_info = tr("数据库失败[%1]").arg(query.lastError().text());
    }
    int row = 0;
    headlist << "时间" << "BMU_ID" << "温度1" << "温度2" << "温度3" << "温度4" << "温度5" << "温度6" << "温度7" \
        << "温度8" << "温度9" << "温度10" << "温度11" << "温度12" << "温度13" << "温度14" << "温度15" << "温度16";
    int columnCount = query.record().count();
    myWidget->setColumnCount(columnCount);
    myWidget->setHorizontalHeaderLabels(headlist);
    while (query.next()) {
        myWidget->setRowCount(row + 1);
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem* item = new QTableWidgetItem(query.value(col).toString());
            myWidget->setItem(row, col, item);
        }
        ++row;
    }
    myWidget->resizeColumnsToContents();
    myWidget->show();
}

void dataAnalysis::bmuSingleData(int row, int column)
{
    QTableWidgetItem* item = ui.tableWidget->item(row, 0);
    QString currentTime = item->text();
    QDateTime datatime1 = QDateTime::fromString(currentTime, "yyyy-MM-dd hh:mm:ss");
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    QString  sql = "";
    QSqlQuery query;
    QStringList headlist;
    QStringList headlist2;
    QWidget* parentWidget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(parentWidget);
    QTableWidget* TempuWidget = new QTableWidget();
    QTableWidget* VoltWidget = new QTableWidget();
    int datarow = 0;
    mydb.setDatabaseName("bmudb.db");
    mydb.open();
    sql = QString("SELECT * FROM Temputure WHERE Time BETWEEN  '%1' AND  '%2'").arg(datatime1.addSecs(0).toString("yyyy-MM-dd hh:mm:ss")).arg(datatime1.addSecs(3).toString("yyyy-MM-dd hh:mm:ss"));
    if (!query.exec(sql)) //执行插入操作
    {
        QString err_info = tr("数据库失败[%1]").arg(query.lastError().text());
    }

    headlist << "时间" << "BMU_ID" << "温度1" << "温度2" << "温度3" << "温度4" << "温度5" << "温度6" << "温度7" \
        << "温度8" << "温度9" << "温度10" << "温度11" << "温度12" << "温度13" << "温度14" << "温度15" << "温度16";
    int columnCount = query.record().count();
    TempuWidget->setColumnCount(columnCount);
    TempuWidget->setHorizontalHeaderLabels(headlist);
    while (query.next()) {
        TempuWidget->setRowCount(datarow + 1);
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem* item = new QTableWidgetItem(query.value(col).toString());
            TempuWidget->setItem(datarow, col, item);
        }
        ++datarow;
    }
    datarow = 0;
     sql = QString("SELECT * FROM Volatage WHERE Time BETWEEN  '%1' AND  '%3'").arg(datatime1.addSecs(0).toString("yyyy-MM-dd hh:mm:ss")).arg(datatime1.addSecs(3).toString("yyyy-MM-dd hh:mm:ss"));
     if (!query.exec(sql)) //执行插入操作
     {
         QString err_info = tr("数据库失败[%1]").arg(query.lastError().text());
     }

     headlist2 << "时间" << "BMU_ID" << "电压1" << "电压2" << "电压3" << "电压4" << "电压5" << "电压6" << "电压7" \
         << "电压8" << "电压9" << "电压10" << "电压11" << "电压12" << "电压13" << "电压14" << "电压15" << "电压16";
    columnCount = query.record().count();
    VoltWidget->setColumnCount(columnCount);
    VoltWidget->setHorizontalHeaderLabels(headlist2);
    while (query.next()) {
        VoltWidget->setRowCount(datarow + 1);
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem* item = new QTableWidgetItem(query.value(col).toString());
            VoltWidget->setItem(datarow, col, item);
        }
        ++datarow;
    }

    // 设置widget为可见
    TempuWidget->resizeColumnsToContents();
    VoltWidget->resizeColumnsToContents();
    TempuWidget->setVisible(true);
    VoltWidget->setVisible(true);
    // 添加widget到布局
    layout->addWidget(TempuWidget);
    layout->addWidget(VoltWidget);
    // 确保父控件布局完成
    parentWidget->update();
    QFile file(":/qss/HF.qss");
    if (!file.open(QIODevice::ReadOnly))
    {
        qWarning("Can't open the style sheet file.");
        return;
    }
    QString qss = QLatin1String(file.readAll());
    parentWidget->setStyleSheet(qss);
    // 显示父控件
    parentWidget->show();
}

void dataAnalysis::on_FastPb_clicked()
{
    IntervalTime = IntervalTime / 2;
    timer->setInterval(IntervalTime);
    PlaySpeed = PlaySpeed * 2;
  //  ui.label_6->setText("X "+QString::number(PlaySpeed, 10));
}

void dataAnalysis::on_SlowPb_clicked()
{
    IntervalTime = IntervalTime * 2;
    timer->setInterval(IntervalTime);
    PlaySpeed = PlaySpeed / 2;
  //  ui.label_6->setText("X " + QString::number(PlaySpeed, 10));
}