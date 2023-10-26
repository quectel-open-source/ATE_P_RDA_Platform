#if !defined(AFX_RDA2GCALIB_H__B2870891_6688_4FA7_0001_02775AB0F159__INCLUDED_)
#define AFX_RDA2GCALIB_H__B2870891_6688_4FA7_0001_02775AB0F159__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "caliblink_export.h"

class CALIBLINK_API CRda2GCalib
{
public:
    CRda2GCalib()
    {
    }
    ~CRda2GCalib()
    {
    }
    virtual BOOL jade_adjust_crystal(long) = 0;
    virtual void CalibInit    (double, double ,double , double) = 0;
    virtual int CalibCrystal (int) = 0;
    virtual int CalibAfcGain (unsigned char) = 0;
    virtual int CalibILoss   (unsigned char, unsigned short, unsigned char) = 0;
    virtual int CalibfastPaOffset(unsigned char band,unsigned int m_chipid,int maj_ver, int min_ver) = 0;
    virtual void SetFastCaliDTSStop() = 0;
    virtual void SetFastCaliDTSStart() = 0;
    virtual DWORD SetFastCaliDTSParam(unsigned char) = 0;
    virtual VOID SetGSMFastCaliGlobalUTSParam() = 0;
    virtual DWORD SetGSMFastCaliUTSParam(unsigned char, unsigned short, int) = 0;
    virtual DWORD SetGSMFastoffsetCaliUTSParam(unsigned char band,unsigned short channel, int frame_num) = 0;
    virtual void GetTokenStrings(LPTSTR , LPTSTR *, LPCTSTR, int *) = 0;
    virtual DWORD GetFastCaliUTSResult(volatile float*) = 0;
    virtual DWORD GetFastCaliboffsetUTSResult(char, volatile float *powbuffer) = 0;//(pFASTCALI_UL_APC_RTN pPwrRes)
    virtual int GetArmStatus() = 0;
    virtual void SetFastCalibMode(BOOL m_bFDTMode) = 0;
    virtual int CalibPaPro   (unsigned char, unsigned short) = 0;
    virtual int CalibfastPaPro(unsigned char band, unsigned short arfcn) = 0;
    virtual int confirmPaPro (int, float*) = 0;
    virtual int CalibPaOffset(unsigned char,unsigned int,int, int) = 0;
    virtual int CalibChangeDACAfcGain(unsigned char) = 0;
    virtual float  CalibTxLoss(unsigned char, short, float) = 0;
    virtual float  CalibRxILoss(unsigned char, unsigned short, float, float) = 0;
    virtual int InitPhone() = 0;
    virtual int CalibChangeDACAfcFreq(unsigned char band) = 0;
    virtual void CalibSetGsm850ILoss() = 0;
    virtual void CalibSetGsm900ILoss() = 0;
    virtual void CalibSetDcsILoss() = 0;
    virtual void CalibSetPcsILoss() = 0;
    virtual int NSCalibPaOffset(unsigned char, unsigned short, unsigned char,float &) = 0;
//  virtual void CopulingSetGsm850ILoss() = 0;
//  virtual void CopulingSetGsm900ILoss() = 0;
//  virtual void CopulingSetDcsILoss() = 0;
//  virtual void CopulingSetPcsILoss() = 0;

    virtual int CheckArfcnIlossSpan(char Iloss[], char) = 0;
    virtual void removemaxandmin(float* m_power) = 0;
    virtual void ResetTester(char) = 0;
    virtual void ReadGpibCmd() = 0;
};

#endif // !defined(AFX_RDA2GCALIB_H__B2870891_6688_4FA7_0001_02775AB0F159__INCLUDED_)
