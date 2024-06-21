#include "ShowVoltageNet.h"
#include "showslave.h"
#include <src/drvmng/modbus_params.h>
extern _PackDetailInfoST     g_PackDetailInfoST[MAX_BMU_NUM];
extern _F0DevInfo            g_DevInfo[MAX_BMU_NUM];

ShowVoltageNet::ShowVoltageNet(uint16_t slaveNum, uint16_t ItemNum, QWidget *parent)
	: QWidget(parent)
{

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
	ui.setupUi(this);
    this->setWindowTitle("电压数据视图");
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(UpdateItemUi()));
    timer->start(1000);//start之后,每隔一秒触发一次槽函数
    this->setAttribute(Qt::WA_DeleteOnClose);
  //  InitUi();
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
    headlist << "电池包总压(V)";      
        for (int k = 0; k < ItemNum; k++)
        {
            headlist << "电池电压" + QString::number(k+1, 10)+ "(mv)";
        }
        //<< "电池电压1" << "电池电压2" << "电池电压3" << "电池电压4" << "电池电压5" << "电池电压6" << "电池电压7" << "电池电压8" << "电池电压9" << "电池电压10"
        //<< "电池电压11" << "电池电压12" << "电池电压13" << "电池电压14" << "电池电压15" << "电池电压16";
    ui.tableWidget->setHorizontalHeaderLabels(headlist);
    ui.tableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers); //禁止双击编辑
    ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui.tableWidget->scrollToBottom();  //让滚动条滚动到最底部
    ui.tableWidget->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
    slavenum = slaveNum;
    VoltageNumPerpack = ItemNum;
}

ShowVoltageNet::~ShowVoltageNet()
{



}

void ShowVoltageNet::InitUi()
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

    lbSV->setText("软件版本:V1.0.1");
    lbHV->setText("硬件版本:V1.0.0");
    lbBootV->setText("Boot版本:V1.0.0");

    lbUUID->setText("UUID:XXXXXXXXXX");
    lbSN->setText("Sn:XXXXXXXXXX");

    HLayoutSoftInfo->addWidget(lbSV);
    HLayoutSoftInfo->addWidget(lbHV);
    HLayoutSoftInfo->addWidget(lbUUID);
    HLayoutSoftInfo->addWidget(lbSN);
    HLayoutSoftInfo->addWidget(lbBootV);
    VLayout->addLayout(HLayoutSoftInfo);
    // Cell总数添加到列表
    QList<QLabel*> m_ItemList;
    for (int i = 0; i < 12; i++)
    {
        QLabel* item = new QLabel();
        item->setStyleSheet(QString("border: 1px solid #323232; \
                                        border-radius:0px;  \
                                        padding:0px 0px;  \
                                        background-color:#267400;"));
       m_ItemList.push_back(item);
    }
    //计算行数

    QLabel  *lbv = new QLabel();
    lbv->setFixedSize(QSize(350, 50));
    lbv->setStyleSheet("color:#ffffff");
    lbv->setText("总电压:0V");
    QLabel* lbs = new QLabel();
    lbs->setFixedSize(QSize(350, 50));
    lbs->setText("状态:正常");
    lbs->setStyleSheet("color:#ffffff");
    HLayout1->addWidget(lbv);
    HLayout1->addWidget(lbs);
    VLayout->addLayout(HLayout1);
    QGroupBox* buttonGroup = new QGroupBox();
    buttonGroup->setLayout(VLayout);
    this->setStyleSheet(QString("border: 1px solid #323232; \
                                    border-radius:0px;  \
                                    padding:0px 0px;  \
                                    background-color:#001d4f;"));
    this->setLayout(VLayout);
}
void ShowVoltageNet::UpdateItemUi()
{
    uint16_t  BatTotalVols = 0;
    for (int rowCount = 0; rowCount < slavenum; rowCount++)
    {
        BatTotalVols = 0;
        for (int i = 0; i < VoltageNumPerpack; i++)
        {
            QTableWidgetItem   *item = new  QTableWidgetItem();
            item->setText((QString::number(g_PackDetailInfoST[rowCount].BatVols[i], 10)));
            ui.tableWidget->setItem(rowCount, i + 1, item); //序号
            if (g_PackDetailInfoST[rowCount].BatVols[i] > 3600)
            {
                item->setBackground(QBrush(QColor(255, 0, 0)));
            }
            else if (g_PackDetailInfoST[rowCount].BatVols[i] < 3000)
            {
                item->setBackground(QBrush(QColor(255, 255, 255)));
            }
            else
            {
                item->setBackground(QBrush(QColor(22, 63, 98)));
            }

            BatTotalVols +=   g_PackDetailInfoST[rowCount].BatVols[i];
        }
        ui.tableWidget->setItem(rowCount,0, new QTableWidgetItem(QString::number(BatTotalVols/1000.00, 'f', 2)));
    }
 
    //g_PackDetailInfoST[]
}