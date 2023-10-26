#pragma once
//
#include "tlhelp32.h"
#include "atlbase.h"
#include <winioctl.h>//HD



//RF�ϡ����б�ʶ
#define RF_TX_UL_INPUT			0
#define RF_RX_DL_OUTPUT			1



//����ƽ̨
typedef enum tagEU_PF_IDX
{
	//
	PF_NDF = 0,		//δ����
	//
	PF_MTK,
	PF_QUALCOMM,
	PF_RDA,
	PF_GCT,
	PF_INTEL,
	PF_HISILICON,
	PF_ASR,
	//
	PF_COUNT
}EU_PF_IDX;



//BBоƬ
typedef enum tagEU_BB_CHIP_IDX
{
	//
	BB_NDF = 0,		//δ����
	//
	BB_MDM6200,		//��ͨ
	BB_QSC6270,		//��ͨ
	BB_XMM6255,		//Intel
	BB_XMM6250,		//Intel
	BB_MT6261,		//MTK
	BB_MDM9x15,		//��ͨ4GоƬ
	BB_MSM8909,		//��ͨ4GоƬ
	BB_MDM9x07,		//��ͨ4GоƬ
	BB_RDA8851,		//RDA
	BB_MSM8937,		//��ͨ4GоƬ
	BB_MSM8953,		//��ͨ4GоƬ
	BB_AR6003G,		//��ͨWiFiоƬ
	BB_QCA1023,		//��ͨWiFiоƬ
	BB_MDM9206,		//��ͨ4GоƬ
	BB_MDM9628,		//��ͨ4G����оƬ
	BB_HI2110,		//��˼Hi2110 NB-IoTоƬ
	BB_MSM8917,		//��ͨ4GоƬ
	BB_MDM9x40,		//��ͨ4GоƬ CAT-6
	BB_SDM450,		//��ͨ8953оƬ����Ƶ���Ͱ�
	BB_WCN3610,		//��ͨWiFiоƬ
	BB_WCN3660,		//��ͨWiFiоƬ
	BB_WCN3680,		//��ͨWiFiоƬ
	BB_MSM8905,		//��ͨ4GоƬ
	BB_MT2625,		//MTK NB-IoTоƬ
	BB_MT2503,		//MTK 2G+GPSоƬ
	BB_SDX20,		//��ͨ4GоƬ
	BB_RDA8955L,	//RDA��2GоƬ
	BB_ASR1802S,	//ASR��4GоƬ
	BB_MDM9150,		//��ͨоƬ ֻ��C-V2X
	//
	BB_CHIP_COUNT
}EU_BB_CHIP_IDX;



//GSMƵ�����к�
typedef enum EU_GSM_BAND_IDX
{
	G_BAND_GSM900 = 0,
	G_BAND_DCS1800,
	G_BAND_PCS1900,
	G_BAND_GSM850,
	G_BAND_COUNT
}EU_GSM_BAND_IDX;

//WCDMAƵ�����к�
typedef enum EU_WCDMA_BAND_IDX
{
	W_BAND_1 = 0,
	W_BAND_2,
	W_BAND_3,
	W_BAND_4,
	W_BAND_5,
	W_BAND_6,
	W_BAND_7,
	W_BAND_8,
	W_BAND_9,
	W_BAND_10,
	W_BAND_19,
	W_BAND_COUNT
}EU_WCDMA_BAND_IDX;

//cdma2000Ƶ�����кţ��ϣ�
typedef enum EU_CDMA2K_BAND_IDX
{
	C2K_BAND_800 = 0,
	C2K_BAND_1900,
	C2K_BAND_COUNT
}EU_CDMA2K_BAND_IDX;

//cdma2000Ƶ�����кţ��£�
typedef enum EU_C2K_BAND_IDX
{
	C2K_BC_0 = 0,
	C2K_BC_COUNT
}EU_C2K_BAND_IDX;

//LTEƵ�����к�
typedef enum EU_LTE_BAND_IDX
{
	L_BAND_1 = 0,
	L_BAND_2,
	L_BAND_3,
	L_BAND_4,
	L_BAND_5,
	L_BAND_7,
	L_BAND_8,
	L_BAND_12,
	L_BAND_17,
	L_BAND_20,
	L_BAND_38,
	L_BAND_39,
	L_BAND_40,
	L_BAND_41,
	L_BAND_13,
	L_BAND_18,
	L_BAND_19,
	L_BAND_25,
	L_BAND_26,
	L_BAND_28,
	L_BAND_34,
	L_BAND_14,
	L_BAND_29,//LTE��B29��B32��ֻ��DL����FDD��ֻ����CA������
	L_BAND_30,
	L_BAND_66,
	L_BAND_71,
	L_BAND_42,
	L_BAND_43,
	L_BAND_48,
	L_BAND_COUNT
}EU_LTE_BAND_IDX;

//TDƵ�����к�
typedef enum EU_TD_BAND_IDX
{
	TD_BAND_34 = 0,
	TD_BAND_39,
	TD_BAND_COUNT
}EU_TD_BAND_IDX;


//WiFiƵ��(FreqBand)���к�
typedef enum EU_WIFI_FB_IDX
{
	WIFI_FB_B24G = 0,	//2.4G
	WIFI_FB_B5G,		//5G
	WIFI_FB_COUNT
}EU_WIFI_FB_IDX;


//WiFi��׼(WiFi Standard)���к�
typedef enum EU_WIFI_STAN_IDX
{
	WIFI_STAN_80211A = 0,
	WIFI_STAN_80211B,
	WIFI_STAN_80211G,
	WIFI_STAN_80211N_20M,
	WIFI_STAN_80211N_40M,
	WIFI_STAN_80211N_5G_20M,
	WIFI_STAN_80211AC_20M,
	WIFI_STAN_80211AC_40M,
	WIFI_STAN_80211AC_80M,
	WIFI_STAN_COUNT
}EU_WIFI_STAN_IDX;


//�����汾���к�
typedef enum EU_BLU_VER_IDX
{
	BLU_VER_10_BR = 0,
	BLU_VER_20_EDR,
	BLU_VER_40_BLE,//Bluetooth Low Energy
	BLU_VER_COUNT
}EU_BLU_VER_IDX;


//��������ʽ���淶
#define FORMAT_GSM_S			0
#define FORMAT_WCDMA_S			1
#define FORMAT_C2K_S			2
#define FORMAT_GSM_NS			3
#define FORMAT_WCDMA_NS			4
#define FORMAT_TD_NS			5
#define FORMAT_LTE_NS			6
#define FORMAT_C2K_NS			7



//�ߡ��С����ŵ���ʶ
#define CH_ALL					-1
#define CH_LOW					0
#define CH_MID					1
#define CH_HIGH					2
#define CH_LOW_EX				3



//����δ���Ե�����ı�ʶ
#define ERROR_RTN_VALUE			9.91E9	//9.91E37



//ͨ�õġ�unsigned char��BUFF
typedef struct tagPKT_BUFF_S
{
	unsigned char * ucp_Buff;
	unsigned long ul_Total_Size;
	unsigned long ul_Data_Length;
}PKT_BUFF_S;



//��������ṹ��
typedef struct tagTESTER_RF_OFFSET_S
{
	double dr_GSM_RF_Loss[G_BAND_COUNT * 6];//����ÿ��GSMƵ�εĵ͡��С����ŵ�������ֵ
	double dr_W_RF_Loss[W_BAND_COUNT * 2];//����ÿ��WƵ�ε�index�Ŵ�����ֵ
	double dr_TD_RF_Loss[TD_BAND_COUNT * 2];//����ÿ��TDƵ�ε�index�Ŵ�����ֵ
	double dr_C2K_RF_Loss[C2K_BC_COUNT * 2];//����ÿ��cdma2000Ƶ�ε�index�Ŵ�����ֵ
	double dr_LTE_RF_Loss[L_BAND_COUNT * 2];//����ÿ��LTEƵ�ε�index�Ŵ�����ֵ
}TESTER_RF_OFFSET_S;



//�������ò����ṹ��
typedef struct tagTESTER_CONFIG_S
{
	int i_GPIB_Card_Numb;//����
	int i_GPIB_Card_Type;//������
	int i_GPIB_Addr_Tester;//������ַ
	int i_GPIB_Addr_PS;//��Դ��ַ
	bool b_Ctrl_PS;//�Ƿ�ص�Դ
	int i_Instru_Option;//���������ͺ� �� ���Զ�ʶ������
	CString cs_IP_SN;//��IP��SN��������
	int i_RF_Port_Numb;//������ָ��RF�˿�, ���߽���ѡ������RF�˿ں�(һ��Ϊ��RF�˿�����������)
	TESTER_RF_OFFSET_S str_Instru_RF_Loss;//������Ƶ������
}TESTER_CONFIG_S;



//����̨���ò���
typedef struct tagTS_CONFIG_S
{
	int i_Com_Port;		//DM ͨ�ſڣ�ͨ�ÿڣ�
	int i_Com_AT_Port;	//AT ͨ�ſ�
	int i_BR;			//������
	int i_TS_Curr_Type_Option;//��ǰ����(ѡ��)�ġ����Թ�λ���ࡢ��ʽ(����:GSM��WCDMA��2G+3G��2G+3G+4G��ѡ��)��
	bool b_Debug_Log_File;//���� debug log �ļ�
}TS_CONFIG_S;



//Ƶ�νṹ��
typedef struct tagBAND_LIST_S
{
	int ir_GSM_Band_List[G_BAND_COUNT + 1];//GSM��Ƶ��indexֵ���б���-1���������
	int ir_WCDMA_Band_List[W_BAND_COUNT + 1];//WCDMA��Ƶ��ֵ���б���-1���������
	int ir_C2K_Band_List[C2K_BC_COUNT + 1];//cdma2000��Ƶ��ֵ���б���-1���������
	int ir_TD_Band_List[TD_BAND_COUNT + 1];//TD��Ƶ��ֵ���б���-1���������
	int ir_LTE_Band_List[L_BAND_COUNT + 1];//LTE��Ƶ��ֵ���б���-1���������
	int i_GSM_Band_Quan;	//GSM��Ƶ�Ρ�����
	int i_WCDMA_Band_Quan;	//WCDMA��Ƶ�Ρ�����
	int i_C2K_Band_Quan;	//cdma2000��Ƶ�Ρ�����
	int i_TD_Band_Quan;		//TD��Ƶ�Ρ�����
	int i_LTE_Band_Quan;	//LTE��Ƶ�Ρ�����
}BAND_LIST_S;



//Ƶ��ʹ�ܿ���
typedef struct tagBAND_ENABLE_S
{
	int ir_GSM_Band_Enable[G_BAND_COUNT + 1];//GSMʹ���б���0���¡���������
	int ir_WCDMA_Band_Enable[W_BAND_COUNT + 1];//WCDMAʹ���б���0���¡���������
	int ir_C2K_Band_Enable[C2K_BC_COUNT + 1];//cdma2000ʹ���б���0���¡���������
	int ir_TD_Band_Enable[TD_BAND_COUNT + 1];//TDʹ���б���0���¡���������
	int ir_LTE_Band_Enable[L_BAND_COUNT + 1];//LTEʹ���б���0���¡���������
}BAND_ENABLE_S;



//���͡�ͨ�ò���������exe��������ƥ�䣩
typedef struct tagPRODU_PARAMS_GEN_S
{
	CString cs_Produ_Name;//������
	int i_Platform_Solution;//ƽ̨����
	int i_BB_Chip;//BBоƬ�ͺ�
	int ir_TS_Type_Seq[10];//���Թ�λ(Flag���)�б�, ���������б�
	BAND_LIST_S str_Band_List;//���͵�����Ƶ������
	CString cs_Produ_Params_File;//�����ļ�·��
}PRODU_PARAMS_GEN_S;



//Max number of drives assuming primary/secondary, master/slave topology
#define MAX_IDE_DRIVES			16



//
typedef struct _IDENTIFY_DATA
{
	USHORT GeneralConfiguration;            // 00 00
	USHORT NumberOfCylinders;               // 02  1
	USHORT Reserved1;                       // 04  2
	USHORT NumberOfHeads;                   // 06  3
	USHORT UnformattedBytesPerTrack;        // 08  4
	USHORT UnformattedBytesPerSector;       // 0A  5
	USHORT SectorsPerTrack;                 // 0C  6
	USHORT VendorUnique1[3];                // 0E  7-9
	USHORT SerialNumber[10];                // 14  10-19
	USHORT BufferType;                      // 28  20
	USHORT BufferSectorSize;                // 2A  21
	USHORT NumberOfEccBytes;                // 2C  22
	USHORT FirmwareRevision[4];             // 2E  23-26
	USHORT ModelNumber[20];                 // 36  27-46
	UCHAR  MaximumBlockTransfer;            // 5E  47
	UCHAR  VendorUnique2;                   // 5F
	USHORT DoubleWordIo;                    // 60  48
	USHORT Capabilities;                    // 62  49
	USHORT Reserved2;                       // 64  50
	UCHAR  VendorUnique3;                   // 66  51
	UCHAR  PioCycleTimingMode;              // 67
	UCHAR  VendorUnique4;                   // 68  52
	UCHAR  DmaCycleTimingMode;              // 69
	USHORT TranslationFieldsValid : 1;        // 6A  53
	USHORT Reserved3 : 15;
	USHORT NumberOfCurrentCylinders;        // 6C  54
	USHORT NumberOfCurrentHeads;            // 6E  55
	USHORT CurrentSectorsPerTrack;          // 70  56
	ULONG  CurrentSectorCapacity;           // 72  57-58
	USHORT CurrentMultiSectorSetting;       //     59
	ULONG  UserAddressableSectors;          //     60-61
	USHORT SingleWordDMASupport : 8;        //     62
	USHORT SingleWordDMAActive : 8;
	USHORT MultiWordDMASupport : 8;         //     63
	USHORT MultiWordDMAActive : 8;
	USHORT AdvancedPIOModes : 8;            //     64
	USHORT Reserved4 : 8;
	USHORT MinimumMWXferCycleTime;          //     65
	USHORT RecommendedMWXferCycleTime;      //     66
	USHORT MinimumPIOCycleTime;             //     67
	USHORT MinimumPIOCycleTimeIORDY;        //     68
	USHORT Reserved5[2];                    //     69-70
	USHORT ReleaseTimeOverlapped;           //     71
	USHORT ReleaseTimeServiceCommand;       //     72
	USHORT MajorRevision;                   //     73
	USHORT MinorRevision;                   //     74
	USHORT Reserved6[50];                   //     75-126
	USHORT SpecialFunctionsEnabled;         //     127
	USHORT Reserved7[128];                  //     128-255
} IDENTIFY_DATA, *PIDENTIFY_DATA;



//��Ʒ����
#define PRODU_TYPE_NDF				0
#define PRODU_TYPE_PCBA				1
#define PRODU_TYPE_MINIPCIE			2
#define PRODU_TYPE_TE_A				3
#define PRODU_TYPE_TE_C				4
#define PRODU_TYPE_TE_B				5
#define PRODU_TYPE_KIT				6



//��Ʒ�汾
#define PRODU_VER_NDF				0
#define PRODU_VER_STD				1
#define PRODU_VER_GW				2//����
#define PRODU_VER_NW				3//����
#define PRODU_VER_ING				4//ingenico
#define PRODU_VER_ZJXD				5//�н��Ŵ�
#define PRODU_VER_ZJ01				6//�н��Ŵ�
#define PRODU_VER_HIK				7
#define PRODU_VER_KT				8
#define PRODU_VER_SKT				9
#define PRODU_VER_CM				10



//CAT ( Category ֵ, �û��豸�ܹ�֧�ֵ�4GLTE���紫�����ʵĵȼ�, Ҳ����˵����4G�����ٶȵ�һ��������׼ )
typedef enum tagEU_LTE_CAT_IDX
{
	LTE_CAT_NDF = -1,
	LTE_CAT_0 = 0,
	LTE_CAT_1,
	LTE_CAT_2,
	LTE_CAT_3,
	LTE_CAT_4,
	LTE_CAT_5,
	LTE_CAT_6,
	LTE_CAT_7,
	LTE_CAT_8,
	LTE_CAT_9,
	LTE_CAT_10,
	LTE_CAT_M,
	LTE_CAT_NB,
	LTE_CAT_11,
	LTE_CAT_12,
	LTE_CAT_18,
	//
	LTE_CAT_COUNT
}EU_LTE_CAT_IDX;




//
