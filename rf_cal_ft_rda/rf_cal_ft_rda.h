#pragma once
#include "Global.h"
#include "GFC.h"
#include "Run.h"

//
 #ifdef DLL_IMPLEMENT
 #define DLL_IMP extern "C" _declspec(dllexport)
 #else
 #define DLL_IMP _declspec(dllimport)//#define DLL_IMP extern "C" _declspec(dllimport)
 #endif

//��������ӿ�
DLL_IMP bool RF_CAL_FT_RDA_INIT_FIRST();
DLL_IMP bool RF_CAL_FT_RDA_INIT_ALL();
DLL_IMP void RF_CAL_FT_RDA_FREE_ALL();
DLL_IMP void RF_CAL_FT_RDA_CLEAR_ALL_PARAMTERS();
DLL_IMP void RF_CAL_FT_RDA_LOAD_GPS_TEST_ENABLE(bool b_GPS_Test_Enable);
DLL_IMP void RF_CAL_FT_RDA_LOAD_TEST_CTRL(bool b_Fail_Stop_Enable, bool b_Flag_Op_Enable);
DLL_IMP void RF_CAL_FT_RDA_LOAD_ARG_QTI(QTI_PROG_ARG * strp_QTI_Arg);
DLL_IMP void RF_CAL_FT_RDA_LOAD_ARG_QTI_SQL(QTI_PROG_ARG_SQL * strp_QTI_Arg_SQL);
DLL_IMP void RF_CAL_FT_RDA_LOAD_ALL_DATA_V1(TESTER_CONFIG_S str_Tester_Config, TS_CONFIG_S str_TS_Config);
DLL_IMP void RF_CAL_FT_RDA_LOAD_ALL_DATA_V2(TESTER_CONFIG_S str_PS_Config, TESTER_CONFIG_S str_Tester_Config, TS_CONFIG_S str_TS_Config, ANT_CFG_ALL_V2_S str_Ant_Config);
DLL_IMP bool RF_CAL_FT_RDA_LOAD_RUN_PATH(const wchar_t * wcp_ConfigFilePath, const wchar_t * wcp_DllWorkPath);
DLL_IMP void RF_CAL_FT_RDA_LOAD_ARG_READ_OCP_PARAMS(READ_OCP_PARAMS_ARG * strp_Read_OCP_Params_Arg);
DLL_IMP bool RF_CAL_FT_RDA_LOAD_PRODU_NAME_AND_TYPE(const wchar_t * wcp_Produ_Name, int i_Produ_Type, int i_Produ_Ver);
DLL_IMP void RF_CAL_FT_RDA_LOAD_OC_INFO(const wchar_t * wcp_OC_Name, const wchar_t * wcp_MO_Name, const wchar_t * wcp_PN_Number, int i_Produ_Process_Property);
DLL_IMP void RF_CAL_FT_RDA_LOAD_PRODU_FW(const wchar_t * wcp_FW);
DLL_IMP void RF_CAL_FT_RDA_LOAD_PRODU_GSM_BAND_LIST(int * ip_GSM_Band_List, int i_GSM_Band_Quan);
DLL_IMP void RF_CAL_FT_RDA_LOAD_PRODU_NB_BAND_LIST(int * ip_NB_Band_List, int i_NB_Band_Quan);
DLL_IMP void RF_CAL_FT_RDA_LOAD_PRODU_VOLT_AND_CURR(double d_Voltage, double d_Current);
DLL_IMP bool RF_CAL_FT_RDA_DO_EXECUTE_RF_FT(bool b_PS_Power_Off_In_The_End, int i_Test_Plan = 0);//���������
DLL_IMP bool RF_CAL_FT_RDA_DO_EXECUTE_NONE_RF_FT(bool b_PS_Power_Off_In_The_End);//��FT�������̵��ǲ�����RF
DLL_IMP bool RF_CAL_FT_RDA_DO_EXECUTE_RF_CAL(bool b_PS_Power_Off_In_The_End);//У׼����
DLL_IMP bool RF_CAL_FT_RDA_DO_EXECUTE_RF_CAL_FT(bool b_PS_Power_Off_In_The_End,bool bDo_FT = true);//��BT�������̵��ǲ�����FT
DLL_IMP void RF_CAL_FT_RDA_DO_EXECUTE_RF_CAL_FT_RELEASE();//������������ͷ���Դ
/*********************�������*********************/
DLL_IMP bool RF_CAL_FT_RDA_DO_MAKE_REF_V1(CStringW * csp_REF_ALL_SN );//�ϴ��������
DLL_IMP bool RF_CAL_FT_RDA_DO_MAKE_REF_V2(CStringW * csp_REF_ALL_SN);//�ϴ��������
DLL_IMP void RF_CAL_FT_RDA_LOAD_DATA_REF_IMEI(const wchar_t * wcp_Ref_IMEI);//���ؽ��洫���IMEI����
DLL_IMP void RF_CAL_FT_RDA_GET_REF_ALL_SN(CStringW * csp_REF_ALL_SN);//��ȡ��ǰSN�ĺ���
DLL_IMP void RF_CAL_FT_RDA_GET_INSTRU_INFO(CStringW * csp_Instru_Info);//��ȡ��ǰ�������豸��Ϣ
/*********************����У׼*********************/
DLL_IMP bool RF_CAL_FT_RDA_DO_CAL_LOSS_V2_S1( CStringW * csp_IMEI_In_REF, CStringW * csp_SN_In_REF );
DLL_IMP bool RF_CAL_FT_RDA_DO_CAL_LOSS_V2_S2(const wchar_t * wcp_Ref_Data_In_SQL, ANT_CFG_ALL_V2_S & oj_str_New_ANT_RF_Loss, bool bNormal);
DLL_IMP void RF_CAL_FT_RDA_DO_CAL_LOSS_V2_S1_END();
/*********************GPS����*********************/
DLL_IMP bool RF_CAL_FT_RDA_DO_GPS_TEST(UINT i_GPSTest_ComPort);//GPS����
/*********************��Դ�ر�*********************/
DLL_IMP bool RF_CAL_FT_RDA_DO_PS_POWER_OFF();
/*********************����Error��Ϣ*********************/
DLL_IMP void RF_CAL_FT_RDA_GET_ERROR_ALL(int *ip_Error_Code, CStringW *csp_Error_Info);
/*********************����CPK���ݻش�********************/
DLL_IMP bool RF_CAL_FT_RDA_GET_TS_CPK_DATA_IN_2G(int i_2G_CPK_Band_Name, double *dp_2G_CPK_Test_Data, double *dp_TX_PWR_Low_Limit, double *dp_TX_PWR_High_Limit, double *dp_TX_PWR_Target_Data);
DLL_IMP void RF_CAL_FT_RDA_GET_TS_CPK_DATA_IN_NB(int& i_NB_CPK_Band_Name, double *dp_NB_CPK_Test_Data);
/*********************�ͻ����߱�־λ********************/
DLL_IMP void RF_CAL_FT_RDA_LOAD_APP_OBJ(int i_Application_Object);
/*********************����ɨ���IMEI���봫��********************/
DLL_IMP void RF_CAL_FT_RDA_LOAD_SCANED_IMEI(const wchar_t * wcp_Scan_IMEI);//���ؽ������ɨ���IMEI����
//���ؽ��洫���IMEI1����
DLL_IMP void RF_CAL_FT_RDA_LOAD_DATA_IMEI_1(const wchar_t * wcp_IMEI1);
//���ؽ��洫���IMEI2����
DLL_IMP void RF_CAL_FT_RDA_LOAD_DATA_IMEI_2(const wchar_t * wcp_IMEI2);
//���ؽ��洫���SN����
DLL_IMP void RF_CAL_FT_RDA_LOAD_DATA_SN(const wchar_t * wcp_SN);
//���ؽ��洫�����������
DLL_IMP void RF_CAL_FT_RDA_LOAD_DATA_BT_ADDR(const wchar_t * wcp_BT_ADDR);
//���ؽ��洫���WIFI����
DLL_IMP void RF_CAL_FT_RDA_LOAD_DATA_MAC_ADDR(const wchar_t * wcp_MAC_ADDR);
//���ؽ��洫���MEID����
DLL_IMP void RF_CAL_FT_RDA_LOAD_DATA_MEID(const wchar_t * wcp_MEID);
//ִ��д��
DLL_IMP bool RF_CAL_FT_RDA_DO_WRITE_NUMBER_IN_RF_CAL();
//ִ�к�����
DLL_IMP bool RF_CAL_FT_RDA_DO_Check_NUMBER_IN_RF_CAL();

//�ж�OPEN/SHORT����Ƿ�Ϸ���壨�����ݿ���Ϣ�����жϣ�
DLL_IMP void RF_CAL_FT_RDA_LOAD_GOLDEN_BOARD_REF_FLAG( bool b_Rtn_Flag);

