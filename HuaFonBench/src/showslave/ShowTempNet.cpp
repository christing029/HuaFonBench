#include "ShowTempNet.h"
#include "showslave.h"
#include <src/drvmng/modbus_params.h>

ShowTempNet::ShowTempNet(uint16_t slaveNum, uint16_t ItemNum, QWidget *parent)
	: QWidget(parent)
{

    QFile file(":/qss/HF.qss");
    if (!file.open(QIODevice::ReadOnly))
    {
        qWarning("Can't open the style sheet file.");
        return;
    }
    Num = slaveNum;
    QString qss = QLatin1String(file.readAll());
    QString paletteColor = qss.mid(20, 7);
    // this->setPalette(QPalette(QColor(paletteColor)));
    this->setStyleSheet(qss);
    // this->setStyleSheet(file.readAll());
    file.close();
	ui.setupUi(this);

    for (int j = 0; j < slaveNum; j++)
    {
        
        int row = ui.tableWidget->rowCount();
        int column = ui.tableWidget->columnCount();
        ui.tableWidget->insertRow(row);
        //下面是为了删除时判断是不是空行，当然如何判断null可能也是的，我可以试
        for (int i = 0; i < column; i++)
        {
            QTableWidgetItem* item = new QTableWidgetItem();
            item->setText("");
            ui.tableWidget->setItem(row, i, item);
        }
    }
    QStringList headlist;
    ui.tableWidget->setColumnCount(ItemNum+1);


    headlist << "电池包状态";
    for (int k = 0; k < ItemNum; k++)
    {
        headlist << "电池温度" + QString::number(k, 10);
    }
    ui.tableWidget->setHorizontalHeaderLabels(headlist);
    ui.tableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers); //禁止双击编辑
    ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui.tableWidget->scrollToBottom();  //让滚动条滚动到最底部
    ui.tableWidget->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(UpdateItemUi()));
    timer->start();
}

ShowTempNet::~ShowTempNet()
{


}

void ShowTempNet::InitUi()
{

   


}
void ShowTempNet::UpdateItemUi()
{
    //   VoltageDataUpdate(g_PackDetailInfoST[SlectBmuID].BatVols);
      //TempDataUpdate(g_PackDetailInfoST[SlectBmuID].BatTemps);
      // BlanceStatusUpdate(g_PackDetailInfoST[SlectBmuID].CellBlance);
    for (int rowCount = 0; rowCount < Num; rowCount++)
    {
        for (int i = 0; i < ui.tableWidget->columnCount() - 1; i++)
        {
            ui.tableWidget->setItem(rowCount, i + 1, new QTableWidgetItem(QString::number((g_PackDetailInfoST[rowCount].BatTemps[i]/10.0), 'f', 2))); //序号
        }
    }

    //g_PackDetailInfoST[]
}