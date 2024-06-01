#include "drvmng.h"
#include "ui_drvmng.h"
#define LibECanVci "ECanVci"
MOBUS_RUN_STATE_BASE_s m_run_state_base = {0};
DEV_INFO_s         m_dev_info = { 0 };
_BMU_DEV_INFO_s     m_bmu_dev_info[MAX_BMU_NUM] = { 0 };
QMutex drvmng::mutex;
drvmng* drvmng::instance = NULL;

drvmng::drvmng(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::drvmng)
{
    QFile file(":/qss/HF.qss");
    if (!file.open(QIODevice::ReadOnly))
    {
        qWarning("Can't open the style sheet file.");
        return;
    }
    QString qss = QLatin1String(file.readAll());
    this->setStyleSheet(qss);
    ui->setupUi(this);
    MyCANControlThread = new Thread; //定义类对象// MyCANControlThread//就是分配内存空间
    connect(MyCANControlThread, SIGNAL(RecStandFrame_signal(QString, QByteArray)), this, SLOT(deal_can_rec(QString, QByteArray)));
    ui->statusbar->showMessage("CAN设备打开失败 ");
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateValue()));
    timer->stop();
    timer->setInterval(1000);
    mbtcp = new ModbusTCP(nullptr);
 //   mblib = new ModbusPoll(nullptr);
    connect(mbtcp, SIGNAL(modbus_state_change_signal(QModbusDevice::State)), this, SLOT(slot_stateChanged(QModbusDevice::State)));
    connect(mbtcp, SIGNAL(modbus_read_holding_unit(QModbusDataUnit)), this, SLOT(slot_read_holding(QModbusDataUnit)));
  //  connect(mbtcp, SIGNAL(modbus_read_input_unit(QModbusDataUnit)), this, SLOT(slot_read_dataunit(QModbusDataUnit)));
    settings = new QSettings("setting.ini", QSettings::IniFormat);
    ui->IPlineEdit->setText(settings->value("IPSetting/IP").toString());
    ui->PortlineEdit->setText(settings->value("IPSetting/Port").toString());
    ui->CB_Baud->setEditText(settings->value("CanSetting/Bound").toString());
    ui->comboBox_4->setCurrentIndex(settings->value("CanSetting/ChannelNum").toInt());

}



void drvmng::slot_stateChanged(QModbusDevice::State stat)
{
    mconnect = _UnCnn;
    switch (stat)
    {
    case  QModbusDevice::UnconnectedState:
            break;
    case QModbusDevice::ConnectingState:
                break;
    case QModbusDevice::ConnectedState:
        mconnect = _EthCnn;
        mbtcp->modbus_read_holding(1, MODBUS_SYSTEM_BASE, sizeof(DEV_INFO_s));
        break;
    case QModbusDevice::ClosingState:
        break;
    default:
        break;
    }
    CnnName= "[IP] " + ipQstr + ":" + portQstr;
    emit signalDeviceCnnState(CnnName, mconnect);
}

void drvmng::updateValue()
{
  static  unsigned char data_from_text[8] = { 0 };
    if (mconnect== _EthCnn)
    {
         QCoreApplication::processEvents();
         mbtcp->modbus_read_holding(1, MODBUS_RUN_STATE_BASE, sizeof(MOBUS_RUN_STATE_BASE_s));  
         mbtcp->modbus_read_holding(1, MODBUS_RUN_STATE_BASE_2, sizeof(MOBUS_RUN_STATE_BASE_s_2));
          for (int i = 0; i < SlaveCount; i++)
          {
              mbtcp->modbus_read_holding(1, MODBUS_S_VOLT_BASE + BS_NR_OF_CELL_BLOCKS_PER_MODULE * i, VoltCntPerSlave);
          }
          for (int i = 0; i < SlaveCount; i++)
          {
              mbtcp->modbus_read_holding(1, MODBUS_S_TEMP_BASE + BS_NR_OF_TEMP_BLOCKS_PER_MODULE * i, TempCntPerSlave);
          }
          for (int i = 0; i < SlaveCount; i++)
          {
              mbtcp->modbus_read_holding(1, MODBUS_S_BMU_STATUS + BS_NR_OF_STATUS_BLOCKS_PER_MODULE * i, BS_NR_OF_STATUS_BLOCKS_PER_MODULE);
          }
    }
    else  if (mconnect == _CanCnn)
    {
        if (data_from_text[1] == 0x08)
        {
            data_from_text[1] = 0x20;
        }
        else
        {
            data_from_text[1] = 0x08;
        }
        CanSnd(SynFrameId, data_from_text, 8);
    }
}
drvmng::~drvmng()
{
    MyCANControlThread->CloseCANThread();
    MyCANControlThread->stop();//停止子线程
    MyCANControlThread->quit();    
    delete mbtcp;
    delete MyCANControlThread;
    delete ui;
}

QString drvmng::getInstanceName() const
{
    return QString();
}

drvmng& drvmng::getInstance()
{
    /*
   * 双重锁定，减少每次开销，只有越过if(NULL == instance) 才需要锁定，极低概率
   */
    if (NULL == instance)
    {
        mutex.lock();                        //线程安全
        if (NULL == instance)
        {
            instance = new drvmng();
        }
        mutex.unlock();
    }
    return *instance;

    // TODO: 在此处插入 return 语句
}

void drvmng::release()
{
    if (instance != NULL)
    {
        mutex.lock();
        delete instance;
        instance = NULL;
        mutex.unlock();
    }
}

void drvmng::Ipconnect(QString Ip, UINT16 port)
{
    ipQstr = Ip;
    portQstr = port;
    if (_EthCnn == mconnect)
    {
        mbtcp->modbus_disconnect();
    }
    else
    {
        mbtcp->modbus_connect(Ip,9030);
    }
    saveCfg();
    return;
}

void drvmng::CanConnect(int CanID)
{
    if (mconnect == _UnCnn)
    {
        mbaud = 3;//500
        mbaud = 5;//500
        MyCANControlThread->Reset();
        MyCANControlThread->OpenCANThread(mbaud, CanID);
        MyCANControlThread->start();//启动子线程//间接调用了run()函数//即接收数据
      //  MyCANControlThread->run();//启动子线程//间接调用了run()函数//即接收数据
        if (MyCANControlThread->isRunning())
        {
            ui->statusbar->showMessage("Can运行 ");
        }
        if (false == MyCANControlThread->IsOpenFlag)//启动设备失败
        {
            ui->statusbar->showMessage("CAN设备打开失败 ");
            MyCANControlThread->CloseCANThread();
            ui->bt_Connected->setText("连接");//
            MyCANControlThread->Reset();
            MyCANControlThread->stop();//停止子线程
            mconnect = _UnCnn;
        }
        else//启动设备成功
        {
            ui->statusbar->showMessage("CAN设备连接成功 ");
            ui->bt_Connected->setText("断开");//
            mconnect = _CanCnn;
        }
    }
    else
    {
        MyCANControlThread->Reset();
        //   MyCANControlThread->CloseCANThread();
        MyCANControlThread->stop();//停止子线程
        ui->statusbar->showMessage("CAN设备连接断开 ");
        ui->bt_Connected->setText("连接");//
        mconnect = _UnCnn;
    }
    emit signalDeviceCnnState("USBCAN-IIC+GC23070124", mconnect);
}

void drvmng::disConnect()
{
    mbtcp->modbus_disconnect();
    MyCANControlThread->Reset();
    //   MyCANControlThread->CloseCANThread();
    MyCANControlThread->stop();//停止子线程
    ui->statusbar->showMessage("CAN设备连接断开 ");
    ui->bt_Connected->setText("连接");//
    mconnect = _UnCnn;
    timer->stop();
    QThread::sleep(2);
}



/// <summary>
/// 接收标准帧后,进行消息分发处理
/// </summary>
/// <param name="rec_data"></param>
void drvmng::deal_can_rec(QString str, QByteArray data)
{ 
    uint8_t dr_src = 0;
    uint8_t dr_dst = 0;
    if (str == "CanDisCnn")
    {
        ui->statusbar->showMessage("CAN设备打开失败 ");
        ui->bt_Connected->setText("连接");//
        emit signalDeviceCnnState("USBCAN-IIC+GC23070124", false);
        return;
    }
    emit signalDebugMsg(str, data);
    BMU_CAN_RecData* getMsg = (BMU_CAN_RecData*)data.data();

#ifdef  New_J1939
   /// <summary>
   /// 从机数据判断
   /// </summary>
   /// <param name="str"></param>
   /// <param name="data"></param>
   if (dr_get_prio(getMsg->FrameId) == BMU_PRIO && dr_get_func(getMsg->FrameId) == 1 && dr_get_dest(getMsg->FrameId) == BCU_ADDR)
   {
       getMsg->FrameId = dr_get_src(getMsg->FrameId);
       emit  signalUpCanBMUMsg(str, data);//子线程处理完毕//触发自定义的信号
   }
   /// <summary>
   /// 主机数据判断
   /// </summary>
   /// <param name="str"></param>
   /// <param name="data"></param>
   else if ((dr_get_src(getMsg->FrameId) == BCU_ADDR))
   {
       emit  signalUpCanBCUMsg(dr_get_func(getMsg->FrameId), data);//子线程处理完毕//触发自定义的信号

   }
   else if ((dr_get_dest(getMsg->FrameId) == PC_ADDR) && (dr_get_prio(getMsg->FrameId) == PARAMETER_PRIO))
   {
       emit  signalUpCanBMUMngMsg(str, data);//子线程处理完毕//触发自定义的信号
   }


#else
   if (getMsg->FrameId > 0x300)
    {
        // 从机网络显示
       emit  signalUpCanBMUMsg(str, data);//子线程处理完毕//触发自定义的信号
    }
    else
    {
        // 主机网络显示
      emit  signalUpCanBCUMsg(getMsg->FrameId, data);
    }
#endif //  new_J1939

}
void drvmng::CanSnd(unsigned int id, unsigned char data_from_text[8], unsigned int len)
{
    if (mconnect != false)
    {
        QByteArray byteArray;
        Thread::StandFrame_Data  rec_standard_data;
        rec_standard_data.FrameId = id;
        memcpy(rec_standard_data.Data, data_from_text, 8);
        byteArray.append(reinterpret_cast<char*>(&rec_standard_data), sizeof(Thread::StandFrame_Data));
       emit signalDebugMsg("CanSnd", byteArray);//子线程处理完毕//触发自定义的信号
        MyCANControlThread->TransmitCANThread(id, (unsigned char*)data_from_text, mEXT, 0, len);
    }
}
void drvmng::StopThread()
{
    timer->stop();
    MyCANControlThread->stop();
}

void drvmng::StartThread()
{
    timer->start();
    MyCANControlThread->start();
    //unsigned char data_from_text[8] = { 0 };
    //data_from_text[1] = 0x20;
    //CanSnd(0x100, data_from_text);
}

void drvmng::mb_downmsg_holding(QString flag, uint address, QVector<quint16> val)
{
    if (flag == "Write")
    {
        if (mbtcp->modbus_write_holding(1, address, val.size(), val) == false)
        {
            QMessageBox::information(this, "", "send fali ");
        }
        else
        {
            QMessageBox::information(this, "", "write ok!!! ");
        }
    }
    else if (flag == "Read")
    {
        if (mbtcp->modbus_read_holding(1, address, val.size()) == false)
        {
            QMessageBox::information(this, "", "send fali ");
        }
        else
        {
            QMessageBox::information(this, "", "read ok!!! ");
        }
    }
}

_Drv_Status drvmng::drv_connect_state()
{ 
    return mconnect;
}

void drvmng::saveCfg()
{
    settings->setValue("IPSetting/IP", ipQstr);
    settings->setValue("IPSetting/Port", portQstr);
    //settings->setValue("CanSetting/Bound", ui->CB_Baud->currentText());
    //settings->setValue("CanSetting/ChannelNum", ui->comboBox_4->currentIndex());
}

uint8_t drvmng::dr_get_prio(uint32_t id)
{
    uint8_t value = (id & 0x3C000000) >> 26;
    return value;
}

uint8_t drvmng::dr_get_func(uint32_t id)
{
    uint8_t value = (id & 0xFF0000) >> 16;
    return value;
}

uint8_t drvmng::dr_get_dest(uint32_t id)
{
    uint8_t value = (id & 0xFF00) >> 8;
    return value;
}

uint8_t drvmng::dr_get_src(uint32_t id)
{
    uint8_t value = id & 0xFF;
    return value;
}

uint32_t drvmng::dr_make_can_ID(uint32_t prio, uint32_t function, uint32_t destAddr, uint32_t srcAddr)
{
    return (prio << 26) | (function << 16) | (destAddr << 8) | srcAddr;
}


void drvmng::slot_read_dataunit(QModbusDataUnit DataUnit)
{
    QVector<quint16> vAllData = DataUnit.values();
    for (int i = 0; i < DataUnit.valueCount(); i++)
    {
        vAllData[i] = vAllData[i] << 8 | vAllData[i] >> 8;
    }
    memcpy(&m_run_state_base, (uint8_t*)&vAllData[0], DataUnit.valueCount()* sizeof(quint16));
}

void drvmng:: SlotsDownMsgComing(QString flag, uint address, QVector<quint16> val)
{
    if (flag=="Write")
    {
        if (mbtcp->modbus_write_holding(1, address, val.size()*2, val) == false)
        {
            QMessageBox::information(this, "", "send fali ");
        }
        else
        {
            QMessageBox::information(this, "", "write ok!!! ");
        }
    }
    else if (flag == "Read")
    {
        if (mbtcp->modbus_read_holding(1, address, val.size()) == false)
        {
            QMessageBox::information(this, "", "send fali ");
        }
        else
        {
            QMessageBox::information(this, "", "read ok!!! ");
        }
    }
}

void drvmng::slot_read_holding(QModbusDataUnit DataUnit)
{
    QCoreApplication::processEvents();
    QVector<quint16> vAllData = DataUnit.values();

    QString uuid = QString::fromLocal8Bit((char*)&m_dev_info.uuid[0], 16);
    switch (DataUnit.startAddress())
    {
    case MODBUS_SYSTEM_BASE:
        memcpy(&m_dev_info, (uint8_t*)&vAllData[0], DataUnit.valueCount());
        mbtcp->modbus_read_holding(1, MODBUS_BATTERY_BASE, sizeof(BATTERY_CFG_s));
        emit signalUpTCPBCUMsg(DataUnit.startAddress(), vAllData);
        break;
    case MODBUS_BATTERY_BASE:
        memcpy(& m_battery_base, (uint8_t*)&vAllData[0], DataUnit.valueCount());
        SlaveCount = m_battery_base.modulesCountPerString; //从机的个数
        VoltCntPerSlave = m_battery_base.cellsCountPerModule; // 每一个从机有多少个电压
        TempCntPerSlave = m_battery_base.tempsCountPerModule;  // 每一个从机有多少温度
        // 获取从机BMU的信息
        emit signalUpReadHolding(DataUnit.startAddress(), vAllData);

        for (int i = 0; i < SlaveCount; i++)
        {

            mbtcp->modbus_read_holding(1, MODBUS_BMU_BASE+ i* sizeof(_BMU_DEV_INFO_s)/2, sizeof(_BMU_DEV_INFO_s)/2);
        }
        if (timer->isActive()==false)
        {
            emit signalUpTCPBMUMsg(DataUnit.startAddress(), vAllData);
            timer->start();
        }
        break;
    case MODBUS_RUN_STATE_BASE:
        emit signalUpTCPBCUMsg(DataUnit.startAddress(), vAllData);
       // emit signalUpAlarmLogMsg(ipQstr, uuid, vAllData);
        break;
    case MODBUS_RUN_STATE_BASE_2:
        emit signalUpTCPBCUMsg(DataUnit.startAddress(), vAllData);
        emit signalUpAlarmLogMsg(ipQstr, uuid, vAllData);
        break;
    case MODBUS_S_VOLT_BASE:
    case MODBUS_S_VOLT_BASE+ BS_NR_OF_CELL_BLOCKS_PER_MODULE*1:
    case MODBUS_S_VOLT_BASE + BS_NR_OF_CELL_BLOCKS_PER_MODULE*2:
    case MODBUS_S_VOLT_BASE + BS_NR_OF_CELL_BLOCKS_PER_MODULE*3:
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
        emit signalUpTCPBMUMsg(DataUnit.startAddress(), vAllData);
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
        emit signalUpTCPBMUMsg(DataUnit.startAddress(), vAllData);
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
        emit signalUpTCPBMUMsg(DataUnit.startAddress(), vAllData);
        break;
    case MODBUS_BMU_BASE:
    case MODBUS_BMU_BASE+ 1*sizeof(_BMU_DEV_INFO_s)/2  :
    case MODBUS_BMU_BASE + 2*sizeof(_BMU_DEV_INFO_s)/2:
    case MODBUS_BMU_BASE + 3 * sizeof(_BMU_DEV_INFO_s)/2:
    case MODBUS_BMU_BASE + 4*sizeof(_BMU_DEV_INFO_s)/2:
    case MODBUS_BMU_BASE + 5*sizeof(_BMU_DEV_INFO_s)/2:
    case MODBUS_BMU_BASE + 6*sizeof(_BMU_DEV_INFO_s)/2:
    case MODBUS_BMU_BASE + 7*sizeof(_BMU_DEV_INFO_s)/2:
    case MODBUS_BMU_BASE + 8*sizeof(_BMU_DEV_INFO_s)/2:
    case MODBUS_BMU_BASE + 9*sizeof(_BMU_DEV_INFO_s)/2:
    case MODBUS_BMU_BASE + 10*sizeof(_BMU_DEV_INFO_s)/2:
    case MODBUS_BMU_BASE + 11*sizeof(_BMU_DEV_INFO_s)/2:
    case MODBUS_BMU_BASE + 12*sizeof(_BMU_DEV_INFO_s)/2:
    case MODBUS_BMU_BASE + 13*sizeof(_BMU_DEV_INFO_s)/2:
    case MODBUS_BMU_BASE + 14*sizeof(_BMU_DEV_INFO_s)/2:
    case MODBUS_BMU_BASE + 15*sizeof(_BMU_DEV_INFO_s)/2:
    //    memcpy(&m_bmu_dev_info[0], (uint8_t*)&vAllData[0], DataUnit.valueCount());
    //    mbtcp->modbus_read_holding(1, MODBUS_S_VOLT_BASE, BS_NR_OF_CELL_BLOCKS_PER_MODULE);
        emit signalUpTCPBMUMsg(DataUnit.startAddress(), vAllData);
        break;
    default:
       emit signalUpReadHolding(DataUnit.startAddress(), vAllData);
        break;
    }
}

   

