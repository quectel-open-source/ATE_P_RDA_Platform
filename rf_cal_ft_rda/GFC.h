#pragma once
//
#include "Global_Header.h"
#include "tlhelp32.h"
#include "atlbase.h"
#include <winioctl.h>//HD
#include <vector>
#include <math.h>



//RF�ϡ����б�ʶ
#define RF_TX_UL_INPUT				0
#define RF_RX_DL_OUTPUT				1


//Division Dual ˫��
#define DD_NDF						0
#define DD_FDD						1
#define DD_TDD						2
//WCDMA������Ŀ
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

//cdma2000������Ŀ
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

//LTE�����������Ŀ
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

//TD�����������Ŀ
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

//GSM�����������Ŀ
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

//WiFi�����������Ŀ
typedef enum EU_WIFI_NS_FT_ITEM_IDX
{
	WIFINFI_TX_PWR_AVG = 0,
	WIFINFI_EVM_AVG,
	WIFINFI_FREQ_ERR,
	WIFINFI_TRANS_SPEC_MASK,
	WIFINFI_RX_PER,
	WIFINFI_COUNT
}EU_WIFI_NS_FT_ITEM_IDX;


//Bluetooth�����������Ŀ
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


//C-V2X�����������Ŀ
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
//NB-IoT �� Subcarrier Spacing
#define NB_SCSP_S3K75				0//3.75 kHz
#define NB_SCSP_S15K				1//15 kHz


//NB-IoT �� Modulation Scheme Used By The Measured Signal�����ͨ�����еĶ�����ͬ��
#define NB_MSCH_BPSK				0//0 = BPSK
#define NB_MSCH_QPSK				1//1 = QPSK


//NB-IoT �� Number Of SubCarrier
#define NB_SINGLE_TONE				1
#define NB_MULTI_TONE_3				3
#define NB_MULTI_TONE_6				6
#define NB_MULTI_TONE_12			12



//����ƽ̨
typedef enum tagEU_PF_IDX
{
	//
	PF_NDF = 0,		//δ����
	//
	PF_MTK,			//MTK
	PF_QUALCOMM,	//��ͨ
	PF_RDA,			//RDA
	PF_GCT,			//GCT
	PF_INTEL,		//Intel
	PF_HISILICON,	//��˼ Hisilicon
	PF_ASR,			//ASR
	PF_REALTEK,		//Realtek
	PF_SPREADTRUM,	//չ�� Spreadtrum
	PF_EIGENCOMM,	//��о Eigencomm
	PF_TI,			//�������� Texas Instruments
	PF_XINYI,		//о����Ϣ�Ƽ�(�Ϻ�)���޹�˾
	PF_ALTAIR,		//Sony Altair
	PF_BEKEN,			//��ͨ���ɵ�·���Ϻ����ɷ����޹�˾
	PF_CYPRESS,			//������˹ Cypress �뵼�幫˾
	PF_SILICON_LABS,	//о�ƿƼ�(Silicon Labs)
	PF_AMLOGIC,			//Amlogic �����뵼��(�Ϻ�)�ɷ����޹�˾
	PF_IONA,			//IONAоƬƽ̨, Orbcommƽ̨��
	PF_MORNINGCORE,		//�о�Ƽ����޹�˾���ҹ���ҵͨ���ն�SoCоƬרҵ�������ҵ
	PF_ESWIN,			//������˹ΰ�Ƽ��������޹�˾����ơ�ESWIN��������һ�Ҽ��ɵ�·�����Ʒ�ͷ����ṩ�̣�����ҵ�񺭸�оƬ�뷽��������ϡ���̬��Ͷ�ʷ�����������
	PF_ICOMM,			//�Ϸ����?iComm, �������Ϸ���Ȱ뵼��ɷ����޹�˾2018���������������ɽ������һ��ȫ�򻯵�רҵ�޾�Բ�뵼�幫˾�����Ҹ��¼�����ҵ
	PF_ROCKCHIP,		//Rockchip ��о΢, ��о΢���ӹɷ����޹�˾, רע�ڼ��ɵ�·������з���Ŀǰ�ѷ�չΪ���ȵ���������IoT�����˹�������������AIoT��������оƬ��ҵ
	PF_MURATA,			//���� Murata Electronics
	PF_AICSEMI,			//AICSEMI ����΢�뵼��(�Ϻ�)���޹�˾
	PF_MORSE_MICRO,		//Ħ��˹΢(Morse Micro)�ǰĴ����ǵ����߼��ɵ�·���������˾
	PF_NXP,				//�����ְ뵼�幫˾��NXP Semiconductors����AVNET(������)������������֧�֡�
	PF_QUECTEL,			//�Ϻ���Զ�����Ʋ�ƷĬ��ƽ̨����
	PF_AUTOTALKS,		//Autotalks ��һ��רע�ڳ�����ͨ��ϵͳ��V2X�������ļ�����˾��Autotalks is a fabless semiconductor company devoted to vehicle-to-everything (V2X) communications for manned and autonomous vehicles.
	PF_FREQCHIP,		//�Ϻ�������΢�������޹�˾������2014�꣬��һ����������Ƶ���ɵ�·оƬ����ơ��з�����Ʒ���۵ĸ��¼�����ҵ�����в�Ʒ�ߣ�˫ģ������ƵSoCоƬ�ͳ��͹��ģ�BLE������ SoCоƬ��
	PF_QORVO,			//Qorvo ��Ѷ���ϰ뵼�����޹�˾(Qorvo=RFMD+Triquint), ��һ����ơ���������������Ƶ�����ɵ�·��Ʒ������������ҵ����˾Ϊ�ƶ���Ʒ��������ʩ�ȷ����ṩ��׼�ͺͶ����Ͳ�Ʒ��������Լ�ս���������
	PF_BESTECHNIC,		//Bestechnic �����Ƽ���Ҫ����������ƵSoCоƬ���з�����������ۣ�Ϊ�ͻ��ṩAIoT�����¾����������������ı�Ե��������ƽ̨оƬ����Ʒ�㷺Ӧ������������������Type-C��������������������ն˲�Ʒ��
	PF_ST,				//ST �ⷨ�뵼��
	PF_NEWRADIO,		//Ŧ��о�Ƽ�(NewRadio Tech)��2016��12���ɺ��鼯�ɵ�·ר�����ϴ��죬�ڱ��������ڡ����ݵȵؾ������з����ġ���˾רע��ͨѶоƬ�ĺ��ļ����з�����ҵ���������й�������������������һ������ͨѶ�����Ͷ�λϵͳ��չ��
	PF_HWA,				//����������ͨ�ɷ����޹�˾��Hwa Create Company������Զ���롰������ͨ����˾ǩ�ļ���Э�顣
	PF_XINCOMM,			//Xincomm Communications Co., Ltd.
	PF_ONMICRO,			//OnMicro ����΢ ��һ�������Ƶǰ�˺�����ͨ�����򡢶�Ԫ��ǰհ���ֵĸ�����оƬ��ƹ�˾����˾�ܲ�λ�ڱ�����
	PF_XHSC,			//XHSC С���뵼�����޹�˾������Ƹ�500ǿ�й�������Ϣ��ҵ�������޹�˾��CEC�����¼��ɵ�·ҵ��ƽ̨����뵼�����޹�˾�ĺ����ӹ�˾��
	PF_TG,				//ƽͷ��뵼�����޹�˾��2018��9�������������ǰ���Ͱͼ��ŵ�ȫ�ʰ뵼��оƬҵ�����塣ƽͷ��ӵ�ж���һ��ȫջ��Ʒϵ�У�������������оƬ��IoTоƬ�ȣ�ʵ��оƬ�˵��������·ȫ���ǡ�
	PF_INFINEON,		//Infineon Ӣ������ȫ�����ȵİ뵼�幫˾��Ӣ�����չ��� CYPRESS �����ҵ��
	PF_NOVATEK,			//��ӽ��NOVATEK���Ƽ�Ϊ̨�� IC ����쵼���̣����²�Ʒ��ƣ��з������ۡ���Ҫ��ƷΪȫϵ�е�ƽ����ʾ��Ļ���� IC���Լ��ж�װ�ü������Ե��Ӳ�Ʒ��Ӧ��֮����Ӱ������ý�嵥оƬ��Ʒ���������
	PF_NATIONSTECH,		//Nationstech �������ɷ����޹�˾����ƣ�������������MCU����ȫоƬ������ҵ�͹��Ҹ��¼�����ҵ����Ӫ��Ʒ������MCU����ȫоƬ�����ż���оƬ����ع���оƬ������оƬ��RCC���²�Ʒ�ȣ��㷺Ӧ��������������ҵ���ơ������������������ؼ���Դ�����������ӡ����ܼҾӼҵ硢���ѵ��ӡ����ܱ�ơ�ҽ�Ƶ��ӡ�����������ʶ��ͨѶ�����������Լ����簲ȫ��֤���������С�����֤�ա��ƶ�֧�����ƶ���ȫ��Ӧ�÷���
	PF_NORDIC,			//Nordic Semiconductor ��һ��Ų���޾�Բ���뵼�幫˾��רע��Ϊ��������IoT���ṩ֧�ֵ�����ͨ�ż�����
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
	BB_QCA6564,		//��ͨWiFiоƬ(����ƽ̨)
	BB_SDM660,		//��ͨ4GоƬ
	BB_RDA8908A,	//RDA��NB-IoTоƬ
	BB_RDA8909B,	//RDA��2G+NB-IoTоƬ
	BB_MT2621,		//MTK��2G+NB-IoTоƬ
	BB_SA415M,		//��ͨ����4G+V2X����
	BB_SDX24,		//��ͨ4GоƬ, A7 at 1.5GHz, 256KB L2, Ӧ���ڱʵ�, LTE-A/����
	BB_MDM9205,		//��ͨ4GоƬ, LTE Cat-M / Cat-NB
	BB_SDX55,		//��ͨ 5G оƬ, ����
	BB_RTL8189,		//Realtekƽ̨WiFiоƬ
	BB_QM215,		//��ͨ4G����ģ��(���MSM8909)
	BB_QCM2150,		//��ͨ4G����ģ��(���MSM8909)
	BB_SA515M,		//��ͨ 5G NR оƬ, SA515M�ǳ���ƽ̨, ��Ӧ�Ĺ���SDX55ƽ̨
	BB_WCN3990,		//��ͨWiFiоƬ
	BB_ASR3601,		//ASR��ASR1802S�ͳɱ�4GоƬ
	BB_SL8541E,		//չ��(Spreadtrum)4G����ģ��оƬ
	BB_HI2152,		//��˼HI2152 4G������ģ��оƬ
	BB_QCA6391,		//��ͨ WiFi ���� оƬ
	BB_EC616,		//��о ���͹���NB-IoT��ģоƬ
	BB_ASR1601,		//ASR��4GоƬ CAT-1
	BB_CC1200,		//TI �͹��ĸ�������Ƶ�շ���
	BB_HI9500,		//��˼ 5G оƬ
	BB_ASR1802SL,	//ASR��4GоƬ��Linux�汾
	BB_ASR1826,		//ASR��4GоƬ, LTE CAT-6
	BB_HI2115,		//��˼Hi2115 NB-IoTоƬ
	BB_QCA6696,		//��ͨ���漶WiFi/BTоƬ��֧��802.11 ax WiFi, ֧������ BT 5.1��
	BB_SDA845,		//��ͨϵͳ��оƬ(SoC: System-on-a-Chip), SDA����modem, ��û�з����ƶ�����
	BB_UDX710,		//չ�� Spreadtrum 5Gƽ̨ ����
	BB_QCX212,		//��ͨ NB-IoT SoC chipset, Category NB2, 2-HARQ
	BB_SM6115,		//��ͨ 4G оƬ, Snapdragon 662
	BB_QTM527,		//��ͨ 5G mmWave antenna module
	BB_EC617,		//�Ϻ���о ���ͳɱ������͹��ĺͳ��߼��ɶ�NB-IoT SoC оƬ����ȫ֧��3GPP Rel14 NB-IoT ��׼
	BB_WCN3980,		//��ͨWiFiоƬ
	BB_ESP8285,		//����WiFiоƬ
	BB_UIS8910DM,	//չ�� advanced system-on-chip solution integrated CAT1bis/GSM/GPRS modems
	BB_UIS8581,		//չ�� ����ģ��оƬ with embedded TD-LTE, LTE FDD, TDSCDMA/HSPA(+), WCDMA/HSPA(+) and GSM/GPRS/EDGE to supportDual SIM Dual Standbyup to LTE+LTE
	BB_XY1100,		//о�� �����ڵ��� IoT �����ĸ����ܣ��߼��ɶȵ� SOC оƬ����оƬ��ȫ���� 3GPP TS 36.211 Э��
	BB_HI2120,		//��˼Hi2120 NB2 NB-IoTоƬ
	BB_MT2731,		//MTK 2G/3G/4G ����ƽ̨оƬ
	BB_WCN3988,		//��ͨWiFiоƬ
	BB_ALT1250,		//Sony Altair eMTC (CAT M), NB IoT (CAT NB1 / NB2)
	BB_QCA6595,		//��ͨ MU-MIMO WiFi/BT 5.1 Automotive Dual-MAC Combo Chip for Automotive Infotainment and Telematics applications
	BB_ASR1603,		//ASR��4GоƬ CAT-1, 1601 + Flash ��װ
	BB_QCA1064,		//��ͨ WiFi ���� оƬ
	BB_MT6880,		//MTK 5G оƬ, T700 ��Ƭ
	BB_MT6890,		//MTK 5G оƬ, T750 ��Ƭ
	BB_WCN3615,		//��ͨWiFiоƬ
	BB_EC616S,		//�Ϻ���о ���ͳɱ������͹��ĺͳ��߼��ɶ� NB-IoT SoC оƬ, ��ȫ֧��3GPP Rel14 NB-IoT ��׼
	BB_QCM6125,		//��ͨ ����ģ�� Qualcomm Snapdragon 600 series processor and LTE modem. LTE Cat12/Cat13 (FDD and TDD)
	BB_UIS8811,		//չ�� advanced system-on-chip solution integrated NB-IoT modems. The UIS8811 integrates RF transceiver for low cost.
	BB_SDX12,		//��ͨ 4G оƬ, ��ͨMDM9x50 cost down ƽ̨, Sixthgeneration LTE multimode modem, 14nm system on chip (SoC).
	BB_QCM2290,		//��ͨ ����ģ�� 4GоƬ
	BB_BK7231,		//��������˫ģ5.1��WiFi802.11n�� WiFi SOC оƬ
	BB_SDX62,		//��ͨ 5G оƬ, ����, SDX55����һ��, Provides Higher Performance mmWave and Features for Global Deployment.
	BB_QCA2064,		//��ͨ highly integrated System-On-Chip (SoC) supporting 802.11ax Wi-Fi and Bluetooth (BT) Milan. It is part of the QCA206x family of SoC��s supporting operation on 2.4 GHz and 5 GHz.
	BB_SM4350,		//��ͨ 5G ����оƬ, the new generation Qualcomm Snapdragon 400 series processor with integrated 5G modem.
	BB_ASR1803S,	//ASR��4GоƬ CAT-4, ASR1802S Costdown оƬ, RTOS�汾
	BB_MT2735,		//MTK 5G оƬ, supporting NR Sub6, LTE Cat19 4x4 MIMO
	BB_WCN3991,		//��ͨWiFiоƬ
	BB_SL8521E,		//չ��(Spreadtrum)4G����ģ��оƬ, ����ģ��ϵͳ��Linux, Android4.4/Linux
	BB_QCM6490,		//��ͨ 5G Smart ��������ģ��, ����5G�汾, ���ڳ�����Tbox���ϵ�һ���. including global multi-gigabit 5G mmW/Sub-6 GHz and WiFi 6E
	BB_QCA9377,		//��ͨ WLAN/Bluetooth оƬ, a single-die wireless local area network (WLAN) and Bluetooth combination solution to support 1 �� 1 802.11a/b/g/n/ac WLAN standards and Bluetooth 5.0 + HS, designed to deliver superior integration of WLAN/Bluetooth and low-energy technology.
	BB_CYW54591,	//The Cypress CYW54591 is a complete dual-band (2.4 GHz and 5 GHz) 5G Wi-Fi 2��2 MIMO MAC/PHY/Radio system-on-Chip.
	BB_ASR1803E,	//ASR��4GоƬ CAT-4, ASR1802S Costdown оƬ, Open Linux�汾
	BB_ASR1803L,	//ASR��4GоƬ CAT-4, ASR1802S Costdown оƬ, ֧��"Open Linux�汾" or "RTOS�汾"
	BB_WCN3998,		//��ͨWiFiоƬ
	BB_QCM4290,		//��ͨ4Gƽ̨, The QCM4290 includes the next generation of the Qualcomm Snapdragon 600 series processor and LTE modem.
	BB_QCX315,		//��ͨ5Gƽ̨, The QCX315 device is a 5G modem from Qualcomm Technologies, Inc. (QTI). It implements the 5G NR standard for sub-6 GHz bands.
	BB_QCS8250,		//��ͨ QCS8250 is the new generation Qualcomm? Snapdragon? premium-tier processor with robotic application.
	BB_CYW43455,	//The Cypress CYW43455 single-chip device provides the highest level of integration for Internet of Things applications and handheld wireless system with integrated single-stream IEEE 802.11ac MAC/baseband/radio and, Bluetooth 5.0.
	BB_UIS8310AM,	//չ�� UIS8310AM is a highly integrated application processor with embedded TDD-LTE, FDD-LTE, WCDMA and GSM/GPRS/EDGE modem and LPDDR2. The specially optimized architecture of UIS8310 can achieve high performance and low power for a lot of applications.
	BB_SDX65,		//��ͨ 5G оƬ, ����, The SDX65/SDX62 device is a multimode modem chip, supporting 2G/3G/4G/5G technologies. 4nm premium-tier 5G modem, 3G/4G/5G modem �CmmWave (mmW) and sub-6 GHz bands (3GPP Release 16 integrated modem).
	BB_UWE5623DU,	//չ�� WiFi/���� оƬ, UWE5623DU is a high intergrated 2-in-1 connectivity single chip, this chip includes 2.4GHz and 5GHz WLAN IEEE 802.11 a/b/g/n/ac 2x2 MU-MIMO 20/40/80 MHz VHT R2 MAC/PHY/Radio, Bluetooth 5.1.
	BB_EC618,		//�Ϻ���о Eigencomm, Cat1оƬ. EC618 is a Cat.1bis SoC chipset with ultra-low cost, ultra-low power and ultra-high integration, it is fully compliant to 3GPP Rel14 Cat.1bis standard��and compatible with 4G commercial networks.
	BB_EFR32BG21,	//о�ƿƼ�(Silicon Labs), ����+LoRa��оƬ, EFR32BG21 Blue Gecko Wireless SoC Family.
	BB_CYW43438,	//The Cypress CYW43438L is a highly integrated single-chip solution and offers the lowest RBOM in the industry for smartphones, tablets, and a wide range of other portable devices.
	BB_UIS8850DG,	//չ�� UIS8850DG is a highly integrated system on chip solution with embedded LTE Cat1bis modems, GNSS modem, RF transceiver, power management unit(PMU), Trust zone and Multi-Function Crypto Engine(CE).
	BB_CYW8X072,	//The Cypress CYW8X072 is a monolithic, single-chip, Bluetooth 4.2 compliant, stand-alone baseband processor with an integrated 2.4 GHz transceiver.
	BB_WCN3950,		//��ͨWiFiоƬ
	BB_W155S1,		//Amlogic W155S1 is an integrated Wi-Fi and Bluetooth combo chip. WiFi&BTоƬ, ֧��802.11_a/b/g/n/ac@WLAN2.4G&5G, BT5.0��BLE��BDR/EDR��.
	BB_CYW43439,	//The Cypress CYW43439 is a highly integrated single-chip solution and offers the lowest RBOM in the industry for smartphones, tablets, and a wide range of other portable devices.
	BB_CB0201,		//��˼ CB0201 ��һ�˼ƽ̨�͹��ĵ�NB-IOTоƬ��֧��3GPP R13/R14/R15 NB-IoT��֧��Rel-16��������ͬʱ֧��BLE/GNSS��
	BB_ASR1606C,	//ASR��LTE CAT1/MоƬ, ASR1606 is a highly cost-efficient System on Chip (SoC) device.��4M RAM+ 4M ROM��
	BB_ASR1606S,	//ASR��LTE CAT1/MоƬ, ASR1606 is a highly cost-efficient System on Chip (SoC) device.��8M RAM+ 8M ROM��
	BB_WCN6856,		//��ͨWiFiоƬ
	BB_QCX216,		//��ͨ compact, low power, low-cost LTE Cat.1bis chip, WiFi2.4GHz Rx.
	BB_QCA206x,		//��ͨ The Qualcomm QCA206x family consist of System-On-Chips (SoC), Bluetooth Milan and Wi-Fi supported, supporting simultaneous operation on 2.4 GHz, 5 GHz, and 6GHz*, also known as Dual Band Simultaneous (DBS). Part Number(s): QCA2065, QCA2066, QCA2062, QCA2064.
	BB_ASR1828,		//ASR��4GоƬ, LTE CAT-6, 1826�ĵ�����Ʒ.
	BB_IPQ5018,		//��ͨ�����������壩, ֧��Wi-Fi 6
	BB_QCA6574,		//��ͨWiFiоƬ, The QCA6574A is a single-die wireless local area network (WLAN) and Bluetooth combo solution to support 2 �� 2 MIMO with two spatial streams IEEE802.11 a/b/g/n/ac WLAN standards and Bluetooth 5.0 enabling seamless integration of WLAN/Bluetooth and Low Energy technology.
	BB_QCA6698,		//��ͨ���漶WiFi/BTоƬ. The QCA6698AQ the most advanced premium Wi-Fi/BT combo chipset in the automotive industry. Wi-Fi 6e Dual MAC 802.11ax MIMO DBS 2x2+ 2x2 BT 5.3 for Automotive Applications.
	BB_EC616L,		//�Ϻ���о ���͹���NB-IoT��ģоƬ
	BB_INT100854,	//оƬ��IONAоƬƽ̨��Orbcommƽ̨�̣�Ӧ�����������ӵ�ģ�鿪����ʵ�������ǵ����ݴ���
	BB_SA2150P,		//SA2150P chipset is a Qualcomm Snapdragon application processor for use with C-V2X and Telematics applications.
	BB_SA8155P,		//SA8155P �Ǹ�ͨ����оƬ
	BB_CX1910,		//CX1910���о�Ƽ����޹�˾�ĳ��漶��ģ˫ͨC-V2XоƬ, ��ʵ�ֶ���Modem����, ��������LTE FDD/TD-LTE �����������
	BB_CYW8x570D,	//The Cypress CYW8x570D single-chip device provides the highest level of integration for Automotive and Industrial IoT wireless systems with integrated Dual-band 2x2 MIMO IEEE 802.11ax WLAN MAC/baseband/radio, Bluetooth 5.3 MAC/baseband/radio, and integrated Power Management Unit.
	BB_UIS7885,		//չ�� UNISOC 5G����ģ��ƽ̨ UIS7885 is a high performance application processor with integrated 2G/3G/4G/5G modem.
	BB_MT6990,		//MTK 5G оƬ, T830 ��Ƭ, MT6990 5G Modem Application.
	BB_ECR6600A,	//ECR6600-Aϵ��оƬ�Ǳ�����˹ΰ�Ƽ��������޹�˾����ơ�ESWIN������һ��߶ȼ��ɵĵ͹���ϵ��оƬ��һ��߶ȼ��ɵĵ͹��� WiFi/BLE Combo оƬ�����������ܼҾ� IoT ��Ӧ�ö���Ƶ�ϵͳ��оƬ�� SoC ��
	BB_W265P1,		//Amlogic W265P1 is a Wi-Fi/Bluetooth combo chip supporting 2T2R 802.11ax and Bluetooth 5.2. Wi-Fi6оƬ, ��֧��2.4GHz��5GHzƵ�Σ�Bluetooth 5.2��֧��PCIe 2.1.
	BB_UWE5622,		//չ�� UNISOC WiFi/���� оƬ, UWE5622 is a highly integrated 2-in-1 connectivity single chip which offers the lowest RBOM in the industry for PC, STB, OTT, industrial control and automotive applications. This chip includes 2.4 GHz and 5 GHz WLAN IEEE 802.11 a/b/g/n/ac 1x1 DL MU-MIMO 20/40/80 MHz VHT R2 MAC/PHY/Radio, Bluetooth 5 with supporting high power mode, Mesh, Direction Finding and Long Range.
	BB_SV6115,		//�Ϸ����?iComm, The SV6115 is a fully integrated SoC with 2.4GHz band 1T1R 11b/g/n/ax Wi-Fi, and MCU. Single-chip IEEE 802.11b/g/n/ax WLAN SoC with USB Interface.
	BB_SV6358,		//�Ϸ����?iComm, The SV6358 is a fully integrated SoC with 2.4GHz band 1T1R 11b/g/n/ax Wi-Fi, Bluetooth Low Energy 5.0, and MCU. Single-chip IEEE 802.11b/g/n/ax WLAN and BLE Combo SoC with USB and SDIO Interface.
	BB_RK3568,		//Rockchip ��о΢, �е����ܴ�����, SATA/PCIE/USB3.0�ȸ�������Χ�ӿ���ȫ, ������AIӦ��, ����������, NVR�洢, �����п�, ��׿10.0�����ϰ汾
	BB_QCN9024,		//��ͨWiFiоƬ, QCN9024 is an 802.11ax Wi-Fi 6E PCIe radio for Retail/Carrier Routers and Mesh nodes. QCN9024 with Qualcomm? 802.11ax technology is a highly integrated wireless local area network (WLAN) system-on-chip (SoC) for 2.4/5/6 GHz IEEE802.11ax/ac/n/g/b/a applications.
	BB_SCHA634,		//SCHA634 �Ǵ����6�ᴫ����, SCHA600 Series: 6-DOF XYZ-Axis Gyroscope and xyz-Axis Accelerometer with digital SPI interface.The SCHA600 is a combined high performance 3-axis angular rate and 3-axis accelerometer.
	BB_ASR1606L,	//ASR��LTE CAT1/MоƬ
	BB_SM6350,		//��ͨ, ����SMART��Ʒ. SM6350 includes the next generation of the Qualcomm? Snapdragon? 600 series processor with integrated 5G modem. It implements the 5G NR standard for sub-6 GHz bands. More RF operating bands and advanced techniques with SDR735: 3G/4G/5G modem�C sub-6 GHz bands.
	BB_SA522M,		//��ͨ 5G NR оƬ, ���� 5G R16 ƽ̨, ����SMART, ��SA515Mƽ̨һ���ģ��൱�������档The SA522M device is the second 5G modem from Qualcomm Technologies, Inc. (QTI). It implements the 5G NR standard for sub-6 GHz bands.
	BB_UIS7863,		//չ�� UNISOC 4G ƽ̨оƬ, Smart����ģ���Ʒ��
	BB_RTL8723,		//Realtekƽ̨WiFi������оƬ
	BB_BK7256,		//BK7256�Ǹ߶ȼ��ɵ�1x1��Ƶ2.4GHz Wi-Fi6(802.11b/g/n/ax)������5.2��Ͻ��������רΪ��Ҫ�߰�ȫ�Ժͷḻ��Դ��Ӧ����ơ�˫32λRISC-V MCU��ȫ������ļ���ʹBK7256��Ϊ�߼�������(IoT)Ӧ�õ�����ѡ��
	BB_MT6825,		//MTK MT6825оƬ���������ǲ�Ʒƽ̨, ����IoT-NTN. MT6825�Ļ����ܹ���������NBоƬMT2625��ʵ�ַ�ʽ.
	BB_CYW8X373,	//The Cypress CYW8x373���磺CYW88373�� single-chip device provides the highest level of integration for Automotive IoT wireless systems with integrated single-stream IEEE 802.11a/b/g/n/ac MAC/baseband/radio and Bluetooth 5.2 (Basic Rate, Enhanced Data Rate and Bluetooth Low Energy).
	BB_SA525M,		//��ͨ SA525M Ϊ��ͨ���� R16 5G ƽ̨, ����SMART. The SA525M device is the second 5G modem from Qualcomm Technologies, Inc. (QTI). It implements the 5G NR standard for sub-6 GHz bands.
	BB_QCS8550,		//��ͨ The QCS8550������ SMART ��Ŀ�� device is the new generation Qualcomm? Snapdragon? premium-tier SoC. It is designed with a 4 nm process, for superior performance and power efficiency.
	BB_WCN7851,		//��ͨWiFiоƬ, The WCN7851 device is a highly integrated System-On-Chip (SoC) supporting Wi-Fi 7 and Bluetooth (BT) 5.3. The WCN7851 supports simultaneous operation on 2.4 GHz + 5 GHz, 2.4 GHz + 6 GHz and 5 GHz + 6 GHz.
	BB_AIC8800D80,	//����΢�뵼�� AIC8800D80 is a highly integrated chip with dual band Wi�\Fi6, BTDM5.3 for wireless application.
	BB_AIC8800F,	//����΢�뵼�� AIC8800F is a highly integrated SoC with dual band WiFi6 , BTDM5.2 , and high�\performance Cortex�\M4F for wireless application. And support external QSPI flash.
	BB_MM6108,		//Ħ��˹΢ Morse Micro provides a complete Wi-Fi HaLow connectivity solution. The MM6108 SoC is a single-chip solution, including Radio, PHY, and MAC sections designed in compliance with the IEEE 802.11ah standard, supporting data rates up to 32.5 Mbps.
	BB_XY1200,		//о����Ϣ�Ƽ��Ƴ��ĵڶ���NB-IoT SoC XY1200��XY1200��ҵ����߼��ɶȣ�֧����32K������ƣ�ͬʱ���г��͹��ĺͳ������ܵ�NB-IoTоƬ����Ӧ�������ܱ�ơ������̸С������Ŵŵȶ������XY1200ӵ�еĸ߼��ɶȡ���32K����У׼�������ɴ���Ƚ����û����ۺϳɱ���
	BB_88Q9098,		//�����ְ뵼�壬NXP��88Q9098 ��������SoCϵ����ҵ���׸���������IEEE802.11ax��׼��Wi-Fi6���������֧��2x2+2x2����˫Wi-Fi��˫ģ����5.3��88Q9098 ϵ�й����ݵ����߽��������������������5��2x2 + 2x2����˫Wi-Fi (AEC-Q100����)��88Q9098S - ��������5��2x2 + 2x2����˫Wi-Fi (AEC-Q100����)��
	BB_RTL8822CS,	//Realtek/���� RTL8822CS ����ģ�����IEEE802.11 a/b/g/n/ac��׼������802.11ac������ʵ��433.3Mbps���������ӵ����߾�������WiFiģ���ṩ������������wifi��UART/PCM�ӿڵ�SDIO�ӿڡ�
	BB_UIS8821,		//չ�� UIS8821 is an advanced system-on-chip solution integrated IOT-NTN modems. Building on the success of UNISOC��s current solutions, the UIS8821 integrates RF transceiver for low cost.
	BB_RTL8821CS,	//Realtek/���� The Realtek RTL8821CS is a highly integrated single-chip that supports 1-stream 802.11ac solutions with Multi-user MIMO (Multiple-Input, Multiple-Output) STA mode with integrated Bluetooth Smart Ready controller, SDIO (SDIO 1.1/2.0/3.0) interface, and HS-UART mixed interface.
	BB_ANT_PRODU,	//ANT���߲�Ʒ
	BB_SDX72,		//��ͨ 5G оƬ, The SDX72 device is a multimode modem chip, supporting 2G/3G/4G/5G technologies. It is designed with an advanced 4 nm process for superior performance and power efficiency. SDX72������SMART����ģ���ƷоƬ.
	BB_SDX75,		//��ͨ 5G оƬ, The SDX75 device is a multimode modem chip, supporting 2G/3G/4G/5G technologies. It is designed with an advanced 4 nm process for superior performance and power efficiency. SDX75������SMART����ģ���ƷоƬ.
	BB_ASR1602,		//ASRƽ̨, ASR1602 is a highly cost-efficient System on Chip (SoC) device which integrates application processing subsystem, communication subsystem, PMU, and embedded pSRAM + flash to enable the most compact single-chip LTE single-mode data module, POC, POS, and other IoT solutions.
	BB_SM6225,		//��ͨ Qualcomm SM6225, 4G SMART оƬ, Qualcomm Snapdragon 4G Platforms in Mid and Low Tiers.
	BB_UWE5621,		//չ�� UNISOC WiFi/���� оƬ, UWE5621DS is a highly integrated 2-in-1 connectivity single chip which offers the lowest RBOM in the industry for PC, STB, OTT, industrial control and automotive applications. This chip includes 2.4 GHz and 5 GHz WLAN IEEE 802.11 a/b/g/n/ac 2��2 MU-MIMO 20/40/80 MHz VHT R2 MAC/PHY/Radio, Bluetooth? 5.0 Smart Ready compliant with supporting high power mode, Mesh, Direction Finding and Long Range.
	BB_ASR1806,		//ASRƽ̨, The ASR1806 is an advanced, highly integrated communication processor and LTE/3G/2G platform for data communication applications.
	BB_IW612,		//�����ְ뵼�壬NXP��The IW612 is a highly integrated 2.4/5 GHz dual-band 1x1 Wi-Fi 6, Bluetooth/Bluetooth Low Energy 5.2 and 802.15.4 tri-radio single-chip solution optimized for a broad array of IoT and industrial applications in smart home, smart devices and accessories, smart appliances, smart energy, industrial automation, gateways and many more.
	BB_QCM5430,		//��ͨ 5G Smart����оƬ����QCM6490ƽ̨�ĵ���汾����������汾��The QCM6490/QCM5430 device is the new generation Qualcomm? Snapdragon 5G SoC with an integrated modem. It is designed with the 6 nm process, for superior performance and power efficiency.
	BB_QCM4490,		//��ͨ Qualcomm 5G SMART ����оƬ, The QCM4490 device is the new generation Snapdragon? 5G SoC with an integrated modem. It is designed with the 4 nm process, for a superior performance.
	BB_SDX35,		//��ͨ 5G ƽ̨, The SDX35 device is a multimode modem chip, supporting 4G/5G technologies. It is a 4 nm chip designed for superior performance and power efficiency. SDX35 ������ SMART ����оƬ��SDX35 ��ȫ��ƽ̨��ģʽ��������Ϊ�� 5G RedcapоƬ���ʹ�ͳ��5G��MBB����оƬҲ�в��죬û��CA��ENDC��
	BB_ATK4055,		//Autotalks SECTON (ATK4055C), SECTON is an automotive-grade V2X hardware add-on. SECTON helps achieving the highest level of communications and safety decision reliability, while minimizing the quantity of required system external components. ���� SMART ����оƬ��
	BB_FR801xH,		//������ FR801xH ϵ��оƬ��FR8012HAQ��FR8016HA��������SOC��Ƭ��ϵͳ�������ڿ��ٿ����ĵ͹�������оƬ������Freqchip���������ܹ̼���Э��ջ��֧�֣���ȫ��������V5.1��LEģʽ��Э�顣ͬʱ�û����Ի���оƬ���õ�ARM CorteM3Ƕ��ʽ32λ�����ܵ�Ƭ����������Ӧ�ó��򡣲��ǡ�SMART����оƬ��������MCU WIFI��ʵ����BLE��
	BB_AIC8800MC,	//����΢�뵼�� AICSEMI INC. AIC8800MC is a highly integrated chip with 2.4GHz WiFi6, BT5.2 for wireless application. AIC8800MC Low�\Energy WiFi6/BT5.2 SoC.
	BB_BK7238,		//��ͨ���ɵ�·, BK7238��һ��߶ȼ��ɵĵ�оƬWi-Fi802.11n�͵͹�������(BLE)5.2��Ͻ��������רΪ�͹��ĺ�С�ռ�Ӧ����Ƶġ�BK7238�����˹���ǿ���32λMCU��ȫ������ͽӿڣ��Ǹ߼�������(IoT)Ӧ�õ�����ѡ��
	BB_RTL8731,		//The Realtek RTL8731BU is a highly integrated single-chip 802.11a/b/g/n 1T1R WLAN with USB 2.0 multi-function.
	BB_RTL8733,		//The Realtek RTL8733BS is a highly integrated 802.11a/b/g/n 1T1R WLAN and Bluetooth 5.2 combo chip.
	BB_EC718,		//�Ϻ���о Eigencomm, EC718 is a Cat.1bis SoC chipset with ultra-low cost, ultra-low power and ultra-high integration, it is fully compliant to 3GPP R14 Cat.1bis standard��and compatible with 4G commercial networks. ����EC718ƽ̨����EC718S\EC718P��Ҫ�������Ǵ洢ѡ��һ�������߿ɹ�ͬ�ο�EC718��datasheet�ĵ�.
	BB_QCS5430,		//��ͨ 5G Smart ����оƬ��QCS5430оƬ�Ǹ�ͨ���QCM/QCS6490ֻ�����������ϵĲü�������֧�ֵĹ�����һ����. QCS��ȥ�����Ѱ汾��, QCM�Ǵ����Ѱ汾��, ������QCM6490��QCS6490һ��. The QCS6490/QCS5430 is available in the PSP1287 that includes dedicated ground pins for improved grounding, mechanical strength, and thermal continuity.
	BB_CYW4373E,	//The Cypress CYW4373E single-chip device provides the highest level of integration for Industrial IoT wireless systems with integrated single-stream IEEE 802.11a/b/g/n/ac MAC/baseband/radio and Bluetooth 5.0 (Basic Rate, Enhanced Data Rate and Bluetooth Low Energy).
	BB_MT8766,		//MTK 4G Smart ����оƬ, The MT8766WB device, with integrated Bluetooth, FM, WLAN and GPS modules, is a highly integrated baseband platform incorporating both modem and application processing subsystems to enable LTE/LTE-A and C2K smart device applications.
	BB_BG21A10768I,	//о�ƿƼ�(Silicon Labs), ����оƬ, EFR32BG21 Blue Gecko ���� SoC ��Ʒϵ��, ��ΪSilabs��оƬ��ͷ����EFR32BG21�������޷�����, ����оƬƽ̨����10dbm��BG21A10768I
	BB_BG21A20768I,	//о�ƿƼ�(Silicon Labs), ����оƬ, EFR32BG21 Blue Gecko ���� SoC ��Ʒϵ��, ��ΪSilabs��оƬ��ͷ����EFR32BG21�������޷�����, ����оƬƽ̨����20dbm��BG21A20768I
	BB_ASR1609,		//ASR��LTE CAT1оƬ, ASR1609S 8+8����, ASR1609C 4+4����, ASR1609 is a highly cost-efficient System on Chip (SoC) device which integrates application processing subsystem, communication subsystem, audio codec, BT/BLE, GNSS and embedded pSRAM + flash to enable the most compact single-chip LTE CAT1 data module, POC, POS, and other IoT solutions.
	BB_BK7235,		//��ͨ���ɵ�·, The BK7235 is a highly integrated 1x1 single-band 2.4 GHz Wi-Fi 6 (802.11b/g/n/ax) and Bluetooth 5.2 Low Energy (LE) combo solution designed for applications that require high security and abundant resources.
	BB_UIS7870,		//չ�� UNISOC 5G����ģ��ƽ̨ UIS7870 is a high performance application processor with integrated 2G/3G/4G/5G modem. 6nm EUV process for best-in-class power-efficient 5G SOC chip.
	BB_DW3300Q,		//Qorvo ��Ѷ���ϰ뵼�����޹�˾ The DW3300Q is a fully integrated low-power, single chip CMOS RF 6.5GHz-8GHz IR-UWB transceiver IC compliant with the IEEE Std 802.15.4?�\2020 (HRP UWB PHY), IEEE Std 802.15.4z?�\2020 and IEEE 802.15.8 standards.
	BB_QCA66x8,		//��ͨ���漶WiFi/BTоƬ. QCA6688 �� QCA6698 ����һ������. The QCA66x8AQ is a series of highly integrated system-on-chip (SoC) devices supporting 802.11ax Wi-Fi 6 or Wi-Fi 6E, and Bluetooth (BT) v5.3 for automotive applications.
	BB_MT2737,		//MTK 5G ����ģ��оƬ. The MT2737 device is a highly integrated baseband platform incorporating both modem and application processing subsystems to enable LTE/LTE-A and NR modem applications.
	BB_QCM4325,		//��ͨ Qualcomm QCM4325, 4G SMART оƬ, �Ǵ�8�� SM6225 COSTDOWN ��6��. The QCM4325 SoC is the next generation Qualcomm Technologies, Inc. (QTI) mid-tier processor and LTE modem. It is designed with 6 nm process for superior performance and power efficiency.
	BB_BES2600IUC,	//Bestechnic �����Ƽ� BES2600IUC-4X is an ultra-low power and highly integrated Bluetooth audio SoC which features the dual-core STAR-MC1 processor for TWS and voice applications.
	BB_EC716S,		//�Ϻ���о Eigencomm, EC716S is a Cat.1bis IoT SoC chipset with ultra-low cost, ultra-low power and ultra-high integration , and is fully compliant to 3GPP Rel14 Cat.1bis standard��and compatible with 4G commercial networks.
	BB_STM32WLE5xx,	//ST �ⷨ�뵼��, The STM32WLE5/E4xx long-range wireless and ultra-low-power devices embed a powerful and ultra-low-power LPWAN-compliant radio solution, enabling the following modulations: LoRa?, (G)FSK, (G)MSK, and BPSK.
	BB_QCS6490,		//��ͨ 5G Smart ��������ģ��, ����5G�汾. QCM6490ȥ�����Ѳ���. QCS��ȥ�����Ѱ汾��, QCM�Ǵ����Ѱ汾��, ������QCM6490��QCS6490һ��. The QCS6490/QCS5430 is available in the PSP1287 that includes dedicated ground pins for improved grounding, mechanical strength, and thermal continuity.
	BB_MT7927,		//MTK WiFi/���� оƬ, MT7927BEW is a highly integrated single chip which features a low power 2x2 2.4GHz and 2x2 5/6GHz DBDC 11a/b/g/n/ac/ax/be Wi-Fi subsystem and a Bluetooth v5.3 subsystem, offering feature-rich wireless connectivity at high standards, and delivering reliable, cost-effective throughput from an extended distance.
	BB_RTL8852,		//The Realtek RTL8852BS is a highly integrated single-chip that supports 2-stream 802.11ax solutions with Multi-user MIMO (Multiple-Input, Multiple-Output) with Wireless LAN (WLAN) SDIO (SDIO 1.1/2.0/3.0) interface controller with integrated Bluetooth 5 HS-UART interface controller. It combines a WLAN MAC, a 2T2R capable WLAN baseband, and RF in a single chip. The RTL8852BS provides a complete solution for a high-performance integrated wireless and Bluetooth device.
	BB_MDM9205S,	//��ͨ4GоƬ, The Qualcomm? 9205 LTE modem (MDM9205/MDM9205S) is the new generation LTE IoT mobile data modem (MDM). MDM9205S supports non-terrestrial network (NTN). MULTIMODE, M1, NB1, 2G, NTN, VoLTE/IMS, and GNSS.
	BB_GENERAL_MCU,	//ͨ��MCUоƬ
	BB_NRT81750,	//Ŧ��оUWB��λͨ��ϵͳоƬ NRT81750 ��һ��߼��ɡ������ܡ��͹��ĵĳ������UWB����λͨ��ϵͳоƬ��Ƶ��֧��CH5~CH12��8��UWB BAND (6.0 GHz to 9.25GHz)����ߴ���֧�ֵ�1.3GHz��ͬʱ֧��IEEE802.15.4-2020��IEEE802.15.4zЭ���׼�Լ�CCC��FiRa���˹淶����оƬ���ڳ����׼���߱������淶���Ӳ�Ʒ���嵽��ơ����ա����������ԡ����������ϸ��ճ����׼������
	BB_SM4250,		//��ͨ Smart 4Gƽ̨. The SM4250 includes the next generation of the Qualcomm? Snapdragon?400 series processor and LTE modem.
	BB_EC626,		//�Ϻ���о Eigencomm, EC626 is a NB-IoT SoC chipset with ultra-low cost, ultra-low power and ultra-high integration, and is fully compliant to 3GPP Rel14 NB-IoT standard.
	BB_SXR2130P,	//��ͨ������ʵ������. SXR2130P is the new generation Qualcomm? Snapdragon? premium-tier processor for eXtended reality(XR) applications. It is designed with the 7 nm process, for superior performance and power efficiency.
	BB_AIC8800DC,	//����΢�뵼�� AICSEMI INC. AIC8800DC������˫ģBT&BLE��֧��. ��Ƶ Wi-Fi 6 ģ�飬֧������ 5.2��˫ģ.
	BB_AIC8800DL,	//����΢�뵼�� AICSEMI INC. AIC8800DL��������ģ��֧��BLE. ��Ƶ Wi-Fi 6 ģ�飬֧�� BLE 5.2����ģ.
	BB_HTD1011,		//HTD1011 �Ǳ���������ͨ�ɷ����޹�˾��Hwa Create Company�������ľ�����ȫ����֪ʶ��Ȩ�������ƶ�ͨ�Ż�������оƬ��оƬȫ��֧����ͨһ�������ƶ�ͨ��ϵͳ��ʽ����Զ���롰������ͨ����˾ǩ�ļ���Э�顣
	BB_QCC2073,		//The QCC2073 device is a highly integrated System-On-Chip (SoC) supporting Wi-Fi 7 and Bluetooth (BT) 5.3. The QCC2073 supports simultaneous operation on 2.4 GHz, 5 GHz and 6 GHz.
	BB_QCC2076,		//The QCC2076 device is a highly integrated System-On-Chip (SoC) supporting Wi-Fi 7 and Bluetooth (BT) 5.3. The QCC2076 supports simultaneous operation on 2.4 GHz +5 GHz, 2.4 GHz + 6 GHz and 5 GHz + 6 GHz.
	BB_UIS7861,		//չ�� UNISOC 4G ƽ̨оƬ, Smart����ģ���Ʒ��UIS7861��UIS7863��costdown��Ƶ��UIS7861 is a highly integrated application processor with embedded TD-LTE, LTE FDD, WCDMA/HSPA(+), WCDMA/DC-HSDPA, and GSM/GPRS/EDGE. The specially optimized architecture of UIS7861 can achieve high performance and low power for a lot of applications. Overall, UIS7861 chipset presents a high cost-effective platform for four mode Android mobile devices.
	BB_EC718E,		//�Ϻ���о Eigencomm, EC718E is a Cat.1bis SoC chipset with ultra-low cost, ultra-low power and ultra-high integration, ����Ҫ��������, ��Ϊ����Ҫ��顰APP BIN �ļ��Ƿ���ڡ���
	BB_QCX217,		//��ͨ��ʵ������оƽ̨оƬ��QCX217 is a Cat.1bis IoT SoC chipset with ultra-low cost, ultra-low power, ultra-high integration, fully compliant to 3GPP Rel. 14 Cat.1bis standard, and compatible with 4G commercial networks.
	BB_RW610,		//�����ְ뵼�壬NXP��The RW610 is a highly integrated, low-power Wireless MCU with an integrated MCU and Wi-Fi 6 + Bluetooth Low Energy (LE) 5.3 radios designed for a broad array of applications. ��WiFi����оƬ.
	BB_XIN100,		//Xincomm, �͹�����оƬ, XIN100-R2 is a TDD/FDD dual mode LTE baseband chip compliant to 3GPP standard for user-end devices. It implements all 3GPP R8/R9 functionalities and supports category-4 throughput (150Mbps DL / 50Mbps UL).
	BB_OM6681x,		//OnMicro ����΢, OM6681x dual core system, include Application Core and SensorHubCore, there are several shared System Peripheral blocks between AppCore and SensorHubCore. Application core is a Coretex-M33S core plus multiple Master/slave AHB standard system. Support full BT 5.2 dual-mode feature (BT BR/EDR and BLE).
	BB_HC32F4A0PGTB,//HC32F4A0PGTB �� ARMv7-M �ܹ� 32bit Cortex-M4 CPU������FPU��MPU��֧��SIMDָ���DSP��ȫָ����ٵ�ԪETM�� ��CoreSight��׼���Ե�Ԫ����߹�����Ƶ 240MHz���ﵽ 300DMIPS��825Coremarks���������ܡ�
	BB_EC718P,		//�Ϻ���о Eigencomm, EC718P is a Cat.1bis SoC chipset with ultra-low cost, ultra-low power and ultra-high integration, ����Ҫ��������, ��Ϊ����Ҫ��顰APP BIN �ļ��Ƿ���ڡ���
	BB_ASR1607,		//ASR �� LTE CAT1 оƬ, ASR1607 is a highly cost-efficient System on Chip (SoC) device which integrates application processing subsystem, communication subsystem, GNSS, audio codec, PMU, and embedded pSRAM + flash to enable the most compact single-chip LTE single-mode position IoT solutions. The communication subsystem integrates LTE CAT1 modem baseband and RF transceiver to cover 600MHz~2.7GHz bands for worldwide roaming. 
	BB_ASR1903S,	//ASR �� 5G оƬ, ���ڷ���ģ��, ��SMART����, ASR1903 is a highly cost-efficient Rel.17 RedCap 5G NR System on Chip (SoC) device which integrates application processing subsystem, communication subsystem, audio codec, and embedded LPDDR. The communication subsystem integrates NR RedCap and LTE CAT4 modem baseband and RF transceiver to cover 450MHz~6GHz bands.
	BB_ASR1903E,	//ASR �� 5G оƬ, ���ڷ���ģ��, ��SMART����, ASR1903 is a highly cost-efficient Rel.17 RedCap 5G NR System on Chip (SoC) device which integrates application processing subsystem, communication subsystem, audio codec, and embedded LPDDR. The communication subsystem integrates NR RedCap and LTE CAT4 modem baseband and RF transceiver to cover 450MHz~6GHz bands.
	BB_ASR1903L,	//ASR �� 5G Linux оƬ, ���ڷ���ģ��, ��SMART����, ASR1903 is a highly cost-efficient Rel.17 RedCap 5G NR System on Chip (SoC) device which integrates application processing subsystem, communication subsystem, audio codec, and embedded LPDDR. The communication subsystem integrates NR RedCap and LTE CAT4 modem baseband and RF transceiver to cover 450MHz~6GHz bands.
	BB_CYW5551x,	//The Cypress, The AIROC? CYW5551x family single-chip device provides the highest level of integration for commercial and consumer systems, with integrated IEEE 802.11 a/b/g/n/ac/ax 1x1 MAC/baseband/radio, Bluetooth? 5.4 +EDR+LE. It provides a small form-factor solution with minimal external components to drive down cost and allows for platform design flexibility in size, form, and function. AIROC? Wi-Fi & Bluetooth? combo chip Low-power, 1 x 1, tri-band, IEEE 802.11ax, Wi-Fi 6/6E, Bluetooth? 5.4.
	BB_OM6626,		//OnMicro ����΢, OM6626 High Performance Bluetooth Low Energy Wireless Radio Chip. Bluetooth Low Energy (Compatible with Bluetooth 5.3)
	BB_MT6813,		//MTK 5G оƬ, 4G/5G NR RedCap modem. Supports LPDDR4X. MT6813 is a highly integrated SoC incorporating modem, RF, and application processing subsystems to enable NR RedCap and LTE Cat-4 modem applications. The chip integrates an Arm? Cortex-A35 processor operating up to 888 MHz.
	BB_BK7258,		//��ͨ���ɵ�·, The BK7258 is a highly integrated 1x1 single-band 2.4 GHz Wi-Fi 6 (802.11b/g/n/ax) and Bluetooth 5.4 Low Energy (LE) combo solution designed for applications that require abundant resources and low power consumption. The integration of a 32-bit ARMv8-M Star MCU and a comprehensive set of peripherals makes the BK7258 ideal for advanced Internet of Things (IoT) applications.
	BB_SM6450P,		//��ͨ SMART ����ƽ̨������6 Gen1оƬ���ͺ�SM6450�����ø�ͨKyro CPU��Ƶ����߿ɴ�2.2GHz��֧��USB 3.1�͸ߴ�12GB��LPDDR5�ڴ棬Ƶ�ʸߴ�2750MHz�������緽�棬��оƬ�齫��������X62 5G�������ṩ5G���ײ���6GHz����Ƶ��֧�֡����оƬ֧�ָߴ�FHD+�ֱ��ʵ�120Hzˢ������ʾ����WiFi���潫֧�ָ�ͨFastConnect 6700 WiFi 6E�����һ���֧������5.2��The SM6450P device is the new generation Snapdragon? SoC. It is designed with the 4 nm process for superior performance. SM6450P includes the following key components: Qualcomm? Kryo? CPU 6xx built on Arm Cortex technology. Qualcomm? Adreno? GPU 7xx for better graphics performance and power efficiency.
	BB_WCN6750,		//��ͨWiFiоƬ, û��DBS, ������WCN6856һ����
	BB_ASR1605,		//ASRƽ̨, ASR1605 is a highly cost-efficient System on Chip (SoC) device which integrates application processing subsystem, communication subsystem, PMU, and embedded pSRAM + flash to enable the most compact single-chip LTE single-mode data module, POS, and other IoT solutions. The communication subsystem integrates LTE CAT1 modem baseband and RF transceiver to cover 600MHz~2.7GHz bands for worldwide roaming.
	BB_SG4250P,		//��ͨ Qualcomm ��Ϸ��ҵ�� SMART ����оƬ, The SG4250P device is a mainstream tier Snapdragon? gaming processor for game streaming platform. It is designed with the 4 nm process for a superior performance. External WCN3950 supports WLAN 1 �� 1 802.11a/b/g/n/ac and Bluetooth 5.0; External WCN3988 supports WLAN 1 �� 1 MU-MIMO 802.11a/b/g/n/ac, 11ax ready, Bluetooth 5.1.
	BB_RTL8710,		//Realtek ƽ̨ WiFi������ SOC оƬ��The RTL8710EC is a low-power single-chip microcontroller integrating dual RISC cores (Arm Cortex-M55 compatible instruction set and RISC-V compatible instruction set).
	BB_TG7100C,		//ƽͷ��뵼�����޹�˾��TG7100C��һ��Wi-Fi+BLE��ϵ�оƬ�飬���ڵ͹��ĺ͸�����Ӧ�ÿ�����������ϵͳ����2.4G���ߵ磬Wi-Fi 802.11b/g/n��BLE5.0����/MAC��ơ�΢��������ϵͳ����һ���͹��ĵ�32λRISCCPU�����ٻ���ʹ洢������Դ����Ԫ���Ƶ͹���ģʽ��
	BB_CYW8x310,	//Infineon Ӣ���裬������BT5.3��AIROC? CYW8x310 single-chip device provides the highest level of integration for Automotive systems, with integrated Bluetooth? 5.3 + EDR. It provides a small form-factor solution with minimal external components to drive down cost and allows for platform design flexibility in size, form, and function. ��Ӣ����������ɿ�����оƬ���������� CYPRESS ��������CYW89310 �������������
	BB_EC716E,		//�Ϻ���о Eigencomm, EC716E �ǻ��� EC716S �������汾, ���ߵĲ�����Ҫ��Flash�洢��С����, ͬʱ EC716E оƬҪ��� APP BIN �ļ���a Cat.1bis IoT SoC chipset with ultra-low cost, ultra-low power and ultra-high integration , and is fully compliant to 3GPP Rel14 Cat.1bis standard��and compatible with 4G commercial networks.
	BB_SDX61,		//��ͨ 5G оƬ, ����, The SDX61 device is a multimode modem chip, supporting 2G/3G/4G/5G technologies. It is designed with a 4 nm process for superior performance and power efficiency. SDX61 �� SDX62 оƬ���ƣ�����5G��Ŀ��
	BB_RTL8832CU,	//Realtek/���� The Realtek RTL8832CU-VF1-CG is a highly integrated single-chip that support 2-stream 802.11ax solutions with Multi-user MIMO (Multiple-Input, Multiple-Output) with Wireless LAN (WLAN). It combines a WLAN MAC, a 2T2R capable WLAN baseband, and RF in a single chip.
	BB_NT98568MBG,	//Novatek NT98568MBG is a highly-integrated SoC with high image quality, low bitrate, low power consumption for battery application with pre-roll and always-on mode, targets on 2Mp to 5Mp/8Mp Edge-IP camera application.
	BB_QCM6690,		//��ͨ Smart 5G ƽ̨. The QCM6690 device is the new generation Qualcomm? 5G SoC with an integrated modem. It is designed with the 4 nm process, for superior performance. 2G/3G/4G/5G modem �C mmWave and sub-6 GHz bands (Rel. 16 integrated modem) with SDR435/SDR735 and 5G DSDA.
	BB_RW612,		//�����ְ뵼�壬NXP��The RW612 is a highly integrated, low-power tri-radio Wireless MCU with an integrated MCU and Wi-Fi 6 + Bluetooth Low Energy (LE) / 802.15.4 radios designed for a broad array of applications.
	BB_N32G430,		//Nationstech �������ɷ����޹�˾����ƣ�����������MCUоƬ��N32G430 ϵ�в��� 32-bit ARM Cortex-M4F �ںˣ���߹�����Ƶ 128MHz��֧�ָ�������� DSP ָ����� �ߴ� 64KB Ƕ��ʽ���� Flash��16KB SRAM�����ɷḻ�ĸ�����ģ������������ 1 �� 12bit 4.7Msps ADC��3 �����ٱȽ��������ɶ�· U(S)ART��I2C��SPI��CAN ������ͨ�Žӿڡ�Ŀǰ�����ڵ�����ơ��綯���ߡ�ƽ�⳵���ɼ�����BMS��CAN BOX������Ѫ���Ǻͼҵ���ư�Ȳ�Ʒ��
	BB_UIS8520,		//չ�� 5G ƽ̨, ��Smart, UIS8520 is a highly integrated baseband platform incorporating both modem and application processing subsystems to enable GSM/GPRS/EDGE/WCDMA/LTE/LTE-A/NR Modem applications. The chip integrates Quad Arm? Cortex?-A55 operating up to 2.0GHz.
	BB_FR303x,		//������ FR303x ϵ����˫ģ����MCU�����ø�����оƬ�Ĵ��¼���������Ƶ��������ARM CortexM3�ںˡ��ḻ��Ƭ����Դ�Լ�PMU������һ��оƬ�С�FR303x ����ROMʵ���������Ŀ��������ܣ���ȫ����SIG V5.3��BR/EDR/LEģʽ��Э�顣�û����Ի���оƬ���ɵ�MCU���ṩ��SDK��������Ӧ�÷�����
	BB_UIS7720,		//չ�� UNISOC 5G ƽ̨, ��Smart, UIS7720 is a high performance application processor with integrated 2G/3G/4G/5G modem. UIS7720 chipset presents a high performance-efficiency platform for 5G Modem devices. Ϊ����оƬƽ̨��
	BB_QCA8695AU,	//QCA8695AU is a monolithic single-chip that supports Bluetooth? 5.4. It is a standalone baseband processor system on chip (SoC) with an integrated 2.4 GHz transceiver. QCA8695AU is compliant with AEC-Q100 Qualification Specifications for Automotive Applications. �Ǹ�ͨ��BTƽ̨оƬ���Ǵ� QCA6595 ��ɾ����WiFi���ܣ�������BT�汾������ LE Audio ��������������ϵ�У�����Smartƽ̨��
	BB_RTL8761,		//RTL8761B ���� Realtek �͹�������5.0������оƬ. The Realtek RTL8761B is a highly integrated single-chip Bluetooth 5 controller with a UART(RTL8761BTV-VI-CG)/USB(RTL8761BUV-VI-CG) interface.
	BB_SYN43756E,	//��ͻ˼ WiFi ���� оƬ, The Synaptics(��ͻ˼) SYN43756E is a Tri-band (2.4 GHz, 5 GHz and 6 GHz, include UNII-5,UNII-6,UNII-7 and UNII-8) Wi-Fi 2��2 MAC/Baseband/Radio with integrated Bluetooth (BT) 5.3. The Synaptics SYN43756E single-chip device includes an integrated 2.4/5/6 GHz IEEE 802.11 a/b/g/n/ac/ax MAC/ baseband/radio. It also supports Bluetooth 5.3 and Bluetooth Low Energy (BLE).
	BB_QCC730,		//��ͨ WiFi оƬ, The QCC730 is a micropower Wi-Fi transceiver single package wireless local area network (WLAN) solution. It supports dual-band 1 �� 1 IEEE 802.11a/b/g/n WLAN standards.
	BB_ASR1901,		//ASR �� 5G оƬ, ���ڷ���ģ��, ��SMART����, ASR1901 is an advanced & highly integrated communication processor that specially designed for 5G mobile broadband and industrial IoT applications. It supports up to 4.6Gbps peak speed in both 5G non-standalone (NSA) & standalone (SA) mode and integrates with global qualified LTE/WCDMA/GSM modem to support all communication standards and abundant data applications.
	BB_nRF52832,	//Nordic MCU ������оƬ, nRF52832 ��һ��ͨ�õĶ�Э��SoC������������Ҫ�߼��͹�������?���ܡ�Э�鲢���Ժͷḻ��Χ�豸�͹��ܼ���Ӧ����ս�����⣬��Ϊ�����RAM�ṩ�˴����ڴ档nRF52832 ���þ�����ȫЭ�鲢�������Ķ�Э�顣��֧�ֵ͹�������������2 Mbps�ߴ����ٶȡ�
	BB_ASR8601,		//ASR �� 4G SMART ����оƬ, ASR8601 is a System on Chip (SoC) device which highly integrates both application processing subsystem, the baseband modem and cellular RF to enable 4G LTE multimedia smartphone applications. The application subsystem integrates quad-Core 64-bit processors ARM Cortex A55 operating up to 1.5 GHz.
	BB_QCM8538,		//��ͨ���� SMART 5G ����ƽ̨. The QCM8538 device is the Qualcomm? Snapdragon? automotive infotainment SoC designed with a 4 nm process, for superior performance and power efficiency. 3G/4G/5G modem �C sub-6 GHz bands (Rel 16 integrated modem). Qualcomm? FastConnect? 7800 System with WCN785x, 802.11be, 2 �� 2 MIMO, Bluetooth 5.3.
	BB_CQ8725S,		//CQ8725S �Ǹ�ͨ��WiFiоƬ��û�з��ѣ�����SMART���ܲ�Ʒƽ̨������ QCS6490��
	//
	BB_CHIP_COUNT
}EU_BB_CHIP_IDX;



//GSMƵ�����к�
typedef enum tagEU_GSM_BAND_IDX
{
	G_BAND_GSM900 = 0,
	G_BAND_DCS1800,
	G_BAND_PCS1900,
	G_BAND_GSM850,
	G_BAND_COUNT,		//GSMƵ������
	G_BAND_SIZE = 6		//GSMƵ����صĴ洢BUFF�ߴ磨���ߴ硱����ȡ����������ٴ�1, ���ڴ�Ž�������
}EU_GSM_BAND_IDX;

//WCDMAƵ�����к�
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
	W_BAND_COUNT,		//WCDMAƵ������
	W_BAND_SIZE = 16	//WCDMAƵ����صĴ洢BUFF�ߴ磨���ߴ硱����ȡ����������ٴ�1, ���ڴ�Ž�������
}EU_WCDMA_BAND_IDX;

//cdma2000Ƶ�����кţ��ϣ�
typedef enum tagEU_CDMA2K_BAND_IDX
{
	C2K_BAND_800 = 0,
	C2K_BAND_1900,
	C2K_BAND_COUNT,		//cdma2000Ƶ������
	C2K_BAND_SIZE = 3	//cdma2000Ƶ����صĴ洢BUFF�ߴ磨���ߴ硱����ȡ����������ٴ�1, ���ڴ�Ž�������
}EU_CDMA2K_BAND_IDX;

//cdma2000Ƶ�����кţ��£�
typedef enum tagEU_C2K_BAND_IDX
{
	C2K_BC_0 = 0,
	C2K_BC_COUNT,		//cdma2000Ƶ������
	C2K_BC_SIZE = 3		//cdma2000Ƶ����صĴ洢BUFF�ߴ磨���ߴ硱����ȡ����������ٴ�1, ���ڴ�Ž�������
}EU_C2K_BAND_IDX;

//LTEƵ�����к�
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
	L_BAND_29,			//LTE��B29��B32��ֻ��DL����FDD��ֻ����CA������
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
	L_BAND_32,			//LTE��B29��B32��ֻ��DL����FDD��ֻ����CA������
	L_BAND_87,
	L_BAND_88,
	L_BAND_15,			//ʵ��û�� LTE B15 Ƶ�Σ��˴�����Ϊ LTE B28B ����
	L_BAND_59,			//B59Ϊ����ר��Ƶ��, 1.8Gר��Ƶ��
	L_BAND_28A,			//LTE 28A ��Ӧ��Ƶ������Ϊ 2801
	L_BAND_28B,			//LTE 28B ��Ӧ��Ƶ������Ϊ 2802
	L_BAND_70,
	L_BAND_53,
	L_BAND_COUNT,		//LTEƵ������
	L_BAND_SIZE = 56	//LTEƵ����صĴ洢BUFF�ߴ磨���ߴ硱����ȡ����������ٴ�1, ���ڴ�Ž�������
}EU_LTE_BAND_IDX;

//TDƵ�����к�
typedef enum tagEU_TD_BAND_IDX
{
	TD_BAND_34 = 0,
	TD_BAND_39,
	TD_BAND_COUNT,		//TDƵ������
	TD_BAND_SIZE = 4	//TDƵ����صĴ洢BUFF�ߴ磨���ߴ硱����ȡ����������ٴ�1, ���ڴ�Ž�������
}EU_TD_BAND_IDX;

//NB-IoTƵ����
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

//NB-IoTƵ�����к�
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
	NB_IDX_B_COUNT,		//NB-IoTƵ������
	NB_IDX_B_SIZE = 46	//NB-IoTƵ����صĴ洢BUFF�ߴ磨���ߴ硱����ȡ����������ٴ�1, ���ڴ�Ž�������
}EU_NB_BAND_INDEX;

//C-V2XƵ�����к�
typedef enum tagEU_CV2X_BAND_IDX
{
	CV2X_BAND_46 = 0,
	CV2X_BAND_47,
	CV2X_BAND_COUNT,	//C-V2XƵ������
	CV2X_BAND_SIZE = 6	//C-V2XƵ����صĴ洢BUFF�ߴ磨���ߴ硱����ȡ����������ٴ�1, ���ڴ�Ž�������
}EU_CV2X_BAND_IDX;


//WiFiƵ��(FreqBand)���к�
typedef enum tagEU_WIFI_FB_IDX
{
	WIFI_FB_B24G = 0,	//2.4G
	WIFI_FB_B5G,		//5G
	WIFI_FB_B6G,		//6G
	WIFI_FB_COUNT
}EU_WIFI_FB_IDX;


//WiFi��׼(WiFi Standard)���к�
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


//�����汾���к�
typedef enum tagEU_BLU_VER_IDX
{
	BLU_VER_10_BR = 0,
	BLU_VER_20_EDR,
	BLU_VER_40_BLE,		//Bluetooth Low Energy
	BLU_VER_COUNT
}EU_BLU_VER_IDX;


//NR 5G SUB6 Ƶ�����к�
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
	NR5GSUB6_N_28A,			//NR 5G SUB6 28A ��Ӧ��Ƶ������Ϊ 2801
	NR5GSUB6_N_28B,			//NR 5G SUB6 28B ��Ӧ��Ƶ������Ϊ 2802
	NR5GSUB6_N_53,			//n53
	NR5GSUB6_N_39,			//n39
	NR5GSUB6_N_67,			//n67, RX ONLY
	NR5GSUB6_N_50,			//n50
	NR5GSUB6_N_COUNT,		//NR 5G SUB6 Ƶ������
	NR5GSUB6_N_SIZE = 49	//NR 5G SUB6 Ƶ����صĴ洢BUFF�ߴ磨���ߴ硱����ȡ����������ٴ�1, ���ڴ�Ž�������
}EU_NR5GSUB6_BAND_INDEX;


//NR 5G MMW ���ײ�Ƶ�����к�
typedef enum tagEU_NR5GMMW_BAND_INDEX
{
	NR5GMMW_N_257 = 0,
	NR5GMMW_N_258,
	NR5GMMW_N_260,
	NR5GMMW_N_261,
	NR5GMMW_N_COUNT,		//NR 5G MMW Ƶ������
	NR5GMMW_N_SIZE = 8		//NR 5G MMW Ƶ����صĴ洢BUFF�ߴ磨���ߴ硱����ȡ����������ٴ�1, ���ڴ�Ž�������
}EU_NR5GMMW_BAND_INDEX;


//NTN Ƶ�����к�( Index �� )
typedef enum tagEU_NTN_BAND_INDEX
{
	NTN_IDX_B_23 = 0,	//NTN B23 Index ��
	NTN_IDX_B_255,		//NTN B255 Index ��
	NTN_IDX_B_256,		//NTN B256 Index ��
	NTN_IDX_B_COUNT,	//NTN Ƶ������
	NTN_IDX_B_SIZE = 8	//NTN Ƶ����صĴ洢BUFF�ߴ磨���ߴ硱����ȡ����������ٴ�1, ���ڴ�Ž�������
}EU_NTN_BAND_INDEX;


//LoraƵ��(FreqBand)���
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
//�����������к�
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
	ANT_TYPE_IDX_COUNT,			//�������͵�������
	ANT_TYPE_IDX_SIZE = 44,		//��ÿ�����ߣ��������ߣ������Լ��Ĳ����洢BUFF���ĳߴ磨���ߴ硱����ȡ��������͵������������ٴ�1, ���ڴ�Ž�������
	ANT_TYPE_BUFF_SIZE = 16		//��ÿ������ӵ�е����ߣ��������ߣ��Ĳ����洢BUFF�����ߵĴ洢BUFF�ߴ磨���ߴ硱����ȡ�����ӵ�е��������������ٴ�1, ���ڴ�Ž�������
	//���ߵĴ洢BUFF�ߴ�ռ���ڴ�ռ���Դ̫�࣬�洢�������ݵ���ؽṹ��δ����û���Ҫ����Ϊ���������ߡ�������ʽ�洢��
}EU_ANT_TYPE_INDEX;


//ASR ƽ̨ RF Key Type
typedef enum tagEU_RF_KEY_TYPE_INDEX
{
	RF_KEY_TYPE_IDX_NDF = -1,
	RF_KEY_TYPE_IDX_PXA1802S_RF858 = 0,		//ASRƽ̨RF Type:"1802S+RF858"
	RF_KEY_TYPE_IDX_PAX1908_RF858,			//ASRƽ̨RF Type:"1802+RF858"
	RF_KEY_TYPE_IDX_RF866,					//ASRƽ̨RF Type:"1826+RF866"
	RF_KEY_TYPE_IDX_RF859C,					//ASRƽ̨RF Type:"1802S+RF859C"
	RF_KEY_TYPE_IDX_1601_3601,				//ASRƽ̨RF Type:"3601_1601"
	RF_KEY_TYPE_IDX_1603,					//ASRƽ̨RF Type:"1603"
	RF_KEY_TYPE_IDX_3603,					//ASRƽ̨RF Type:"3603"
	RF_KEY_TYPE_IDX_1803_FAICON,			//ASRƽ̨RF Type:"1803"
	RF_KEY_TYPE_IDX_1606,					//ASRƽ̨RF Type:"1606"
	RF_KEY_TYPE_IDX_1828_RF866,				//ASRƽ̨RF Type:"1828+RF866"
	RF_KEY_TYPE_IDX_1602,					//ASRƽ̨RF Type:"1602"
	RF_KEY_TYPE_IDX_1806,					//ASRƽ̨RF Type:"1806"
	RF_KEY_TYPE_IDX_1828_RF866S,			//ASRƽ̨RF Type:"1828+RF866S����1828+RF866����"
	RF_KEY_TYPE_IDX_1609,					//ASRƽ̨RF Type:"1609"
	RF_KEY_TYPE_IDX_1607,					//ASRƽ̨RF Type:"1607"����1609����
	RF_KEY_TYPE_IDX_1903,					//ASRƽ̨RF Type:"1903"
	RF_KEY_TYPE_IDX_1605,					//ASRƽ̨RF Type:"1605"����ʱ��1602���ã���ƽ̨���ֺ��ٸ���
	RF_KEY_TYPE_IDX_1901_RF869,				//ASRƽ̨RF Type:"1901+RF869"
	RF_KEY_TYPE_IDX_8601,					//ASRƽ̨RF Type:"8601"
	RF_KEY_TYPE_IDX_COUNT
}EU_RF_KEY_TYPE_INDEX;



//��������ʽ���淶
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



//�ߡ��С����ŵ���ʶ
#define CH_ALL					-1
#define CH_LOW					0
#define CH_MID					1
#define CH_HIGH					2
#define CH_LOW_EX				3
#define CH_LMH_COUNT			4



//�����ͺ�
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



//����δ���Ե�����ı�ʶ
#define ERROR_RTN_VALUE			9.91E9	//9.91E37



//�ṹ�塢�����ȳ�ʼ������ͳһֵ
#define DEFAULT_INIT_VALUE			-999.0	//�ṹ�塢�����ȳ�ʼ������ͳһֵ



//DUT��ANT���������������RF�ڽ��߷���
#define PLAN_ANT4_MAIN1_DIV1_GPS1_WIFI1			1//4��ANT����, ��1���� + 1�ּ� + 1GPS + 1WiFi������
#define PLAN_ANT4_MAIN2_DIV2					2//4��ANT����, ��2��MAIN������ + 2��DIV�ּ����ߡ�



//��ǰ���Ե�RFͨ·��RF��·��
#define RX_CHAIN_MAIN			1
#define RX_CHAIN_DIV			2
#define RX_CHAIN_GPS			3
#define RX_CHAIN_MAIN_DIV		4
//ͨ�õġ�unsigned char��BUFF
typedef struct tagPKT_BUFF_S
{
	unsigned char * ucp_Buff;
	unsigned long ul_Total_Size;
	unsigned long ul_Data_Length;
	//�ṹ��/���캯����ʼ��
	tagPKT_BUFF_S() : ucp_Buff( NULL ), ul_Total_Size( 0 ), ul_Data_Length( 0 )
	{
		//�������ʱ, ���û�и���������ֵ, �Ͷ���ֵ��0, ������ʵ�ʵ�ֵ����ֵ��
	}
}PKT_BUFF_S;



//������������
#define PROCESS_ATT_ERROR			-1//�޷�ʶ��Ĳ�����������
#define PROCESS_ATT_ALL_TEST		0//ȫ������
#define PROCESS_ATT_ONLY_LABEL		1//ֻ���ǩ
#define PROCESS_ATT_TO_DL			2//ֻ����DL
#define PROCESS_ATT_TO_BT			3//ֻ����BT
#define PROCESS_ATT_TO_FT			4//ֻ����FT
#define PROCESS_ATT_TO_FCT			5//ֻ����FCT



//��������ṹ�� V1��
typedef struct tagTESTER_RF_OFFSET_S
{
	double dr_GSM_RF_Loss[G_BAND_SIZE * 6];		//����ÿ��GSMƵ�εĵ͡��С����ŵ�������ֵ
	double dr_W_RF_Loss[W_BAND_SIZE * 2];		//����ÿ��WƵ�ε�index�Ŵ�����ֵ
	double dr_TD_RF_Loss[TD_BAND_SIZE * 2];		//����ÿ��TDƵ�ε�index�Ŵ�����ֵ
	double dr_C2K_RF_Loss[C2K_BC_SIZE * 2];		//����ÿ��cdma2000Ƶ�ε�index�Ŵ�����ֵ
	double dr_LTE_RF_Loss[L_BAND_SIZE * 2];		//����ÿ��LTEƵ�ε�index�Ŵ�����ֵ
	double dr_NBIoT_RF_Loss[NB_IDX_B_SIZE * 2];	//����ÿ��NB-IoTƵ�ε�index�Ŵ�����ֵ
}TESTER_RF_OFFSET_S;



//��������ṹ�� V2��
typedef struct tagTESTER_RF_OFFSET_V2_S
{
	double dr_GSM_RF_Loss[G_BAND_SIZE * 6];				//����ÿ��GSMƵ��index�ŵĵ͡��С����ŵ��������ֵ
	double dr_W_RF_Loss[W_BAND_SIZE * 6];				//����ÿ��WƵ�ε�index�ŵĵ͡��С����ŵ��������ֵ
	double dr_TD_RF_Loss[TD_BAND_SIZE * 6];				//����ÿ��TDƵ�ε�index�ŵĵ͡��С����ŵ��������ֵ
	double dr_C2K_RF_Loss[C2K_BC_SIZE * 6];				//����ÿ��cdma2000Ƶ�ε�index�ŵĵ͡��С����ŵ��������ֵ
	double dr_LTE_RF_Loss[L_BAND_SIZE * 6];				//����ÿ��LTEƵ�ε�index�ŵĵ͡��С����ŵ��������ֵ
	double dr_NBIoT_RF_Loss[NB_IDX_B_SIZE * 6];			//����ÿ��NB-IoTƵ�ε�index�ŵĵ͡��С����ŵ��������ֵ
	double dr_NR_5G_SUB6_RF_Loss[NR5GSUB6_N_SIZE * 6];	//5G NR SUB6 Ƶ�ε�index�ŵĵ͡��С����ŵ��������ֵ
	double dr_GPS_RF_Loss[2];							//GPS�� 1.57G һ��Ƶ��Ĵ������ֵ
	double dr_WiFi_RF_Loss[WIFI_FB_COUNT * 6];			//WiFi��2.4G��5GƵ��ĵ͡��С����ŵ��������ֵ
	double dr_BLU_RF_Loss[2];							//������ 2.4G һ��Ƶ��Ĵ������ֵ
	double dr_CV2X_RF_Loss[CV2X_BAND_SIZE * 6];			//����ÿ��CV2XƵ�ε�index�ŵĵ͡��С����ŵ��������ֵ
	double dr_LORA_RF_Loss[LORA_FB_COUNT * 6];			//LoraƵ��ĵ͡��С����ŵ��������ֵ
}TESTER_RF_OFFSET_V2_S;



//�������ò����ṹ��
typedef struct tagTESTER_CONFIG_S
{
	int i_GPIB_Card_Numb;		//����
	int i_GPIB_Card_Type;		//������
	int i_GPIB_Addr_Tester;		//������ַ
	int i_GPIB_Addr_PS;			//��Դ��ַ
	bool b_Ctrl_PS;				//�Ƿ�ص�Դ
	int i_Instru_Option;		//���������ͺ� �� ���Զ�ʶ������
	CStringW cs_IP_SN;			//��IP��SN��������
	int i_RF_Port_Numb;			//������ָ��RF�˿�, ���߽���ѡ������RF�˿ں�(һ��Ϊ��RF�˿�����������)
	TESTER_RF_OFFSET_S str_Instru_RF_Loss;	//������Ƶ������
}TESTER_CONFIG_S;



//����̨���ò���
typedef struct tagTS_CONFIG_S
{
	int i_Com_Port;				//DM ͨ�ſڣ�ͨ�ÿڣ�
	int i_Com_AT_Port;			//AT ͨ�ſ�
	int i_BR;					//������
	int i_TS_Curr_Type_Option;	//��ǰ����(ѡ��)�ġ����Թ�λ���ࡢ��ʽ(����:GSM��WCDMA��2G+3G��2G+3G+4G��ѡ��)��
	bool b_Debug_Log_File;		//���� debug log �ļ�
}TS_CONFIG_S;
//MOB��Ʒ���Ʋ���̨���ò���
typedef struct tagTS_CONFIG_MOB_S
{
	int i_Com_Port;				//DM ͨ�ſڣ�ͨ�ÿڣ�
	int i_Com_AT_Port;			//AT ͨ�ſ�
	int i_Com_MCU_Port;			//MCU ͨ�ſ�
	int i_Com_DBG_Port;			//DBG ͨ�ſ�
	int i_BR;					//������
	int i_TS_Curr_Type_Option;	//��ǰ����(ѡ��)�ġ����Թ�λ���ࡢ��ʽ(����:GSM��WCDMA��2G+3G��2G+3G+4G��ѡ��)��
	bool b_Debug_Log_File;		//���� debug log �ļ�
	CString cs_BT_MAC;			//�㲥��������ַ���ӽ�������
	double d_GPS_Loss;          //GPS LOSS
}TS_CONFIG_MOB_S;



//Ƶ�����ò���
typedef struct tagBAND_CONFIG_S
{
	int i_Band_Name;			//Ƶ������2Gʹ��index�ţ�,��-1����������
	int i_Tx_Quan;				//Ƶ�ε�TX����
	int ir_Rx_For_Tx_Quan[8];	//Ƶ��ÿ��TX��Ӧ��RX����
}BAND_CONFIG_S;



//Ƶ�νṹ�� V1��
typedef struct tagBAND_LIST_S
{
	int ir_GSM_Band_List[G_BAND_SIZE];		//GSM��Ƶ��indexֵ���б���-1���������
	int ir_WCDMA_Band_List[W_BAND_SIZE];	//WCDMA��Ƶ��ֵ���б���-1���������
	int ir_C2K_Band_List[C2K_BC_SIZE];		//cdma2000��Ƶ��ֵ���б���-1���������
	int ir_TD_Band_List[TD_BAND_SIZE];		//TD��Ƶ��ֵ���б���-1���������
	int ir_LTE_Band_List[L_BAND_SIZE];		//LTE��Ƶ��ֵ���б���-1���������
	int ir_NBIoT_Band_List[NB_IDX_B_SIZE];	//NB-IoT��Ƶ��ֵ���б���-1���������
	int i_GSM_Band_Quan;	//GSM��Ƶ�Ρ�����
	int i_WCDMA_Band_Quan;	//WCDMA��Ƶ�Ρ�����
	int i_C2K_Band_Quan;	//cdma2000��Ƶ�Ρ�����
	int i_TD_Band_Quan;		//TD��Ƶ�Ρ�����
	int i_LTE_Band_Quan;	//LTE��Ƶ�Ρ�����
	int i_NBIoT_Band_Quan;	//NB-IoT��Ƶ�Ρ�����
}BAND_LIST_S;



//�������߶�Ӧ��Ƶ�νṹ�� V2��
typedef struct tagBAND_LIST_V2_S
{
	int ir_GSM_Band_List[G_BAND_SIZE];				//GSM��Ƶ��indexֵ���б���-1���������
	int ir_WCDMA_Band_List[W_BAND_SIZE];			//WCDMA��Ƶ��ֵ���б���-1���������
	int ir_C2K_Band_List[C2K_BC_SIZE];				//cdma2000��Ƶ��ֵ���б���-1���������
	int ir_TD_Band_List[TD_BAND_SIZE];				//TD��Ƶ��ֵ���б���-1���������
	int ir_LTE_Band_List[L_BAND_SIZE];				//LTE��Ƶ��ֵ���б���-1���������
	int ir_NBIoT_Band_List[NB_IDX_B_SIZE];			//NB-IoT��Ƶ��ֵ���б���-1���������
	int ir_NR_5G_SUB6_Band_List[NR5GSUB6_N_SIZE];	//NR 5G SUB6 ��Ƶ��ֵ���б���-1���������
	int ir_CV2X_Band_List[CV2X_BAND_SIZE];			//C-V2X��Ƶ��ֵ���б���-1���������
	int i_GSM_Band_Quan;		//GSM��Ƶ�Ρ�����
	int i_WCDMA_Band_Quan;		//WCDMA��Ƶ�Ρ�����
	int i_C2K_Band_Quan;		//cdma2000��Ƶ�Ρ�����
	int i_TD_Band_Quan;			//TD��Ƶ�Ρ�����
	int i_LTE_Band_Quan;		//LTE��Ƶ�Ρ�����
	int i_NBIoT_Band_Quan;		//NB-IoT��Ƶ�Ρ�����
	int i_NR_5G_SUB6_Band_Quan;	//NR 5G SUB6 ��Ƶ�Ρ�����
	int i_CV2X_Band_Quan;		//C-V2X��Ƶ�Ρ�����
	BAND_CONFIG_S strr_GSM_Band_CFG[G_BAND_SIZE];				//2G ��Ƶ�����ò�����
	BAND_CONFIG_S strr_WCDMA_Band_CFG[W_BAND_SIZE];				//WCDMA ��Ƶ�����ò�����
	BAND_CONFIG_S strr_LTE_Band_CFG[L_BAND_SIZE];				//LTE ��Ƶ�����ò�����
	BAND_CONFIG_S strr_NR_5G_SUB6_Band_CFG[NR5GSUB6_N_SIZE];	//NR 5G SUB6 ��Ƶ�����ò�����
}BAND_LIST_V2_S;



//DUT���������������Խṹ��
typedef struct tagANT_PROP_S
{
	EU_ANT_TYPE_INDEX eu_ANT_HW_Type_Name;	//Ӳ��ʵ�����ߣ����ͣ���,��-1������������
	int i_ANT_SW_Numb;						//��ͨ�����������ߺţ�0~7��, �޴˺������趨Ϊ��-1��
}ANT_PROP_S;


//�����б�ṹ��
typedef struct tagANT_LIST_S
{
	ANT_PROP_S strr_ANT_Prop_List[ANT_TYPE_BUFF_SIZE];			//DUT�����ߣ����ԡ�Index�ţ��б�������Index���б����У��ԡ�-1����β��
	int i_ANT_Quan;												//DUT����������
}ANT_LIST_S;


//DUT�������������ṹ�� V1 ��
typedef struct tagANT_CFG_ALL_S
{
	ANT_LIST_S str_ANT_List;									//DUT���������ߣ����ԡ�Index�ţ��б�
	TESTER_RF_OFFSET_V2_S strr_ANT_RF_Loss[ANT_TYPE_IDX_SIZE];	//���ߵ�����Ƶ�Ρ����𡱣��ԡ�����Index�š���Ϊ�ṹ������Buff�Ĵ洢������index�ţ�
}ANT_CFG_ALL_S;


//DUT�������������ṹ�� V2 ��
typedef struct tagANT_CFG_ALL_V2_S
{
	ANT_LIST_S str_ANT_List;											//DUT���������ߣ����ԡ�Index�ţ��б�
	TESTER_RF_OFFSET_V2_S strr_ANT_RF_Loss_List[ANT_TYPE_BUFF_SIZE];	//DUT�����ߵ�����Ƶ�Ρ����𡱣��ԡ�str_ANT_List���еġ�����Index�ŵ�����˳����Ϊ�ṹ������Buff�ġ��洢˳�򡱣����ٴ洢�ò��������ߣ�
}ANT_CFG_ALL_V2_S;


//�������ߡ�����Ƶ�εĽ����и��ŵ�����
typedef struct tagREF_DATA_BASIC_S
{
	int i_Band_Name_And_Enable;										//Band�� �� Bandʹ�ܱ�ʶ
	double dr_Tx_Power[CH_LMH_COUNT];								//TX��幦������
	double dr_Rx_Level[CH_LMH_COUNT];								//RX�����յ�ƽ����
}REF_DATA_BASIC_S;


//�������ߡ�����Ƶ�εĽ������
typedef struct tagREF_DATA_BAND_S
{
	REF_DATA_BASIC_S strr_GSM_REF_Data[G_BAND_SIZE];				//2G ����Ƶ�εĽ�����ݣ���Ƶ��index�Ŵ洢�������������洢��
	REF_DATA_BASIC_S strr_WCDMA_REF_Data[W_BAND_SIZE];				//WCDMA ����Ƶ�εĽ�����ݣ���Ƶ��index�Ŵ洢�������������洢��
	REF_DATA_BASIC_S strr_C2K_REF_Data[C2K_BC_SIZE];				//cdma2000 ����Ƶ�εĽ�����ݣ���Ƶ��index�Ŵ洢�������������洢��
	REF_DATA_BASIC_S strr_TD_REF_Data[TD_BAND_SIZE];				//TD ����Ƶ�εĽ�����ݣ���Ƶ��index�Ŵ洢�������������洢��
	REF_DATA_BASIC_S strr_LTE_REF_Data[L_BAND_SIZE];				//LTE ����Ƶ�εĽ�����ݣ���Ƶ��index�Ŵ洢�������������洢��
	REF_DATA_BASIC_S strr_NBIoT_REF_Data[NB_IDX_B_SIZE];			//NB-IoT ����Ƶ�εĽ�����ݣ���Ƶ��index�Ŵ洢�������������洢��
	REF_DATA_BASIC_S strr_NR_5G_SUB6_REF_Data[NR5GSUB6_N_SIZE];		//NR 5G SUB6 ����Ƶ�εĽ�����ݣ���Ƶ��index�Ŵ洢�������������洢��
	REF_DATA_BASIC_S strr_CV2X_REF_Data[CV2X_BAND_SIZE];			//C-V2X ����Ƶ�εĽ�����ݣ���Ƶ��index�Ŵ洢�������������洢��
	REF_DATA_BASIC_S str_GPS_REF_Data;								//GPS�Ľ�����ݣ���Ƶ��index�Ŵ洢�������������洢��
	REF_DATA_BASIC_S strr_WiFi_REF_Data[WIFI_FB_COUNT];				//WiFi��2.4G��5G�Ľ�����ݣ���Ƶ��index�Ŵ洢�������������洢��
	REF_DATA_BASIC_S str_Bluetooth_REF_Data;						//�����Ľ�����ݣ���Ƶ��index�Ŵ洢�������������洢��
	REF_DATA_BASIC_S strr_Lora_REF_Data[LORA_FB_COUNT];				//Lora�Ľ�����ݣ���Ƶ��index�Ŵ洢�������������洢��
}REF_DATA_BAND_S;


//�������ߡ�����Ƶ�εĽ������ V1 ��
typedef struct tagREF_DATA_ALL_S
{
	ANT_LIST_S str_Ref_ANT_List;									//���������У׼�漰�����ߣ����ԡ�Index�ţ��б�
	REF_DATA_BAND_S strr_Ref_Band_Data[ANT_TYPE_IDX_SIZE];			//���ߵ�����Ƶ�Ρ�������ݡ����ԡ�����Index�š���Ϊ�ṹ������Buff�Ĵ洢������index�ţ�
}REF_DATA_ALL_S;


//�������ߡ�����Ƶ�εĽ������ V2 ��
typedef struct tagREF_DATA_ALL_V2_S
{
	ANT_LIST_S str_Ref_Ant_List;									//���DUT�������������ߣ����ԡ�Index�ţ��б�
	REF_DATA_BAND_S strr_Ref_Data_List[ANT_TYPE_BUFF_SIZE];			//���DUT�������������ߵ�����Ƶ�Ρ�������ݡ����ԡ�str_Ref_Ant_List���еġ�����Index�ŵ�����˳����Ϊ�ṹ������Buff�ġ��洢˳�򡱣����ٴ洢�ò��������ߣ�
}REF_DATA_ALL_V2_S;


//Ƶ��ʹ�ܿ���
typedef struct tagBAND_ENABLE_S
{
	int ir_GSM_Band_Enable[G_BAND_SIZE];				//GSM ʹ���б���0���¡���������
	int ir_WCDMA_Band_Enable[W_BAND_SIZE];				//WCDMA ʹ���б���0���¡���������
	int ir_C2K_Band_Enable[C2K_BC_SIZE];				//cdma2000 ʹ���б���0���¡���������
	int ir_TD_Band_Enable[TD_BAND_SIZE];				//TD ʹ���б���0���¡���������
	int ir_LTE_Band_Enable[L_BAND_SIZE];				//LTE ʹ���б���0���¡���������
	int ir_NBIoT_Band_Enable[NB_IDX_B_SIZE];			//NB-IoT ʹ���б���0���¡���������
	int ir_NR_5G_SUB6_Band_Enable[NR5GSUB6_N_SIZE];		//NR 5G SUB6 ʹ���б���0���¡���������
	int ir_CV2X_Band_Enable[CV2X_BAND_SIZE];			//C-V2X ʹ���б���0���¡���������
}BAND_ENABLE_S;



//���͡�ͨ�ò���������exe��������ƥ�䣩
typedef struct tagPRODU_PARAMS_GEN_S
{
	CString cs_Produ_Name;			//������
	int i_Platform_Solution;		//ƽ̨����
	int i_BB_Chip;					//BBоƬ�ͺ�
	int ir_TS_Type_Seq[10];			//���Թ�λ(Flag���)�б�, ���������б�
	BAND_LIST_V2_S str_Band_List;	//���͵�����Ƶ������
	CString cs_Produ_Params_File;	//�����ļ�·��
}PRODU_PARAMS_GEN_S;



//��������¼�ṹ��
typedef struct tagCABLE_LOSS_SET_S
{
	CString cs_BandName;//GSM_900��W Band1��T Band39��L Band1...
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



//��Ʒ����
#define PRODU_TYPE_NDF				0
#define PRODU_TYPE_PCBA				1
#define PRODU_TYPE_MINIPCIE			2
#define PRODU_TYPE_TE_A				3
#define PRODU_TYPE_TE_C				4
#define PRODU_TYPE_TE_B				5
#define PRODU_TYPE_KIT				6
#define PRODU_TYPE_MOB				7//Module On Board
#define PRODU_TYPE_COB				8//Chip On Board
#define PRODU_TYPE_ASM				9//Assembly ������ʹ���Զ������̣�



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
	LTE_CAT_NDF = -1,	//δ����
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
//������ȡ�ӿ�
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
//�ⲿ�������
typedef void( __stdcall * CALLBACK_EXT_PS_POWER_ON )(void * p_usr_Arg);
typedef void( __stdcall * CALLBACK_EXT_PS_POWER_OFF )(void * p_usr_Arg);
//callback �ṹ�� V2 ��������׷�ӵ�ocp�����ӿ�
typedef bool( __stdcall * CALLBACK_READ_PRODU_PS_CH2_VOLT_AND_CURR )(double * dp_Voltage_CH2, double * dp_Current_CH2, void * p_usr_Arg);
typedef bool( __stdcall * CALLBACK_READ_PRODU_NETWORK_FORMAT_BAND_LIST )(int i_Network_Format, int * ip_Band_List, int * ip_Band_Quan, void * p_usr_Arg);
//callback �ṹ�� V3 ��������׷�ӵ�ocp�����ӿ�
typedef bool( __stdcall * CALLBACK_READ_PRODU_NETWORK_FORMAT_BAND_ANT_LIST )(int i_Network_Format, int i_Rx_Chain_Type, int * ip_Band_ANT_List, int * ip_Band_ANT_Quan, void * p_usr_Arg);
typedef bool( __stdcall * CALLBACK_READ_PRODU_ANT_LIST )(ANT_PROP_S * strp_ANT_Prop_List, int * ip_ANT_Quan, void * p_usr_Arg);
//callback �ṹ�� sql_db �����ӿ�
typedef bool( __stdcall * CALLBACK_FIND_READ_REF_STD_2017_CONN_V1 )(const wchar_t * wcp_Key_IMEI, CString & oj_cs_Ref_Produ_Name, CString & oj_cs_Ref_Data_Str, CString & oj_Ref_OC, CString & oj_Ref_Make_Date, CString & oj_cs_Err_Info, void * p_usr_Arg);
//callback �ṹ�� Open-Short���ʹ�����л�OS����õ��Ķ�exe����Ļص��������� �����ӿ�
typedef bool( __stdcall * CALLBACK_REF_OS_SWITCH_OPEN )(CString & oj_cs_Barcode_Of_Open, void * p_usr_Arg);
typedef bool( __stdcall * CALLBACK_REF_OS_SWITCH_SHORT )(CString & oj_cs_Barcode_Of_Short, void * p_usr_Arg);




//��������ʾ callback �ṹ��
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



//��ȡ������OCP������ callback �ṹ�� V1
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



//��ȡ������OCP������ callback �ṹ�� V2 ��������׷�ӵ�ocp�����ӿڣ�
typedef struct tagREAD_OCP_PARAMS_V2_ARG
{
	//read ocp params callback
	void *												p_usr_Arguments;
	//
	CALLBACK_READ_PRODU_PS_CH2_VOLT_AND_CURR			cb_Read_Produ_PS_CH2_Volt_And_Curr;
	CALLBACK_READ_PRODU_NETWORK_FORMAT_BAND_LIST		cb_Read_Produ_Network_Format_Band_List;
}READ_OCP_PARAMS_V2_ARG;



//��ȡ������OCP������ callback �ṹ�� V3 ��������׷�ӵ�ocp�����ӿڣ�
typedef struct tagREAD_OCP_PARAMS_V3_ARG
{
	//read ocp params callback
	void *												p_usr_Arguments;
	//
	CALLBACK_READ_PRODU_NETWORK_FORMAT_BAND_ANT_LIST	cb_Read_Produ_Network_Format_Band_ANT_List;
	CALLBACK_READ_PRODU_ANT_LIST						cb_Read_Produ_ANT_List;
}READ_OCP_PARAMS_V3_ARG;
//�����������ݴ��� callback �ṹ��
typedef struct tagCTU_PROG_ARG
{
	//ctu(��������) progress callback
	void *							p_usr_Arguments;
	CALLBACK_SHOW_REDIT_INFO		cb_Show_REdit_Info;
	CALLBACK_SHOW_PLC_REG_DATA		cb_Show_PLC_Reg_Data;
	CALLBACK_SEND_PLC_TRAY_DATA		cb_Send_PLC_Tray_Data;
	CALLBACK_UPDATE_TS_STATUS		cb_Update_TS_Status;
	CALLBACK_UPDATE_TS_PFQUAN		cb_Update_TS_PFQuan;
	CALLBACK_UPDATE_TS_TRD			cb_Update_TS_TRD;
}CTU_PROG_ARG;



//�ⲿ����Ŀ��� callback �ṹ��
typedef struct tagEXT_PS_ARG
{
	//�ⲿ����Ŀ��ƻص��ӿ�
	void *							p_usr_Arguments;
	CALLBACK_EXT_PS_POWER_ON		cb_Ext_PS_Power_On;
	CALLBACK_EXT_PS_POWER_OFF		cb_Ext_PS_Power_Off;
}EXT_PS_ARG;
//���� sql_db ������ callback �ṹ�� V1
typedef struct tagOP_SQL_DB_V1_ARG
{
	//sql_db ������ callback
	void *										p_usr_Arguments;
	//
	CALLBACK_FIND_READ_REF_STD_2017_CONN_V1		cb_Find_Read_REF_STD_2017_CONN_V1;
}OP_SQL_DB_V1_ARG;



//Open-Short���ʹ�����л�OS����õ��Ķ�exe����Ļص���������
typedef struct tagOP_REF_OS_SWITCH_V1_ARG
{
	//REF_OS ��exe����Ļص���������� callback
	void *								p_usr_Arguments;
	//
	CALLBACK_REF_OS_SWITCH_OPEN			cb_Ref_Os_Switch_Open;	//�л�Open���
	CALLBACK_REF_OS_SWITCH_SHORT		cb_Ref_Os_Switch_Short;	//�л�Short���
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
