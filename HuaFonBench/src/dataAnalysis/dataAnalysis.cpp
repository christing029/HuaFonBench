#include "dataAnalysis.h"
#include <QTreeWidget>
#include <QtGui/qstandarditemmodel.h>
#include  <QScrollBar>

dataAnalysis::dataAnalysis(QWidget *parent)
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
    InitUi();
    LoadBmuDB();
    myWidget = new QTableWidget();
    myWidget->resizeColumnsToContents();
}

dataAnalysis::~dataAnalysis()
{

}

void dataAnalysis::InitUi()
{
    ui.FirstPage->setIcon(QIcon(":/icon/pause.ico"));
    ui.NextPage->setIcon(QIcon(":/icon/start.ico"));
    ui.PreviousPage->setIcon(QIcon(":/icon/startall.ico"));
    ui.LastPage->setIcon(QIcon(":/icon/startall.ico"));
  /*  ui.StartPb->setIcon(QIcon(":/icon/start.ico"));
    ui.StopPb->setIcon(QIcon(":/icon/stopall.png"));
    ui.FastPb->setIcon(QIcon(":/icon/DoubleLast_32x32.png"));
    ui.SlowPb->setIcon(QIcon(":/icon/DoublePrev_32x32.png"));*/
    //timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()), this, SLOT(updateValue()));
    //timer->stop();
    //timer->setInterval(IntervalTime);

    QMenu* menu = new QMenu(this);
    menu->addAction(tr("该时刻详细电压"), this, &dataAnalysis::bmuCurrentTimeVoltage);
    menu->addAction(tr("该时刻详细温度"), this, &dataAnalysis::bmuCurrentTimeTemputure);
    menu->setStyleSheet("QMenu {background-color: #435; border: 1px solid #ccc;}");
    ui.tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(ui.tableWidget, &QTableWidget::customContextMenuRequested, [this, menu](const QPoint& pos) {
        QModelIndex index = ui.tableWidget->indexAt(pos);
        if (index.isValid()) {  
                   int   SlectId = index.row();
                   QTableWidgetItem *item=  ui.tableWidget->item(SlectId, 0);
                   SelectTime = item->text();
            menu->exec(ui.tableWidget->viewport()->mapToGlobal(pos));
        }
        });
    // 连接cellDoubleClicked信号到一个自定义槽函数
    QObject::connect(ui.tableWidget, &QTableWidget::cellDoubleClicked, [&](int row, int column) {
        // 这里处理双击事件，row是双击的行，column是双击的列
        // 例如，打印行和列的索引
        qDebug() << "Double clicked on row:" << row << "column:" << column;
        bmuSingleData(row, column);
        });
    ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui.tableWidget->horizontalHeader()->setSectionsClickable(true);
    ui.tableWidget->verticalHeader()->setSectionsClickable(true);
}

void dataAnalysis::on_Clear_clicked()
{

    QMessageBox messageBox(QMessageBox::NoIcon, "清除", "是否清除数据", QMessageBox::Yes | QMessageBox::No, NULL);
    messageBox.setWindowFlag(Qt::WindowStaysOnTopHint);
    int reply = messageBox.exec(); 
    if (reply == QMessageBox::No)
    {
        return;
    }
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("bcudb.db");
    QString  sql = " delete from BCUInfoBase";
    QSqlQuery query;
    QString err_info;
    QString a;
    if (!mydb.open()) //如果数据库打开失败，会弹出一个警告窗口
    {
        QMessageBox::warning(this, "警告", "数据库打开失败");
    }
    else
    {
        //  qDebug()<<"时间测试数据库打开";
    }

    if (!query.exec(sql)) //执行插入操作
    {
        QString err_info = tr("数据库失败[%1]").arg(query.lastError().text());
    }
     sql = " delete from BCUAlarmInfo";
    if (!query.exec(sql)) //执行插入操作
    {
        QString err_info = tr("数据库失败[%1]").arg(query.lastError().text());
    }
    mydb.setDatabaseName("bmudb.db");
    if (!mydb.open()) //如果数据库打开失败，会弹出一个警告窗口
    {
        QMessageBox::warning(this, "警告", "数据库打开失败");
    }
    else
    {
        QMessageBox::warning(this, "警告", "删除BMU成功");
    }
    sql = " delete from Temputure";
    if (!query.exec(sql)) //执行插入操作
    {
        QString err_info = tr("数据库失败[%1]").arg(query.lastError().text());
    }
    sql = " delete from Volatage";

    if (!query.exec(sql)) //执行插入操作
    {
        QString err_info = tr("数据库失败[%1]").arg(query.lastError().text());
    }
    else
    {
        QMessageBox::warning(this, "警告", "删除BCU成功");
    }

}
void dataAnalysis::on_PbReadData_clicked()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    QString  sql = "";
    QSqlQuery query;
    QString err_info;
    QString a;
    QStringList  headlist;
    if (ui.comboBox_2->currentText().contains("温度数据"))
    {
        mydb.setDatabaseName("bmudb.db");
        mydb.open();
        query.exec("PRAGMA table_info(Temputure)");
        while (query.next()) {
            headlist.append(query.value(1).toString()); // 列名在结果的第二列
        }
        sql = QString("SELECT * FROM Temputure WHERE ID= %1").arg(ui.comboBox->currentIndex());
    }
    else  if (ui.comboBox_2->currentText().contains("电压数据"))
    {
        mydb.setDatabaseName("bmudb.db");
        mydb.open();
        query.exec("PRAGMA table_info(Volatage)");
        while (query.next()) {
            headlist.append(query.value(1).toString()); // 列名在结果的第二列
        }
        sql = QString("SELECT * FROM Volatage WHERE ID= %1").arg(ui.comboBox->currentIndex());
    }
    else  if (ui.comboBox_2->currentText().contains("状态数据"))
    {
        mydb.setDatabaseName("bcudb.db");
        mydb.open();
        query.exec("PRAGMA table_info(BCUInfoBase)");
        while (query.next()) {
            headlist.append(query.value(1).toString()); // 列名在结果的第二列
        }
        sql = "SELECT * FROM BCUInfoBase";
     
    }
    else  if (ui.comboBox_2->currentText().contains("告警数据"))
    {
        mydb.setDatabaseName("bcudb.db");
        mydb.open();
        sql = "SELECT * FROM BCUAlarmInfo";
        query.exec("PRAGMA table_info(BCUAlarmInfo)");
        while (query.next()) {
            headlist.append(query.value(1).toString()); // 列名在结果的第二列
        } 
    }
    if (!query.exec(sql)) //执行插入操作
    {
        QString err_info = tr("数据库失败[%1]").arg(query.lastError().text());
    }
    else
    {
        ui.tableWidget->setColumnCount(headlist.count());
        ui.tableWidget->setHorizontalHeaderLabels(headlist);
        populateTableWidget(query);
        //QMessageBox::warning(this, "警告", "温度数据成功");
    }
}
void dataAnalysis::on_NextPage_clicked()
{
    int rowCount = ui.tableWidget->model()->rowCount();
    int rowHeight = ui.tableWidget->rowHeight(0);
    int tableViewHeight = ui.tableWidget->height();
    int rowCountPerPage = tableViewHeight / rowHeight - 1;
    int canNotViewCount = rowCount - rowCountPerPage;
    if (canNotViewCount == 0)
        return;
    int maxValue = ui.tableWidget->verticalScrollBar()->maximum();
    if (maxValue == 0)
        return;
    int pageValue = maxValue * rowCountPerPage / canNotViewCount;
    int nCurScroller = ui.tableWidget->verticalScrollBar()->value();

    if (nCurScroller < maxValue)
    {
        ui.tableWidget->verticalScrollBar()->setSliderPosition(nCurScroller + pageValue);
        CurrentPage ++;
    }
    else
    {
        QMessageBox::question(NULL, "提示信息", "已经到最后页了！");
        ui.tableWidget->verticalScrollBar()->setSliderPosition(0);
    }
    ui.PageNo->setText("当前页: "+QString::number(CurrentPage, 10));
}
void dataAnalysis::on_PreviousPage_clicked()
{
    int rowCount = ui.tableWidget->model()->rowCount();
    int rowHeight = ui.tableWidget->rowHeight(0);
    int tableViewHeight = ui.tableWidget->height();
    int rowCountPerPage = tableViewHeight / rowHeight - 1;
    int canNotViewCount = rowCount - rowCountPerPage;
    if (canNotViewCount == 0)
        return ;
    int maxValue = ui.tableWidget->verticalScrollBar()->maximum();
    if (maxValue == 0)
        return;
    int pageValue = maxValue * rowCountPerPage / canNotViewCount;
    int nCurScroller = ui.tableWidget->verticalScrollBar()->value();
    if (nCurScroller > 0)
    {
        ui.tableWidget->verticalScrollBar()->setSliderPosition(nCurScroller - pageValue);
        CurrentPage--;
    }
    else
    {
        CurrentPage = 1;
        QMessageBox::question(NULL, "提示信息", "已经到首页了！");
        ui.tableWidget->verticalScrollBar()->setSliderPosition(maxValue);
    }
    ui.PageNo->setText("当前页: "+QString::number(CurrentPage, 10));
}
void dataAnalysis::on_FirstPage_clicked()
{
    CurrentPage = 1;
    int maxValue = ui.tableWidget->verticalScrollBar()->maximum();
    if (maxValue == 0)
        return;
    ui.tableWidget->verticalScrollBar()->setSliderPosition(0);
    ui.PageNo->setText("当前页: " + QString::number(CurrentPage, 10));
    return;
}
void dataAnalysis::on_LastPage_clicked()
{

    int maxValue = ui.tableWidget->verticalScrollBar()->maximum();
    if (maxValue == 0)
        return;
    ui.tableWidget->verticalScrollBar()->setSliderPosition(maxValue);
    return;
}


void dataAnalysis::LoadBmuDB()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("bmudb.db");
    if (!mydb.open()) //如果数据库打开失败，会弹出一个警告窗口
    {
         QMessageBox::warning(this, "警告", "数据库打开失败");
    }
    else
    {
        //  qDebug()<<"时间测试数据库打开";
    }

}

void dataAnalysis::StartAnalysis()
{


}


void dataAnalysis::populateTableWidget(QSqlQuery  query)
{
    int row =0;

    int columnCount = query.record().count();
    ui.tableWidget->setColumnCount(columnCount);
    while (query.next()) {
        ui.tableWidget->setRowCount(row+1);
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem* item = new QTableWidgetItem(query.value(col).toString());
            ui.tableWidget->setItem(row, col, item);
        }
        ++row;      
    }
    pageCount();
}

int dataAnalysis::pageCount()
{
    int rowCount = ui.tableWidget->model()->rowCount();
    int rowHeight = ui.tableWidget->rowHeight(0);
    if (rowHeight == 0)
        return 0;
    int tableViewHeight = ui.tableWidget->height();
    int rowCntPerPage = tableViewHeight/ rowHeight-1;
    int ret = rowCount / rowCntPerPage;
    int rem = rowCount % rowCntPerPage;
    if (rem != 0) ret++;
    ui.TotalPage->setText("总页数: "+ QString::number(ret,10));
    return ret;
}

void dataAnalysis::bmuCurrentTimeVoltage()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    QString  sql = "";
    QSqlQuery query;
    QStringList headlist;
    int row = 0;
    QDateTime datatime1 = QDateTime::fromString(SelectTime, "yyyy-MM-dd hh:mm:ss");

    mydb.setDatabaseName("bmudb.db");
    mydb.open();

    query.exec("PRAGMA table_info(Volatage)");
    while (query.next()) {
        headlist.append(query.value(1).toString()); // 列名在结果的第二列
    }

    sql = QString("SELECT * FROM Volatage WHERE Time BETWEEN  '%1' AND  '%2'" ).arg(datatime1.addSecs(0).toString("yyyy-MM-dd hh:mm:ss")).arg(datatime1.addSecs(3).toString("yyyy-MM-dd hh:mm:ss"));
   // SELECT* FROM Temputure WHERE Time BETWEEN '2023-01-01' AND '2024-12-31'
    if (!query.exec(sql)) //执行插入操作
    {
        QString err_info = tr("数据库失败[%1]").arg(query.lastError().text());
        return;
    }
    int columnCount = query.record().count();
    myWidget->setColumnCount(columnCount);
    myWidget->setHorizontalHeaderLabels(headlist);
    while (query.next()) {
       myWidget->setRowCount(row + 1);
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem* item = new QTableWidgetItem(query.value(col).toString());
            myWidget->setItem(row, col, item);
        }
        ++row;
    }
    myWidget->resizeColumnsToContents();
    myWidget->show();
}

void dataAnalysis::bmuCurrentTimeTemputure()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    QString  sql = "";
    QSqlQuery query;
    QStringList headlist;
    mydb.setDatabaseName("bmudb.db");
    mydb.open();
    query.exec("PRAGMA table_info(Temputure)");
    while (query.next()) {
        headlist.append(query.value(1).toString()); // 列名在结果的第二列
    }

    QDateTime datatime1 = QDateTime::fromString(SelectTime, "yyyy-MM-dd hh:mm:ss");
    sql = QString("SELECT * FROM Temputure WHERE Time BETWEEN  '%1' AND  '%2'").arg(datatime1.addSecs(0).toString("yyyy-MM-dd hh:mm:ss")).arg(datatime1.addSecs(3).toString("yyyy-MM-dd hh:mm:ss"));

    if (!query.exec(sql)) //执行插入操作
    {
        QString err_info = tr("数据库失败[%1]").arg(query.lastError().text());
    }
    int row = 0;
        int columnCount = query.record().count();
    myWidget->setColumnCount(columnCount);
    myWidget->setHorizontalHeaderLabels(headlist);
    while (query.next()) {
        myWidget->setRowCount(row + 1);
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem* item = new QTableWidgetItem(query.value(col).toString());
            myWidget->setItem(row, col, item);
        }
        ++row;
    }
    myWidget->resizeColumnsToContents();
    myWidget->show();
}

void dataAnalysis::bmuSingleData(int row, int column)
{
    QTableWidgetItem* item = ui.tableWidget->item(row, 0);
    QString currentTime = item->text();
    QDateTime datatime1 = QDateTime::fromString(currentTime, "yyyy-MM-dd hh:mm:ss");
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    QString  sql = "";
    QSqlQuery query;
    QStringList headlist;
    QStringList headlist2;
    QWidget* parentWidget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(parentWidget);
    QTableWidget* TempuWidget = new QTableWidget();
    QTableWidget* VoltWidget = new QTableWidget();
    int datarow = 0;
    mydb.setDatabaseName("bmudb.db");
    mydb.open();

    query.exec("PRAGMA table_info(Temputure)");
    while (query.next()) {
         headlist.append (query.value(1).toString()); // 列名在结果的第二列
    }

    sql = QString("SELECT * FROM Temputure WHERE Time BETWEEN  '%1' AND  '%2'").arg(datatime1.addSecs(0).toString("yyyy-MM-dd hh:mm:ss")).arg(datatime1.addSecs(3).toString("yyyy-MM-dd hh:mm:ss"));
    if (!query.exec(sql)) //执行插入操作
    {
        QString err_info = tr("数据库失败[%1]").arg(query.lastError().text());
    }
    
    int columnCount = query.record().count();
    TempuWidget->setColumnCount(columnCount);
    TempuWidget->setHorizontalHeaderLabels(headlist);
    while (query.next()) {
        TempuWidget->setRowCount(datarow + 1);
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem* item = new QTableWidgetItem(query.value(col).toString());
            TempuWidget->setItem(datarow, col, item);
        }
        ++datarow;
    }
    datarow = 0;
    query.exec("PRAGMA table_info(Volatage)");
    while (query.next()) {
        headlist2.append(query.value(1).toString()); // 列名在结果的第二列
    }
     sql = QString("SELECT * FROM Volatage WHERE Time BETWEEN  '%1' AND  '%3'").arg(datatime1.addSecs(0).toString("yyyy-MM-dd hh:mm:ss")).arg(datatime1.addSecs(3).toString("yyyy-MM-dd hh:mm:ss"));
     if (!query.exec(sql)) //执行插入操作
     {
         QString err_info = tr("数据库失败[%1]").arg(query.lastError().text());
     }

    columnCount = query.record().count();
    VoltWidget->setColumnCount(columnCount);
    VoltWidget->setHorizontalHeaderLabels(headlist2);
    while (query.next()) {
        VoltWidget->setRowCount(datarow + 1);
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem* item = new QTableWidgetItem(query.value(col).toString());
            VoltWidget->setItem(datarow, col, item);
        }
        ++datarow;
    }

    // 设置widget为可见
    TempuWidget->resizeColumnsToContents();
    VoltWidget->resizeColumnsToContents();
    TempuWidget->setVisible(true);
    VoltWidget->setVisible(true);
    // 添加widget到布局
    layout->addWidget(TempuWidget);
    layout->addWidget(VoltWidget);
    // 确保父控件布局完成
    parentWidget->update();
    QFile file(":/qss/HF.qss");
    if (!file.open(QIODevice::ReadOnly))
    {
        qWarning("Can't open the style sheet file.");
        return;
    }
    QString qss = QLatin1String(file.readAll());
    parentWidget->setStyleSheet(qss);
    // 显示父控件
    parentWidget->show();
}

void dataAnalysis::on_FastPb_clicked()
{
    IntervalTime = IntervalTime / 2;
    timer->setInterval(IntervalTime);
    PlaySpeed = PlaySpeed * 2;
  //  ui.label_6->setText("X "+QString::number(PlaySpeed, 10));
}

void dataAnalysis::on_SlowPb_clicked()
{
    IntervalTime = IntervalTime * 2;
    timer->setInterval(IntervalTime);
    PlaySpeed = PlaySpeed / 2;
  //  ui.label_6->setText("X " + QString::number(PlaySpeed, 10));
}