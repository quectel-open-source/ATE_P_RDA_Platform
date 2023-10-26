//错误代码
//FT:05
//仪器设备部分(01)
#define ERR_FT_PS_INIT	                        0x22010101
#define ERR_FT_PS_POWER_OFF						0x22010102


//COM通信部分(02)
#define ERR_FT_DISABLE_MBIM_FAIL                0x22020101
#define ERR_FT_DETECT_ALL_COM_PORT              0x22020201
#define ERR_FT_OPEN_AT_PORT                     0x22020301
#define ERR_FT_READ_FW_VER                      0x22020401
#define ERR_FT_CHECK_ADC_VOLT                   0x22020501
#define ERR_FT_READ_SN							0x22020502
#define ERR_FT_CHECK_SN_LENGHT					0x22020503


//QLIB通信部分
#define ERR_FT_QLIB_INIT                        0x22020601
#define ERR_FT_SWITCH_FTM_MODE                  0x22020602
#define ERR_FT_CHECK_FLAG                       0x22020603
#define ERR_FT_GSM_RELEASE_TCH                  0x22020604
#define ERR_FT_STOP_GSM_SESSION                 0x22020605
#define ERR_FT_STOP_WCDMA_SESSION               0x22020606
#define ERR_FT_STOP_C2K_NS                      0x22020607
#define ERR_FT_C2K_CMD_RELEASE                  0x22020608
#define ERR_FT_TD_BER_DROP_ALL                  0x22020609
#define ERR_FT_STOP_TD_SESSION                  0x2202060A
#define ERR_FT_ENTER_LTE_MODE                   0x2202060B
#define ERR_FT_END_LTE_MODE                     0x2202060C
#define ERR_FT_ENTER_GPS_MODE                   0x2202060D
#define ERR_FT_EXIT_GPS_MODE                    0x2202060E
#define ERR_FT_MEASURE_GPS                      0x2202060F
#define ERR_FT_SWITCH_LTE_RX_CHAIN              0x22020610

//电流相关(03)
#define ERR_FT_TEST_CURRENT                     0x22030101

//RF相关(04)
//呼叫(01)
#define ERR_FT_START_CALL_GSM                   0x22040101
#define ERR_FT_START_CALL_WCDMA                 0x22040102
#define ERR_FT_START_CALL_CDMA2000              0x22040103
#define ERR_FT_START_CALL_TDSCDMA               0x22040104
#define ERR_FT_START_CALL_LTE                   0x22040105
#define ERR_FT_START_CALL_LTE_CAT_M             0x22040106

//Handover(02)
#define ERR_FT_HANDOVER_NS_GSM                  0x22040201
#define ERR_FT_HANDOVER_NS_WCDMA                0x22040202
#define ERR_FT_HANDOVER_NS_CDMA2000             0x22040203
#define ERR_FT_HANDOVER_NS_TDSCDMA              0x22040204
#define ERR_FT_HANDOVER_NS_LTE                  0x22040205
#define ERR_FT_HANDOVER_NS_LTE_CAT_M            0x22040206
//GSM900的RF(03)
#define ERR_FT_2G_NDF                           0x22040300
#define ERR_FT_GSM900_TX_POWER                  0x22040301
#define ERR_FT_GSM900_TX_PVT                    0x22040302
#define ERR_FT_GSM900_FREQ_ERR                  0x22040303
#define ERR_FT_GSM900_PHASE_ERR_RMS             0x22040304
#define ERR_FT_GSM900_PHASE_ERR_PEAK            0x22040305
#define ERR_FT_GSM900_SPEC_SWITCH               0x22040306
#define ERR_FT_GSM900_SPEC_MOD                  0x22040307
#define ERR_FT_GSM900_RX_LEVEL                  0x22040308
#define ERR_FT_GSM900_RX_QUALITY                0x22040309
#define ERR_FT_GSM900_RX_BER                    0x2204030A
//DCS1800的RF(04)
#define ERR_FT_DCS_TX_POWER                     0x22040401
#define ERR_FT_DCS_TX_PVT                       0x22040402
#define ERR_FT_DCS_FREQ_ERR                     0x22040403
#define ERR_FT_DCS_PHASE_ERR_RMS                0x22040404
#define ERR_FT_DCS_PHASE_ERR_PEAK               0x22040405
#define ERR_FT_DCS_SPEC_SWITCH                  0x22040406
#define ERR_FT_DCS_SPEC_MOD                     0x22040407
#define ERR_FT_DCS_RX_LEVEL                     0x22040408
#define ERR_FT_DCS_RX_QUALITY                   0x22040409
#define ERR_FT_DCS_RX_BER                       0x2204040A
//PCS1900的RF(05)
#define ERR_FT_PCS_TX_POWER                     0x22040501
#define ERR_FT_PCS_TX_PVT                       0x22040502
#define ERR_FT_PCS_FREQ_ERR                     0x22040503
#define ERR_FT_PCS_PHASE_ERR_RMS                0x22040504
#define ERR_FT_PCS_PHASE_ERR_PEAK               0x22040505
#define ERR_FT_PCS_SPEC_SWITCH                  0x22040506
#define ERR_FT_PCS_SPEC_MOD                     0x22040507
#define ERR_FT_PCS_RX_LEVEL                     0x22040508
#define ERR_FT_PCS_RX_QUALITY                   0x22040509
#define ERR_FT_PCS_RX_BER                       0x2204050A
//GSM850的RF(06)
#define ERR_FT_GSM850_TX_POWER                  0x22040601
#define ERR_FT_GSM850_TX_PVT                    0x22040602
#define ERR_FT_GSM850_FREQ_ERR                  0x22040603
#define ERR_FT_GSM850_PHASE_ERR_RMS             0x22040604
#define ERR_FT_GSM850_PHASE_ERR_PEAK            0x22040605
#define ERR_FT_GSM850_SPEC_SWITCH               0x22040606
#define ERR_FT_GSM850_SPEC_MOD                  0x22040607
#define ERR_FT_GSM850_RX_LEVEL                  0x22040608
#define ERR_FT_GSM850_RX_QUALITY                0x22040609
#define ERR_FT_GSM850_RX_BER                    0x2204060A
//WCDMA的RF(07)
#define ERR_FT_WCDMA_TX_MAX_POWER               0x22040701
#define ERR_FT_WCDMA_TX_MIN_POWER               0x22040702
#define ERR_FT_WCDMA_SEM                        0x22040703
#define ERR_FT_WCDMA_EVM_RMS                    0x22040704
#define ERR_FT_WCDMA_FREQ_ERR                   0x22040705
#define ERR_FT_WCDMA_PCDE                       0x22040706
#define ERR_FT_WCDMA_OBW                        0x22040707
#define ERR_FT_WCDMA_ACLR_N10MHZ                0x22040708
#define ERR_FT_WCDMA_ACLR_N5MHZ                 0x22040709
#define ERR_FT_WCDMA_ACLR_P5MHZ                 0x2204070A
#define ERR_FT_WCDMA_ACLR_P10MHZ                0x2204070B
#define ERR_FT_WCDMA_ILPC_E_MAX                 0x2204070C
#define ERR_FT_WCDMA_ILPC_E_MIN                 0x2204070D
#define ERR_FT_WCDMA_ILPC_F_MAX                 0x2204070E
#define ERR_FT_WCDMA_ILPC_F_MIN                 0x2204070F
#define ERR_FT_WCDMA_RX_BER                     0x22040710
#define ERR_FT_WCDMA_RX_LEVEL_DIV               0x22040711
//cdma2000的RF(08)
#define ERR_FT_C2K_TX_MAX_POWER                 0x22040801
#define ERR_FT_C2K_TX_MIN_POWER                 0x22040802
#define ERR_FT_C2K_FREQ_ERR                     0x22040803
#define ERR_FT_C2K_TIME_ERR                     0x22040804
#define ERR_FT_C2K_IQ_OFFSET                    0x22040805
#define ERR_FT_C2K_PHASE_ERR_RMS                0x22040806
#define ERR_FT_C2K_EVM_RMS                      0x22040807
#define ERR_FT_C2K_ACPR_ADJ_L                   0x22040808
#define ERR_FT_C2K_ACPR_ADJ_H                   0x22040809
#define ERR_FT_C2K_ACPR_ALT_L                   0x2204080A
#define ERR_FT_C2K_ACPR_ALT_H                   0x2204080B
#define ERR_FT_C2K_RX_RSP_FER                   0x2204080C
#define ERR_FT_C2K_RX_RSP_SER                   0x2204080D
//TD-SCDMA的RF(09)
#define ERR_FT_TD_TX_MAX_POWER                  0x22040901
#define ERR_FT_TD_TX_MIN_POWER                  0x22040902
#define ERR_FT_TD_FREQ_ERR                      0x22040903
#define ERR_FT_TD_PHASE_ERR                     0x22040904
#define ERR_FT_TD_IQ_OFFSET                     0x22040905
#define ERR_FT_TD_OBW                           0x22040906
#define ERR_FT_TD_EVM                           0x22040907
#define ERR_FT_TD_PCDE                          0x22040908
#define ERR_FT_TD_SEM                           0x22040909
#define ERR_FT_TD_ACLR_L2                       0x2204090A
#define ERR_FT_TD_ACLR_L1                       0x2204090B
#define ERR_FT_TD_ACLR_R1                       0x2204090C
#define ERR_FT_TD_ACLR_R2                       0x2204090D
#define ERR_FT_TD_RX_BER                        0x2204090E
//LTE的RF(0A)
#define ERR_FT_LTE_TX_POWER                     0x22040A01
#define ERR_FT_LTE_OBW                          0x22040A02
#define ERR_FT_LTE_SEM                          0x22040A03
#define ERR_FT_LTE_ACLR_N2                      0x22040A04
#define ERR_FT_LTE_ACLR_N1                      0x22040A05
#define ERR_FT_LTE_ACLR_EN1                     0x22040A06
#define ERR_FT_LTE_ACLR_EP1                     0x22040A07
#define ERR_FT_LTE_ACLR_P1                      0x22040A08
#define ERR_FT_LTE_ACLR_P2                      0x22040A09
#define ERR_FT_LTE_IQ_OO                        0x22040A0A
#define ERR_FT_LTE_FREQ_ERR                     0x22040A0B
#define ERR_FT_LTE_EVM_AVG                      0x22040A0C
#define ERR_FT_LTE_EVM_MAX                      0x22040A0D
#define ERR_FT_LTE_MARGIN                       0x22040A0E
#define ERR_FT_LTE_RX_BLER                      0x22040A0F
#define ERR_FT_LTE_RX_BLER_DIV                  0x22040A10
#define ERR_FT_LTE_RX_BLER_MAIN_DIV             0x22040A11
#define ERR_FT_LTE_RX_LEVEL_DIV                 0x22040A12

//GPS的RF(0B)
#define ERR_FT_GPS_CNO                          0x22040B01
#define ERR_FT_GPS_FREQ_OFFSET                  0x22040B02
#define ERR_FT_GPS_Test_Enable                  0x22040B03
#define ERR_FT_GPS_Test_Instrument_Init         0x22040B04
#define ERR_FT_GPS_GET_SNR						0x22040B05

//蓝牙的RF(0C)
#define ERR_FT_BTLE_Power                       0x22040C00
#define ERR_FT_BTLE_Freq_Drift99                0x22040C01
#define ERR_FT_BTLE_Ber							0x22040C02
#define ERR_FT_BTLE_Max_Drift_Rate				0x22040C03
#define ERR_FT_BTLE_Freq_Offset					0x22040C04
#define ERR_FT_BTLE_Initial_Freq_Drift			0x22040C05
#define ERR_FT_BTLE_Device_Open                 0x22040C06
#define ERR_FT_BTLE_Device_Reset                0x22040C07
#define ERR_FT_BTLE_Instrument_Init             0x22040C08
#define ERR_FT_BTLE_Set_Tx_Model                0x22040C09
#define ERR_FT_BTLE_Tx_Measure                  0x22040C0A
#define ERR_FT_BTLE_Test_End                    0x22040C0B
#define ERR_FT_BTLE_Set_Rx_Model                0x22040C0C

//NB的RF(0C)
#define ERR_NB_Ber								0x22040C00
#define ERR_NB_MaxPower							0x22040C01
#define ERR_NB_ACLR								0x22040C02
#define ERR_NB_EVM								0x22040C03
#define ERR_NB_FreqErr							0x22040C04
#define ERR_NB_OBW								0x22040C05
#define ERR_NB_SEM								0x22040C06
#define ERR_NB_MinPower							0x22040C07

#define ERR_NB_Band1							0x00000000
#define ERR_NB_Band3							0x00000010
#define ERR_NB_Band5							0x00000020
#define ERR_NB_Band8							0x00000030
#define ERR_NB_Band20							0x00000040
#define ERR_NB_Band28							0x00000050
//RDA测试公共部分

#define ERR_PS_INIT_CHECK						0x22050000
#define ERR_PS_POWER_ON_CHECK					0x22050001
#define ERR_RF_INIT_TESTER_FAIL					0x22050002
#define ERR_RF_DEVICE_CONNECT					0x22050003
#define ERR_RF_DEVICE_DETECT					0x22050004
#define ERR_RF_OPEN_RF_INSTRUMENT				0x22050005
#define ERR_Open_Log_File						0x22050006
#define ERR_RDA_Load_Setting					0x22050007
#define ERR_Close_Log_File						0x22050008
#define ERR_Open_Log_File_1						0x22050009

#define ERR_RDA_OPEN_PORT						0x22050011
#define ERR_RDA_ChipRestart						0x22050012
#define ERR_Check_Band_Select					0x22050013
#define ERR_Check_PowerOn_Curr					0x22050014
#define ERR_Check_Work_Curr						0x22050015
#define ERR_LOAD_RUN_PATH						0x22050016


#define ERR_GET_FLAG							0x22050030
#define ERR_WRITE_SN_FLAG						0x22050031
#define ERR_READ_SN_FLAG						0x22050032
#define ERR_CHECK_SN_FLAG						0x22050033
#define ERR_Open_ATCOM							0x22050034
#define ERR_Check_ATCommand						0x22050035
#define ERR_IMEI_Number_Check					0x22050036
#define ERR_Check_Quectel_Flag					0x22050037

//2G BT/FT 公共部分
#define ERR_RDA_2G_Reopen_Comport				0x22050020
#define ERR_RDA_2G_INIT_CALIB_OBJ				0x22050021
#define ERR_RDA_2G_Check_Open					0x22050022
//NB BT/FT 公共部分
#define ERR_RDA_NB_Reopen_Comport				0x22050040
#define ERR_RDA_NB_INIT_CALIB_OBJ				0x22050041
#define ERR_RDA_NB_EnterCalibMode				0x22050042
#define ERR_RDA_NB_Check_Open					0x22050043
//NB  FT 部分
#define ERR_RDA_NB_NsftInstrumentPrepare		0x22050050
#define ERR_RDA_NB_NsftCalibPrepare				0x22050051
#define ERR_NB_FT								0x22050052
//2G FT 部分
#define ERR_2G_NSTestTotalInitialize			0x22050060
#define ERR_2G_FT								0x22050061
//2G校准部分
#define ERR_RDA_2G_EnterCalibMode				0x22050100
#define ERR_RDA_2G_InstrumentPrepare			0x22050101
#define ERR_RDA_2G_CalibPrepare					0x22050102
#define ERR_RDA_2G_SetCalibParams				0x22050103
#define ERR_RDA_2G_Crystal_Calib				0x22050104
#define ERR_RDA_2G_AFC_Gains_Cal_Band_GSM850	0x22050105
#define ERR_RDA_2G_AFC_Gains_Cal_Band_GSM900	0x22050106
#define ERR_RDA_2G_AFC_Gains_Cal_Band_DCS		0x22050107
#define ERR_RDA_2G_AFC_Gains_Cal_Band_PCS		0x22050108
#define ERR_RDA_2G_CalibPAProfil_Band_GSM850	0x22050109
#define ERR_RDA_2G_CalibPAProfil_Band_GSM900	0x2205010A
#define ERR_RDA_2G_CalibPAProfil_Band_DCS		0x2205010B
#define ERR_RDA_2G_CalibPAProfil_Band_PCS		0x2205010C
#define ERR_RDA_2G_CalibPAOffset_Band_GSM850	0x2205010D
#define ERR_RDA_2G_CalibPAOffset_Band_GSM900	0x2205010E
#define ERR_RDA_2GR_CalibPAOffset_Band_DCS		0x2205010F
#define ERR_RDA_2G_CalibPAOffset_Band_PCS		0x22050110
#define ERR_RDA_2G_CalibILoss_Band_GSM850		0x22050111
#define ERR_RDA_2G_CalibILoss_Band_GSM900		0x22050112
#define ERR_RDA_2G_CalibILoss_Band_DCS			0x22050113
#define ERR_RDA_2G_CalibILoss_Band_PCS			0x22050114
#define ERR_RDA_2G_Calibrate					0x22050115

//NB校准部分
#define ERR_RDA_NB_InstrumentPrepare			0x22050131
#define ERR_RDA_NB_CalibPrepare					0x22050132
#define ERR_RDA_NB_SetCalibParams				0x22050133
#define ERR_RDA_NB_Crystal_Calib				0x22050134
#define ERR_RDA_NB_APC_OFFSET_Cal_Band_Band1	0x22050135
#define ERR_RDA_NB_APC_OFFSET_Cal_Band_Band3	0x22050136
#define ERR_RDA_NB_APC_OFFSET_Cal_Band_Band5	0x22050137
#define ERR_RDA_NB_APC_OFFSET_Cal_Band_Band8	0x22050138
#define ERR_RDA_NB_APC_OFFSET_Cal_Band_Band20	0x22050139
#define ERR_RDA_NB_APC_OFFSET_Cal_Band_Band28	0x2205013A
#define ERR_RDA_NB_AGC_OFFSET_Band_Band1		0x2205013B
#define ERR_RDA_NB_AGC_OFFSET_Band_Band3		0x2205013C
#define ERR_RDA_NB_AGC_OFFSET_Band_Band5		0x2205013D
#define ERR_RDA_NB_AGC_OFFSET_Band_Band8		0x2205013E
#define ERR_RDA_NB_AGC_OFFSET_Band_Band20		0x2205013F
#define ERR_RDA_NB_AGC_OFFSET_Band_Band28		0x22050140
#define ERR_RDA_NB_Calibrate					0x22050141		

#define ERR_RDA_IMEI1_WRITE						0x22060001	
#define ERR_RDA_IMEI1_READ						0x22060002
#define ERR_RDA_IMEI1_CHECK						0x22060003
#define ERR_RDA_IMEI2_WRITE						0x22060004	
#define ERR_RDA_IMEI2_READ						0x22060005	
#define ERR_RDA_IMEI2_CHECK						0x22060006
#define ERR_RDA_BTADDR_WRITE					0x22060007	
#define ERR_RDA_BTADDR_READ						0x22060008
#define ERR_RDA_BTADDR_CHECK					0x22060009
#define ERR_RDA_WIFIMAC_WRITE					0x2206000A	
#define ERR_RDA_WIFIMAC_READ					0x2206000B	
#define ERR_RDA_WIFIMAC_CHECK					0x2206000C
#define ERR_RDA_MEID_WRITE						0x2206000D	
#define ERR_RDA_MEID_READ						0x2206000E	
#define ERR_RDA_MEID_CHECK						0x22060010
#define ERR_RDA_SN_WRITE						0x22060011
#define ERR_RDA_SN_CHECK						0x22060012


class CErrorCode
{
public:
	CErrorCode();
	virtual ~CErrorCode();
public:
// 	int Get_GSM_FT_Errocode(int iErrorCode);
// 	CString Format_ErrorCode_Info(int iErrorCode,CString sTestItem, float f_Value);
};
