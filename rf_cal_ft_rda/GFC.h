#pragma once
//
#include "Global_Header.h"
#include "tlhelp32.h"
#include "atlbase.h"
#include <winioctl.h>//HD
#include <vector>
#include <math.h>



//RF上、下行标识
#define RF_TX_UL_INPUT				0
#define RF_RX_DL_OUTPUT				1


//Division Dual 双工
#define DD_NDF						0
#define DD_FDD						1
#define DD_TDD						2
//WCDMA测试项目
typedef enum EU_WCDMA_FT_ITEM_IDX
{
	WFI_MAX_POWER = 0,
	WFI_MIN_POWER,
	WFI_SEM,
	WFI_EVM,
	WFI_FREQ_ERR,
	WFI_PCDE,
	WFI_OBW,
	WFI_PHASE_DISC,
	WFI_ACLR_M_10,
	WFI_ACLR_M_5,
	WFI_ACLR_P_5,
	WFI_ACLR_P_10,
	WFI_BER,
	WFI_ILPC_E_MAX,
	WFI_ILPC_F_MAX,
	WFI_ILPC_E_MIN,
	WFI_ILPC_F_MIN,
	WFI_MAX_CALL_CURR,
	WFI_SENS,
	WFI_COUNT
}EU_WCDMA_FT_ITEM_IDX;

//cdma2000测试项目
typedef enum EU_CDMA2K_FT_ITEM_IDX
{
	CFI_OLPC_PWR_25 = 0,
	CFI_OLPC_PWR_65,
	CFI_RXQ_FER,
	CFI_CONF_LEV,
	CFI_WAVE_QLTY,
	CFI_FREQ_ERR,
	CFI_TIME_ERR,
	CFI_MAX_PWR,
	CFI_MIN_PWR,
	CFI_OLTR_1UP,
	CFI_OLTR_2DOWN,
	CFI_OLTR_3DOWN,
	CFI_OLTR_4UP,
	CFI_GOUT,
	CFI_SPEC_PWR_N4,
	CFI_SPEC_PWR_N3,
	CFI_SPEC_PWR_N2,
	CFI_SPEC_PWR_N1,
	CFI_SPEC_PWR_P1,
	CFI_SPEC_PWR_P2,
	CFI_SPEC_PWR_P3,
	CFI_SPEC_PWR_P4,
	CFI_COUNT
}EU_CDMA2K_FT_ITEM_IDX;

typedef enum EU_C2K_NS_FT_ITEM_IDX
{
	CNFI_MAX_PWR = 0,
	CNFI_MIN_PWR,
	CNFI_WAVE_QLTY,
	CNFI_FREQ_ERR,
	CNFI_TIME_ERR,
	CNFI_IQ_OO,
	CNFI_PE_RMS,
	CNFI_EVM_RMS,
	CNFI_ACPR_ADJ_L,
	CNFI_ACPR_ADJ_H,
	CNFI_ACPR_ALT_L,
	CNFI_ACPR_ALT_H,
	CNFI_COUNT
}EU_C2K_NS_FT_ITEM_IDX;

//LTE非信令测试项目
typedef enum EU_LTE_NS_FT_ITEM_IDX
{
	LNFI_TX_PWR_AVG = 0,
	LNFI_TX_PWR_MAX,
	LNFI_TX_PWR_MIN,
	LNFI_EVM_AVG,
	LNFI_EVM_MAX,
	LNFI_IQ_OO,
	LNFI_FREQ_ERR,
	LNFI_SPEC_FLAT,
	LNFI_MARGIN,
	LNFI_OBW,
	LNFI_SLOT_PWR,
	LNFI_SEM,
	LNFI_ACLR_N2,
	LNFI_ACLR_N1,
	LNFI_ACLR_EN1,
	LNFI_ACLR_EP1,
	LNFI_ACLR_P1,
	LNFI_ACLR_P2,
	LNFI_ACLR_EPWR,
	LNFI_COUNT
}EU_LTE_NS_FT_ITEM_IDX;

//TD非信令测试项目
typedef enum EU_TD_NS_FT_ITEM_IDX
{
	TNFI_TX_PWR_AVG = 0,
	TNFI_TX_MIN_PWR,
	TNFI_PVT,
	TNFI_FREQ_ERR,
	TNFI_PE,
	TNFI_IQ_OO,
	TNFI_OBW,
	TNFI_EVM,
	TNFI_PCDE,
	TNFI_SEM,
	TNFI_ACLR_L2,
	TNFI_ACLR_L1,
	TNFI_ACLR_R1,
	TNFI_ACLR_R2,
	TNFI_COUNT
}EU_TD_NS_FT_ITEM_IDX;

//GSM非信令测试项目
typedef enum EU_GSM_NS_FT_ITEM_IDX
{
	GNFI_TX_PWR = 0,
	GNFI_PVT,
	GNFI_FREQ_ERR,
	GNFI_PE_RMS,
	GNFI_PE_PEAK,
	GNFI_SPEC_SWIT,
	GNFI_SPEC_MOD,
	GNFI_COUNT
}EU_GSM_NS_FT_ITEM_IDX;

//WiFi非信令测试项目
typedef enum EU_WIFI_NS_FT_ITEM_IDX
{
	WIFINFI_TX_PWR_AVG = 0,
	WIFINFI_EVM_AVG,
	WIFINFI_FREQ_ERR,
	WIFINFI_TRANS_SPEC_MASK,
	WIFINFI_RX_PER,
	WIFINFI_COUNT
}EU_WIFI_NS_FT_ITEM_IDX;


//Bluetooth非信令测试项目
typedef enum EU_BLU_NS_FT_ITEM_IDX
{
	BLUNFI_BR_FREQ_DEV_DELTA_F1_AVG = 0,
	BLUNFI_BR_FREQ_DEV_DELTA_F2_AVG,
	BLUNFI_BR_FREQ_DEV_DELTA_F2_MAX,
	BLUNFI_EDR_AVG_DEVM,
	BLUNFI_EDR_PEAK_DEVM,
	BLUNFI_EDR_P99_DEVM,
	BLUNFI_EDR_INIT_FREQ_ERR,
	BLUNFI_EDR_BLOCK_FREQ_ERR,
	BLUNFI_EDR_RELA_PWR,
	BLUNFI_BR_PWR_AVG,
	BLUNFI_BR_FREQ_ACCU,
	BLUNFI_BR_FREQ_DRIFT,
	BLUNFI_BLE_PWR_AVG,
	BLUNFI_BLE_FREQ_ACCU,
	BLUNFI_BLE_FREQ_DEV_DELTA_F1_AVG,
	BLUNFI_BLE_FREQ_DEV_DELTA_F2_AVG,
	BLUNFI_BLE_FREQ_DEV_DELTA_F2_P99,
	BLUNFI_BLE_FREQ_DRIFT,
	BLUNFI_BLE_MAX_DRIFT_RATE,
	BLUNFI_BLE_FREQ_OFFSET,
	BLUNFI_BLE_INIT_FREQ_DRIFT,
	BLUNFI_BR_RX_BER,
	BLUNFI_EDR_RX_BER,
	BLUNFI_BLE_RX_BER,
	BLUNFI_COUNT
}EU_BLU_NS_FT_ITEM_IDX;


//C-V2X非信令测试项目
typedef enum EU_CV2X_NS_FT_ITEM_IDX
{
	CV2X_TX_MAX_POWER = 0,
	CV2X_FREQ_ERR,
	CV2X_EVM_AVG,
	CV2X_EVM_MAX,
	CV2X_ACLR_N2,
	CV2X_ACLR_N1,
	CV2X_ACLR_EN1,
	CV2X_ACLR_EP1,
	CV2X_ACLR_P1,
	CV2X_ACLR_P2,
	CV2X_ACLR_EPWR,
	CV2X_COUNT
}EU_CV2X_NS_FT_ITEM_IDX;
//NB-IoT 的 Subcarrier Spacing
#define NB_SCSP_S3K75				0//3.75 kHz
#define NB_SCSP_S15K				1//15 kHz


//NB-IoT 的 Modulation Scheme Used By The Measured Signal（与高通代码中的定义相同）
#define NB_MSCH_BPSK				0//0 = BPSK
#define NB_MSCH_QPSK				1//1 = QPSK


//NB-IoT 的 Number Of SubCarrier
#define NB_SINGLE_TONE				1
#define NB_MULTI_TONE_3				3
#define NB_MULTI_TONE_6				6
#define NB_MULTI_TONE_12			12



//方案平台
typedef enum tagEU_PF_IDX
{
	//
	PF_NDF = 0,		//未定义
	//
	PF_MTK,			//MTK
	PF_QUALCOMM,	//高通
	PF_RDA,			//RDA
	PF_GCT,			//GCT
	PF_INTEL,		//Intel
	PF_HISILICON,	//海思 Hisilicon
	PF_ASR,			//ASR
	PF_REALTEK,		//Realtek
	PF_SPREADTRUM,	//展锐 Spreadtrum
	PF_EIGENCOMM,	//移芯 Eigencomm
	PF_TI,			//德州仪器 Texas Instruments
	PF_XINYI,		//芯翼信息科技(上海)有限公司
	PF_ALTAIR,		//Sony Altair
	PF_BEKEN,			//博通集成电路（上海）股份有限公司
	PF_CYPRESS,			//赛普拉斯 Cypress 半导体公司
	PF_SILICON_LABS,	//芯科科技(Silicon Labs)
	PF_AMLOGIC,			//Amlogic 晶晨半导体(上海)股份有限公司
	PF_IONA,			//IONA芯片平台, Orbcomm平台商
	PF_MORNINGCORE,		//宸芯科技有限公司是我国行业通信终端SoC芯片专业领域的企业
	PF_ESWIN,			//北京奕斯伟科技集团有限公司（简称“ESWIN”），是一家集成电路领域产品和服务提供商，核心业务涵盖芯片与方案、硅材料、生态链投资孵化三大领域
	PF_ICOMM,			//南方硅谷?iComm, 深圳市南方硅谷半导体股份有限公司2018年成立于深圳市南山区，是一家全球化的专业无晶圆半导体公司，国家高新技术企业
	PF_ROCKCHIP,		//Rockchip 瑞芯微, 瑞芯微电子股份有限公司, 专注于集成电路设计与研发，目前已发展为领先的物联网（IoT）及人工智能物联网（AIoT）处理器芯片企业
	PF_MURATA,			//村田 Murata Electronics
	PF_AICSEMI,			//AICSEMI 爱科微半导体(上海)有限公司
	PF_MORSE_MICRO,		//摩尔斯微(Morse Micro)是澳大利亚的无线集成电路解决方案公司
	PF_NXP,				//恩智浦半导体公司，NXP Semiconductors。由AVNET(安富利)作第三方代理支持。
	PF_QUECTEL,			//上海移远，自制产品默认平台定义
	PF_AUTOTALKS,		//Autotalks 是一家专注于车辆间通信系统（V2X）开发的技术公司。Autotalks is a fabless semiconductor company devoted to vehicle-to-everything (V2X) communications for manned and autonomous vehicles.
	PF_FREQCHIP,		//上海富芮坤微电子有限公司成立于2014年，是一家致力于射频集成电路芯片的设计、研发及产品销售的高新技术企业。现有产品线：双模蓝牙音频SoC芯片和超低功耗（BLE）蓝牙 SoC芯片。
	PF_QORVO,			//Qorvo 威讯联合半导体有限公司(Qorvo=RFMD+Triquint), 是一家设计、开发及生产“射频”集成电路产品的美国独资企业，公司为移动产品、基础设施等方面提供标准型和定制型产品解决方案以及战略制造服务。
	PF_BESTECHNIC,		//Bestechnic 恒玄科技主要从事智能音频SoC芯片的研发，设计与销售，为客户提供AIoT场景下具有语音交互能力的边缘智能主控平台芯片，产品广泛应用于智能蓝牙耳机，Type-C耳机，智能音箱等智能终端产品。
	PF_ST,				//ST 意法半导体
	PF_NEWRADIO,		//纽瑞芯科技(NewRadio Tech)于2016年12月由海归集成电路专家联合创办，在北京、深圳、苏州等地均设有研发中心。公司专注于通讯芯片的核心技术研发及产业化，立足中国本土，致力于引领下一代无线通讯技术和定位系统发展。
	PF_HWA,				//北京华力创通股份有限公司（Hwa Create Company）。移远是与“国智天通”公司签的技术协议。
	PF_XINCOMM,			//Xincomm Communications Co., Ltd.
	PF_ONMICRO,			//OnMicro 昂瑞微 是一家深耕射频前端和无线通信领域、多元化前瞻布局的复合型芯片设计公司。公司总部位于北京。
	PF_XHSC,			//XHSC 小华半导体有限公司是世界财富500强中国电子信息产业集团有限公司（CEC）旗下集成电路业务平台华大半导体有限公司的核心子公司。
	PF_TG,				//平头哥半导体有限公司于2018年9月宣布成立，是阿里巴巴集团的全资半导体芯片业务主体。平头哥拥有端云一体全栈产品系列，涵盖数据中心芯片、IoT芯片等，实现芯片端到端设计链路全覆盖。
	PF_INFINEON,		//Infineon 英飞凌是全球领先的半导体公司，英飞凌收购了 CYPRESS 的相关业务。
	PF_NOVATEK,			//联咏（NOVATEK）科技为台湾 IC 设计领导厂商，从事产品设计，研发及销售。主要产品为全系列的平面显示屏幕驱动 IC，以及行动装置及消费性电子产品上应用之数字影音，多媒体单芯片产品解决方案。
	PF_NATIONSTECH,		//Nationstech 国民技术股份有限公司（简称：国民技术），是MCU、安全芯片领先企业和国家高新技术企业。主营产品包括：MCU、安全芯片、可信计算芯片、电池管理芯片、蓝牙芯片、RCC创新产品等，广泛应用于物联网、工业控制、电机控制与驱动、电池及能源管理、汽车电子、智能家居家电、消费电子、智能表计、医疗电子、安防、生物识别、通讯、传感器，以及网络安全认证、电子银行、电子证照、移动支付与移动安全等应用方向。
	PF_NORDIC,			//Nordic Semiconductor 是一家挪威无晶圆厂半导体公司，专注于为物联网（IoT）提供支持的无线通信技术。
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
	BB_QCA6564,		//高通WiFi芯片(车规平台)
	BB_SDM660,		//高通4G芯片
	BB_RDA8908A,	//RDA的NB-IoT芯片
	BB_RDA8909B,	//RDA的2G+NB-IoT芯片
	BB_MT2621,		//MTK的2G+NB-IoT芯片
	BB_SA415M,		//高通车规4G+V2X基线
	BB_SDX24,		//高通4G芯片, A7 at 1.5GHz, 256KB L2, 应用于笔电, LTE-A/车载
	BB_MDM9205,		//高通4G芯片, LTE Cat-M / Cat-NB
	BB_SDX55,		//高通 5G 芯片, 工规
	BB_RTL8189,		//Realtek平台WiFi芯片
	BB_QM215,		//高通4G智能模块(替代MSM8909)
	BB_QCM2150,		//高通4G智能模块(替代MSM8909)
	BB_SA515M,		//高通 5G NR 芯片, SA515M是车规平台, 对应的工规SDX55平台
	BB_WCN3990,		//高通WiFi芯片
	BB_ASR3601,		//ASR的ASR1802S低成本4G芯片
	BB_SL8541E,		//展锐(Spreadtrum)4G智能模块芯片
	BB_HI2152,		//海思HI2152 4G非智能模块芯片
	BB_QCA6391,		//高通 WiFi 蓝牙 芯片
	BB_EC616,		//移芯 超低功耗NB-IoT单模芯片
	BB_ASR1601,		//ASR的4G芯片 CAT-1
	BB_CC1200,		//TI 低功耗高性能射频收发器
	BB_HI9500,		//海思 5G 芯片
	BB_ASR1802SL,	//ASR的4G芯片的Linux版本
	BB_ASR1826,		//ASR的4G芯片, LTE CAT-6
	BB_HI2115,		//海思Hi2115 NB-IoT芯片
	BB_QCA6696,		//高通车规级WiFi/BT芯片（支持802.11 ax WiFi, 支持蓝牙 BT 5.1）
	BB_SDA845,		//高通系统级芯片(SoC: System-on-a-Chip), SDA不带modem, 即没有蜂窝移动网络
	BB_UDX710,		//展锐 Spreadtrum 5G平台 工规
	BB_QCX212,		//高通 NB-IoT SoC chipset, Category NB2, 2-HARQ
	BB_SM6115,		//高通 4G 芯片, Snapdragon 662
	BB_QTM527,		//高通 5G mmWave antenna module
	BB_EC617,		//上海移芯 超低成本、超低功耗和超高集成度NB-IoT SoC 芯片，完全支持3GPP Rel14 NB-IoT 标准
	BB_WCN3980,		//高通WiFi芯片
	BB_ESP8285,		//乐鑫WiFi芯片
	BB_UIS8910DM,	//展锐 advanced system-on-chip solution integrated CAT1bis/GSM/GPRS modems
	BB_UIS8581,		//展锐 智能模块芯片 with embedded TD-LTE, LTE FDD, TDSCDMA/HSPA(+), WCDMA/HSPA(+) and GSM/GPRS/EDGE to supportDual SIM Dual Standbyup to LTE+LTE
	BB_XY1100,		//芯翼 适用于低速 IoT 场景的高性能，高集成度的 SOC 芯片。该芯片完全兼容 3GPP TS 36.211 协议
	BB_HI2120,		//海思Hi2120 NB2 NB-IoT芯片
	BB_MT2731,		//MTK 2G/3G/4G 车规平台芯片
	BB_WCN3988,		//高通WiFi芯片
	BB_ALT1250,		//Sony Altair eMTC (CAT M), NB IoT (CAT NB1 / NB2)
	BB_QCA6595,		//高通 MU-MIMO WiFi/BT 5.1 Automotive Dual-MAC Combo Chip for Automotive Infotainment and Telematics applications
	BB_ASR1603,		//ASR的4G芯片 CAT-1, 1601 + Flash 封装
	BB_QCA1064,		//高通 WiFi 蓝牙 芯片
	BB_MT6880,		//MTK 5G 芯片, T700 套片
	BB_MT6890,		//MTK 5G 芯片, T750 套片
	BB_WCN3615,		//高通WiFi芯片
	BB_EC616S,		//上海移芯 超低成本、超低功耗和超高集成度 NB-IoT SoC 芯片, 完全支持3GPP Rel14 NB-IoT 标准
	BB_QCM6125,		//高通 智能模块 Qualcomm Snapdragon 600 series processor and LTE modem. LTE Cat12/Cat13 (FDD and TDD)
	BB_UIS8811,		//展锐 advanced system-on-chip solution integrated NB-IoT modems. The UIS8811 integrates RF transceiver for low cost.
	BB_SDX12,		//高通 4G 芯片, 高通MDM9x50 cost down 平台, Sixthgeneration LTE multimode modem, 14nm system on chip (SoC).
	BB_QCM2290,		//高通 智能模块 4G芯片
	BB_BK7231,		//集成蓝牙双模5.1和WiFi802.11n的 WiFi SOC 芯片
	BB_SDX62,		//高通 5G 芯片, 工规, SDX55的下一代, Provides Higher Performance mmWave and Features for Global Deployment.
	BB_QCA2064,		//高通 highly integrated System-On-Chip (SoC) supporting 802.11ax Wi-Fi and Bluetooth (BT) Milan. It is part of the QCA206x family of SoC’s supporting operation on 2.4 GHz and 5 GHz.
	BB_SM4350,		//高通 5G 智能芯片, the new generation Qualcomm Snapdragon 400 series processor with integrated 5G modem.
	BB_ASR1803S,	//ASR的4G芯片 CAT-4, ASR1802S Costdown 芯片, RTOS版本
	BB_MT2735,		//MTK 5G 芯片, supporting NR Sub6, LTE Cat19 4x4 MIMO
	BB_WCN3991,		//高通WiFi芯片
	BB_SL8521E,		//展锐(Spreadtrum)4G智能模块芯片, 智能模块系统是Linux, Android4.4/Linux
	BB_QCM6490,		//高通 5G Smart 车载智能模块, 包含5G版本, 用于车机和Tbox整合的一体机. including global multi-gigabit 5G mmW/Sub-6 GHz and WiFi 6E
	BB_QCA9377,		//高通 WLAN/Bluetooth 芯片, a single-die wireless local area network (WLAN) and Bluetooth combination solution to support 1 × 1 802.11a/b/g/n/ac WLAN standards and Bluetooth 5.0 + HS, designed to deliver superior integration of WLAN/Bluetooth and low-energy technology.
	BB_CYW54591,	//The Cypress CYW54591 is a complete dual-band (2.4 GHz and 5 GHz) 5G Wi-Fi 2×2 MIMO MAC/PHY/Radio system-on-Chip.
	BB_ASR1803E,	//ASR的4G芯片 CAT-4, ASR1802S Costdown 芯片, Open Linux版本
	BB_ASR1803L,	//ASR的4G芯片 CAT-4, ASR1802S Costdown 芯片, 支持"Open Linux版本" or "RTOS版本"
	BB_WCN3998,		//高通WiFi芯片
	BB_QCM4290,		//高通4G平台, The QCM4290 includes the next generation of the Qualcomm Snapdragon 600 series processor and LTE modem.
	BB_QCX315,		//高通5G平台, The QCX315 device is a 5G modem from Qualcomm Technologies, Inc. (QTI). It implements the 5G NR standard for sub-6 GHz bands.
	BB_QCS8250,		//高通 QCS8250 is the new generation Qualcomm? Snapdragon? premium-tier processor with robotic application.
	BB_CYW43455,	//The Cypress CYW43455 single-chip device provides the highest level of integration for Internet of Things applications and handheld wireless system with integrated single-stream IEEE 802.11ac MAC/baseband/radio and, Bluetooth 5.0.
	BB_UIS8310AM,	//展锐 UIS8310AM is a highly integrated application processor with embedded TDD-LTE, FDD-LTE, WCDMA and GSM/GPRS/EDGE modem and LPDDR2. The specially optimized architecture of UIS8310 can achieve high performance and low power for a lot of applications.
	BB_SDX65,		//高通 5G 芯片, 工规, The SDX65/SDX62 device is a multimode modem chip, supporting 2G/3G/4G/5G technologies. 4nm premium-tier 5G modem, 3G/4G/5G modem –mmWave (mmW) and sub-6 GHz bands (3GPP Release 16 integrated modem).
	BB_UWE5623DU,	//展锐 WiFi/蓝牙 芯片, UWE5623DU is a high intergrated 2-in-1 connectivity single chip, this chip includes 2.4GHz and 5GHz WLAN IEEE 802.11 a/b/g/n/ac 2x2 MU-MIMO 20/40/80 MHz VHT R2 MAC/PHY/Radio, Bluetooth 5.1.
	BB_EC618,		//上海移芯 Eigencomm, Cat1芯片. EC618 is a Cat.1bis SoC chipset with ultra-low cost, ultra-low power and ultra-high integration, it is fully compliant to 3GPP Rel14 Cat.1bis standard，and compatible with 4G commercial networks.
	BB_EFR32BG21,	//芯科科技(Silicon Labs), 蓝牙+LoRa的芯片, EFR32BG21 Blue Gecko Wireless SoC Family.
	BB_CYW43438,	//The Cypress CYW43438L is a highly integrated single-chip solution and offers the lowest RBOM in the industry for smartphones, tablets, and a wide range of other portable devices.
	BB_UIS8850DG,	//展锐 UIS8850DG is a highly integrated system on chip solution with embedded LTE Cat1bis modems, GNSS modem, RF transceiver, power management unit(PMU), Trust zone and Multi-Function Crypto Engine(CE).
	BB_CYW8X072,	//The Cypress CYW8X072 is a monolithic, single-chip, Bluetooth 4.2 compliant, stand-alone baseband processor with an integrated 2.4 GHz transceiver.
	BB_WCN3950,		//高通WiFi芯片
	BB_W155S1,		//Amlogic W155S1 is an integrated Wi-Fi and Bluetooth combo chip. WiFi&BT芯片, 支持802.11_a/b/g/n/ac@WLAN2.4G&5G, BT5.0（BLE、BDR/EDR）.
	BB_CYW43439,	//The Cypress CYW43439 is a highly integrated single-chip solution and offers the lowest RBOM in the industry for smartphones, tablets, and a wide range of other portable devices.
	BB_CB0201,		//海思 CB0201 是一款海思平台低功耗的NB-IOT芯片，支持3GPP R13/R14/R15 NB-IoT（支持Rel-16升级），同时支持BLE/GNSS。
	BB_ASR1606C,	//ASR的LTE CAT1/M芯片, ASR1606 is a highly cost-efficient System on Chip (SoC) device.（4M RAM+ 4M ROM）
	BB_ASR1606S,	//ASR的LTE CAT1/M芯片, ASR1606 is a highly cost-efficient System on Chip (SoC) device.（8M RAM+ 8M ROM）
	BB_WCN6856,		//高通WiFi芯片
	BB_QCX216,		//高通 compact, low power, low-cost LTE Cat.1bis chip, WiFi2.4GHz Rx.
	BB_QCA206x,		//高通 The Qualcomm QCA206x family consist of System-On-Chips (SoC), Bluetooth Milan and Wi-Fi supported, supporting simultaneous operation on 2.4 GHz, 5 GHz, and 6GHz*, also known as Dual Band Simultaneous (DBS). Part Number(s): QCA2065, QCA2066, QCA2062, QCA2064.
	BB_ASR1828,		//ASR的4G芯片, LTE CAT-6, 1826的迭代产品.
	BB_IPQ5018,		//高通方案（开发板）, 支持Wi-Fi 6
	BB_QCA6574,		//高通WiFi芯片, The QCA6574A is a single-die wireless local area network (WLAN) and Bluetooth combo solution to support 2 × 2 MIMO with two spatial streams IEEE802.11 a/b/g/n/ac WLAN standards and Bluetooth 5.0 enabling seamless integration of WLAN/Bluetooth and Low Energy technology.
	BB_QCA6698,		//高通车规级WiFi/BT芯片. The QCA6698AQ the most advanced premium Wi-Fi/BT combo chipset in the automotive industry. Wi-Fi 6e Dual MAC 802.11ax MIMO DBS 2x2+ 2x2 BT 5.3 for Automotive Applications.
	BB_EC616L,		//上海移芯 超低功耗NB-IoT单模芯片
	BB_INT100854,	//芯片是IONA芯片平台，Orbcomm平台商，应用于卫星连接的模块开发，实现与卫星的数据传输
	BB_SA2150P,		//SA2150P chipset is a Qualcomm Snapdragon application processor for use with C-V2X and Telematics applications.
	BB_SA8155P,		//SA8155P 是高通的主芯片
	BB_CX1910,		//CX1910是宸芯科技有限公司的车规级多模双通C-V2X芯片, 可实现多种Modem功能, 并集成了LTE FDD/TD-LTE 的物理加速器
	BB_CYW8x570D,	//The Cypress CYW8x570D single-chip device provides the highest level of integration for Automotive and Industrial IoT wireless systems with integrated Dual-band 2x2 MIMO IEEE 802.11ax WLAN MAC/baseband/radio, Bluetooth 5.3 MAC/baseband/radio, and integrated Power Management Unit.
	BB_UIS7885,		//展锐 UNISOC 5G智能模块平台 UIS7885 is a high performance application processor with integrated 2G/3G/4G/5G modem.
	BB_MT6990,		//MTK 5G 芯片, T830 套片, MT6990 5G Modem Application.
	BB_ECR6600A,	//ECR6600-A系列芯片是北京奕斯伟科技集团有限公司（简称“ESWIN”）的一款高度集成的低功耗系列芯片是一款高度集成的低功耗 WiFi/BLE Combo 芯片，是面向智能家居 IoT 等应用而设计的系统级芯片（ SoC ）
	BB_W265P1,		//Amlogic W265P1 is a Wi-Fi/Bluetooth combo chip supporting 2T2R 802.11ax and Bluetooth 5.2. Wi-Fi6芯片, 其支持2.4GHz和5GHz频段，Bluetooth 5.2，支持PCIe 2.1.
	BB_UWE5622,		//展锐 UNISOC WiFi/蓝牙 芯片, UWE5622 is a highly integrated 2-in-1 connectivity single chip which offers the lowest RBOM in the industry for PC, STB, OTT, industrial control and automotive applications. This chip includes 2.4 GHz and 5 GHz WLAN IEEE 802.11 a/b/g/n/ac 1x1 DL MU-MIMO 20/40/80 MHz VHT R2 MAC/PHY/Radio, Bluetooth 5 with supporting high power mode, Mesh, Direction Finding and Long Range.
	BB_SV6115,		//南方硅谷?iComm, The SV6115 is a fully integrated SoC with 2.4GHz band 1T1R 11b/g/n/ax Wi-Fi, and MCU. Single-chip IEEE 802.11b/g/n/ax WLAN SoC with USB Interface.
	BB_SV6358,		//南方硅谷?iComm, The SV6358 is a fully integrated SoC with 2.4GHz band 1T1R 11b/g/n/ax Wi-Fi, Bluetooth Low Energy 5.0, and MCU. Single-chip IEEE 802.11b/g/n/ax WLAN and BLE Combo SoC with USB and SDIO Interface.
	BB_RK3568,		//Rockchip 瑞芯微, 中等性能处理器, SATA/PCIE/USB3.0等各类型外围接口齐全, 轻量级AI应用, 物联网网关, NVR存储, 车载中控, 安卓10.0及以上版本
	BB_QCN9024,		//高通WiFi芯片, QCN9024 is an 802.11ax Wi-Fi 6E PCIe radio for Retail/Carrier Routers and Mesh nodes. QCN9024 with Qualcomm? 802.11ax technology is a highly integrated wireless local area network (WLAN) system-on-chip (SoC) for 2.4/5/6 GHz IEEE802.11ax/ac/n/g/b/a applications.
	BB_SCHA634,		//SCHA634 是村田的6轴传感器, SCHA600 Series: 6-DOF XYZ-Axis Gyroscope and xyz-Axis Accelerometer with digital SPI interface.The SCHA600 is a combined high performance 3-axis angular rate and 3-axis accelerometer.
	BB_ASR1606L,	//ASR的LTE CAT1/M芯片
	BB_SM6350,		//高通, 车载SMART产品. SM6350 includes the next generation of the Qualcomm? Snapdragon? 600 series processor with integrated 5G modem. It implements the 5G NR standard for sub-6 GHz bands. More RF operating bands and advanced techniques with SDR735: 3G/4G/5G modem– sub-6 GHz bands.
	BB_SA522M,		//高通 5G NR 芯片, 车载 5G R16 平台, 并非SMART, 和SA515M平台一样的，相当于升级版。The SA522M device is the second 5G modem from Qualcomm Technologies, Inc. (QTI). It implements the 5G NR standard for sub-6 GHz bands.
	BB_UIS7863,		//展锐 UNISOC 4G 平台芯片, Smart智能模块产品。
	BB_RTL8723,		//Realtek平台WiFi、蓝牙芯片
	BB_BK7256,		//BK7256是高度集成的1x1单频2.4GHz Wi-Fi6(802.11b/g/n/ax)和蓝牙5.2组合解决方案，专为需要高安全性和丰富资源的应用设计。双32位RISC-V MCU和全套外设的集成使BK7256成为高级物联网(IoT)应用的理想选择。
	BB_MT6825,		//MTK MT6825芯片是属于卫星产品平台, 属于IoT-NTN. MT6825的基本架构都是沿用NB芯片MT2625的实现方式.
	BB_CYW8X373,	//The Cypress CYW8x373（如：CYW88373） single-chip device provides the highest level of integration for Automotive IoT wireless systems with integrated single-stream IEEE 802.11a/b/g/n/ac MAC/baseband/radio and Bluetooth 5.2 (Basic Rate, Enhanced Data Rate and Bluetooth Low Energy).
	BB_SA525M,		//高通 SA525M 为高通车载 R16 5G 平台, 并非SMART. The SA525M device is the second 5G modem from Qualcomm Technologies, Inc. (QTI). It implements the 5G NR standard for sub-6 GHz bands.
	BB_QCS8550,		//高通 The QCS8550（属于 SMART 项目） device is the new generation Qualcomm? Snapdragon? premium-tier SoC. It is designed with a 4 nm process, for superior performance and power efficiency.
	BB_WCN7851,		//高通WiFi芯片, The WCN7851 device is a highly integrated System-On-Chip (SoC) supporting Wi-Fi 7 and Bluetooth (BT) 5.3. The WCN7851 supports simultaneous operation on 2.4 GHz + 5 GHz, 2.4 GHz + 6 GHz and 5 GHz + 6 GHz.
	BB_AIC8800D80,	//爱科微半导体 AIC8800D80 is a highly integrated chip with dual band Wi‐Fi6, BTDM5.3 for wireless application.
	BB_AIC8800F,	//爱科微半导体 AIC8800F is a highly integrated SoC with dual band WiFi6 , BTDM5.2 , and high‐performance Cortex‐M4F for wireless application. And support external QSPI flash.
	BB_MM6108,		//摩尔斯微 Morse Micro provides a complete Wi-Fi HaLow connectivity solution. The MM6108 SoC is a single-chip solution, including Radio, PHY, and MAC sections designed in compliance with the IEEE 802.11ah standard, supporting data rates up to 32.5 Mbps.
	BB_XY1200,		//芯翼信息科技推出的第二代NB-IoT SoC XY1200。XY1200是业界最高集成度，支持免32K晶振设计，同时具有超低功耗和超高性能的NB-IoT芯片，可应用于智能表计、智能烟感、智能门磁等多个领域。XY1200拥有的高集成度、免32K、免校准能力，可大幅度降低用户的综合成本。
	BB_88Q9098,		//恩智浦半导体，NXP，88Q9098 汽车无线SoC系列是业界首个基于最新IEEE802.11ax标准的Wi-Fi6解决方案，支持2x2+2x2并发双Wi-Fi和双模蓝牙5.3。88Q9098 系列规格兼容的无线解决方案包括：带有蓝牙5的2x2 + 2x2并发双Wi-Fi (AEC-Q100三级)；88Q9098S - 带有蓝牙5的2x2 + 2x2并发双Wi-Fi (AEC-Q100二级)。
	BB_RTL8822CS,	//Realtek/瑞昱 RTL8822CS 无线模块符合IEEE802.11 a/b/g/n/ac标准，能在802.11ac单流下实现433.3Mbps的速率连接到无线局域网。WiFi模块提供了用于蓝牙的wifi、UART/PCM接口的SDIO接口。
	BB_UIS8821,		//展锐 UIS8821 is an advanced system-on-chip solution integrated IOT-NTN modems. Building on the success of UNISOC’s current solutions, the UIS8821 integrates RF transceiver for low cost.
	BB_RTL8821CS,	//Realtek/瑞昱 The Realtek RTL8821CS is a highly integrated single-chip that supports 1-stream 802.11ac solutions with Multi-user MIMO (Multiple-Input, Multiple-Output) STA mode with integrated Bluetooth Smart Ready controller, SDIO (SDIO 1.1/2.0/3.0) interface, and HS-UART mixed interface.
	BB_ANT_PRODU,	//ANT天线产品
	BB_SDX72,		//高通 5G 芯片, The SDX72 device is a multimode modem chip, supporting 2G/3G/4G/5G technologies. It is designed with an advanced 4 nm process for superior performance and power efficiency. SDX72不属于SMART智能模块产品芯片.
	BB_SDX75,		//高通 5G 芯片, The SDX75 device is a multimode modem chip, supporting 2G/3G/4G/5G technologies. It is designed with an advanced 4 nm process for superior performance and power efficiency. SDX75不属于SMART智能模块产品芯片.
	BB_ASR1602,		//ASR平台, ASR1602 is a highly cost-efficient System on Chip (SoC) device which integrates application processing subsystem, communication subsystem, PMU, and embedded pSRAM + flash to enable the most compact single-chip LTE single-mode data module, POC, POS, and other IoT solutions.
	BB_SM6225,		//高通 Qualcomm SM6225, 4G SMART 芯片, Qualcomm Snapdragon 4G Platforms in Mid and Low Tiers.
	BB_UWE5621,		//展锐 UNISOC WiFi/蓝牙 芯片, UWE5621DS is a highly integrated 2-in-1 connectivity single chip which offers the lowest RBOM in the industry for PC, STB, OTT, industrial control and automotive applications. This chip includes 2.4 GHz and 5 GHz WLAN IEEE 802.11 a/b/g/n/ac 2×2 MU-MIMO 20/40/80 MHz VHT R2 MAC/PHY/Radio, Bluetooth? 5.0 Smart Ready compliant with supporting high power mode, Mesh, Direction Finding and Long Range.
	BB_ASR1806,		//ASR平台, The ASR1806 is an advanced, highly integrated communication processor and LTE/3G/2G platform for data communication applications.
	BB_IW612,		//恩智浦半导体，NXP，The IW612 is a highly integrated 2.4/5 GHz dual-band 1x1 Wi-Fi 6, Bluetooth/Bluetooth Low Energy 5.2 and 802.15.4 tri-radio single-chip solution optimized for a broad array of IoT and industrial applications in smart home, smart devices and accessories, smart appliances, smart energy, industrial automation, gateways and many more.
	BB_QCM5430,		//高通 5G Smart智能芯片，是QCM6490平台的低配版本，共用软件版本。The QCM6490/QCM5430 device is the new generation Qualcomm? Snapdragon 5G SoC with an integrated modem. It is designed with the 6 nm process, for superior performance and power efficiency.
	BB_QCM4490,		//高通 Qualcomm 5G SMART 智能芯片, The QCM4490 device is the new generation Snapdragon? 5G SoC with an integrated modem. It is designed with the 4 nm process, for a superior performance.
	BB_SDX35,		//高通 5G 平台, The SDX35 device is a multimode modem chip, supporting 4G/5G technologies. It is a 4 nm chip designed for superior performance and power efficiency. SDX35 不属于 SMART 智能芯片。SDX35 是全新平台和模式，可以认为是 5G Redcap芯片，和传统的5G的MBB高速芯片也有差异，没有CA和ENDC。
	BB_ATK4055,		//Autotalks SECTON (ATK4055C), SECTON is an automotive-grade V2X hardware add-on. SECTON helps achieving the highest level of communications and safety decision reliability, while minimizing the quantity of required system external components. 不是 SMART 智能芯片。
	BB_FR801xH,		//富芮坤 FR801xH 系列芯片（FR8012HAQ、FR8016HA）是面向SOC（片上系统），易于快速开发的低功耗蓝牙芯片。基于Freqchip的蓝牙智能固件和协议栈的支持，完全兼容蓝牙V5.1（LE模式）协议。同时用户可以基于芯片内置的ARM CorteM3嵌入式32位高性能单片机开发各种应用程序。不是“SMART智能芯片”。属于MCU WIFI，实际是BLE。
	BB_AIC8800MC,	//爱科微半导体 AICSEMI INC. AIC8800MC is a highly integrated chip with 2.4GHz WiFi6, BT5.2 for wireless application. AIC8800MC Low‐Energy WiFi6/BT5.2 SoC.
	BB_BK7238,		//博通集成电路, BK7238是一款高度集成的单芯片Wi-Fi802.11n和低功耗蓝牙(BLE)5.2组合解决方案，专为低功耗和小空间应用设计的。BK7238集成了功能强大的32位MCU和全套外设和接口，是高级物联网(IoT)应用的理想选择。
	BB_RTL8731,		//The Realtek RTL8731BU is a highly integrated single-chip 802.11a/b/g/n 1T1R WLAN with USB 2.0 multi-function.
	BB_RTL8733,		//The Realtek RTL8733BS is a highly integrated 802.11a/b/g/n 1T1R WLAN and Bluetooth 5.2 combo chip.
	BB_EC718,		//上海移芯 Eigencomm, EC718 is a Cat.1bis SoC chipset with ultra-low cost, ultra-low power and ultra-high integration, it is fully compliant to 3GPP R14 Cat.1bis standard，and compatible with 4G commercial networks. 另外EC718平台包含EC718S\EC718P主要的区别是存储选择不一样，二者可共同参考EC718的datasheet文档.
	BB_QCS5430,		//高通 5G Smart 智能芯片，QCS5430芯片是高通针对QCM/QCS6490只是做了算力上的裁剪，具体支持的功能是一样的. QCS是去除蜂窝版本的, QCM是带蜂窝版本的, 类似于QCM6490和QCS6490一样. The QCS6490/QCS5430 is available in the PSP1287 that includes dedicated ground pins for improved grounding, mechanical strength, and thermal continuity.
	BB_CYW4373E,	//The Cypress CYW4373E single-chip device provides the highest level of integration for Industrial IoT wireless systems with integrated single-stream IEEE 802.11a/b/g/n/ac MAC/baseband/radio and Bluetooth 5.0 (Basic Rate, Enhanced Data Rate and Bluetooth Low Energy).
	BB_MT8766,		//MTK 4G Smart 智能芯片, The MT8766WB device, with integrated Bluetooth, FM, WLAN and GPS modules, is a highly integrated baseband platform incorporating both modem and application processing subsystems to enable LTE/LTE-A and C2K smart device applications.
	BB_BG21A10768I,	//芯科科技(Silicon Labs), 蓝牙芯片, EFR32BG21 Blue Gecko 无线 SoC 产品系列, 因为Silabs的芯片开头都是EFR32BG21，后续无法区分, 创建芯片平台命名10dbm：BG21A10768I
	BB_BG21A20768I,	//芯科科技(Silicon Labs), 蓝牙芯片, EFR32BG21 Blue Gecko 无线 SoC 产品系列, 因为Silabs的芯片开头都是EFR32BG21，后续无法区分, 创建芯片平台命名20dbm：BG21A20768I
	BB_ASR1609,		//ASR的LTE CAT1芯片, ASR1609S 8+8配置, ASR1609C 4+4配置, ASR1609 is a highly cost-efficient System on Chip (SoC) device which integrates application processing subsystem, communication subsystem, audio codec, BT/BLE, GNSS and embedded pSRAM + flash to enable the most compact single-chip LTE CAT1 data module, POC, POS, and other IoT solutions.
	BB_BK7235,		//博通集成电路, The BK7235 is a highly integrated 1x1 single-band 2.4 GHz Wi-Fi 6 (802.11b/g/n/ax) and Bluetooth 5.2 Low Energy (LE) combo solution designed for applications that require high security and abundant resources.
	BB_UIS7870,		//展锐 UNISOC 5G智能模块平台 UIS7870 is a high performance application processor with integrated 2G/3G/4G/5G modem. 6nm EUV process for best-in-class power-efficient 5G SOC chip.
	BB_DW3300Q,		//Qorvo 威讯联合半导体有限公司 The DW3300Q is a fully integrated low-power, single chip CMOS RF 6.5GHz-8GHz IR-UWB transceiver IC compliant with the IEEE Std 802.15.4?‐2020 (HRP UWB PHY), IEEE Std 802.15.4z?‐2020 and IEEE 802.15.8 standards.
	BB_QCA66x8,		//高通车规级WiFi/BT芯片. QCA6688 与 QCA6698 共用一套资料. The QCA66x8AQ is a series of highly integrated system-on-chip (SoC) devices supporting 802.11ax Wi-Fi 6 or Wi-Fi 6E, and Bluetooth (BT) v5.3 for automotive applications.
	BB_MT2737,		//MTK 5G 车载模块芯片. The MT2737 device is a highly integrated baseband platform incorporating both modem and application processing subsystems to enable LTE/LTE-A and NR modem applications.
	BB_QCM4325,		//高通 Qualcomm QCM4325, 4G SMART 芯片, 是从8核 SM6225 COSTDOWN 成6核. The QCM4325 SoC is the next generation Qualcomm Technologies, Inc. (QTI) mid-tier processor and LTE modem. It is designed with 6 nm process for superior performance and power efficiency.
	BB_BES2600IUC,	//Bestechnic 恒玄科技 BES2600IUC-4X is an ultra-low power and highly integrated Bluetooth audio SoC which features the dual-core STAR-MC1 processor for TWS and voice applications.
	BB_EC716S,		//上海移芯 Eigencomm, EC716S is a Cat.1bis IoT SoC chipset with ultra-low cost, ultra-low power and ultra-high integration , and is fully compliant to 3GPP Rel14 Cat.1bis standard，and compatible with 4G commercial networks.
	BB_STM32WLE5xx,	//ST 意法半导体, The STM32WLE5/E4xx long-range wireless and ultra-low-power devices embed a powerful and ultra-low-power LPWAN-compliant radio solution, enabling the following modulations: LoRa?, (G)FSK, (G)MSK, and BPSK.
	BB_QCS6490,		//高通 5G Smart 车载智能模块, 包含5G版本. QCM6490去掉蜂窝部分. QCS是去除蜂窝版本的, QCM是带蜂窝版本的, 类似于QCM6490和QCS6490一样. The QCS6490/QCS5430 is available in the PSP1287 that includes dedicated ground pins for improved grounding, mechanical strength, and thermal continuity.
	BB_MT7927,		//MTK WiFi/蓝牙 芯片, MT7927BEW is a highly integrated single chip which features a low power 2x2 2.4GHz and 2x2 5/6GHz DBDC 11a/b/g/n/ac/ax/be Wi-Fi subsystem and a Bluetooth v5.3 subsystem, offering feature-rich wireless connectivity at high standards, and delivering reliable, cost-effective throughput from an extended distance.
	BB_RTL8852,		//The Realtek RTL8852BS is a highly integrated single-chip that supports 2-stream 802.11ax solutions with Multi-user MIMO (Multiple-Input, Multiple-Output) with Wireless LAN (WLAN) SDIO (SDIO 1.1/2.0/3.0) interface controller with integrated Bluetooth 5 HS-UART interface controller. It combines a WLAN MAC, a 2T2R capable WLAN baseband, and RF in a single chip. The RTL8852BS provides a complete solution for a high-performance integrated wireless and Bluetooth device.
	BB_MDM9205S,	//高通4G芯片, The Qualcomm? 9205 LTE modem (MDM9205/MDM9205S) is the new generation LTE IoT mobile data modem (MDM). MDM9205S supports non-terrestrial network (NTN). MULTIMODE, M1, NB1, 2G, NTN, VoLTE/IMS, and GNSS.
	BB_GENERAL_MCU,	//通用MCU芯片
	BB_NRT81750,	//纽瑞芯UWB定位通信系统芯片 NRT81750 是一款高集成、高性能、低功耗的超宽带（UWB）定位通信系统芯片，频段支持CH5~CH12，8个UWB BAND (6.0 GHz to 9.25GHz)，最高带宽支持到1.3GHz，同时支持IEEE802.15.4-2020和IEEE802.15.4z协议标准以及CCC和FiRa联盟规范。该芯片属于车规标准，具备汽车规范，从产品定义到设计、工艺、生产、测试、质量，都严格按照车规标准开发。
	BB_SM4250,		//高通 Smart 4G平台. The SM4250 includes the next generation of the Qualcomm? Snapdragon?400 series processor and LTE modem.
	BB_EC626,		//上海移芯 Eigencomm, EC626 is a NB-IoT SoC chipset with ultra-low cost, ultra-low power and ultra-high integration, and is fully compliant to 3GPP Rel14 NB-IoT standard.
	BB_SXR2130P,	//高通虚拟现实处理器. SXR2130P is the new generation Qualcomm? Snapdragon? premium-tier processor for eXtended reality(XR) applications. It is designed with the 7 nm process, for superior performance and power efficiency.
	BB_AIC8800DC,	//爱科微半导体 AICSEMI INC. AIC8800DC是蓝牙双模BT&BLE都支持. 单频 Wi-Fi 6 模块，支持蓝牙 5.2，双模.
	BB_AIC8800DL,	//爱科微半导体 AICSEMI INC. AIC8800DL是蓝牙单模仅支持BLE. 单频 Wi-Fi 6 模块，支持 BLE 5.2，单模.
	BB_HTD1011,		//HTD1011 是北京华力创通股份有限公司（Hwa Create Company）开发的具有完全自主知识产权的卫星移动通信基带处理芯片。芯片全面支持天通一号卫星移动通信系统制式。移远是与“国智天通”公司签的技术协议。
	BB_QCC2073,		//The QCC2073 device is a highly integrated System-On-Chip (SoC) supporting Wi-Fi 7 and Bluetooth (BT) 5.3. The QCC2073 supports simultaneous operation on 2.4 GHz, 5 GHz and 6 GHz.
	BB_QCC2076,		//The QCC2076 device is a highly integrated System-On-Chip (SoC) supporting Wi-Fi 7 and Bluetooth (BT) 5.3. The QCC2076 supports simultaneous operation on 2.4 GHz +5 GHz, 2.4 GHz + 6 GHz and 5 GHz + 6 GHz.
	BB_UIS7861,		//展锐 UNISOC 4G 平台芯片, Smart智能模块产品，UIS7861是UIS7863的costdown降频。UIS7861 is a highly integrated application processor with embedded TD-LTE, LTE FDD, WCDMA/HSPA(+), WCDMA/DC-HSDPA, and GSM/GPRS/EDGE. The specially optimized architecture of UIS7861 can achieve high performance and low power for a lot of applications. Overall, UIS7861 chipset presents a high cost-effective platform for four mode Android mobile devices.
	BB_EC718E,		//上海移芯 Eigencomm, EC718E is a Cat.1bis SoC chipset with ultra-low cost, ultra-low power and ultra-high integration, 其需要单独定义, 因为其需要检查“APP BIN 文件是否存在”。
	BB_QCX217,		//高通（实际是移芯平台芯片）QCX217 is a Cat.1bis IoT SoC chipset with ultra-low cost, ultra-low power, ultra-high integration, fully compliant to 3GPP Rel. 14 Cat.1bis standard, and compatible with 4G commercial networks.
	BB_RW610,		//恩智浦半导体，NXP，The RW610 is a highly integrated, low-power Wireless MCU with an integrated MCU and Wi-Fi 6 + Bluetooth Low Energy (LE) 5.3 radios designed for a broad array of applications. 纯WiFi蓝牙芯片.
	BB_XIN100,		//Xincomm, 低轨卫星芯片, XIN100-R2 is a TDD/FDD dual mode LTE baseband chip compliant to 3GPP standard for user-end devices. It implements all 3GPP R8/R9 functionalities and supports category-4 throughput (150Mbps DL / 50Mbps UL).
	BB_OM6681x,		//OnMicro 昂瑞微, OM6681x dual core system, include Application Core and SensorHubCore, there are several shared System Peripheral blocks between AppCore and SensorHubCore. Application core is a Coretex-M33S core plus multiple Master/slave AHB standard system. Support full BT 5.2 dual-mode feature (BT BR/EDR and BLE).
	BB_HC32F4A0PGTB,//HC32F4A0PGTB 是 ARMv7-M 架构 32bit Cortex-M4 CPU，集成FPU、MPU，支持SIMD指令的DSP，全指令跟踪单元ETM， 及CoreSight标准调试单元。最高工作主频 240MHz，达到 300DMIPS或825Coremarks的运算性能。
	BB_EC718P,		//上海移芯 Eigencomm, EC718P is a Cat.1bis SoC chipset with ultra-low cost, ultra-low power and ultra-high integration, 其需要单独定义, 因为其需要检查“APP BIN 文件是否存在”。
	BB_ASR1607,		//ASR 的 LTE CAT1 芯片, ASR1607 is a highly cost-efficient System on Chip (SoC) device which integrates application processing subsystem, communication subsystem, GNSS, audio codec, PMU, and embedded pSRAM + flash to enable the most compact single-chip LTE single-mode position IoT solutions. The communication subsystem integrates LTE CAT1 modem baseband and RF transceiver to cover 600MHz~2.7GHz bands for worldwide roaming. 
	BB_ASR1903S,	//ASR 的 5G 芯片, 属于蜂窝模组, 非SMART智能, ASR1903 is a highly cost-efficient Rel.17 RedCap 5G NR System on Chip (SoC) device which integrates application processing subsystem, communication subsystem, audio codec, and embedded LPDDR. The communication subsystem integrates NR RedCap and LTE CAT4 modem baseband and RF transceiver to cover 450MHz~6GHz bands.
	BB_ASR1903E,	//ASR 的 5G 芯片, 属于蜂窝模组, 非SMART智能, ASR1903 is a highly cost-efficient Rel.17 RedCap 5G NR System on Chip (SoC) device which integrates application processing subsystem, communication subsystem, audio codec, and embedded LPDDR. The communication subsystem integrates NR RedCap and LTE CAT4 modem baseband and RF transceiver to cover 450MHz~6GHz bands.
	BB_ASR1903L,	//ASR 的 5G Linux 芯片, 属于蜂窝模组, 非SMART智能, ASR1903 is a highly cost-efficient Rel.17 RedCap 5G NR System on Chip (SoC) device which integrates application processing subsystem, communication subsystem, audio codec, and embedded LPDDR. The communication subsystem integrates NR RedCap and LTE CAT4 modem baseband and RF transceiver to cover 450MHz~6GHz bands.
	BB_CYW5551x,	//The Cypress, The AIROC? CYW5551x family single-chip device provides the highest level of integration for commercial and consumer systems, with integrated IEEE 802.11 a/b/g/n/ac/ax 1x1 MAC/baseband/radio, Bluetooth? 5.4 +EDR+LE. It provides a small form-factor solution with minimal external components to drive down cost and allows for platform design flexibility in size, form, and function. AIROC? Wi-Fi & Bluetooth? combo chip Low-power, 1 x 1, tri-band, IEEE 802.11ax, Wi-Fi 6/6E, Bluetooth? 5.4.
	BB_OM6626,		//OnMicro 昂瑞微, OM6626 High Performance Bluetooth Low Energy Wireless Radio Chip. Bluetooth Low Energy (Compatible with Bluetooth 5.3)
	BB_MT6813,		//MTK 5G 芯片, 4G/5G NR RedCap modem. Supports LPDDR4X. MT6813 is a highly integrated SoC incorporating modem, RF, and application processing subsystems to enable NR RedCap and LTE Cat-4 modem applications. The chip integrates an Arm? Cortex-A35 processor operating up to 888 MHz.
	BB_BK7258,		//博通集成电路, The BK7258 is a highly integrated 1x1 single-band 2.4 GHz Wi-Fi 6 (802.11b/g/n/ax) and Bluetooth 5.4 Low Energy (LE) combo solution designed for applications that require abundant resources and low power consumption. The integration of a 32-bit ARMv8-M Star MCU and a comprehensive set of peripherals makes the BK7258 ideal for advanced Internet of Things (IoT) applications.
	BB_SM6450P,		//高通 SMART 智能平台。骁龙6 Gen1芯片，型号SM6450。采用高通Kyro CPU，频率最高可达2.2GHz，支持USB 3.1和高达12GB的LPDDR5内存，频率高达2750MHz。在网络方面，该芯片组将采用骁龙X62 5G基带，提供5G毫米波和6GHz以下频段支持。这款芯片支持高达FHD+分辨率的120Hz刷新率显示屏，WiFi方面将支持高通FastConnect 6700 WiFi 6E，并且还将支持蓝牙5.2。The SM6450P device is the new generation Snapdragon? SoC. It is designed with the 4 nm process for superior performance. SM6450P includes the following key components: Qualcomm? Kryo? CPU 6xx built on Arm Cortex technology. Qualcomm? Adreno? GPU 7xx for better graphics performance and power efficiency.
	BB_WCN6750,		//高通WiFi芯片, 没有DBS, 其他与WCN6856一样。
	BB_ASR1605,		//ASR平台, ASR1605 is a highly cost-efficient System on Chip (SoC) device which integrates application processing subsystem, communication subsystem, PMU, and embedded pSRAM + flash to enable the most compact single-chip LTE single-mode data module, POS, and other IoT solutions. The communication subsystem integrates LTE CAT1 modem baseband and RF transceiver to cover 600MHz~2.7GHz bands for worldwide roaming.
	BB_SG4250P,		//高通 Qualcomm 游戏事业部 SMART 智能芯片, The SG4250P device is a mainstream tier Snapdragon? gaming processor for game streaming platform. It is designed with the 4 nm process for a superior performance. External WCN3950 supports WLAN 1 × 1 802.11a/b/g/n/ac and Bluetooth 5.0; External WCN3988 supports WLAN 1 × 1 MU-MIMO 802.11a/b/g/n/ac, 11ax ready, Bluetooth 5.1.
	BB_RTL8710,		//Realtek 平台 WiFi、蓝牙 SOC 芯片，The RTL8710EC is a low-power single-chip microcontroller integrating dual RISC cores (Arm Cortex-M55 compatible instruction set and RISC-V compatible instruction set).
	BB_TG7100C,		//平头哥半导体有限公司，TG7100C是一款Wi-Fi+BLE组合的芯片组，用于低功耗和高性能应用开发。无线子系统包含2.4G无线电，Wi-Fi 802.11b/g/n和BLE5.0基带/MAC设计。微控制器子系统包含一个低功耗的32位RISCCPU，高速缓存和存储器。电源管理单元控制低功耗模式。
	BB_CYW8x310,	//Infineon 英飞凌，纯蓝牙BT5.3。AIROC? CYW8x310 single-chip device provides the highest level of integration for Automotive systems, with integrated Bluetooth? 5.3 + EDR. It provides a small form-factor solution with minimal external components to drive down cost and allows for platform design flexibility in size, form, and function. 在英飞凌手中完成开发的芯片，将不会有 CYPRESS 的字样，CYW89310 属于这种情况。
	BB_EC716E,		//上海移芯 Eigencomm, EC716E 是基于 EC716S 的衍生版本, 二者的差异主要是Flash存储大小差异, 同时 EC716E 芯片要检查 APP BIN 文件。a Cat.1bis IoT SoC chipset with ultra-low cost, ultra-low power and ultra-high integration , and is fully compliant to 3GPP Rel14 Cat.1bis standard，and compatible with 4G commercial networks.
	BB_SDX61,		//高通 5G 芯片, 工规, The SDX61 device is a multimode modem chip, supporting 2G/3G/4G/5G technologies. It is designed with a 4 nm process for superior performance and power efficiency. SDX61 与 SDX62 芯片类似，用于5G项目。
	BB_RTL8832CU,	//Realtek/瑞昱 The Realtek RTL8832CU-VF1-CG is a highly integrated single-chip that support 2-stream 802.11ax solutions with Multi-user MIMO (Multiple-Input, Multiple-Output) with Wireless LAN (WLAN). It combines a WLAN MAC, a 2T2R capable WLAN baseband, and RF in a single chip.
	BB_NT98568MBG,	//Novatek NT98568MBG is a highly-integrated SoC with high image quality, low bitrate, low power consumption for battery application with pre-roll and always-on mode, targets on 2Mp to 5Mp/8Mp Edge-IP camera application.
	BB_QCM6690,		//高通 Smart 5G 平台. The QCM6690 device is the new generation Qualcomm? 5G SoC with an integrated modem. It is designed with the 4 nm process, for superior performance. 2G/3G/4G/5G modem – mmWave and sub-6 GHz bands (Rel. 16 integrated modem) with SDR435/SDR735 and 5G DSDA.
	BB_RW612,		//恩智浦半导体，NXP，The RW612 is a highly integrated, low-power tri-radio Wireless MCU with an integrated MCU and Wi-Fi 6 + Bluetooth Low Energy (LE) / 802.15.4 radios designed for a broad array of applications.
	BB_N32G430,		//Nationstech 国民技术股份有限公司（简称：国民技术），MCU芯片，N32G430 系列采用 32-bit ARM Cortex-M4F 内核，最高工作主频 128MHz，支持浮点运算和 DSP 指令，集成 高达 64KB 嵌入式加密 Flash，16KB SRAM，集成丰富的高性能模拟器件，内置 1 个 12bit 4.7Msps ADC，3 个高速比较器，集成多路 U(S)ART、I2C、SPI、CAN 等数字通信接口。目前多用于电机控制、电动工具、平衡车、采集卡、BMS、CAN BOX、红外血氧仪和家电控制板等产品。
	BB_UIS8520,		//展锐 5G 平台, 非Smart, UIS8520 is a highly integrated baseband platform incorporating both modem and application processing subsystems to enable GSM/GPRS/EDGE/WCDMA/LTE/LTE-A/NR Modem applications. The chip integrates Quad Arm? Cortex?-A55 operating up to 2.0GHz.
	BB_FR303x,		//富芮坤 FR303x 系列是双模蓝牙MCU，采用富芮坤芯片的创新技术，将射频、基带、ARM CortexM3内核、丰富的片上资源以及PMU集成在一个芯片中。FR303x 内置ROM实现了蓝牙的控制器功能，完全兼容SIG V5.3（BR/EDR/LE模式）协议。用户可以基于芯片集成的MCU和提供的SDK开发各种应用方案。
	BB_UIS7720,		//展锐 UNISOC 5G 平台, 非Smart, UIS7720 is a high performance application processor with integrated 2G/3G/4G/5G modem. UIS7720 chipset presents a high performance-efficiency platform for 5G Modem devices. 为蜂窝芯片平台。
	BB_QCA8695AU,	//QCA8695AU is a monolithic single-chip that supports Bluetooth? 5.4. It is a standalone baseband processor system on chip (SoC) with an integrated 2.4 GHz transceiver. QCA8695AU is compliant with AEC-Q100 Qualification Specifications for Automotive Applications. 是高通的BT平台芯片，是从 QCA6595 上删减了WiFi功能，升级了BT版本，增加 LE Audio 功能衍生而来的系列，不是Smart平台。
	BB_RTL8761,		//RTL8761B 瑞昱 Realtek 低功耗蓝牙5.0纯蓝牙芯片. The Realtek RTL8761B is a highly integrated single-chip Bluetooth 5 controller with a UART(RTL8761BTV-VI-CG)/USB(RTL8761BUV-VI-CG) interface.
	BB_SYN43756E,	//新突思 WiFi 蓝牙 芯片, The Synaptics(新突思) SYN43756E is a Tri-band (2.4 GHz, 5 GHz and 6 GHz, include UNII-5,UNII-6,UNII-7 and UNII-8) Wi-Fi 2×2 MAC/Baseband/Radio with integrated Bluetooth (BT) 5.3. The Synaptics SYN43756E single-chip device includes an integrated 2.4/5/6 GHz IEEE 802.11 a/b/g/n/ac/ax MAC/ baseband/radio. It also supports Bluetooth 5.3 and Bluetooth Low Energy (BLE).
	BB_QCC730,		//高通 WiFi 芯片, The QCC730 is a micropower Wi-Fi transceiver single package wireless local area network (WLAN) solution. It supports dual-band 1 × 1 IEEE 802.11a/b/g/n WLAN standards.
	BB_ASR1901,		//ASR 的 5G 芯片, 属于蜂窝模组, 非SMART智能, ASR1901 is an advanced & highly integrated communication processor that specially designed for 5G mobile broadband and industrial IoT applications. It supports up to 4.6Gbps peak speed in both 5G non-standalone (NSA) & standalone (SA) mode and integrates with global qualified LTE/WCDMA/GSM modem to support all communication standards and abundant data applications.
	BB_nRF52832,	//Nordic MCU 纯蓝牙芯片, nRF52832 是一款通用的多协议SoC。它满足了需要高级低功耗蓝牙?功能、协议并发性和丰富外围设备和功能集的应用挑战。此外，它为闪存和RAM提供了大量内存。nRF52832 采用具有完全协议并发能力的多协议。它支持低功耗蓝牙，包括2 Mbps高传输速度。
	BB_ASR8601,		//ASR 的 4G SMART 智能芯片, ASR8601 is a System on Chip (SoC) device which highly integrates both application processing subsystem, the baseband modem and cellular RF to enable 4G LTE multimedia smartphone applications. The application subsystem integrates quad-Core 64-bit processors ARM Cortex A55 operating up to 1.5 GHz.
	BB_QCM8538,		//高通车载 SMART 5G 智能平台. The QCM8538 device is the Qualcomm? Snapdragon? automotive infotainment SoC designed with a 4 nm process, for superior performance and power efficiency. 3G/4G/5G modem – sub-6 GHz bands (Rel 16 integrated modem). Qualcomm? FastConnect? 7800 System with WCN785x, 802.11be, 2 × 2 MIMO, Bluetooth 5.3.
	BB_CQ8725S,		//CQ8725S 是高通纯WiFi芯片，没有蜂窝，属于SMART智能产品平台。类似 QCS6490。
	//
	BB_CHIP_COUNT
}EU_BB_CHIP_IDX;



//GSM频段序列号
typedef enum tagEU_GSM_BAND_IDX
{
	G_BAND_GSM900 = 0,
	G_BAND_DCS1800,
	G_BAND_PCS1900,
	G_BAND_GSM850,
	G_BAND_COUNT,		//GSM频段数量
	G_BAND_SIZE = 6		//GSM频段相关的存储BUFF尺寸（“尺寸”必须比“数量”至少大1, 用于存放结束符）
}EU_GSM_BAND_IDX;

//WCDMA频段序列号
typedef enum tagEU_WCDMA_BAND_IDX
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
	W_BAND_COUNT,		//WCDMA频段数量
	W_BAND_SIZE = 16	//WCDMA频段相关的存储BUFF尺寸（“尺寸”必须比“数量”至少大1, 用于存放结束符）
}EU_WCDMA_BAND_IDX;

//cdma2000频段序列号（老）
typedef enum tagEU_CDMA2K_BAND_IDX
{
	C2K_BAND_800 = 0,
	C2K_BAND_1900,
	C2K_BAND_COUNT,		//cdma2000频段数量
	C2K_BAND_SIZE = 3	//cdma2000频段相关的存储BUFF尺寸（“尺寸”必须比“数量”至少大1, 用于存放结束符）
}EU_CDMA2K_BAND_IDX;

//cdma2000频段序列号（新）
typedef enum tagEU_C2K_BAND_IDX
{
	C2K_BC_0 = 0,
	C2K_BC_COUNT,		//cdma2000频段数量
	C2K_BC_SIZE = 3		//cdma2000频段相关的存储BUFF尺寸（“尺寸”必须比“数量”至少大1, 用于存放结束符）
}EU_C2K_BAND_IDX;

//LTE频段序列号
typedef enum tagEU_LTE_BAND_IDX
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
	L_BAND_29,			//LTE的B29和B32，只有DL，是FDD，只有做CA才有用
	L_BAND_30,
	L_BAND_66,
	L_BAND_71,
	L_BAND_42,
	L_BAND_43,
	L_BAND_48,
	L_BAND_9,
	L_BAND_11,
	L_BAND_21,
	L_BAND_47,
	L_BAND_46,
	L_BAND_27,
	L_BAND_85,
	L_BAND_31,
	L_BAND_72,
	L_BAND_73,
	L_BAND_32,			//LTE的B29和B32，只有DL，是FDD，只有做CA才有用
	L_BAND_87,
	L_BAND_88,
	L_BAND_15,			//实际没有 LTE B15 频段，此处定义为 LTE B28B 服务
	L_BAND_59,			//B59为国网专用频段, 1.8G专网频段
	L_BAND_28A,			//LTE 28A 对应的频段数字为 2801
	L_BAND_28B,			//LTE 28B 对应的频段数字为 2802
	L_BAND_70,
	L_BAND_53,
	L_BAND_COUNT,		//LTE频段数量
	L_BAND_SIZE = 56	//LTE频段相关的存储BUFF尺寸（“尺寸”必须比“数量”至少大1, 用于存放结束符）
}EU_LTE_BAND_IDX;

//TD频段序列号
typedef enum tagEU_TD_BAND_IDX
{
	TD_BAND_34 = 0,
	TD_BAND_39,
	TD_BAND_COUNT,		//TD频段数量
	TD_BAND_SIZE = 4	//TD频段相关的存储BUFF尺寸（“尺寸”必须比“数量”至少大1, 用于存放结束符）
}EU_TD_BAND_IDX;

//NB-IoT频段名
typedef enum tagEU_NB_BAND_IDX
{
	NB_BAND_1 = 1,
	NB_BAND_2,
	NB_BAND_3,
	NB_BAND_4,
	NB_BAND_5,
	NB_BAND_7 = 7,
	NB_BAND_8,
	NB_BAND_9,
	NB_BAND_10,
	NB_BAND_11,
	NB_BAND_12,
	NB_BAND_13,
	NB_BAND_14,
	NB_BAND_17 = 17,
	NB_BAND_18,
	NB_BAND_19,
	NB_BAND_20,
	NB_BAND_21,
	NB_BAND_22,
	NB_BAND_23,
	NB_BAND_24 = 24,
	NB_BAND_25,
	NB_BAND_26,
	NB_BAND_27,
	NB_BAND_28,
	NB_BAND_30 = 30,
	NB_BAND_31,
	NB_BAND_65 = 65,
	NB_BAND_66 = 66,
	NB_BAND_68 = 68,
	NB_BAND_70 = 70,
	NB_BAND_71,
	NB_BAND_72,
	NB_BAND_73,
	NB_BAND_74,
	NB_BAND_85 = 85,
	NB_BAND_86,
	NB_BAND_87,
	NB_BAND_88
}EU_NB_BAND_IDX;

//NB-IoT频段序列号
typedef enum tagEU_NB_BAND_INDEX
{
	NB_IDX_B_1 = 0,
	NB_IDX_B_2,
	NB_IDX_B_3,
	NB_IDX_B_4,
	NB_IDX_B_5,
	NB_IDX_B_7,
	NB_IDX_B_8,
	NB_IDX_B_9,
	NB_IDX_B_10,
	NB_IDX_B_11,
	NB_IDX_B_12,
	NB_IDX_B_13,
	NB_IDX_B_14,
	NB_IDX_B_17,
	NB_IDX_B_18,
	NB_IDX_B_19,
	NB_IDX_B_20,
	NB_IDX_B_21,
	NB_IDX_B_22,
	NB_IDX_B_23,
	NB_IDX_B_24,
	NB_IDX_B_25,
	NB_IDX_B_26,
	NB_IDX_B_27,
	NB_IDX_B_28,
	NB_IDX_B_30,
	NB_IDX_B_31,
	NB_IDX_B_65,
	NB_IDX_B_66,
	NB_IDX_B_68,
	NB_IDX_B_70,
	NB_IDX_B_71,
	NB_IDX_B_72,
	NB_IDX_B_73,
	NB_IDX_B_74,
	NB_IDX_B_85,
	NB_IDX_B_86,
	NB_IDX_B_87,
	NB_IDX_B_88,
	NB_IDX_B_COUNT,		//NB-IoT频段数量
	NB_IDX_B_SIZE = 46	//NB-IoT频段相关的存储BUFF尺寸（“尺寸”必须比“数量”至少大1, 用于存放结束符）
}EU_NB_BAND_INDEX;

//C-V2X频段序列号
typedef enum tagEU_CV2X_BAND_IDX
{
	CV2X_BAND_46 = 0,
	CV2X_BAND_47,
	CV2X_BAND_COUNT,	//C-V2X频段数量
	CV2X_BAND_SIZE = 6	//C-V2X频段相关的存储BUFF尺寸（“尺寸”必须比“数量”至少大1, 用于存放结束符）
}EU_CV2X_BAND_IDX;


//WiFi频段(FreqBand)序列号
typedef enum tagEU_WIFI_FB_IDX
{
	WIFI_FB_B24G = 0,	//2.4G
	WIFI_FB_B5G,		//5G
	WIFI_FB_B6G,		//6G
	WIFI_FB_COUNT
}EU_WIFI_FB_IDX;


//WiFi标准(WiFi Standard)序列号
typedef enum tagEU_WIFI_STAN_IDX
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
	WIFI_STAN_80211AX_20M,
	WIFI_STAN_80211AX_40M,
	WIFI_STAN_80211AX_5G_20M,
	WIFI_STAN_80211AX_5G_40M,
	WIFI_STAN_80211AX_5G_80M,
	WIFI_STAN_80211N_5G_40M,
	WIFI_STAN_80211AH_1M,
	WIFI_STAN_80211AH_2M,
	WIFI_STAN_80211AH_4M,
	WIFI_STAN_80211AH_8M,
	WIFI_STAN_80211AH_16M,
	WIFI_STAN_80211AX_5G_160M,
	WIFI_STAN_80211AX_6G_20M,	//WiFi6E
	WIFI_STAN_80211AX_6G_40M,
	WIFI_STAN_80211AX_6G_80M,
	WIFI_STAN_80211AX_6G_160M,
	WIFI_STAN_80211BE_20M,		//WiFi7
	WIFI_STAN_80211BE_40M,
	WIFI_STAN_80211BE_5G_20M,	//WiFi7
	WIFI_STAN_80211BE_5G_40M,
	WIFI_STAN_80211BE_5G_80M,
	WIFI_STAN_80211BE_5G_160M,
	WIFI_STAN_80211BE_6G_20M,	//WiFi7
	WIFI_STAN_80211BE_6G_40M,
	WIFI_STAN_80211BE_6G_80M,
	WIFI_STAN_80211BE_6G_160M,
	WIFI_STAN_80211BE_6G_320M,
	WIFI_STAN_COUNT
}EU_WIFI_STAN_IDX;


//蓝牙版本序列号
typedef enum tagEU_BLU_VER_IDX
{
	BLU_VER_10_BR = 0,
	BLU_VER_20_EDR,
	BLU_VER_40_BLE,		//Bluetooth Low Energy
	BLU_VER_COUNT
}EU_BLU_VER_IDX;


//NR 5G SUB6 频段序列号
typedef enum tagEU_NR5GSUB6_BAND_INDEX
{
	NR5GSUB6_N_1 = 0,
	NR5GSUB6_N_2,
	NR5GSUB6_N_3,
	NR5GSUB6_N_5,
	NR5GSUB6_N_7,
	NR5GSUB6_N_8,
	NR5GSUB6_N_20,
	NR5GSUB6_N_28,
	NR5GSUB6_N_41,
	NR5GSUB6_N_66,
	NR5GSUB6_N_71,
	NR5GSUB6_N_77,
	NR5GSUB6_N_78,
	NR5GSUB6_N_79,
	NR5GSUB6_N_12,
	NR5GSUB6_N_25,
	NR5GSUB6_N_48,
	NR5GSUB6_N_38,
	NR5GSUB6_N_40,
	NR5GSUB6_N_14,
	NR5GSUB6_N_13,
	NR5GSUB6_N_18,
	NR5GSUB6_N_26,
	NR5GSUB6_N_29,
	NR5GSUB6_N_30,
	NR5GSUB6_N_75,
	NR5GSUB6_N_76,
	NR5GSUB6_N_91,
	NR5GSUB6_N_92,
	NR5GSUB6_N_93,
	NR5GSUB6_N_94,
	NR5GSUB6_N_70,
	NR5GSUB6_N_257,
	NR5GSUB6_N_258,
	NR5GSUB6_N_260,
	NR5GSUB6_N_261,
	NR5GSUB6_N_255,			//NTN 1.6GHz, FDD
	NR5GSUB6_N_256,			//NTN 2GHz, FDD
	NR5GSUB6_N_46,			//TD Unlicensed, TDD
	NR5GSUB6_N_28A,			//NR 5G SUB6 28A 对应的频段数字为 2801
	NR5GSUB6_N_28B,			//NR 5G SUB6 28B 对应的频段数字为 2802
	NR5GSUB6_N_53,			//n53
	NR5GSUB6_N_39,			//n39
	NR5GSUB6_N_67,			//n67, RX ONLY
	NR5GSUB6_N_50,			//n50
	NR5GSUB6_N_COUNT,		//NR 5G SUB6 频段数量
	NR5GSUB6_N_SIZE = 49	//NR 5G SUB6 频段相关的存储BUFF尺寸（“尺寸”必须比“数量”至少大1, 用于存放结束符）
}EU_NR5GSUB6_BAND_INDEX;


//NR 5G MMW 毫米波频段序列号
typedef enum tagEU_NR5GMMW_BAND_INDEX
{
	NR5GMMW_N_257 = 0,
	NR5GMMW_N_258,
	NR5GMMW_N_260,
	NR5GMMW_N_261,
	NR5GMMW_N_COUNT,		//NR 5G MMW 频段数量
	NR5GMMW_N_SIZE = 8		//NR 5G MMW 频段相关的存储BUFF尺寸（“尺寸”必须比“数量”至少大1, 用于存放结束符）
}EU_NR5GMMW_BAND_INDEX;


//NTN 频段序列号( Index 号 )
typedef enum tagEU_NTN_BAND_INDEX
{
	NTN_IDX_B_23 = 0,	//NTN B23 Index 号
	NTN_IDX_B_255,		//NTN B255 Index 号
	NTN_IDX_B_256,		//NTN B256 Index 号
	NTN_IDX_B_COUNT,	//NTN 频段数量
	NTN_IDX_B_SIZE = 8	//NTN 频段相关的存储BUFF尺寸（“尺寸”必须比“数量”至少大1, 用于存放结束符）
}EU_NTN_BAND_INDEX;


//Lora频点(FreqBand)序号
typedef enum tagEU_LORA_VER_IDX
{
	LORA_FB_SR_LORA_L400PLUS = 0,
	LORA_FB_SR_LORA_H800PLUS,
	LORA_FB_COUNT
}EU_LORA_VER_IDX;


//Lora STAN
typedef enum tagEU_LORA_STAN_IDX
{
	LORA_STAN_470500000 = 0,
	LORA_STAN_488500000,
	LORA_STAN_509500000,
	LORA_STAN_863500000,
	LORA_STAN_902500000,
	LORA_STAN_926500000,
	LORA_STAN_868300000,
	LORA_STAN_868950000,
	LORA_STAN_COUNT
}EU_LORA_STAN_IDX;


//Lora NS FT Item
typedef enum EU_LORA_NS_FT_ITEM_IDX
{
	LORANFI_TX_PWR = 0,
	LORANFI_FREQ_ERR,
	LORANFI_RX_PER,
	LORANFI_COUNT
}EU_LORA_NS_FT_ITEM_IDX;
//天线类型序列号
typedef enum tagEU_ANT_TYPE_INDEX
{
	ANT_TYPE_IDX_NDF = -1,
	ANT_TYPE_IDX_MAIN_1 = 0,
	ANT_TYPE_IDX_DIV_1,
	ANT_TYPE_IDX_GPS,
	ANT_TYPE_IDX_WIFI_BLU,
	ANT_TYPE_IDX_DIV_GPS,
	ANT_TYPE_IDX_MULTI_DG,
	ANT_TYPE_IDX_MULTI_M,
	ANT_TYPE_IDX_MULTI_M1,
	ANT_TYPE_IDX_MULTI_M2,
	ANT_TYPE_IDX_NR5GSUB6_1,
	ANT_TYPE_IDX_NR5GSUB6_2,
	ANT_TYPE_IDX_NR5GSUB6_3,
	ANT_TYPE_IDX_NR5GSUB6_4,
	ANT_TYPE_IDX_NR5GSUB6_5,
	ANT_TYPE_IDX_NR5GSUB6_6,
	ANT_TYPE_IDX_NR5GSUB6_7,
	ANT_TYPE_IDX_NR5GSUB6_8,
	ANT_TYPE_IDX_MAIN_2,
	ANT_TYPE_IDX_DIV_2,
	ANT_TYPE_IDX_MULTI_M3,
	ANT_TYPE_IDX_MULTI_M4,
	ANT_TYPE_IDX_WIFI_MIMO,
	ANT_TYPE_IDX_V2X_MAIN,
	ANT_TYPE_IDX_V2X_DIV,
	ANT_TYPE_IDX_DSDA_MAIN,
	ANT_TYPE_IDX_DSDA_DIV,
	ANT_TYPE_IDX_V2X_TRX0,
	ANT_TYPE_IDX_V2X_TRX1,
	ANT_TYPE_IDX_NR5GSUB6_9,
	ANT_TYPE_IDX_NR5GSUB6_10,
	ANT_TYPE_IDX_NR5GSUB6_11,
	ANT_TYPE_IDX_NR5GSUB6_12,
	ANT_TYPE_IDX_WIFI_BLU_GPS,
	ANT_TYPE_IDX_BLU_ONLY,
	ANT_TYPE_IDX_ECALL,
	ANT_TYPE_IDX_WIFI_0,
	ANT_TYPE_IDX_LORA,
	ANT_TYPE_IDX_R2_WIFI_BLU,
	ANT_TYPE_IDX_COUNT,			//天线类型的总数量
	ANT_TYPE_IDX_SIZE = 44,		//“每个天线（所有天线）都有自己的参数存储BUFF”的尺寸（“尺寸”必须比“天线类型的总数量”至少大1, 用于存放结束符）
	ANT_TYPE_BUFF_SIZE = 16		//“每个机型拥有的天线（有限天线）的参数存储BUFF”天线的存储BUFF尺寸（“尺寸”必须比“机型拥有的天线数量”至少大1, 用于存放结束符）
	//天线的存储BUFF尺寸占用内存空间资源太多，存储天线数据的相关结构体未来最好还是要调整为“有限天线”的排序式存储。
}EU_ANT_TYPE_INDEX;


//ASR 平台 RF Key Type
typedef enum tagEU_RF_KEY_TYPE_INDEX
{
	RF_KEY_TYPE_IDX_NDF = -1,
	RF_KEY_TYPE_IDX_PXA1802S_RF858 = 0,		//ASR平台RF Type:"1802S+RF858"
	RF_KEY_TYPE_IDX_PAX1908_RF858,			//ASR平台RF Type:"1802+RF858"
	RF_KEY_TYPE_IDX_RF866,					//ASR平台RF Type:"1826+RF866"
	RF_KEY_TYPE_IDX_RF859C,					//ASR平台RF Type:"1802S+RF859C"
	RF_KEY_TYPE_IDX_1601_3601,				//ASR平台RF Type:"3601_1601"
	RF_KEY_TYPE_IDX_1603,					//ASR平台RF Type:"1603"
	RF_KEY_TYPE_IDX_3603,					//ASR平台RF Type:"3603"
	RF_KEY_TYPE_IDX_1803_FAICON,			//ASR平台RF Type:"1803"
	RF_KEY_TYPE_IDX_1606,					//ASR平台RF Type:"1606"
	RF_KEY_TYPE_IDX_1828_RF866,				//ASR平台RF Type:"1828+RF866"
	RF_KEY_TYPE_IDX_1602,					//ASR平台RF Type:"1602"
	RF_KEY_TYPE_IDX_1806,					//ASR平台RF Type:"1806"
	RF_KEY_TYPE_IDX_1828_RF866S,			//ASR平台RF Type:"1828+RF866S，与1828+RF866区分"
	RF_KEY_TYPE_IDX_1609,					//ASR平台RF Type:"1609"
	RF_KEY_TYPE_IDX_1607,					//ASR平台RF Type:"1607"，与1609共用
	RF_KEY_TYPE_IDX_1903,					//ASR平台RF Type:"1903"
	RF_KEY_TYPE_IDX_1605,					//ASR平台RF Type:"1605"，暂时与1602共用，待平台区分后再更改
	RF_KEY_TYPE_IDX_1901_RF869,				//ASR平台RF Type:"1901+RF869"
	RF_KEY_TYPE_IDX_8601,					//ASR平台RF Type:"8601"
	RF_KEY_TYPE_IDX_COUNT
}EU_RF_KEY_TYPE_INDEX;



//“网络制式”规范
#define FORMAT_GSM_S			0
#define FORMAT_WCDMA_S			1
#define FORMAT_C2K_S			2
#define FORMAT_GSM_NS			3
#define FORMAT_WCDMA_NS			4
#define FORMAT_TD_NS			5
#define FORMAT_LTE_NS			6
#define FORMAT_C2K_NS			7
#define FORMAT_NBIOT_S			8
#define FORMAT_NBIOT_NS			9
#define FORMAT_NR5GSUB6_NS		10
#define FORMAT_GPS_NS			11
#define FORMAT_WIFI_NS			12
#define FORMAT_BLUETOOTH_NS		13
#define FORMAT_CV2X_NS			14
#define FORMAT_NR5GMMW_NS		15
#define FORMAT_NTN_NS			16
#define FORMAT_LORA_NS			17



//高、中、低信道标识
#define CH_ALL					-1
#define CH_LOW					0
#define CH_MID					1
#define CH_HIGH					2
#define CH_LOW_EX				3
#define CH_LMH_COUNT			4



//仪器型号
#define CMU200					0
#define AG_E1960				1
#define AG_E1968				2
#define AG6601A					3
#define MT8820					4
#define CMD55					5
#define AG8922					6
#define CMW500					7
#define AG_E1987A				8
#define AG_E1962B				9
#define LP_IQXS					10
#define CMW100					11
#define LP_IQXM					12
#define LP_5G_IQXS				13
#define CMP180					14
#define	MT8870A					15
#define	WZ_T6290E				16
#define LP_IQXEL_MW				17
#define LP_5GQ_IQXS				18



//仪器未测试到结果的标识
#define ERROR_RTN_VALUE			9.91E9	//9.91E37



//结构体、变量等初始化所用统一值
#define DEFAULT_INIT_VALUE			-999.0	//结构体、变量等初始化所用统一值



//DUT端ANT天线组合与仪器端RF口接线方案
#define PLAN_ANT4_MAIN1_DIV1_GPS1_WIFI1			1//4根ANT天线, “1主集 + 1分集 + 1GPS + 1WiFi蓝牙”
#define PLAN_ANT4_MAIN2_DIV2					2//4根ANT天线, “2根MAIN主天线 + 2根DIV分集天线”



//当前测试的RF通路（RF链路）
#define RX_CHAIN_MAIN			1
#define RX_CHAIN_DIV			2
#define RX_CHAIN_GPS			3
#define RX_CHAIN_MAIN_DIV		4
//通用的“unsigned char”BUFF
typedef struct tagPKT_BUFF_S
{
	unsigned char * ucp_Buff;
	unsigned long ul_Total_Size;
	unsigned long ul_Data_Length;
	//结构体/构造函数初始化
	tagPKT_BUFF_S() : ucp_Buff( NULL ), ul_Total_Size( 0 ), ul_Data_Length( 0 )
	{
		//定义变量时, 如果没有给出变量的值, 就都赋值成0, 否则按照实际的值来赋值。
	}
}PKT_BUFF_S;



//测试流程属性
#define PROCESS_ATT_ERROR			-1//无法识别的测试流程属性
#define PROCESS_ATT_ALL_TEST		0//全检流程
#define PROCESS_ATT_ONLY_LABEL		1//只打标签
#define PROCESS_ATT_TO_DL			2//只做到DL
#define PROCESS_ATT_TO_BT			3//只做到BT
#define PROCESS_ATT_TO_FT			4//只做到FT
#define PROCESS_ATT_TO_FCT			5//只做到FCT



//仪器线损结构体 V1版
typedef struct tagTESTER_RF_OFFSET_S
{
	double dr_GSM_RF_Loss[G_BAND_SIZE * 6];		//依据每个GSM频段的低、中、高信道存放损耗值
	double dr_W_RF_Loss[W_BAND_SIZE * 2];		//依据每个W频段的index号存放损耗值
	double dr_TD_RF_Loss[TD_BAND_SIZE * 2];		//依据每个TD频段的index号存放损耗值
	double dr_C2K_RF_Loss[C2K_BC_SIZE * 2];		//依据每个cdma2000频段的index号存放损耗值
	double dr_LTE_RF_Loss[L_BAND_SIZE * 2];		//依据每个LTE频段的index号存放损耗值
	double dr_NBIoT_RF_Loss[NB_IDX_B_SIZE * 2];	//依据每个NB-IoT频段的index号存放损耗值
}TESTER_RF_OFFSET_S;



//仪器线损结构体 V2版
typedef struct tagTESTER_RF_OFFSET_V2_S
{
	double dr_GSM_RF_Loss[G_BAND_SIZE * 6];				//依据每个GSM频段index号的低、中、高信道存放线损值
	double dr_W_RF_Loss[W_BAND_SIZE * 6];				//依据每个W频段的index号的低、中、高信道存放线损值
	double dr_TD_RF_Loss[TD_BAND_SIZE * 6];				//依据每个TD频段的index号的低、中、高信道存放线损值
	double dr_C2K_RF_Loss[C2K_BC_SIZE * 6];				//依据每个cdma2000频段的index号的低、中、高信道存放线损值
	double dr_LTE_RF_Loss[L_BAND_SIZE * 6];				//依据每个LTE频段的index号的低、中、高信道存放线损值
	double dr_NBIoT_RF_Loss[NB_IDX_B_SIZE * 6];			//依据每个NB-IoT频段的index号的低、中、高信道存放线损值
	double dr_NR_5G_SUB6_RF_Loss[NR5GSUB6_N_SIZE * 6];	//5G NR SUB6 频段的index号的低、中、高信道存放线损值
	double dr_GPS_RF_Loss[2];							//GPS的 1.57G 一个频点的存放线损值
	double dr_WiFi_RF_Loss[WIFI_FB_COUNT * 6];			//WiFi的2.4G和5G频点的低、中、高信道存放线损值
	double dr_BLU_RF_Loss[2];							//蓝牙的 2.4G 一个频点的存放线损值
	double dr_CV2X_RF_Loss[CV2X_BAND_SIZE * 6];			//依据每个CV2X频段的index号的低、中、高信道存放线损值
	double dr_LORA_RF_Loss[LORA_FB_COUNT * 6];			//Lora频点的低、中、高信道存放线损值
}TESTER_RF_OFFSET_V2_S;



//仪器配置参数结构体
typedef struct tagTESTER_CONFIG_S
{
	int i_GPIB_Card_Numb;		//卡号
	int i_GPIB_Card_Type;		//卡类型
	int i_GPIB_Addr_Tester;		//仪器地址
	int i_GPIB_Addr_PS;			//电源地址
	bool b_Ctrl_PS;				//是否控电源
	int i_Instru_Option;		//具体仪器型号 或 可自动识别仪器
	CStringW cs_IP_SN;			//用IP或SN访问仪器
	int i_RF_Port_Numb;			//仪器的指定RF端口, 工具界面选择输入RF端口号(一般为多RF端口仪器的设置)
	TESTER_RF_OFFSET_S str_Instru_RF_Loss;	//仪器各频段线损
}TESTER_CONFIG_S;



//测试台配置参数
typedef struct tagTS_CONFIG_S
{
	int i_Com_Port;				//DM 通信口（通用口）
	int i_Com_AT_Port;			//AT 通信口
	int i_BR;					//波特率
	int i_TS_Curr_Type_Option;	//当前运行(选择)的“测试工位种类、制式(例如:GSM、WCDMA、2G+3G、2G+3G+4G等选择)”
	bool b_Debug_Log_File;		//保存 debug log 文件
}TS_CONFIG_S;
//MOB产品定制测试台配置参数
typedef struct tagTS_CONFIG_MOB_S
{
	int i_Com_Port;				//DM 通信口（通用口）
	int i_Com_AT_Port;			//AT 通信口
	int i_Com_MCU_Port;			//MCU 通信口
	int i_Com_DBG_Port;			//DBG 通信口
	int i_BR;					//波特率
	int i_TS_Curr_Type_Option;	//当前运行(选择)的“测试工位种类、制式(例如:GSM、WCDMA、2G+3G、2G+3G+4G等选择)”
	bool b_Debug_Log_File;		//保存 debug log 文件
	CString cs_BT_MAC;			//广播的蓝牙地址，从界面输入
	double d_GPS_Loss;          //GPS LOSS
}TS_CONFIG_MOB_S;



//频段配置参数
typedef struct tagBAND_CONFIG_S
{
	int i_Band_Name;			//频段名（2G使用index号）,“-1”代表不启用
	int i_Tx_Quan;				//频段的TX数量
	int ir_Rx_For_Tx_Quan[8];	//频段每个TX对应的RX数量
}BAND_CONFIG_S;



//频段结构体 V1版
typedef struct tagBAND_LIST_S
{
	int ir_GSM_Band_List[G_BAND_SIZE];		//GSM“频段index值”列表，“-1”代表结束
	int ir_WCDMA_Band_List[W_BAND_SIZE];	//WCDMA“频段值”列表，“-1”代表结束
	int ir_C2K_Band_List[C2K_BC_SIZE];		//cdma2000“频段值”列表，“-1”代表结束
	int ir_TD_Band_List[TD_BAND_SIZE];		//TD“频段值”列表，“-1”代表结束
	int ir_LTE_Band_List[L_BAND_SIZE];		//LTE“频段值”列表，“-1”代表结束
	int ir_NBIoT_Band_List[NB_IDX_B_SIZE];	//NB-IoT“频段值”列表，“-1”代表结束
	int i_GSM_Band_Quan;	//GSM“频段”数量
	int i_WCDMA_Band_Quan;	//WCDMA“频段”数量
	int i_C2K_Band_Quan;	//cdma2000“频段”数量
	int i_TD_Band_Quan;		//TD“频段”数量
	int i_LTE_Band_Quan;	//LTE“频段”数量
	int i_NBIoT_Band_Quan;	//NB-IoT“频段”数量
}BAND_LIST_S;



//单个天线对应的频段结构体 V2版
typedef struct tagBAND_LIST_V2_S
{
	int ir_GSM_Band_List[G_BAND_SIZE];				//GSM“频段index值”列表，“-1”代表结束
	int ir_WCDMA_Band_List[W_BAND_SIZE];			//WCDMA“频段值”列表，“-1”代表结束
	int ir_C2K_Band_List[C2K_BC_SIZE];				//cdma2000“频段值”列表，“-1”代表结束
	int ir_TD_Band_List[TD_BAND_SIZE];				//TD“频段值”列表，“-1”代表结束
	int ir_LTE_Band_List[L_BAND_SIZE];				//LTE“频段值”列表，“-1”代表结束
	int ir_NBIoT_Band_List[NB_IDX_B_SIZE];			//NB-IoT“频段值”列表，“-1”代表结束
	int ir_NR_5G_SUB6_Band_List[NR5GSUB6_N_SIZE];	//NR 5G SUB6 “频段值”列表，“-1”代表结束
	int ir_CV2X_Band_List[CV2X_BAND_SIZE];			//C-V2X“频段值”列表，“-1”代表结束
	int i_GSM_Band_Quan;		//GSM“频段”数量
	int i_WCDMA_Band_Quan;		//WCDMA“频段”数量
	int i_C2K_Band_Quan;		//cdma2000“频段”数量
	int i_TD_Band_Quan;			//TD“频段”数量
	int i_LTE_Band_Quan;		//LTE“频段”数量
	int i_NBIoT_Band_Quan;		//NB-IoT“频段”数量
	int i_NR_5G_SUB6_Band_Quan;	//NR 5G SUB6 “频段”数量
	int i_CV2X_Band_Quan;		//C-V2X“频段”数量
	BAND_CONFIG_S strr_GSM_Band_CFG[G_BAND_SIZE];				//2G “频段配置参数”
	BAND_CONFIG_S strr_WCDMA_Band_CFG[W_BAND_SIZE];				//WCDMA “频段配置参数”
	BAND_CONFIG_S strr_LTE_Band_CFG[L_BAND_SIZE];				//LTE “频段配置参数”
	BAND_CONFIG_S strr_NR_5G_SUB6_Band_CFG[NR5GSUB6_N_SIZE];	//NR 5G SUB6 “频段配置参数”
}BAND_LIST_V2_S;



//DUT单个天线名和属性结构体
typedef struct tagANT_PROP_S
{
	EU_ANT_TYPE_INDEX eu_ANT_HW_Type_Name;	//硬件实体天线（类型）名,“-1”代表无天线
	int i_ANT_SW_Numb;						//高通定义的软件天线号（0~7）, 无此号码则设定为“-1”
}ANT_PROP_S;


//天线列表结构体
typedef struct tagANT_LIST_S
{
	ANT_PROP_S strr_ANT_Prop_List[ANT_TYPE_BUFF_SIZE];			//DUT的天线（属性、Index号）列表（以天线Index号列表排列，以“-1”结尾）
	int i_ANT_Quan;												//DUT的天线数量
}ANT_LIST_S;


//DUT所有天线完整结构体 V1 版
typedef struct tagANT_CFG_ALL_S
{
	ANT_LIST_S str_ANT_List;									//DUT的所有天线（属性、Index号）列表
	TESTER_RF_OFFSET_V2_S strr_ANT_RF_Loss[ANT_TYPE_IDX_SIZE];	//天线的所有频段“线损”（以“天线Index号”作为结构体数组Buff的存储、访问index号）
}ANT_CFG_ALL_S;


//DUT所有天线完整结构体 V2 版
typedef struct tagANT_CFG_ALL_V2_S
{
	ANT_LIST_S str_ANT_List;											//DUT的所有天线（属性、Index号）列表
	TESTER_RF_OFFSET_V2_S strr_ANT_RF_Loss_List[ANT_TYPE_BUFF_SIZE];	//DUT的天线的所有频段“线损”（以“str_ANT_List”中的“天线Index号的排列顺序”作为结构体数组Buff的“存储顺序”，不再存储用不到的天线）
}ANT_CFG_ALL_V2_S;


//单个天线、单个频段的金板低中高信道数据
typedef struct tagREF_DATA_BASIC_S
{
	int i_Band_Name_And_Enable;										//Band名 和 Band使能标识
	double dr_Tx_Power[CH_LMH_COUNT];								//TX金板功率数据
	double dr_Rx_Level[CH_LMH_COUNT];								//RX金板接收电平数据
}REF_DATA_BASIC_S;


//单个天线、所有频段的金板数据
typedef struct tagREF_DATA_BAND_S
{
	REF_DATA_BASIC_S strr_GSM_REF_Data[G_BAND_SIZE];				//2G 所有频段的金板数据（用频段index号存储，像线损那样存储）
	REF_DATA_BASIC_S strr_WCDMA_REF_Data[W_BAND_SIZE];				//WCDMA 所有频段的金板数据（用频段index号存储，像线损那样存储）
	REF_DATA_BASIC_S strr_C2K_REF_Data[C2K_BC_SIZE];				//cdma2000 所有频段的金板数据（用频段index号存储，像线损那样存储）
	REF_DATA_BASIC_S strr_TD_REF_Data[TD_BAND_SIZE];				//TD 所有频段的金板数据（用频段index号存储，像线损那样存储）
	REF_DATA_BASIC_S strr_LTE_REF_Data[L_BAND_SIZE];				//LTE 所有频段的金板数据（用频段index号存储，像线损那样存储）
	REF_DATA_BASIC_S strr_NBIoT_REF_Data[NB_IDX_B_SIZE];			//NB-IoT 所有频段的金板数据（用频段index号存储，像线损那样存储）
	REF_DATA_BASIC_S strr_NR_5G_SUB6_REF_Data[NR5GSUB6_N_SIZE];		//NR 5G SUB6 所有频段的金板数据（用频段index号存储，像线损那样存储）
	REF_DATA_BASIC_S strr_CV2X_REF_Data[CV2X_BAND_SIZE];			//C-V2X 所有频段的金板数据（用频段index号存储，像线损那样存储）
	REF_DATA_BASIC_S str_GPS_REF_Data;								//GPS的金板数据（用频段index号存储，像线损那样存储）
	REF_DATA_BASIC_S strr_WiFi_REF_Data[WIFI_FB_COUNT];				//WiFi的2.4G和5G的金板数据（用频段index号存储，像线损那样存储）
	REF_DATA_BASIC_S str_Bluetooth_REF_Data;						//蓝牙的金板数据（用频段index号存储，像线损那样存储）
	REF_DATA_BASIC_S strr_Lora_REF_Data[LORA_FB_COUNT];				//Lora的金板数据（用频段index号存储，像线损那样存储）
}REF_DATA_BAND_S;


//所有天线、所有频段的金板数据 V1 版
typedef struct tagREF_DATA_ALL_S
{
	ANT_LIST_S str_Ref_ANT_List;									//金板制作和校准涉及的天线（属性、Index号）列表
	REF_DATA_BAND_S strr_Ref_Band_Data[ANT_TYPE_IDX_SIZE];			//天线的所有频段“金板数据”（以“天线Index号”作为结构体数组Buff的存储、访问index号）
}REF_DATA_ALL_S;


//所有天线、所有频段的金板数据 V2 版
typedef struct tagREF_DATA_ALL_V2_S
{
	ANT_LIST_S str_Ref_Ant_List;									//金板DUT所操作到的天线（属性、Index号）列表
	REF_DATA_BAND_S strr_Ref_Data_List[ANT_TYPE_BUFF_SIZE];			//金板DUT所操作到的天线的所有频段“金板数据”（以“str_Ref_Ant_List”中的“天线Index号的排列顺序”作为结构体数组Buff的“存储顺序”，不再存储用不到的天线）
}REF_DATA_ALL_V2_S;


//频段使能控制
typedef struct tagBAND_ENABLE_S
{
	int ir_GSM_Band_Enable[G_BAND_SIZE];				//GSM 使能列表，“0以下”代表不测试
	int ir_WCDMA_Band_Enable[W_BAND_SIZE];				//WCDMA 使能列表，“0以下”代表不测试
	int ir_C2K_Band_Enable[C2K_BC_SIZE];				//cdma2000 使能列表，“0以下”代表不测试
	int ir_TD_Band_Enable[TD_BAND_SIZE];				//TD 使能列表，“0以下”代表不测试
	int ir_LTE_Band_Enable[L_BAND_SIZE];				//LTE 使能列表，“0以下”代表不测试
	int ir_NBIoT_Band_Enable[NB_IDX_B_SIZE];			//NB-IoT 使能列表，“0以下”代表不测试
	int ir_NR_5G_SUB6_Band_Enable[NR5GSUB6_N_SIZE];		//NR 5G SUB6 使能列表，“0以下”代表不测试
	int ir_CV2X_Band_Enable[CV2X_BAND_SIZE];			//C-V2X 使能列表，“0以下”代表不测试
}BAND_ENABLE_S;



//机型“通用参数”（与exe界面设置匹配）
typedef struct tagPRODU_PARAMS_GEN_S
{
	CString cs_Produ_Name;			//机型名
	int i_Platform_Solution;		//平台方案
	int i_BB_Chip;					//BB芯片型号
	int ir_TS_Type_Seq[10];			//测试工位(Flag相关)列表, 测试属性列表
	BAND_LIST_V2_S str_Band_List;	//机型的完整频段数据
	CString cs_Produ_Params_File;	//参数文件路径
}PRODU_PARAMS_GEN_S;



//线损单条记录结构体
typedef struct tagCABLE_LOSS_SET_S
{
	CString cs_BandName;//GSM_900、W Band1、T Band39、L Band1...
	double d_Tx_Low_Loss;
	double d_Tx_Mid_Loss;
	double d_Tx_High_Loss;
	double d_Rx_Low_Loss;
	double d_Rx_Mid_Loss;
	double d_Rx_High_Loss;
}CABLE_LOSS_SET_S;
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
	USHORT TranslationFieldsValid : 1;      // 6A  53
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
#define PRODU_TYPE_MOB				7//Module On Board
#define PRODU_TYPE_COB				8//Chip On Board
#define PRODU_TYPE_ASM				9//Assembly 整机（使用自定义流程）



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
	LTE_CAT_NDF = -1,	//未定义
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
	LTE_CAT_16,
	LTE_CAT_20,
	LTE_CAT_19,
	LTE_CAT_15,
	LTE_CAT_13,
	//
	LTE_CAT_COUNT
}EU_LTE_CAT_IDX;




//prototype of callback function
typedef void( __stdcall * CALLBACK_SHOW_REDIT_INFO )(const wchar_t * wcp_Msg, void * p_usr_Arg);
typedef void( __stdcall * CALLBACK_SHOW_STATE )(const wchar_t * wcp_State, void * p_usr_Arg);
typedef bool( __stdcall * CALLBACK_SHOW_TEST_RESULT )(const wchar_t * wcp_Name, double d_Low, double d_High, double d_Data, void * p_usr_Arg);
typedef void( __stdcall * CALLBACK_SAVE_TRACE_LOG )(const wchar_t * wcp_Trace_Log, void * p_usr_Arg);
typedef void( __stdcall * CALLBACK_SHOW_TITLE )(const wchar_t * wcp_Title, void * p_usr_Arg);
//参数读取接口
typedef bool( __stdcall * CALLBACK_LOAD_PRODU_PARAMS_GEN )(const wchar_t * wcp_Produ_Name, int i_Produ_Type, int i_Produ_Ver, void * p_usr_Arg);
typedef void( __stdcall * CALLBACK_OCP_GET_ERROR_INFO )(CString * csp_Error_Info, void * p_usr_Arg);
//
typedef bool( __stdcall * CALLBACK_READ_PRODU_GSM_BAND_LIST )(int * ip_GSM_Band_List, int * ip_GSM_Band_Quan, void * p_usr_Arg);
typedef bool( __stdcall * CALLBACK_READ_PRODU_WCDMA_BAND_LIST )(int * ip_WCDMA_Band_List, int * ip_WCDMA_Band_Quan, void * p_usr_Arg);
typedef bool( __stdcall * CALLBACK_READ_PRODU_C2K_BAND_LIST )(int * ip_C2K_Band_List, int * ip_C2K_Band_Quan, void * p_usr_Arg);
typedef bool( __stdcall * CALLBACK_READ_PRODU_TD_BAND_LIST )(int * ip_TD_Band_List, int * ip_TD_Band_Quan, void * p_usr_Arg);
typedef bool( __stdcall * CALLBACK_READ_PRODU_LTE_BAND_LIST )(int * ip_LTE_Band_List, int * ip_LTE_Band_Quan, void * p_usr_Arg);
typedef bool( __stdcall * CALLBACK_READ_PRODU_NBIOT_BAND_LIST )(int * ip_NBIoT_Band_List, int * ip_NBIoT_Band_Quan, void * p_usr_Arg);
//
typedef bool( __stdcall * CALLBACK_READ_PRODU_PF_AND_BB_CHIP )(int * ip_Platform_Solution, int * ip_BB_Chip, void * p_usr_Arg);
typedef bool( __stdcall * CALLBACK_READ_PRODU_TS_TYPE_SEQ )(int * ip_TS_Type_Seq, void * p_usr_Arg);
typedef bool( __stdcall * CALLBACK_READ_PRODU_INIT_TIME )(int * ip_Init_Time, void * p_usr_Arg);
typedef bool( __stdcall * CALLBACK_READ_PRODU_CAL_TREE_NAME )(CStringW * csp_Cal_Tree_Name, void * p_usr_Arg);
typedef bool( __stdcall * CALLBACK_READ_PRODU_VOLT_AND_CURR )(double * dp_Voltage, double * dp_Current, void * p_usr_Arg);
typedef bool( __stdcall * CALLBACK_READ_PRODU_LTE_CAT )(int * ip_LTE_CAT, void * p_usr_Arg);
typedef bool( __stdcall * CALLBACK_READ_PRODU_LANDI_ENABLE )(bool * bp_Landi_Enable, void * p_usr_Arg);
typedef bool( __stdcall * CALLBACK_READ_PRODU_WIFI_ENABLE )(bool * bp_WiFi_Enable, void * p_usr_Arg);
typedef bool( __stdcall * CALLBACK_READ_PRODU_NW_SCAN_MODE )(int * ip_Nw_Scan_Mode, void * p_usr_Arg);
typedef void( __stdcall * CALLBACK_READ_PRODU_HW_SIM_ENABLE )(const wchar_t * wcp_OC, bool * bp_HW_SIM_Enable, void * p_usr_Arg);
//
typedef void( __stdcall * CALLBACK_SHOW_PLC_REG_DATA )(int i_Addr, unsigned short us_Data, void * p_usr_Arg);
typedef void( __stdcall * CALLBACK_SEND_PLC_TRAY_DATA )(unsigned short us_Tray_Data, unsigned short us_TS_Data, const wchar_t * wcp_Barcode, void * p_usr_Arg);
typedef void( __stdcall * CALLBACK_UPDATE_TS_STATUS )(int i_TS_Channel, int i_TS_Status, void * p_usr_Arg);
typedef void( __stdcall * CALLBACK_UPDATE_TS_PFQUAN )(int i_TS_Channel, int i_Quan_Pass, int i_Quan_Fail, void * p_usr_Arg);
typedef void( __stdcall * CALLBACK_UPDATE_TS_TRD )(int i_TS_Channel, const wchar_t * wcp_TRD, void * p_usr_Arg);
//外部供电控制
typedef void( __stdcall * CALLBACK_EXT_PS_POWER_ON )(void * p_usr_Arg);
typedef void( __stdcall * CALLBACK_EXT_PS_POWER_OFF )(void * p_usr_Arg);
//callback 结构体 V2 中新增、追加的ocp函数接口
typedef bool( __stdcall * CALLBACK_READ_PRODU_PS_CH2_VOLT_AND_CURR )(double * dp_Voltage_CH2, double * dp_Current_CH2, void * p_usr_Arg);
typedef bool( __stdcall * CALLBACK_READ_PRODU_NETWORK_FORMAT_BAND_LIST )(int i_Network_Format, int * ip_Band_List, int * ip_Band_Quan, void * p_usr_Arg);
//callback 结构体 V3 中新增、追加的ocp函数接口
typedef bool( __stdcall * CALLBACK_READ_PRODU_NETWORK_FORMAT_BAND_ANT_LIST )(int i_Network_Format, int i_Rx_Chain_Type, int * ip_Band_ANT_List, int * ip_Band_ANT_Quan, void * p_usr_Arg);
typedef bool( __stdcall * CALLBACK_READ_PRODU_ANT_LIST )(ANT_PROP_S * strp_ANT_Prop_List, int * ip_ANT_Quan, void * p_usr_Arg);
//callback 结构体 sql_db 函数接口
typedef bool( __stdcall * CALLBACK_FIND_READ_REF_STD_2017_CONN_V1 )(const wchar_t * wcp_Key_IMEI, CString & oj_cs_Ref_Produ_Name, CString & oj_cs_Ref_Data_Str, CString & oj_Ref_OC, CString & oj_Ref_Make_Date, CString & oj_cs_Err_Info, void * p_usr_Arg);
//callback 结构体 Open-Short金板使用中切换OS金板用到的对exe层面的回调操作处理 函数接口
typedef bool( __stdcall * CALLBACK_REF_OS_SWITCH_OPEN )(CString & oj_cs_Barcode_Of_Open, void * p_usr_Arg);
typedef bool( __stdcall * CALLBACK_REF_OS_SWITCH_SHORT )(CString & oj_cs_Barcode_Of_Short, void * p_usr_Arg);




//主界面显示 callback 结构体
typedef struct tagQTI_PROG_ARG
{
	//qti progress callback
	void *							p_usr_Arguments;
	CALLBACK_SHOW_REDIT_INFO		cb_Show_REdit_Info;
	CALLBACK_SHOW_STATE				cb_Show_State;
	CALLBACK_SHOW_TEST_RESULT		cb_Show_Test_Result;
	CALLBACK_SAVE_TRACE_LOG			cb_Save_Trace_Log;
	CALLBACK_SHOW_TITLE				cb_Show_Title;
}QTI_PROG_ARG;



//读取、输入OCP参数的 callback 结构体 V1
typedef struct tagREAD_OCP_PARAMS_ARG
{
	//read ocp params callback
	void *									p_usr_Arguments;
	//
	CALLBACK_LOAD_PRODU_PARAMS_GEN			cb_Load_Produ_Params_Gen;
	CALLBACK_OCP_GET_ERROR_INFO				cb_OCP_Get_Error_Info;
	//
	CALLBACK_READ_PRODU_GSM_BAND_LIST		cb_Read_Produ_GSM_Band_List;
	CALLBACK_READ_PRODU_WCDMA_BAND_LIST		cb_Read_Produ_WCDMA_Band_List;
	CALLBACK_READ_PRODU_C2K_BAND_LIST		cb_Read_Produ_C2K_Band_List;
	CALLBACK_READ_PRODU_TD_BAND_LIST		cb_Read_Produ_TD_Band_List;
	CALLBACK_READ_PRODU_LTE_BAND_LIST		cb_Read_Produ_LTE_Band_List;
	CALLBACK_READ_PRODU_NBIOT_BAND_LIST		cb_Read_Produ_NBIoT_Band_List;
	//
	CALLBACK_READ_PRODU_PF_AND_BB_CHIP		cb_Read_Produ_PF_And_BB_Chip;
	CALLBACK_READ_PRODU_TS_TYPE_SEQ			cb_Read_Produ_TS_Type_Seq;
	CALLBACK_READ_PRODU_INIT_TIME			cb_Read_Produ_Init_Time;
	CALLBACK_READ_PRODU_CAL_TREE_NAME		cb_Read_Produ_Cal_Tree_Name;
	CALLBACK_READ_PRODU_VOLT_AND_CURR		cb_Read_Produ_Volt_And_Curr;
	CALLBACK_READ_PRODU_LTE_CAT				cb_Read_Produ_LTE_CAT;
	CALLBACK_READ_PRODU_LANDI_ENABLE		cb_Read_Produ_Landi_Enable;
	CALLBACK_READ_PRODU_WIFI_ENABLE			cb_Read_Produ_WiFi_Enable;
	CALLBACK_READ_PRODU_NW_SCAN_MODE		cb_Read_Produ_Nw_Scan_Mode;
	CALLBACK_READ_PRODU_HW_SIM_ENABLE		cb_Read_Produ_HW_SIM_Enable;
}READ_OCP_PARAMS_ARG;



//读取、输入OCP参数的 callback 结构体 V2 （新增、追加的ocp函数接口）
typedef struct tagREAD_OCP_PARAMS_V2_ARG
{
	//read ocp params callback
	void *												p_usr_Arguments;
	//
	CALLBACK_READ_PRODU_PS_CH2_VOLT_AND_CURR			cb_Read_Produ_PS_CH2_Volt_And_Curr;
	CALLBACK_READ_PRODU_NETWORK_FORMAT_BAND_LIST		cb_Read_Produ_Network_Format_Band_List;
}READ_OCP_PARAMS_V2_ARG;



//读取、输入OCP参数的 callback 结构体 V3 （新增、追加的ocp函数接口）
typedef struct tagREAD_OCP_PARAMS_V3_ARG
{
	//read ocp params callback
	void *												p_usr_Arguments;
	//
	CALLBACK_READ_PRODU_NETWORK_FORMAT_BAND_ANT_LIST	cb_Read_Produ_Network_Format_Band_ANT_List;
	CALLBACK_READ_PRODU_ANT_LIST						cb_Read_Produ_ANT_List;
}READ_OCP_PARAMS_V3_ARG;
//控制中心数据传输 callback 结构体
typedef struct tagCTU_PROG_ARG
{
	//ctu(控制中心) progress callback
	void *							p_usr_Arguments;
	CALLBACK_SHOW_REDIT_INFO		cb_Show_REdit_Info;
	CALLBACK_SHOW_PLC_REG_DATA		cb_Show_PLC_Reg_Data;
	CALLBACK_SEND_PLC_TRAY_DATA		cb_Send_PLC_Tray_Data;
	CALLBACK_UPDATE_TS_STATUS		cb_Update_TS_Status;
	CALLBACK_UPDATE_TS_PFQUAN		cb_Update_TS_PFQuan;
	CALLBACK_UPDATE_TS_TRD			cb_Update_TS_TRD;
}CTU_PROG_ARG;



//外部供电的控制 callback 结构体
typedef struct tagEXT_PS_ARG
{
	//外部供电的控制回调接口
	void *							p_usr_Arguments;
	CALLBACK_EXT_PS_POWER_ON		cb_Ext_PS_Power_On;
	CALLBACK_EXT_PS_POWER_OFF		cb_Ext_PS_Power_Off;
}EXT_PS_ARG;
//用于 sql_db 操作的 callback 结构体 V1
typedef struct tagOP_SQL_DB_V1_ARG
{
	//sql_db 操作的 callback
	void *										p_usr_Arguments;
	//
	CALLBACK_FIND_READ_REF_STD_2017_CONN_V1		cb_Find_Read_REF_STD_2017_CONN_V1;
}OP_SQL_DB_V1_ARG;



//Open-Short金板使用中切换OS金板用到的对exe层面的回调操作处理
typedef struct tagOP_REF_OS_SWITCH_V1_ARG
{
	//REF_OS 对exe层面的回调操作处理的 callback
	void *								p_usr_Arguments;
	//
	CALLBACK_REF_OS_SWITCH_OPEN			cb_Ref_Os_Switch_Open;	//切换Open金板
	CALLBACK_REF_OS_SWITCH_SHORT		cb_Ref_Os_Switch_Short;	//切换Short金板
}OP_REF_OS_SWITCH_V1_ARG;




//
class CGFC
{
public:
	CGFC( void );
	~CGFC( void );
	void WCSTOK_INT( const wchar_t * wcp_StrToken, int * ip_List, int * ip_Quan );
	void WCSTOK_DOUBLE( const wchar_t * wcp_StrToken, double * dp_List, int * ip_Quan );
	bool WCSTOK_STRING_C( const wchar_t * wcp_StrToken, const wchar_t * wcp_StrDelimit, int i_Get_Index, CString * csp_Get_CString );
	bool WCSTOK_STRING_S( const wchar_t * wcp_StrToken, int i_Get_Index, CString * csp_Get_CString );
	void BUFF_BYTE_CALLOC( unsigned char ** ucp2_Buff, unsigned long ul_Buff_Size );
	void BUFF_BYTE_FREE( unsigned char ** ucp2_Buff );
	void BUFF_CHAR_CALLOC( char ** cp2_Buff, unsigned long ul_Buff_Size );
	void BUFF_CHAR_FREE( char ** cp2_Buff );
	void BUFF_DOUBLE_CALLOC( double ** dp2_Buff, unsigned long ul_Buff_Size );
	void BUFF_DOUBLE_FREE( double ** dp2_Buff );
	void BUFF_DWORD_CALLOC( DWORD ** dwp2_Buff, unsigned long ul_Buff_Size );
	void BUFF_DWORD_FREE( DWORD ** dwp2_Buff );
	void BUFF_WCHAR_CALLOC( wchar_t ** wcp2_Buff, unsigned long ul_Buff_Size );
	void BUFF_WCHAR_FREE( wchar_t ** wcp2_Buff );
	bool Confirm_Reg_Com_Port( const int i_Tgt_Com_Port );
	bool Confirm_Reg_Dynamic_Com_Port( int i_Tgt_Com_Port, int i_TimeOut );
	bool Get_Reg_Com_Port_List( int * ip_COM_List, int * ip_COM_Quan );
	bool PKT_BUFF_ADD_DATA( PKT_BUFF_S * strp_Pkt_Buff, const unsigned char * ucp_Input_Data, const unsigned long ul_Add_Quan );
	void PKT_BUFF_CALLOC( PKT_BUFF_S * strp_Pkt_Buff, const unsigned long ul_Buff_Size );
	void PKT_BUFF_DEL_ALL( PKT_BUFF_S * strp_Pkt_Buff );
	void PKT_BUFF_DEL_DATA( PKT_BUFF_S * strp_Pkt_Buff, const unsigned long ul_Del_Quan );
	unsigned long PKT_BUFF_EXTRACT_DATA( PKT_BUFF_S * strp_Pkt_Buff, unsigned char * ucp_Get_Data, const unsigned long ul_Get_Quan );
	void PKT_BUFF_FREE( PKT_BUFF_S * strp_Pkt_Buff );
	void PKT_BUFF_INIT( PKT_BUFF_S * strp_Pkt_Buff );
	DWORD HEX_BYTE_TO_DWORD( unsigned char * ucp_Hex_Char, int i_Hex_Char_Quan );
	void MultiByte_To_WideChar( const char * cp_Char_8, wchar_t * wcp_WCHAR_16, int * ip_Len_16 );
	bool WideChar_To_MultiByte( const wchar_t * wcp_WCHAR_16, char * cp_Char_8, int * ip_Len_8 );
	bool mem_uc_str( unsigned char * ucp_Buff_Src, unsigned long ul_Quan_Src, unsigned char * ucp_Buff_Tgt, unsigned long ul_Quan_Tgt, unsigned long * ulp_Tgt_Index );
	bool Get_Local_PC_Name( CString * csp_PC_Name );
	bool GET_AT_RSP_DIGIT_DATA( const wchar_t * wcp_Src_Data, const wchar_t * wcp_Key_Word, int i_Line_Offset, double * dp_Digit_Data );
	bool GET_AT_RSP_STRING( const wchar_t * wcp_Src_Data, const wchar_t * wcp_Key_Word, int i_Line_Offset, CString * csp_String );
	bool Get_Reg_Usb_Dev_List( const wchar_t * wcp_USB_PID_VID, CString * csp_USB_Dev_List, int * ip_USB_Quan );
	bool Get_File_Directory( const wchar_t * wcp_File_Path, CString * csp_File_Directory );
	bool Kill_Process( const wchar_t * wcp_Process_Name );
	bool Calcu_ARFCN_GSM( int i_G_Band_Index, double d_Center_Freq, int i_Up_Down_Link, int * ip_ARFCN );
	bool Calcu_ARFCN_WCDMA( int i_W_Band_Index, double d_Center_Freq, int i_Up_Down_Link, int * ip_ARFCN );
	bool Calcu_Center_Freq_GSM( int i_G_Band_Index, int i_ARFCN, int i_Up_Down_Link, double * dp_Center_Freq );
	bool Calcu_Center_Freq_WCDMA( int i_W_Band_Index, int i_ARFCN, int i_Up_Down_Link, double * dp_Center_Freq );
	CString m_csError_Info;
	bool GET_AT_RSP_MID_STRING( const wchar_t * wcp_Src_Data, const wchar_t * wcp_Start_Key, const wchar_t * wcp_End_Key, CString * csp_Useful_String );
	void Empty_Directory( const wchar_t * wcp_Dir_Path );
	bool Get_Reg_Usb_Dev_Friendly_Name( const wchar_t * wcp_USB_PID_VID, const wchar_t * wcp_USB_Dev_Name, CString * csp_Friendly_Name );
	void WCSTOK_STRING_T( const wchar_t * wcp_StrToken, CString * csp_Get_CString_Array, int * ip_Get_Quan );
	bool Calcu_Center_Freq_LTE( int i_L_Band_Name, int i_ARFCN, int i_Up_Down_Link, double * dp_Center_Freq_MHz );
	bool Calcu_ARFCN_LTE( int i_L_Band_Name, double d_Center_Freq_MHz, int i_Up_Down_Link, int * ip_ARFCN );
	bool Get_LTE_Band_Name( int i_LTE_Band_Index, int * ip_L_Band_Name );
	bool Get_LTE_Band_Index( int i_LTE_Band_Name, int * ip_L_Band_Index );
	int Trans_UL_ARFCN_LTE( int i_L_Band_Name, int i_Arfcn_DL );
	int Trans_UL_ARFCN_WCDMA( int i_W_Band_Index, int i_Arfcn_DL );
	bool Calcu_Center_Freq_TD( int i_TD_Band_Name, int i_ARFCN, double * dp_Center_Freq_MHz );
	bool Calcu_ARFCN_TD( int i_TD_Band, double d_Center_Freq_MHz, int * ip_ARFCN );
	bool Get_TD_Band_Name( int i_TD_Band_Index, int * ip_TD_Band_Name );
	bool Get_TD_Band_Index( int i_TD_Band_Name, int * ip_TD_Band_Index );
	bool Encode_RF_Ref_Tx_Data_To_Str_V1( double d_Code_Key, int i_Band_And_Tx_Data_Quan, int * ip_Band_List, double * dp_RF_Tx_Data, CString * csp_Str_Data );
	bool Decode_RF_Ref_Tx_Data_From_Str_V1( const wchar_t * wcp_Ref_Str_Data, double d_Code_Key, int * ip_Band_And_Tx_Data_Quan, int * ip_Band_List, double * dp_RF_Tx_Data );
	void WCSTOK_STRING_T_C( const wchar_t * wcp_StrToken, const wchar_t * wcp_StrDelimit, CString * csp_Get_CString_Array, int * ip_Get_Quan );
	int Calcu_IMEI_Checksum( const wchar_t * wcp_IMEI_14_Bits );
	bool Get_CDMA2000_Band_Name( int i_C2K_Band_Index, int * ip_C2K_Band_Name );
	bool Get_CDMA2000_Band_Index( int i_C2K_Band_Name, int * ip_C2K_Band_Index );
	bool Calcu_Center_Freq_CDMA2000( int i_C2K_Band_Name, int i_ARFCN, int i_Up_Down_Link, double * dp_Center_Freq_MHz );
	bool Get_WCDMA_Band_Name( int i_W_Band_Index, int * ip_W_Band_Name );
	bool Get_WCDMA_Band_Index( int i_W_Band_Name, int * ip_W_Band_Index );
	void Get_RF_Offset_Freq_Band_Seg( int i_Format, int i_Band_Index, double * dp_Freq_Tx_S, double * dp_Freq_Tx_E, double * dp_Freq_Rx_S, double * dp_Freq_Rx_E );
	bool GET_ARFCN_L_M_H_TYPE( int i_Band, int i_Format_Network, int i_ARFCN, int * ip_LMH_TYPE );
	void Adjust_From_Small_To_Large_Array_Int( int * ip_Data_List, int i_Quan );
	int Rand_One_Number( int i_Range );
	bool Calcu_MEID_Check_Digit( const wchar_t * wcp_MEID_Hex, wchar_t * wcp_Checksum );
	void WCSTOK_STRING_T_Q( const wchar_t * wcp_StrToken, int i_Take_Quan, CString * csp_Take_CString_Array );
	void Adjust_From_Small_To_Large_Array_Double( double * dp_Data_List, int i_Quan );
	bool ReadPhysicalDriveInNTUsingSmart( CString * csp_HDD_SN );
	void PrintIdeInfo( int drive, DWORD * diskdata, CString * csp_HDD_SN );
	void ConvertToString( DWORD * diskdata, int firstIndex, int lastIndex, char * buf );
	int HEX_WCHAR_TO_SIGNED_INT32( const wchar_t * wcp_HEX_WCHAR );
	unsigned long HEX_WCHAR_TO_UNSIGNED_INT32( const wchar_t * wcp_HEX_WCHAR );
	bool Encode_RF_Ref_Tx_Data_To_Str_V2( double d_Code_Key, double * dp_RF_Tx_Data, int i_RF_Tx_Quan, int * ip_Band_List, int i_Band_Quan, CString * csp_Str_Data );
	bool Decode_RF_Ref_Tx_Data_From_Str_V2( const wchar_t * wcp_Ref_Str_Data, double d_Code_Key, int * ip_Band_List, int * ip_Band_Quan, int * ip_RF_Tx_Data_Quan, double * dp_RF_Tx_Data );
	bool Get_Data_In_Quotation_Marks( const wchar_t * wcp_Src_Data, CString * csp_Get_Data );
	void Get_PF_Name( int i_PF_Index, CString * csp_PF_Name );
	void Get_BB_Name( int i_BB_Index, CString * csp_BB_Name );
	void Get_Produ_Type_Name( int i_Produ_Type_Index, CString * csp_Produ_Type_Name );
	void Get_Produ_Ver_Name( int i_Produ_Ver_Index, CString * csp_Produ_Ver_Name );
	long HEX_WCHAR_TO_LONG_INT( const wchar_t * wcp_HEX_WCHAR );
	bool Calcu_Center_Freq_WiFi( int i_WiFi_CH, double * dp_Center_Freq_MHz );
	bool Get_WiFi_FreqBand_Name( int i_WiFi_FB_Index, CString * csp_WiFi_FB_Name );
	bool Get_WiFi_Standard_Name( int i_WiFi_STAN_Index, CString * csp_WiFi_STAN_Name );
	bool Calcu_Center_Freq_Bluetooth( int i_BLU_VER_Index, int i_BLU_CH, double * dp_Center_Freq_MHz );
	bool Get_Bluetooth_Version_Name( int i_BLU_VER_Index, CString * csp_BLU_VER_Name );
	bool Get_FileName_From_FilePath( const wchar_t * wcp_File_Path, bool b_Need_Extend_Name, CString * csp_File_Name );
	void WCSTOK_STRING_S_C_Ex( const wchar_t * wcp_StrToken, wchar_t wc_StrDelimit, CString * csp_Get_CString_Array, int * ip_Get_Quan );
	bool Get_WiFi_Standard_FreqBand( int i_WiFi_STAN_Index, int * ip_WiFi_FB_Index );
	bool Get_LTE_Category_Name( int i_LTE_CAT_Index, CString * csp_LTE_CAT_Name );
	bool Get_GSM_Band_Name( int i_G_Band_Index, CString * csp_G_Band_Name );
	int Get_Process_Attributes_Index( const CString cs_Process_Attributes_Name );
	bool Get_Process_Attributes_Name( const int i_Process_Attributes_Index, CString & csref_Process_Attributes );
	bool Get_NBIoT_Band_Index( int i_NBIoT_Band_Name, int * ip_NBIoT_Band_Index );
	bool Get_NBIoT_Band_Name( int i_NBIoT_Band_Index, int * ip_NBIoT_Band_Name );
	bool Get_LTE_Band_DD_FDD_TDD( int i_LTE_Band_Name, int & oj_i_LTE_DD );
	bool Get_DD_FDD_TDD_Name( int i_FDD_TDD, CString & oj_cs_DD_Name );
	bool Get_NR_5G_SUB6_Band_Index( int i_Band_Name, int & oj_i_Band_Index );
	bool Get_NR_5G_SUB6_Band_Name( int i_Band_Index, int & oj_i_Band_Name );
	bool Get_ANT_Type_Name( EU_ANT_TYPE_INDEX eu_Ant_Type_Index, CString & oj_cs_Ant_Type_Name );
	bool IS_SMART_MODULE( int i_BB_Chip );
	void Empty_Struct_TESTER_RF_OFFSET_S( TESTER_RF_OFFSET_S & oj_str_RF_Loss_V1 );
	void Empty_Struct_TESTER_RF_OFFSET_V2_S( TESTER_RF_OFFSET_V2_S & oj_str_RF_Loss_V2 );
	void Empty_Struct_ANT_CFG_ALL_S( ANT_CFG_ALL_S & oj_str_ANT_Config_All );
	void Empty_Struct_ANT_LIST_S( ANT_LIST_S & oj_str_ANT_List );
	void Empty_Struct_REF_DATA_ALL_S( REF_DATA_ALL_S & oj_str_Ref_Data_All );
	void Empty_Struct_REF_DATA_BAND_S( REF_DATA_BAND_S & oj_str_Ref_Data_Band );
	void Copy_Struct_ANT_CFG_ALL_S( ANT_CFG_ALL_S & oj_str_ANT_CFG_Dest, ANT_CFG_ALL_S str_ANT_CFG_Source );
	void Copy_Struct_ANT_LIST_S( ANT_LIST_S & oj_str_ANT_List_Dest, ANT_LIST_S str_ANT_List_Source );
	void Copy_Struct_TESTER_RF_OFFSET_V2_S( TESTER_RF_OFFSET_V2_S & oj_str_RF_Loss_Dest, TESTER_RF_OFFSET_V2_S str_RF_Loss_Source );
	void Copy_Struct_TESTER_RF_OFFSET_V2_S_To_TESTER_RF_OFFSET_S( TESTER_RF_OFFSET_S & oj_str_RF_Loss_V1_Dest, TESTER_RF_OFFSET_V2_S str_RF_Loss_V2_Source );
	void Copy_Struct_TESTER_RF_OFFSET_S_To_TESTER_RF_OFFSET_V2_S( TESTER_RF_OFFSET_V2_S & oj_str_RF_Loss_V2_Dest, TESTER_RF_OFFSET_S str_RF_Loss_V1_Source );
	bool Get_RF_Key_Type_Name( const EU_RF_KEY_TYPE_INDEX eu_RF_Key_Type_Index, CString & oj_cs_RF_Key_Type_Name );
	void Unicode_To_UTF8( const wchar_t * wcp_Unicode_Str, CStringA & oj_csa_UTF_8_Str );
	void UTF8_To_Unicode(const char * cp_UTF_8_Str, CStringW & oj_Unicode_Str);
	bool Get_CV2X_Band_Index( int i_CV2X_Band_Name, int * ip_CV2X_Band_Index );
	bool Get_CV2X_Band_Name( int i_CV2X_Band_Index, int * ip_CV2X_Band_Name );
	void Copy_Struct_BAND_ENABLE_S( BAND_ENABLE_S & oj_str_Band_Enable_Dest, BAND_ENABLE_S str_Band_Enable_Source );
	void Assign_Struct_BAND_ENABLE_S( BAND_ENABLE_S & oj_str_Band_Enable, int i_Value_Data );
	bool Get_NB_SCSP_Name( int i_S3K75_S15K, CString & oj_cs_NB_SCSP_Name );
	bool Get_NB_Mod_Scheme_Name( int i_BPSK_QPSK, CString & oj_cs_NB_Mod_Scheme_Name );
	bool Get_NR_5G_MMW_Band_Index( int i_Band_Name, int & oj_i_Band_Index );
	bool Get_NR_5G_MMW_Band_Name( int i_Band_Index, int & oj_i_Band_Name );
	bool Get_ANT_Type_Index( const wchar_t * wcp_Ant_Type_Name, EU_ANT_TYPE_INDEX & oj_eu_Ant_Type_Idx );
	void Get_RF_Instru_Name( int i_Instru_Index, CString & oj_cs_Instru_Name );
	void Empty_Struct_REF_DATA_ALL_V2_S( REF_DATA_ALL_V2_S & oj_str_Ref_Data_All_V2 );
	bool Get_ANT_Type_List_Buff_Index( ANT_LIST_S str_Ant_List, EU_ANT_TYPE_INDEX eu_Ant_Type_Idx, int & oj_i_Ant_Buff_Index );
	void Empty_Struct_ANT_CFG_ALL_V2_S( ANT_CFG_ALL_V2_S & oj_str_ANT_Config_All );
	void Copy_Struct_ANT_CFG_ALL_V2_S( ANT_CFG_ALL_V2_S & oj_str_ANT_CFG_Dest, ANT_CFG_ALL_V2_S str_ANT_CFG_Source );
	void Copy_Struct_ANT_CFG_ALL_V2_S_To_ANT_CFG_ALL_S( ANT_CFG_ALL_S & oj_str_ANT_CFG_V1_Dest, const ANT_CFG_ALL_V2_S & oj_str_ANT_CFG_V2_Source );
	void Copy_Struct_ANT_CFG_ALL_S_To_ANT_CFG_ALL_V2_S( ANT_CFG_ALL_V2_S & oj_str_ANT_CFG_V2_Dest, const ANT_CFG_ALL_S & oj_str_ANT_CFG_V1_Source );
	bool Get_RF_Loss_Data_From_ANT_CFG_ALL_V2_S( const ANT_CFG_ALL_V2_S & oj_str_ANT_CFG_V2, EU_ANT_TYPE_INDEX eu_Ant_Type_Idx, int i_Format_Network, int i_Band_Name, int i_L_M_H, double & oj_d_RF_Loss_Tx_Input, double & oj_d_RF_Loss_Rx_Output );
	bool Get_Rx_Chain_Type_Name( int i_Rx_Chain_Type, CString & oj_cs_Rx_Chain_Type_Name );
	bool Determine_Type_Of_Plan_Connect_ANT_And_RF_Port( const ANT_CFG_ALL_V2_S str_ANT_CFG_ALL_V2, int & oj_i_Plan_Connect_ANT_And_RF_Port );
	bool Determine_Type_Of_Plan_Connect_ANT_And_RF_Port_V2( const ANT_LIST_S str_ANT_List, int & oj_i_Plan_Connect_ANT_And_RF_Port );
	bool Setup_Struct_ANT_CFG_ALL_V2_S_To_SQL_RF_Loss_String_All( int i_BB_Chip, double d_Loss_Limit_Low, double d_Loss_Limit_High, const ANT_CFG_ALL_V2_S & oj_str_ANT_CFG_ALL, const BAND_LIST_V2_S & oj_str_Band_List, CString & oj_cs_SQL_RF_Loss_String );
	bool Load_ANT_CFG_ALL_V2_S_To_SQL_RF_Loss_String_2G( double d_Loss_Limit_Low, double d_Loss_Limit_High, EU_ANT_TYPE_INDEX eu_Ant_Name_Type, int i_Ant_Buff_Index, const ANT_CFG_ALL_V2_S & oj_str_ANT_CFG_ALL, const BAND_LIST_V2_S & oj_str_Band_List, CString & oj_cs_SQL_RF_Loss_String );
	bool Load_ANT_CFG_ALL_V2_S_To_SQL_RF_Loss_String_3G( double d_Loss_Limit_Low, double d_Loss_Limit_High, EU_ANT_TYPE_INDEX eu_Ant_Name_Type, int i_Ant_Buff_Index, const ANT_CFG_ALL_V2_S & oj_str_ANT_CFG_ALL, const BAND_LIST_V2_S & oj_str_Band_List, CString & oj_cs_SQL_RF_Loss_String );
	bool Load_ANT_CFG_ALL_V2_S_To_SQL_RF_Loss_String_4G( double d_Loss_Limit_Low, double d_Loss_Limit_High, EU_ANT_TYPE_INDEX eu_Ant_Name_Type, int i_Ant_Buff_Index, const ANT_CFG_ALL_V2_S & oj_str_ANT_CFG_ALL, const BAND_LIST_V2_S & oj_str_Band_List, CString & oj_cs_SQL_RF_Loss_String );
	bool Load_ANT_CFG_ALL_V2_S_To_SQL_RF_Loss_String_5G( double d_Loss_Limit_Low, double d_Loss_Limit_High, EU_ANT_TYPE_INDEX eu_Ant_Name_Type, int i_Ant_Buff_Index, const ANT_CFG_ALL_V2_S & oj_str_ANT_CFG_ALL, const BAND_LIST_V2_S & oj_str_Band_List, CString & oj_cs_SQL_RF_Loss_String );
	bool Load_ANT_CFG_ALL_V2_S_To_SQL_RF_Loss_String_WiFi( double d_Loss_Limit_Low, double d_Loss_Limit_High, EU_ANT_TYPE_INDEX eu_Ant_Name_Type, int i_Ant_Buff_Index, const ANT_CFG_ALL_V2_S & oj_str_ANT_CFG_ALL, CString & oj_cs_SQL_RF_Loss_String );
	bool Load_ANT_CFG_ALL_V2_S_To_SQL_RF_Loss_String_Bluetooth( double d_Loss_Limit_Low, double d_Loss_Limit_High, EU_ANT_TYPE_INDEX eu_Ant_Name_Type, int i_Ant_Buff_Index, const ANT_CFG_ALL_V2_S & oj_str_ANT_CFG_ALL, CString & oj_cs_SQL_RF_Loss_String );
	bool Load_ANT_CFG_ALL_V2_S_To_SQL_RF_Loss_String_LORA( double d_Loss_Limit_Low, double d_Loss_Limit_High, EU_ANT_TYPE_INDEX eu_Ant_Name_Type, int i_Ant_Buff_Index, const ANT_CFG_ALL_V2_S & oj_str_ANT_CFG_ALL, CString & oj_cs_SQL_RF_Loss_String );
	bool Setup_SQL_RF_Loss_String_To_Struct_ANT_CFG_ALL_V2_S( const wchar_t * wcp_SQL_RF_Loss_String, const ANT_LIST_S & oj_str_Ant_List, ANT_CFG_ALL_V2_S & oj_str_ANT_CFG_ALL );
	bool Get_Each_Data_In_Band_Code( const wchar_t * wcp_Band_Code, int & oj_i_ANT, int & oj_i_Format_Network, int & oj_i_Band_Name, int & oj_i_Tx_Rx, int & oj_i_L_M_H );
	bool Load_Value_Code_To_Struct_ANT_CFG_ALL_V2_S( ANT_CFG_ALL_V2_S & oj_str_ANT_CFG_ALL, const wchar_t * wcp_Value_Code, int i_ANT, int i_Format_Network, int i_Band_Name, int i_Tx_Rx, int i_L_M_H, const ANT_LIST_S & oj_str_Ant_List );
	bool Load_ANT_CFG_ALL_V2_S_To_SQL_RF_Loss_String_GPS( double d_Loss_Limit_Low, double d_Loss_Limit_High, EU_ANT_TYPE_INDEX eu_Ant_Name_Type, int i_Ant_Buff_Index, const ANT_CFG_ALL_V2_S & oj_str_ANT_CFG_ALL, CString & oj_cs_SQL_RF_Loss_String );
	bool Setup_Vector_Str_CABLE_LOSS_SET_S_To_SQL_RF_Loss_String( std::vector<CABLE_LOSS_SET_S> & oj_ve_str_CABLE_LOSS_SET, CString & oj_cs_SQL_RF_Loss_String );
	bool Load_CABLE_LOSS_SET_S_To_SQL_RF_Loss_String_2G( EU_ANT_TYPE_INDEX eu_Ant_Name_Type, const CABLE_LOSS_SET_S & oj_str_CABLE_LOSS_SET, CString & oj_cs_SQL_RF_Loss_String );
	bool Load_CABLE_LOSS_SET_S_To_SQL_RF_Loss_String_WCDMA( EU_ANT_TYPE_INDEX eu_Ant_Name_Type, const CABLE_LOSS_SET_S & oj_str_CABLE_LOSS_SET, CString & oj_cs_SQL_RF_Loss_String );
	bool Load_CABLE_LOSS_SET_S_To_SQL_RF_Loss_String_TDSCDMA( EU_ANT_TYPE_INDEX eu_Ant_Name_Type, const CABLE_LOSS_SET_S & oj_str_CABLE_LOSS_SET, CString & oj_cs_SQL_RF_Loss_String );
	bool Load_CABLE_LOSS_SET_S_To_SQL_RF_Loss_String_LTE( EU_ANT_TYPE_INDEX eu_Ant_Name_Type, const CABLE_LOSS_SET_S & oj_str_CABLE_LOSS_SET, CString & oj_cs_SQL_RF_Loss_String );
	bool Check_Fluctuation_In_SQL_RF_Loss_String_V1( CString * csp_SQL_RF_Loss_String_Buff, int i_Quan_Of_SQL_RF_Loss_String, const ANT_LIST_S & oj_str_Ant_List, double d_2G3G4G_Limits, double d_5G_Limits, bool & oj_b_Result_All_Data_Pass, CString & oj_cs_Result_Fail_String_Out_Of_Limits );
	bool Setup_Struct_ANT_CFG_ALL_V2_S_To_SQL_RF_Loss_String_V1( double d_Loss_Limit_Low, double d_Loss_Limit_High, const ANT_CFG_ALL_V2_S & oj_str_ANT_CFG_ALL, const BAND_LIST_V2_S & oj_str_Band_List, CString & oj_cs_SQL_RF_Loss_String );
	bool Setup_Struct_ANT_CFG_ALL_V2_S_To_SQL_RF_Loss_String_V2( double d_Loss_Limit_Low, double d_Loss_Limit_High, const ANT_CFG_ALL_V2_S & oj_str_ANT_CFG_ALL, const BAND_LIST_V2_S & oj_str_Band_List, CString & oj_cs_SQL_RF_Loss_String );
	bool Get_File_Version_In_Sel_Exe_Path( const wchar_t * wcp_File_Name, CString & oj_cs_Version_Of_File );
	void DateTimeStr_To_IntArray( const wchar_t * wcp_DateTime_Source, int * ip_Date_Time_Array, int * ip_Array_Quan );
	bool Get_PF_Name_V2( int i_PF_Index, CString * csp_PF_Name );
	bool Get_BB_Name_V2( int i_BB_Index, CString * csp_BB_Name );
	int Trans_UL_ARFCN_NTN( int i_NTN_Band_Name, int i_Arfcn_DL );
	bool Calcu_Center_Freq_NTN( int i_NTN_Band_Name, int i_ARFCN, int i_Up_Down_Link, double * dp_Center_Freq_MHz );
	bool Calcu_ARFCN_NTN( int i_NTN_Band_Name, double d_Center_Freq_MHz, int i_Up_Down_Link, int * ip_ARFCN );
	bool Get_NTN_Band_Index( int i_NTN_Band_Name, int * ip_NTN_Band_Index );
	bool Get_NTN_Band_Name( int i_NTN_Band_Index, int * ip_NTN_Band_Name );
	bool Calcu_Freq_WiFi_11AH( int i_WiFi_CH, double * dp_Center_Freq_MHz, int i_Region );
	bool Get_Lora_Standard_FreqBand( int i_Lora_Arfcn, int & oj_i_Band_Index );
	bool Get_RF_Loss_Data_From_ANT_CFG_ALL_V3_S( const ANT_CFG_ALL_V2_S & oj_str_ANT_CFG_V2, EU_ANT_TYPE_INDEX eu_Ant_Type_Idx, int i_Format_Network, int i_Band_Name, int i_L_M_H, double & oj_d_RF_Loss_Tx_Input, double & oj_d_RF_Loss_Rx_Output );
	void Calcu_Center_Freq_Lora( int i_Center_Freq_Hz, double * dp_Center_Freq_MHz );
	bool Get_Lora_FreqBand_Name( int i_Lora_Arfcn, CString * csp_Lora_FB_Name );
	bool Get_Lora_Modulation_Name( int i_Lora_FB_Index, CString * csp_Lora_FB_Name );
	void Empty_Struct_ANT_CFG_ALL_V3_S( ANT_CFG_ALL_V2_S & oj_str_ANT_Config_All );
	void Empty_Struct_TESTER_RF_OFFSET_V3_S( TESTER_RF_OFFSET_V2_S & oj_str_RF_Loss_V2 );
	void Copy_Struct_ANT_CFG_ALL_V3_S( ANT_CFG_ALL_V2_S & oj_str_ANT_CFG_Dest, ANT_CFG_ALL_V2_S str_ANT_CFG_Source );
	void Copy_Struct_TESTER_RF_OFFSET_V3_S( TESTER_RF_OFFSET_V2_S & oj_str_RF_Loss_Dest, TESTER_RF_OFFSET_V2_S str_RF_Loss_Source );
	void Empty_Struct_REF_DATA_ALL_V3_S( REF_DATA_ALL_V2_S & oj_str_Ref_Data_All_V2 );
	void Empty_Struct_REF_DATA_BAND_V1_S( REF_DATA_BAND_S & oj_str_Ref_Data_Band );
	void IS_CAT1_NB_PRODU_FOR_LOG_FILE( int i_BB_Chip, bool & oj_b_Is_CAT1_NB_Produ );
	bool Check_Loss_LMH_Linear_In_ANT_CFG_ALL_V2_S_R1( const ANT_CFG_ALL_V2_S & oj_str_ANT_V2_All, double d_Loss_Valid_Value_Threshold, double d_Loss_Delta_Tolerance, double b_Max_Filter_Freq_In_MHz, CString & oj_cs_Error_Info, CString & oj_cs_Error_Band_Name );
	bool Check_Loss_LMH_Linear_R1( double d_Value_Low, double d_Value_Mid, double d_Value_High, double d_Loss_Valid_Value_Threshold, double d_Check_Standard, CString cs_ANT_Name, CString cs_Band_Name, int i_Tx_Rx_Index, CString & oj_cs_Error_Info, CString & oj_cs_Error_Band_Name );
	bool Check_Loss_LMH_Linear_In_ANT_CFG_ALL_V2_S_R2( const ANT_CFG_ALL_V2_S & oj_str_ANT_V2_All, double d_Loss_Valid_Value_Threshold, double d_Loss_Delta_Tolerance, CString & oj_cs_Error_Info, CString & oj_cs_Error_Band_Name );
};
