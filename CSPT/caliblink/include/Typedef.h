#if !defined(AFX_TYPEDEF_H__B2870891_8800_9999_9338_02775AB0F888__INCLUDED_)
#define AFX_TYPEDEF_H__B2870891_8800_9999_9338_02775AB0F888__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct  {
    float m_fcalibvoltagevalue;
    float m_fchargevoltagevalue;
    float m_fchargeoffsetvalue;
    float m_fshutoffvoltagevalue;
    float m_fshutoffoffsetvalue;
} calib_voltage;
typedef struct {
    float m_fGsmIloss;
    float m_fEGsmIloss;
    float m_fDcsIloss;
    float m_fPcsIloss;
} Insertion_Loss;

typedef struct {
    int m_iGsmChannel;
    int m_iEGsmChannel;
    int m_iDcsChannel;
    int m_iPcsChannel;
} Channel_select;
typedef struct {
    int m_iGsmBand;
    int m_iEGsmBand;
    int m_iDcsBand;
    int m_iPcsBand;
    int m_iGPSTest;
} Band_select;
typedef struct {
    int m_iGsmCrystalPcl;
    int m_iGsmAfcPcl;
    int m_iEGsmAfcPcl;
    int m_iDcsAfcPcl;
    int m_iPcsAfcPcl;
} Calib_PclValue;
typedef struct {
    int m_iCouplingPcl;
    int m_iCouplingRange;
} Coupling_Select;
typedef struct {
    Coupling_Select CouplingValue[4];
} Coupling_PclValue;

typedef struct {
    int m_iUseCharge;
    int m_iCalibBattery;
    int m_iCalibCrystal;
    int m_iCalibAFC;
    int m_iCalibILoss;
    int m_iCalibPAProfile;
    int m_iCalibPAOffset;
    int m_iSetNewPcl;
    int m_iFastCalib;
    int m_iCalibPAProfileDac;
    int m_iCalibTiming;
    int m_iCalibRamp;
    int m_iCalibSaveCfp;
} Calib_Item;
typedef struct {
    int m_iGsmPclLevelValue[15];
} Calib_GsmPclLevelValue;
typedef struct {
    int m_iDcsPclLevelValue[16];
} Calib_DcsPclLevelValue;
typedef struct {
    int m_iRampValue[16];
} Calib_RampValue;
typedef struct {
    int m_iXCVTiming[20];
} Calib_XCVTiming;
typedef struct {
    int m_iPaDac[16];
} Calib_PaProfileDac;
typedef struct {
    int m_iPATiming[15];
} Calib_PATiming;
typedef struct {
    int m_iSWTiming[15];
} Calib_SWTiming;
typedef struct {
    int m_iGsmFrequencyError;
    int m_iEGsmFrequencyError;
    int m_iDcsFrequencyError;
    int m_iPcsFrequencyError;
    int m_iPhaseError;
    int m_iRMSError;
} Test_PandFError;
typedef struct {
    int m_iGsmRxLevel;
    int m_iEGsmRxLevel;
    int m_iDcsRxLevel;
    int m_iPcsRxLevel;
    int m_iRxLevelLimit;
} Test_RxLevel;
typedef struct {
    int m_iUseCharge;
    int m_iTestPowerflag;
    int m_iTestPandFErrorflag;
    int m_iTestPVTflag;
    int m_irxlevelflag;
    int m_iTestSensitivity;
    int m_iTestMSpecture;
    int m_iTestSSpecture;
} Test_Item;

typedef struct {
    int m_iCouplingPower;
    int m_iCouplingBer;
} Coupling_Item;

typedef struct {
    float m_fGsmSensitivity;
    float m_fEGsmSensitivity;
    float m_fDcsSensitivity;
    float m_fPcsSensitivity;
} Coupling_Ber;

typedef struct {
    float m_fGsmSensitivity;
    float m_fEGsmSensitivity;
    float m_fDcsSensitivity;
    float m_fPcsSensitivity;
} Test_Sensitivity;
typedef struct {
    float m_iPerPclMaxValue;
    float m_iPerPclMinValue;
} MaxandMin_pclvalue;
typedef struct {
    MaxandMin_pclvalue Gsm_pclvalue[15];
} Gsm_AllPclLimitvalue;
typedef struct {
    MaxandMin_pclvalue Dcs_pclvalue[16];
} Dcs_AllPclLimitvalue;
typedef struct {

    float m_iSSpecturevalue;
    int m_iSSpectureflag;
} SwitchSpecture_Select;
typedef struct {
    SwitchSpecture_Select SSpecture[8];
} AllSwitchSpecture;
typedef struct {
    float m_iMSpecturevalue;
    int m_iMSpectureflag;

} ModulationSpecture_Select;
typedef struct {
    ModulationSpecture_Select MSpecture[22];
} AllModulationSpecture;
typedef struct {
//  float m_TxPower[3];
    float m_TxLoss[3];
    float m_TxFrequency[3];
//  float m_RxPower[3];
    float m_RxLoss[3];
    float m_RxFrequency[3];
} ILossSetup;
typedef struct {
    Calib_RampValue m_RampCurve[4];
} Calib_4RampCurve;
typedef struct {
    Calib_RampValue m_RampCurve[24];
} Calib_24RampCurve;
typedef struct DPOINT {
    double   dx;
    double   dy;
} DPOINT;

typedef struct PA_POINT {
    int      x;
    int      y;
    int      IsCtrl;
} PA_POINT;

typedef struct PA_INSERT {
    int      nVal;
    int      IsCtrl;
} PA_INSERT;

typedef struct {
    int m_iCalibCrystalFlag;
    int m_iCalibAPCFastOffsetFlag;
    int m_iCalibAGCFlag;
    int m_iCalibAPCOffsetFlag;
    int m_iCalibAPC1dBFlag;
} NB_Calib_Item;

typedef struct {
    float m_fCellPower;
    float m_fLossRang;
    float m_fArfcnLimit;
} NB_Calib_AgcPara;

typedef struct {
    int m_iBand1;
    int m_iBand3;
    int m_iBand5;
    int m_iBand8;
    int m_iBand20;
    int m_iBand28;
	int m_iBand2;
	int m_iBand4;
	int m_iBand12;
	int m_iBand13;
	int m_iBand17;
	int m_iBand18;
	int m_iBand19;
	int m_iBand25;
	int m_iBand26;
	int m_iBand66;
	int m_iBand70;
	int m_iBand71;
} NB_Calib_BandSelect;

typedef struct {
    float m_iBand1iloss[3];
    float m_iBand3iloss[3];
    float m_iBand5iloss[3];
    float m_iBand8iloss[3];
    float m_iBand20iloss[3];
    float m_iBand28iloss[3];
	float m_iBand2iloss[3];
	float m_iBand4iloss[3];
	float m_iBand12iloss[3];
	float m_iBand13iloss[3];
	float m_iBand17iloss[3];
	float m_iBand18iloss[3];
	float m_iBand19iloss[3];
	float m_iBand25iloss[3];
	float m_iBand26iloss[3];
	float m_iBand66iloss[3];
	float m_iBand70iloss[3];
	float m_iBand71iloss[3];
} NB_Calib_iloss;

typedef struct {
    int m_icrystalband;
    int m_icrystalchannel;
    int m_icrystaltxpower;
} NB_Calib_CrystalPara;

typedef struct {
    float m_fTxPowSetting;
    float m_fTxOffset;
} NB_Calib_ApcPara;

typedef struct {
    int m_iMaxPowerFlag;
    int m_iMinPowerFlag;
    int m_iFreqErrFlag;
    int m_iEvmFlag;
    int m_iAclrFlag;
    int m_iSemFlag;
    int m_iOBWFlag;
    int m_iSensitivityFlag;
} NB_Test_Item;

typedef struct {
    int m_iBand1Channel[3];
    int m_iBand3Channel[3];
    int m_iBand5Channel[3];
    int m_iBand8Channel[3];
    int m_iBand20Channel[3];
    int m_iBand28Channel[3];
	int m_iBand2Channel[3];
	int m_iBand4Channel[3];
	int m_iBand12Channel[3];
	int m_iBand13Channel[3];
	int m_iBand17Channel[3];
	int m_iBand18Channel[3];
	int m_iBand19Channel[3];
	int m_iBand25Channel[3];
	int m_iBand26Channel[3];
	int m_iBand66Channel[3];
	int m_iBand70Channel[3];
	int m_iBand71Channel[3];
} NB_Test_Channel;

typedef struct {
    int m_iBand1SeleChannel[3];
    int m_iBand3SeleChannel[3];
    int m_iBand5SeleChannel[3];
    int m_iBand8SeleChannel[3];
    int m_iBand20SeleChannel[3];
    int m_iBand28SeleChannel[3];
	int m_iBand2SeleChannel[3];
	int m_iBand4SeleChannel[3];
	int m_iBand12SeleChannel[3];
	int m_iBand13SeleChannel[3];
	int m_iBand17SeleChannel[3];
	int m_iBand18SeleChannel[3];
	int m_iBand19SeleChannel[3];
	int m_iBand25SeleChannel[3];
	int m_iBand26SeleChannel[3];
	int m_iBand66SeleChannel[3];
	int m_iBand70SeleChannel[3];
	int m_iBand71SeleChannel[3];
} NB_Test_SeleChannel;

typedef struct {
    int m_iBand1SensPow;
    int m_iBand3SensPow;
    int m_iBand5SensPow;
    int m_iBand8SensPow;
    int m_iBand20SensPow;
    int m_iBand28SensPow;
	int m_iBand2SensPow;
	int m_iBand4SensPow;
	int m_iBand12SensPow;
	int m_iBand13SensPow;
	int m_iBand17SensPow;
	int m_iBand18SensPow;
	int m_iBand19SensPow;
	int m_iBand25SensPow;
	int m_iBand26SensPow;
	int m_iBand66SensPow;
	int m_iBand70SensPow;
	int m_iBand71SensPow;
} NB_Test_SensPow;

typedef struct {
    int m_iBand1CouplingPow;
    int m_iBand3CouplingPow;
    int m_iBand5CouplingPow;
    int m_iBand8CouplingPow;
    int m_iBand20CouplingPow;
    int m_iBand28CouplingPow;
	int m_iBand2CouplingPow;
	int m_iBand4CouplingPow;
	int m_iBand12CouplingPow;
	int m_iBand13CouplingPow;
	int m_iBand17CouplingPow;
	int m_iBand18CouplingPow;
	int m_iBand19CouplingPow;
	int m_iBand25CouplingPow;
	int m_iBand26CouplingPow;
	int m_iBand66CouplingPow;
	int m_iBand70CouplingPow;
	int m_iBand71CouplingPow;
	int m_iBand1RxCouplingPow;
	int m_iBand3RxCouplingPow;
	int m_iBand5RxCouplingPow;
	int m_iBand8RxCouplingPow;
	int m_iBand20RxCouplingPow;
	int m_iBand28RxCouplingPow;
	int m_iBand2RxCouplingPow;
	int m_iBand4RxCouplingPow;
	int m_iBand12RxCouplingPow;
	int m_iBand13RxCouplingPow;
	int m_iBand17RxCouplingPow;
	int m_iBand18RxCouplingPow;
	int m_iBand19RxCouplingPow;
	int m_iBand25RxCouplingPow;
	int m_iBand26RxCouplingPow;
	int m_iBand66RxCouplingPow;
	int m_iBand70RxCouplingPow;
	int m_iBand71RxCouplingPow;
	int m_iCouplingPowerLimit;
	int m_iCouplingRxPowerLimit;
} NB_Test_CouplingPow;

struct GSM_NS_TEST_RST  
{
	float Tx_Power;
	float FreqErr;
	float PhaseErr;
	float PhaseRMSErr;
	float Ber;
	int   PVT;
	int   ORFSM;
	int   ORFSS;
	int   RxLevel;
};

struct NB_NS_TEST_RST  
{  
	float Max_Power;
	float Min_Power;
	float ACLR;
	float OBW;
	float EVM;
	float FreqErr;
	float BER;
	int SpecEmMask;
};

struct NB_NS_TEST_LIMIT  
{  
	float Max_Power_Limit[2];
	float Min_Power_Limit[2];
	float ACLR_Limit[4];
	float OBW_Limit;
	float EVM_Limit;
	float FreqErr_Limit;
	float SEM_Limit;
	float BER_Limit;
};

struct NB_NS_TEST_ACLR 
{  
	float URATneg;
    float GSMneg;
    float GSMpos;
    float URATpos;
};

struct GOLDEN_CABLE_LOSS
{
	float GSM850[3];
	float GSM900[3];
	float GSM1800[3];
	float GSM1900[3];
	float BAND1[3];
	float BAND3[3];
	float BAND5[3];
	float BAND8[3];
	float BAND20[3];
	float BAND28[3];
};

#endif // !defined(AFX_TYPEDEF_H__B2870891_8800_9999_9338_02775AB0F888__INCLUDED_)
