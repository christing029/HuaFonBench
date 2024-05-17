#ifndef DEVICEDATA_H
#define DEVICEDATA_H


#include <QString>
#include <list>
using namespace std;

#if 0
// 接收来自从控数据记录
class BMUCanDataRec
{
public:
    BMUCanDataRec(): FrameId(0) {}
    // BMU 单体数据
    /*******************************************************/
    typedef   struct 
    {
        uint8_t FrameId;
        uint8_t SegmentIndex; //分段索引
        uint8_t Data[7]; // 数据
    }BMU_CAN_RecData;
public:
    int  FrameId;
    char SegmentIndex;
    char Data[7];
};
// 列表
typedef list<BMUCanDataRec> BMUCanDataRecList;

// // 发送来自从控数据记录
class BMU_CAN_SndData
{
public:
    BMU_CAN_SndData(): txNo(0) {}

public:
    int txNo;
    char SeriaNumber[32];
    char cbLoad[32];
    char cbVolt[32];
    char cbDataList[32];
    char curTime[32];
};
// 列表
typedef list<BMU_CAN_SndData> BMU_CAN_SndData;
#endif



// 三级控数据记录
class BAUDeviceData
{
public:
    BAUDeviceData(): SeriaNumber(0) {}
public:
    uint64_t SeriaNumber;
    QString  Load;
    QString  Volt;
    uint64_t DataList;
    QString  CurTime;
};
// 列表
typedef list<BAUDeviceData> BAUDeviceDataList;

// 用户管理
class UserInfoData
{
public:
    UserInfoData(): SeriaNumber(0) {}
public:
    uint64_t SeriaNumber;
    char  UserName[32];
    char  UserPasswrd[32];
    char  UserRole[32];
    char  UserTel[32];
    char  UserInfo[32];
    int hasPhoto; // 0,没有照片;1,有照片
};
// 列表
typedef list<UserInfoData> UserInfoDataList;



#endif // DEVICEDATA_H


