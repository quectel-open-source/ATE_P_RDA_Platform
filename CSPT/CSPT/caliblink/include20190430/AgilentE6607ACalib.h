// AgilentCalib.h : header file
//

#if !defined(AFX_AGILENTE6607ACALIB_H__B2870891_abcd_4FA7_6688_02775AB0F159__INCLUDED_)
#define AFX_AGILENTE6607ACALIB_H__B2870891_abcd_4FA7_6688_02775AB0F159__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "caliblink_export.h"
#include "Rda2GCalib.h"

class CALIBLINK_API CAgilentE6607ACalib: public CRda2GCalib
{
    // 8960 Calibration Fucntions
public:
    CAgilentE6607ACalib();
    BOOL jade_adjust_crystal(long);
    void CalibInit (double, double ,double , double );
    int CalibCrystal(int);

    void SetFastCaliDTSStop();
    void SetFastCaliDTSStart();
    DWORD SetFastCaliDTSParam(unsigned char);
    void SetFastCalibMode();
    VOID SetGSMFastCaliGlobalUTSParam();
    DWORD SetGSMFastCaliUTSParam(unsigned char, unsigned short, int);
    void GetTokenStrings(LPTSTR , LPTSTR *, LPCTSTR, int *);
    DWORD GetFastCaliUTSResult(volatile float*);
    DWORD GetFastCaliboffsetUTSResult(char, volatile float *powbuffer);//(pFASTCALI_UL_APC_RTN pPwrRes)
    int GetArmStatus();
    int CalibfastPaPro(unsigned char band, unsigned short arfcn);
    void SetFastCalibMode(BOOL m_bFDTMode);
    int CalibChangeDACAfcGain(unsigned char);
    float  CalibTxLoss(unsigned char, short, float);
    float  CalibRxILoss(unsigned char, unsigned short, float, float);
    int InitPhone();
    int CalibChangeDACAfcFreq(unsigned char band);
    void CalibSetGsm900ILoss();
    void CalibSetGsm850ILoss();
    DWORD SetGSMFastoffsetCaliUTSParam(unsigned char,unsigned short, int);

    int  CalibfastPaOffset(unsigned char,unsigned int,int, int);
    int CalibPaPro(unsigned char, unsigned short);
    void CalibSetDcsILoss();
    void CalibSetPcsILoss();
    int CalibILoss(unsigned char, unsigned short, unsigned char);
    int  CalibAfcGain(unsigned char);
    int CheckArfcnIlossSpan(char Iloss[], char);
    void removemaxandmin(float* m_power);
    int GetTxPwr(float *);
    int confirmPaPro (int, float*);
    int CalibPaOffset(unsigned char,unsigned int,int, int);
    void ResetTester(char);
    void ReadGpibCmd();
    int NSCalibPaOffset(unsigned char, unsigned short, unsigned char,float&);
	float  CalibMakeGolden(unsigned char band, short m_channel, float iloss);

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

};

#endif // !defined(AFX_AGILENTE6607ACALIB_H__B2870891_abcd_4FA7_6688_02775AB0F159__INCLUDED_)
