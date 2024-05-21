#ifndef SHOWSLAVE_H
#define SHOWSLAVE_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "slaveiteminfo.h"
#include <QSqlQuery>
#include <QTableWidget>
#include <QWidget>
#include <QtConcurrent/QtConcurrent>
#include "src/public/sqlite_amalgamation/DeviceData.h"
#include <src/showslave/ShowBMUNet.h>
#include <src/drvmng/StantCan_params.h>
#include <src/public/CustomDockWidget.h>
#include <list>
#include "modbus_params.h"
#include "ShowFanNet.h"
using namespace QtConcurrent;

namespace Ui {
class ShowSlave;
}
class ShowSlave : public QMainWindow
{
    Q_OBJECT
public:
    explicit ShowSlave(QWidget *parent = nullptr);
    ~ShowSlave();
private:
    Ui::ShowSlave *ui;
    void InitUi(uint8_t SlaveNum);
    void  HideAll();
    void myFunc(const QString& str);
private slots:
  //void on_treeView_clicked(const QModelIndex& index);
    void on_treeView_doubleClicked(const QModelIndex& index);
    void slotContextMenu();
    void slotSlaveNetMenu();
    void slotDataMenu();
    void slotTempDataMenu();
    void slotFanDataMenu();
    void KeepLiveProcess();
private :
 // SlaveItemInfo   pchann1[15];
    SlaveItemInfo* slaveItemInfo;
  QMenu* menu;
  QStandardItemModel* mode;
  QStandardItem* Iconitem[15];
protected:
  uint8_t SlectSlaveId = 0;
  uint16_t SlaveCount = 15; //从机的个数
  uint16_t VoltCntPerSlave = 16; // 每一个从机有多少个电压
  uint16_t TempCntPerSlave = 16;  // 每一个从机有多少温度
private:
  QList<uint16_t> CellVoltList;
  list<int16_t> CellTempList;
  list<bool> CellBlanceList;    //0:没有均衡  1:均衡
  list<bool> CellCnnStatusList; //0:正常  1 :断线
  uint16_t TotalVolt;
  uint16_t TotalCurrent;
  uint8_t  DI;
  uint8_t  DO;
 _RealpackMinMaxInfo   RealpackMinMaxInfo[12] = { 0 };
  BMU_CAN_RecData* SlaveMsg = NULL;
  bool initCanUi = true;
private:
  // BMU数据库操作
  void Openbmu_DataBase();
  void Add_VoltageTable(uint8_t ID,uint16_t V[LECU_MAX_VOL]);
  void Add_TempTable(uint8_t ID,int16_t T[LECU_MAX_TEMP]);
  void bmu_data_save_table(BMU_CAN_RecData* getMsg);
  void bmu_tcp_updata_table();
private slots:
    void SlotsCanUpBMUMsg(QString str, QByteArray data);
    void slotsUpTCPBMUMsg(uint startAddress, QVector<quint16> val);

protected:
//  ShowBMUNet* bmunet = NULL;
};
extern _PackDetailInfoST     g_PackDetailInfoST[MAX_BMU_NUM];
extern  _F0DevInfo            g_DevInfo[MAX_BMU_NUM];
#endif // SHOWSLAVE_H
