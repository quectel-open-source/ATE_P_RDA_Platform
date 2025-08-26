// DTTest.h : header file
//

#if !defined(AFX_DTTEST_H__B2870891_6666_4FA7_8888_02775AB0F159__INCLUDED_)
#define AFX_DTTEST_H__B2870891_6666_4FA7_8888_02775AB0F159__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "caliblink_export.h"

class CALIBLINK_API CDTTest
{
    // Cpt3110 Test Function
public:
    CDTTest();
    void TestPCSInitCpt3110(double,double);
    void  TestInitCpt3110    (double, double);
    int  TestSetupCpt3110   (unsigned char);
    int  TestRfItemCpt3110  (void);
    int  TestMeasCpt3110    (void);
    void  DisplayRxlevelCode();
    void  DisplayTxPowerCode();
    void  DisplayPFCode();
    void  DisplayPVTCode();
    void  DisplayORFSMSCode();
    void  DisplaySensitivityCode();
    void  PrintTestResult(void);
    int  PrintORFSMS(int, int);
    int   TestDisConn(void);
    int  PrintRxlevel(void);
    int  PrintTxPower(void);
    int  PrintPVT(void);
    int  PrintPFerror(void);
    int  PrintSensitivity(void);
    int TestRxLevelCpt3110(void);
    int TestPowerDataCpt3110(void);
    int TestMdandSwSpecDataCpt3110(void);
    int TestRfPCSItemCpt3110();
    int  PrintRxlevelCheck(void);
    int  PrintTxPowerCheck(void);
    int  PrintPVTCheck(void);
    int  PrintPFerrorCheck(void);
    int  PrintSensitivityCheck(void);
    int  PrintORFSMSCheck(int, int);

    void SetErrorBit(int);
};

#endif // !defined(AFX_AGILENTTEST_H__B2870891_6666_4FA7_8888_02775AB0F159__INCLUDED_)
