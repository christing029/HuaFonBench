
#ifndef _V_ECANVCI_H_
#define _V_ECANVCI_H_
#include <qt_windows.h>
#define Dll_EXPORTS
#define USBCAN1		3
#define USBCAN2		4
#define	ERR_CAN_OVERFLOW			0x0001	
#define	ERR_CAN_ERRALARM			0x0002	
#define	ERR_CAN_PASSIVE				0x0004	
#define	ERR_CAN_LOSE				0x0008	
#define	ERR_CAN_BUSERR				0x0010	
#define	ERR_CAN_REG_FULL			0x0020	
#define	ERR_CAN_REG_OVER			0x0040	
#define	ERR_CAN_ZHUDONG	    		0x0080	
#define	ERR_DEVICEOPENED			0x0100	
#define	ERR_DEVICEOPEN				0x0200	
#define	ERR_DEVICENOTOPEN			0x0400	
#define	ERR_BUFFEROVERFLOW			0x0800	
#define	ERR_DEVICENOTEXIST			0x1000	
#define	ERR_LOADKERNELDLL			0x2000	
#define ERR_CMDFAILED				0x4000
#define	ERR_BUFFERCREATE			0x8000	
#define	STATUS_OK					1
#define STATUS_ERR					0

#define CMD_DESIP			0
#define CMD_DESPORT			1
#define CMD_CHGDESIPANDPORT		2
typedef  struct  _BOARD_INFO{
        USHORT	hw_Version;
        USHORT	fw_Version;
        USHORT	dr_Version;
        USHORT	in_Version;
        USHORT	irq_Num;
        BYTE	can_Num;
        CHAR	str_Serial_Num[20];
        CHAR	str_hw_Type[40];
        USHORT	Reserved[4];
} BOARD_INFO,*P_BOARD_INFO;
typedef  struct  _CAN_OBJ{
    UINT	ID;
    UINT	TimeStamp;
    BYTE	TimeFlag;
    BYTE	SendType;
    BYTE	RemoteFlag;
    BYTE	ExternFlag;
    BYTE	DataLen;
    BYTE	Data[8];
    BYTE	Reserved[3];
}CAN_OBJ,*P_CAN_OBJ;
typedef struct _CAN_STATUS{
    UCHAR	ErrInterrupt;
    UCHAR	regMode;
    UCHAR	regStatus;
    UCHAR	regALCapture;
    UCHAR	regECCapture;
    UCHAR	regEWLimit;
    UCHAR	regRECounter;
    UCHAR	regTECounter;
    DWORD	Reserved;
}CAN_STATUS,*P_CAN_STATUS;
typedef struct _ERR_INFO{
        UINT	ErrCode;
        BYTE	Passive_ErrData[3];
        BYTE	ArLost_ErrData;
} ERR_INFO,*P_ERR_INFO;
typedef struct _INIT_CONFIG{
    DWORD	AccCode;
    DWORD	AccMask;
    DWORD	Reserved;
    UCHAR	Filter;
    UCHAR	Timing0;
    UCHAR	Timing1;
    UCHAR	Mode;
}INIT_CONFIG,*P_INIT_CONFIG;

typedef struct _tagChgDesIPAndPort
{
    char szpwd[10];
    char szdesip[20];
    int desport;
}CHGDESIPANDPORT;
typedef struct _FILTER_RECORD{
    DWORD ExtFrame;	//????????
    DWORD Start;
    DWORD End;
}FILTER_RECORD,*P_FILTER_RECORD;


#ifdef Dll_EXPORTS
    #define DllAPI __declspec(dllexport)
#else
    #define DllAPI __declspec(dllimport)

#endif

#define EXTERNC	 extern "C"
#define CALL __stdcall//__cdecl

//extern "C"
//{

EXTERNC	DllAPI DWORD CALL OpenDevice(DWORD DeviceType,DWORD DeviceInd,DWORD Reserved);
EXTERNC DllAPI DWORD CALL CloseDevice(DWORD DeviceType,DWORD DeviceInd);

EXTERNC DllAPI DWORD CALL InitCAN(DWORD DeviceType, DWORD DeviceInd, DWORD CANInd, P_INIT_CONFIG pInitConfig);

EXTERNC DllAPI DWORD CALL ReadBoardInfo(DWORD DeviceType,DWORD DeviceInd,P_BOARD_INFO pInfo);
EXTERNC DllAPI DWORD CALL ReadErrInfo(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd,P_ERR_INFO pErrInfo);
EXTERNC DllAPI DWORD CALL ReadCANStatus(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd,P_CAN_STATUS pCANStatus);

EXTERNC DllAPI DWORD CALL GetReference(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd,DWORD RefType,PVOID pData);
EXTERNC DllAPI DWORD CALL SetReference(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd,DWORD RefType,PVOID pData);

EXTERNC DllAPI ULONG CALL GetReceiveNum(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd);
EXTERNC DllAPI DWORD CALL ClearBuffer(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd);

EXTERNC DllAPI DWORD CALL StartCAN(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd);
EXTERNC DllAPI DWORD CALL ResetCAN(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd);

EXTERNC DllAPI ULONG CALL Transmit(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd,P_CAN_OBJ pSend,ULONG Len);
EXTERNC DllAPI ULONG CALL Receive(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd,P_CAN_OBJ pReceive,ULONG Len,INT WaitTime);



#endif
