#ifndef CAN_H
#define CAN_H
#include <QThread>
#include <iostream>
#include <QDebug>
#include <QLibrary>
#include <QTimer>
#include <QObject>
#include <QMessageBox>
#include <QMutex>
#include "ECanVci.h"

class Thread : public QThread   //用户自定义的类
{
    Q_OBJECT
        /*can发送类型*/
        enum CAN_SEND_TYPE
    {
        CAN_SEND_NORMAL = 0,//正常
        CAN_SEND_SIGNAL,//单次
        CAN_SEND_SELF,//自发自收
        CAN_SEND_SELF_SIGNAL//单次自发自收
    };
    /*can数据类型*/
    enum CAN_DATA_TYPE
    {
        CAN_DATA_INFO = 0,//数据帧
        CAN_DATA_REMOTE//远程帧
    };
    ///*是否扩展帧*/
    enum CAN_EXTERN_TYPE
    {
        CAN_FRAM_STANDARD = 0,//标准帧
        CAN_FRAM_EXTERN//扩展帧
    };
public:
    typedef   struct
    {
        UINT FrameId;
        BYTE Data[8]; // 数据
    }StandFrame_Data;

public:
    Thread();//构造函数//初始化变量
    ~Thread();//构造函数//初始化变量
    void stop();
    void OpenCANThread(byte baud, int id);
    void CloseCANThread();
    void ReceiveCANThread();
    void TransmitCANThread(unsigned int id, unsigned char *ch,bool EXT,bool RTR, unsigned int len);
    void Reset();
public:
    typedef DWORD(__stdcall OpenDevice)(DWORD,DWORD,DWORD);
    typedef DWORD(__stdcall ResetCAN)(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd);
    typedef DWORD(__stdcall CloseDevice)(DWORD DeviceType,DWORD DeviceInd);
    typedef DWORD(__stdcall InitCAN)(DWORD DeviceType, DWORD DeviceInd, DWORD CANInd, P_INIT_CONFIG pInitConfig);
    typedef DWORD(__stdcall StartCAN)(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd);
    typedef ULONG(__stdcall Transmit)(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd,P_CAN_OBJ pSend,ULONG Len);
    typedef ULONG(__stdcall Receive)(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd,P_CAN_OBJ pReceive,ULONG Len,INT WaitTime/*=-1*/);
    typedef ULONG(__stdcall GetReceiveNum)(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd);
    typedef DWORD(__stdcall ClearBuffer)(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd);
    typedef DWORD(__stdcall ReadErrInfo)(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd,P_ERR_INFO pErrInfo);
    typedef DWORD(__stdcall ReadCANStatus)(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd,P_CAN_STATUS pCANStatus);
    typedef DWORD(__stdcall SetReference)(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd,DWORD RefType,PVOID pData);
    typedef DWORD(__stdcall ReadBoardInfo)(DWORD DeviceType,DWORD DeviceInd,P_BOARD_INFO pInfo);
    int devtype=4;//设备类型号//
    int devind=0; //设备索引号
    int res;    //保留参数，通常为0
    int canind=0; //第几路can
    int reftype;//参数类型
    bool  IsOpenFlag = false;
//Widget *ui;
public:
    //QThread类的虚函数//就是子线程处理函数
   virtual void run() override;//子线程处理函数//不能直接调用该函数//只能通过start间接调用
private:
    bool stopped =false;
    long mrec = 0;
    OpenDevice *pOpenDevice;
    ResetCAN *pResetCAN;
    CloseDevice *pCloseDevice;
    InitCAN *pInitCAN;
    StartCAN *pStartCAN;
    Transmit *pTransmitCAN;
    Receive *pReceive;
    GetReceiveNum *pGetReceiveNum;
    ClearBuffer *pClearBuffer;
    ReadErrInfo *pReadErrInfoCAN;
    ReadCANStatus *pReadCANStatus;
    SetReference *pSetReference;
    ReadBoardInfo *pReadBoardInfo;
    QMutex pause_mutex;
private:
     void TestCanRec();
signals:
    void my_signal(QString str);//信号函数
    void RecStandFrame_signal(QString, QByteArray);//信号函数
};

#endif // CAN_H
