#ifndef JSON_H
#define JSON_H
#include <QJsonObject > // { }
#include <QJsonArray > // [ ]
#include <QJsonDocument > // 解析Json
#include <QJsonValue> // int float double bool null { } [ ]
#include <QJsonParseError >
#include <QList>
//module
enum
{
    COLUMN_NAME = 0,
    COLUMN_REG_ADDRESS,
    COLUMN_OFFSET_LEN,
    COLUMN_DEFAULT_VAL,
    COLUMN_REAL_VAL,
    COLUMN_Uint_VAL,
    COLUMN_SET_BUTTON,
    COLUMN_GET_BUTTON,
};
struct MasterItem
{
    QString TopicName;//主体名称
    QString StartAddress;//主体名称
    QString OffSetAddress;//类型
    QString RW;//配置项属性
    QString FORMATE;//配置项格式
    QString Val_def;
    QString Val_real;
    QString Unit; //单位
};

struct ItemMode
{
    QString ItemName;//配置项名称
    QString Type_Address;//类型
    QString RW;//配置项属性
    QString FORMATE;//配置项格式
    QString val_def;
    QString val_real;
    QString Unit; // 单位
};




class json
{

    //对象结构体
    struct mJson
    {
        QString SlaveIdName; //
        QVector<ItemMode> sModule;
        QVector<MasterItem> mModule;
//        int moduleSize = 0;                                //用于module的个数
//        int modeSize = 0;                                  //mode  的个数
//        bool isNull = true;                                 //预留判空
    };
public:
    json();
    void creatslavecfg();
    void readslacecfg(QString FilePath);
    void read_master_mbtcpcfg(QString filePath);
    mJson JsonTemp;                        			 //存储单个信息的结构体
    QVector<mJson > JsonTxt;                	//存储所有相关配置内容
    void testwritecfg();
    void testinit();
    
private:
    QList<QString>     t_slavecfgName={"序列","硬件 ","产品 "};
    uint  slaveCnt = 1;
    uint row =3;
   uint  column=5;


};

#endif // JSON_H
