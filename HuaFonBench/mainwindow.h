#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "SARibbonMainWindow.h"
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
#include<QCloseEvent>
#include <src/drvmng/drvmng.h>
#include <src/mastermng/mastermng.h>
#include <src/public/CustomDockWidget.h>
#include <src/shownetwork/shownetwork.h>
#include <src/showslave/showslave.h>
#include <src/showmaster/ShowBCU.h>
#include <src/slavemng/slavemng.h>
#include <src/ota/UPFileWindows.h>
#include <src/log/LogWindow.h>
#include <src/public/VersionInfo.h>
#include <src/log/DebugLog.h>
#include <src/log/HistoryAlarmLog.h>
#include <src/usermng/deviceFind.h>
#include <src/dataAnalysis/dataAnalysis.h>
#include <src/usermng/usermng.h>

class SARibbonCategory;
class SARibbonContextCategory;
class QTextEdit;
class MainWindow : public SARibbonMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget* par=nullptr);
    ~MainWindow();
private slots:
    void onShowContextCategory(bool on);
//    void onWpsStyle(bool on);
private:
//    void createCategoryMain(SARibbonCategory* page);
//    void createCategoryOther(SARibbonCategory* page);
    void createCategorySysMng(SARibbonCategory* page);
    void createCategorySYSHelp(SARibbonCategory* page);
    void createCategoryDevMng(SARibbonCategory* page);
    void createCategoryTestMng(SARibbonCategory* page);
    void createCategorySYSRun(SARibbonCategory* page);
    void createCategoryResultDes(SARibbonCategory* page);

    void onAgentUserMng();
    void onAgentDeviceMng();
    void onAgentDeviceFind();
    void onAgentDeviceUpdateMng();
private slots:
//    void onMenuButtonPopupCheckableTest(bool b);
//    void onInstantPopupCheckableTest(bool b);
//    void onDelayedPopupCheckableTest(bool b);
//    void onMenuButtonPopupCheckabletriggered(bool b);
//    void onInstantPopupCheckabletriggered(bool b);
//    void onDelayedPopupCheckabletriggered(bool b);
    void onComputertriggered();
    void onTimeertriggered();
    void ShowNetDatatriggered();
    void ShowMasterDatatriggered();
    void ShowSlaveDatatriggered();
    void onSlaveMngtriggered();
    void onMasterMngtriggered();
    void onFaultMngtriggered();
    void DataAnalysistriggered();
    void onSysRunStartAll();
    void onSysRunStopAll();
    void onLoggerMng();
    void onDebugLogger();
    void onSYsSoftVerInfo();
    void slotsDeviceCnnState(QString Name, bool CnnSat);
    void slotsDebugMsg(QString, QByteArray);
    void onConnecttriggered();
    void onHistoryAlarmLog();
private:
    SARibbonContextCategory* m_contextCategory;
    QTextEdit* m_edit;
    ShowSlave* m_showbmu;
    DebugLog   *m_debugdata;
    SARibbonCheckBox* m_checkBox;
  //  drvmng* m_drvmng;
    MasterMng* m_mastermng;
    ShowBCU* m_showbcu; 
    HistoryAlarmLog* m_alarmlog;
    SlaveMng* m_slavemng;
private:
    QPixmap* connectIco;                // 图片：已连接
    QPixmap* disconnectIco;             // 图片：断开连接
    QLabel* labelStsInfo;               // 状态栏提示信息
    QLabel* labelStsIP;            // IP信息
    QLabel* labelStsIco;           // 状态图标
  //  QLabel* labelStsStatus;        // 状态信息
    QPushButton* pBtnStsConnect;	// 重连按钮
    QStatusBar* statusbar;
    QAction* Connact;
    QRadioButton* m_rb;
    SARibbonLineEdit* m_ip;
    SARibbonComboBox* can_channle;

protected:
    void   closeEvent(QCloseEvent* event) override;

};
//extern drvmng* m_devmng;
#endif // MAINWINDOW_H
