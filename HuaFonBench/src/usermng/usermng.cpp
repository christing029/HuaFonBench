#include "usermng.h"
#include "ui_usermng.h"
#include <qDebug>
#include <QFile>
usermng::usermng(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::usermng)
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
    OpenDataBase();
    InitDataBase();
}

usermng::~usermng()
{
    delete ui;
}

int usermng::InitDataBase()
{
    // QSqlQuery query;
    int rc;
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    //rc = sqlite3_open("UserMng.db", &m_user_db);
    //if (rc != 0)
    //{

    //    qDebug()<< "error!\n";
    //    return -1;
    //}

    //if (createTable() < 0)
    //{
    //    qDebug() << "failed to create table!\n";
    //    return -1;
    //}
    return 0;
}

void usermng::OpenDataBase()
{
    //QSqlDatabase agentDevice = QSqlDatabase::addDatabase("QSQLITE");
    //agentDevice.setDatabaseName("UserMng.db");

    //if (!agentDevice.open()) //如果数据库打开失败，会弹出一个警告窗口
    //{
    //    QMessageBox::warning(this, "警告", "数据库打开失败");
    //}
    //else
    //{

    //    //读表数据到TreeWidget
    //    int i = 0;
    //    QSqlQuery query;
    //    query.exec("select rowid as UserInfo,* from UserInfo");//查询所有的信息
    //    ui->treeWidget->clear();

    //    while (query.next())
    //    {
    //        QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget);
    //       item->setText(0, query.value(1).toString());
    //        item->setText(1, query.value(2).toString());
    //        item->setText(2, query.value(3).toString());
    //        item->setText(3, query.value(4).toString());
    //        item->setText(4, query.value(5).toString());
    //        item->setText(5, query.value(6).toString());
    //    }
    //}
}


int usermng::createTable()
{
    // 创建数据库
    //int rc;

    //sqlite3_stmt* stmt = NULL;
    //char sql[512] =
    //    "CREATE TABLE IF NOT EXISTS UserInfo("
    //    "    id INTEGER PRIMARY KEY ,"
    //    "    UserName  TEXT, "
    //    "    UserPasswrd TEXT ,"
    //    "    UserRole TEXT ,"
    //    "    UserTel TEXT ,"
    //    "    DevicetInfo TEXT ,"
    //    "    photo BLOB "
    //    ")";
    //rc = sqlite3_prepare_v2(m_user_db, sql, -1, &stmt, NULL);
    //if (rc != SQLITE_OK)
    //{
    //    qDebug() << "failed to prepare: %s \n", sqlite3_errmsg(m_user_db);
    //    return -1;
    //}
    //rc = sqlite3_step(stmt);
    //if (rc != SQLITE_DONE)
    //{
    //    qDebug() << "error: %s \n", sqlite3_errmsg(m_user_db);
    //    sqlite3_finalize(stmt);
    //    return -1;
    //}
    //sqlite3_finalize(stmt);
    return 0;
}

// 增加一行用户

void usermng::on_bt_add_clicked()
{
    // 写数据库
    AddUserDase();
    OpenDataBase();
}

// 删除一行用户
void usermng::on_bt_remove_clicked()
{
    QTreeWidgetItem* item = ui->treeWidget->currentItem();
    if (!item) return; // 没有选中项
    // 取得行号
    int id = (item->text(0)).toInt();
    // 从DataSource中删除记录
    if (id == 0)
    {
        //  qDebug()<<"请输入需要删除的零件的ID"; //删除的时候需要输入ID
    }
    else
    {
        //从数据库中查询是否有这个ID
        QSqlQuery query;
        QString temp = QString("select * from UserInfo where rowid = '%1'").arg(id);
        query.exec(temp);
        QString deleteid;
        while (query.next())
        {
            deleteid = query.value(1).toString();
        }
        if (deleteid == NULL)
        {
            QString a = QString("没有编号为%1的零件，删除失败").arg(id);
        }
        else
        {
            QString str = QString("delete from UserInfo where rowid = '%1'").arg(id);
            query.exec(str);//删除信息
            // 从界面中删除该条显示
            int index = ui->treeWidget->indexOfTopLevelItem(item);
            QTreeWidgetItem* which = ui->treeWidget->takeTopLevelItem(index);
            delete which;
            return;
            // ui->textEdit->setText("删除成功");
        }
    }
}


void usermng::AddUserDase()
{
    QString str = QString("insert into UserInfo(UserName,UserPasswrd,UserRole,UserTel,DevicetInfo) values('%0', '%1', '%2', '%3','%4')").arg(ui->txName->text()).
        arg(ui->txPasswrd->text()).arg(ui->cbUserRole->currentText()).arg(ui->txUserTel->text()).arg(ui->txUserInfo->text());
    QSqlQuery query;
    QString err_info;
    QString a;
    if (!query.exec(str)) //执行插入操作
    {
       // QString err_info = tr("数据库失败[%1]").arg(query.lastError().text());
    }

}
void usermng::on_treeWidget_itemClicked(QTreeWidgetItem* item, int column)
{
    QTreeWidgetItem* putr = ui->treeWidget->currentItem();
    ui->txName->setText(putr->text(1));
    ui->txPasswrd->setText(putr->text(2));
    ui->cbUserRole->setEditText(putr->text(3));
    ui->txUserTel->setText(putr->text(4));
    ui->txUserInfo->setText(putr->text(5));
}