#include "showslave.h"
#include "ui_showslave.h"
#include <QFile>
#include <src/slavemng/slavemng.h>
#include <QDateTime>
#include <iostream>
#include <QThread>
#include <QTimer>
#include <QFuture>
#include "ShowVoltageNet.h"
#include "ShowTempNet.h"

#pragma execution_character_set("utf-8")
_PackDetailInfoST     g_PackDetailInfoST[MAX_BMU_NUM] = { 0 };
_F0DevInfo            g_DevInfo[MAX_BMU_NUM] = { 0 };
ShowSlave::ShowSlave(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShowSlave)
{
    ui->setupUi(this);
  //  InitUi();
    QFile file(":/qss/HF.qss");
    if (!file.open(QIODevice::ReadOnly))
    {
        qWarning("Can't open the style sheet file.");
        return;
    }
    QString qss = QLatin1String(file.readAll());
    QString paletteColor = qss.mid(20, 7);
    // this->setPalette(QPalette(QColor(paletteColor)));
    this->setStyleSheet(qss);
    // this->setStyleSheet(file.readAll());
    file.close();
    Openbmu_DataBase();
    QTimer* KeepLiveTimer = new QTimer(this);
    connect(KeepLiveTimer, SIGNAL(timeout()), this, SLOT(KeepLiveProcess()));
 //   KeepLiveTimer->start(1000);//start之后,每隔一秒触发一次槽函数  
    KeepLiveTimer->stop();
   // Iconitem = new QStandardItem("");
   slaveItemInfo = new SlaveItemInfo();
   InitUi(15);
}


void ShowSlave::myFunc(const QString& str)
{
    qDebug() << __FUNCTION__ << str << QThread::currentThreadId() << QThread::currentThread();
}

ShowSlave::~ShowSlave()
{
    delete ui;
}


void ShowSlave::InitUi(uint8_t SlaveNum)
{
    mode = new QStandardItemModel(this);
    mode->setHorizontalHeaderLabels(QStringList()<< ("从控号 ")<< (" 状态 "));
    ui->treeView->setModel(mode);
    ui->treeView->setEditTriggers(QTreeView::NoEditTriggers);
    ui->treeView->expandAll();
    for (int i = 0; i < SlaveNum; i++)
    {
        QStandardItem* item = new QStandardItem("从控"+ QString::number(i+1, 10));
        mode->setItem(i, 0, item);
        mode->item(i, 0)->setCheckable(false);
        mode->item(i, 0)->setCheckState(Qt::PartiallyChecked);
        Iconitem[i] = new QStandardItem("");
        Iconitem[i]->setIcon(QIcon(":/icon/globes_grey.png"));
        mode->setItem(i, 1, Iconitem[i]);
    } 
    QMenu* menu = new QMenu(this);
    menu->addAction(tr("电池组实时视图"), this, &ShowSlave::slotSlaveNetMenu);
    menu->addAction(tr("电压数据视图"), this, &ShowSlave::slotDataMenu);
    menu->addAction(tr("温度数据视图"), this, &ShowSlave::slotTempDataMenu);
    menu->addAction(tr("电池组风扇视图"), this, &ShowSlave::slotFanDataMenu);
    menu->addAction(tr("电池组配置视图"), this, &ShowSlave::slotContextMenu);
    menu->setStyleSheet("QMenu {background-color: #435; border: 1px solid #ccc;}");
    ui->treeView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->treeView, &QTreeView::customContextMenuRequested, [this, menu](const QPoint& pos) {
        QModelIndex index = ui->treeView->indexAt(pos);
        if (index.isValid()) {
          SlectSlaveId = index.row();
            menu->exec(ui->treeView->viewport()->mapToGlobal(pos));
        }
        });

}

void ShowSlave::HideAll()
{
   // for (int i=0;i<8;i++)
   // pchann1[i].hide();
}

void ShowSlave::slotContextMenu()
{
    SlaveMng *slavemng = new SlaveMng();
    slavemng->show();
}

void ShowSlave::slotSlaveNetMenu()
{
   // bmunet = new ShowBMUNet();
     ShowBMUNet  *bmu = new ShowBMUNet(SlectSlaveId);
     bmu->SetSlaveNum(20);
     bmu->SetTempNum(TempCntPerSlave);
     bmu->SetVoltNum(VoltCntPerSlave);
     bmu->show();
}
void ShowSlave::slotDataMenu()
{
    //CustomDockWidget*  dockWidget = new CustomDockWidget(this);
    //addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
    //dockWidget->setFeatures(QDockWidget::DockWidgetClosable | QDockWidget::DockWidgetFloatable);
    //dockWidget->setWidget(new ShowVoltageNet(SlaveCount));
    //ui->horizontalLayout->addWidget(new ShowVoltageNet(SlaveCount, VoltCntPerSlave));
    ShowVoltageNet  *net = new ShowVoltageNet(SlaveCount, VoltCntPerSlave);
    net->show();
}

void ShowSlave::slotTempDataMenu()
{
    ShowTempNet* net = new ShowTempNet(SlaveCount, TempCntPerSlave);
    net->show();
}

void ShowSlave::slotFanDataMenu()
{
    ShowFanNet *net = new ShowFanNet(nullptr);
    net->show();

}



void ShowSlave::KeepLiveProcess()
{
   for (int i = 0; i < 8; i++)
 {
    if (g_PackDetailInfoST[i].Vaild == true)
    {
        if (g_PackDetailInfoST[i].Nowlive != g_PackDetailInfoST[i].Keeplive)
        {
            g_PackDetailInfoST[i].Keeplive = g_PackDetailInfoST[i].Nowlive;
        }
        else
        {
            // 异常
            g_PackDetailInfoST[i].Vaild = false;
        }
    }
    else
    {
     //   QStandardItem* item = new QStandardItem("");
        Iconitem[i]->setIcon(QIcon(":/icon/globes_red.png"));
      //  iconitem->setIcon(QIcon(":/icon/globes_red.png"));
        mode->setItem(i, 1, Iconitem[i]);

    }
}
}

void ShowSlave::on_treeView_doubleClicked(const QModelIndex& index)
{
    QWidget* w = this->findChild<QWidget*>("toc");
    ui->horizontalLayout->removeWidget(w);
    w->deleteLater();
    QString tx = mode->itemFromIndex(index)->text();
    int  row = mode->itemFromIndex(index)->index().row();
    slaveItemInfo->LableInfoShow(row, VoltCntPerSlave, TempCntPerSlave);
    QVBoxLayout* layout = new  QVBoxLayout(slaveItemInfo);

    layout->addWidget(slaveItemInfo);

    ui->horizontalLayout->addWidget(slaveItemInfo);


    //HideAll();
    ////        QDockWidget *dockWin1 = new QDockWidget("端口一浮窗",this);
    ////        dockWin1->setFeatures(QDockWidget::DockWidgetMovable);
    ////        dockWin1->setFeatures(QDockWidget::AllDockWidgetFeatures);
    ////        dockWin1->setWidget(pchann1);
    ////        addDockWidget(Qt::RightDockWidgetArea,dockWin1);      //窗口的默认停靠位置要在下一个dock窗口构造前写出

    //QVBoxLayout* layout = new  QVBoxLayout(&pchann1[row]);
    //layout->addWidget(&pchann1[row]);
    //ui->horizontalLayout->addWidget(&pchann1[row]);
    //pchann1[row].show();
    //pchann1[row].LableInfoShow(row);
}

void ShowSlave::Openbmu_DataBase()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("bmudb.db");
    if (!mydb.open()) //如果数据库打开失败，会弹出一个警告窗口
    {
        //    QMessageBox::warning(this, "警告", "数据库打开失败");
    }
    else
    {
        //  qDebug()<<"时间测试数据库打开";
    }
 //   Add_BMUDB_voltageTable();
}

//1）	分段索引在1~16之间，表明发送的是电压数据，允许最多发送48个电压数据。
//2）	分段索引在16~24之间，表明发送的是温度数据，允许最多发送24个温度数据
//3）	分段索引23，BatTotalVolt BatCurrent；
//4）	分段索引24，RelayStatus，SignalStatus，ErrTempCount，ErrVolCount，SWVersion HWVersion
//5）	分段索引25 BalancePosition，DataReady，




void ShowSlave::Add_VoltageTable(uint8_t ID,uint16_t V[LECU_MAX_VOL])
{
    QDateTime time = QDateTime::currentDateTime();
    QString    curTime = time.toString("yyyy-MM-dd hh:mm:ss");
    int currentRow = 0;
    QString str = QString("insert into Volatage(ID,V1,V2,V3,V4,V5,V6,V7,V8,V9,V10,V11,V12,V13,V14,V15,V16,Time) values('%1', '%2', '%3', '%4','%5','%6','%7', '%8', '%9', '%10','%11','%12','%13', '%14', '%15', '%16','%17','%18')")
        .arg(ID).arg(V[0]).arg(V[1]).arg(V[2]).arg(V[3]).arg(V[4]).arg(V[5]).arg(V[6]).arg(V[7]).arg(V[8]).arg(V[9]).arg(V[10]).arg(V[11]).arg(V[12]).arg(V[13]).arg(V[14]).arg(V[15]).arg(curTime);
    QSqlQuery query;
    QString err_info;
    QString a;
    if (!query.exec(str)) //执行插入操作
    {
        QString err_info = tr("数据库失败[%1]").arg(query.lastError().text());
    }
}

void ShowSlave::Add_TempTable(uint8_t ID,int16_t T[LECU_MAX_TEMP])
{
    QDateTime time = QDateTime::currentDateTime();
    QString    curTime = time.toString("yyyy-MM-dd hh:mm:ss");
    int currentRow = 0;
    QString str = QString("insert into Temputure(ID,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,Time) values('%1', '%2', '%3', '%4','%5','%6','%7', '%8', '%9', '%10','%11','%12','%13', '%14', '%15', '%16','%17','%18')")
        .arg(ID).arg(T[0]).arg(T[1]).arg(T[2]).arg(T[3]).arg(T[4]).arg(T[5]).arg(T[6]).arg(T[7]).arg(T[8]).arg(T[9]).arg(T[10]).arg(T[11]).arg(T[12]).arg(T[13]).arg(T[14]).arg(T[15]).arg(curTime);
    QSqlQuery query;
    QString err_info;
    QString a;
    if (!query.exec(str)) //执行插入操作
    {
        QString err_info = tr("数据库失败[%1]").arg(query.lastError().text());
    }
}

void ShowSlave::bmu_data_save_table(BMU_CAN_RecData *getMsg)
{
    bmu_volatge_segment* volseg;
    bmu_temp_segment* tempseg;
    _PackDetailStatus* detailstatus;
    uint8_t ID = getMsg->FrameId - 0x301;
    if ((getMsg->SegmentIndex - 1) *3 < LECU_MAX_VOL)
    {
        volseg = (bmu_volatge_segment*)getMsg->Data;
        g_PackDetailInfoST[ID].BatVols[(getMsg->SegmentIndex - 1) * 3] = volseg->volt_1.Val.volatage_val;
        g_PackDetailInfoST[ID].BatVols[(getMsg->SegmentIndex - 1) * 3] = volseg->volt_1.Val.volatage_val;
        g_PackDetailInfoST[ID].BatVols[(getMsg->SegmentIndex - 1) * 3 + 1] = volseg->volt_2.Val.volatage_val;
        g_PackDetailInfoST[ID].BatVols[(getMsg->SegmentIndex - 1) * 3 + 2] = volseg->volt_3.Val.volatage_val;
        g_PackDetailInfoST[ID].CellBlance[(getMsg->SegmentIndex - 1) * 3] = volseg->volt_1.Val.blance;
        g_PackDetailInfoST[ID].CellBlance[(getMsg->SegmentIndex - 1) * 3 + 1] = volseg->volt_2.Val.blance;
        g_PackDetailInfoST[ID].CellBlance[(getMsg->SegmentIndex - 1) * 3 + 2] = volseg->volt_3.Val.blance;
        g_PackDetailInfoST[ID].CellCnnStatus[(getMsg->SegmentIndex - 1) * 3] = volseg->volt_1.Val.connsta;
        g_PackDetailInfoST[ID].CellCnnStatus[(getMsg->SegmentIndex - 1) * 3 + 1] = volseg->volt_2.Val.connsta;
        g_PackDetailInfoST[ID].CellCnnStatus[(getMsg->SegmentIndex - 1) * 3 + 2] = volseg->volt_3.Val.connsta;
        return;
    }
    else if ((getMsg->SegmentIndex-37)*3  < LECU_MAX_TEMP)
    {
        tempseg = (bmu_temp_segment*)getMsg->Data;
        g_PackDetailInfoST[ID].BatTemps[(getMsg->SegmentIndex - 37) * 3] = tempseg->temp_1;
        g_PackDetailInfoST[ID].BatTemps[(getMsg->SegmentIndex - 37) * 3 + 1] = tempseg->temp_2;
        g_PackDetailInfoST[ID].BatTemps[(getMsg->SegmentIndex - 37) * 3 + 2] = tempseg->temp_3;
        return;
    }
    else if (getMsg->SegmentIndex == 73)
    {
        detailstatus = (_PackDetailStatus*)getMsg->Data;
        memcpy(&g_PackDetailInfoST[ID].PackDetailStatus, detailstatus, 7);
        return;
    }
    switch (getMsg->SegmentIndex)
    {
    case 0x37:
    {
        memcpy(&RealpackMinMaxInfo[ID].A0, getMsg->Data, 7);
    }
    break;
     case 0xa0: 
     {
         memcpy(&RealpackMinMaxInfo[ID].A0, getMsg->Data, 7);
     }
     break;
     case 0xa1: 
     {
         memcpy(&RealpackMinMaxInfo[ID].A1, getMsg->Data, 7);
     }
     break;
     case 0xa2:
     {
         memcpy(&RealpackMinMaxInfo[ID].A2, getMsg->Data, 7);
     }
     break;
     case 0xa3:
     {
         memcpy(&RealpackMinMaxInfo[ID].A3, getMsg->Data, 7);
     }
     break;
     case 75:
         g_PackDetailInfoST[ID].FanSpeed = (getMsg->Data[2]| getMsg->Data[3]<<8)&0x3fff;
         break;
     case 0xF0:
     case 0xF1:
     case 0xF2:
     case 0xF3:
     case 0xF4:
     case 0xF5:
     case 0xF6:
     case 0xF7:
     case 0xF8:
         memcpy(&g_DevInfo[ID].UseBatCount +((getMsg->SegmentIndex)-0xf0)*7, getMsg->Data, 7);
         g_PackDetailInfoST[ID].BmuInfo.UseBatCount = g_DevInfo[ID].UseBatCount;
         g_PackDetailInfoST[ID].BmuInfo.UseTempCount = g_DevInfo[ID].UseTempCount;
         memcpy(&g_PackDetailInfoST[ID].BmuInfo.SN, &g_DevInfo[ID].SN, 16);
         memcpy(&g_PackDetailInfoST[ID].BmuInfo.UUID, &g_DevInfo[ID].UUID, 16);
         memcpy(&g_PackDetailInfoST[ID].BmuInfo.SoftWareVerion, &g_DevInfo[ID].SoftWareVerion, 6);
         memcpy(&g_PackDetailInfoST[ID].BmuInfo.HardWareVerion, &g_DevInfo[ID].HardWareVerion, 6);
         break;
     default:
         break;
    }
}

void ShowSlave::slotsUpTCPBMUMsg(uint startAddress, QVector<quint16> val)
{
    QMutex pause_mutex;
    pause_mutex.lock();
    BATTERY_CFG_s battery_base = { 0 };
  //  QStandardItem* item = new QStandardItem("");
    switch (startAddress)
    {
    case MODBUS_BATTERY_BASE:
        memcpy((uint8_t*)&battery_base, (uint8_t*)&val[0], val.count());
        InitUi(battery_base.modulesCountPerString);
        SlaveCount = battery_base.modulesCountPerString;
        VoltCntPerSlave = battery_base.cellsCountPerModule;
        TempCntPerSlave = battery_base.tempsCountPerModule;
        for (int i = 0; i < battery_base.modulesCountPerString; i++)
        {
        g_PackDetailInfoST[i].Vaild = true;
        g_PackDetailInfoST[i].Nowlive++;
        Iconitem[i]->setIcon(QIcon(":/icon/globes_green.png"));
        mode->setItem(i, 1, Iconitem[0]);
         }
        break;
    case MODBUS_S_VOLT_BASE:
    case MODBUS_S_VOLT_BASE + BS_NR_OF_CELL_BLOCKS_PER_MODULE * 1:
    case MODBUS_S_VOLT_BASE + BS_NR_OF_CELL_BLOCKS_PER_MODULE * 2:
    case MODBUS_S_VOLT_BASE + BS_NR_OF_CELL_BLOCKS_PER_MODULE * 3:
    case MODBUS_S_VOLT_BASE + BS_NR_OF_CELL_BLOCKS_PER_MODULE * 4:
    case MODBUS_S_VOLT_BASE + BS_NR_OF_CELL_BLOCKS_PER_MODULE * 5:
    case MODBUS_S_VOLT_BASE + BS_NR_OF_CELL_BLOCKS_PER_MODULE * 6:
    case MODBUS_S_VOLT_BASE + BS_NR_OF_CELL_BLOCKS_PER_MODULE * 7:
    case MODBUS_S_VOLT_BASE + BS_NR_OF_CELL_BLOCKS_PER_MODULE * 8:
    case MODBUS_S_VOLT_BASE + BS_NR_OF_CELL_BLOCKS_PER_MODULE * 9:
    case MODBUS_S_VOLT_BASE + BS_NR_OF_CELL_BLOCKS_PER_MODULE * 10:
    case MODBUS_S_VOLT_BASE + BS_NR_OF_CELL_BLOCKS_PER_MODULE * 11:
    case MODBUS_S_VOLT_BASE + BS_NR_OF_CELL_BLOCKS_PER_MODULE * 12:
    case MODBUS_S_VOLT_BASE + BS_NR_OF_CELL_BLOCKS_PER_MODULE * 13:
    case MODBUS_S_VOLT_BASE + BS_NR_OF_CELL_BLOCKS_PER_MODULE * 14:
    case MODBUS_S_VOLT_BASE + BS_NR_OF_CELL_BLOCKS_PER_MODULE * 15:
    case MODBUS_S_VOLT_BASE + BS_NR_OF_CELL_BLOCKS_PER_MODULE * 16:
        startAddress = (startAddress - MODBUS_S_VOLT_BASE) / BS_NR_OF_CELL_BLOCKS_PER_MODULE;
       // Iconitem[0]->setIcon(QIcon(":/icon/globes_green.png"));
       //mode->setItem(startAddress, 1, Iconitem[0]);
   //     memcpy(&g_PackDetailInfoST[startAddress].BatVols[0], (uint8_t*)&val[0], val.count()*2);
        break;
    case MODBUS_S_TEMP_BASE:
    case MODBUS_S_TEMP_BASE + BS_NR_OF_TEMP_BLOCKS_PER_MODULE * 1:
    case MODBUS_S_TEMP_BASE + BS_NR_OF_TEMP_BLOCKS_PER_MODULE * 2:
    case MODBUS_S_TEMP_BASE + BS_NR_OF_TEMP_BLOCKS_PER_MODULE * 3:
    case MODBUS_S_TEMP_BASE + BS_NR_OF_TEMP_BLOCKS_PER_MODULE * 4:
    case MODBUS_S_TEMP_BASE + BS_NR_OF_TEMP_BLOCKS_PER_MODULE * 5:
    case MODBUS_S_TEMP_BASE + BS_NR_OF_TEMP_BLOCKS_PER_MODULE * 6:
    case MODBUS_S_TEMP_BASE + BS_NR_OF_TEMP_BLOCKS_PER_MODULE * 7:
    case MODBUS_S_TEMP_BASE + BS_NR_OF_TEMP_BLOCKS_PER_MODULE * 8:
    case MODBUS_S_TEMP_BASE + BS_NR_OF_TEMP_BLOCKS_PER_MODULE * 9:
    case MODBUS_S_TEMP_BASE + BS_NR_OF_TEMP_BLOCKS_PER_MODULE * 10:
    case MODBUS_S_TEMP_BASE + BS_NR_OF_TEMP_BLOCKS_PER_MODULE * 11:
    case MODBUS_S_TEMP_BASE + BS_NR_OF_TEMP_BLOCKS_PER_MODULE * 12:
    case MODBUS_S_TEMP_BASE + BS_NR_OF_TEMP_BLOCKS_PER_MODULE * 13:
    case MODBUS_S_TEMP_BASE + BS_NR_OF_TEMP_BLOCKS_PER_MODULE * 14:
    case MODBUS_S_TEMP_BASE + BS_NR_OF_TEMP_BLOCKS_PER_MODULE * 15:
    case MODBUS_S_TEMP_BASE + BS_NR_OF_TEMP_BLOCKS_PER_MODULE * 16:
        startAddress = (startAddress - MODBUS_S_TEMP_BASE) / BS_NR_OF_TEMP_BLOCKS_PER_MODULE;
        memcpy(&g_PackDetailInfoST[startAddress].BatTemps[0], (uint8_t*)&val[0], val.count()*2);
        break;
    case MODBUS_S_BMU_STATUS:
    case MODBUS_S_BMU_STATUS + BS_NR_OF_STATUS_BLOCKS_PER_MODULE * 1:
    case MODBUS_S_BMU_STATUS + BS_NR_OF_STATUS_BLOCKS_PER_MODULE * 2:
    case MODBUS_S_BMU_STATUS + BS_NR_OF_STATUS_BLOCKS_PER_MODULE * 3:
    case MODBUS_S_BMU_STATUS + BS_NR_OF_STATUS_BLOCKS_PER_MODULE * 4:
    case MODBUS_S_BMU_STATUS + BS_NR_OF_STATUS_BLOCKS_PER_MODULE * 5:
    case MODBUS_S_BMU_STATUS + BS_NR_OF_STATUS_BLOCKS_PER_MODULE * 6:
    case MODBUS_S_BMU_STATUS + BS_NR_OF_STATUS_BLOCKS_PER_MODULE * 7:
    case MODBUS_S_BMU_STATUS + BS_NR_OF_STATUS_BLOCKS_PER_MODULE * 8:
    case MODBUS_S_BMU_STATUS + BS_NR_OF_STATUS_BLOCKS_PER_MODULE * 9:
    case MODBUS_S_BMU_STATUS + BS_NR_OF_STATUS_BLOCKS_PER_MODULE * 10:
    case MODBUS_S_BMU_STATUS + BS_NR_OF_STATUS_BLOCKS_PER_MODULE * 11:
    case MODBUS_S_BMU_STATUS + BS_NR_OF_STATUS_BLOCKS_PER_MODULE * 12:
    case MODBUS_S_BMU_STATUS + BS_NR_OF_STATUS_BLOCKS_PER_MODULE * 13:
    case MODBUS_S_BMU_STATUS + BS_NR_OF_STATUS_BLOCKS_PER_MODULE * 14:
    case MODBUS_S_BMU_STATUS + BS_NR_OF_STATUS_BLOCKS_PER_MODULE * 15:
        startAddress = (startAddress - MODBUS_S_BMU_STATUS) / BS_NR_OF_STATUS_BLOCKS_PER_MODULE;
        memcpy(&g_PackDetailInfoST[startAddress].BmuStatus.pcbTemperature_ddegC, (uint8_t*)&val[0], val.count() * 2);
        break;
    case MODBUS_BMU_BASE:
    case MODBUS_BMU_BASE + sizeof(_BMU_DEV_INFO_s) * 1/2:
    case MODBUS_BMU_BASE + sizeof(_BMU_DEV_INFO_s) * 2/2:
    case MODBUS_BMU_BASE + sizeof(_BMU_DEV_INFO_s) * 3/2:
    case MODBUS_BMU_BASE + sizeof(_BMU_DEV_INFO_s) * 4/2:
    case MODBUS_BMU_BASE + sizeof(_BMU_DEV_INFO_s) * 5/2:
    case MODBUS_BMU_BASE + sizeof(_BMU_DEV_INFO_s) * 6/2:
    case MODBUS_BMU_BASE + sizeof(_BMU_DEV_INFO_s) * 7/2:
    case MODBUS_BMU_BASE + sizeof(_BMU_DEV_INFO_s) * 8/2:
    case MODBUS_BMU_BASE + sizeof(_BMU_DEV_INFO_s) * 9/2:
    case MODBUS_BMU_BASE + sizeof(_BMU_DEV_INFO_s) * 10/2:
    case MODBUS_BMU_BASE + sizeof(_BMU_DEV_INFO_s) * 11/2:
    case MODBUS_BMU_BASE + sizeof(_BMU_DEV_INFO_s) * 12/2:
    case MODBUS_BMU_BASE + sizeof(_BMU_DEV_INFO_s) * 13/2:
    case MODBUS_BMU_BASE + sizeof(_BMU_DEV_INFO_s) * 14/2:
    case MODBUS_BMU_BASE + sizeof(_BMU_DEV_INFO_s) * 15/2:
        startAddress = ((startAddress - MODBUS_BMU_BASE)) / (sizeof(_BMU_DEV_INFO_s)/2);
     //   memcpy(&g_PackDetailInfoST[startAddress].BmuInfo.UseBatCount, (uint8_t*)&val[0], val.count() * 2);
        break;
    }
//    delete  item;
    pause_mutex.unlock();
}

/// <summary>
/// 接收到从机发来的数据
/// </summary>
/// <param name="str"></param>
/// <param name="data"></param>
void ShowSlave::SlotsCanUpBMUMsg(QString str, QByteArray data)
{
    /// 1 显示在线图标

    if (initCanUi)
    {
       // InitUi(15);
    }
    else
    {
      initCanUi = false;
    }
    QMutex pause_mutex;
    pause_mutex.lock();
    BMU_CAN_RecData* Msg = (BMU_CAN_RecData*)data.data();
    uint32_t RevSlaveId = Msg->FrameId;
    if (RevSlaveId > 15)
    {
        pause_mutex.unlock();
        return;
    }
    g_PackDetailInfoST[RevSlaveId].Vaild = true;
    g_PackDetailInfoST[RevSlaveId].Nowlive++;
    
    Iconitem[RevSlaveId]->setIcon(QIcon(":/icon/globes_green.png"));
    mode->setItem(RevSlaveId, 1, Iconitem[RevSlaveId]);
    // 2 save 数据表
    bmu_data_save_table(Msg);
    pause_mutex.unlock();
}
