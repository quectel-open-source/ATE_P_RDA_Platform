// AgilentCalib.h : header file
//

#if !defined(AFX_ZHONGYOU4923CALIB_H__B2870891_6238_4FA7_6688_02775AB0F159__INCLUDED_)
#define AFX_ZHONGYOU4923CALIB_H__B2870891_6238_4FA7_6688_02775AB0F159__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "caliblink_export.h"

class CALIBLINK_API CZy4923Calib
{
    // ZY4923 Calibration Fucntions
public:
    CZy4923Calib();
    BOOL jade_adjust_crystal(long);
    void CalibInitZY4923    (double, double ,double , double );
    int CalibCrystalZY4923 (int);
    int CalibAfcGainZY4923 (unsigned char);
    int CalibILossZY4923   (unsigned char, unsigned short, unsigned char);
    int CalibPaProZY4923   (unsigned char, unsigned short);

    int confirmPaProZY4923 (int, float*);
    int CalibPaOffsetZY4923(unsigned char);
    int CalibChangeDACAfcGainZY4923(unsigned char);
    float  CalibTxLossZY4923(unsigned char, short, float);
    float  CalibRxILossZY4923(unsigned char, unsigned short, float, float);
    int InitPhone();
    int CalibChangeDACAfcFreqZY4923(unsigned char band);
    void CalibSetGsm850ILoss();
    void CalibSetGsm900ILoss();
    void CalibSetDcsILoss();
    void CalibSetPcsILoss();
    int CheckArfcnIlossSpan(char Iloss[], char);
    void removemaxandmin(float* m_power);
};

#endif // !defined(AFX_ZHONGYOU4923CALIB_H__B2870891_6238_4FA7_6688_02775AB0F159__INCLUDED_)
