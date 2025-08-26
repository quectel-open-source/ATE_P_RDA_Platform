// Cmw500Test.h : header file
//

#if !defined(AFX_CMW500TEST_H__B2870891_8888_4FA7_6653_02775AB0F159__INCLUDED_)
#define AFX_CMW500TEST_H__B2870891_8888_4FA7_6653_02775AB0F159__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "caliblink_export.h"

class CALIBLINK_API CCmw500Test
{
public:
    CCmw500Test();
    // Cmw500200 Test Function
    int   TestInitCmw500  (double, double);
    int   TestSetupCmw500 (unsigned char);
    int   TestRfItemCmw500();
    void  DisplaySensitivitycode();
    void  DisplayRxlevelcode();
    void  DisplayPVTCode();
    void  DisplayORFSMCode();
    void  DisplayORFSSCode();
    void  DisplaySensitivityCode();
    int   TestMeasCmw500  (unsigned char, unsigned int);
    int   TestDisConn();
    void DisplayRxlevelCode();
    int  PrintRxlevel(void);
    int  PrintTxPower(void);
    int  PrintPVT(void);
    int  PrintPFerror(void);
    int  PrintORFSMS(void);
    int  PrintSensitivity(void);
    int  TestRxLandRxQCmw500(void);
    int  TestPowPvtandPFERCmw500(void);
    int  TestSwSpecCmw500(void);
    int  TestModulationCmw500(void);
    int  TestSensiCmw500(void);
    void  SetErrorBit(int);
    int  TestpcsRfItemCmw500();
    int  TestPCSInitCmw500(double,double);
    void GetTokenStrings(LPTSTR lpszSouce, LPTSTR *lppszDest, LPCTSTR lpsczDelimit, int *lpnCount);
public:
};

#endif // !defined(AFX_CMW500TEST_H__B2870891_8888_4FA7_6653_02775AB0F159__INCLUDED_)
