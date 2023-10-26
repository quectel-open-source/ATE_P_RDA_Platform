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

//输出函数接口
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
DLL_IMP bool RF_CAL_FT_RDA_DO_EXECUTE_RF_FT(bool b_PS_Power_Off_In_The_End, int i_Test_Plan = 0);//非信令测试
DLL_IMP bool RF_CAL_FT_RDA_DO_EXECUTE_NONE_RF_FT(bool b_PS_Power_Off_In_The_End);//跑FT测试流程但是不测试RF
DLL_IMP bool RF_CAL_FT_RDA_DO_EXECUTE_RF_CAL(bool b_PS_Power_Off_In_The_End);//校准测试
DLL_IMP bool RF_CAL_FT_RDA_DO_EXECUTE_RF_CAL_FT(bool b_PS_Power_Off_In_The_End,bool bDo_FT = true);//跑BT测试流程但是不测试FT
DLL_IMP void RF_CAL_FT_RDA_DO_EXECUTE_RF_CAL_FT_RELEASE();//跑完测试流程释放资源
/*********************金版制作*********************/
DLL_IMP bool RF_CAL_FT_RDA_DO_MAKE_REF_V1(CStringW * csp_REF_ALL_SN );//上传金板数据
DLL_IMP bool RF_CAL_FT_RDA_DO_MAKE_REF_V2(CStringW * csp_REF_ALL_SN);//上传金板数据
DLL_IMP void RF_CAL_FT_RDA_LOAD_DATA_REF_IMEI(const wchar_t * wcp_Ref_IMEI);//加载界面传入的IMEI号码
DLL_IMP void RF_CAL_FT_RDA_GET_REF_ALL_SN(CStringW * csp_REF_ALL_SN);//获取当前SN的号码
DLL_IMP void RF_CAL_FT_RDA_GET_INSTRU_INFO(CStringW * csp_Instru_Info);//获取当前的仪器设备信息
/*********************线损校准*********************/
DLL_IMP bool RF_CAL_FT_RDA_DO_CAL_LOSS_V2_S1( CStringW * csp_IMEI_In_REF, CStringW * csp_SN_In_REF );
DLL_IMP bool RF_CAL_FT_RDA_DO_CAL_LOSS_V2_S2(const wchar_t * wcp_Ref_Data_In_SQL, ANT_CFG_ALL_V2_S & oj_str_New_ANT_RF_Loss, bool bNormal);
DLL_IMP void RF_CAL_FT_RDA_DO_CAL_LOSS_V2_S1_END();
/*********************GPS测试*********************/
DLL_IMP bool RF_CAL_FT_RDA_DO_GPS_TEST(UINT i_GPSTest_ComPort);//GPS测试
/*********************电源关闭*********************/
DLL_IMP bool RF_CAL_FT_RDA_DO_PS_POWER_OFF();
/*********************测试Error信息*********************/
DLL_IMP void RF_CAL_FT_RDA_GET_ERROR_ALL(int *ip_Error_Code, CStringW *csp_Error_Info);
/*********************测试CPK数据回传********************/
DLL_IMP bool RF_CAL_FT_RDA_GET_TS_CPK_DATA_IN_2G(int i_2G_CPK_Band_Name, double *dp_2G_CPK_Test_Data, double *dp_TX_PWR_Low_Limit, double *dp_TX_PWR_High_Limit, double *dp_TX_PWR_Target_Data);
DLL_IMP void RF_CAL_FT_RDA_GET_TS_CPK_DATA_IN_NB(int& i_NB_CPK_Band_Name, double *dp_NB_CPK_Test_Data);
/*********************客户工具标志位********************/
DLL_IMP void RF_CAL_FT_RDA_LOAD_APP_OBJ(int i_Application_Object);
/*********************界面扫描的IMEI号码传入********************/
DLL_IMP void RF_CAL_FT_RDA_LOAD_SCANED_IMEI(const wchar_t * wcp_Scan_IMEI);//加载界面界面扫描的IMEI号码
//加载界面传入的IMEI1号码
DLL_IMP void RF_CAL_FT_RDA_LOAD_DATA_IMEI_1(const wchar_t * wcp_IMEI1);
//加载界面传入的IMEI2号码
DLL_IMP void RF_CAL_FT_RDA_LOAD_DATA_IMEI_2(const wchar_t * wcp_IMEI2);
//加载界面传入的SN号码
DLL_IMP void RF_CAL_FT_RDA_LOAD_DATA_SN(const wchar_t * wcp_SN);
//加载界面传入的蓝牙号码
DLL_IMP void RF_CAL_FT_RDA_LOAD_DATA_BT_ADDR(const wchar_t * wcp_BT_ADDR);
//加载界面传入的WIFI号码
DLL_IMP void RF_CAL_FT_RDA_LOAD_DATA_MAC_ADDR(const wchar_t * wcp_MAC_ADDR);
//加载界面传入的MEID号码
DLL_IMP void RF_CAL_FT_RDA_LOAD_DATA_MEID(const wchar_t * wcp_MEID);
//执行写号
DLL_IMP bool RF_CAL_FT_RDA_DO_WRITE_NUMBER_IN_RF_CAL();
//执行号码检查
DLL_IMP bool RF_CAL_FT_RDA_DO_Check_NUMBER_IN_RF_CAL();

//判断OPEN/SHORT金板是否合法金板（从数据库信息的来判断）
DLL_IMP void RF_CAL_FT_RDA_LOAD_GOLDEN_BOARD_REF_FLAG( bool b_Rtn_Flag);

