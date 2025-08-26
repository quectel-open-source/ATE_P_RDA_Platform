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
#endif // !defined(AFX_TYPEDEF_H__B2870891_8800_9999_9338_02775AB0F888__INCLUDED_)
