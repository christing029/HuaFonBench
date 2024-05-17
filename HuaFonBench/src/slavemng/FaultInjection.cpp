#include "FaultInjection.h"
#include "QCheckBox"
#include <src/drvmng/drvmng.h>
FaultInjection::FaultInjection(QWidget *parent)
	: QWidget(parent)
{
	 ui.setupUi(this);

     QStringList headlist;
     headlist << "是否使能" << "故障名称" << "值" << "单位"<<"单设";

     volttableWidget = new QTableWidget(this);
     volttableWidget->setColumnCount(5);
     volttableWidget->setHorizontalHeaderLabels(headlist);
     ui.verticalLayout->addWidget(volttableWidget);


     temptableWidget = new QTableWidget(this);
     temptableWidget->setColumnCount(5);
     temptableWidget->setHorizontalHeaderLabels(headlist);
     ui.verticalLayout->addWidget(temptableWidget);
     temptableWidget->hide();




     for (int i = 0; i < 16; i++)
     {
          volttableWidget->insertRow(i);
          QCheckBox* check = new QCheckBox("", this);
          volttableWidget->setCellWidget(i, 0, check);  
          volttableWidget->setItem(i, 1, new QTableWidgetItem("电压" + QString::number(i + 1, 10)));
          volttableWidget->setItem(i, 2, new QTableWidgetItem("3000"));
          volttableWidget->setItem(i, 3, new QTableWidgetItem("mv"));

          QPushButton* button = new QPushButton("下发 ", this);
          connect(button, SIGNAL(clicked()), this, SLOT(on_button_clicked()));
          volttableWidget->setCellWidget(i, 4, button);


          QCheckBox* check1 = new QCheckBox("", this);
          temptableWidget->insertRow(i);
          temptableWidget->setCellWidget(i, 0, check1);
          temptableWidget->setItem(i, 1, new QTableWidgetItem("温度"+ QString::number(i+1, 10)));
          temptableWidget->setItem(i, 2, new QTableWidgetItem("3000"));
          temptableWidget->setItem(i, 3, new QTableWidgetItem("0.1°"));  

          QPushButton* button1 = new QPushButton("下发 ", this);
          connect(button1, SIGNAL(clicked()), this, SLOT(on_button_clicked()));
          temptableWidget->setCellWidget(i, 4, button1);
     }
   
     connect(ui.checkBox, &QCheckBox::stateChanged, [&]() {
         if (ui.checkBox->isChecked())
         {
            
             for (int i = 0; i <16; i++)
             {
                 QWidget* cellWidget = volttableWidget->cellWidget(i, 0);
                 QWidget* cellWidget1 = temptableWidget->cellWidget(i, 0);
                 QCheckBox* checkBox = dynamic_cast<QCheckBox*>(cellWidget);
                 QCheckBox* checkBox1 = dynamic_cast<QCheckBox*>(cellWidget1);
                 checkBox->setChecked(true);
                 checkBox1->setChecked(true);
             }

         }
         else
         {
             for (int j = 0; j < 16;j++)
             {
                 QWidget* cellWidget = volttableWidget->cellWidget(j, 0);
                 QWidget* cellWidget1 = temptableWidget->cellWidget(j, 0);
                 QCheckBox* checkBox = dynamic_cast<QCheckBox*>(cellWidget);
                 QCheckBox* checkBox1 = dynamic_cast<QCheckBox*>(cellWidget1);
                 checkBox->setChecked(false);
                 checkBox1->setChecked(false);

             }
            
         }
         });


     connect(ui.comboBox, QOverload<const QString&>::of(&QComboBox::currentTextChanged), [=](const QString& str)
        {                     
            if (str == "电压注入故障")
            {
                volttableWidget->show();
                temptableWidget->hide();
            }
            else if (str == "温度注入故障")
            {
                temptableWidget->show();
                volttableWidget->hide();
            }
            else if (str == "AFE注入故障")
            {
           
            }
            else if (str == "风扇转速注入故障")
            {

            }
            else if (str == "DI注入故障")
            {

            }
            else if (str == "电流注入故障")
            {

            }
        });

     uint16_t cheksum = 0;


     std::string str = "~00S005SDA60";
     QByteArray qba = QByteArray::fromStdString(str);
     for (int i = 0; i < qba.count(); i++)
     {
         cheksum += qba[i];
     }
}

void FaultInjection::on_button_clicked()
{
    QPushButton* obj = dynamic_cast<QPushButton*>(this->sender());
    int x = obj->frameGeometry().x();
    int y = obj->frameGeometry().y();
    QModelIndex index = volttableWidget->indexAt(QPoint(x, y));
    int currentRow = index.row();
    QString val = volttableWidget->item(currentRow, 2)->text();//
    QString val_t = temptableWidget->item(currentRow, 2)->text();//
    unsigned char data_from_text[8] = { 0 };

    uint32_t frameId = 0;
    frameId = drvmng::getInstance().dr_make_can_ID(PARAMETER_PRIO, 0, ui.comboBox_2->currentIndex()+1, PC_ADDR);

    data_from_text[0] = 00;
    data_from_text[1] =0x1a|0x80;
    data_from_text[2] = 5;//长度
    //Data0： 1 电压，2 温度  Data1： 1 使能，0 关闭Data3：模拟数据位置Data4：模拟数据高 8 位Data5：模拟数据低 8 位

    if (ui.comboBox->currentIndex() == 0)
    {
        data_from_text[3] = 1;//Data0： 1 电压，2 温度Data1：
        QWidget *cellwidget = volttableWidget->cellWidget(currentRow, 0);
        QCheckBox * checkBox = dynamic_cast<QCheckBox*>(cellwidget);
        if (checkBox) {
            data_from_text[4] = checkBox->isChecked();
            // 例如，你可以打印是否选中
        }
        data_from_text[6] = val.toUInt(nullptr,10)>>8;
        data_from_text[7] = val.toUInt(nullptr, 10) &0xff;
    }
    if (ui.comboBox->currentIndex() == 1)
    {
        data_from_text[3] =2;//Data0： 1 电压，2 温度Data1：
        QWidget* cellwidget = temptableWidget->cellWidget(currentRow, 0);
        QCheckBox* checkBox = dynamic_cast<QCheckBox*>(cellwidget);
        if (checkBox) {
            data_from_text[4] = checkBox->isChecked();
            // 例如，你可以打印是否选中
        }
        data_from_text[6] = val_t.toUInt(nullptr, 10) >> 8;
        data_from_text[7] = val_t.toUInt(nullptr, 10) & 0xff;
    }
    data_from_text[5] = currentRow;  // 位置 0开始
    drvmng::getInstance().CanSnd(frameId, data_from_text,8);
}

FaultInjection::~FaultInjection()
{

}

void FaultInjection::voltefaultshow()
{
    for (int i = 0 ;i<16 ;i++)
    {
       /* ui.tableWidget->insertRow(i);
        QCheckBox* check = new QCheckBox("", this);
        ui.tableWidget->setCellWidget(i, 0, check);
        if (volttable[i].Vaild)
        {
            check->setChecked(true);
        }
        ui.tableWidget->setItem(i, 1, new QTableWidgetItem(volttable[i].Name));
        ui.tableWidget->setItem(i, 2, new QTableWidgetItem(volttable[i].Value));*/
    }
}

void FaultInjection::tempfaultshow()
{
    for (int i = 0; i < 16; i++)
    {
      /*  QCheckBox* check = new QCheckBox("", this);
        ui.tableWidget->setCellWidget(i, 0, check);
        if (temptable[i].Vaild)
        {
            check->setChecked(true);
        }
        ui.tableWidget->setItem(i, 1, new QTableWidgetItem(temptable[i].Name));
        ui.tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(temptable[i].Value)));*/



    }
}

void FaultInjection::difaultshow()
{


}

void FaultInjection::currentfaultshow()
{
}
