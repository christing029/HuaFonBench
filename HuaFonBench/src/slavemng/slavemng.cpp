#include "slavemng.h"
#include "ui_slavemng.h"
#include <QFile>
#include <QMessageBox>
#include <QTranslator>
#include <mainwindow.h>
SlaveMng::SlaveMng(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SlaveMng)
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
    InitUi();
    setAttribute(Qt::WA_Mapped);;
    faultInj = new FaultInjection();
    connect(ui->comboBox, QOverload<const QString&>::of(&QComboBox::currentTextChanged), [=](const QString& str)
        {
            if (str == "故障注入")
            {
                faultInj->show();
                ui->tableWidget->hide();
                ui->verticalLayout->addWidget(faultInj);
            }
            else if (str == "从机基本设置")
            {
               faultInj->hide();
               ui->tableWidget->show();
            }
        });
}

SlaveMng::~SlaveMng()
{
    delete ui;
}


void SlaveMng::InitUi()
{
    json js;
  //  ui->tableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers ); //禁止双击编辑
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->resizeColumnToContents(0);
    QHeaderView *widthlist  = ui->tableWidget->horizontalHeader();
    widthlist->setStyleSheet("border:Opx;background-color: #f2f1f7;\ncolor: rgb(127, 127, 127);");
    widthlist->resizeSection(0,80);
    widthlist->resizeSection(1,80);
    widthlist->resizeSection(2,80);

    QStringList headlist;
    headlist << "参数名称" << "地址" << "长度" << "默认值" << "实际值" << "单位" << "下设" << "读取";
    ui->tableWidget->setHorizontalHeaderLabels(headlist);
    js.readslacecfg();
        //设置表格列数
    //统计现有的表格行
    int t_rowCount = ui->tableWidget->rowCount();
    //t_groupName 为一个数组，存放数据，添加到表格
    for (int i = 0; i < js.JsonTxt[0].mModule.size(); i++)
    {
        //insertRow()插入一行。
        ui->tableWidget->insertRow(t_rowCount + i);		//按需求加行
        ui->tableWidget->setItem(t_rowCount + i, COLUMN_NAME, new QTableWidgetItem(js.JsonTxt[0].mModule[i].TopicName));
        ui->tableWidget->setItem(t_rowCount + i, COLUMN_REG_ADDRESS, new QTableWidgetItem(js.JsonTxt[0].mModule[i].StartAddress));
        ui->tableWidget->setItem(t_rowCount + i, COLUMN_OFFSET_LEN, new QTableWidgetItem(js.JsonTxt[0].mModule[i].OffSetAddress));
        ui->tableWidget->setItem(t_rowCount + i, COLUMN_DEFAULT_VAL, new QTableWidgetItem(js.JsonTxt[0].mModule[i].Val_def));
        ui->tableWidget->setItem(t_rowCount + i, COLUMN_REAL_VAL, new QTableWidgetItem(js.JsonTxt[0].mModule[i].Val_real));
        ui->tableWidget->setItem(t_rowCount + i, COLUMN_Uint_VAL, new QTableWidgetItem(js.JsonTxt[0].mModule[i].Unit));

        QTableWidgetItem* item;
        item = ui->tableWidget->item(i, COLUMN_NAME);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        item = ui->tableWidget->item(i, COLUMN_DEFAULT_VAL);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        item = ui->tableWidget->item(i, COLUMN_REG_ADDRESS);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        item = ui->tableWidget->item(i, COLUMN_OFFSET_LEN);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable);

        if (js.JsonTxt[0].mModule[i].RW.contains("W"))
        {

            QPushButton* button = new QPushButton("下发", this);
            connect(button, SIGNAL(clicked()), this, SLOT(on_button_clicked()));
            ui->tableWidget->setCellWidget(t_rowCount + i, COLUMN_SET_BUTTON, button);
        }
        if (js.JsonTxt[0].mModule[i].RW.contains("R"))
        {
            QPushButton* readbutton = new QPushButton("读取", this);
            ui->tableWidget->setCellWidget(t_rowCount + i, COLUMN_GET_BUTTON, readbutton);
            connect(readbutton, SIGNAL(clicked()), this, SLOT(on_readbutton_clicked()));
        }
        }
}
void SlaveMng::SlaveCanReadDataSnd(int row)
{
    unsigned char data_from_text[8] = { 0 };
    uint32_t id;
    uint32_t bmu_add = ui->cb_channle->currentIndex()+1;
    
    QString ID = ui->tableWidget->item(row, COLUMN_REG_ADDRESS)->text();//
    QString val = ui->tableWidget->item(row, COLUMN_REAL_VAL)->text();//
    QString len = ui->tableWidget->item(row, COLUMN_OFFSET_LEN)->text();//
    id=  drvmng::getInstance().dr_make_can_ID(PARAMETER_PRIO,0, bmu_add, PC_ADDR);
   uint   IDVal= ID.toUInt(NULL, 16) | 0;
    data_from_text[1] = IDVal >>8;
    data_from_text[0] = IDVal&0xff;
    data_from_text[2] = ui->tableWidget->item(row, COLUMN_OFFSET_LEN)->text().toUInt(NULL, 10);
    drvmng::getInstance().CanSnd(id, data_from_text,8);
}
void SlaveMng::SlaveCanWriteDataSnd(int row)
{
    unsigned char data_from_text[8] = { 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20 };
    uint8_t  data_from_text1[8] = { 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20 };
    uint32_t id;
    uint32_t bmu_add = ui->cb_channle->currentIndex() + 1;
    QString ID = ui->tableWidget->item(row, COLUMN_REG_ADDRESS)->text();//
    QString val = ui->tableWidget->item(row, COLUMN_REAL_VAL)->text();//
    id = drvmng::getInstance().dr_make_can_ID(PARAMETER_PRIO, 0, bmu_add, PC_ADDR);
    uint   IDVal = ID.toUInt(NULL, 16) | 0x8000;
    uint8_t len= ui->tableWidget->item(row, COLUMN_OFFSET_LEN)->text().toUInt(NULL, 10);
    if (ui->tableWidget->item(m_currentrow, COLUMN_Uint_VAL)->text() == "字符串")
    {
        QByteArray dataArry(16, ' ');
        dataArry = val.toUtf8();
        dataArry.append(QByteArray(16- dataArry.count(), ' ')); // 在数组后面添加10个零
        if (len < 5)
        {
            data_from_text[0] = IDVal & 0xff;
            data_from_text[1] = IDVal >> 8;
            data_from_text[2] = len;
            data_from_text[3] = 1;
            data_from_text[4] = dataArry[0];
            data_from_text[5] = dataArry[1];
            data_from_text[6] = dataArry[2];
            data_from_text[7] = dataArry[3];
            drvmng::getInstance().CanSnd(id, data_from_text, len+4);
        }
        else
        {
            uint8_t remlen = 0;
            data_from_text[0] = IDVal & 0xff;
            data_from_text[1] = IDVal >> 8;
            data_from_text[2] = len;
            data_from_text[3] = 1;
            data_from_text[4] = dataArry[0];
            data_from_text[5] = dataArry[1];
            data_from_text[6] = dataArry[2];
            data_from_text[7] = dataArry[3];
            drvmng::getInstance().CanSnd(id, data_from_text, 8);
            remlen = len - 4;
            uint8_t index = 1;
            while (remlen != 0)
            {
                data_from_text1[0] = ++index;
                if (remlen < 7)
                {
                    for (int i = 0; i < remlen; i++) {
                        data_from_text1[i + 1] = dataArry[4 + (index - 2) * 7 + i];
                    }
                    drvmng::getInstance().CanSnd(id, data_from_text1, remlen + 1);
                    remlen = 0;
                }
                else
                {
                    for (int i = 0; i < 7; i++) {
                        data_from_text1[i+1] = dataArry[4 + (index - 2) * 7 +i];
                    }
                    remlen = remlen - 7;
                    drvmng::getInstance().CanSnd(id, data_from_text1, 8);
                }
            }
        }
    }
    else if (len < 5)
    {
        data_from_text[0] = IDVal & 0xff;
        data_from_text[1] = IDVal >> 8;
        data_from_text[2] = len;
        data_from_text[3] = 1;
        uint data = val.toUInt(NULL, 16);
        data_from_text[4] = data >> 24;
        data_from_text[5] = (data >> 16) & 0xff;
        data_from_text[6] = (data >> 8) & 0xff;
        data_from_text[7] = (data) & 0xff;
        drvmng::getInstance().CanSnd(id, data_from_text, 8);
    }
    else 
    {
        uint8_t remlen = 0;
        data_from_text[0] = IDVal & 0xff;
        data_from_text[1] = IDVal >> 8;
        data_from_text[2] = len;
        data_from_text[3] = 1;
        uint data = val.toUInt(NULL, 16);
        data_from_text[4] = data >> 24;
        data_from_text[5] = (data >> 16) & 0xff;
        data_from_text[6] = (data >> 8) & 0xff;
        data_from_text[7] = (data) & 0xff;
        drvmng::getInstance().CanSnd(id, data_from_text, 8);
        remlen = len - 4;
        uint8_t index = 1;
       /* while (remlen != 0)
        {
            data_from_text[0] = ++index;
            if (remlen < 7)
            {
                for (int i = 0; i < remlen; i++) {
                    data_from_text[i + 1] = dataArry[4 + (index - 2) * 7 + i];
                }
                drvmng::getInstance().CanSnd(id, data_from_text, remlen + 1);
                remlen = 0;
            }
            else
            {
                for (int i = 0; i < 7; i++) {
                    data_from_text1[i + 1] = dataArry[4 + (index - 2) * 7 + i];
                }
                remlen = remlen - 7;
                drvmng::getInstance().CanSnd(id, data_from_text, 8);
            }
        }
    }*/ 
    }
}
void SlaveMng::on_button_clicked()
{
    QPushButton* obj = dynamic_cast<QPushButton*>(this->sender());
    int x = obj->frameGeometry().x();
    int y = obj->frameGeometry().y();
    QModelIndex index = ui->tableWidget->indexAt(QPoint(x, y));
    int currentRow = index.row();
    //采用CanSlaveSnd
    SlaveCanWriteDataSnd(currentRow);
    QMessageBox::information(this, "", "send ok ");
   
}

void SlaveMng::on_readbutton_clicked()
{
    QPushButton* obj = dynamic_cast<QPushButton*>(this->sender());
    int x = obj->frameGeometry().x();
    int y = obj->frameGeometry().y();
    QModelIndex index = ui->tableWidget->indexAt(QPoint(x, y));
    int row = index.row();
    m_recByte.clear();
    m_dataTotalLen = 0;
    m_remdataLen = 8;
    m_indexcurr = 1;
    headflag = false;
    SlaveCanReadDataSnd(row);
    return;
}

void SlaveMng::SlotsCanUpBMUMsg(QString str, QByteArray data)
{
    // 开始数据
    BMU_CAN_RecMngData* MsgHead = (BMU_CAN_RecMngData*)data.data();
    // 中间数据
    BMU_CAN_RecMngData_Index* MsgIndex = (BMU_CAN_RecMngData_Index*)data.data();
    if ((m_indexcurr == MsgIndex->SegmentIndex)&& headflag)
    {
        if (m_remdataLen > 7)
        {
            m_recByte.append(reinterpret_cast<char*>(MsgIndex->Data), 7);
            m_remdataLen = m_remdataLen - 7;
            m_indexcurr++;
            return;
        }
        else
        {
            m_recByte.append(reinterpret_cast<char*>(MsgIndex->Data), m_remdataLen);
            m_remdataLen = 0;
        }
     }

    // 最后数据
    //第一包数据
    for (int row = 0; row < ui->tableWidget->rowCount(); row++)
    {
        QString address = ui->tableWidget->item(row, COLUMN_REG_ADDRESS)->text();
        int columu_address = address.toUInt(NULL, 16);
        if (columu_address == MsgHead->SegmentIndex)
        {
            headflag = true;
            m_currentrow = row;
            m_dataTotalLen = MsgHead->length;
            if (m_dataTotalLen < 5)
            {
                m_recByte.append(reinterpret_cast<char*>(MsgHead->Data), m_dataTotalLen);
                m_remdataLen = 0;

            }
            else
            {
   
                m_recByte.append(reinterpret_cast<char*>(MsgHead->Data),4);
                m_remdataLen = m_dataTotalLen -4;
                m_indexcurr++;

            }
        }
    }
    if (m_remdataLen == 0)
    {
        QString str = "";
        for (BYTE byte : m_recByte) {
            str += QString::number(byte, 16);
        }
        if (ui->tableWidget->item(m_currentrow, COLUMN_Uint_VAL)->text() == "字符串")
        {
            QString str1 = "";
            ui->tableWidget->item(m_currentrow, COLUMN_REAL_VAL)->setText(str1.prepend(m_recByte));
        }
        else
        {
            ui->tableWidget->item(m_currentrow, COLUMN_REAL_VAL)->setText(str);
        }
        m_recByte.clear();
        m_dataTotalLen = 0;
        m_remdataLen = 8;
        m_indexcurr = 1;
        headflag = false;
    }

}



