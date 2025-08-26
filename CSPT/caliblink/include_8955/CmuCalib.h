// CmuCalib.h : header file
//

#if !defined(AFX_CMUCALIB_H__B2870891_8888_4FA7_9338_02775AB0F159__INCLUDED_)
#define AFX_CMUCALIB_H__B2870891_8888_4FA7_9338_02775AB0F159__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "caliblink_export.h"
#include "Rda2GCalib.h"

class CALIBLINK_API CCmuCalib: public CRda2GCalib
{
    // CMU Calibration Fucntions
public:
    CCmuCalib();
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
    void SetGSMFastoffsetCaliUTSParam(unsigned char);
    int  GetFastCaliboffsetUTSResult(unsigned char,volatile float*);
    int  CalibfastPaOffset(unsigned char,unsigned int,int, int);
    BOOL jade_adjust_crystal(long);
    void SetFastCaliDTSStop();
    void SetFastCaliDTSStart();
    DWORD SetFastCaliDTSParam(unsigned char);
    DWORD SetGSMFastoffsetCaliUTSParam(unsigned char band,unsigned short channel, int frame_num);
    DWORD GetFastCaliUTSResult(volatile float*);
    int GetArmStatus();
    DWORD GetFastCaliboffsetUTSResult(char, volatile float *powbuffer);
    float  CalibRxILoss(unsigned char, unsigned short, float, float);
    int InitPhone();
    void CalibSetGsm850ILoss();
    void CalibSetGsm900ILoss();
    void CalibSetDcsILoss();
    void CalibSetPcsILoss();
    void ResetTester(char);
    void ReadGpibCmd();
//  int NSCalibPrintTxPower(unsigned char, unsigned short,unsigned char, float);
    int NSCalibPaOffset(unsigned char, unsigned short, unsigned char,float &);
private:

};

#endif // !defined(AFX_CMUCALIB_H__B2870891_8888_4FA7_9338_02775AB0F159__INCLUDED_)
