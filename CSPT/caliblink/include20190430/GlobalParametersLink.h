#ifndef GLOBAL_PARAMETERS_LINK_H
#define GLOBAL_PARAMETERS_LINK_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "caliblink_export.h"
#include "Typedef.h"
#include "visa.h"
#include "ColorListBox.h"
#include "visatype.h"
#include <string>

typedef enum {
    JDL_ARFCN_MIN,
    JDL_ARFCN_MAX
} jdl_arfcn_pos_t;

enum {
    STATUS_CANCEL = -10,
    STATUS_FAIL_BAND_3 = -4,
    STATUS_FAIL_BAND_2 = -3,
    STATUS_FAIL_BAND_1 = -2,
    STATUS_FAIL = -1,
    STATUS_PASS = 0,
};

class Caliberation;

CALIBLINK_API extern CFile *m_LogFile;
CALIBLINK_API extern Caliberation* m_calib;
CALIBLINK_API extern CColorListBox* m_DisplayList;
CALIBLINK_API extern char m_strcaliberrbuf[256];
CALIBLINK_API extern int m_stopflag;
CALIBLINK_API extern  int     logtext(const char *, ...);
CALIBLINK_API extern void     BufferClean(void);
CALIBLINK_API extern void     BufferChangeFormat(void);
CALIBLINK_API extern char     gpib_InBuffer[4096];
CALIBLINK_API extern int m_Rfport;
CALIBLINK_API extern int m_iqxstream;
CALIBLINK_API extern int m_cmw100;
CALIBLINK_API extern int  m_Idisplayflag;
CALIBLINK_API extern unsigned int m_testfailitemflag;
CALIBLINK_API extern float m_Pow;             // Power
CALIBLINK_API extern float m_frequency[3];
CALIBLINK_API extern int  m_initpvt;
CALIBLINK_API extern int  m_orfsinit;
CALIBLINK_API extern float m_RxLev; // RxLev
CALIBLINK_API extern int  m_iberr;
CALIBLINK_API extern float m_fberr[3];
CALIBLINK_API extern unsigned char  m_GorD;       //0 - GSM , 1 - DCS
//tester
CALIBLINK_API extern int m_gCalibIlossLimit;
CALIBLINK_API extern int m_gChannelIlosslimit;
CALIBLINK_API extern  int m_gradio1128;
// Tester Used Flag
// 0 = CMU200
// 1 = 8960
//extern int m_gPmdopalorct1010;
CALIBLINK_API extern int           m_UseTcpPort;
CALIBLINK_API extern int h_BASE;               //tester handle
CALIBLINK_API extern int m_TestorCalibflag;
CALIBLINK_API extern int m_selecRFflag;
CALIBLINK_API extern float m_prfsswitch[8];
CALIBLINK_API extern float m_prfsmodulate[22];
CALIBLINK_API extern float m_pvtmask;
CALIBLINK_API extern ViSession instr;
CALIBLINK_API extern ViStatus status;
CALIBLINK_API extern Band_select m_gBandTestSelect;
CALIBLINK_API extern int m_gConnectTime;
CALIBLINK_API extern int m_gConnectPower;
CALIBLINK_API extern Channel_select m_gcalibchannel;
CALIBLINK_API extern Channel_select m_gtestchannel;
CALIBLINK_API extern Calib_PclValue m_gcalibpcl;
CALIBLINK_API extern Calib_Item m_gcalibItem;
CALIBLINK_API extern Test_PandFError m_gPandFError;
CALIBLINK_API extern Test_RxLevel m_gRxLevel;
CALIBLINK_API extern Test_Item m_gTestItemflag;
CALIBLINK_API extern Coupling_Item m_gCouplingItemflag;
CALIBLINK_API extern Coupling_Ber m_gCouplingSensitivity;
CALIBLINK_API extern Test_Sensitivity m_gSensitivity;
CALIBLINK_API extern Gsm_AllPclLimitvalue m_gGSmPCLLimit;
CALIBLINK_API extern Gsm_AllPclLimitvalue m_gEGSmPCLLimit;
CALIBLINK_API extern Dcs_AllPclLimitvalue m_gDCSPCLLimit;
CALIBLINK_API extern Dcs_AllPclLimitvalue m_gPCSPCLLimit;
CALIBLINK_API extern AllSwitchSpecture m_gGSMSwitchSpecture;
CALIBLINK_API extern AllSwitchSpecture m_gDCSSwitchSpecture;

CALIBLINK_API extern AllModulationSpecture m_gGSMModuSpecture;    // GSM and DCS use the same table
CALIBLINK_API extern AllModulationSpecture m_gDCSModuSpecture;

CALIBLINK_API extern ILossSetup m_gGsm850ILoss;
CALIBLINK_API extern ILossSetup m_gGsm900ILoss;
CALIBLINK_API extern ILossSetup m_gDcsILoss;
CALIBLINK_API extern ILossSetup m_gPcsILoss;

CALIBLINK_API extern unsigned int  m_factoryAddress;
CALIBLINK_API extern Calib_GsmPclLevelValue m_gGsmcalibPcl;
CALIBLINK_API extern char m_BSNbuffer[56];
CALIBLINK_API extern bool m_ReadEID;
CALIBLINK_API extern int  ih_BASE_Gpadc;       //power  handle
CALIBLINK_API extern Calib_GsmPclLevelValue m_gEGsmcalibPcl;
CALIBLINK_API extern Calib_DcsPclLevelValue m_gDcscalibPcl;
CALIBLINK_API extern Calib_DcsPclLevelValue m_gPcscalibPcl;
CALIBLINK_API extern Calib_GsmPclLevelValue m_gdefaultGsmcalibPcl;
CALIBLINK_API extern int  iGlobalFlagBs;
CALIBLINK_API extern Calib_DcsPclLevelValue m_gDcsDefaultCalibPCL ;
CALIBLINK_API extern Calib_PaProfileDac m_gGsmProfileDac;
CALIBLINK_API extern Calib_PaProfileDac m_gPcsProfileDac;
CALIBLINK_API extern Calib_PaProfileDac m_gEGsmProfileDac;
CALIBLINK_API extern Calib_PaProfileDac m_gDcsProfileDac;
CALIBLINK_API extern Calib_XCVTiming m_gXcvTiming;
CALIBLINK_API extern Calib_PATiming  m_gPaTiming;
CALIBLINK_API extern Calib_SWTiming  m_gSwTiming;
CALIBLINK_API extern int m_gtxIQtimingoffset;
CALIBLINK_API extern Calib_24RampCurve m_g24rampcurve;
CALIBLINK_API extern Calib_4RampCurve m_g4rampcurve;
CALIBLINK_API extern int  VoltOut;
CALIBLINK_API extern int  m_gCalibInittime;
CALIBLINK_API extern int  m_CheckCalibPreStation;
CALIBLINK_API extern std::string   m_PreStationCalib;
CALIBLINK_API extern int m_timingfileflag;
CALIBLINK_API extern int m_paprifilefileflag;
CALIBLINK_API extern calib_voltage m_gcalibvoltage;
CALIBLINK_API extern int m_AutoTestflag;
CALIBLINK_API extern int m_CheckNsTestPreStation;
CALIBLINK_API extern std::string   m_PreStarionNSTEST;
CALIBLINK_API extern Gsm_AllPclLimitvalue m_gDefaultGSmPCLLimit;
CALIBLINK_API extern Dcs_AllPclLimitvalue m_gDefaultDCSPCLLimit;
CALIBLINK_API extern Insertion_Loss m_gTestILoss;
CALIBLINK_API extern int m_CheckANNTESTPreStation;
CALIBLINK_API extern std::string   m_PreStarionANNTEST;
CALIBLINK_API extern Coupling_PclValue m_gCouplingpcl;
CALIBLINK_API extern ViSession defaultRM;
CALIBLINK_API extern int GpibFlag;

CALIBLINK_API extern unsigned int  m_IsSetCalibBit;
CALIBLINK_API extern unsigned int  m_IsPreCalibSetBit;
CALIBLINK_API extern unsigned int  m_IsSetFunBit;
CALIBLINK_API extern unsigned int  m_IsPreTestSetBit;
CALIBLINK_API extern unsigned int  m_IsUnsetFunBit;
CALIBLINK_API extern std::string m_ConnDeviceName;
CALIBLINK_API extern int m_calibandtestmod;
CALIBLINK_API extern int m_flashtype;
CALIBLINK_API extern std::string   m_TcpHostName;
CALIBLINK_API extern int           m_PasswordNeeded;
CALIBLINK_API extern unsigned int  m_AutoTesttimes;
CALIBLINK_API extern int           m_SignalTestflag;
CALIBLINK_API extern int           m_SetCalibStation;
CALIBLINK_API extern int           m_SetNsTestStation;
CALIBLINK_API extern int           m_SetANNTESTStation;
CALIBLINK_API extern int m_systemfileflag;
CALIBLINK_API extern int m_bgPlatform;
CALIBLINK_API extern int m_GpibIDNum;
CALIBLINK_API extern int  iGpibNumber;
//power
CALIBLINK_API extern int  iPowPriAddr;
CALIBLINK_API extern int  iPowSecAddr;
//tester
CALIBLINK_API extern int  iTesterPriAddr;
CALIBLINK_API extern int  iTesterSecAddr;

CALIBLINK_API extern std::string m_gpsDeviceName;
CALIBLINK_API extern bool     m_EnableGPSTest;
CALIBLINK_API extern bool     m_AutoShutDown;
CALIBLINK_API extern int      m_GPSTimeout;
CALIBLINK_API extern int      m_CalibStartDelayTime;
CALIBLINK_API extern bool     m_bUseCoolHostCom;
CALIBLINK_API extern std::string   m_CoolHostName;
CALIBLINK_API extern int m_gdefaultGPSPowerlimit;
CALIBLINK_API extern int m_gGPSPowerlimit;
CALIBLINK_API extern int m_gdefaultGpsGrpLen;
CALIBLINK_API extern int m_mcc_val;
CALIBLINK_API extern int m_mnc_val;

//for NB-iot
CALIBLINK_API extern int m_NB;
CALIBLINK_API extern int m_GSM;
CALIBLINK_API extern  int m_AFC_Calib;

CALIBLINK_API extern int m_NB_calib_usePower;
CALIBLINK_API extern NB_Calib_Item m_NB_calib_items;
CALIBLINK_API extern NB_Calib_AgcPara m_NB_calib_AgcParams;
CALIBLINK_API extern NB_Calib_BandSelect m_NB_calib_BandCK;
CALIBLINK_API extern NB_Calib_iloss m_NB_calib_bandiloss;
CALIBLINK_API extern NB_Calib_ApcPara m_NB_calib_ApcParams;
CALIBLINK_API extern NB_Calib_CrystalPara m_NB_Calib_CrystalPara;

CALIBLINK_API extern NB_Test_Item m_NB_Test_items;
CALIBLINK_API extern NB_Test_Channel m_NB_Test_channel;
CALIBLINK_API extern NB_Test_SensPow m_NB_Test_SensPow;
CALIBLINK_API extern NB_Test_CouplingPow m_NB_Test_CouplingPow;
CALIBLINK_API extern NB_Test_SeleChannel m_NB_Test_SeleChannel;

CALIBLINK_API extern int           m_NBiotCheckNsTestPreStation;
CALIBLINK_API extern int           m_NBiotSetNsTestStation;
CALIBLINK_API extern std::string   m_NBiotPreStarionNSTEST;
CALIBLINK_API extern int           m_NBiotCheckANNTESTPreStation;
CALIBLINK_API extern int           m_NBiotSetANNTESTStation;
CALIBLINK_API extern std::string   m_NBiotPreStarionANNTEST;
//end for NB-iot

CALIBLINK_API extern float ch2freq(unsigned char band, unsigned short arfcn, BOOL dw1up0);
CALIBLINK_API extern void WriteGpibcmd(char* cmdbuff);
CALIBLINK_API extern void ReadGpibCmd();

CALIBLINK_API extern unsigned char IsHex(const char* szStr);
CALIBLINK_API extern unsigned char IsInteger(char* szStr);
CALIBLINK_API extern unsigned char IsFloat(char* szStr);
CALIBLINK_API extern unsigned long u4HexCharToDecInt(char word);
CALIBLINK_API extern unsigned long u4HexToDecInt(const char *szHex, short int i2Size);

CALIBLINK_API extern GOLDEN_CABLE_LOSS m_golden_cable_loss;

#endif // !defined(AFX_GLOBALPARAMETERS_H__B2870891_8888_9999_9338_02775AB0F888__INCLUDED_)
