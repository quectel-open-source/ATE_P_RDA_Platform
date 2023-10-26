#pragma once
//
#include "tlhelp32.h"
#include "atlbase.h"
#include <winioctl.h>//HD



//RF上、下行标识
#define RF_TX_UL_INPUT			0
#define RF_RX_DL_OUTPUT			1



//方案平台
typedef enum tagEU_PF_IDX
{
	//
	PF_NDF = 0,		//未定义
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



//BB芯片
typedef enum tagEU_BB_CHIP_IDX
{
	//
	BB_NDF = 0,		//未定义
	//
	BB_MDM6200,		//高通
	BB_QSC6270,		//高通
	BB_XMM6255,		//Intel
	BB_XMM6250,		//Intel
	BB_MT6261,		//MTK
	BB_MDM9x15,		//高通4G芯片
	BB_MSM8909,		//高通4G芯片
	BB_MDM9x07,		//高通4G芯片
	BB_RDA8851,		//RDA
	BB_MSM8937,		//高通4G芯片
	BB_MSM8953,		//高通4G芯片
	BB_AR6003G,		//高通WiFi芯片
	BB_QCA1023,		//高通WiFi芯片
	BB_MDM9206,		//高通4G芯片
	BB_MDM9628,		//高通4G车载芯片
	BB_HI2110,		//海思Hi2110 NB-IoT芯片
	BB_MSM8917,		//高通4G芯片
	BB_MDM9x40,		//高通4G芯片 CAT-6
	BB_SDM450,		//高通8953芯片的主频降低版
	BB_WCN3610,		//高通WiFi芯片
	BB_WCN3660,		//高通WiFi芯片
	BB_WCN3680,		//高通WiFi芯片
	BB_MSM8905,		//高通4G芯片
	BB_MT2625,		//MTK NB-IoT芯片
	BB_MT2503,		//MTK 2G+GPS芯片
	BB_SDX20,		//高通4G芯片
	BB_RDA8955L,	//RDA的2G芯片
	BB_ASR1802S,	//ASR的4G芯片
	BB_MDM9150,		//高通芯片 只有C-V2X
	//
	BB_CHIP_COUNT
}EU_BB_CHIP_IDX;



//GSM频段序列号
typedef enum EU_GSM_BAND_IDX
{
	G_BAND_GSM900 = 0,
	G_BAND_DCS1800,
	G_BAND_PCS1900,
	G_BAND_GSM850,
	G_BAND_COUNT
}EU_GSM_BAND_IDX;

//WCDMA频段序列号
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

//cdma2000频段序列号（老）
typedef enum EU_CDMA2K_BAND_IDX
{
	C2K_BAND_800 = 0,
	C2K_BAND_1900,
	C2K_BAND_COUNT
}EU_CDMA2K_BAND_IDX;

//cdma2000频段序列号（新）
typedef enum EU_C2K_BAND_IDX
{
	C2K_BC_0 = 0,
	C2K_BC_COUNT
}EU_C2K_BAND_IDX;

//LTE频段序列号
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
	L_BAND_29,//LTE的B29和B32，只有DL，是FDD，只有做CA才有用
	L_BAND_30,
	L_BAND_66,
	L_BAND_71,
	L_BAND_42,
	L_BAND_43,
	L_BAND_48,
	L_BAND_COUNT
}EU_LTE_BAND_IDX;

//TD频段序列号
typedef enum EU_TD_BAND_IDX
{
	TD_BAND_34 = 0,
	TD_BAND_39,
	TD_BAND_COUNT
}EU_TD_BAND_IDX;


//WiFi频段(FreqBand)序列号
typedef enum EU_WIFI_FB_IDX
{
	WIFI_FB_B24G = 0,	//2.4G
	WIFI_FB_B5G,		//5G
	WIFI_FB_COUNT
}EU_WIFI_FB_IDX;


//WiFi标准(WiFi Standard)序列号
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


//蓝牙版本序列号
typedef enum EU_BLU_VER_IDX
{
	BLU_VER_10_BR = 0,
	BLU_VER_20_EDR,
	BLU_VER_40_BLE,//Bluetooth Low Energy
	BLU_VER_COUNT
}EU_BLU_VER_IDX;


//“网络制式”规范
#define FORMAT_GSM_S			0
#define FORMAT_WCDMA_S			1
#define FORMAT_C2K_S			2
#define FORMAT_GSM_NS			3
#define FORMAT_WCDMA_NS			4
#define FORMAT_TD_NS			5
#define FORMAT_LTE_NS			6
#define FORMAT_C2K_NS			7



//高、中、低信道标识
#define CH_ALL					-1
#define CH_LOW					0
#define CH_MID					1
#define CH_HIGH					2
#define CH_LOW_EX				3



//仪器未测试到结果的标识
#define ERROR_RTN_VALUE			9.91E9	//9.91E37



//通用的“unsigned char”BUFF
typedef struct tagPKT_BUFF_S
{
	unsigned char * ucp_Buff;
	unsigned long ul_Total_Size;
	unsigned long ul_Data_Length;
}PKT_BUFF_S;



//仪器线损结构体
typedef struct tagTESTER_RF_OFFSET_S
{
	double dr_GSM_RF_Loss[G_BAND_COUNT * 6];//依据每个GSM频段的低、中、高信道存放损耗值
	double dr_W_RF_Loss[W_BAND_COUNT * 2];//依据每个W频段的index号存放损耗值
	double dr_TD_RF_Loss[TD_BAND_COUNT * 2];//依据每个TD频段的index号存放损耗值
	double dr_C2K_RF_Loss[C2K_BC_COUNT * 2];//依据每个cdma2000频段的index号存放损耗值
	double dr_LTE_RF_Loss[L_BAND_COUNT * 2];//依据每个LTE频段的index号存放损耗值
}TESTER_RF_OFFSET_S;



//仪器配置参数结构体
typedef struct tagTESTER_CONFIG_S
{
	int i_GPIB_Card_Numb;//卡号
	int i_GPIB_Card_Type;//卡类型
	int i_GPIB_Addr_Tester;//仪器地址
	int i_GPIB_Addr_PS;//电源地址
	bool b_Ctrl_PS;//是否控电源
	int i_Instru_Option;//具体仪器型号 或 可自动识别仪器
	CString cs_IP_SN;//用IP或SN访问仪器
	int i_RF_Port_Numb;//仪器的指定RF端口, 工具界面选择输入RF端口号(一般为多RF端口仪器的设置)
	TESTER_RF_OFFSET_S str_Instru_RF_Loss;//仪器各频段线损
}TESTER_CONFIG_S;



//测试台配置参数
typedef struct tagTS_CONFIG_S
{
	int i_Com_Port;		//DM 通信口（通用口）
	int i_Com_AT_Port;	//AT 通信口
	int i_BR;			//波特率
	int i_TS_Curr_Type_Option;//当前运行(选择)的“测试工位种类、制式(例如:GSM、WCDMA、2G+3G、2G+3G+4G等选择)”
	bool b_Debug_Log_File;//保存 debug log 文件
}TS_CONFIG_S;



//频段结构体
typedef struct tagBAND_LIST_S
{
	int ir_GSM_Band_List[G_BAND_COUNT + 1];//GSM“频段index值”列表，“-1”代表结束
	int ir_WCDMA_Band_List[W_BAND_COUNT + 1];//WCDMA“频段值”列表，“-1”代表结束
	int ir_C2K_Band_List[C2K_BC_COUNT + 1];//cdma2000“频段值”列表，“-1”代表结束
	int ir_TD_Band_List[TD_BAND_COUNT + 1];//TD“频段值”列表，“-1”代表结束
	int ir_LTE_Band_List[L_BAND_COUNT + 1];//LTE“频段值”列表，“-1”代表结束
	int i_GSM_Band_Quan;	//GSM“频段”数量
	int i_WCDMA_Band_Quan;	//WCDMA“频段”数量
	int i_C2K_Band_Quan;	//cdma2000“频段”数量
	int i_TD_Band_Quan;		//TD“频段”数量
	int i_LTE_Band_Quan;	//LTE“频段”数量
}BAND_LIST_S;



//频段使能控制
typedef struct tagBAND_ENABLE_S
{
	int ir_GSM_Band_Enable[G_BAND_COUNT + 1];//GSM使能列表，“0以下”代表不测试
	int ir_WCDMA_Band_Enable[W_BAND_COUNT + 1];//WCDMA使能列表，“0以下”代表不测试
	int ir_C2K_Band_Enable[C2K_BC_COUNT + 1];//cdma2000使能列表，“0以下”代表不测试
	int ir_TD_Band_Enable[TD_BAND_COUNT + 1];//TD使能列表，“0以下”代表不测试
	int ir_LTE_Band_Enable[L_BAND_COUNT + 1];//LTE使能列表，“0以下”代表不测试
}BAND_ENABLE_S;



//机型“通用参数”（与exe界面设置匹配）
typedef struct tagPRODU_PARAMS_GEN_S
{
	CString cs_Produ_Name;//机型名
	int i_Platform_Solution;//平台方案
	int i_BB_Chip;//BB芯片型号
	int ir_TS_Type_Seq[10];//测试工位(Flag相关)列表, 测试属性列表
	BAND_LIST_S str_Band_List;//机型的完整频段数据
	CString cs_Produ_Params_File;//参数文件路径
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



//产品类型
#define PRODU_TYPE_NDF				0
#define PRODU_TYPE_PCBA				1
#define PRODU_TYPE_MINIPCIE			2
#define PRODU_TYPE_TE_A				3
#define PRODU_TYPE_TE_C				4
#define PRODU_TYPE_TE_B				5
#define PRODU_TYPE_KIT				6



//产品版本
#define PRODU_VER_NDF				0
#define PRODU_VER_STD				1
#define PRODU_VER_GW				2//国网
#define PRODU_VER_NW				3//南网
#define PRODU_VER_ING				4//ingenico
#define PRODU_VER_ZJXD				5//中交信达
#define PRODU_VER_ZJ01				6//中交信达
#define PRODU_VER_HIK				7
#define PRODU_VER_KT				8
#define PRODU_VER_SKT				9
#define PRODU_VER_CM				10



//CAT ( Category 值, 用户设备能够支持的4GLTE网络传输速率的等级, 也可以说成是4G网络速度的一个技术标准 )
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
