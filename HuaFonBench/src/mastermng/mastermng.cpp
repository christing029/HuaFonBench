#include "mastermng.h"
#include "ui_mastermng.h"
#include <QFile>
#include <QTranslator>
#include <src/drvmng/drvmng.h>

MasterMng::MasterMng(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MasterMng)
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
    bcucal = new BCUCalibration();
    connect(bcucal, SIGNAL(signalDownMsg(QString, uint, QVector<quint16>)), this, SLOT(SlotsCalDownMsgComing(QString, uint, QVector<quint16>)));
    connect(ui->comboBox, QOverload<const QString&>::of(&QComboBox::currentTextChanged),[=](const QString& str) 
        {
            QString file="";
            file = "./db/" + str + ".json";
            InitUi(file);
        });
    QStringList headlist;
    headlist << "参数名称" << "地址" << "字节" << "默认值" << "实际值"  <<"单位" << "下设" << "读取" ;
    ui->tableWidget->setHorizontalHeaderLabels(headlist);
    InitUi("./db/SOC基本设置.json");
 
}
MasterMng::~MasterMng()
{
    deleteLater();
}
void MasterMng::InitUi(QString JsonFile)
{
    json js;
    if (JsonFile == "./db/校准设置.json")
    {
        bcucal->show();
        ui->tableWidget->hide();
       ui->verticalLayout->addWidget(bcucal);
       return; 
    }
    //cal->show();
    bcucal->hide();
    ui->tableWidget->hide();
    ui->tableWidget->show();
    ui->tableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers); //
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->resizeColumnToContents(0);
    QHeaderView* widthlist = ui->tableWidget->horizontalHeader();
    widthlist->setStyleSheet("border:Opx;background-color: #f2f1f7;\ncolor: rgb(127, 127, 127);");
    widthlist->resizeSection(0, 80);
    widthlist->resizeSection(1, 80);
    widthlist->resizeSection(2, 80);
    while (ui->tableWidget->rowCount() > 0) {
        ui->tableWidget->removeRow(0);
    }
    this->ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
    js.read_master_mbtcpcfg(JsonFile);
    int t_rowCount = ui->tableWidget->rowCount();
    //
    for (int i = 0; i < js.JsonTxt[0].mModule.size(); i++)
    {
        //
        int Address = js.JsonTxt[0].mModule[i].StartAddress.toUInt(Q_NULLPTR,16) + js.JsonTxt[0].mModule[i].OffSetAddress.toUInt(Q_NULLPTR,10);
        ui->tableWidget->insertRow(t_rowCount + i);		//
        ui->tableWidget->setItem(t_rowCount + i, COLUMN_NAME, new QTableWidgetItem(js.JsonTxt[0].mModule[i].TopicName));
        ui->tableWidget->setItem(t_rowCount + i, COLUMN_DEFAULT_VAL, new QTableWidgetItem(js.JsonTxt[0].mModule[i].Val_def));
        ui->tableWidget->setItem(t_rowCount + i, COLUMN_REAL_VAL, new QTableWidgetItem(js.JsonTxt[0].mModule[i].Val_real));
        ui->tableWidget->setItem(t_rowCount + i, COLUMN_REG_ADDRESS, new QTableWidgetItem("0x" + QString::number( Address,16)));
        ui->tableWidget->setItem(t_rowCount + i, COLUMN_OFFSET_LEN, new QTableWidgetItem(js.JsonTxt[0].mModule[i].FORMATE));
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
            QPushButton* button = new QPushButton("下发 ", this);
            connect(button, SIGNAL(clicked()), this, SLOT(on_button_clicked()));
            ui->tableWidget->setCellWidget(t_rowCount + i, COLUMN_SET_BUTTON, button);
        }
        if (js.JsonTxt[0].mModule[i].RW.contains("R"))
        {
            QPushButton* readbutton = new QPushButton("读取 ", this);
            ui->tableWidget->setCellWidget(t_rowCount + i, COLUMN_GET_BUTTON, readbutton);
            connect(readbutton, SIGNAL(clicked()), this, SLOT(on_readbutton_clicked()));
        }
        }
}
void MasterMng::SlaveCanDataSnd(int row)
{

}
void MasterMng::on_button_clicked()
{
    QVector<quint16> writeValue;
    QPushButton* obj = dynamic_cast<QPushButton*>(this->sender());
    int x = obj->frameGeometry().x();
    int y = obj->frameGeometry().y();
    QModelIndex index = ui->tableWidget->indexAt(QPoint(x, y));
    int currentRow = index.row();
    QString address = ui->tableWidget->item(currentRow, COLUMN_REG_ADDRESS)->text();//
    QString val = ui->tableWidget->item(currentRow, COLUMN_REAL_VAL)->text();//
    if (ui->tableWidget->item(currentRow, COLUMN_OFFSET_LEN)->text() == "IP")
    {
        bool ok;
        QStringList str = val.split(".");
       uint16_t ip1= str[0].toInt(&ok, 10);
       uint16_t ip2 = str[1].toInt(&ok, 10);
       uint16_t ip3 = str[2].toInt(&ok, 10);
       uint16_t ip4 = str[3].toInt(&ok, 10);
       uint16_t hip = ip1 |(ip2 << 8);
       uint16_t lip = ip3 | (ip4 << 8);
       writeValue.append(hip);
       writeValue.append(lip);
    }
    else  if (ui->tableWidget->item(currentRow, COLUMN_OFFSET_LEN)->text() == "MAC")
    {
        bool ok;
        QStringList str = val.split("-");
        uint16_t mac1 = str[0].toInt(&ok, 16);
        uint16_t mac2 = str[1].toInt(&ok, 16);
        uint16_t mac3 = str[2].toInt(&ok, 16);
        uint16_t mac4 = str[3].toInt(&ok, 16);
        uint16_t mac5 = str[4].toInt(&ok, 16);
        uint16_t mac6 = str[5].toInt(&ok, 16);
        writeValue.append(mac1);
        writeValue.append(mac2);
        writeValue.append(mac3);
    }
    else
    {
    
        writeValue.append(val.toInt());
    }
    drvmng::getInstance().mb_downmsg_holding("Write", address.toUInt(NULL, 16), writeValue);
}

void MasterMng::on_readbutton_clicked()
{
    QVector<quint16> writeValue;
    QPushButton* obj = dynamic_cast<QPushButton*>(this->sender());
    int x = obj->frameGeometry().x();
    int y = obj->frameGeometry().y();
    QModelIndex index = ui->tableWidget->indexAt(QPoint(x, y));
    int currentRow = index.row();
    QString address = ui->tableWidget->item(currentRow, COLUMN_REG_ADDRESS)->text();//
    QString val = ui->tableWidget->item(currentRow, COLUMN_REAL_VAL)->text();//
    writeValue.append(val.toInt());
    if ((ui->tableWidget->item(currentRow, COLUMN_OFFSET_LEN)->text() == "2")|| (ui->tableWidget->item(currentRow, COLUMN_OFFSET_LEN)->text() == "IP"))
    {//
        writeValue.append(val.toInt());
    }
    if (ui->tableWidget->item(currentRow, COLUMN_OFFSET_LEN)->text() == "MAC")
    {//
        writeValue.append(val.toInt());
        writeValue.append(val.toInt());
    }
    drvmng::getInstance().mb_downmsg_holding("Read", address.toUInt(NULL, 16), writeValue);
     // emit signalDownMsg("Read", address.toUInt(NULL, 16), writeValue);
    return;
}

void MasterMng::on_bt_write_all_clicked()
{
    QVector<quint16> writeValue;
    QString address = ui->tableWidget->item(0, COLUMN_REG_ADDRESS)->text();//
    for (int row = 0; row < ui->tableWidget->rowCount(); row++)
    {
        QTableWidgetItem* item = ui->tableWidget->item(row, COLUMN_REAL_VAL);
        writeValue.append(item->text().toInt());
    }
    drvmng::getInstance().mb_downmsg_holding("Write", address.toUInt(NULL, 16), writeValue);
    //emit signalDownMsg("Write",address.toUInt(NULL, 16), writeValue);
}
void MasterMng::on_bt_read_all_clicked()
{
    QVector<quint16> writeValue(ui->tableWidget->rowCount());
    QString address = ui->tableWidget->item(0, COLUMN_REG_ADDRESS)->text();//
    QString val = ui->tableWidget->item(0, COLUMN_REAL_VAL)->text();//
    drvmng::getInstance().mb_downmsg_holding("Read", address.toUInt(NULL, 16), writeValue);
   // emit signalDownMsg("Read", address.toUInt(NULL, 16), writeValue);
    return;
}
void MasterMng::slotsUpReadHolding(uint startAddress, QVector<quint16> val)
{
    int index = 0;
    ///Fresh UI
    for (int row = 0; row < ui->tableWidget->rowCount(); row++)
    {
      QString address = ui->tableWidget->item(row, COLUMN_REG_ADDRESS)->text();
        int columu_address = address.toUInt(NULL, 16);
        for (int add = startAddress; add < startAddress + val.size(); add++)
        {
            if (columu_address == add)
            {
                /// <summary>
                /// 显示IP
                /// </summary>
                /// <param name="startAddress"></param>
                /// <param name="val"></param>
                if (ui->tableWidget->item(row, COLUMN_OFFSET_LEN)->text() =="IP")
                {
                     index = add - startAddress;
                    QString QIP = "192.168.0.1";
                    QIP=  QString::number(val[index]&0xff,10) +"."\
                         + QString::number(val[index]>>8, 10) + "."\
                         + QString::number(val[index+1] & 0xff, 10) + "."\
                         + QString::number(val[index+1]>>8 , 10);
                    ui->tableWidget->item(row, COLUMN_REAL_VAL)->setText(QIP);
                    break;
                }
                /// <summary>
                /// 显示MAC
                /// </summary>
                /// <param name="startAddress"></param>
                /// <param name="val"></param>
                if (ui->tableWidget->item(row, COLUMN_OFFSET_LEN)->text() == "MAC")
                {
                    index = add - startAddress;
                    QString QMac = "aa.bb.cc";
                    QMac = QString::number(val[index] & 0xff, 16) + "-"\
                        + QString::number(val[index] >> 8, 16) + "-"\
                        + QString::number(val[index + 1] & 0xff, 16) + "-"\
                        + QString::number(val[index + 1] >> 8, 16) + "-"\
                        + QString::number(val[index + 2] & 0xff, 16) + "-"\
                        + QString::number(val[index + 2] >> 8, 16);
                    ui->tableWidget->item(row, COLUMN_REAL_VAL)->setText(QMac);
                    break;
                }
                index = add - startAddress;
                ui->tableWidget->item(row, COLUMN_REAL_VAL)->setText(QString::number((INT16)val[index],10));
            }
        }
    }
}

void MasterMng::SlotsCalDownMsgComing(QString str, uint address, QVector<quint16> val)
{
    emit signalDownMsg("Write", address, val);
}
