// CmuTest.h : header file
//

#if !defined(AFX_CMUTEST_H__B2870891_8888_4FA7_6666_02775AB0F159__INCLUDED_)
#define AFX_CMUTEST_H__B2870891_8888_4FA7_6666_02775AB0F159__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "caliblink_export.h"

class CALIBLINK_API CCmuTest
{
public:
    CCmuTest();
    // CMU200 Test Function
    int   TestInitCmu  (double, double);
    int   TestSetupCmu (unsigned char);
    int   TestRfItemCmu();

    void  DisplaySensitivitycode();
    void  DisplayRxlevelcode();
    void  DisplayPVTCode();
    void  DisplayORFSMCode();
    void  DisplayORFSSCode();
    void  DisplaySensitivityCode();
    int   TestMeasCmu  (unsigned char, unsigned int);
    int   TestDisConn();
    void DisplayRxlevelCode();
    int  PrintRxlevel(void);
    int  PrintTxPower(void);
    int  PrintPVT(void);
    int  PrintPFerror(void);
    int  PrintORFSMS(void);
    int  PrintSensitivity(void);
    int  TestRxLandRxQCMU(unsigned char);
    int  TestPowPvtandPFERCMU(unsigned char);
    int  TestSwSpecCMU(unsigned char);
    int  TestModulationCMU(unsigned char);
    int  TestSensiCMU(unsigned char);
    void  SetErrorBit(int);
    int  TestpcsRfItemCmu();
    int  TestPCSInitCmu(double,double);
public:
};

#endif // !defined(AFX_CMUTEST_H__B2870891_8888_4FA7_6666_02775AB0F159__INCLUDED_)
