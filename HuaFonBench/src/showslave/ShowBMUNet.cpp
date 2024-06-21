#include "ShowBMUNet.h"
#include <src/showslave/ShowBMUNetItem.h>
#include "showslave.h"
#include <src/drvmng/modbus_params.h>
#include <src/drvmng/drvmng.h>
extern _PackDetailInfoST     g_PackDetailInfoST[MAX_BMU_NUM];
extern _F0DevInfo            g_DevInfo[MAX_BMU_NUM];
ShowBMUNet::ShowBMUNet(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void ShowBMUNet::UpdateBmuItemUi()
{
    VoltageDataUpdate(g_PackDetailInfoST[SlectBmuID].BatVols);
    TempDataUpdate(g_PackDetailInfoST[SlectBmuID].BatTemps);
    BlanceStatusUpdate(g_PackDetailInfoST[SlectBmuID].BmuStatus.balanceState);
    CnnStatusUpdate(g_PackDetailInfoST[SlectBmuID].BmuStatus.cellOpenWire);

    lbpcbTemp->setText("PCB温度:" + QString::number(g_PackDetailInfoST[SlectBmuID].BmuStatus.pcbTemperature_ddegC * 0.1) + " °");
    lbblanceTemp->setText("均衡温度:" + QString::number(g_PackDetailInfoST[SlectBmuID].BmuStatus.balanceTemperature_ddegC * 0.1) + " °");

    BatPlusTemp->setText("电池温度+:" + QString::number(g_PackDetailInfoST[SlectBmuID].BmuStatus.batPositiveTemperature_ddegC * 0.1) + " °");
    BatMinusTemp->setText("电池温度-:" + QString::number(g_PackDetailInfoST[SlectBmuID].BmuStatus.batNegativeTemperature_ddegC * 0.1) + " °");
    //CopperBarScrewTempI->setText("螺柱1温度:" + QString::number(g_PackDetailInfoST[SlectBmuID].BatTemps[44] * 0.1) + " °");
    //CopperBarSerewTempII->setText("螺柱2温度:" + QString::number(g_PackDetailInfoST[SlectBmuID].BatTemps[45] * 0.1) + " °");
    fan->SetTip("风扇转速:" + QString::number(g_PackDetailInfoST[SlectBmuID].FanSpeed));
    uint8_t sp = 0;
    if (g_PackDetailInfoST[SlectBmuID].FanSpeed == 0)
    {
        sp = 0;
    }
    else
    {
       sp = 3800 / g_PackDetailInfoST[SlectBmuID].FanSpeed;
    }
    fan->speedset(sp);
}


ShowBMUNet::ShowBMUNet(uint8_t BmuId,QWidget* parent) : QWidget(parent)
{
    ui.setupUi(this);
    SlectBmuID= BmuId;
    this->setWindowTitle("PackID:"+QString::number(SlectBmuID+1));
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(UpdateBmuItemUi()));
    timer->start(1000);//start之后,每隔一秒触发一次槽函数
    SlaveItemInit();
    this->setAttribute(Qt::WA_DeleteOnClose);
}

ShowBMUNet::~ShowBMUNet()
{
    deleteLater();
}

void ShowBMUNet::SlaveItemInit()
{
    QList<QHBoxLayout*>* HlayoutList = new QList<QHBoxLayout*>();
    QVBoxLayout* VLayout = new QVBoxLayout();
    QHBoxLayout* HLayout1 = new QHBoxLayout();// 总信息

    QHBoxLayout* HLayoutSoftInfo = new QHBoxLayout();// 总信息
    QLabel* lbSV = new QLabel();
    QLabel* lbHV = new QLabel();
    QLabel* lbUUID = new QLabel();
    QLabel* lbSN = new QLabel();
    QLabel* lbBootV = new QLabel();
    lbSV->setStyleSheet("color:#ffffff");
    lbHV->setStyleSheet("color:#ffffff");
    lbUUID->setStyleSheet("color:#ffffff");
    lbSN->setStyleSheet("color:#ffffff");
    lbBootV->setStyleSheet("color:#ffffff");

    //lbSV->setText("软件版本:V0.0.0");
    //lbHV->setText("硬件版本:V0.0.0");
    //lbBootV->setText("Boot版本:V0.0.0");

    //lbUUID->setText("UUID:XXXXXXXXXX");
    //lbSN->setText("Sn:XXXXXXXXXX");
    QString softver;
    QString hwver;
    QString SnVer;
    for (int i = 0; i < 3; i++)
    {
        softver += QString::number(g_PackDetailInfoST[SlectBmuID].BmuInfo.SoftWareVerion[i], 10);
        hwver += QString::number(g_PackDetailInfoST[SlectBmuID].BmuInfo.HardWareVerion[i],  10);
    }
    softver += g_PackDetailInfoST[SlectBmuID].BmuInfo.SoftWareVerion[3];
    
    lbSV->setText("软件版本: V"+ softver);
    lbHV->setText("硬件版本: V" + hwver);

    for (int k = 0; k < 16; k++)
    {
        SnVer += QString::number(g_PackDetailInfoST[SlectBmuID].BmuInfo.SN[k], 16);
    }
    lbSN->setText("SN: " + SnVer);
    QString UUID;
    for (int k = 0; k < 16; k++)
    {
        UUID += QString::number(g_PackDetailInfoST[SlectBmuID].BmuInfo.UUID[k], 16);
    }

    lbUUID->setText("UUID: " + UUID);


    HLayoutSoftInfo->addWidget(lbSV);
    HLayoutSoftInfo->addWidget(lbHV);
    HLayoutSoftInfo->addWidget(lbUUID);
    HLayoutSoftInfo->addWidget(lbSN);
    HLayoutSoftInfo->addWidget(lbBootV);

    VLayout->addLayout(HLayoutSoftInfo);
    // Cell总数添加到列表
    for (int i = 0; i < SlaveNum; i++)
    {
        ShowBMUNetItem* item = new ShowBMUNetItem(i);
     //   item->setFixedSize(QSize(450, 150));
        item->setStyleSheet(QString("border: 1px solid #323232; \
                                        border-radius:0px;  \
                                        padding:0px 0px;  \
                                        background-color:#267400;"));
        this->m_ItemList.push_back(item);
    }
    //计算行数
     row = SlaveNum / Colunm;

     lbv = new QLabel();
   //  lbv->setFixedSize(QSize(150, 50));
     lbv->setStyleSheet("color:#ffffff");
     lbv->setText("总电压:0V");

    fan = new QtWidgetsFan();
    fan->setFixedSize(QSize(200, 100));

    QMenu* menu = new QMenu(this);
    menu->addAction(tr("开启"), this, &ShowBMUNet::UpdateBmuItemUi, 1);
    menu->addAction(tr("111"), this, &ShowBMUNet::UpdateBmuItemUi, 1);
    menu->addAction(tr("222"), this, &ShowBMUNet::UpdateBmuItemUi, 1);
    menu->setStyleSheet("QMenu {background-color: #435; border: 1px solid #ccc;}");
    fan->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(fan, &QWidget::customContextMenuRequested, [this, menu](const QPoint& pos) {

        menu->exec(this->mapToGlobal(pos));
        }
    );
     lbpcbTemp = new QLabel();
   //  lbpcbTemp->setFixedSize(QSize(150, 50));
     lbpcbTemp->setStyleSheet("color:#ffffff");
     lbpcbTemp->setText("PCB温度:0°");


     lbblanceTemp = new QLabel();
   //  lbblanceTemp->setFixedSize(QSize(150, 50));
     lbblanceTemp->setStyleSheet("color:#ffffff");
     lbblanceTemp->setText("均衡温度:0°");

     //QLabel* BatPlusTemp;
     //QLabel* BatMinusTemp;
     //QLabel* CopperBarScrewTempI;
     //QLabel* CopperBarSerewTempII;


     BatPlusTemp = new QLabel();
  //   BatPlusTemp->setFixedSize(QSize(150, 50));
     BatPlusTemp->setStyleSheet("color:#ffffff");
     BatPlusTemp->setText("电池+温度:0°");


     BatMinusTemp = new QLabel();
 //    BatMinusTemp->setFixedSize(QSize(150, 50));
     BatMinusTemp->setStyleSheet("color:#ffffff");
     BatMinusTemp->setText("电池-温度:0°");

  //   CopperBarScrewTempI = new QLabel();
  // //  CopperBarScrewTempI->setFixedSize(QSize(150, 50));
  //   CopperBarScrewTempI->setStyleSheet("color:#ffffff");
  //   CopperBarScrewTempI->setText("螺柱1温度:0°");

  //   CopperBarSerewTempII = new QLabel();
  ////   CopperBarSerewTempII->setFixedSize(QSize(150, 50));
  //   CopperBarSerewTempII->setStyleSheet("color:#ffffff");
  //   CopperBarSerewTempII->setText("螺柱2温度:0°");


     QLabel* lbs = new QLabel();
     //lbs->setFixedSize(QSize(150, 50));
     lbs->setText("状态:正常");
     lbs->setStyleSheet("color:#ffffff");
     HLayout1->addWidget(fan);
     HLayout1->addWidget(lbv);
     HLayout1->addWidget(lbpcbTemp);
     HLayout1->addWidget(lbblanceTemp);
     HLayout1->addWidget(lbs);

     HLayout1->addWidget(BatPlusTemp);
     HLayout1->addWidget(BatMinusTemp);
     //HLayout1->addWidget(CopperBarScrewTempI);
     //HLayout1->addWidget(CopperBarSerewTempII);



    for (int k = 0; k < row; k++)
    {
        QHBoxLayout* HLayout = new QHBoxLayout();
        for (int i = 0; i < Colunm; i++)
        {
           // HLayout->setObjectName("BMUItem");
            HLayout->setContentsMargins(5, 5, 5, 5);
            HLayout->addWidget(this->m_ItemList[i+k* Colunm]);
            HLayout->setStretch(i, 20);
           // HLayout->addStretch();
        }
        HlayoutList->push_back(HLayout);
        VLayout->addLayout(HlayoutList[0].back());
        VLayout->setStretch(k+1, 20);
    }
    VLayout->addLayout(HLayout1);
    QGroupBox* buttonGroup = new QGroupBox();
    buttonGroup->setLayout(VLayout);
    this->setStyleSheet(QString("border: 1px solid #323232; \
                                    border-radius:0px;  \
                                    padding:0px 0px;  \
                                    background-color:#001d4f;"));
    this->setLayout(VLayout); 
    CreatFanMenu();
}

void ShowBMUNet::VoltageDataUpdate(uint16_t *volt)
{
    uint8_t maxVId=0;
    uint8_t MinVid=0;
    uint16_t MaxVal;
    uint16_t MinVal;
    float TalVal =0;
    MaxVal = volt[0];
    MinVal = volt[0];
    if ((volt == nullptr))
        return;
    for (int i =0;i< VoltSensorNum;i++)
    {
      //  QCoreApplication::processEvents();
        TalVal += volt[i];
        m_ItemList[i]->SetVoltageVal(volt[i]);
        if (MaxVal < volt[i])
        {
            MaxVal = volt[i];
            maxVId = i;
        }
        if (MinVal > volt[i])
        {
            MinVal = volt[i];
            MinVid = i;
        }
         m_ItemList[i]->IsMaxVolt(false);
         m_ItemList[i]->IsMinVolt(false);
    }
    m_ItemList[maxVId]->IsMaxVolt(true);
    m_ItemList[MinVid]->IsMinVolt(true);
    

    lbv->setText("总电压:"+QString::number(TalVal*0.001)+" V");
}

void ShowBMUNet::VersionUpdate()
{
    //g_DevInfo->SoftWareVerion;
    //g_DevInfo->SoftWareVerion;
    //g_DevInfo->SoftWareVerion;
}

void ShowBMUNet::TempDataUpdate(int16_t *Temp)
{
    if ((Temp == nullptr))
        return;
    uint8_t maxVId = 0;
    uint8_t MinVid = 0;
    int16_t MaxVal;
    int16_t MinVal;
    MaxVal = Temp[0];
    MinVal = Temp[0];
    for (int i = 0; i < TemptureSensorNum; i++)
    {
        m_ItemList[i]->SetTempVal(Temp[i]);
        if (MaxVal < Temp[i])
        {
            MaxVal = Temp[i];
            maxVId = i;
        }
        if (MinVal > Temp[i])
        {
            MinVal = Temp[i];
            MinVid = i;
        }
        m_ItemList[i]->IsMaxTemp(false);
        m_ItemList[i]->IsMinTemp(false);
    }
    m_ItemList[maxVId]->IsMaxTemp(true);
    m_ItemList[MinVid]->IsMinTemp(true);
}

void ShowBMUNet::BlanceStatusUpdate(uint64_t Blance)
{
    for (int i = 0; i < SlaveNum; i++)
    {
         uint8_t sta= (Blance >> i)&0x1;
        // QCoreApplication::processEvents();
        m_ItemList[i]->SetBlanceVal(sta);
    }
}

void ShowBMUNet::CnnStatusUpdate(uint64_t Status)
{
    for (int i = 0; i < SlaveNum; i++)
    {
        uint8_t sta = (Status >> i) & 0x1;
        // QCoreApplication::processEvents();
        m_ItemList[i]->SetCnnVal(sta);
    }
}


void ShowBMUNet::CreatFanMenu()
{
    m_pMenuRD = new QMenu(this);
    m_pMenuRD->setStyleSheet("QMenu { color: yellow; }");
    QMenu* pMenuFanSwtich = new QMenu(this);
    QMenu* pMenuFanSpeed = new QMenu(this);
    QMenu* pMenuFanType = new QMenu(this);
    QMenu* PackLineStyle = new QMenu(this);

    pMenuFanSwtich->setStyleSheet("QMenu { color: yellow; }");
    pMenuFanSpeed->setStyleSheet("QMenu { color: yellow; }");
    pMenuFanType->setStyleSheet("QMenu { color: yellow; }");
    PackLineStyle->setStyleSheet("QMenu { color: yellow; }");

    pMenuFanSwtich->setTitle(tr("风扇控制"));
        QAction* m_pActionTestV = pMenuFanSwtich->addAction(tr("开启"));
        m_pActionTestV->setChecked(true);
    
        QAction* m_pActionTestV1 = pMenuFanSwtich->addAction(tr("关闭"));
        m_pActionTestV1->setChecked(true);


    m_pMenuRD->addMenu(pMenuFanSwtich);

    pMenuFanSpeed->setTitle(tr("风扇调速"));

    for (int i = 1; i < 6; i++)
    {
        pMenuFanSpeed->addAction(tr("速度档位-") + QString::number(i, 10));
    }
    m_pMenuRD->addMenu(pMenuFanSpeed);

    pMenuFanType->setTitle(tr("风扇类型"));
    QAction* FanType1 = pMenuFanType->addAction(tr("PWM周期内高电平驱动"));
    FanType1->setChecked(true);

    QAction* FanType2 = pMenuFanType->addAction(tr("PWM周期内低电平驱动"));
    FanType1->setChecked(true);

    m_pMenuRD->addMenu(pMenuFanType);

    PackLineStyle->setTitle(tr("PACK线束装配方式"));
    QAction* QAPackLine1 = PackLineStyle->addAction(tr("西安测试版本"));
    FanType1->setChecked(true);

    QAction* QAPackLine2 = PackLineStyle->addAction(tr("产线CCS版本"));
    FanType1->setChecked(true);

    QAction* QAPackLine3 = PackLineStyle->addAction(tr("根绝ID_CRT_TEMP_POS动态适配"));
    FanType1->setChecked(true);

    m_pMenuRD->addMenu(PackLineStyle);

    connect(m_pMenuRD, SIGNAL(triggered(QAction*)), this, SLOT(SlotMenuClicked(QAction*)));
}

void ShowBMUNet::SetFanCtl(uint8_t ctl)
{
    uint32_t frameId = 0;
    unsigned char data_from_text[8] = { 0 };
    frameId = drvmng::getInstance().dr_make_can_ID(PARAMETER_PRIO, 0, SlectBmuID +1, PC_ADDR);

    data_from_text[0] = 00;
    data_from_text[1] = 0x19 | 0x80;
    data_from_text[2] = 2;//长度
   // Data 0: 0, 禁止FUN TEST.1 使能FUN TEST
    data_from_text[3] = 1;//长度
    //Data 1:0，FAN打开；1，FAN关闭
    data_from_text[4] = ctl;//0:开 1：关
    drvmng::getInstance().CanSnd(frameId, data_from_text, 5);
}

void ShowBMUNet::SetFanSpeed(uint16_t speed)
{
    uint32_t frameId = 0;
    unsigned char data_from_text[8] = { 0 };
    frameId = drvmng::getInstance().dr_make_can_ID(PARAMETER_PRIO, 0, SlectBmuID +1, PC_ADDR);

    data_from_text[0] = 0x04;
    data_from_text[1] = 0x19 | 0x80;
    data_from_text[2] = 2;//长度
    data_from_text[4] = speed>>8;//长度
    data_from_text[3] = speed&0xff;//0:开 1：关
    drvmng::getInstance().CanSnd(frameId, data_from_text, 5);
}

void ShowBMUNet::SetFanType(uint16_t type)
{
    uint32_t frameId = 0;
    unsigned char data_from_text[8] = { 0 };
    frameId = drvmng::getInstance().dr_make_can_ID(PARAMETER_PRIO, 0, SlectBmuID + 1, PC_ADDR);

    data_from_text[0] = 0x13;
    data_from_text[1] = 0x10 | 0x80;
    data_from_text[2] = 2;//长度
    data_from_text[4] = type >> 8;//长度
    data_from_text[3] = type & 0xff;//0:开 1：关
    drvmng::getInstance().CanSnd(frameId, data_from_text, 5);

}

void ShowBMUNet::SetLineStyle(uint16_t style)
{
    uint32_t frameId = 0;
    unsigned char data_from_text[8] = { 0 };
    frameId = drvmng::getInstance().dr_make_can_ID(PARAMETER_PRIO, 0, SlectBmuID + 1, PC_ADDR);

    data_from_text[0] = 0x14;
    data_from_text[1] = 0x10 | 0x80;
    data_from_text[2] = 2;//长度
    data_from_text[4] = style >> 8;//长度
    data_from_text[3] = style & 0xff;//0:开 1：关
    drvmng::getInstance().CanSnd(frameId, data_from_text, 5);

}

void ShowBMUNet::SetTempChannelGPIOPort(uint16_t TempChannel, uint16_t GpioPort)
{

    uint32_t frameId = 0;
    unsigned char data_from_text[8] = { 0 };
    frameId = drvmng::getInstance().dr_make_can_ID(PARAMETER_PRIO, 0, SlectBmuID + 1, PC_ADDR);

    data_from_text[0] = 0x0F;
    data_from_text[1] = 0x10 | 0x80;
    data_from_text[2] = 2;//长度
    data_from_text[4] = TempChannel;//长度
    data_from_text[3] = GpioPort ;//0:开 1：关
    drvmng::getInstance().CanSnd(frameId, data_from_text, 5);

}




void ShowBMUNet::SlotMenuClicked(QAction* action)
{
    QString str = action->text();
    if (str == "开启")
    {
        SetFanCtl(1);
        fan->start();
    }
    else if (str == "关闭")
    {
        SetFanCtl(0);
        fan->stop();
    }
    else if(str.contains("-"))
    {
        bool ok;
        QStringList list = str.split("-");
        SetFanSpeed(3700/ (list[1].toInt(&ok, 10)));
        //fan->speedset(list[1].toInt(&ok, 10)*15);
        action->setChecked(true);
        action->setEnabled(true);
    }
    else if (str.contains("PWM周期内高电平驱动"))
    {
        SetFanType(0);
    }
    else if (str.contains("PWM周期内低电平驱动"))
    {
        SetFanType(1);
    }
    else if (str.contains("西安测试版本"))
    {
        SetLineStyle(0);
    }
    else if (str.contains("产线CCS版本"))
    {
        SetLineStyle(1);
    }
    else if (str.contains("根绝ID_CRT_TEMP_POS动态适配"))
    {
        SetLineStyle(2);
    }
}








void ShowBMUNet::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::RightButton)
    {
        m_pMenuRD->exec(QCursor::pos());
    }
}