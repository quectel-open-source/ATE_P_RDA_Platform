// AgilentTest.h : header file
//

#if !defined(AFX_AGILENTE6607ANSFT_H__B2870891_6666_4FA7_1256_02775AB0F159__INCLUDED_)
#define AFX_AGILENTE6607ANSFT_H__B2870891_6666_4FA7_1256_02775AB0F159__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "caliblink_export.h"
#include "Rda2GNsft.h"

class CALIBLINK_API CAgilentE6607ANsft: public CRda2GNsft
{
public:
    CAgilentE6607ANsft();
    void NonsigTotalInitialize();
    void NonsigInitialize(char,int, int,char);
    void WriteGpibCmd(const char *cmdbuff, ...);
    void ReadGpibCmd();
    void SetRfPathLoss(char band);
    int pcl2dbm(char band, char pcl);
    void SetNsftMeasWin();
    int NsftMeasureTxPower(char band, int pcl, float& power);
    void GetTokenStrings(LPTSTR lpszSouce, LPTSTR *lppszDest, LPCTSTR lpsczDelimit, int *lpnCount);
    float ch2freq(unsigned char band, unsigned short arfcn, BOOL dw1up0);
    int NsftMeasurePVT(char band);
    int NsftMeasurePhaseNFrequency(char band);
    int NsftMeasureRxLevel(char band, int);
    void SetCellPower(char, int);
    int NSFTSetup(char band, int channel);
    int TestSensitivity(unsigned char band);
    int CouplingSensitivity(unsigned char band);
    void NonsigSetup();
    int TestModulation(unsigned char);
    int TestSwSpec(unsigned char);

    //nbiot
    virtual void NbiotNstInit()  {
        ;
    }
    virtual int NbiotNstMeasSetup(int,int,float) {
        return 0;
    }
    virtual int NbiotNstCellSetup(int,int,float) {
        return 0;
    }
    virtual int NbiotMeasureTxPower(float*,float*,float*) {
        return 0;
    }
    int NbiotMeasureTxOBW(float*,float*) {
        return 0;
    }
    int NbiotMeasureTxSEM() {
        return 0;
    }
    int NbiotMeasureTxACLR() {
        return 0;
    }


public:
};

#endif // !defined(AFX_AGILENTE6607ANSFT_H__B2870891_6666_4FA7_1256_02775AB0F159__INCLUDED_)
