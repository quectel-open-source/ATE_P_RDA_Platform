#pragma once
#include "stdafx.h"

//∑µªÿΩ·π˚∂®“Â-Quectel
#define RTN_SUCCESS					0
#define RTN_ERROR					-1
#define RTN_FAIL					1
#define RTN_IGNORE                2

//GPIBø®¥´ ‰–≠“È
#define GPIB_NI					0
#define GPIB_VISA				1
#define GPIB_VISA_TCPIP			2

enum RF_Device
{
	A8960,
	CMU200,
	E6607A,
	CTP3110,
	CMW,
	E6640
};

enum MesgFlag
{
	TEST_FAIL,
	TEST_PASS,
	TEST_TITLE,
	TEST_ITEM
};
enum RFItems
{
	TEST_FreqErr,
	TEST_PhaseErr,
	TEST_PhaseRMSErr,
	TEST_Power,
	TEST_PVT,
	TEST_ORFSM,
	TEST_ORFSS,
	TEST_RxLevel,
	TEST_Ber
};

struct RF_Instrument
{
	int iGPIB_Type;
	CString sTCPIP_Addr;
	short iGPIB_Card;//GPIBø®∫≈
	short iGPIB_Addr;//≤‚ ‘“«∆˜GPIBµÿ÷∑∫≈
};
struct PS_Instrument
{
	bool b_Ctrl_PS;
	int iGPIB_Type;
	CString sTCPIP_Addr;
	short iGPIB_Card;//GPIBø®∫≈
	short iGPIB_Addr;//≤‚ ‘“«∆˜GPIBµÿ÷∑∫≈
	double fVoltage;
	double fCurrent;
};
#define CHANNEL_NUM 10
struct GSM2G_NS_TEST_RST_All
{
	float TX_Power[4][CHANNEL_NUM];
	float Ber[4][CHANNEL_NUM];
	float FreqErr[4][CHANNEL_NUM];
	float PhaseErr[4][CHANNEL_NUM];
	float PhaseRMSErr[4][CHANNEL_NUM];
	int PVT[4][CHANNEL_NUM];
	int ORFSM[4][CHANNEL_NUM];
	int ORFSS[4][CHANNEL_NUM];
	int RxLevel[4][CHANNEL_NUM];
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