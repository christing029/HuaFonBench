#include "ShowFanNet.h"
#include "showslave.h"
ShowFanNet::ShowFanNet(QWidget *parent)
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

    for (int j = 0; j < 16; j++)
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

    //QStringList headlist;
    ////ui.tableWidget->setColumnCount(16 );
    //for (int k = 0; k < 16; k++)
    //{
    //    headlist << "风扇转速" + QString::number(k, 10);
    //}
    //ui.tableWidget->setHorizontalHeaderLabels(headlist);

    ui.tableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers); //禁止双击编辑
    //ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    //ui.tableWidget->scrollToBottom();  //让滚动条滚动到最底部
    ui.tableWidget->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
    //int row = ui.tableWidget->rowCount();
    ////    int column = ui.tableWidget->columnCount();
    //ui.tableWidget->insertRow(row);
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(UpdateItemUi()));
    timer->start(500);
}

ShowFanNet::~ShowFanNet()
{
    deleteLater();
}
void ShowFanNet::UpdateItemUi()
{
    for (int rowCount = 0; rowCount < 16; rowCount++)
    {  
            ui.tableWidget->setItem(rowCount, 0, new QTableWidgetItem(QString::number(rowCount, 10))); //序号
            ui.tableWidget->setItem(rowCount, 1, new QTableWidgetItem(QString::number((g_PackDetailInfoST[rowCount].FanSpeed),10))); //序号
            ui.tableWidget->setItem(rowCount, 2, new QTableWidgetItem(QString::number((g_PackDetailInfoST[rowCount].FanStatus1), 10))); //序号
            ui.tableWidget->setItem(rowCount, 3, new QTableWidgetItem(QString::number((g_PackDetailInfoST[rowCount].FanStatus2), 10))); //序号
    }

    //g_PackDetailInfoST[]
}