// Cmw500Test.h : header file
//

#if !defined(AFX_CMW500NSFT_H__B2870891_8668_4FA7_6699_02775AB0F188__INCLUDED_)
#define AFX_CMW500NSFT_H__B2870891_8668_4FA7_6699_02775AB0F188__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "caliblink_export.h"
#include "Rda2GNsft.h"

class CALIBLINK_API CCmw500Nsft: public CRda2GNsft
{
public:
    CCmw500Nsft();
    void NonsigTotalInitialize();
    void NonsigInitialize(char,int, int,char);
    void WriteGpibCmd(const char *cmdbuff, ...);
    void ReadGpibCmd();
    void SetRfPathLoss(char band);
    int pcl2dbm(char band, char pcl);
    void SetNsftMeasWin();
    int NsftMeasureTxPower(char band, int pcl, float& power);
    float ch2freq(unsigned char band, unsigned short arfcn, BOOL dw1up0);
    int NsftMeasurePVT(char band);
    int NsftMeasurePhaseNFrequency(char band);
    int NsftMeasureRxLevel(char band, int);
    void SetCellPower(char, int);
    void GetTokenStrings(LPTSTR lpszSouce, LPTSTR *lppszDest, LPCTSTR lpsczDelimit, int *lpnCount);
    int NSFTSetup(char, int);
    int TestSensitivity(unsigned char band);
    int CouplingSensitivity(unsigned char band);
    void NonsigSetup();
    int TestModulation(unsigned char);
    int TestSwSpec(unsigned char);
public:
};

#endif // !defined(AFX_CMW500NSFT_H__B2870891_8668_4FA7_6699_02775AB0F188__INCLUDED_)
