// AgilentCalib.h : header file
//

#if !defined(AFX_AGILENTCALIB_H__B2870891_6688_4FA7_6688_02775AB0F159__INCLUDED_)
#define AFX_AGILENTCALIB_H__B2870891_6688_4FA7_6688_02775AB0F159__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "caliblink_export.h"
#include "Rda2GCalib.h"

class CALIBLINK_API CAgilentCalib : public CRda2GCalib
{
    // 8960 Calibration Fucntions
public:
    CAgilentCalib();
    BOOL jade_adjust_crystal(long);
    void CalibInit    (double, double ,double , double );
    int CalibCrystal (int);
    int CalibAfcGain (unsigned char);
    int CalibILoss   (unsigned char, unsigned short, unsigned char);
    int CalibfastPaOffset(unsigned char band,unsigned int,int, int);
    void SetFastCaliDTSStop();
    void SetFastCaliDTSStart();
    DWORD SetFastCaliDTSParam(unsigned char);
    void SetFastCalibMode();
    VOID SetGSMFastCaliGlobalUTSParam();
    DWORD SetGSMFastCaliUTSParam(unsigned char, unsigned short, int);
    DWORD SetGSMFastoffsetCaliUTSParam(unsigned char band,unsigned short channel, int frame_num);
    void GetTokenStrings(LPTSTR , LPTSTR *, LPCTSTR, int *);
    DWORD GetFastCaliUTSResult(volatile float*);
    DWORD GetFastCaliboffsetUTSResult(char, volatile float *powbuffer);//(pFASTCALI_UL_APC_RTN pPwrRes)
    int GetArmStatus();
    void SetFastCalibMode(BOOL m_bFDTMode);
    int CalibPaPro   (unsigned char, unsigned short);
    int CalibfastPaPro(unsigned char band, unsigned short arfcn);
    int confirmPaPro (int, float*);
    int CalibPaOffset(unsigned char,unsigned int,int, int);
    int CalibChangeDACAfcGain(unsigned char);
    float  CalibTxLoss(unsigned char, short, float);
    float  CalibRxILoss(unsigned char, unsigned short, float, float);
    int InitPhone();
    int CalibChangeDACAfcFreq(unsigned char band);
    void CalibSetGsm850ILoss();
    void CalibSetGsm900ILoss();
    void CalibSetDcsILoss();
    void CalibSetPcsILoss();
//  void CopulingSetGsm850ILoss();
//  void CopulingSetGsm900ILoss();
//  void CopulingSetDcsILoss();
//  void CopulingSetPcsILoss();
    void ResetTester(char);
    int CheckArfcnIlossSpan(char Iloss[], char);
    void removemaxandmin(float* m_power);
    void ReadGpibCmd();
    int NSCalibPaOffset(unsigned char, unsigned short, unsigned char,float &m_power);
    int GPSTestPrepare();

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
};

#endif // !defined(AFX_AGILENTCALIB_H__B2870891_6688_4FA7_6688_02775AB0F159__INCLUDED_)
