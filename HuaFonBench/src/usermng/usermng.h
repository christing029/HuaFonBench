#ifndef USERMNG_H
#define USERMNG_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
//#include <src/public/sqlite_amalgamation/sqlite3.h>
#include <QTreeWidget>
#include <QWidget>
#include <QtSql/QSqlError>
namespace Ui {
class usermng;
}

class usermng : public QWidget
{
    Q_OBJECT

public:
    explicit usermng(QWidget *parent = nullptr);
    ~usermng();

private:
    Ui::usermng *ui;

private:

    int InitDataBase();
    int createTable();
    void OpenDataBase();
    void  AddUserDase();
    void  DelUserBase();
    bool StoreFile(QString FilePathName);
    //AgentDevDataSource* m_dataSource;
    //QIcon m_flagPhoto;
    //QSqlDatabase agentDevice;
private :
 //   sqlite3* m_user_db;
    QByteArray PhotoData;
    bool      isPhotoFlag;
private slots:
    void on_bt_add_clicked();
    void on_bt_remove_clicked();
    void on_treeWidget_itemClicked(QTreeWidgetItem* item, int column);
};

#endif // USERMNG_H
