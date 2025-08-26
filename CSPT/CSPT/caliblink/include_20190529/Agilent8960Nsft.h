// AgilentTest.h : header file
//

#if !defined(AFX_AGILENT8960NSFT_H__B2870891_8866_4FA7_8668_02775AB0F159__INCLUDED_)
#define AFX_AGILENT8960NSFT_H__B2870891_8866_4FA7_8668_02775AB0F159__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "caliblink_export.h"
#include "Rda2GNsft.h"

class CALIBLINK_API CAgilent8960Nsft: public CRda2GNsft
{
    // 8960 Test Function
public:

    CAgilent8960Nsft();
    void NonsigTotalInitialize();
    void SetRfPathLoss(char);
    void WriteGpibCmd(const char *cmdbuff, ...);
    void ReadGpibCmd();
    void SetCellPower(char band, int power);
    void NonsigSetup();
    void NonsigInitialize(char,int, int,char);
    int TestSensitivity(unsigned char band);
    int CouplingSensitivity(unsigned char band);
    int TestModulation(unsigned char);
    int TestSwSpec(unsigned char);
    int TestDisConn();
    int NsftMeasurePVT(char band);
    int NsftMeasureTxPower(char band, int pcl, float& power);
    int NsftMeasurePhaseNFrequency(char band);
    int pcl2dbm(char , char);
    void SetNsftMeasWin();
    void GetTokenStrings(LPTSTR lpszSouce, LPTSTR *lppszDest, LPCTSTR lpsczDelimit, int *lpnCount);
    float ch2freq(unsigned char, unsigned short, BOOL);
    int NsftMeasureRxLevel(char, int);
    int NSFTSetup(char, int);
    void NSFTSetupCellPower(char band,int power);

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
    int NbiotMeasureTxACLR(struct NB_NS_TEST_ACLR * m_nb_aclr) {
        return 0;
    }
};

#endif // !defined(AFX_AGILENT8960NSFT_H__B2870891_8866_4FA7_8668_02775AB0F159__INCLUDED_)
