// Cmw500Calib.h : header file
//

#if !defined(AFX_MT8870CALIB_H__B2870891_8888_4FA7_9355_02775AB0F159__INCLUDED_)
#define AFX_MT8870CALIB_H__B2870891_8888_4FA7_9355_02775AB0F159__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "caliblink_export.h"
#include "Rda2GCalib.h"

class CALIBLINK_API CMT8870Calib: public CRda2GCalib
{
public:
    CMT8870Calib();

    BOOL jade_adjust_crystal(long)  {
        return 0;
    }
    void CalibInit(double, double ,double , double) {
        ;
    }
    int CalibCrystal (int) {
        return 0;
    }
    int CalibAfcGain (unsigned char)  {
        return 0;
    }
    int CalibILoss   (unsigned char, unsigned short, unsigned char)  {
        return 0;
    }
    int CalibfastPaOffset(unsigned char band,unsigned int m_chipid,int maj_ver, int min_ver) {
        return 0;
    }
    void SetFastCaliDTSStop() {
        ;
    }
    void SetFastCaliDTSStart() {
        ;
    }
    DWORD SetFastCaliDTSParam(unsigned char) {
        return 0;
    }
    VOID SetGSMFastCaliGlobalUTSParam() {
        ;
    }
    DWORD SetGSMFastCaliUTSParam(unsigned char, unsigned short, int) {
        return 0;
    }
    DWORD SetGSMFastoffsetCaliUTSParam(unsigned char band,unsigned short channel, int frame_num)  {
        return 0;
    }
    void GetTokenStrings(LPTSTR , LPTSTR *, LPCTSTR, int *) {
        ;
    }
    DWORD GetFastCaliUTSResult(volatile float*)  {
        return 0;
    }
    DWORD GetFastCaliboffsetUTSResult(char, volatile float *powbuffer) {
        return 0;   //(pFASTCALI_UL_APC_RTN pPwrRes)
    }
    int GetArmStatus()  {
        return 0;
    }
    void SetFastCalibMode(BOOL m_bFDTMode)  {
        ;
    }
    int CalibPaPro   (unsigned char, unsigned short) {
        return 0;
    }
    int CalibfastPaPro(unsigned char band, unsigned short arfcn)  {
        return 0;
    }
    int confirmPaPro (int, float*)   {
        return 0;
    }
    int CalibPaOffset(unsigned char,unsigned int,int, int)  {
        return 0;
    }
    int CalibChangeDACAfcGain(unsigned char)    {
        return 0;
    }
    float  CalibTxLoss(unsigned char, short, float)   {
        return 0;
    }
    float  CalibRxILoss(unsigned char, unsigned short, float, float) {
        return 0;
    }
    int InitPhone() {
        return 0;
    }
    int CalibChangeDACAfcFreq(unsigned char band)   {
        return 0;
    }
    void CalibSetGsm850ILoss()  {
        ;
    }
    void CalibSetGsm900ILoss()  {
        ;
    }
    void CalibSetDcsILoss()     {
        ;
    }
    void CalibSetPcsILoss()     {
        ;
    }
    int NSCalibPaOffset(unsigned char, unsigned short, unsigned char,float &)    {
        return 0;
    }
    int CheckArfcnIlossSpan(char Iloss[], char)  {
        return 0;
    }
    void removemaxandmin(float* m_power)   {
        ;
    }
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

private:

};

#endif // !defined(AFX_MT8870CALIB_H__B2870891_8888_4FA7_9355_02775AB0F159__INCLUDED_)
