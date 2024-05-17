#include "slaveiteminfo.h"
#include <QDateTime>
#include <QMessageBox>
#include "ui_slaveiteminfo.h"
#include "showslave.h"
#include "qmenu.h"
#include "qevent.h"
#include <src/drvmng/drvmng.h>

SlaveItemInfo::SlaveItemInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SlaveItemInfo)
{
    ui->setupUi(this);
  //  InitUi();
    InitChart();
 //   ui->widget_2->setCurPower(qrand()%(0-100));
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(UpdateItemUi()));
    timer->start();
    timer->setInterval(1000);
}

SlaveItemInfo::~SlaveItemInfo()
{
    delete ui;
}

void SlaveItemInfo::InitUi()
{

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget_2->clearContents();
    ui->tableWidget_2->setRowCount(0);
    ui->tableWidget_3->clearContents();
    ui->tableWidget_3->setRowCount(0);
    QStringList headlist;
    QStringList headlist1;
    QStringList headlist2;
    for (int k = 0; k < VoltNum; k++)
    {
        headlist << "电池电压" + QString::number(k, 10)+"(v)";
    }
    headlist << "采集时间";    
    
    ui->tableWidget->setColumnCount(headlist.count());
    ui->tableWidget->setHorizontalHeaderLabels(headlist);

    for (int k = 0; k < TempNum; k++)
    {
        headlist1 << "电池温度" + QString::number(k, 10) + "(°)";
    }
    headlist1 << "采集时间";
    ui->tableWidget_2->setColumnCount(headlist1.count());
    ui->tableWidget_2->setHorizontalHeaderLabels(headlist1);

    headlist2 << "电池总压" << "电池电流" << "RelayStatus" << "SignalStatus"
        << "采集时间";
    ui->tableWidget_3->setColumnCount(headlist2.count());
    ui->tableWidget_3->setHorizontalHeaderLabels(headlist2);

    ui->tableWidget->scrollToBottom();  //让滚动条滚动到最底部
    ui->tableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers); //禁止双击编辑
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
  //  ui->tableWidget->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);

    ui->tableWidget_2->scrollToBottom();  //让滚动条滚动到最底部
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers); //禁止双击编辑
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_2->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);

    ui->tableWidget_3->scrollToBottom();  //让滚动条滚动到最底部
    ui->tableWidget_3->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers); //禁止双击编辑
    ui->tableWidget_3->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_3->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
    CreateMenu();

}


void SlaveItemInfo::UpdateItemUi()
{
    if (!drvmng::getInstance().drv_connect_state())
    {
        return;
    }
    /// <summary>
    /// 电压显示
    /// </summary>
    QDateTime time = QDateTime::currentDateTime();
    QString    curTime = time.toString("yyyy-MM-dd hh:mm:ss");
    int rowCount = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowCount);
    for (int i = 0; i < ui->tableWidget->columnCount()-1; i++)
    {
        ui->tableWidget->setItem(rowCount, i, new QTableWidgetItem(QString::number((g_PackDetailInfoST[slaveItemID].BatVols[i] / 1000.00), 'f', 2))); //序号
    }
    ui->tableWidget->setItem(rowCount, ui->tableWidget->columnCount()-1, new QTableWidgetItem(curTime));   //采集时间
    ui->tableWidget->scrollToBottom();  //让滚动条滚动到最底部
    /// <summary>
    /// 温度显示
    /// </summary>
    rowCount = ui->tableWidget_2->rowCount();
    ui->tableWidget_2->insertRow(rowCount);
    for (int i = 0; i < ui->tableWidget_2->columnCount()-1; i++)
    {
        ui->tableWidget_2->setItem(rowCount, i , new QTableWidgetItem(QString::number((g_PackDetailInfoST[slaveItemID].BatTemps[i] /10.00), 'f', 2))); //序号
    }
    ui->tableWidget_2->setItem(rowCount, ui->tableWidget_2->columnCount()-1, new QTableWidgetItem(curTime));   //采集时间
    ui->tableWidget_2->scrollToBottom();  //让滚动条滚动到最底部


    ///图形显示

    if (RealtimeDataType == 1)
    {
       
        RealtimeDataSlot(g_PackDetailInfoST[slaveItemID].BatVols[RealtimeDataId]);
    }

    if (RealtimeDataType == 2)
    {

        RealtimeDataSlot(g_PackDetailInfoST[slaveItemID].BatVols[RealtimeDataId]);
    }
}


void SlaveItemInfo::InitChart()
{
    // init chart
    spline[0].setColor(Qt::red);     //设置折线颜色
    spline[0].setWidth(2);           //设置折线宽度
    m_series[0].setPen(spline[0]);
    spline[1].setColor(Qt::blue);
    spline[1].setWidth(2);
    m_series[1].setPen(spline[1]);
    m_series[1].setPointLabelsVisible(false);
  //  m_series[0].setUseOpenGL(true);
    m_series[0].setPointLabelsVisible(false);
    m_chart = new QChart();
    m_chart->setTheme(QChart::ChartThemeBlueCerulean); //设置系统主题
    m_chart->legend()->hide();                         //设置图例
    m_chart->setAnimationOptions(QChart::SeriesAnimations);// 设置曲线动画显示
    X_axis.setTitleText(" 采集时间 ");
    Y_axis.setTitleText(" 电池电压 ");
    for(int i = 0; i < CHANNEL_NUMBER; i++)
    {
        m_chart->addSeries(&m_series[i]);
        m_chart->setAxisX(&X_axis,&m_series[i]);
        m_chart->setAxisY(&Y_axis,&m_series[i]);

        for(int j = 0; j < POINT_NUMBER; j++)
        {
          //  m_series[i].append(j, 0);
        }
    }
    /// X轴参数设置
    X_axis.setRange(0,POINT_NUMBER);        //设置范围
    X_axis.setLabelFormat("%d");            //设置刻度的格式
    X_axis.setTickCount(20+1);              //设置X轴刻度线数目
    X_axis.setGridLineVisible(true);        //设置是否显示网格线
    X_axis.setLabelsVisible(true);          //设置刻度是否显示

    /// Y轴参数设置
    // Y_axis.setLabelFormat("%g");
    Y_axis.setLabelFormat("%.0f");
    Y_axis.setTickCount(15+1);             //设置Y轴刻度线数目
    Y_axis.setGridLineVisible(true);        //设置是否显示网格线
    Y_axis.setLabelsVisible(true);          //设置刻度是否显示
    Y_axis.setRange(AXIS_MIN_Y,AXIS_MAX_Y);
    m_chartView = new ChartView(m_chart);
    ui->gridLayout->addWidget(m_chartView);             //将图表显示添加到layout控件
    m_chartView->setRenderHint(QPainter::Antialiasing);     //启动反走样 Antialiasing反混
    connect(&m_series[0],&QSplineSeries::pointAdded,[=](int index){
        qreal y = m_series[0].at(index).y();
        if (y>Y_axis.max())
        {
            Y_axis.setMax(y +AXIS_STEP_Y);
        }
        if (y<Y_axis.min())
        {
            Y_axis.setMin(y -AXIS_STEP_Y);
        }
    }
    );
  connect(&m_series[0],  SIGNAL(hovered(QPointF, bool)), this, SLOT(showPointData(QPointF,bool)));
   tip = new Callout(m_chart);
   tip->hide();
}

void SlaveItemInfo::showPointData(QPointF position, bool isHovering)
{
    if (tip == 0)
        tip = new Callout(m_chart);
    if (isHovering) {

        tip->setText(QString("X: %1 \nY: %2 ").arg(QString::number(position.x(), 'd', 0)).arg(QString::number(position.y(), 'd', 0)));
        tip->setAnchor(position);
        tip->setZValue(11);
        tip->updateGeometry();
        tip->show();
    }
    else {
        tip->hide();
    }

}

void SlaveItemInfo::RealtimeDataSlot(int16_t chlData)
{
    /*****************************************************************/

    QVector<QPointF> list;
    QVector<QPointF> newlist;
    list = m_series[0].pointsVector();//获取现在图中列表
#if 0
    chlData = chlData + qrand() % 10; //TEST
    if (list.size() == 0)
    {
        Y_axis.setRange(chlData - AXIS_STEP_Y, chlData + AXIS_STEP_Y);
    }

    if (list.size() < AXIS_MAX_X)
    {
        //保持原来
        newlist = list;
    }
    else
    {
        //错位移动
        for (int i = 1; i < list.size(); i++)
        {
            newlist.append(QPointF(i - 1, list.at(i).y()));
        }
    }
    m_series[0].append(QPointF(newlist.size(), chlData));//最后补上新的数据
   
#else
    if (count > AXIS_MAX_X)
    {
        m_series->remove(0);
        m_chart->axisX()->setMin(count - AXIS_MAX_X);
        m_chart->axisX()->setMax(count);                    // 更新X轴范围
    }
    m_series->append(QPointF(count, chlData));  // 更新显示（随机生成10以内的一个数）
    count++;

#endif





  //  /*****************************************************************/
  //  m_series[0].replace(newlist);//替换更新
  //  m_series[0].append(QPointF(QPointF(newlist.size(), chlData)));
 
  //  m_series[0].setPen(QColor(255, 0, 0));//设置曲线颜色
  //  m_series[0].setUseOpenGL(true);//openGl 加速

  ////  m_chart->removeSeries(&m_series[0]);
  //  m_chart->addSeries(&m_series[0]);
  //  // m_chart->createDefaultAxes();//设置坐标轴

  //  X_axis.setRange(0,AXIS_MAX_X);//范围
  //  X_axis.setTitleText("times(secs)");//标题
  //  X_axis.setTickCount(10);//分隔个数
  //  X_axis.setLineVisible(true);//可视化
  //  X_axis.setLinePenColor(Qt::blue);//颜色

  //  Y_axis.setRange(0,1200);
  //  Y_axis.setTickCount(6);
  //  Y_axis.setLineVisible(true);
  //  Y_axis.setLinePenColor(Qt::blue);

  //      QVector<QPointF> crtPoints, oldPoints;
  //      int size = 0;
  //      qreal minRange, maxRange;

  //      minRange = Y_axis.min();
  //      maxRange = Y_axis.max();

  //          oldPoints = m_series[0].pointsVector();
  //          oldPoints.pop_front();
  //          size = oldPoints.count();
  //          for(int j = 0; j < size; j++)
  //          {
  //              crtPoints.push_back(QPointF(j, oldPoints.at(j).y()));
  //          }
  //          crtPoints.push_back(QPointF(POINT_NUMBER-1, chlData));

  //          if(chlData < minRange)
  //          {
  //              minRange = chlData - 5;
  //              Y_axis.setMin(minRange);
  //          }
  //          if(chlData > maxRange)
  //          {
  //              maxRange = chlData + 5;
  //              Y_axis.setMax(maxRange);
  //          }
  //          m_series[0].replace(crtPoints);
}

void SlaveItemInfo::CreateMenu()
{

    //m_pMenuRD = new QMenu(this);
    //m_pMenuRD->setTitle(tr("电压曲线"));
    //m_pMenuTest = m_pMenuRD->addAction(tr("电压-"));
    //connect(m_pMenuRD, SIGNAL(triggered(QAction*)), this, SLOT(SlotMenuClicked(QAction*)));
    //m_pMenuTest->setEnabled(true);
    //m_pMenuTest->setVisible(true);
    //m_pMenuTest->setCheckable(true);

    m_pMenuRD = new QMenu(this);
    QMenu   *m_pMenuTestV = new QMenu(this);
    QMenu   *m_pMenuTestT = new QMenu(this);
    m_pMenuTestV->setTitle(tr("电压曲线"));

    
    for (int i = 0; i < VoltNum; i++)
    {
        QAction* m_pActionTestV = m_pMenuTestV->addAction(tr("电压-")+ QString::number(i, 10));
        m_pActionTestV->setChecked(true);
    }

    m_pMenuRD->addMenu(m_pMenuTestV);

    m_pMenuTestT->setTitle(tr("温度曲线"));

    for (int i = 0; i < TempNum; i++)
    {
        m_pMenuTestT->addAction(tr("温度-") + QString::number(i, 10));
    }
    m_pMenuRD->addMenu(m_pMenuTestT);
   // connect(m_pMenuRD, &QAction::triggered, this, &SlaveItemInfo::UpdateItemUi);
    connect(m_pMenuRD, SIGNAL(triggered(QAction*)), this, SLOT(SlotMenuClicked(QAction*)));
}


void SlaveItemInfo::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::RightButton)
    {
        m_pMenuRD->exec(QCursor::pos());
    }
}




void SlaveItemInfo::LableInfoShow(int Id,uint16_t voltNum,uint16_t tempNum)
{
    QString  tx;
    tx = "从控" + QString ::number(Id,10) + "信息";
    ui->LabelInfo->setText(tx);
    slaveItemID = Id;
    VoltNum = voltNum;
    TempNum = tempNum;
    InitUi();
}


void SlaveItemInfo::ShowVoltInfo(uint16_t *Volt)
{
    QDateTime time = QDateTime::currentDateTime();
    QString    curTime = time.toString("yyyy-MM-dd hh:mm:ss");
    int rowCount = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowCount);
    for (int i = 0; i < ui->tableWidget->columnCount() - 1; i++)
    {
        float  tempV = Volt[i]*0.001;
        ui->tableWidget->setItem(rowCount, i, new QTableWidgetItem(QString::number(tempV))); //序号
    }
    ui->tableWidget->setItem(rowCount, 16, new QTableWidgetItem(curTime));   //采集时间
    RealtimeDataSlot(Volt[0]);
    ui->tableWidget->scrollToBottom();  //让滚动条滚动到最底部
}





void SlaveItemInfo::ShowtTempInfo(int16_t *Tempture)
{
    QDateTime time = QDateTime::currentDateTime();
    QString    curTime = time.toString("yyyy-MM-dd hh:mm:ss");
    int rowCount = ui->tableWidget_2->rowCount();
    ui->tableWidget_2->insertRow(rowCount);
    for (int i = 0; i < ui->tableWidget_2->columnCount() - 1; i++)
    {
        float  tempV = Tempture[i] * 0.1;
        ui->tableWidget_2->setItem(rowCount, i, new QTableWidgetItem(QString::number(tempV))); //序号
    }
    ui->tableWidget_2->setItem(rowCount, 16, new QTableWidgetItem(curTime));   //采集时间
    ui->tableWidget_2->scrollToBottom();  //让滚动条滚动到最底部
}

void SlaveItemInfo::ShowSatusInfo(uint8_t Blance[16], uint8_t Status[16])
{
    ui->tableWidget_3->scrollToBottom();  //让滚动条滚动到最底部
}


void SlaveItemInfo::on_tableWidget_itemClicked(QTableWidgetItem* item)
{
    int currow = item->row();
    QTableWidgetItem* it = ui->tableWidget->item(currow, 3);
    //if (ui->rBT_T0->isChecked())
    //{
    //    ui->lET0->setText(it->text());
    //}
    // 显示标记点
    QPointF position;
    position.setX(currow);
    qreal   yval = it->text().toDouble();
    position.setY(yval);
    tip->setText(QString("X: %1 \nY: %2 ").arg(QString::number(position.x(), 'd', 0)).arg(QString::number(position.y(), 'd', 0)));
    tip->setAnchor(position);
    tip->setZValue(11);
    tip->updateGeometry();
    tip->show();
       
}

void SlaveItemInfo::SlotMenuClicked(QAction* action)
{
    bool ok;
    m_series->clear();
    count = 0;
   QString str= action->text();
   QStringList list = str.split("-");
   RealtimeDataId = list[1].toInt(&ok, 10);
   if (list[0] == "电压")
   {
       RealtimeDataType = 1;
       Y_axis.setTitleText(" 电池电压-"+ list[1]);
       Y_axis.setRange(0, 5000);
       Y_axis.setLabelFormat("%d");
       Y_axis.setTickCount(10);             //设置Y轴刻度线数目
       Y_axis.setGridLineVisible(true);        //设置是否显示网格线
       Y_axis.setLabelsVisible(true);          //设置刻度是否显示
   }
   else if(list[0] == "温度")
   {
       RealtimeDataType = 2;
       Y_axis.setTitleText(" 电池温度-"+ list[1]);
       Y_axis.setLabelFormat("%0.f");
       Y_axis.setRange(-10, 200);
       Y_axis.setTickCount(10);             //设置Y轴刻度线数目
   }
   
   action->setChecked(true);
   action->setEnabled(true);
}
