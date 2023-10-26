#include "StdAfx.h"
#include "Power_Supply.h"
#include "Global_Header.h"


//
CPower_Supply::CPower_Supply(void)
: m_csError_Info(_T(""))
, m_csIDN(_T(""))
, m_iGPIB_Numb(0)
, m_iGPIB_Addr(0)
, m_iCtrl_Type_GPIB_Or_LAN(0)
, m_ul_PS_Handle(0)
, m_iPS_Type(0)
, m_iPS_Model(0)
, m_d_Init_Volt(0)
, m_d_Init_Curr(0)
, m_bCtrl_PS(false)
, m_csIP_Instru(_T(""))
{
	m_ul_PS_Handle = NULL;
}

CPower_Supply::~CPower_Supply(void)
{
	FREE_ALL();
}
void CPower_Supply::Release_PS(void)
{
	//FREE_ALL();
}


int CPower_Supply::INIT_PS(void)
{
	wchar_t * wcpData = NULL;

	//
	try
	{
		//���
		this->m_csError_Info.Format(_T(""));
		this->m_csIDN.Format(_T(""));


		//���ͷŵ�Դ���
		//���ڡ�����ʽ�µ硱֮���������
		//NI������ibonl�����ͷž���������ŵ���Դ��������ȡ���֮ǰ����Ϊ��Դ�������µ硱�����ӳ�ʱ�䣬���е�ibwrt����ʵ���ϻ�������ibonl֮����ɡ������µ硱ָ��ᷢ��ʧ�ܡ�
		this->FREE_ALL();


		//------------------------------------- �򿪡������������ ------------------------------------- 
		if (this->m_iCtrl_Type_GPIB_Or_LAN == GPIB_NI)// NI GPIB ��
		{
			this->m_ul_PS_Handle = ibdev(this->m_iGPIB_Numb, this->m_iGPIB_Addr, 0, 13, 1, 0);
			//
			if (ibsta & ERR)
			{
				this->m_csError_Info.Format(_T("Power Supply ibdev Fail!"));
				throw(0);
			}

			//
			ibclr(this->m_ul_PS_Handle);
		}
		else if ((this->m_iCtrl_Type_GPIB_Or_LAN == GPIB_VISA) || (this->m_iCtrl_Type_GPIB_Or_LAN == GPIB_VISA_TCPIP))// LAN ����ͨ��
		{
			char crCmd[260];
			int iTemp;
			CString csData;

			//Connect IQxstream ��NI Visa����, �� viOpen & viOpenRM
			this->m_vist_Status = viOpenDefaultRM(&this->m_vise_DefaultRM);
			//�жϷ���ֵ
			if (this->m_vist_Status != VI_SUCCESS)
			{
				this->m_csError_Info.Format(_T("FAIL, INIT_PS, viOpenDefaultRM fail!"));
				throw(0);
			}

			//���visaָ��
			csData.Format(_T("TCPIP::%s::inst0::INSTR"), this->m_csIP_Instru);

			//���
			memset(crCmd, 0, sizeof(crCmd));

			//ת�����ַ��ִ�
			this->WideChar_To_MultiByte(csData, crCmd, &iTemp);

			//open��������һ�γ��ԣ�
			this->m_vist_Status = viOpen(this->m_vise_DefaultRM, crCmd, VI_NULL, VI_NULL, &this->m_ul_PS_Handle);
			//�ж�open�����ķ���ֵ
			if (this->m_vist_Status != VI_SUCCESS)
			{
				int a = 0;
				int irPS_Port[3] = { 1790, 5025, 2268 };//��ͬ��Դ�Ĺ̶� LAN Port

				//������������ LAN Port
				for (a = 0; a < 3; a++)
				{
					//���visaָ��
					csData.Format(_T("TCPIP::%s::%d::SOCKET"), this->m_csIP_Instru, irPS_Port[a]);

					//���
					memset(crCmd, 0, sizeof(crCmd));

					//ת�����ַ��ִ�
					this->WideChar_To_MultiByte(csData, crCmd, &iTemp);

					//open����
					this->m_vist_Status = viOpen(this->m_vise_DefaultRM, crCmd, VI_NULL, VI_NULL, &this->m_ul_PS_Handle);

					if (this->m_vist_Status != VI_SUCCESS)
					{
						//����ʧ�ܣ�������һ��ָ��
					}
					else
					{
						//open success
						break;
					}
				}//for( a = 0; a < 3; a++
				//�ж�ѭ�����Խ��
				if (a >= 3)
				{
					this->m_csError_Info.Format(_T("FAIL, INIT_PS, viOpen fail!"));
					//fail
					throw(0);
				}
			}//if( this->m_vist_Status != VI_SUCCESS


			//����VISA ����: VI_ATTR_TERMCHAR_EN, VI_FALSE, VI_ATTR_SUPPRESS_END_EN, VI_FALSE
			viSetAttribute(this->m_ul_PS_Handle, VI_ATTR_TERMCHAR_EN, VI_FALSE);
			viSetAttribute(this->m_ul_PS_Handle, VI_ATTR_SUPPRESS_END_EN, VI_FALSE);
			viSetAttribute(this->m_ul_PS_Handle, VI_ATTR_TMO_VALUE, ViAttrState(10000));
		}
		else
		{
			this->m_csError_Info.Format(_T("FAIL, INIT_PS, Control Type Error!"));
			//fail
			throw(0);
		}
		//-------------------------------------


		//------------------------------------- ʶ���Դ�ͺ� ------------------------------------- 
		//�����ڴ�
		wcpData = (wchar_t *)calloc(128, sizeof(wchar_t));

		//��ѯ��Դ�ͺ�
		if (this->Query(_T("*IDN?\n"), wcpData) != RTN_SUCCESS)
		{
			this->m_csError_Info.Format(_T("FAIL, INIT_PS, Query IDN!"));
			throw(0);
		}

		//��������
		this->m_csIDN.Format(_T("%s"), wcpData);

		//�жϵ�Դ�ͺ�
		if (wcsstr(wcpData, _T("KEITHLEY")) != NULL)
		{
			this->m_iPS_Model = KEITHLEY;

			if (wcsstr(wcpData, _T("2306")) != NULL)
			{
				this->m_iPS_Type = TWO_CH;
			}
			else
			{
				this->m_iPS_Type = ONE_CH;
			}
		}
		else if (wcsstr(wcpData, _T("E3610")) != NULL)//E36100ϵ��
		{
			this->m_iPS_Model = AG_E3610X;

			this->m_iPS_Type = ONE_CH;
		}
		else if (wcsstr(wcpData, _T("E36")) != NULL)//E3640ϵ��
		{
			this->m_iPS_Model = AG_E36XX;

			this->m_iPS_Type = ONE_CH;
		}
		else if ((wcsstr(wcpData, _T("KIKUSUI")) != NULL) && (wcsstr(wcpData, _T("PMX")) != NULL))
		{
			this->m_iPS_Model = KS_PMX;

			this->m_iPS_Type = ONE_CH;
		}
		else if ((wcsstr(wcpData, _T("BJDH")) != NULL) && (wcsstr(wcpData, _T("DH17")) != NULL))
		{
			this->m_iPS_Model = DH_17XX;

			this->m_iPS_Type = ONE_CH;
		}
		else if ((wcsstr(wcpData, _T("GW-INSTEK")) != NULL) && (wcsstr(wcpData, _T("PSW3")) != NULL))
		{
			//PSW30-36
			this->m_iPS_Model = GW_PFR_PSW;

			this->m_iPS_Type = ONE_CH;
		}
		else if ((wcsstr(wcpData, _T("GW-INSTEK")) != NULL) && (wcsstr(wcpData, _T("PFR-100L")) != NULL))
		{
			//PFR-100L
			this->m_iPS_Model = GW_PFR_PSW;

			this->m_iPS_Type = ONE_CH;
		}
		else if (wcsstr(wcpData, _T("IT61")) != NULL)
		{
			this->m_iPS_Model = IT6100B;

			this->m_iPS_Type = ONE_CH;
		}
		else
		{
			this->m_iPS_Model = AG_66;

			if ((wcsstr(wcpData, _T("66309")) != NULL) || (wcsstr(wcpData, _T("66319")) != NULL))
			{
				this->m_iPS_Type = TWO_CH;
			}
			else
			{
				this->m_iPS_Type = ONE_CH;
			}
		}



		//�ָ���������
		this->Query(_T("*CLS;*RST;*OPC?\n"), wcpData);
		//
		Sleep(500);



		//�ȹر�ȫ�����
		this->Power_Off(1);
		this->Power_Off(2);



		//------------------------------------- ��ʼ�����õ�Դ ------------------------------------- 
		switch (this->m_iPS_Model)
		{
		case KEITHLEY:
			this->INIT_PS_KEITHLEY();
			break;

		case AG_66:
			this->INIT_PS_Agilent();
			break;

		case AG_E36XX:
		case AG_E3610X:
			this->INIT_PS_Agilent();
			break;

		case KS_PMX:
			this->INIT_PS_KS_PMX();
			break;

		case DH_17XX:
			this->INIT_PS_DH_17XX();
			break;

		case GW_PFR_PSW:
			this->INIT_PS_GW_PFR_PSW();
			break;

		case IT6100B:
			this->INIT_PS_IT6100B();
			break;

		default:
			this->INIT_PS_Agilent();
			break;
		}//switch( this->m_iPS_Model
		//-------------------------------------


		//�ȹر�ȫ�����
		this->Power_Off(1);
		this->Power_Off(2);


		//��Դ��ʼ����Ϻ��ȡ��Դϵͳ����
		if (false == this->CHECK_PS_SYSTEM_ERROR())
		{
			throw(0);
		}

	}
	catch (...)
	{
		//�ͷ��ڴ�
		if (wcpData != NULL)
		{
			free(wcpData);
		}

		//fail
		return RTN_FAIL;
	}

	//�ͷ��ڴ�
	if (wcpData != NULL)
	{
		free(wcpData);
	}

	//pass
	return RTN_SUCCESS;
}

int CPower_Supply::Write(const wchar_t * wcpSend_Data)
{
	char * cpWrite_Buff = NULL;
	int iTemp, iWrite_Size;

	try
	{
		//�����������ݵĳ���
		iWrite_Size = wcslen(wcpSend_Data);
		//�����ڴ�
		cpWrite_Buff = (char *)calloc((iWrite_Size * 2), sizeof(char));
		//�������ݣ�˫char����תΪ��char����
		if(this->WideChar_To_MultiByte(wcpSend_Data, cpWrite_Buff, &iTemp) == false)
		{
			throw(0);
		}

		//------------------------------------- ��������
		if (this->m_iCtrl_Type_GPIB_Or_LAN == GPIB_NI)
		{
			if(ibwrt(this->m_ul_PS_Handle, cpWrite_Buff, strlen(cpWrite_Buff)) & ERR)   
			{
				ibclr(this->m_ul_PS_Handle);   
				this->m_csError_Info.Format(_T("Power Supply ibwrt Fail!"));
				throw(0);
			}
		}
		else if ((this->m_iCtrl_Type_GPIB_Or_LAN == GPIB_VISA) || (this->m_iCtrl_Type_GPIB_Or_LAN == GPIB_VISA_TCPIP))
		{
			this->m_vist_Status = viPrintf(this->m_ul_PS_Handle, (ViString)cpWrite_Buff);
			if(this->m_vist_Status != VI_SUCCESS)
			{
				this->m_csError_Info.Format(_T("Power Supply viPrintf Fail!"));
				throw(0);
			}
		}
		else
		{
			throw(0);
		}
	}
	catch(...)
	{
		//�ͷ��ڴ�
		if(cpWrite_Buff != NULL)
		{
			free(cpWrite_Buff);
			cpWrite_Buff = NULL;
		}
		return RTN_FAIL;
	}

	//�ͷ��ڴ�
	if(cpWrite_Buff != NULL)
	{
		free(cpWrite_Buff);
		cpWrite_Buff = NULL;
	}

	return RTN_SUCCESS;
}

int CPower_Supply::Read(wchar_t * wcpRead_Data)
{
	char * cpRead_Buff = NULL;
	int iRead_Size = 512;
	int iTemp;

	try
	{
		//�����ڴ�
		cpRead_Buff = (char *)calloc((iRead_Size + 8), sizeof(char));
		memset(cpRead_Buff, 0, (iRead_Size + 8));
		
		//------------------------------------- ������
		if (this->m_iCtrl_Type_GPIB_Or_LAN == GPIB_NI)
		{
			if(ibrd(this->m_ul_PS_Handle, cpRead_Buff, iRead_Size) & ERR)
			{
				ibclr(this->m_ul_PS_Handle);   
				this->m_csError_Info.Format(_T("Power Supply ibrd Fail!"));
				throw(0);
			}

			//NI��ʱ�������Զ���ӡ�\n���ַ�
			iTemp = strlen(cpRead_Buff) - 1;
			if (iTemp>=0)
			{
				if (*(cpRead_Buff + iTemp) == '\n')
				{
					*(cpRead_Buff + iTemp) = '\0';
				}
			}
		}
		else if ((this->m_iCtrl_Type_GPIB_Or_LAN == GPIB_VISA) || (this->m_iCtrl_Type_GPIB_Or_LAN == GPIB_VISA_TCPIP))
		{
			this->m_vist_Status = viRead(this->m_ul_PS_Handle, (ViPBuf)cpRead_Buff, (ViUInt32)iRead_Size, (ViPUInt32)(&iTemp));
			
			if(this->m_vist_Status != VI_SUCCESS)
			{
				this->m_csError_Info.Format(_T("Power Supply viRead Fail!"));
				throw(0);
			}
			cpRead_Buff[iTemp - 1] = '\0';
		}
		else
		{
			throw(0);
		}

		//���ڶ�����������Ҫת��Ϊwchar_t��˫�ַ��������ڽ�����ʾ
		this->MultiByte_To_WideChar(cpRead_Buff, wcpRead_Data, &iTemp);
	}
	catch(...)
	{
		//�ͷ��ڴ�
		if(cpRead_Buff != NULL)
		{
			free(cpRead_Buff);
			cpRead_Buff = NULL;
		}
		return RTN_FAIL;
	}

	//�ͷ��ڴ�
	if(cpRead_Buff != NULL)
	{
		free(cpRead_Buff);
		cpRead_Buff = NULL;
	}

	return RTN_SUCCESS;
}

bool CPower_Supply::WideChar_To_MultiByte(const wchar_t * wcp_WCHAR_16, char * cp_Char_8, int * ip_Len_8)
{
	int iSize = WideCharToMultiByte(CP_ACP, 0, wcp_WCHAR_16, -1, NULL, 0, NULL, NULL);

	if(!WideCharToMultiByte(CP_ACP, 0, wcp_WCHAR_16 ,-1, cp_Char_8, iSize, NULL, NULL))
	{
		return false;
	}

	*ip_Len_8 = iSize;

	return true;
}

void CPower_Supply::MultiByte_To_WideChar(const char * cp_Char_8, wchar_t * wcp_WCHAR_16, int * ip_Len_16)
{
	//utf8���룬char*  --->Unicode��wchar_t*
	int nLen = strlen(cp_Char_8) + 1;     
    int nwLen = MultiByteToWideChar(CP_ACP, 0, cp_Char_8, nLen, NULL, 0);

    MultiByteToWideChar(CP_ACP, 0, cp_Char_8, nLen, wcp_WCHAR_16, nwLen);//CP_UTF8(�������޷���ʾ)
  
    *ip_Len_16 = nwLen - 1;//ע�⣺nwLen������ȣ��ַ������ǰ�������ֹ����\0����

	*(wcp_WCHAR_16 + nwLen - 1) = '\0';
}

int CPower_Supply::Query(const wchar_t * wcpSend_Data, wchar_t * wcpRead_Data)
{
	if(this->Write(wcpSend_Data) == RTN_SUCCESS)
	{
		Sleep(200);

		return this->Read(wcpRead_Data);
	}
	else
	{
		return RTN_FAIL;
	}
}

int CPower_Supply::INIT_PS_KEITHLEY(void)
{
	this->Set_Volt(1, this->m_d_Init_Volt);

	this->Set_Curr(1, this->m_d_Init_Curr);
	
	this->Set_Test_Point(5);

	return RTN_SUCCESS;
}

int CPower_Supply::INIT_PS_Agilent(void)
{
	this->Set_Volt( 1, this->m_d_Init_Volt );

	this->Set_Curr( 1, this->m_d_Init_Curr );
	
	this->Set_Test_Point(500);

	//���Agilent 66309��66319��������˿ڵĶ�������
	if(this->m_iPS_Type == TWO_CH)
	{
		this->Write(_T("INST:COUP:OUTP:STAT NONE\n"));
	}

	//����
	return RTN_SUCCESS;
}

void CPower_Supply::Set_Volt(int iCH, double dVolt)
{
	CString csCmd;

	//
	switch (this->m_iPS_Type)
	{
	case TWO_CH:
	{
		if (iCH <= 2)
		{
			if (this->m_iPS_Model == KEITHLEY)
			{
				csCmd.Format(_T("SOUR%d:VOLT %.3f\n"), iCH, dVolt);
			}
			else if (this->m_iPS_Model == AG_66)
			{
				csCmd.Format(_T("SOUR:VOLT%d %.3f\n"), iCH, dVolt);
			}
			else
			{
				csCmd.Format(_T("SOUR:VOLT%d %.3f\n"), iCH, dVolt);
			}

			break;
		}
		else
		{
			return;
		}
	}
	//
	break;

	case ONE_CH:
	{
		if (iCH == 1)
		{
			switch (this->m_iPS_Model)
			{
			case KEITHLEY:
				csCmd.Format(_T("VOLT %.3f\n"), dVolt);
				break;
			case AG_66:
				csCmd.Format(_T("VOLT %.3f\n"), dVolt);
				break;
			case KS_PMX:
				csCmd.Format(_T("VOLTage %.3f\n"), dVolt);
				break;
			case DH_17XX:
				csCmd.Format(_T("VOLTage %.3f\n"), dVolt);
				break;
			case GW_PFR_PSW:
				csCmd.Format(_T("VOLTage %.3f\n"), dVolt);
				break;
			case IT6100B:
				csCmd.Format(_T("SOURce:VOLTage:LEVel %.3fV\n"), dVolt);//�����﷨��[SOURce:]VOLTage[:LEVel] <NRf>
				break;
			default:
				csCmd.Format(_T("VOLT %.3f\n"), dVolt);
				break;
			}

			//
			break;
		}
		else
		{
			return;
		}
	}
	//
	break;

	default:
		return;
	}//switch( this->m_iPS_Type


	//����ָ��
	this->Write(csCmd);
}

void CPower_Supply::Set_Curr(int iCH, double dCurr)
{
	CString csCmd;

	switch (this->m_iPS_Type)
	{
	case TWO_CH:
		if (iCH <= 2)
		{
			if (this->m_iPS_Model == KEITHLEY)
			{
				csCmd.Format(_T(":SOUR%d:CURR:LIM %.3f\n"), iCH, dCurr);
			}
			else if (this->m_iPS_Model == AG_66)
			{
				csCmd.Format(_T("SOUR:CURR%d %.3f\n"), iCH, dCurr);
			}
			else
			{
				csCmd.Format(_T("SOUR:CURR%d %.3f\n"), iCH, dCurr);
			}

			break;
		}
		else
		{
			return;
		}
	case ONE_CH:
		if (iCH == 1)
		{
			switch (this->m_iPS_Model)
			{
			case KEITHLEY:
				csCmd.Format(_T(":SOUR:CURR:LIM %.3f\n"), dCurr);
				break;
			case AG_66:
				csCmd.Format(_T("CURR %.3f\n"), dCurr);
				break;
			case KS_PMX:
				csCmd.Format(_T("CURRent %.3f\n"), dCurr);
				break;
			case DH_17XX:
				csCmd.Format(_T("CURRent %.3f\n"), dCurr);
				break;
			case GW_PFR_PSW:
				csCmd.Format(_T("CURRent %.3f\n"), dCurr);
				break;
			case IT6100B:
				csCmd.Format(_T("SOURce:CURRent:LEVel %.3fA\n"), dCurr);//�����﷨��[SOURce:]CURRent [:LEVel] <NRf>
				break;
			default:
				csCmd.Format(_T("CURR %.3f\n"), dCurr);
				break;
			}

			//
			break;
		}
		else
		{
			return;
		}
	default:
		return;
	}

	//����ָ��
	this->Write(csCmd);
}

void CPower_Supply::Set_Test_Point(int iPoint)
{
	CString csCmd;

	switch (this->m_iPS_Model)
	{
	case KEITHLEY:
		csCmd.Format(_T("SENS:AVER %d\n"), iPoint);
		break;
	case AG_66:
		csCmd.Format(_T("SENS:SWE:POIN %d\n"), iPoint);
		break;
	case IT6100B:
		csCmd.Format(_T("SENSe:AVERage:COUNt %d\n"), iPoint);//�����﷨��SENSe:AVERage:COUNt <NR1 | MIN | MAX | DEF>
		break;
	default:
		return;
	}

	//
	this->Write(csCmd);
}

void CPower_Supply::Power_On(int iCH)
{
	CString csCmd;

	switch (this->m_iPS_Type)
	{
	case TWO_CH:
		if (iCH <= 2)
		{
			if (this->m_iPS_Model == KEITHLEY)
			{
				csCmd.Format(_T("OUTP%d ON\n"), iCH);
			}
			else if (this->m_iPS_Model == AG_66)
			{
				csCmd.Format(_T("OUTP%d ON\n"), iCH);
			}
			else
			{
				csCmd.Format(_T("OUTP%d ON\n"), iCH);
			}

			break;
		}
		else
		{
			return;
		}

	case ONE_CH:
		if (iCH == 1)
		{
			switch (this->m_iPS_Model)
			{
			case KEITHLEY:
				csCmd.Format(_T("OUTP ON\n"));
				break;

			case AG_66:
			case AG_E36XX:
			case AG_E3610X:
				csCmd.Format(_T("OUTP ON\n"));
				break;

			case KS_PMX:
			case DH_17XX:
			case GW_PFR_PSW:
				csCmd.Format(_T("OUTPut ON\n"));
				break;

			case IT6100B:
				csCmd.Format(_T("OUTPut:STATe ON\n"));//�����﷨��OUTPut[:STATe] <bool>
				break;

			default:
				csCmd.Format(_T("OUTP ON\n"));
				break;
			}

			//
			break;
		}
		else
		{
			return;
		}

	default:
		return;
	}

	//����ָ��
	this->Write(csCmd);
}

void CPower_Supply::Power_Off(int iCH)
{
	CString csCmd;

	switch (this->m_iPS_Type)
	{
	case TWO_CH:
		if (iCH <= 2)
		{
			if (this->m_iPS_Model == KEITHLEY)
			{
				csCmd.Format(_T("OUTP%d OFF\n"), iCH);
			}
			else if (this->m_iPS_Model == AG_66)
			{
				csCmd.Format(_T("OUTP%d OFF\n"), iCH);
			}
			else
			{
				csCmd.Format(_T("OUTP%d OFF\n"), iCH);
			}

			break;
		}
		else
		{
			return;
		}

	case ONE_CH:
		if (iCH == 1)
		{
			switch (this->m_iPS_Model)
			{
			case KEITHLEY:
				csCmd.Format(_T("OUTP OFF\n"));
				break;

			case AG_66:
			case AG_E36XX:
			case AG_E3610X:
				csCmd.Format(_T("OUTP OFF\n"));
				break;

			case KS_PMX:
			case DH_17XX:
			case GW_PFR_PSW:
				csCmd.Format(_T("OUTPut OFF\n"));//OUTPut 0(0��ʾ�ر�)
				break;

			case IT6100B:
				csCmd.Format(_T("OUTPut:STATe OFF\n"));//�����﷨��OUTPut[:STATe] <bool>
				break;

			default:
				csCmd.Format(_T("OUTP OFF\n"));
				break;
			}

			//
			break;
		}
		else
		{
			return;
		}

	default:
		return;
	}


	//����ָ��
	this->Write(csCmd);
}

bool CPower_Supply::Meas_Volt(int iCH, double * dpVolt)
{
	wchar_t * wcpData = NULL;
	CString csCmd;

	try
	{
		wcpData = (wchar_t *)calloc(128, sizeof(wchar_t));

		switch (this->m_iPS_Type)
		{
		case TWO_CH:
			if (iCH <= 2)
			{
				if (this->m_iPS_Model == KEITHLEY)
				{
					csCmd.Format(_T("MEAS%d:VOLT?\n"), iCH);
					this->Query(csCmd, wcpData);
					*dpVolt = _wtof(wcpData);
				}
				else if (this->m_iPS_Model == AG_66)
				{
					this->Write(_T("SENS:FUNC \"VOLT\"\n"));
					csCmd.Format(_T("MEAS:VOLT%d?\n"), iCH);
					this->Query(csCmd, wcpData);
					*dpVolt = _wtof(wcpData);
				}
				else
				{
					csCmd.Format(_T("MEAS:VOLT%d?\n"), iCH);
					this->Query(csCmd, wcpData);
					*dpVolt = _wtof(wcpData);
				}

				break;
			}
			else
			{
				throw(0);
			}

		case ONE_CH:
			if (iCH == 1)
			{
				switch (this->m_iPS_Model)
				{
				case KEITHLEY:
					this->Query(_T("MEAS:VOLT?\n"), wcpData);
					*dpVolt = _wtof(wcpData);
					break;
				case AG_66:
					this->Write(_T("SENS:FUNC \"VOLT\"\n"));
					this->Query(_T("MEAS:VOLT?\n"), wcpData);
					*dpVolt = _wtof(wcpData);
					break;
				case IT6100B:
					this->Query(_T("MEASure:VOLTage:DC?\n"), wcpData);//�����﷨�� MEASure:VOLTage[:DC]?
					*dpVolt = _wtof(wcpData);
					break;
				case KS_PMX:
					this->Query(_T("MEASure:VOLTage?\n"), wcpData);
					*dpVolt = _wtof(wcpData);
					break;
				case DH_17XX:
					this->Query(_T("MEASure:VOLTage?\n"), wcpData);
					*dpVolt = _wtof(wcpData);
					break;
				case GW_PFR_PSW:
					this->Query(_T("MEASure:VOLTage?\n"), wcpData);
					*dpVolt = _wtof(wcpData);
					break;
				default:
					this->Query(_T("MEAS:VOLT?\n"), wcpData);
					*dpVolt = _wtof(wcpData);
					break;
				}

				//
				break;
			}
			else
			{
				throw(0);
			}

		default:
			throw(0);
		}
	}
	catch (...)
	{
		//�ͷ��ڴ�
		if (wcpData != NULL)
		{
			free(wcpData);
		}

		//fail
		return false;
	}

	//�ͷ��ڴ�
	if (wcpData != NULL)
	{
		free(wcpData);
	}

	//pass
	return true;
}

bool CPower_Supply::Meas_Curr(int iCH, double * dpCurr)
{
	wchar_t wcpData[128];
	CString csCmd;

	try
	{
		memset(wcpData, 0, sizeof(wcpData));
		switch(this->m_iPS_Type)
		{
		case TWO_CH:
			if(iCH <= 2)
			{
				if(this->m_iPS_Model == KEITHLEY)
				{
					csCmd.Format(_T("MEAS%d:CURR?\n"), iCH);
					this->Query(csCmd, wcpData);
					*dpCurr = _wtof(wcpData);
				}
				else if(this->m_iPS_Model == AG_66)
				{
					this->Write(_T("SENS:CURR:DET DC\n"));
					this->Write(_T("SENS:FUNC \"CURR\"\n"));
					csCmd.Format(_T("MEAS:CURR%d?\n"), iCH);
					this->Query(csCmd, wcpData);
					*dpCurr = _wtof(wcpData);
				}
				else
				{
					csCmd.Format(_T("MEAS:CURR%d?\n"), iCH);
					this->Query(csCmd, wcpData);
					*dpCurr = _wtof(wcpData);
				}

				break;
			}
			else
			{
				throw(0);
			}
		case ONE_CH:
			if(iCH == 1)
			{
				switch(this->m_iPS_Model)
				{
				case KEITHLEY:
					this->Query(_T("MEAS:CURR?\n"), wcpData);
					*dpCurr = _wtof(wcpData);
					break;
				case AG_66:
					this->Write(_T("SENS:CURR:DET DC\n"));
					this->Write(_T("SENS:FUNC \"CURR\"\n"));
					this->Query(_T("MEAS:CURR?\n"), wcpData);
					*dpCurr = _wtof(wcpData);
					break;
				case IT6100B:
					this->Query(_T("MEASure:CURRent:DC?\n"), wcpData);//�����﷨�� MEASure:CURRent[:DC]?
					*dpCurr = _wtof(wcpData);
					break;
				case KS_PMX:
					this->Query(_T("MEASure:CURRent?\n"), wcpData);
					*dpCurr = _wtof(wcpData);
					break;
				case DH_17XX:
					this->Query(_T("MEASure:CURRent?\n"), wcpData);
					*dpCurr = _wtof(wcpData);
					break;
				case GW_PFR_PSW:
					this->Query(_T("MEASure:CURRent?\n"), wcpData);
					*dpCurr = _wtof(wcpData);
					break;
				default:
					this->Query(_T("MEAS:CURR?\n"), wcpData);
					*dpCurr = _wtof(wcpData);
					break;
				}

				//
				break;
			}
			else
			{
				throw(0);
			}
		default:
			throw(0);
		}
	}
	catch(...)
	{
		return false;
	}

	return true;
}

bool CPower_Supply::Meas_Curr_V1(int iCH, double * dpCurr, UINT iCount, UINT iTimeGap, UINT iType)
{
	int i = 0;
	double dpCurrMin = 0.0, dpCurrMax = 0.0, dpCurrAvg = 0.0,dpCurrMea = 0.0,dpCurrTotal = 0.0;
	for (i = 0; i < iCount; i++)
	{
		dpCurrMea = 0.0;
		if (Meas_Curr(iCH, &dpCurrMea) == false)
		{
			//����ƽ������ʱfail������ѭ��
			if (iType == 0)
			{
				return false;
			}
		}
		//תmA
		dpCurrMea = dpCurrMea* 1000.0;
		//��ͼ���ƽ��ֵ
		dpCurrTotal += dpCurrMea;
		//
		if (dpCurrMea >= dpCurrMax)
		{
			dpCurrMax = dpCurrMea;
		}
		if (dpCurrMea <= dpCurrMin)
		{
			dpCurrMin = dpCurrMea;
		}
		Sleep(iTimeGap);
	}
	switch (iType)
	{
	case 0:
	default:
		*dpCurr = dpCurrTotal / iCount;
		break;
	case 1:
		*dpCurr = dpCurrMin;
		break;
	case 2:
		*dpCurr = dpCurrMax;
		break;
	}
	return true;
}

void CPower_Supply::Close_VISA(void)
{
	if(this->m_vise_DefaultRM != NULL)
	{
		viClear(this->m_ul_PS_Handle);
		viClose(this->m_ul_PS_Handle);
		viClose(this->m_vise_DefaultRM);

		//
		this->m_ul_PS_Handle = NULL;
		this->m_vise_DefaultRM = NULL;
	}
}

int CPower_Supply::INIT_PS_IT6100B(void)
{
	this->Set_Volt(1, this->m_d_Init_Volt);

	this->Set_Curr(1, this->m_d_Init_Curr);
	
	this->Set_Test_Point(50);

	//����������������SOURCE METER ΪԶ�̿���ģʽ
	this->Write(_T("SYSTem:REMote\n"));

	return RTN_SUCCESS;
}

void CPower_Supply::POWER_ON_V1(int i_CH)
{
	//�׶�ʽ�ϵ硢�򿪵�Դ���

	int i;
	double drVolt_List[4] = { 0.0, 1.2, 2.4 };


	//
	for(i=0; i<3; i++)
	{
		//���õ�ѹֵ
		this->Set_Volt( i_CH, drVolt_List[i] );

		//�������ֻһ�Σ�
		if(i == 0)
		{
			//�򿪵�Դ���
			this->Power_On( i_CH );
		}

		//�ӳ�
		Sleep(500);
	}


	//����е���ʵ�������ѹ��
	this->Set_Volt( i_CH, this->m_d_Init_Volt );

	//
	Sleep(400);

	//�ٴ����á�ʵ�������ѹ������ֹGPIB������
	this->Set_Volt( i_CH, this->m_d_Init_Volt );
}

void CPower_Supply::POWER_OFF_V1(int i_CH)
{
	int i;
	double drVolt_List[4] = { 2.4, 1.2, 0.0 };


	//
	for(i=0; i<3; i++)
	{
		//���õ�ѹֵ
		this->Set_Volt( i_CH, drVolt_List[i] );

		//�ӳ�
		Sleep(450);
	}


	//�ر����
	this->Power_Off( i_CH );
}

bool CPower_Supply::CHECK_PS_SYSTEM_ERROR()
{
	wchar_t * wcpData = NULL;
	CString csData;

	//
	try
	{
		//�����ڴ�
		wcpData = (wchar_t *)calloc(128, sizeof(wchar_t));

		//
		switch (this->m_iPS_Model)
		{
		case KEITHLEY:
			this->Query(_T(":SYSTem:ERRor?\n"), wcpData);
			break;

		case AG_66:
		case AG_E36XX:
		case IT6100B:
		case AG_E3610X:
		case KS_PMX:
		case DH_17XX:
		case GW_PFR_PSW:
			this->Query(_T("SYSTem:ERRor?\n"), wcpData);
			break;

		default:
			this->Query(_T("SYSTem:ERRor?\n"), wcpData);
			break;
		}

		//ת����д
		csData.Format(_T("%s"), wcpData);
		csData.MakeUpper();


		//�ж����ؽ��
		if (NULL == _tcsstr(csData, _T("NO ERROR")))
		{
			//û�ҵ�"NO ERROR"�ؼ��ʣ��д�����
			//���������Ϣ
			this->m_csError_Info.Format(_T("ERROR, PS has error(%s)!"), wcpData);
			//fail
			throw(0);
		}


		//�ͷ��ڴ�
		if (wcpData != NULL)
		{
			free(wcpData);
		}

	}
	catch (...)
	{
		//�ͷ��ڴ�
		if (wcpData != NULL)
		{
			free(wcpData);
		}

		//fail
		return false;
	}

	//pass
	return true;
}


void CPower_Supply::FREE_ALL()
{
	switch (this->m_iCtrl_Type_GPIB_Or_LAN)
	{
	case GPIB_NI://NI API
		this->Close_NI_Device();
		//
		break;

	case GPIB_VISA://VISA API
	case GPIB_VISA_TCPIP:
		this->Close_VISA();
		//
		break;

	default:
		//
		break;
	}//switch( m_iCtrl_Type_GPIB_Or_LAN
}


void CPower_Supply::Close_NI_Device()
{
	//NI
	if (this->m_ul_PS_Handle != NULL)
	{
		//Place the device or interface online or offline.
		//if v is zero, the device or interface is placed offline.
		//If v is non-zero, the device or interface is left operational, or online.
		ibonl(this->m_ul_PS_Handle, 0);

		//��վ��
		this->m_ul_PS_Handle = NULL;
		this->m_vise_DefaultRM = NULL;
	}
}


void CPower_Supply::INIT_PS_KS_PMX()
{
	this->Set_Volt(1, this->m_d_Init_Volt);

	this->Set_Curr(1, this->m_d_Init_Curr);
}

void CPower_Supply::INIT_PS_DH_17XX()
{
	this->Set_Volt(1, this->m_d_Init_Volt);

	this->Set_Curr(1, this->m_d_Init_Curr);
}

void CPower_Supply::INIT_PS_GW_PFR_PSW()
{
	this->Set_Volt(1, this->m_d_Init_Volt);

	this->Set_Curr(1, this->m_d_Init_Curr);
}