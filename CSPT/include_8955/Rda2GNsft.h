#if !defined(AFX_RDA2GNSFT_H__B2870891_6688_4FA7_0002_02775AB0F159__INCLUDED_)
#define AFX_RDA2GNSFT_H__B2870891_6688_4FA7_0002_02775AB0F159__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "caliblink_export.h"

class CALIBLINK_API CRda2GNsft
{
public:
    CRda2GNsft()
    {
    }
    ~CRda2GNsft()
    {
    }
    virtual void NonsigTotalInitialize() = 0;
    virtual void NonsigInitialize(char,int, int,char) = 0;
    virtual void WriteGpibCmd(const char *cmdbuff, ...) = 0;
    virtual void ReadGpibCmd() = 0;
    virtual void SetRfPathLoss(char band) = 0;
    virtual int pcl2dbm(char band, char pcl) = 0;
    virtual void SetNsftMeasWin() = 0;
    virtual int NsftMeasureTxPower(char band, int pcl,float &power) = 0;
    virtual void GetTokenStrings(LPTSTR lpszSouce, LPTSTR *lppszDest, LPCTSTR lpsczDelimit, int *lpnCount) = 0;
    virtual float ch2freq(unsigned char band, unsigned short arfcn, BOOL dw1up0) = 0;
    void  DisplayPVTCode(char);
    int  PrintTxPower(char, char);
    virtual int NsftMeasurePVT(char band) = 0;
    void DisplayTxPowerCode(char band);
    void DisplayCouplingTxPowerCode(char band);
    int PrintPVT(char band);
    virtual int NsftMeasurePhaseNFrequency(char band) = 0;
    void DisplayPFCode(char band);
    int PrintPFerror(char band);
    virtual int NsftMeasureRxLevel(char band, int) = 0;
    void DisplayRxlevelCode(char);
    int  PrintRxlevel(char);
    virtual void SetCellPower(char, int) = 0;
    virtual int NSFTSetup(char band, int channel) = 0;
    int PrintORFSMS(char band);
    void DisplayORFSSCode(char band);
    void DisplayORFSMCode(char band);
    int PrintSensitivity(char band);
    int PrintCouplingSensitivity(char band);
    void DisplaySensitivityCode(char band);
    void DisplayCouplingSensitivityCode(char band);
    virtual int TestSensitivity(unsigned char band) = 0;
    virtual int CouplingSensitivity(unsigned char band) = 0;
    virtual void NonsigSetup() = 0;
    virtual int TestModulation(unsigned char) = 0;
    virtual int TestSwSpec(unsigned char) = 0;
};

#endif // !defined(AFX_RDA2GNSFT_H__B2870891_6688_4FA7_0002_02775AB0F159__INCLUDED_)
