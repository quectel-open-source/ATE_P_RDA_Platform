#if !defined(AFX_CALIBFUNC_H__0085E535_3A50_4E39_B80F_0C486449C69E__INCLUDED_)
#define AFX_CALIBFUNC_H__0085E535_3A50_4E39_B80F_0C486449C69E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "stdafx.h"
#include "Typedef.h"
#include "TargetConnection.h"
#include "ChipInfo.h"
#include "AgilentTest.h"
#include "AgilentCalib.h"
#include "CmuCalib.h"
#include "CmuTest.h"
#include "AgilentE6607ACalib.h"
#include "AgilentE6607ANsft.h"
#include "AgilentE6640Calib.h"
#include "AgilentE6640Nsft.h"
#include "DTTest.h"
#include "DT3110Calib.h"
#include "Cmw500Test.h"
#include "Cmw500Calib.h"
#include "Cmu200Nsft.h"
#include "Agilent8960Nsft.h"
#include "Cmw500Nsft.h"
#include "Cmw100Calib.h"
#include "Cmw100Nsft.h"
#include "MT8821Calib.h"
#include "SP9010Calib.h"
#include "Rda2GCalib.h"
#include "Rda2GNsft.h"

CALIBLINK_API void Set4RampCurve(Calib_4RampCurve &rampcurve4);
CALIBLINK_API void Set24RampCurve(Calib_24RampCurve &rampcurve24);
CALIBLINK_API int ReadRam(uint32_t ramAddress, void *data,uint32_t length, TargetConnectionWrapper* conn);
CALIBLINK_API VOID BCD2Stri(unsigned char *pcIn, unsigned char *pcOut, unsigned char iLength);
CALIBLINK_API void logTitle(const char *title);


///////////////process related//////////////////////////
CALIBLINK_API int GetBSN(char *m_buffer, TargetConnectionWrapper* conn);
CALIBLINK_API int SetCalibNewPCL();
CALIBLINK_API int SetCalibDefaultPCL();
CALIBLINK_API int SetPaProfileDac(unsigned int chipid);
CALIBLINK_API int SetTiming();
CALIBLINK_API int Setramp(unsigned int chipid, int maj_ver, int min_ver);
CALIBLINK_API int checkOpen(TargetConnectionWrapper *conn, QString devicename);
CALIBLINK_API int CheckMmiLod(TargetConnectionWrapper *conn);
CALIBLINK_API int ReadEID(ChipInfo* chip, TargetConnectionWrapper *conn, unsigned char *dataBuf);
CALIBLINK_API int initCalibObj(ChipInfo* chip, TargetConnectionWrapper *conn, unsigned int &chipID, int &majVer, int &minVer);
CALIBLINK_API int doReadEID(ChipInfo* chip, TargetConnectionWrapper *conn, unsigned char* dataBuf);
CALIBLINK_API int ReadBSN(TargetConnectionWrapper *conn, unsigned char* dataBuf, int preBit, bool checkBit);
CALIBLINK_API void SaveCalibLogInfo(char* m_buffer);
CALIBLINK_API int enterCalibMode(TargetConnectionWrapper *conn);
CALIBLINK_API bool GetPhoneParam(std::string &xcvName, std::string &paName, std::string &swName);
CALIBLINK_API int GetPhaseCheck(std::string m_stationname, TargetConnectionWrapper* conn);
CALIBLINK_API int CalibPrepare(TargetConnectionWrapper* conn);
CALIBLINK_API int setCalibParams(unsigned int chipID, int maj_ver, int min_ver);
CALIBLINK_API void setTime(int iInitFlag);
CALIBLINK_API void showTime_Count(int iEndFlag);
CALIBLINK_API int CalibBurnFlash(void);
CALIBLINK_API int calibParasavetofile();
CALIBLINK_API int CalibItemsProcess(volatile unsigned int &calib_items, unsigned int CalibItemNum[4][5], unsigned int chipID, int maj_ver, int min_ver, CRda2GCalib* instrument,int GSMCalibItemsRet[20]);
CALIBLINK_API int NsftCalibPrepare(bool nsftFlag, TargetConnectionWrapper* conn);
CALIBLINK_API bool NSTestTotalInitialize(bool nsftFlag, TargetConnectionWrapper* conn, CRda2GNsft *instrument);
CALIBLINK_API int NsftGetComstatus();
CALIBLINK_API int NsftSetconnect(char band, unsigned int tch, unsigned int bch, char pcl,int times);
CALIBLINK_API int PrintPVT(char band);
CALIBLINK_API int PrintPFerror(char band);
CALIBLINK_API int PrintTxPower(char band, char Pcl);
CALIBLINK_API int PrintRxlevel(char band);
CALIBLINK_API BOOL MeasureBER(char band, char flag ,char nsftorcoupling ,float rxpower, CRda2GNsft* instrument);
CALIBLINK_API int NSTestItemProcess(char band, unsigned int tch, unsigned int bch, char pcl,int times, CRda2GNsft* instrument,struct GSM_NS_TEST_RST *m_gsm_test_ret);
CALIBLINK_API void NSTestPrintBandInfo(char band, unsigned int tch, unsigned int bch, char pcl);
CALIBLINK_API int CouplingPowerAndBerItemProcess(char band, unsigned int tch, unsigned int bch, char pcl,int times, CRda2GNsft* instrument);
CALIBLINK_API void CouplingPrintBandInfo(char band, unsigned int tch, unsigned int bch, char pcl);
CALIBLINK_API int CouplingPrintTxPower(unsigned char band, unsigned short arfcn,unsigned char pcl, float testpower);
CALIBLINK_API void NSTestPrintBandInfo(char band, unsigned int tch, unsigned int bch, char pcl);
CALIBLINK_API void CouplingPrintBandInfo(char band, unsigned int tch, unsigned int bch, char pcl);
CALIBLINK_API int TestItems(bool NStest, char band, unsigned int tch, unsigned int bch, char pcl,int times, CRda2GNsft* instrument,GSM_NS_TEST_RST *m_gsm_test_ret);
CALIBLINK_API int TestProcessLauncher(CCmuTest Cmutest, CAgilentTest Agitest, CDTTest Dttest, CCmw500Test Cmw500test);
CALIBLINK_API int CouplingPrepare(TargetConnectionWrapper* conn);
CALIBLINK_API int CouplingItems(unsigned char band, unsigned short arfcn,unsigned char pcl,float &m_power, CRda2GCalib* instrument);
CALIBLINK_API int CouplingPowerandBerCalibPrepare(TargetConnectionWrapper* conn);
CALIBLINK_API int CouplingPowerandBerTotalInitialize(CRda2GNsft* instrument, TargetConnectionWrapper* conn);
//nbiot
CALIBLINK_API int initNbiotCalibObj(ChipInfo* chip, TargetConnectionWrapper *conn, unsigned int &chipID, int &majVer, int &minVer);
CALIBLINK_API int enterNbiotCalibMode(TargetConnectionWrapper *conn);
CALIBLINK_API int NbiotCalibPrepare(TargetConnectionWrapper* conn);
CALIBLINK_API int NbiotCalibItemsProcess(volatile unsigned int &calib_items, unsigned int CalibItemNum[4][5],CRda2GCalib* instrument,int NBCalibItemsRet[20]);
CALIBLINK_API int NbiotBurnFlash(void);
CALIBLINK_API int NbiotNSTestItemProcess(int band, unsigned int txarfcn, float txpower, float rxpower,TargetConnectionWrapper* conn,CRda2GNsft* instrument,NB_NS_TEST_RST *m_nb_test_ret);
CALIBLINK_API int NbiotNsftStop();
CALIBLINK_API int NbiotNsftGetComstatus();
CALIBLINK_API int NbiotNsftSetconnect(int band,unsigned int arfcn,float txpower,float rxpower);
CALIBLINK_API int NbiotGetPhaseCheck(std::string m_stationname, TargetConnectionWrapper* conn);
CALIBLINK_API int NbiotNsftCalibPrepare(TargetConnectionWrapper* conn,int nsftflag);
CALIBLINK_API int NbiotCouplingPrepare(TargetConnectionWrapper* conn);
CALIBLINK_API int NbiotChannel(int band,int txarfcn,int *rxarfcn);
CALIBLINK_API int NbiotCouplingProcess(TargetConnectionWrapper* conn,CRda2GNsft* instrument);
CALIBLINK_API int NbiotNsftInstrumentPrepare(CRda2GNsft* instrument);
CALIBLINK_API int NbiotInstrumentPrepare(CRda2GCalib* instrument);
CALIBLINK_API int NbiotCouplingInstrumentPrepare(CRda2GNsft* instrument);
CALIBLINK_API int NbiotCouplingItems(int band, unsigned int txarfcn, float txpower,CRda2GNsft* instrument);

//////////////////relate to instrument/////////////////////////
CALIBLINK_API int CalibPowerOff();
CALIBLINK_API void AgilentPowerConnect();
CALIBLINK_API int MeasurCurrent(float *current);
CALIBLINK_API int GetAutotestCurrAnyTime();
CALIBLINK_API int GetCurrAnyTime();
CALIBLINK_API void ResetTester(char band, CRda2GCalib* instrument);
CALIBLINK_API int InstrumentPrepare(CRda2GCalib* instrument);
CALIBLINK_API int CalibBatteryVS(void);
CALIBLINK_API int CalibCrystal(CRda2GCalib* instrument);
CALIBLINK_API int CalibAfcGain(char band, CRda2GCalib* instrument);
CALIBLINK_API void SetFastCalibMode(CRda2GCalib* instrument);
CALIBLINK_API int CalibfastPaProfile(char band, int channel, CRda2GCalib* instrument);
CALIBLINK_API int CalibPaProfile(char band, int channel, CRda2GCalib* instrument);
CALIBLINK_API int CalibPaOffset(char band, CRda2GCalib* instrument, unsigned int chipID, int maj_ver, int min_ver);
CALIBLINK_API int CalibfastPaOffset(char band, CRda2GCalib* instrument, unsigned int chipID, int maj_ver, int min_ver);
CALIBLINK_API void SetFastCalibStopMode(CRda2GCalib* instrument);
CALIBLINK_API int CalibILoss(char band, int channel, int power, CRda2GCalib* instrument);

#endif // !defined(AFX_CALIBILOSSDCSDLG_H__0084EB35_3A50_4E39_B80F_0C486449C69E__INCLUDED_)
