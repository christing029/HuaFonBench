
#include <QTextEdit>
#include <QAbstractButton>
#include "SARibbonBar.h"
#include "SARibbonCategory.h"
#include <QPushButton>
#include "SARibbonPannel.h"
#include "SARibbonToolButton.h"
#include <QAction>
#include <QMenu>
#include <QDebug>
#include <QElapsedTimer>
#include "SARibbonMenu.h"
#include "SARibbonComboBox.h"
#include "SARibbonLineEdit.h"
#include "SARibbonGallery.h"
#include "SARibbonCheckBox.h"
#include "SARibbonQuickAccessBar.h"
#include "SARibbonButtonGroupWidget.h"
#include <QElapsedTimer>
#include <QFileDialog>
#include <QLabel>
#include <QProcess>
#include <QStatusBar>
#include "mainwindow.h"
#include "src/slavemng/FaultInjection.h"
#define PRINT_COST(ElapsedTimer,LastTime,STR) \
do{\
        int ___TMP_INT = ElapsedTimer.elapsed();\
        qDebug() << STR << ___TMP_INT - LastTime << "(" << ___TMP_INT << ")";\
        LastTime = ___TMP_INT;\
}while(0)
 MainWindow::MainWindow(QWidget *par):SARibbonMainWindow(par)
{
    QFile file(":/qss/HF.qss");
    if (!file.open(QIODevice::ReadOnly))
    {
        qWarning("Can't open the style sheet file.");
     //   return;
    }
    QString qss = QLatin1String(file.readAll());
   //  this->setStyleSheet(qss);
    file.close();
    SARibbonBar* ribbon = ribbonBar();
    QFont ft = ribbon->font();
    ft.setPointSize(15);
    ribbon->setFont(ft);
    this->setWindowTitle(QStringLiteral(" 华峰储能自动化测试系统 "));
   // ribbon->applitionButton()->setText(QStringLiteral("开始"));
    SARibbonToolButton* btstart = ribbon->quickAccessBar()->addButton(new QAction(QIcon(":/icon/startall.ico"),"测试开始",this));
    QObject::connect(btstart, &QPushButton::clicked, []() {
        drvmng::getInstance().StartThread();
        });
    SARibbonToolButton *btstop=  ribbon->quickAccessBar()->addButton(new QAction(QIcon(":/icon/stopall.png"),"测试暂停",this));
    QObject::connect(btstop, &QPushButton::clicked, []() {
        drvmng::getInstance().StopThread();
        });
    
    ribbon->quickAccessBar()->addButton(new QAction(QIcon(":/icon/k2.ico"),"白色风格",this));
   // ribbon->quickAccessBar()->addButton(new QAction(QIcon(":/icon/k3.ico"),"action4",this));

    SARibbonCategory* category0 = ribbon->addCategoryPage(QStringLiteral("系统管理"));
    createCategorySysMng(category0);
    SARibbonCategory* category1 = ribbon->addCategoryPage(QStringLiteral("主从配置"));
    createCategoryDevMng(category1);
    SARibbonCategory* category2 = ribbon->addCategoryPage(QStringLiteral("测试场景"));
    createCategoryTestMng(category2);
    SARibbonCategory* category3 = ribbon->addCategoryPage(QStringLiteral("结果分析"));
    createCategoryResultDes(category3);
    SARibbonCategory* category4 = ribbon->addCategoryPage(QStringLiteral("帮助信息"));
    createCategorySYSHelp(category4);

   // ribbon->quickAccessBar()->addButton(new QAction(QIcon(":/icon/icon/save.png"),"action1",this));

    m_contextCategory = ribbon->addContextCategory(QStringLiteral("context"),Qt::red,1);

    /// 状态栏
     statusbar = new QStatusBar(ribbon);
    statusbar->setMinimumHeight(50);
    labelStsInfo = new QLabel();
    labelStsIP = new QLabel();
    labelStsIco = new QLabel();
    //labelStsStatus = new QLabel();
    pBtnStsConnect = new QPushButton();
    // 新建图标信息（路径为资源文件路径，请自行添加）
     disconnectIco= new QPixmap(":/icon/globes_red.png");
     connectIco = new QPixmap(":/icon/globes_green.png");
    QFont font("Microsoft YaHei", 8);
    // 获取IP+端口信息：
    QString ipQstr = "USBCAN-IIC+";
    QString portQstr = "GC23070124";
    // 添加提示信息标签
    labelStsInfo->setMinimumWidth(this->width()/ 2);
    labelStsInfo->setFont(font);
    statusbar->addWidget(labelStsInfo);
    // 添加机械臂控制器连接标签、按钮、图标、状态
    labelStsIP->setMinimumWidth(120);
    labelStsIP->setText("[IP] "+ipQstr+":"+ portQstr);
    labelStsIP->setFont(font);
    labelStsIP->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    statusbar->addPermanentWidget(labelStsIP);

    labelStsIco->setMaximumSize(20, 20);
    labelStsIco->setScaledContents(true);
    labelStsIco->setPixmap(*disconnectIco);
    statusbar->addPermanentWidget(labelStsIco);

    pBtnStsConnect->setFixedSize(88, 20);
    pBtnStsConnect->setText("断开");
    pBtnStsConnect->setFont(font);
    statusbar->addPermanentWidget(pBtnStsConnect);

    //labelStsStatus->setMinimumWidth(120);
    //labelStsStatus->setText("Connect");
    //labelStsStatus->setFont(font);
    //statusbar->addPermanentWidget(labelStsStatus);
    statusbar->showMessage(QStringLiteral("浙江华峰储能科技有限公司版权所有---2023年10月1日"));
    setStatusBar(statusbar);
    this->resize(1200,800);
    showNormal();
    setWindowFlags(Qt::FramelessWindowHint);

   m_showbmu = new ShowSlave;
   m_mastermng = new MasterMng();
  
   connect(&drvmng::getInstance(), SIGNAL(signalUpMbMsg(QString,uint, QVector<quint16>)), m_mastermng, SLOT(SlotsUpMbMsgComing(QString,uint, QVector<quint16>)));
   connect(&drvmng::getInstance(), SIGNAL(signalUpReadHolding(uint, QVector<quint16>)), m_mastermng, SLOT(slotsUpReadHolding(uint, QVector<quint16>)));
  
   m_showbcu = new ShowBCU();
   connect(&drvmng::getInstance(), SIGNAL(signalUpCanBCUMsg(uint, QByteArray)), m_showbcu, SLOT(SlotsCanUpBCUMsg(uint, QByteArray)));
   connect(&drvmng::getInstance(), SIGNAL(signalUpReadHolding(uint, QVector<quint16>)), m_showbcu, SLOT(slotsUpReadHolding(uint, QVector<quint16>)));
   connect(&drvmng::getInstance(), SIGNAL(signalUpTCPBCUMsg(uint, QVector<quint16>)), m_showbcu, SLOT(SlotsUpMBShowBcu(uint, QVector<quint16>)));
   connect(&drvmng::getInstance(), SIGNAL(signalDeviceCnnState(QString, bool)), this, SLOT(slotsDeviceCnnState(QString, bool)));

   m_slavemng = new SlaveMng();

   connect(&drvmng::getInstance(), SIGNAL(signalUpCanBMUMsg(QString, QByteArray)), m_showbmu, SLOT(SlotsCanUpBMUMsg(QString, QByteArray)));
   connect(&drvmng::getInstance(), SIGNAL(signalUpCanBMUMngMsg(QString, QByteArray)), m_slavemng, SLOT(SlotsCanUpBMUMsg(QString, QByteArray)));

   connect(&drvmng::getInstance(), SIGNAL(signalUpTCPBMUMsg(uint, QVector<quint16>)), m_showbmu, SLOT(slotsUpTCPBMUMsg(uint, QVector<quint16>)));
   // debug
   connect(&drvmng::getInstance(), SIGNAL(signalDebugMsg(QString, QByteArray)), this, SLOT(slotsDebugMsg(QString, QByteArray)));
   m_alarmlog = new HistoryAlarmLog();
   connect(&drvmng::getInstance(), SIGNAL(signalUpAlarmLogMsg(QString, QString, QVector<quint16>)), m_alarmlog, SLOT(slotsStatuslogMsg(QString, QString, QVector<quint16>)));
   m_debugdata = new DebugLog;
   this->takeCentralWidget();
   setCentralWidget(m_showbmu);
}

void MainWindow::onShowContextCategory(bool on)
{
    ribbonBar()->setContextCategoryVisible(m_contextCategory,on);
}

void MainWindow::onAgentUserMng()
{

    usermng   *user;
    user = new usermng ;
    this->takeCentralWidget();
    setCentralWidget(user);
}
void MainWindow::onAgentDeviceMng()
{
    drvmng::getInstance().show();
    //setCentralWidget(&m_drvmng);
}

void MainWindow::onAgentDeviceFind()
{
    deviceFind* user;
    user = new deviceFind;
    this->takeCentralWidget();
    setCentralWidget(user);
  
}



//| 1 | 主控（二级主控，低压并机主机） | 0x100~0x19F | 预留160个ID |
//| -- - | -- - | -- - | -- - |
//| 2 | 高压控制模块（暂无，预留） | 0x1A0~0x1AF | 预留16个ID |
//| 3 | 从机（设置参数） | 0x200~0x2FF | 预留256个ID |
//| 4 | 从机（上报信息） | 0x300~0x3FF | 预留256个ID |
//| 外部扩展模块 |  |  |  |
//| 5 | 外部设置控制模块（PC，其他） | 0x400~0x49F | 预留256个ID |

MainWindow::~MainWindow()
{
    drvmng::release();
    delete m_showbmu;
    delete m_debugdata;
    delete m_mastermng;
    delete m_showbcu;
    delete m_slavemng;
}

void MainWindow::closeEvent(QCloseEvent* e) {
    //窗口关闭时弹出的提示窗口
    QMessageBox msgBox;
    msgBox.setText("提示");
    msgBox.setInformativeText("确认退出?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
    if (ret == QMessageBox::Ok) {
        //若用户点击确认，则接收这个事件,当前窗口会关闭
    //   delete drvmng::getInstance().instance;
    //    e->accept();
    //    delete this;
       drvmng::getInstance().disConnect();
        QApplication::quit();
        e->accept();
    }
    else {
        //若用户点击取消，则忽略这个事件，当前窗口不会关闭
        e->ignore();
    }
}



void MainWindow::createCategorySysMng(SARibbonCategory *page)
{

    SARibbonPannel* pannel = page->addPannel(QStringLiteral("基本信息管理"));

    QAction* act = new QAction(this);
    act->setIcon(QIcon(":/icon/UserAccounts.png"));
    act->setText(QStringLiteral("用户登录管理"));
    pannel->addLargeAction(act);

    connect(act,&QAction::triggered,this,&MainWindow::onAgentUserMng);


    act = new QAction(this);
    act->setIcon(QIcon(":/icon/Phone.png"));
    act->setText(QStringLiteral("设备发现"));
    pannel->addLargeAction(act);
    connect(act, &QAction::triggered, this, &MainWindow::onAgentDeviceFind);


    //act = new QAction(this);
    //act->setIcon(QIcon(":/icon/Phone.png"));
    //act->setText(QStringLiteral("测试设备管理"));
    //pannel->addLargeAction(act);
    // connect(act,&QAction::triggered,this,&MainWindow::onAgentDeviceMng);




    act = new QAction(this);
    act->setIcon(QIcon(":/icon/resultDes.png"));
    act->setText(QStringLiteral("设备升级"));
    pannel->addLargeAction(act);
    connect(act, &QAction::triggered, this, &MainWindow::onAgentDeviceUpdateMng);


    SARibbonPannel* pannel2 = page->addPannel(QStringLiteral("日志管理"));
    act = new QAction(this);
    act->setIcon(QIcon(":/icon/Calendar.png"));
    act->setText(QStringLiteral("操作日志"));
    pannel2->addLargeAction(act);
    
     connect(act,&QAction::triggered,this,&MainWindow::onLoggerMng);

    act = new QAction(this);
    act->setIcon(QIcon(":/icon/GanttView.png"));
    act->setText(QStringLiteral("调试日志"));
    pannel2->addLargeAction(act);

   connect(act,&QAction::triggered,this,&MainWindow::onDebugLogger);


   m_checkBox = new SARibbonCheckBox(this);
   m_checkBox->setSizePolicy(QSizePolicy::Expanding,
       QSizePolicy::Fixed);
   m_checkBox->setWindowIcon(QIcon(":/icon/icon/folder.png"));
   m_checkBox->setText(QStringLiteral("调试使能"));
   pannel2->addWidget(m_checkBox);


   SARibbonPannel* pannel32 = page->addPannel(QStringLiteral("设备管理"));
   Connact = new QAction(this);
   Connact->setIcon(QIcon(":/icon/Phone.png"));
   Connact->setText(QStringLiteral("连接"));
   pannel32->addLargeAction(Connact);


   QSettings  *settings = new QSettings("setting.ini", QSettings::IniFormat);

  // ui->PortlineEdit->setText(settings->value("IPSetting/Port").toString());
  // ui->CB_Baud->setEditText(settings->value("CanSetting/Bound").toString());
  // ui->comboBox_4->setCurrentIndex(settings->value("CanSetting/ChannelNum").toInt());


   m_rb = new QRadioButton(this);
   QRadioButton* m_rb_2 = new QRadioButton(this);

   m_rb->setSizePolicy(QSizePolicy::Expanding,
       QSizePolicy::Fixed);
   m_rb->setWindowIcon(QIcon(":/icon/Phone.png"));
   m_rb->setText(QStringLiteral("以太网通讯"));
   m_rb->setChecked(true);
   pannel32->addWidget(m_rb);
   m_ip = new SARibbonLineEdit(this);
   m_ip->setText(settings->value("IPSetting/IP").toString());
   QPalette palette;
   palette.setColor(QPalette::Text, Qt::red);
   m_ip->setPalette(palette);
   pannel32->addWidget(m_ip);

   can_channle = new SARibbonComboBox(this);
   pannel32->addWidget(can_channle);
   can_channle->addItem(QStringLiteral("通道一"));
   can_channle->addItem(QStringLiteral("通道二"));
   m_rb_2->setSizePolicy(QSizePolicy::Expanding,
       QSizePolicy::Fixed);
   m_rb_2->setWindowIcon(QIcon(":/icon/Phone.png"));
   m_rb_2->setText(QStringLiteral("CAN通讯"));
   pannel32->addWidget(m_rb_2);
   connect(Connact, &QAction::triggered, this, &MainWindow::onConnecttriggered);




    SARibbonPannel* pannel3 = page->addPannel(QStringLiteral("常用功能"));
    act = new QAction(this);
    act->setIcon(QIcon(":/icon/time.png"));
    act->setText(QStringLiteral("系统时间"));
    pannel3->addLargeAction(act);
    connect(act,&QAction::triggered,this,&MainWindow::onTimeertriggered);

    act = new QAction(this);
    act->setIcon(QIcon(":/icon/Computer.png"));
    act->setText(QStringLiteral("计算器"));
    pannel3->addLargeAction(act);
    connect(act,&QAction::triggered,this,&MainWindow::onComputertriggered);

}

void MainWindow::createCategorySYSHelp(SARibbonCategory *page)
{

    QAction* act = new QAction(this);
    SARibbonPannel* pannel = page->addPannel(QStringLiteral("帮助信息"));
    act = new QAction(this);
    act->setIcon(QIcon(":/icon/help.ico"));
    act->setText(QStringLiteral("帮助文件"));
    pannel->addLargeAction(act);

    act = new QAction(this);
    act->setIcon(QIcon(":/icon/BORole.png"));
    act->setText(QStringLiteral("联系方式"));
    pannel->addLargeAction(act);


    act = new QAction(this);
    act->setIcon(QIcon(":/icon/BODetails.png"));
    act->setText(QStringLiteral("软件说明"));
    pannel->addLargeAction(act);

    act = new QAction(this);
    act->setIcon(QIcon(":/icon/information.png"));
    act->setText(QStringLiteral("软件版本"));
    pannel->addLargeAction(act);
    connect(act,&QAction::triggered,this,&MainWindow::onSYsSoftVerInfo);
}

void MainWindow::onSYsSoftVerInfo()
{
    this->takeCentralWidget();
    VersionInfo* dlg = new VersionInfo(this);
    this->setCentralWidget(dlg);

    
}

void MainWindow::slotsDeviceCnnState(QString Name, bool CnnSat)
{
    labelStsIP->setText(Name);
    if (CnnSat == false)
    {
        pBtnStsConnect->setText("已断开");
        Connact->setText(QStringLiteral("连接"));
        labelStsIco->setPixmap(*disconnectIco);
    }
    else
    {
        pBtnStsConnect->setText("已连接");
        labelStsIco->setPixmap(*connectIco);
        Connact->setText(QStringLiteral("断开"));
    }
    // statusbar->addPermanentWidget(labelStsIP);
}

void MainWindow::slotsDebugMsg(QString str, QByteArray val)
{
    //调试信息
    if (m_checkBox->checkState() != Qt::CheckState::Checked)
    {
        return;
    }
    m_debugdata->Debug_Data_Show("Can接口", str, val);
}

void MainWindow::onConnecttriggered()
{

    if (m_rb->isChecked())
    {
        drvmng::getInstance().Ipconnect(m_ip->text(), 9030);
    }
    else
    {
        drvmng::getInstance().CanConnect(can_channle->currentIndex());
    }

}

void MainWindow::onHistoryAlarmLog()
{
    this->takeCentralWidget();
    setCentralWidget(m_alarmlog);
}

void MainWindow::createCategoryDevMng(SARibbonCategory *page)
{
    SARibbonPannel* pannel = page->addPannel(QStringLiteral("主从设备配置"));
    QAction* act = new QAction(this);

    act->setIcon(QIcon(":/icon/set.png"));
    act->setText(QStringLiteral("从机设备配置"));
    pannel->addLargeAction(act);
    connect(act,&QAction::triggered,this,&MainWindow::onSlaveMngtriggered);

    act = new QAction(this);
    act->setIcon(QIcon(":/icon/set.png"));
    act->setText(QStringLiteral("二级主控设备配置"));
    pannel->addLargeAction(act);
    connect(act,&QAction::triggered,this,&MainWindow::onMasterMngtriggered);


    act = new QAction(this);
    act->setIcon(QIcon(":/icon/set.png"));
    act->setText(QStringLiteral("故障注入配置"));
    pannel->addLargeAction(act);
    connect(act, &QAction::triggered, this, &MainWindow::onFaultMngtriggered);

    pannel = page->addPannel(QStringLiteral("传感器参数标定"));

    act = new QAction(this);
    act->setIcon(QIcon(":/icon/k1.ico"));
    act->setText(QStringLiteral("电流传感器标定"));
    pannel->addLargeAction(act);


    act = new QAction(this);
    act->setIcon(QIcon(":/icon/k2.ico"));
    act->setText(QStringLiteral("电压传感器标定"));
    pannel->addLargeAction(act);

    act = new QAction(this);
    act->setIcon(QIcon(":/icon/k3.ico"));
    act->setText(QStringLiteral("温度传感器标定"));
    pannel->addLargeAction(act);

}

void MainWindow::createCategorySYSRun(SARibbonCategory* page)
{
    SARibbonPannel* pannel = page->addPannel(QStringLiteral("测试运行"));

    QAction* act = new QAction(this);
    act->setIcon(QIcon(":/icon/startall.ico"));
    act->setText(QStringLiteral("测试开始"));
    pannel->addLargeAction(act);
    connect(act, &QAction::triggered, this, &MainWindow::onSysRunStartAll);
    //act = new QAction(this);
    //act->setIcon(QIcon(":/icon/start.ico"));
    //act->setText(QStringLiteral("测试运行"));
    //pannel->addLargeAction(act);
    // connect(act,&QAction::triggered,this,&MainWindow::onSysRunStartAll);

    act = new QAction(this);
    act->setIcon(QIcon(":/icon/stopall.png"));
    act->setText(QStringLiteral("测试暂停"));
    pannel->addLargeAction(act);
    connect(act, &QAction::triggered, this, &MainWindow::onSysRunStopAll);

    m_logcheckBox = new SARibbonCheckBox(this);
    m_logcheckBox->setSizePolicy(QSizePolicy::Expanding,
        QSizePolicy::Fixed);
    m_logcheckBox->setWindowIcon(QIcon(":/icon/icon/folder.png"));
    m_logcheckBox->setText(QStringLiteral("日志保存"));
    pannel->addWidget(m_logcheckBox);
    connect(m_logcheckBox, &QCheckBox::stateChanged, [&]() {
        if (m_logcheckBox->isChecked())
        {
            m_showbcu->BCULogEnable(true);
            m_showbmu->LogEnable(true);
        }
        else
        {
            m_showbcu->BCULogEnable(false);
            m_showbmu->LogEnable(false);
        }
        }
    );
}

void MainWindow::createCategoryResultDes(SARibbonCategory *page)
{

    SARibbonPannel* pannel = page->addPannel(QStringLiteral("测试结果"));

    QAction* act = new QAction(this);
    act->setIcon(QIcon(":/icon/resultDes.png"));
    act->setText(QStringLiteral("历史告警查询"));
    pannel->addLargeAction(act);
    connect(act, &QAction::triggered, this, &MainWindow::onHistoryAlarmLog);

    //act = new QAction(this);
    //act->setIcon(QIcon(":/icon/chartDataManager.png"));
    //act->setText(QStringLiteral("结果导出"));
    //pannel->addLargeAction(act);

    act = new QAction(this);
    act->setIcon(QIcon(":/icon/resultShow.png"));
    act->setText(QStringLiteral("数据管理"));
    pannel->addLargeAction(act);
    connect(act,&QAction::triggered,this,&MainWindow::DataAnalysistriggered);

    act = new QAction(this);
    act->setIcon(QIcon(":/icon/resultOut.png"));
    act->setText(QStringLiteral("BCU数据回放"));
    pannel->addLargeAction(act);
    //  connect(act,&QAction::triggered,this,&MainFrm::WdReportOutTriggered);


    act = new QAction(this);
    act->setIcon(QIcon(":/icon/resultOut.png"));
    act->setText(QStringLiteral("BMU数据回放"));
    pannel->addLargeAction(act);

}

void MainWindow::createCategoryTestMng(SARibbonCategory *page)
{

    SARibbonPannel* pannel2 = page->addPannel(QStringLiteral("H100储能网络拓扑"));
    QAction* act = new QAction(this);

    act = new QAction(this);
    act->setIcon(QIcon(":/icon/k1.ico"));
    act->setText(QStringLiteral("H100总体网络拓扑"));
    pannel2->addLargeAction(act);
    connect(act,&QAction::triggered,this,&MainWindow::ShowNetDatatriggered);


    act = new QAction(this);
    act->setIcon(QIcon(":/icon/k1.ico"));
    act->setText(QStringLiteral("H100主机网络拓扑"));
    pannel2->addLargeAction(act);
     connect(act,&QAction::triggered,this,&MainWindow::ShowMasterDatatriggered);


    act = new QAction(this);
    act->setIcon(QIcon(":/icon/k1.ico"));
    act->setText(QStringLiteral("H100从机网络拓扑"));
    pannel2->addLargeAction(act);
    connect(act,&QAction::triggered,this,&MainWindow::ShowSlaveDatatriggered);

    createCategorySYSRun(page);
}



void MainWindow::onComputertriggered()
{
    QProcess *poc = new QProcess;
    poc->start("C:\\Windows\\system32\\calc.exe");
    // system("calc");
}

void MainWindow::onTimeertriggered()
{
    QProcess *poc = new QProcess;
    poc->start("C:\\Windows\\system32\\calc.exe");
}

void MainWindow::ShowNetDatatriggered()
{
    //setWindowTitle(QStringLiteral("总体网络拓扑"));
    //CustomDockWidget *dockWidget = new CustomDockWidget(this);
    //addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
    //dockWidget->setWidget(new shownetwork());
    //setWindowTitle(QStringLiteral("总体网络拓扑"));
    //this->takeCentralWidget();
    //this->setCentralWidget(new shownetwork());

}


void MainWindow::onFaultMngtriggered()
{
    FaultInjection* p = new FaultInjection();
    p->show();

}

void MainWindow::DataAnalysistriggered()
{
    setWindowTitle(QStringLiteral("结果分析"));

    dataAnalysis* user;
    user = new dataAnalysis;
    this->takeCentralWidget();
    setCentralWidget(user);
}



void MainWindow::ShowMasterDatatriggered()
{
    setWindowTitle(QStringLiteral("主机网络测试拓扑"));
    this->takeCentralWidget();
  //  this->setCentralWidget(m_showbcu);
  //  ShowBCU* buc = new ShowBCU();
    this->setCentralWidget(m_showbcu);

}

void MainWindow::ShowSlaveDatatriggered()
{
   setWindowTitle(QStringLiteral("从机网络测试拓扑"));
   CustomDockWidget *dockWidget = new CustomDockWidget(this);
   this->takeCentralWidget();
   setCentralWidget(m_showbmu); 
}

void MainWindow::onSlaveMngtriggered()
{
    setWindowTitle(QStringLiteral("从控CAN设置"));
    m_slavemng->show();
}

void MainWindow::onMasterMngtriggered()
{
    setWindowTitle(QStringLiteral("主控ModbusTcp设置"));
      //this->takeCentralWidget();
      //MasterMng  *dlg = new MasterMng(this) ;
      //this->setCentralWidget(dlg);
      m_mastermng->show();
}

void MainWindow::onAgentDeviceUpdateMng()
{
    UPFileWindows* drv;
    drv = new UPFileWindows;
    drv->show();
}
void MainWindow::onSysRunStartAll()
{

    drvmng::getInstance().StartThread();
}

void MainWindow::onSysRunStopAll()
{
    drvmng::getInstance().StopThread();
}


void MainWindow::onLoggerMng()
{
    setWindowTitle(QStringLiteral("操作日志"));
    LogWindow* dlg;
    dlg = new LogWindow;
    this->takeCentralWidget();
    setCentralWidget(dlg);     
}

void MainWindow::onDebugLogger()
{

    setWindowTitle(QStringLiteral("调试日志"));
    CustomDockWidget* dockWidget = new CustomDockWidget(this);
    addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
    dockWidget->setWidget(m_debugdata);
}
