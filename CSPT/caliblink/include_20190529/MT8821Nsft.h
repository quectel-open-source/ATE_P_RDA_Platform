// IQXStreamNSFT.h : header file

#if !defined(AFX_MT8821NSFT_H__B2870891_8668_4FA7_6699_02775AB0F188__INCLUDED_)
#define AFX_MT8821NSFT_H__B2870891_8668_4FA7_6699_02775AB0F188__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "caliblink_export.h"
#include "Rda2GNsft.h"

class CALIBLINK_API CMT8821Nsft: public CRda2GNsft
{
public:
    CMT8821Nsft();

    void NonsigTotalInitialize() {
        ;
    }
    void NonsigInitialize(char,int, int,char) {
        ;
    }
    void SetRfPathLoss(char band) {
        ;
    }
    int pcl2dbm(char band, char pcl) {
        return 0;
    }
    void SetNsftMeasWin() {
        ;
    }
    int NsftMeasureTxPower(char band, int pcl, float& power) {
        return 0;
    }
    float ch2freq(unsigned char band, unsigned short arfcn, BOOL dw1up0) {
        return 0;
    }
    int NsftMeasurePVT(char band) {
        return 0;
    }
    int NsftMeasurePhaseNFrequency(char band) {
        return 0;
    }
    int NsftMeasureRxLevel(char band, int) {
        return 0;
    }
    void SetCellPower(char, int) {
        ;
    }
    void GetTokenStrings(LPTSTR lpszSouce, LPTSTR *lppszDest, LPCTSTR lpsczDelimit, int *lpnCount) {
        ;
    }
    int NSFTSetup(char, int) {
        return 0;
    }
    int TestSensitivity(unsigned char band) {
        return 0;
    }
    int CouplingSensitivity(unsigned char band) {
        return 0;
    }
    void NonsigSetup() {
        ;
    }
    int TestModulation(unsigned char) {
        return 0;
    }
    int TestSwSpec(unsigned char) {
        return 0;
    }

    void WriteGpibCmd(const char *cmdbuff, ...);
    void ReadGpibCmd();

    //NBIOT
    void NbiotNstInit();
    int NbiotNstCellSetup(int band,int arfcn,float rxpower);
    int NbiotNstMeasSetup(int band,int arfcn,float txpower);
    int NbiotMeasureTxPower(float *m_evm,float *m_txpower,float *m_freqerr);
    int NbiotChan2Freq(int band,int arfcn,float *DlFreq,float *UlFreq,int UL_DL);
    int NbiotSetiLoss(int band,unsigned short arfcn,int DL_UL);
    int NbiotMeasureTxOBW(float* m_ACLR,float* m_OBW);
    int NbiotMeasureTxSEM();
    int NbiotMeasureTxACLR(struct NB_NS_TEST_ACLR * m_nb_aclr);

private:

};

#endif // !defined(AFX_MT8821NSFT_H__B2870891_8888_4FA7_9355_02775AB0F159__INCLUDED_)
