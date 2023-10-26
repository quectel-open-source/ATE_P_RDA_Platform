#pragma once
#include "stdafx.h"

//测试应用对象（1.产线测试版; 2.客户测试版）
#define APP_OBJ_TL					1
#define APP_OBJ_CUS					2

typedef enum
{
	RF_PORT1 = 1,
	RF_PORT2 = 2,
	RF_PORT3 = 3,
	RF_PORT4 = 4,
	RF_PORT5 = 5,
	RF_PORT6 = 6,
	RF_PORT7 = 7,
	RF_PORT8 = 8
} E_RCTLIB_PORT_TYPE;

//生产性质（正常、REP等）
#define PRODU_PROP_NDF			0
#define PRODU_PROP_NORMAL		1//正常工单
#define PRODU_PROP_REP			2//REP工单, 返工, 重流, 纸质标签必换标签和IMEI号段, 镭雕则不跟换

//返回结果定义-Quectel
#define RTN_SUCCESS				0
#define RTN_ERROR				-1
#define RTN_FAIL				1
#define RTN_IGNORE              2

//GPIB卡传输协议
#define GPIB_NI					0
#define GPIB_VISA				1
#define GPIB_VISA_TCPIP			2

// #define CMU200                  0
// #define AG_E1960				1
// #define AG_E1968				2
// #define AG6601A                 3
// #define MT8820                  4
// #define CMD55                   5
// #define AG8922                  6
// #define CMW500                  7
// #define AG_E1987A               8
// #define AG_E1962B               9
// #define LP_IQXS                 10
// #define CMW100                  11
// #define LP_IQXM                 12

#define PROCESS_BARCODE_17		17//有SN
#define PROCESS_BARCODE_15		15//有SN
#define PROCESS_BARCODE_2		2//无SN只写标志位
#define PROCESS_BARCODE_0		0//空

// enum RF_Device
// {
// 	A8960,
// 	CMU200,
// 	E6607A,
// 	CTP3110,
// 	CMW,
// 	E6640
// };

enum MesgFlag
{
	TEST_FAIL,
	TEST_PASS,
	TEST_TITLE,
	TEST_ITEM
};
enum GSM_RFItems
{
	GSM_TEST_FreqErr = 0,
	GSM_TEST_PhaseErr,
	GSM_TEST_PhaseRMSErr,
	GSM_TEST_Power,
	GSM_TEST_PVT,
	GSM_TEST_ORFSM,
	GSM_TEST_ORFSS,
	GSM_TEST_RxLevel,
	GSM_TEST_Ber,
	GSM_TEST_COUNT
};
enum NB_RFItems
{
	NB_TEST_Ber = 0,
	NB_TEST_MaxPower,
	NB_TEST_ACLR,
	NB_TEST_EVM,
	NB_TEST_FreqErr,
	NB_TEST_OBW,
	NB_TEST_SEM,
	NB_TEST_MinPower,
	NB_TEST_COUNT
};

struct RF_Instrument
{
	int iGPIB_Type;
	CString sTCPIP_Addr;
	short iGPIB_Card;//GPIB卡号
	short iGPIB_Addr;//测试仪器GPIB地址号
	int iInstru_Option;//具体仪器型号 或 可自动识别仪器
	int i_RF_Port_Numb;
	int i_IQM_Bandk;//IQ_M Bank号
	CString sInstrumentInfo;
};
struct PS_Instrument
{
	bool b_Ctrl_PS;
	int iGPIB_Type;
	CString sTCPIP_Addr;
	short iGPIB_Card;//GPIB卡号
	short iGPIB_Addr;//测试仪器GPIB地址号
	double fVoltage;
	double fCurrent;
};
#define CHANNEL_NUM 3

struct GSM2G_NS_TEST_RST
{
	float TX_Power;
	float Ber;
	float FreqErr;
	float PhaseErr;
	float PhaseRMSErr;
	int PVT;
	int ORFSM;
	int ORFSS;
	int RxLevel;
};
struct GSM2G_CAL_TEST_RST
{
	int iBattery_Voltage_Sensor;
	int iCrystal_Calibration;
	int iAFC_Gains_Calibration[4];
	int iCalibPAProfile[4];
	int iCalibPAOffset[4];
	int iCalibILoss[4];
	int iset_sw_param;
	int iCalibBurnFlash;
	int m_iCalibSaveCfp;
};

//数据库金板 callback 结构体
typedef void(__stdcall * CALLBACK_SQL_GOLDEN_INFO)(const wchar_t * wcp_SQL_Golden_Info, void * p_usr_Arg);

typedef struct tagQTI_PROG_ARG_SQL
{
	void *							p_usr_Arguments;
	CALLBACK_SQL_GOLDEN_INFO		cb_SQL_Golden_Info;
}QTI_PROG_ARG_SQL;
