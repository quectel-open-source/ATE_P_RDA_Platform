// AgilentTest.h : header file
//

#if !defined(AFX_ZHONGY4923TEST_H__B2870891_6619_4FA7_8888_02775AB0F159__INCLUDED_)
#define AFX_ZHONGY4923TEST_H__B2870891_6619_4FA7_8888_02775AB0F159__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "caliblink_export.h"

class CALIBLINK_API CZy4923Test
{
    // ZY4923 Test Function
public:
    CZy4923Test();
    void TestPCSInitZY4923(double,double);
    void  TestInitZY4923    (double, double);
    int  TestSetupZY4923   (unsigned char);
    int  TestRfItemZY4923  (void);
    int  TestMeasZY4923    (void);
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
    int  PrintPVT(int);
    int  PrintPFerror(void);
    int  PrintSensitivity(void);
    int TestRxLevelZY4923(void);
    int TestPowerDataZY4923(void);
    int TestMdandSwSpecDataZY4923(void);
    int TestRfPCSItemZY4923();
    void TestSetGsm850ILoss();
    void TestSetGsm900ILoss();
    void TestSetDcsILoss();
    void TestSetPcsILoss();
    void SetErrorBit(int);
};

#endif // !defined(AFX_ZHONGY4923TEST_H__B2870891_6619_4FA7_8888_02775AB0F159__INCLUDED_)
