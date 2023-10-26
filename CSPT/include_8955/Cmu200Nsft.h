// CmuTest.h : header file
//

#if !defined(AFX_CMU200NSFT_H__B2870891_8866_4FA7_6886_02775AB0F159__INCLUDED_)
#define AFX_CMU200NSFT_H__B2870891_8866_4FA7_6886_02775AB0F159__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "caliblink_export.h"
#include "Rda2GNsft.h"

class CALIBLINK_API CCmu200Nsft: public CRda2GNsft
{
public:
    CCmu200Nsft();
    void NonsigTotalInitialize();
    void SetRfPathLoss(char);
    void WriteGpibCmd(const char *cmdbuff, ...);
    void ReadGpibCmd();
    void NonsigInitialize(char,int, int,char);
    int NSFTSetup(char, int);
    void SetCellPower(char band, int power);
    int TestSensitivity(unsigned char band);
    int CouplingSensitivity(unsigned char band);
    void GetTxpower(char);
    int NsftMeasurePhaseNFrequency(char band);
    int NsftMeasureRxLevel(char band, int);
    int TestModulation(unsigned char);
    int TestSwSpec(unsigned char);
    int TestMeasCmu  (unsigned char, unsigned int);
    int TestDisConn();
    void SetErrorBit(int);
    int pcl2dbm(char , char);
    void SetNsftMeasWin();
    void GetTokenStrings(LPTSTR lpszSouce, LPTSTR *lppszDest, LPCTSTR lpsczDelimit, int *lpnCount);
    float ch2freq(unsigned char, unsigned short, BOOL);
    int NsftMeasurePVT(char band);
    int NsftMeasureTxPower(char band, int pcl, float& power);
    void NonsigSetup();
    void NSFTSetupCellPower(char band,int power);
public:
};

#endif // !defined(AFX_CMU200NSFT_H__B2870891_8866_4FA7_6886_02775AB0F159__INCLUDED_)
