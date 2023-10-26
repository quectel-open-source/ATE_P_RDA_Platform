// IQXStreamNSFT.h : header file

#if !defined(AFX_IQMStreamNSFT_H__B2870891_8668_4FA7_6699_02775AB0F188__INCLUDED_)
#define AFX_IQMStreamNSFT_H__B2870891_8668_4FA7_6699_02775AB0F188__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "caliblink_export.h"
#include "Rda2GNsft.h"

class CALIBLINK_API CIQMStreamNsft: public CRda2GNsft
{
public:
    CIQMStreamNsft();
	void NonsigTotalInitialize();
	void NonsigInitialize(char,int, int,char);
	//void WriteGpibCmd(const char *cmdbuff, ...);
	//void ReadGpibCmd();
	void SetRfPathLoss(char band){;}
	void SetRfPathLoss(char band,int arfcn);
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
    int NbiotMeasureTxACLR();

private:

	int CommandCompleted(DWORD waitTime);
};

#endif // !defined(AFX_IQXStreamNSFT_H__B2870891_8888_4FA7_9355_02775AB0F159__INCLUDED_)