// AgilentTest.h : header file
//

#if !defined(AFX_AGILENTTEST_H__B2870891_6666_4FA7_8888_02775AB0F159__INCLUDED_)
#define AFX_AGILENTTEST_H__B2870891_6666_4FA7_8888_02775AB0F159__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "caliblink_export.h"

class CALIBLINK_API CAgilentTest
{
    // 8960 Test Function
public:
    CAgilentTest();
    void TestPCSInit8960(double,double);
    void  TestInit8960    (double, double);
    int  TestSetup8960   (unsigned char);
    int  TestRfItem8960  (void);
    int  TestMeas8960    (void);
    void  DisplayRxlevelCode();
    void  DisplayTxPowerCode();
    void  DisplayPFCode();
    void  DisplayPVTCode();
    void  DisplayORFSMSCode();
    void  DisplaySensitivityCode();
    void  PrintTestResult(void);
    int  PrintORFSMS(void);
    int   TestDisConn(void);
    int  PrintRxlevel(void);
    int  PrintTxPower(void);
    int  PrintPVT(void);
    int  PrintPFerror(void);
    int  PrintSensitivity(void);
    int TestRxLevel8960(void);
    int TestPowerData8960(void);
    int TestMdandSwSpecData8960(void);
    int TestRfPCSItem8960();
    void TestSetGsm850ILoss();
    void TestSetGsm900ILoss();
    void TestSetDcsILoss();
    void TestSetPcsILoss();
    void SetErrorBit(int);
};

#endif // !defined(AFX_AGILENTTEST_H__B2870891_6666_4FA7_8888_02775AB0F159__INCLUDED_)
