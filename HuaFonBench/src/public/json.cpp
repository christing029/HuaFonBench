#include "json.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonObject>
#include <qjsondocument.h>
#include <qjsonobject.h>
//#pragma execution_character_set("utf-8")

json::json()
{

}

void json::creatslavecfg()
{
    //创建json对象
    QJsonObject rootObject;
    // 定义 { } 对象
    QJsonArray jsonArray[2];
    QJsonArray ArrayName;

    for (int k =0;k<slaveCnt;k++)
    {
    for(int i =0;i<t_slavecfgName.size();i++)
    {
    jsonArray[i].append(QJsonObject{{"name","11111111"}});
    jsonArray[i].append(QJsonObject{{"real", "22222222"}});
    jsonArray[i].append(QJsonObject{{"type", "RW"}});
    ArrayName.append(QJsonObject{{t_slavecfgName[i],  jsonArray[i]}});
    }
    QString  IDName ="从机配置ID=" +  QString::number(k+1,10) ;
     rootObject.insert(IDName, ArrayName);
    //转换为json文件对象
    QJsonDocument doc(rootObject);
    //将json文件对象转换为字符串
    QByteArray data = doc.toJson();
    //写入文件
    QFile file_json("./db/2.json");
    file_json.open(QIODevice::ReadWrite);
    file_json.write(data);
    //关闭文件
    file_json.close();
       }
}

void json::readslacecfg(QString FilePath)
{
       QJsonObject rootObj11;
      QJsonParseError jsonError;
      int modeNum =0;
      int dataCount = 4;
    //读取json文件
    QFile file2_json(FilePath);
    file2_json.open(QIODevice::ReadOnly);
//    //json文件读入字符串
    QByteArray data = file2_json.readAll();
    file2_json.close();
//////    //使用字符串初始化json文件对象
    QJsonDocument document = QJsonDocument::fromJson(data, &jsonError);
    if(jsonError.error!=QJsonParseError::NoError)
    {
    //JSON文件加载内容报错.需要提示报错信息
    file2_json.close();
    return;
    }
    if (document.isArray())
    {
        modeNum = document.array().size();
        //循环读取json外圈大循环mode
        for (int i = 0; i < modeNum; ++i)
        {
            QJsonObject obj = document[i].toObject();
            QStringList keys = obj.keys();
            QJsonValue value = obj.value("A_SlaveID");
            JsonTemp.SlaveIdName = value.toString();
            value = obj.value("Item");
            int size = value.toArray().size();
           // JsonTemp.isNull = true;                        //必须要加避免读空而误删数据
            if (value.isArray() && size)
            {
                //JsonTemp.isNull = false;                 	 //size不为0,则设置为非空作为标记点
                //JsonTemp.moduleSize = size;             	 //mode size置位
                JsonTemp.mModule.clear();                	 //需要提前清空缓存数据
                for (int i = 0; i < size; ++i)
                {
                    MasterItem moduleTemp;
                    QJsonObject objModule = value[i].toObject();

                    moduleTemp.TopicName = objModule.value("Name").toString();
                    moduleTemp.StartAddress = objModule.value("StartAddress").toString();
                    moduleTemp.RW = objModule.value("RW").toString();
                    moduleTemp.FORMATE = objModule.value("FORMATE").toString();
                    moduleTemp.Val_def = objModule.value("Val_def").toString();
                    moduleTemp.Val_real = objModule.value("Val_real").toString();
                    moduleTemp.OffSetAddress = objModule.value("OffSetAddress").toString();
                    moduleTemp.Unit = objModule.value("UNIT").toString();
                    JsonTemp.mModule.push_back(moduleTemp);                //需要配合clear来尾插
                    dataCount++;                                                    //记录有效数据个数
                }
            }
            JsonTxt.push_back(JsonTemp);
        }
    }
}

void json::read_master_mbtcpcfg(QString filePath)
{
    QJsonObject rootObj11;
    QJsonParseError jsonError;
    int modeNum = 0;
    int dataCount = 4;
    //读取json文件
    QFile file2_json(filePath);
    file2_json.open(QIODevice::ReadOnly);
    //    //json文件读入字符串
    QByteArray data = file2_json.readAll();
    file2_json.close();
    //////    //使用字符串初始化json文件对象
    QJsonDocument document = QJsonDocument::fromJson(data, &jsonError);
    if (jsonError.error != QJsonParseError::NoError)
    {
        //JSON文件加载内容报错.需要提示报错信息
        file2_json.close();
        return;
    }
    if (document.isArray())
    {
        modeNum = document.array().size();
        //循环读取json外圈大循环mode
        for (int i = 0; i < modeNum; ++i)
        {
            QJsonObject obj = document[i].toObject();
            QStringList keys = obj.keys();
            QJsonValue value = obj.value("A_BCUID");
            JsonTemp.SlaveIdName = value.toString();
            value = obj.value("SOC_Item");
            int size = value.toArray().size();
            // JsonTemp.isNull = true;                        //必须要加避免读空而误删数据
            if (value.isArray() && size)
            {
                //JsonTemp.isNull = false;                 	 //size不为0,则设置为非空作为标记点
                //JsonTemp.moduleSize = size;             	 //mode size置位
                JsonTemp.mModule.clear();                	 //需要提前清空缓存数据
                for (int i = 0; i < size; ++i)
                {
                    MasterItem moduleTemp;
                    ItemMode moduleTemp1;
                    QJsonObject objModule = value[i].toObject();
                    moduleTemp.TopicName = objModule.value("Name").toString();
                    moduleTemp.StartAddress = objModule.value("StartAddress").toString();
                    moduleTemp.OffSetAddress = objModule.value("OffSetAddress").toString();
                    moduleTemp.RW = objModule.value("RW").toString();
                    moduleTemp.FORMATE = objModule.value("FORMATE").toString();
                    moduleTemp.Val_def = objModule.value("Val_def").toString();
                    moduleTemp.Val_real = objModule.value("Val_real").toString();
                    moduleTemp.Unit = objModule.value("UNIT").toString();
                    JsonTemp.mModule.push_back(moduleTemp);
                  //  JsonTemp.mModule.push_back(moduleTemp);                //需要配合clear来尾插
                    dataCount++;                                                    //记录有效数据个数
                }
            }
            JsonTxt.push_back(JsonTemp);
        }
    }
}


void json::testinit()
{
    QJsonArray jsonArrayModule[8];
    QJsonArray jsonArrayALL;
    QJsonObject jsonObjectALL;
    QJsonObject jsonObjectModule;
    QJsonDocument jsonDoc;

    for (int k = 0; k < slaveCnt; k++)
    {
        for (int i = 0; i < t_slavecfgName.size(); i++)
        {

            jsonObjectModule.insert("Name", t_slavecfgName[i]);
            jsonObjectModule.insert("RW", "RW");
            jsonObjectModule.insert("Val_def", "11111");
            jsonObjectModule.insert("Val_real", "2222");
            jsonArrayModule[slaveCnt-1].push_back(jsonObjectModule);
        }
        jsonObjectALL.insert("A_SlaveID" , QString::number(k+1, 10));
        jsonObjectALL.insert("Item", jsonArrayModule[slaveCnt - 1]);
        jsonArrayALL.push_back(jsonObjectALL);
    }
    jsonDoc.setArray(jsonArrayALL);
    QByteArray json = jsonDoc.toJson();

    //写文件
    QFile file("./db/2.json");
    file.open(QIODevice::WriteOnly);
    file.write(json);
    file.close();

}


