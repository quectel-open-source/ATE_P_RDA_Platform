#if !defined(AFX_DT3110CALIB_H__B2870891_6688_4FA7_6688_02775AB0F666__INCLUDED_)
#define AFX_DT3110CALIB_H__B2870891_6688_4FA7_6688_02775AB0F666__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "caliblink_export.h"
#include "Rda2GCalib.h"

class CALIBLINK_API CDT3110Calib: public CRda2GCalib
{
public:
    CDT3110Calib();
    void SetFastCalibMode();
    VOID SetGSMFastCaliGlobalUTSParam();
    DWORD SetGSMFastCaliUTSParam(unsigned char, unsigned short, int);
    DWORD SetGSMFastCalipaoffsetUTSParam(unsigned char band,unsigned short channel, int frame_num);
    void GetTokenStrings(LPTSTR , LPTSTR *, LPCTSTR, int *);
    DWORD GetFastCaliUTSResult();
    void SetFastCalibMode(BOOL m_bFDTMode);
    BOOL jade_adjust_crystal(long);
    void CalibInit    (double, double ,double , double );
    int CalibCrystal (int);
    int CalibAfcGain (unsigned char);
    int CalibILoss   (unsigned char, unsigned short, unsigned char);
    int CalibIP2     (unsigned char);
    int CalibPaPro   (unsigned char, unsigned short);
    int confirmPaPro (int, float*);
    int CalibPaOffset(unsigned char,unsigned int,int, int);
    int CalibChangeDACAfcGain(unsigned char);
    int CalibChangeDACAfcFreq(unsigned char band);
    int CalibfastPaPro(unsigned char band, unsigned short arfcn);
    int CalibfastPaOffset(unsigned char band,unsigned int,int, int);
    void SetFastCaliDTSStop();
    void SetFastCaliDTSStart();
    DWORD SetFastCaliDTSParam(unsigned char);
    DWORD SetGSMFastoffsetCaliUTSParam(unsigned char band,unsigned short channel, int frame_num);
    DWORD GetFastCaliUTSResult(volatile float*);
    int GetArmStatus();
    DWORD GetFastCaliboffsetUTSResult(char, volatile float *powbuffer);
    float  CalibTxLoss(unsigned char, short, float);
    float  CalibRxILoss(unsigned char, unsigned short, float, float);
    int InitPhone();
    void CalibSetGsm850ILoss();
    void CalibSetGsm900ILoss();
    void CalibSetDcsILoss();
    void CalibSetPcsILoss();
    int CheckArfcnIlossSpan(char Iloss[], char);
    void removemaxandmin(float* m_power);
    void ResetTester(char);
    void ReadGpibCmd();
    int NSCalibPaOffset(unsigned char, unsigned short, unsigned char,float &m_power);
	float CalibMakeGolden(unsigned char band, short m_channel, float iloss){
		return 0;
	}

//nbiot
    void NbiotCalibInit() {
        ;
    }
    int  NbiotCalibAfcGain(int, int,float,int)  {
        return 0;
    }
    int  NbiotCalibILoss(int, unsigned short,float,int) {
        return 0;
    }
    int  NbiotCalibPaOffset(int, unsigned short,float,int)    {
        return 0;
    }
    int  NbiotCalibPaPro(int, unsigned short,float,int)    {
        return 0;
    }
    int  NbiotCalibCrystal(int, int,float,int)   {
        return 0;
    }
	float NbiotCalibTxLoss(int band, int arfcn,float txpower,int state){
		return 0;
	}
	float NbiotCalibMakeGolden(int band, int arfcn,float ILoss,int state){
		return 0;
	}
	int NbiotInstrFastMode(bool ){
		return 0;
	}
	int NbiotFastSetPowOffset(int band,int arfcn,int slotcount, float* targetpwr){
		return 0;
	}
	int NbiotFastGetPowOffset(int slotcount,float* power){
		return 0;
	}
};

#endif // !defined(AFX_DT3110CALIB_H__B2870891_6688_4FA7_6688_02775AB0F666__INCLUDED_)
