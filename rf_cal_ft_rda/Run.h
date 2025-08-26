#pragma once
#include "stdafx.h"
#include <map>
#include <set>
#include "Power_Supply.h"
#include "ComObj00.h"
#include "Global.h"
#include "GFC.h"
//RAD �����������ͷ�ļ�
#include "AgilentTest.h"
#include "AgilentCalib.h"
#include "CmuCalib.h"
#include "CmuTest.h"
#include "AgilentE6607ACalib.h"
#include "AgilentE6607ANsft.h"
#include "AgilentE6640Calib.h"
#include "AgilentE6640Nsft.h"
#include "DTTest.h"
#include "DT3110Calib.h"
#include "Cmw500Test.h"
#include "Cmw500Calib.h"
#include "Cmu200Nsft.h"
#include "Agilent8960Nsft.h"
#include "Cmw500Nsft.h"
#include "Cmw100Calib.h"
#include "Cmw100Nsft.h"
#include "MT8821Calib.h"
#include "MT8821Nsft.h"
#include "SP9010Calib.h"
#include "SP9010Nsft.h"
#include "MT8870Calib.h"
#include "MT8870Nsft.h"
#include "IQXStreamCalib.h"
#include "IQXStreamNsft.h"
#include "IQMStreamCalib.h"
#include "IQMStreamNsft.h"
#include "Rda2GCalib.h"
#include "Rda2GNsft.h"
#include "QAPLC_Lib.h"
//RDA Connect ���ͷ�ļ�
#include "TargetConnection.h"
#include "ChipInfo.h"
#include "GlobalParametersLink.h"
#include "Global_N.h"
#include "ErrorCode.h"
#include "Caliberation.h"

/***********************��ʱ����*************************/
#define TEMPORARY_TEST_FOLLOW_FLAG		0
//������Ҫ�������̴���Ĺ���
#define TEMPORARY_MO_COUNT				1
const CString g_sTemporaryMOName[TEMPORARY_MO_COUNT] = { 
// 	"YYZJSD19011617" ,"YYZJSD19011889","YYZTTG19021368",//M25��ʱ����
// 	"YYZTTG19021369","YYZTTG19021371","YYZTTG19021370",//BC32��ʱ����
// 	"YYZJSD19021545", //BC25��ʱ����
// 	"YYZTTG19021382","YYZTTG19021389",//M25��ʱ����
// 	"YYZTTG19031379"//BC25PB��ͨ��ʱ���BER����
// 	"YYZTTG19031441", "YYZTTG19031443",//M35-R�����鵵,��ͨ��ʱ����
// 	"YYZTTG19031448", "YYZTTG19031449" //M56-R�����鵵,��ͨ��ʱ����
//	"YYZTTG19031434",//BC32B8RB��ͨ��ʱȥ��GSM�����ײ���
//	"YYZTTG19041392",//M35-R��ͨ��ʱ��������ʽ����ͬ���鵵��
//	"YYZJSD19041941",//���TE-A����ʱ��ͬ��ģ���л�����ʱ�˿��쳣������
//	"HF190531115242",//�Ϸ�BC32��������������RDAƽ̨8908A��ʱ�����⻹�޷��鵵
//	"YYZJSD19051966",//������BC32������������RDAƽ̨8908A��ʱ�����⻹�޷��鵵
//	"YYZJSD19051997",//BC32 100PF ��ȥ�����þɵ�Setting�ļ���֤
//	"YYZTTG19061399",//��ͨС�����Բ���֤
//	"YYZTTG19061416",//BC25PA-04-BT band8����ƫ��
//	"YYZJSD19051944",//BC32B8RB-08-STDС������֤
//	"YYZJSD19061824"//BC92RB-08-STD
//	"YYZTTG19071470",//M35R У׼�ĵ�DACֵ����
//	"YYZTTG19071474"//M35R У׼�ĵ�DACֵ����
//	"YYZJSD19102062",//BC65PB-04-BT�ù�����FW�ȽϾɣ������ķ��������FW��û�м��ɺ�
//	"YYZJSD19102063"//BC65PB-04-BT�ù�����FW�ȽϾɣ������ķ��������FW��û�м��ɺ�
//	"YYZTTM20011447",//M25MA 4Ƶ��2Ƶ
//	"YYZTTM20011448",//M25MA 4Ƶ��2Ƶ
// 	"YYZTTM20011422",//M25MA 4Ƶ��2Ƶ
//	"YYZTTM20011423",//M25MA 4Ƶ��2Ƶ
//	"YYZXTG20011431",//M25MA 4Ƶ��2Ƶ
//	"YYZXTG20011426"
//	"REYTTM20031500"//M56Rû��������ֻ���Ը��ŵ���Cell Power -100 BER
//	"REYTTM20031500"//M56Rû��������DCSֻ���Ը��ŵ�
//	"RSWJSD20061731"//BC32-B8RB_Setting-PCBA_V1.1
	"CXGQ5000000652"//M6315����ά��������PA������
};
enum CUSTOMER_ID
{
	CUSTOMER_CHANGE_CHEN = 0,
	CUSTOMER_South_Africa
};

#define SHOW_LOG			1		//�����ϲ�ռ�ص�log��ӡ
//��������
#define BLE_RX_LEVEL		-70.0
#define BLE_POWER_TAR		8.0
#define BLE_POWER_TOL	    4.0
//GPS Test
#define GPS_SNR_LEVEL		-120.0
//NB ��������-108
#define NB_BER_LEVEL		-108.0
#define NB_POWER_TAR		23.0
#define NB_POWER_TOL		1.5
//Golden Sample
#define POWER_GOLDEN_TOL	9.0
//GSM ��������102
#define GSM_BER_LEVEL		102.0
#define GSM_RX_LEVEL		75
#define GSM_RX_LEVEL_TOL	2.0

#define GSM_POWER_TAR		32.5
#define GSM_POWER_TOL	    1.5
#define GSM_POWER_MIN_TAR	5.0
#define GSM_POWER_MIN_TOL	4.0

#define DCS_POWER_TAR		29.5
#define DCS_POWER_TOL		1.5

#define DCS_POWER_MIN_TAR	0.0
#define DCS_POWER_MIN_TOL	4.0

#define MIN_POWER_TEST		1

#define GOLDEN_MARK		"Golden_Board"

#define TEST_LOOP		3//������ѭ������

//��������
#define POWER_ON_CURRENT_LOW	1.0
#define POWER_ON_CURRENT_HIGH	160.0
#define WORK_CURRENT_LOW		1.0
#define WORK_CURRENT_HIGH		100.0
#define MAXPOWER_CURRENT_LOW	1.0
#define MAXPOWER_CURRENT_HIGH	600.0
typedef enum RF_MODEL
{
	GSM_Mode,
	NB_LOT 
}RF_MODEL;

typedef enum TEST_MODEL
{
	BT,
	FT,
	GOLDEN
}TEST_MODEL;

 typedef enum GSM_BAND_IDX
 {
 	GSM = 0, EGSM, DCS,PCS,GSM_BAND_COUNT
 }GSM_BAND_IDX;

struct PRODUCT_INFO
{
	CString sOC_Name;
	CString sMO_Name;
	CString sPN_Number;
	CString sProdu_Name;
	CString sFW_Ver;
	CString sIMEI;
	CString sIMEI1;
	CString sSN;
	CString sSN_W;
	CString sIMEI2;
	CString sBT_Addr;
	CString sWIFI_MAC;
	CString sMEID;
	CString sGolden;
	CString sTreeName;
	CString sSW_DL;							        //����汾��Ϣ,��������汾
	CString sSW_Label;							    //����汾��Ϣ����ǩ����汾
	int i_Process_Type;//PRODU_PROP_REP PRODU_PROP_NORMAL
	int i_Produ_Type;
	int i_Produ_Ver;
	int i_Initial_Time;
	int GSM_BandList[G_BAND_SIZE];
	int GSM_BandCount;
	int NB_BandList[NB_IDX_B_SIZE];
	int NB_BandCount;
};

struct GSM2G_NS_TEST
{
	int iBandlistOption[GSM_BAND_COUNT];
	int iChannel[GSM_BAND_COUNT][CHANNEL_NUM];
	int iPCLList[GSM_BAND_COUNT][2];
// 	float iChannelFreqTx[4][CHANNEL_NUM];
// 	float iChannelLossTx[4][CHANNEL_NUM];
// 	float iChannelFreqRx[4][CHANNEL_NUM];
// 	float iChannelLossRx[4][CHANNEL_NUM];
	float Power_Limit[2][GSM_BAND_COUNT][2]; // 0-max ,1-Min
	float Freq_Limit[GSM_BAND_COUNT];
	float RXLevel_Limit[2];
	//int SensitivityLevel[4];
	//float SwitchSpecture_Limit[4][8];
	//float ModuSpecture_Limit[4][22];
	//float Ber_Limit;
	//float FreqErr_Limit;
	//float PhaseErr_Limit[2];
	//float PhaseRMSErr_Limit[2];
};

struct GSM2G_NS_TEST_RST_ALL
{
	float TX_Power[GSM_BAND_COUNT][CHANNEL_NUM];
	float Ber[GSM_BAND_COUNT][CHANNEL_NUM];
	float FreqErr[GSM_BAND_COUNT][CHANNEL_NUM];
	float PhaseErr[GSM_BAND_COUNT][CHANNEL_NUM];
	float PhaseRMSErr[GSM_BAND_COUNT][CHANNEL_NUM];
	int PVT[GSM_BAND_COUNT][CHANNEL_NUM];
	int ORFSM[GSM_BAND_COUNT][CHANNEL_NUM];
	int ORFSS[GSM_BAND_COUNT][CHANNEL_NUM];
	int RxLevel[GSM_BAND_COUNT][CHANNEL_NUM];
};

struct NB_NS_TEST
{
	int iBandlistOption[NB_IDX_B_SIZE]; //Band1,Band3,Band5,Band8,Band20,Band28
	int iChannel[NB_IDX_B_SIZE][CHANNEL_NUM];
	//float Power_Limit[NB_BAND_COUNT][2];
	float MaxPower_Limit[2];
	float MinPower_Limit[2];
	float EVM_Limit;
	float FreqErr_Limit[2];
	float Carrier_leakage_Limit;
	float Emission_Limit;
	float OBW_Limit;
	int SEM_Limit;
	int ACLR_Limit;
	float Ber_Limit;
};

struct NB_NS_TEST_RST_ALL
{
	float Ber[NB_IDX_B_SIZE][CHANNEL_NUM];
	float TX_Power[NB_IDX_B_SIZE][CHANNEL_NUM];
	int ACLR[NB_IDX_B_SIZE][CHANNEL_NUM];
	float EVM[NB_IDX_B_SIZE][CHANNEL_NUM];
	float FreqErr[NB_IDX_B_SIZE][CHANNEL_NUM];
	float OBW[NB_IDX_B_SIZE][CHANNEL_NUM];
	int SEM[NB_IDX_B_SIZE][CHANNEL_NUM];
	float MinPower[NB_IDX_B_SIZE][CHANNEL_NUM];
};

struct BTLE_NS_TEST_RST
{
	float f_TX_Power;
	float f_Ber;
	float f_Freq_Drift99;
	float f_Max_Drift_Rate;
	float f_Freq_Offset;
	float f_Initial_Freq_Drift;
};
const CString g_RFDeiviceName[NB_IDX_B_SIZE] = { "CMU200", "AG_E1960", "AG_E1968", "AG6601A", "MT8820" ,
"CMD55", "AG8922", "CMW500", "AG_E1987A", "AG_E1962B", "LP_IQXS", "CMW100", "LP_IQXM" };
const CString g_GSMBandName[NB_IDX_B_SIZE] = { "GSM850", "GSM900", "DCS", "PCS" };
const CString g_NBBandName[NB_IDX_B_SIZE] = { "Band1", "Band2", "Band3", "Band4", "Band5", "Band7", "Band8", "Band9", 
"Band10", "Band11", "Band12", "Band13", "Band14", "Band17", "Band18", "Band19", "Band20", "Band21", "Band22", "Band23", "Band24",
"Band25", "Band26", "Band27", "Band28", "Band30", "Band31", "Band65", "Band66", "Band68", "Band70", "Band71", "Band72", "Band73",
"Band74", "Band85", "Band86", "Band87", "Band88" };

class CRun
{
public:
	CRun();
	virtual ~CRun();
	bool UnRAR_File(CString sRAR_File, CString sUnRAR_Path, CString sPassword);
	void Load_ARG_QTI_SQL(QTI_PROG_ARG_SQL * strp_QTI_Arg_SQL);
protected:
	//CFile * m_LogFile;
	FILE * m_FileHandle;
	CStdioFile m_file;
	bool m_File_Open;
	
	void Init_Instrument_Struct();
	bool Get_WinRAR_Path(CString &csp_WinRAR_Path);
	bool RDA_2G_Get_RF_Performance_Data(CString sRFItem, CString Key1, CString Key2, CString Key3, CString& sValue);
	bool RDA_NB_Get_RF_Performance_Data(CString sRFItem, CString Key1, CString Key2, CString Key3, CString& sValue);
public:
	//���Գ�ʼ��
	bool Check_Temporary_Test_Status();//����Ƿ�����ʱ����
	int Calcu_IMEI_Checksum(CString sIMEI_14_Bits);
	bool IMEI_Number_Check(CString sIMEI);
	void MultiByte_To_WideChar(const char * cp_Char_8, wchar_t * wcp_WCHAR_16, int * ip_Len_16);
	bool WideChar_To_MultiByte(const wchar_t * wcp_WCHAR_16, char * cp_Char_8, int * ip_Len_8);
	CStringW CStrA2CStrW(const CStringA &cstrSrcA);
	CStringA CStrW2CStrA(const CStringW &cstrSrcW);
	bool ExtractStr_DouHao(CString sData, UINT nIndex, CString &sOutput);
	bool IS_W64(__out LPSYSTEM_INFO lpSystemInfo);
	int Get_GSM_FT_Errocode(int iBand, int iTestType);
	int Get_NB_FT_Errocode(int iBand, int iTestType);
	bool Calcu_Center_Freq_GSM(int i_G_Band, int i_ARFCN, int i_Up_Down_Link, float * dp_Center_Freq);
	bool Calcu_Channel_Freq_NBLot(int i_G_Band, int i_ARFCN, int i_Up_Down_Link, float & dp_Center_Freq, CString &sError);
	bool Calcu_Center_Freq_NBLot(int i_G_Band, float & dp_Center_Freq, CString &sError);
	bool Calcu_Freq_NBLot(int i_G_Band, float & dp_Low_Freq, float & dp_Mid_Freq, float & dp_High_Freq, CString &sError);
	//��ȡ���ߵ�Buffer Index
	bool Get_ANT_Type_List_Buff_Index(ANT_LIST_S str_Ant_List, EU_ANT_TYPE_INDEX eu_Ant_Type_Idx, int & oj_i_Ant_Buff_Index);
	/****************���������****************/
	void Copy_Product_Strcut_Golden();
	bool Calc_Golden_Vale_V1(CString &sGoldenData);
	bool Calc_Golden_Vale_V2(CString &sGoldenData);
	bool UnPack_Golden_SN(CString sSqlGoldenData, CString& sGSM_SN, CString& sNB_SN);
	bool Extract_Power_From_ChanGolden_Data(CString sSqlGoldenData, CString sChanInfo, double& db_RfTxData);
	bool Decode_SQL_Golden_Data(const wchar_t * wcp_Ref_Data_In_SQL);
	bool Compare_Golden_Current_Prodcut_Band();
	bool Encode_RF_Ref_Tx_Data_To_Str_V1(double d_Code_Key, int i_Band_And_Tx_Data_Quan, int * ip_Band_List, double * dp_RF_Tx_Data, CString & csp_Str_Data);
	//��ȡ���ANT+��ʽ+Band+T/R
	bool Format_Golden_Band_Info(EU_ANT_TYPE_INDEX eu_Ant_Sel, RF_MODEL eu_RFModel, int iBandName, int iLMH, int iTxRx, CString& sBandInfo);
	bool Encode_RF_Ref_Tx_Data_To_Str_V2(CString &csp_Str_Data);
	bool Decode_RF_Ref_Tx_Data_From_Str_V1(const char * wcp_Ref_Str_Data, double d_Code_Key, int * ip_Band_And_Tx_Data_Quan, int * ip_Band_List, double * dp_RF_Tx_Data, CString &sDecodeData);
	bool Get_2G_Band_Index(int ip_2G_Band_Name, int * i_2G_Band_Index, double *dp_Low_Limit, double *dp_High_Limit, double *dp_Target_Data);
	bool Get_2G_Band_Index(CString sRefBandName, int * i_2G_Band_Index);
	bool Get_NBIoT_Band_Index(int i_NBIoT_Band_Name, int * ip_NBIoT_Band_Index);
	bool Get_NBIoT_Band_Name(int i_NBIoT_Band_Index, int * ip_NBIoT_Band_Name);
	bool PACK_RF_REF_STR_NB(double * dp_Meas_Power_Data, int i_Power_Quan, int * ip_L_Band_List, CString &csp_Ref_Data_Str);
public:
	CGeneral_Global m_General_Global;
	//����GSM�Ĳ��Է���
	int m_i_RF_Test_Plan;
	//���Ʋ��������
	bool m_b_Show_FLag;
	//������Ƶı���
	bool m_b_Flag_Op_Enable; //�����Ƿ������д���־λ��exe�ļ��ڡ����߲��ԡ�ʱ����ֵΪtrue�����Խ���д��SN��־λ�����з����ԡ�ʱ����ֵΪfalse����д��SN��־λ��
	bool m_b_Fail_Stop_Enable; //����FT��������������˲������Ƿ�������²��ԡ�exe�ļ��ڡ����߲��ԡ�ʱ����ֵΪtrue�����ֲ�����ֹͣ�����з����ԡ�ʱ����ֵΪfalse�����ֲ���Ҳ�������ԡ�
	bool m_b_GPS_Test_Enable; //�����Ƿ���FT�в���GPS����Ӧ����ֵ��DLL�п���GPS�����Ƿ��������ԣ�true�������GPS��false��������GPS����һ����exe�ġ�onTime ��ʼ���Ĵ��������и�ֵ����
	//���Զ˿�
	CString mPortName;		//RF���Զ˿�URT
	//CString mGPSPortName;	//GPS���Զ˿�232 ���� Main
	//int m_iGPSEnablePort;	//GPS����ʹ�ܶ˿� ���� URT
	int m_iATPort;			//ATͨѶ���Զ˿�
	int m_iATBauDrate;		//ATͨѶ������
	//RDA������ر���
	unsigned int m_chipid;
	int maj_ver;
	int min_ver;
	//��������
	//TESTER_RF_OFFSET_S m_str_Instru_RF_Loss;
	double m_dr_GSM_RF_Loss[G_BAND_SIZE * 6];				//����ÿ��GSMƵ��index�ŵĵ͡��С����ŵ��������ֵ
	double m_dr_NBIoT_RF_Loss[NB_IDX_B_SIZE * 6];			//����ÿ��NB-IoTƵ�ε�index�ŵĵ͡��С����ŵ��������ֵ
	/*RDA GSMУ׼��Ŀ*/
	void SetInitValue();
	unsigned int m_CalibItemNum[4][5];
	unsigned int m_TestItemNum[4][10];
	unsigned int m_CoulingItemNum[4];
	//���Ͳ���
	CString m_sProdu_Name;
	PRODUCT_INFO m_Product_Info;//��Ʒ��Ϣ�����洢
	PRODUCT_INFO m_Golden_Info;
	READ_OCP_PARAMS_ARG* strp_Read_OCP_Params_Arg;
public:
	int m_iErrorCode;
	CString m_sErrorMessage;
	CString	m_sLogMessage;					//����log��ʱ�洢����

	CString m_LogSaveDir;
	CString m_DllWorkPath;
	CString m_SettingPath;
	CPower_Supply m_cla_PS;
	QTI_PROG_ARG * m_strp_QTI_ARG;
//	QTI_PROG_ARG_SQL * m_strp_QTI_ARG_SQL;

	RF_Instrument m_RFInstrument;
	PS_Instrument m_PSInstrument;
	UINT m_Device_Type;//Ag8960....
	//Golden Board Control
	bool m_b_GoldenBoard;
	QAPLCInstLibHandle m_QAPLC_Handel;				//Open-Short����У׼���;
	bool            m_bSQL_REF_Rtn_Flag;
public:
/****************���Գ�ʼ��****************/
	void Initial_Test_Info();
	void Initial_FT_TestRst_Info();
	void Initial_Produc_Info();
	void Clear_Write_Numbers();
	bool Test_Clear_All_Parameters();
	void Clear_Check_SW();
/****************�����ͷ�****************/
	void Test_Release_All();
/****************log��ӡ����****************/
	void Get_LogSave_Path();
	int Open_LogFile(CString sFileFullPath);//����log�ļ����·��,�ض���
	bool Close_FileLog();
	int Open_LogFile_V1(CString sFileFullPath);//����log�ļ����·��,�ļ�ָ��
	bool Close_FileLog_V1();
	void ShowTestMessage(CString sMsg, int iflag = 0, bool bLogOnly = false);
	void ShowRuningLog(CString sMsg, int iflag = 0);
	int Show_Test_Result(CString s_Name, double d_Low, double d_High, double d_Data);
	int Show_Test_Result_Check(const char * cp_Name, double d_Low, double d_High, double d_Data, bool RunLogShow = true);
	void Show_Title(const char * cp_Title);
	void Close_file();
	bool Upload_Test_Log();//�ϴ�����log�����Թ���
	bool Upload_Test_Log_V1();//�ϴ�����log�����Թ���
/****************2G ��������log����****************/
	void RDA_2G_GetCal_TestResult_FromFlag_V1(int iFlag);
	int RDA_2G_GetCal_TestResult_FromFlag_V2(int iFlag[]);
	bool RDA_2G_GetCal_TestResult_FromFlag_V3(int iFlag[]);
	int RDA_2G_Check_NST_Test_Result_V1(int PCL, bool iCheck);//0:max��1��min
	void Init_RDA_2G_NST_Result(GSM_NS_TEST_RST& str_NS_TEST_RST);
	int RDA_2G_Check_NST_Test_Result_V2(int iBandIndex, int iChannIndex, int iChannel, int PCL, GSM_NS_TEST_RST str_NS_TEST_RST, bool RunLogShow = true);//0:max��1��min
	//bool RDA_2G_NST_Fetch_RST_Again(GSM_NS_TEST_RST& str_NS_TEST_RST);
/****************NB ��������log����****************/
	int RDA_NB_GetCal_TestResult_FromFlag_V1(int iFlag[]);
	bool RDA_NB_GetCal_TestResult_FromFlag_V2(int iFlag[]);
	void Init_RDA_NB_NST_Result(NB_NS_TEST_RST& str_NS_TEST_RST);
	int RDA_NB_Check_NST_Test_Result_V1(bool iCheck);
	int RDA_NB_Check_NST_Test_Result_V2(int iBandIndex, int iChannIndex, int iBand, int iChannel, NB_NS_TEST_RST str_NS_TEST_RST, bool RunLogShow = true);
/****************��Դ���Բ���****************/
	bool m_bPS_Init;
	int PS_Initial();
	int PS_PowerOn();
	int PS_PowerOff();
	int PS_Release();
	bool PS_Reboot(bool bDelay = true);
	void PowerOnDelay(bool bReduceTime = false, int iReduceTime = 0);
	bool Test_Current(CString sTestItem, double dCurr_Low, double dCurr_High,int iLoop=1);
/****************ATͨѶ����****************/
	CComObj00 m_ATComPort;	//AT���Զ˿�
	bool m_b_ATComOpen;
	bool m_RDA_ComOpen;
	bool Open_ATComPort(UINT iComPort,UINT iBauDrate);
	bool Check_ATCommand(CString sCmd);
	bool Read_IMEI_Number(CString& sIMEI);
	bool Write_IMEI_Number(CString sIMEI);
	bool Read_IMEI2_Number(CString& sIMEI2);
	bool Write_IMEI2_Number(CString sIMEI2);
	bool Read_MEID_Number(CString& sMEID);
	bool Write_MEID_Number(CString sMEID);
	bool Read_BTAddr_Number(CString& sBT_Addr);
	bool Write_BTAddr_Number(CString sBT_Addr);
	bool Read_WIFIMAC_Number(CString& sWIFI_MAC);
	bool Write_WIFIMAC_Number(CString sWIFI_MAC);
	bool Read_SN_Number(CString& sSN);
	bool Write_SN_Number(CString sSN);
	bool Read_Golden_Number(CString& sGolden);
	bool Write_Golden_Number(CString sGolden);

	//������汾����������汾
	bool Read_FW_VER_QGMR(CString& sQGMR_VER);//QGMR���汾
	//������汾����ǩ����汾
	bool Read_FW_VER_ATI(CString& sATI_VER);//ATI���汾
	//����SIM����
	bool TEST_SIM_CARD();//AT+CPIN?
	bool Do_Write_BackUP();//д����ָ��AT+QPRTPARA=1 
	bool Do_Check_BackUP();//��鱸��ָ��AT+QPRTPARA?

	void Close_ATComPort();
	bool DO_Write_Number();
	bool DO_Check_Number();
	bool DO_Check_SW();
	bool DO_Write_Check_BKPara();
/****************���Ա�־λ****************/
	bool Check_SN_Length(CString sSN);
	bool Check_SN_Flag(UINT iModel, CString sSN);
	bool Get_Write_SN_Flag(UINT iModel, CString sSN, CString &sSN_Write);
	bool Check_SN_Flag_Test(UINT iModel);
	bool Write_SN_Flag_Test(UINT iModel);
/****************RDAͨ�ò��Բ���****************/
	void RDA_Test_Init();
	void RDA_Test_Release();
	int RDA_openPort();//У׼���Զ˿�URT
	bool RDA_Chip_Reboot();
	bool RDA_Load_Setting();
	int Calc_Band_Select_Count(UINT iRFMode, int iBand_Index_List[]);
	void Get_TxPower_List(UINT iRFMode, double* fTxPower_List);
	bool Check_IS_FX5125_PA();    //M25��M56����PA�ж�
/****************RDA���Ե�������****************/
	bool CAL_FT_RDA_LOAD_RUN_PATH(const wchar_t * wcp_ConfigFileFullName, const wchar_t * wcp_DllWorkPath);
	void CAL_FT_RDA_LOAD_ALL_DATA_V1(TESTER_CONFIG_S str_Tester_Config, TS_CONFIG_S str_TS_Config);
	void CAL_FT_RDA_LOAD_ALL_DATA_V2(TESTER_CONFIG_S str_PS_Config, TESTER_CONFIG_S str_Tester_Config, TS_CONFIG_S str_TS_Config, ANT_CFG_ALL_V2_S str_Ant_Config);
	bool RDA_LOAD_GOLDEN_NAME_AND_TYPE(const wchar_t * wcp_Produ_Name, int i_Produ_Type, int i_Produ_Ver);
	bool RDA_LOAD_PRODU_NAME_AND_TYPE(const wchar_t * wcp_Produ_Name, int i_Produ_Type, int i_Produ_Ver);
	void RDA_LOAD_PRODU_GSM_BAND_LIST(int * ip_GSM_Band_List, int i_GSM_Band_Quan);
	void RDA_LOAD_PRODU_GSM_BAND_LIST_Golden(int * ip_GSM_Band_List, int i_GSM_Band_Quan);
	void RDA_LOAD_PRODU_NB_BAND_LIST(int * ip_NB_Band_List, int i_NB_Band_Quan);
	bool DO_EXECUTE_Test_Init(UINT iModel);
	bool DO_EXECUTE_RF_Test_Init(UINT iMode, bool bClearLoss = false, bool bDoRF = true);
	bool DO_EXECUTE_RF_FT(bool bClearLoss = false,bool bDoRF = true);
	bool DO_EXECUTE_RF_Test(bool bGSM_Mid = false);
	void RF_CAL_FT_Test_End(bool b_PS_Power_Off = true, bool bRelease = true);
	bool RF_CAL_FT_RDA_DO_EXECUTE_RF_FT(bool b_PS_Power_Off_In_The_End, bool bRelease = true, bool bClearLoss = false, bool bDoRF = true);
	bool DO_EXECUTE_RF_CAL();
	bool RF_CAL_FT_RDA_DO_EXECUTE_RF_CAL(bool b_PS_Power_Off_In_The_End);
	bool RF_CAL_FT_RDA_DO_EXECUTE_RF_CAL_FT(bool b_PS_Power_Off_In_The_End, bool bDoFT = true);
	bool DO_CAL_LOSS_V2_S1(CStringW * csp_IMEI_In_REF, CStringW * csp_SN_In_REF);
	bool DO_CAL_LOSS_V2_S2_V1(CString sGlodenData_R, const wchar_t * wcp_Ref_Data_In_SQL, ANT_CFG_ALL_V2_S & str_Ant_Config);
	bool DO_CAL_LOSS_V2_S2_V2(CString sGlodenData_R, const wchar_t * wcp_Ref_Data_In_SQL, ANT_CFG_ALL_V2_S & str_Ant_Config);
	bool DO_MAKE_REF_V1(CStringW * csp_REF_ALL_SN);//�ϴ��������
	bool DO_MAKE_REF_V2(CStringW * csp_REF_ALL_SN);//�ϴ��������
	//ִ��RFУ׼����-ͨ��Open/Short��������������
	bool DO_CAL_LOSS_By_QAPLC(ANT_CFG_ALL_V2_S & str_Ant_Config);  //������еͷֱ𲹳�
	//ִ��QAPLC������У׼
	bool Do_QAPLC_Loss_Calibration(const vector<double> stlFreq_MHz, vector<double>* pstlPathLoss_dB);
	//����OCP��ANT����Ϣ��ȡ��ǰ������Ǳ��RF Port��
	bool Get_RF_Port_Number_By_OCP_ANT_ID(EU_ANT_TYPE_INDEX iAntType_OCP, int & iRFPortType);
/****************�������Ʋ���****************/
	int m_GPIB_INS;
	bool m_b_Inst_Release;
	int Instrument_Open();
	void Instrument_Release();
	bool Instrument_CheckError(int ud);
	bool InStrument_Query(CString sCmd, CString &sOutput);
	bool InStrument_Write(CString sCmd);
	void Find_Loss_Table_IQM(CString sData,CStringArray& TableArray);
	bool Instrument_Init_CAL(bool b_GSM_Test,bool b_NB_Test);
/****************GPS���Բ���****************/
	float m_fGPS_Loss;
	int m_iGPS_CN_Limit;
	bool m_b_GPS_Test_Flag;
	bool GPS_Test_Instrument_CMW(int iLevel = -130);//GSP ���������ź�ǿ��
	bool GPS_Test_Instrument_IQ(int iLevel = -120);
	bool GPS_Test_Instrument_Init(UINT iTimeDelay = 1000);
	bool GPS_QGNSSC_Enable();
	bool GPS_QGNSSC_Disable();
	bool GPS_Test_Enable();
	int RDA_GPS_Test(UINT iGPSPortName, UINT iTimeOut = 10000);
	bool GPS_Test_V1(UINT iGPSPort, UINT iTimeOut = 10000);
	bool GPS_Test_V2(UINT iTimeDelay = 100);
	bool DO_GPS_Test(UINT i_GPSTest_ComPort = 0);
/****************�������Բ���****************/
	float m_fBT_Loss;
	BTLE_NS_TEST_RST m_BTLE_NS_Rst;
	bool m_b_BTLE_Test_Flag;
	bool BTLE_Test_Instrument_CMW(int iChannel = 0, bool bTx = true, int iBurstType = 0, int iLevel = -70);//Basic Rate,Enhandced Data Rate,Low Energy
	bool BTLE_Test_Instrument_IQ(int iChannel = 0, bool bTx = true, int iBurstType = 0, int iLevel = -70);
	bool BTLE_Test_Instrument_Init(int iChannel = 0, bool bTx = true, int iBurstType = 0, int iLevel = -70,UINT iTimeDelay = 500);
	bool BTLE_Test_Instrument_Generate_ON_OFF(bool b_On = true);
	bool BTLE_Device_Open();
	bool BTLE_Device_Reset();
	bool BTLE_Set_Tx_Model(int iChannel, int iPayloadLength = 25, int iPatternType = 2);
	bool BTLE_Tx_Measure();
	bool BTLE_Tx_Rst_Check(int iChannel, bool bShow = true);
	bool BTLE_Set_Rx_Model(int iChannel);
	bool BTLE_Test_End(int & iRxPackets);
	bool BTLE_Rx_Rst_Check(int iRxPackets);
	bool DO_BTLE_Test();
	bool BT_Test_Check_Flag();
/****************2GУ׼���ղⲿ��****************/
	//GSM CPK��band�����֣�Ĭ���ǵ�һ��band
	int m_i2G_CPK_Band_Name;
	//GSM ���Կ��ر���
	bool m_bGSM_Test_Eanble;
	//GSM ���������
	int m_GSMTestOption[GSM_TEST_COUNT];
	//GSM ��������
	GSM2G_NS_TEST m_GSM_Test;
	//GSM ��������Խ��
	GSM2G_NS_TEST_RST_ALL m_GSM_Test_Rst;
	//void RDA_2G_CableLoss_Init();
	void RDA_2G_SetCableLoss_RF(bool bClearLoss = false);
	int RDA_2G_TestPrepare();
	int RDA_2G_Do_Calibration();
	void RDA_2G_NS_Test_Option(bool b_Do_Ber);
	void RDA_2G_NS_Init_Parameters();
	int RDA_2G_Do_NonSignaling_Test();
	int RDA_2G_Do_NonSignaling_Test_Mid();
/****************NBУ׼���ղⲿ��****************/
	//NB CPK��band�����֣�Ĭ���ǵ�һ��band
	int m_iNB_CPK_Band_Name;
	//NB ���Կ��ر���
	bool m_bNB_Test_Eanble;
	//NB ���������
	int m_NBTestOption[NB_TEST_COUNT];
	//NB ��������
	NB_NS_TEST m_NB_Test;
	//NB ��������Խ��
	NB_NS_TEST_RST_ALL m_NB_Test_Rst;
	//void RDA_NB_CableLoss_Init();
	void RDA_NB_SetCableLoss_RF(bool bClearLoss = false);
	int RDA_NB_TestPrepare();
	int RDA_NB_Do_Calibration();
	void RDA_NB_NS_Init_Parameters();
	int RDA_NB_Do_NonSignaling_Test();

/****************�ͻ�����****************/
	int m_i_Customer_Flag;
	CUSTOMER_ID m_Customer_ID;
	bool Check_Quectel_FW_Flag();
public:
	//��������ָ��
	friend class CAgilentTest;
	friend class CAgilentCalib;
	friend class CCmuCalib;
	friend class CCmuTest;
	friend class CAgilentE6607ACalib;
	friend class CAgilentE6607ANsft;
	friend class CAgilentE6640Calib;
	friend class CAgilentE6640Nsft;
	friend class CDT3110Calib;
	friend class CDTTest;
	friend class CCmw500Calib;
	friend class CCmw500Test;
	friend class CCmu200Nsft;
	friend class CAgilent8960Nsft;
	friend class CCmw500Nsft;
	friend class CCmw100Calib;
	friend class CCmw100Nsft;
	friend class CMT8821Calib;
	friend class CSP9010Calib;

	CAgilentCalib		*m_pAgicalib;
	CAgilent8960Nsft *m_pAgilent8960Nsft;
	CCmuCalib     *m_pCmucalib;
	CCmu200Nsft   *m_pCmu200Nsft;
	CAgilentE6607ACalib *m_pAgilentE6607ACalib;
	CAgilentE6640Calib *m_pAgilentE6640Calib;
	CAgilentE6640Nsft   *m_pAgilentE6640Nsft;
	CAgilentE6607ANsft  *m_pAgilentE6607ANsft;
	CDT3110Calib  *m_pDtCalib;
	CCmw500Calib  *m_pCmw500Calib;
	CCmw500Nsft   *m_pCmw500Nsft;
	CCmw100Calib  *m_pCmw100Calib;
	CCmw100Nsft   *m_pCmw100Nsft;
	CMT8821Calib  *m_pMT8821Calib;
	CMT8821Nsft  *m_pMT8821Nsft;
	CSP9010Calib  *m_pSP9010Calib;
	CSP9010Nsft  *m_pSP9010Nsft;
	CMT8870Calib  *m_pMT8870Calib;
	CMT8870Nsft   *m_pMT8870Nsft;
	CIQXStreamCalib  *m_pIQXStreamCalib;
	CIQXStreamNsft   *m_pIQXStreamNsft;
	CIQMStreamCalib  *m_pIQMStreamCalib;
	CIQMStreamNsft   *m_pIQMStreamNsft;

	CRda2GCalib *m_Rda2GcalibInstrument;
	CRda2GNsft *m_Rda2GNsftInstrument;

	TargetConnectionWrapper* m_conn;//2G����COM�����Ӿ��
	ChipInfo*     m_chip;

	void Check_SQL_Golden_Info(const wchar_t * wcp_Msg);

	private:
		
		 QTI_PROG_ARG_SQL * m_strp_QTI_ARG_SQL;

};

