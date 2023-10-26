// Cmw500Calib.h : header file
//

#if !defined(AFX_SP9010CALIB_H__B2870891_8888_4FA7_9355_02775AB0F159__INCLUDED_)
#define AFX_SP9010CALIB_H__B2870891_8888_4FA7_9355_02775AB0F159__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "caliblink_export.h"
#include "Rda2GCalib.h"

class CALIBLINK_API CSP9010Calib: public CRda2GCalib
{
    // Cmw500 Calibration Fucntions
public:
    CSP9010Calib();

	BOOL jade_adjust_crystal(long);
	void CalibInit(double, double ,double , double );
	int CalibCrystal(int);
	int CalibAfcGain(unsigned char);
	int CalibILoss(unsigned char, unsigned short, unsigned char);
	int CalibPaPro(unsigned char, unsigned short);
	int confirmPaPro(int, float*);
	int CalibPaOffset(unsigned char,unsigned int,int, int);
	float ch2freq(unsigned char, unsigned short, BOOL);
	int CalibChangeDACAfcFreq(unsigned char);
	int CalibChangeDACAfcGain(unsigned char);
	float  CalibTxLoss(unsigned char band, short m_channel, float m_txPower);
	int CheckArfcnIlossSpan(char Iloss[], char);
	void removemaxandmin(float* m_power);
	void SetFastCalibMode(BOOL);
	DWORD SetGSMFastCaliUTSParam(unsigned char ,unsigned short, int);
	void GetTokenStrings(LPTSTR , LPTSTR *, LPCTSTR , int *);
	DWORD GetGSMFastCaliULResult(unsigned char,volatile float *);
	int CalibfastPaPro(unsigned char, unsigned short);
	VOID SetGSMFastCaliGlobalUTSParam();
	int SetGSMFastoffsetCaliUTSParam(unsigned char);
	int  GetFastCaliboffsetUTSResult(unsigned char,volatile float*);
	int  CalibfastPaOffset(unsigned char,unsigned int,int, int);
	int pcl2dbm(char band, char pcl);
	void SetBCHChannel(char band,int channel);
	void SetTCHChannel(char band, unsigned short channel);
	void SetTCHPcl(char band, char pcl);
	void SetTCHTsc(unsigned char tsc);
	void SetTCHPower(float Power);
	int GetFreqErr(float *m_freqerr);
	int GetTxPower(int exppow,float *measurepow);
	int GetTxOffsetPower(char band,int pcl,float *measurepow);
	void SetMeasureRxILoss(unsigned char SelPow);
	void WriteGpibcmd(char* cmdbuff);
	void SetRxChannel(char band, int Arfcn);
	void SetFastCaliDTSStop();
	void SetFastCaliDTSStart();
	DWORD SetFastCaliDTSParam(unsigned char);
	DWORD SetGSMFastoffsetCaliUTSParam(unsigned char band,unsigned short channel, int frame_num);
	DWORD GetFastCaliUTSResult(volatile float*);
	int GetArmStatus();
	DWORD GetFastCaliboffsetUTSResult(char, volatile float *powbuffer);
	float CalibRxILoss(unsigned char, unsigned short, float, float);
	int InitPhone();
	void CalibSetGsm850ILoss();
	void CalibSetGsm900ILoss();
	void CalibSetDcsILoss();
	void CalibSetPcsILoss();
	int NSCalibPaOffset(unsigned char, unsigned short, unsigned char,float&);
	float CalibMakeGolden(unsigned char band, short m_channel, float iloss);

    void ResetTester(char);
    void ReadGpibCmd();

    //nbiot
    void NbiotCalibInit();
    int NbiotCalibAfcGain(int band, int arfcn,float txpower,int state);
    int NbiotCalibILoss(int band, unsigned short arfcn,float rxpower,int state);
    int NbiotCalibPaOffset(int band, unsigned short arfcn,float txpower,int state);
    int NbiotCalibPaPro(int band, unsigned short arfcn,float txpower,int state);
    int NbiotCalibCrystal(int band, int arfcn,float txpower,int state);
    int NbiotChan2Freq(int band,int arfcn,float *DlFreq,float *UlFreq,int UL_DL);
    int NbiotGetFreqErr(float *m_freqerr);
    int NbiotGetTxPower(float *Power);
    int NbiotSetiLoss(int band,unsigned short arfcn,int DL_UL);
	float NbiotCalibTxLoss(int band, int arfcn,float txpower,int state);
	float NbiotCalibMakeGolden(int band, int arfcn,float ILoss,int state);

private:

};

#endif // !defined(AFX_SP9010CALIB_H__B2870891_8888_4FA7_9355_02775AB0F159__INCLUDED_)
