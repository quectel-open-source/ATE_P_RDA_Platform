#pragma once
#if !defined(QALPC_LIB_H)
#define QALPC_LIB_H


#if defined(QAPLC_INSTRUMENT_LIBRARY)
#define QAPLC_INSTRUMENT_LIBRARY_EXPORT __declspec(dllexport)
#else
#define QAPLC_INSTRUMENT_LIBRARY_EXPORT __declspec(dllimport)
#endif

#include <vector>
using namespace std;

/*
Instrument Type
*/
typedef enum
{
	QAPLC_INSTRUMENT_TYPE_CMW100 ,
	QAPLC_INSTRUMENT_TYPE_IQXSTREAM_M ,
	QAPLC_INSTRUMENT_TYPE_IQXSTREAM_5G ,
	QAPLC_INSTRUMENT_TYPE_COUNT
} QAPLCInstrumentType;


/*
|******************************************Instrument Port Mapping***************************************************
|CMW100(OneInst)     |      RF1, |      RF2, |      RF3, |      RF4, |      RF5, |      RF6, |      RF7, |      RF8 |
|RfPortType          |  RfPort1, |  RfPort2, |  RfPort3, |  RfPort4, |  RfPort5, |  RfPort6, |  RfPort7, |  RfPort8 |
|--------------------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|----------|
|CMW100(TwoInst)     |      RF1, |      RF2, |      RF3, |      RF4, |      RF5, |      RF6, |      RF7, |      RF8 |
|RfPortType          |  RfPort1, |  RfPort2, |  RfPort3, |  RfPort4, |  RfPort1, |  RfPort2, |  RfPort3, |  RfPort4 |
|--------------------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|----------|
|IQxstream-M         |BANK1_RF1, |BANK1_RF2, |BANK1_RF3, |BANK1_RF4, |BANK2_RF1, |BANK2_RF2, |BANK2_RF3, |BANK2_RF4 |
|RfPortType          |  RfPort1, |  RfPort2, |  RfPort3, |  RfPort4, |  RfPort5, |  RfPort6, |  RfPort7, |  RfPort8 |
|--------------------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|----------|
|IQxstream-5G        |     RF1A, |     RF1B, |     RF2A, |     RF2B, |     RF3A, |     RF3B, |     RF4A, |     RF4B |
|RfPortType          |  RfPort1, |  RfPort2, |  RfPort3, |  RfPort4, |  RfPort5, |  RfPort6, |  RfPort7, |  RfPort8 |
*********************************************************************************************************************
*/
typedef enum
{
	RfPort1 = 1 ,
	RfPort2 ,
	RfPort3 ,
	RfPort4 ,
	RfPort5 ,
	RfPort6 ,
	RfPort7 ,
	RfPort8 ,
	RfPortCount
} RfPortType;


/*
Each port supports 8 paths
*/
typedef enum
{
	RfPortPathIndex1 = 1 ,
	RfPortPathIndex2 ,
	RfPortPathIndex3 ,
	RfPortPathIndex4 ,
	RfPortPathIndex5 ,
	RfPortPathIndex6 ,
	RfPortPathIndex7 ,
	RfPortPathIndex8 ,
} RfPortPathIndex;


/*
QAPLC_Lib API return type
*/
typedef enum
{
	S_DONE = 0 ,                             /**< PASS */
	S_ERROR = 1 ,							 /**< FAIL */
	S_ERROR_ITEM_COUNT /* Keep this last */  /**< Undefined error */
}InstErrorCode;

/*
QAPLC_Lib Multi-Thread Handle
*/
typedef void* QAPLCInstLibHandle;

/*
* @details Create QAPLC_Lib Handle
* @param [in] instrumentType
* @return QAPLCInstLibHandle
*/
QAPLC_INSTRUMENT_LIBRARY_EXPORT QAPLCInstLibHandle QAPLCInstLib_CreateHandle ( QAPLCInstrumentType instrumentType );
/*
* @details Destroy QAPLC_Lib Handle
* @param [in] handle
* @return 0->success , other fail
*/
QAPLC_INSTRUMENT_LIBRARY_EXPORT int QAPLCInstLib_DestroyHandle ( QAPLCInstLibHandle handle );
/*
* @details Connect Instrument
* @param [in] handle
* @param [in] address
* @return 0->success , other fail
*/
QAPLC_INSTRUMENT_LIBRARY_EXPORT int QAPLCInstLib_Connect ( QAPLCInstLibHandle handle , const char *address );
/*
* @details Disconnect Instrument
* @param [in] handle
* @return 0->success , other fail
*/
QAPLC_INSTRUMENT_LIBRARY_EXPORT int QAPLCInstLib_Disconnect ( QAPLCInstLibHandle handle );
/*
* @details Get Instrument serial number
* @param [in] handle
* @return Instrument serial number
*/
QAPLC_INSTRUMENT_LIBRARY_EXPORT const char* QAPLCInstLib_GetIdString ( QAPLCInstLibHandle handle );
/*
* @details Set Debug Log CallBack Function
* @param [in] handle
* @param [in] void* CallBack_Debug_Log
* @param [in] bEnableGPIBLog
* @param [in] p_usr_Arguments
* @return 0->success , other fail
*/
QAPLC_INSTRUMENT_LIBRARY_EXPORT int QAPLCInstLib_Debug_Log_CallBack ( QAPLCInstLibHandle handle , void* CallBack_Debug_Log , bool bEnableGPIBLog , void * p_usr_Arguments );
/*
* @details Init Base Inst
* @param [in] handle
* @return 0->success , other fail
*/
QAPLC_INSTRUMENT_LIBRARY_EXPORT int QAPLCInstLib_InitBaseInst ( QAPLCInstLibHandle handle );
/*
* @details Set the InstrumentPort and FreqList you want to measure pathloss
* @param [in] handle
* @param [in] PortNum
* @param [in] PortPathIndex
* @param [in] FreqList in STL vector container,Freq Spec(450M~5950M) ,Max FreqPoint 2000
* @return 0->success , other fail
*/
QAPLC_INSTRUMENT_LIBRARY_EXPORT int QAPLCInstLib_Set_InstPort_And_FreqList ( QAPLCInstLibHandle handle ,
	const RfPortType PortNum , 
	const RfPortPathIndex PortPathIndex , 
	const vector<double> stlFreq_MHz );
/*
* @details Connect the open board and execute open
* @param [in] handle
* @param [in] PortNum
* @param [in] PortPathIndex
* @return 0->success , other fail
*/
QAPLC_INSTRUMENT_LIBRARY_EXPORT int QAPLCInstLib_Excute_Open ( QAPLCInstLibHandle handle , 
	const RfPortType PortNum , 
	const RfPortPathIndex PortPathIndex );
/*
* @details Connect the open board and execute short
* @param [in] handle
* @param [in] PortNum
* @param [in] PortPathIndex
* @return 0->success , other fail
*/
QAPLC_INSTRUMENT_LIBRARY_EXPORT int QAPLCInstLib_Excute_Short ( QAPLCInstLibHandle handle , 
	const RfPortType PortNum , 
	const RfPortPathIndex PortPathIndex );
/*
* @details Evaluation and obtain pathloss measurement results
* @param [in] handle
* @param [in] PortNum
* @param [in] PortPathIndex
* @param [in/out] PathlossList in STL vector container,It is consistent with the order of input parameters stlFreq_MHz
* @return 0->success , other fail
*/
QAPLC_INSTRUMENT_LIBRARY_EXPORT int QAPLCInstLib_Excute_Evaluation ( QAPLCInstLibHandle handle , 
	const RfPortType PortNum , 
	vector<double> &stlPathLoss_dB , 
	const RfPortPathIndex PortPathIndex );


#endif//#if !defined(QALPC_LIB_H)