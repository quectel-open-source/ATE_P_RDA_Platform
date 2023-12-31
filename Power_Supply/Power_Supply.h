#pragma once
#include "ni488.h"
#include "visa.h"
#include "visatype.h"



//通道号
#define TWO_CH				0
#define ONE_CH				1


//电源型号
//#define KEITHLEY			0
//#define AG_66				1
//#define AG_E36				2
//#define IT6100B				3

#define KEITHLEY			0
#define AG_66				1
#define AG_E36XX			2
#define IT6100B				3
#define AG_E3610X			4
#define KS_PMX				5
#define GW_PFR_PSW			6
#define DH_17XX				7


// #ifdef DLL_IMPLEMENT
// #define DLL_IMP _declspec(dllexport)
// #else
// #define DLL_IMP _declspec(dllimport)
// #endif

//
class AFX_EXT_CLASS CPower_Supply
{
public:
	CPower_Supply(void);
	~CPower_Supply(void);
	CStringW m_csError_Info;
	CStringW m_csIDN;
	int INIT_PS(void);
	void Release_PS(void);
	int m_iGPIB_Numb;
	int m_iGPIB_Addr;
	int m_iCtrl_Type_GPIB_Or_LAN;		//程控方式：GPIB卡、LAN网线
	CStringW m_csIP_Instru;				//LAN网线程控IP
	unsigned long int m_ul_PS_Handle;
	ViSession m_vise_DefaultRM;
	ViStatus m_vist_Status;
	int Write(const wchar_t * wcpSend_Data);
	int Read(wchar_t * wcpRead_Data);
	void MultiByte_To_WideChar(const char * cp_Char_8, wchar_t * wcp_WCHAR_16, int * ip_Len_16);
	bool WideChar_To_MultiByte(const wchar_t * wcp_WCHAR_16, char * cp_Char_8, int * ip_Len_8);
	int Query(const wchar_t * wcpSend_Data, wchar_t * wcpRead_Data);
	int m_iPS_Type;
	int m_iPS_Model;
	int INIT_PS_KEITHLEY(void);
	int INIT_PS_Agilent(void);
	double m_d_Init_Volt;
	double m_d_Init_Curr;
	void Set_Volt(int iCH, double dVolt);
	void Set_Curr(int iCH, double dCurr);
	void Set_Test_Point(int iPoint);
	void Power_On(int iCH);
	void Power_Off(int iCH);
	bool Meas_Volt(int iCH, double * dpVolt);
	bool Meas_Curr(int iCH, double * dpCurr);
	bool Meas_Curr_V1(int iCH, double * dpCurr,UINT iCount=1,UINT iTimeGap=10,UINT iType = 0);//0:Average,1:Min,2:Max
	void Close_VISA(void);
	bool m_bCtrl_PS;
	int INIT_PS_IT6100B(void);
	void POWER_ON_V1(int i_CH);
	void POWER_OFF_V1(int i_CH);
	bool CHECK_PS_SYSTEM_ERROR();
	void FREE_ALL();
	void Close_NI_Device();
	void INIT_PS_KS_PMX();
	void INIT_PS_DH_17XX();
	void INIT_PS_GW_PFR_PSW();

};
