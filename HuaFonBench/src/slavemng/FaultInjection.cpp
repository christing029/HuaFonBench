#include "FaultInjection.h"
#include "QCheckBox"
#include <src/drvmng/drvmng.h>

#include <src/drvmng/modbus_params.h>
#include <src/drvmng/drvmng.h>
extern _PackDetailInfoST     g_PackDetailInfoST[MAX_BMU_NUM];

FaultInjection::FaultInjection(QWidget *parent)
	: QWidget(parent)
{

     QFile file(":/qss/HF.qss");
     if (!file.open(QIODevice::ReadOnly))
     {
         qWarning("Can't open the style sheet file.");
         return;
     }
     QString qss = QLatin1String(file.readAll());
     this->setStyleSheet(qss);
     ui.setupUi(this);
     QStringList headlist;
     headlist << "是否使能" << "故障名称" << "实际值" << "下设值"<<"单位" << "下设";

     volttableWidget = new QTableWidget(this);
     volttableWidget->setColumnCount(6);
     volttableWidget->setHorizontalHeaderLabels(headlist);
     ui.verticalLayout->addWidget(volttableWidget);


     temptableWidget = new QTableWidget(this);
     temptableWidget->setColumnCount(6);
     temptableWidget->setHorizontalHeaderLabels(headlist);
     ui.verticalLayout->addWidget(temptableWidget);
     temptableWidget->hide();

     for (int i = 0; i < 16; i++)
     {
          volttableWidget->insertRow(i);
          QCheckBox* check = new QCheckBox("", this);
          check->setChecked(true);
          volttableWidget->setCellWidget(i, 0, check); 
          volttableWidget->setItem(i, 1, new QTableWidgetItem("电压" + QString::number(i + 1, 10)));
          volttableWidget->setItem(i, 3, new QTableWidgetItem("3000"));
          volttableWidget->setItem(i, 4, new QTableWidgetItem("mv"));

          QPushButton* button = new QPushButton("下发 ", this);
          connect(button, SIGNAL(clicked()), this, SLOT(on_button_clicked()));
          volttableWidget->setCellWidget(i, 5, button);


       //   QPushButton* readbutton = new QPushButton("读取 ", this);
       ////   connect(readbutton, SIGNAL(clicked()), this, SLOT(on_button_clicked()));
       //   volttableWidget->setCellWidget(i, 5, readbutton);

          QCheckBox* check1 = new QCheckBox("", this);
          check1->setChecked(true);
          temptableWidget->insertRow(i);
          temptableWidget->setCellWidget(i, 0, check1);
          temptableWidget->setItem(i, 1, new QTableWidgetItem("温度"+ QString::number(i+1, 10)));
          temptableWidget->setItem(i, 3, new QTableWidgetItem("250"));
          temptableWidget->setItem(i, 4, new QTableWidgetItem("0.1°"));  

          QPushButton* button1 = new QPushButton("下发 ", this);
          connect(button1, SIGNAL(clicked()), this, SLOT(on_button_clicked()));
          temptableWidget->setCellWidget(i, 5, button1);

          //QPushButton* readbutton2 = new QPushButton("读取 ", this);
          //connect(readbutton2, SIGNAL(clicked()), this, SLOT(on_button_clicked()));          //volttableWidget->setCellWidget(i, 5, readbutton2);

     }
  
     QStringList  bcutableStr;
     bcutableStr << "电流" << "负级绝缘电阻"<< "正级绝缘电阻" \
                 <<"电池电压" << "P+P-电压" << "环境温度" << "PCB温度" <<"P-温度"<<"P+温度"  << "电池-温度"<<"电池+温度" \
                             << "DI_POWER_5V" << "DI_POWER_24V" << "DI_MCU_FTL1" << "DI_MCU_FTL2"\
                             << "DI_MCU_FTL3" << "DI_MCU_FTL4" << "DI_温度传感器"\
                             << "DI_急停传感器" << "DI_水浸传感器" << "DI_消防传感器"\
                             << "DI_ENTRANCE_SENSO" << "DI_烟感" << "DI_减法器"\
                             << "DI_CONT_PLUS" <<  "DI_CONT_TRIP";
     bcutableWidget = new QTableWidget(this);
     bcutableWidget->setColumnCount(6);
     bcutableWidget->setHorizontalHeaderLabels(headlist);
     ui.verticalLayout->addWidget(bcutableWidget);
     bcutableWidget->hide();

     for (int i = 0; i < bcutableStr.count(); i++)
     {
         bcutableWidget->insertRow(i);
         QCheckBox* check = new QCheckBox("", this);
         check->setChecked(true);
         bcutableWidget->setCellWidget(i, 0, check);
         bcutableWidget->setItem(i, 1, new QTableWidgetItem(bcutableStr[i]));
         bcutableWidget->setItem(i, 2, new QTableWidgetItem(""));
         bcutableWidget->setItem(0, 4, new QTableWidgetItem("0.1A"));
         bcutableWidget->setItem(1, 4, new QTableWidgetItem("kΩ"));
         bcutableWidget->setItem(2, 4, new QTableWidgetItem("kΩ"));
         bcutableWidget->setItem(3, 4, new QTableWidgetItem("0.1°"));
         bcutableWidget->setItem(4, 4, new QTableWidgetItem("0.1V"));
         bcutableWidget->setItem(5, 4, new QTableWidgetItem("0.1°"));
         bcutableWidget->setItem(6, 4, new QTableWidgetItem("0.1°"));
         bcutableWidget->setItem(7, 4, new QTableWidgetItem("0.1°"));
         bcutableWidget->setItem(8, 4, new QTableWidgetItem("0.1°"));
         bcutableWidget->setItem(9, 4, new QTableWidgetItem("0.1°"));
         bcutableWidget->setItem(10, 4, new QTableWidgetItem("0.1°"));
         bcutableWidget->setItem(11, 4, new QTableWidgetItem("0.1°"));
         QPushButton* bcubutton = new QPushButton("下发 ", this);
         connect(bcubutton, SIGNAL(clicked()), this, SLOT(on_bcubutton_clicked()));
         bcutableWidget->setCellWidget(i, 5, bcubutton);

       //  QPushButton* bcureadbutton = new QPushButton("读取 ", this);
       ////  connect(bcureadbutton, SIGNAL(clicked()), this, SLOT(on_bcubutton_clicked()));
       //  bcutableWidget->setCellWidget(i, 5, bcureadbutton);

     }

     QTimer *timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()), this, SLOT(updateUiData()));
     timer->start();
     timer->setInterval(500);
     
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
                bcutableWidget->hide();
            }
            else if (str == "温度注入故障")
            {
                temptableWidget->show();
                volttableWidget->hide();
                bcutableWidget->hide();
            }
            else if (str == "BCU注入故障")
            {
                bcutableWidget->show();
                volttableWidget->hide();
                temptableWidget->hide();
            }
        });
}

void FaultInjection::on_button_clicked()
{
    QPushButton* obj = dynamic_cast<QPushButton*>(this->sender());
    int x = obj->frameGeometry().x();
    int y = obj->frameGeometry().y();
    QModelIndex index = volttableWidget->indexAt(QPoint(x, y));
    int currentRow = index.row();
    QString val = volttableWidget->item(currentRow, 3)->text();//
    QString val_t = temptableWidget->item(currentRow, 3)->text();//
    unsigned char data_from_text[8] = { 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff };
    QWidget* cellwidgetT = temptableWidget->cellWidget(currentRow, 0);
    QCheckBox* checkBoxT = dynamic_cast<QCheckBox*>(cellwidgetT);
    QWidget* cellwidgetV = volttableWidget->cellWidget(currentRow, 0);
    QCheckBox* checkBoxV = dynamic_cast<QCheckBox*>(cellwidgetV);
    uint16_t bmuid =ui.comboBox_2->currentIndex();
    if (ui.cBDeviceType->currentText().contains("BCU"))
    {
        if (drvmng::getInstance().drv_connect_state() == _EthCnn)
        {
            if (ui.comboBox->currentText().contains("电压"))
            {
                bmbcuVTFaultSet(ui.comboBox->currentText(), currentRow, ui.checkBox->isChecked(), val.toInt(nullptr, 10));
            }
            else if (ui.comboBox->currentText().contains("温度"))
            {
                bmbcuVTFaultSet(ui.comboBox->currentText(), currentRow, ui.checkBox->isChecked(), val_t.toInt(nullptr, 10));
            }
         }
        else if (drvmng::getInstance().drv_connect_state() == _CanCnn)
        {
            uint32_t frameId = 0;
            frameId = drvmng::getInstance().dr_make_can_ID(PARAMETER_PRIO, 0, bmuid + 1, PC_ADDR);
            //Data0： 1 电压，2 温度  Data1： 1 使能，0 关闭Data3：模拟数据位置Data4：模拟数据高 8 位Data5：模拟数据低 8 位
            if (ui.comboBox->currentText().contains("电压"))
            {
                data_from_text[0] = 0x16;
                data_from_text[1] = 0x28 | 0x80;
                data_from_text[2] = 5;//长度
                data_from_text[3] = 1;//Data0： 1 电压，2 温度Data1：
                if (cellwidgetV) {
                    data_from_text[4] = checkBoxV->isChecked();
                    // 例如，你可以打印是否选中
                }
                data_from_text[6] = val.toUInt(nullptr, 10) >> 8;
                data_from_text[7] = val.toUInt(nullptr, 10) & 0xff;
            }
            if (ui.comboBox->currentText().contains("温度"))
            {
                data_from_text[0] = 0x1A;
                data_from_text[1] = 0x28 | 0x80;
                if (cellwidgetT) {
                    data_from_text[4] = checkBoxT->isChecked();
                    // 例如，你可以打印是否选中
                }
                data_from_text[6] = val_t.toInt(nullptr, 10) >> 8;
                data_from_text[7] = val_t.toInt(nullptr, 10) & 0xff;
            }
            data_from_text[5] = currentRow;  // 位置 0开始
            drvmng::getInstance().CanSnd(frameId, data_from_text, 8);
        }
     }
    else if (ui.cBDeviceType->currentText().contains("BMU"))
    {
        if (drvmng::getInstance().drv_connect_state() == _CanCnn)
        {
            uint32_t frameId = 0;
            uint16_t  divisor = currentRow / 3 ;// 分段索引//1 - 36 
            uint16_t  remainder = currentRow % 3;
            frameId = drvmng::getInstance().dr_make_can_ID(PARAMETER_PRIO, 0x2, bmuid + 1, PC_ADDR);
            //Data0： 1 电压，2 温度  Data1： 1 使能，0 关闭Data3：模拟数据位置Data4：模拟数据高 8 位Data5：模拟数据低 8 位
            if (ui.comboBox->currentText().contains("电压"))
            {
                data_from_text[0] = divisor+1;
                if (remainder == 0)
                {
                          m_bmuvolt_t[bmuid][currentRow] = val.toInt(nullptr, 10);
                    data_from_text[2] = val.toInt(nullptr, 10) >> 8;;
                    data_from_text[1] = val.toInt(nullptr, 10) & 0xff;
              
                }
                else if (remainder == 1)
                {
                    data_from_text[4] = val.toInt(nullptr, 10) >> 8;;
                    data_from_text[3] = val.toInt(nullptr, 10) & 0xff;

                }if (remainder == 2)
                {
                    data_from_text[6] = val.toInt(nullptr, 10) >> 8;;
                    data_from_text[5] = val.toInt(nullptr, 10) & 0xff;
                }
            }
            if (ui.comboBox->currentText().contains("温度"))
            {
                data_from_text[0] = divisor+37;// 分段索引37 - 72 
                if (remainder == 0)
                {
                    data_from_text[2] = val_t.toInt(nullptr, 10) >> 8;;
                    data_from_text[1] = val_t.toInt(nullptr, 10) & 0xff;
                }
                else if (remainder == 1)
                {
                    data_from_text[4] = val_t.toInt(nullptr, 10) >> 8;;
                    data_from_text[3] = val_t.toInt(nullptr, 10) & 0xff;

                }if (remainder == 2)
                {
                    data_from_text[6] = val_t.toInt(nullptr, 10) >> 8;;
                    data_from_text[5] = val_t.toInt(nullptr, 10) & 0xff;
                }

            }

            drvmng::getInstance().CanSnd(frameId, data_from_text, 8);
        }
        else if (drvmng::getInstance().drv_connect_state() == _EthCnn)
        {
            ethbmuVTFaultSet(ui.comboBox->currentText(), currentRow, ui.checkBox->isChecked(), val_t.toInt(nullptr, 10));
        }

    }
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

void FaultInjection::bmbcufaultSet(QString name, int currentRow, uint16_t Type, uint16_t val)
{
    //   << "电流" << "负级绝缘电阻" << "正级绝缘电阻" << "电池电压" << "P+P-电压" << "电流温度" << "PCB温度" << "P-温度" << "P+温度" << "电池-温度" << "电池+温度";
    QVector<quint16> writeValue;
    if (name.contains("电流"))
    {
        writeValue.append(val);
        drvmng::getInstance().mb_downmsg_holding("Write", 0x2811, writeValue);
        writeValue.clear();
        writeValue.append(Type);
        drvmng::getInstance().mb_downmsg_holding("Write", 0x2810, writeValue);
    }

    else if (name.contains("负级绝缘电阻"))
    {
        writeValue.append(val);
        drvmng::getInstance().mb_downmsg_holding("Write", 0x2813, writeValue);
        writeValue.clear();
        writeValue.append(Type);
        drvmng::getInstance().mb_downmsg_holding("Write", 0x2812, writeValue);

    }
    else if (name.contains("正级绝缘电阻"))
    {
        writeValue.append(val);
        drvmng::getInstance().mb_downmsg_holding("Write", 0x2813, writeValue);
        writeValue.clear();
        if (Type == 1)
        {
            Type = 2;
        }
        writeValue.append(Type);
        drvmng::getInstance().mb_downmsg_holding("Write", 0x2812, writeValue);
    }
    else if (name.contains("电池电压"))
    {

        writeValue.append(val);
        drvmng::getInstance().mb_downmsg_holding("Write", 0x281f, writeValue);
        writeValue.clear();
        if (Type == 1)
        {
            Type = 1;
        }
        writeValue.append(Type);
        drvmng::getInstance().mb_downmsg_holding("Write", 0x281e, writeValue);
    }

    else if (name.contains("P+P-电压"))
    {

        writeValue.append(val);
        drvmng::getInstance().mb_downmsg_holding("Write", 0x281f, writeValue);
        writeValue.clear();
        if (Type == 1)
        {
            Type = SIM_STRING_VOLTAGE_STRING;
        }
        writeValue.append(Type);
        drvmng::getInstance().mb_downmsg_holding("Write", 0x281e, writeValue);
    }


    else if (name.contains("电流温度"))
    {
        writeValue.append(val);
        drvmng::getInstance().mb_downmsg_holding("Write", 0x2815, writeValue);
        writeValue.clear();
        if (Type == 1)
        {
            Type = SIM_BCU_TEMP_CURRENT;
        }
        writeValue.append(Type);
        drvmng::getInstance().mb_downmsg_holding("Write", 0x2814, writeValue);
    }
    else if (name.contains("PCB温度"))
    {
        writeValue.append(val);
        drvmng::getInstance().mb_downmsg_holding("Write", 0x2815, writeValue);
        writeValue.clear();
        if (Type == 1)
        {
            Type = SIM_BCU_TEMP_PCB;
        }
        writeValue.append(Type);
        drvmng::getInstance().mb_downmsg_holding("Write", 0x2814, writeValue);
    }
    else if (name.contains("P-温度"))
    {
        writeValue.append(val);
        drvmng::getInstance().mb_downmsg_holding("Write", 0x2815, writeValue);
        writeValue.clear();
        if (Type == 1)
        {
            Type = SIM_BCU_TEMP_PACK_N;
        }
        writeValue.append(Type);
        drvmng::getInstance().mb_downmsg_holding("Write", 0x2814, writeValue);
    }
    else if (name.contains("P+温度"))
    {
        writeValue.append(val);
        drvmng::getInstance().mb_downmsg_holding("Write", 0x2815, writeValue);
        writeValue.clear();
        if (Type == 1)
        {
            Type = SIM_BCU_TEMP_PACK_P;
        }
        writeValue.append(Type);
        drvmng::getInstance().mb_downmsg_holding("Write", 0x2814, writeValue);
    }
    else if (name.contains("电池-温度"))
    {
        writeValue.append(val);
        drvmng::getInstance().mb_downmsg_holding("Write", 0x2815, writeValue);
        writeValue.clear();
        if (Type == 1)
        {
            Type = SIM_BCU_TEMP_PACK_N;
        }
        writeValue.append(Type);
        drvmng::getInstance().mb_downmsg_holding("Write", 0x2814, writeValue);
    }
    else if (name.contains("电池+温度"))
    {
        writeValue.append(val);
        drvmng::getInstance().mb_downmsg_holding("Write", 0x2815, writeValue);
        writeValue.clear();
        if (Type == 1)
        {
            Type = SIM_BCU_TEMP_PACK_P;
        }
        writeValue.append(Type);
        drvmng::getInstance().mb_downmsg_holding("Write", 0x2814, writeValue);
    }
    else if (name.contains("SOC"))
    {
        writeValue.append(val);
        drvmng::getInstance().mb_downmsg_holding("Write", 0x2820, writeValue);
        writeValue.clear();
        writeValue.append(Type);
        drvmng::getInstance().mb_downmsg_holding("Write", 0x2821, writeValue);
    }
}

void FaultInjection::bmbcuVTFaultSet(QString name, int currentRow, uint16_t type, uint16_t val)
{
    QVector<quint16> writeValue;
    uint16_t BmuIndex = ui.comboBox_2->currentIndex();
    uint16_t BmuType = type;
    uint16_t CellIndex = currentRow;
    if (ui.comboBox_2->currentIndex() == 16)
    {
        BmuIndex = 0xff;
    }
    if (ui.comboBox->currentText().contains("电压"))
    {
        QWidget* cellwidgetV = volttableWidget->cellWidget(currentRow, 0);
        QCheckBox* checkBoxV = dynamic_cast<QCheckBox*>(cellwidgetV);
        BmuType = checkBoxV->isChecked();
        if (ui.checkBox->isChecked())
        {
            BmuType = 0xff;
        }
        writeValue.append(BmuType);
        writeValue.append(BmuIndex);
        writeValue.append(CellIndex);
        writeValue.append(val);
        drvmng::getInstance().mb_downmsg_holding("Write", 0x2816, writeValue);
    }
    else  if (ui.comboBox->currentText().contains("温度"))
    {
        QWidget* cellwidgetT = temptableWidget->cellWidget(currentRow, 0);
        QCheckBox* checkBoxT = dynamic_cast<QCheckBox*>(cellwidgetT);
        BmuType = checkBoxT->isChecked();
        if (ui.checkBox->isChecked())
        {
            BmuType = 0xff;
        }
        writeValue.append(BmuType);
        writeValue.append(BmuIndex);
        writeValue.append(CellIndex);
        writeValue.append(val);
        drvmng::getInstance().mb_downmsg_holding("Write", 0x281a, writeValue);
    }
}

void FaultInjection::ethbmuVTFaultSet(QString name, int currentRow, uint16_t type, uint16_t val)
{
}


void FaultInjection::on_bcubutton_clicked()
{
    QPushButton* obj = dynamic_cast<QPushButton*>(this->sender());
    int x = obj->frameGeometry().x();
    int y = obj->frameGeometry().y();
    QModelIndex index = bcutableWidget->indexAt(QPoint(x, y));
    int currentRow = index.row();
    QWidget* cellwidget = bcutableWidget->cellWidget(currentRow, 0);
    QCheckBox* checkBox = dynamic_cast<QCheckBox*>(cellwidget);
    QString name = bcutableWidget->item(currentRow, 1)->text();//
    QString val = bcutableWidget->item(currentRow, 2)->text();//
    uint16_t Type = checkBox->isChecked();
    int16_t u16val = val.toInt(nullptr, 10);
    if (drvmng::getInstance().drv_connect_state() == _CanCnn)
    {
        //   << "电流" << "负级绝缘电阻" << "正级绝缘电阻" << "电池电压" << "P+P-电压" << "电流温度" << "PCB温度" << "P-温度" << "P+温度" << "电池-温度" << "电池+温度";
        uint32_t frameId = 0;
        unsigned char data_from_text[8] = { 0 };
        frameId = drvmng::getInstance().dr_make_can_ID(PARAMETER_PRIO, 0,0xA1 , PC_ADDR);
        if (name.contains("电流"))
        {
            data_from_text[0] = 0x11;
            data_from_text[1] = 0x28 | 0x80;
            data_from_text[2] = 2;//长度
            data_from_text[3] = u16val>>8;
            data_from_text[4] = u16val&0xff;
            drvmng::getInstance().CanSnd(frameId, data_from_text, 8);
            data_from_text[0] = 0x10;
            data_from_text[1] = 0x28 | 0x80;
            data_from_text[2] =2;//长度
            data_from_text[3] = 0;
            data_from_text[4] = Type;
            drvmng::getInstance().CanSnd(frameId, data_from_text, 8);
        }
        if (name.contains("负级绝缘"))
        {
            data_from_text[0] = 0x13;
            data_from_text[1] = 0x28 | 0x80;
            data_from_text[2] = 2;//长度
            data_from_text[3] = u16val >> 8;
            data_from_text[4] = u16val & 0xff;
            drvmng::getInstance().CanSnd(frameId, data_from_text, 8);
            data_from_text[0] = 0x12;
            data_from_text[1] = 0x28 | 0x80;
            data_from_text[2] = 2;//长度
            data_from_text[3] = 0;
            data_from_text[4] = Type;
            drvmng::getInstance().CanSnd(frameId, data_from_text, 8);
        }

        if (name.contains("正级绝缘"))
        {
            data_from_text[0] = 0x13;
            data_from_text[1] = 0x28 | 0x80;
            data_from_text[2] = 2;//长度
            data_from_text[3] = u16val >> 8;
            data_from_text[4] = u16val & 0xff;
            drvmng::getInstance().CanSnd(frameId, data_from_text, 8);
            data_from_text[0] = 0x12;
            data_from_text[1] = 0x28 | 0x80;
            data_from_text[2] = 2;//长度
            if (Type == 1)
            {
                Type = 2;
            }
            data_from_text[3] = 0;
            data_from_text[4] = Type;
            drvmng::getInstance().CanSnd(frameId, data_from_text, 8);
        }

        if (name.contains("电池电压"))
        {
            data_from_text[0] = 0x1F;
            data_from_text[1] = 0x28 | 0x80;
            data_from_text[2] = 2;//长度
            data_from_text[3] = u16val >> 8;
            data_from_text[4] = u16val & 0xff;
            drvmng::getInstance().CanSnd(frameId, data_from_text, 8);
            data_from_text[0] = 0x1E;
            data_from_text[1] = 0x28 | 0x80;
            data_from_text[2] = 2;//长度
            data_from_text[3] = 0;
            data_from_text[4] = Type;
            drvmng::getInstance().CanSnd(frameId, data_from_text, 8);
        }

        if (name.contains("P+P-电压"))
        {
            data_from_text[0] = 0x1F;
            data_from_text[1] = 0x28 | 0x80;
            data_from_text[2] = 2;//长度
            data_from_text[3] = u16val >> 8;
            data_from_text[4] = u16val & 0xff;
            drvmng::getInstance().CanSnd(frameId, data_from_text, 8);
            data_from_text[0] = 0x1E;
            data_from_text[1] = 0x28 | 0x80;
            data_from_text[2] = 2;//长度
            data_from_text[3] = 0;
            if (Type == 1)
            {
                Type = 2;
            }
            data_from_text[4] = Type;
            drvmng::getInstance().CanSnd(frameId, data_from_text, 8);
        }
        if (name.contains("电流温度"))
        {
            data_from_text[0] = 0x15;
            data_from_text[1] = 0x28 | 0x80;
            data_from_text[2] = 2;//长度
            data_from_text[3] = u16val >> 8;
            data_from_text[4] = u16val & 0xff;
            drvmng::getInstance().CanSnd(frameId, data_from_text, 8);
            data_from_text[0] = 0x14;
            data_from_text[1] = 0x28 | 0x80;
            data_from_text[2] = 2;//长度
            if (Type == 1)
            {
                Type = SIM_BCU_TEMP_CURRENT;
            }
            data_from_text[3] = 0;
            data_from_text[4] = Type;
            drvmng::getInstance().CanSnd(frameId, data_from_text, 8);
        }
        if (name.contains("PCB温度"))
        {
            data_from_text[0] = 0x15;
            data_from_text[1] = 0x28 | 0x80;
            data_from_text[2] = 2;//长度
            data_from_text[3] = u16val >> 8;
            data_from_text[4] = u16val & 0xff;
            drvmng::getInstance().CanSnd(frameId, data_from_text, 8);
            data_from_text[0] = 0x14;
            data_from_text[1] = 0x28 | 0x80;
            data_from_text[2] = 2;//长度
            if (Type == 1)
            {
                Type = SIM_BCU_TEMP_PCB;
            }
            data_from_text[3] = 0;
            data_from_text[4] = Type;
            drvmng::getInstance().CanSnd(frameId, data_from_text, 8);
        }

        if (name.contains("P-温度"))
        {
            data_from_text[0] = 0x15;
            data_from_text[1] = 0x28 | 0x80;
            data_from_text[2] = 2;//长度
            data_from_text[3] = u16val >> 8;
            data_from_text[4] = u16val & 0xff;
            drvmng::getInstance().CanSnd(frameId, data_from_text, 8);
            data_from_text[0] = 0x14;
            data_from_text[1] = 0x28 | 0x80;
            data_from_text[2] = 2;//长度
            if (Type == 1)
            {
                Type = SIM_BCU_TEMP_PACK_N;
            }
            data_from_text[3] = 0;
            data_from_text[4] = Type;
            drvmng::getInstance().CanSnd(frameId, data_from_text, 8);
        }

        if (name.contains("P+温度"))
        {
            data_from_text[0] = 0x15;
            data_from_text[1] = 0x28 | 0x80;
            data_from_text[2] = 2;//长度
            data_from_text[3] = u16val >> 8;
            data_from_text[4] = u16val & 0xff;
            drvmng::getInstance().CanSnd(frameId, data_from_text, 8);
            data_from_text[0] = 0x14;
            data_from_text[1] = 0x28 | 0x80;
            data_from_text[2] = 2;//长度
            if (Type == 1)
            {
                Type = SIM_BCU_TEMP_PACK_P;
            }
            data_from_text[3] = 0;
            data_from_text[4] = Type;
            drvmng::getInstance().CanSnd(frameId, data_from_text, 8);
        }
        if (name.contains("电池-温度"))
        {
            data_from_text[0] = 0x15;
            data_from_text[1] = 0x28 | 0x80;
            data_from_text[2] = 2;//长度
            data_from_text[3] = u16val >> 8;
            data_from_text[4] = u16val & 0xff;
            drvmng::getInstance().CanSnd(frameId, data_from_text, 8);
            data_from_text[0] = 0x14;
            data_from_text[1] = 0x28 | 0x80;
            data_from_text[2] = 2;//长度
            if (Type == 1)
            {
                Type = SIM_BCU_TEMP_BATTERY_N;
            }
            data_from_text[3] = 0;
            data_from_text[4] = Type;
            drvmng::getInstance().CanSnd(frameId, data_from_text, 8);
        }
        if (name.contains("电池+温度"))
        {
            data_from_text[0] = 0x15;
            data_from_text[1] = 0x28 | 0x80;
            data_from_text[2] = 2;//长度
            data_from_text[3] = u16val >> 8;
            data_from_text[4] = u16val & 0xff;
            drvmng::getInstance().CanSnd(frameId, data_from_text, 8);
            data_from_text[0] = 0x14;
            data_from_text[1] = 0x28 | 0x80;
            data_from_text[2] = 2;//长度
            if (Type == 1)
            {
                Type = SIM_BCU_TEMP_BATTERY_P;
            }
            data_from_text[3] = 0;
            data_from_text[4] = Type;
            drvmng::getInstance().CanSnd(frameId, data_from_text, 8);
        }
    }
    else if (drvmng::getInstance().drv_connect_state() == _EthCnn)
    {
        bmbcufaultSet(name, currentRow,Type,u16val);
    }
}

void FaultInjection::on_cBDeviceType_currentTextChanged(const QString& arg1)
{
    ui.comboBox->clear();
    QStringList str;
    if (arg1 == "BCU")
    {
        str << "BCU注入故障"<<"温度注入故障"<<"电压注入故障";
        ui.comboBox_2->setEnabled(true);
    }
    else if(arg1 == "BMU")
    {
        str << "温度注入故障" << "电压注入故障";
        ui.comboBox_2->setEnabled(true);
    }        
    ui.comboBox->addItems(str);
}

void FaultInjection::updateUiData()
{
    uint16_t bmuid = ui.comboBox_2->currentIndex();
    if (ui.comboBox->currentText().contains("温度"))
    {
     for (int i=0;i<16;i++)
    temptableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(g_PackDetailInfoST[bmuid].BatTemps[i]),10));
    }
    else if (ui.comboBox->currentText().contains("电压"))
    {
        for (int i = 0; i < 16; i++)
            volttableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(g_PackDetailInfoST[bmuid].BatVols[i]), 10));
    }
    else if (ui.comboBox->currentText().contains("BCU"))
    {

        //bcutableStr << "电流" << "负级绝缘电阻" << "正级绝缘电阻" \
        //    << "电池电压" << "P+P-电压" << "电流温度" << "PCB温度" << "P-温度" << "P+温度" << "电池-温度" << "电池+温度" \
        //    << "DI_POWER_5V" << "DI_POWER_24V" << "DI_MCU_FTL1" << "DI_MCU_FTL2"\
        //    << "DI_MCU_FTL3" << "DI_MCU_FTL4" << "DI_温度传感器"\
        //    << "DI_急停传感器" << "DI_水浸传感器" << "DI_消防传感器"\
        //    << "DI_ENTRANCE_SENSO" << "DI_烟感" << "DI_减法器"\
        //    << "DI_CONT_PLUS" << "DI_CONT_TRIP";

            bcutableWidget->setItem(0, 2, new QTableWidgetItem(QString::number(g_BCUDetailInfoST.bcuStateBase1.MODBUS_CLUSTER_CUR), 10));
            bcutableWidget->setItem(1, 2, new QTableWidgetItem(QString::number(g_BCUDetailInfoST.bcuStateBase1.MODBUS_NEGATIVE_BUS_RESISTANCE), 10));
            bcutableWidget->setItem(2, 2, new QTableWidgetItem(QString::number(g_BCUDetailInfoST.bcuStateBase1.MODBUS_POSITIVE_BUS_RESISTANCE), 10));
            bcutableWidget->setItem(3, 2, new QTableWidgetItem(QString::number(g_BCUDetailInfoST.bcuStateBase1.MODBUS_CLUSTER_VOLT), 10));
            bcutableWidget->setItem(4, 2, new QTableWidgetItem(QString::number(g_BCUDetailInfoST.bcuStateBase1.MODBUS_P_VOLT), 10));
            bcutableWidget->setItem(5, 2, new QTableWidgetItem(QString::number(g_BCUDetailInfoST.bcuStateBase2.MODBUS_CURRENT_TEMP), 10));
            bcutableWidget->setItem(6, 2, new QTableWidgetItem(QString::number(g_BCUDetailInfoST.bcuStateBase2.MODBUS_PCB_TEMP), 10));
            bcutableWidget->setItem(7, 2, new QTableWidgetItem(QString::number(g_BCUDetailInfoST.bcuStateBase2.MODBUS_PACK_PLUS_TEMP), 10));
            bcutableWidget->setItem(8, 2, new QTableWidgetItem(QString::number(g_BCUDetailInfoST.bcuStateBase2.MODBUS_PACK_MINUS_TEMP), 10));
            bcutableWidget->setItem(9, 2, new QTableWidgetItem(QString::number(g_BCUDetailInfoST.bcuStateBase2.MODBUS_BATTERY_PLUS_TEMP), 10));
            bcutableWidget->setItem(10, 2, new QTableWidgetItem(QString::number(g_BCUDetailInfoST.bcuStateBase2.MODBUS_BATTERY_MINUS_TEMP), 10));

    }
}
