/* Copyright (C) 2016 RDA Technologies Limited and/or its affiliates("RDA").
 * All rights reserved.
 *
 * This software is supplied "AS IS" without any warranties.
 * RDA assumes no responsibility or liability for the use of the software,
 * conveys no license or title under any patent, copyright, or mask work
 * right to the product. RDA reserves the right to make changes in the
 * software without notification.  RDA also make no representation or
 * warranty that such application will be suitable for the specified use
 * without further testing or modification.
 */
/// @defgroup calib Calibration Driver
///  @{
///

#ifndef _CALIB_M_H_
#define _CALIB_M_H_


#include "cs_types.h"

// =============================================================================
//  MACROS
// =============================================================================
/// Version of the calibration stub and code (on 8 bits).
#define CALIB_MAJ_VERSION                       (2)
#define CALIB_MIN_VERSION                       (7)
#define CALIB_MARK_VERSION                      (0XCA1B0000)
#define CALIB_VERSION_NUMBER                    (( CALIB_MARK_VERSION | CALIB_MAJ_VERSION << 8 | CALIB_MIN_VERSION ))
#define CALIB_STUB_VERSION                      (0XCA5B0001)
/// Number of calib timings for the transceiver.
#define CALIB_XCV_TIME_QTY                      (20)
/// Number of calib timings for the PA.
#define CALIB_PA_TIME_QTY                       (15)
/// Number of calib timings for the switch.
#define CALIB_SW_TIME_QTY                       (15)
/// Number of calib timings for PAL.
#define CALIB_PAL_TIME_QTY                      (20)
/// Number of generic parameters for the transceiver.
#define CALIB_XCV_PARAM_QTY                     (20)
/// Number of generic parameters for the PA.
#define CALIB_PA_PARAM_QTY                      (15)
/// Number of generic parameters for the switch.
#define CALIB_SW_PARAM_QTY                      (15)
/// Mask for transceiver RF name.
#define CALIB_XCV_MASK                          ((1 << 24))
/// Mask for PA RF name.
#define CALIB_PA_MASK                           ((1 << 25))
/// Mask for switch RF name.
#define CALIB_SW_MASK                           ((1 << 26))
#define CALIB_GSM_PCL_QTY                       (15)
#define CALIB_DCS_PCL_QTY                       (17)
#define CALIB_PCS_PCL_QTY                       (18)
#define CALIB_PADAC_PROF_INTERP_QTY             (16)
#define CALIB_PADAC_PROF_QTY                    (1024)
#define CALIB_PADAC_RAMP_QTY                    (32)
#define CALIB_LOW_VOLT_QTY                      (6)
/// Number of coefficiens in the MDF FIR filter.
#define CALIB_VOC_MDF_QTY                       (64)
/// Number of coefficiens in the SDF FIR filter.
#define CALIB_VOC_SDF_QTY                       (64)
/// Mask for echo cancelation enable (to be used with audio VoC enable).
#define CALIB_EC_ON                             ((1 << 0))
/// Mask for MDF FIR filter enable (to be used with audio VoC enable).
#define CALIB_MDF_ON                            ((1 << 1))
/// Mask for SDF FIR filter enable (to be used with audio VoC enable).
#define CALIB_SDF_ON                            ((1 << 2))
/// Number of audio gain steps.
#define CALIB_AUDIO_GAIN_QTY                    (8)
/// The audio gain value standing for mute.
#define CALIB_AUDIO_GAIN_VALUE_MUTE             (-128)
/// Number of misc audio parameters.
#define CALIB_AUDIO_PARAM_QTY                   (8)
/// Unrealistic values meaning that the power measure is not complete yet.
#define CALIB_STUB_SEARCH_POWER                 (0X0)
/// Unrealistic values meaning that the FOf measure is not complete yet.
#define CALIB_STUB_SEARCH_FOF                   (-2000000)
/// For communication between Calib Stub and calibration tools.
#define CALIB_STUB_XTAL_IDLE                    (-2000001)
/// For communication between Calib Stub and calibration tools.
#define CALIB_STUB_PA_PROF_IDLE                 (-2000002)
/// For communication between Calib Stub and calibration tools.
#define CALIB_STUB_ILOSS_IDLE                   (-128)
/// For communication between Calib Stub and calibration tools.
#define CALIB_STUB_DCO_IDLE                     (-32768)
/// For communication between Calib Stub and calibration tools.
#define CALIB_STUB_DCO_ERROR                    (-32767)
/// For communication between Calib Stub and calibration tools.
#define CALIB_STUB_GPADC_ERROR                  (0XFFFF)
/// For communication between Calib Stub and calibration tools.
#define CALIB_STUB_GPADC_IDLE                   (0XFFFE)
/// Number of cells used for measurement averages
#define CALIB_NB_CELLS                          (5)
/// Maximum number of different Audio Interfaces supported by this calibration structure.
/// The value of CALIB_AUDIO_ITF_QTY must be the same as AUD_ITF_QTY!
#define CALIB_AUDIO_ITF_QTY                     (6)
/// The number of GP ADC channels.
#define CALIB_GPADC_CH_QTY                      (4)
#define CALIB_GPADC_ACC_COUNT                   (8)
#define CALIB_GPADC_ACC_COUNT_MAX               (128)
#define CALIB_AUDIO_DICTA_REC                   (1)
#define CALIB_AUDIO_DICTA_PLAY                  (2)

// ============================================================================
// CALIB_METHOD_T
// -----------------------------------------------------------------------------
/// Calib process method type.
// =============================================================================
typedef enum {
    CALIB_METH_DEFAULT                          = 0xCA11E700,
    CALIB_METH_COMPILATION                      = 0xCA11E701,
    CALIB_METH_MANUAL                           = 0xCA11E702,
    CALIB_METH_AUTOMATIC                        = 0xCA11E703,
    CALIB_METH_SIMULATION                       = 0xCA11E704
} CALIB_METHOD_T;


// ============================================================================
// CALIB_H_ENUM_0_T
// -----------------------------------------------------------------------------
/// Used for autonomous calib processes, results from Calib Stub to remote.
// =============================================================================
typedef enum {
    CALIB_PROCESS_STOP                          = 0x00000000,
    CALIB_PROCESS_CONTINUE                      = 0x00000001,
    CALIB_PROCESS_PENDING                       = 0x00000002,
    CALIB_PROCESS_NEED_CALM                     = 0x00000003,
    CALIB_PROCESS_ERR_BAD_POW                   = 0x000000F0,
    CALIB_PROCESS_ERR_NO_MONO_POW               = 0x000000F1,
    CALIB_PROCESS_ERR_ZERO_DAC                  = 0x000000F2,
    CALIB_PROCESS_ERROR                         = 0x000000FF
} CALIB_H_ENUM_0_T;


// ============================================================================
// CALIB_STUB_BAND_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef enum {
    CALIB_STUB_BAND_GSM850                      = 0x00000000,
    CALIB_STUB_BAND_GSM900                      = 0x00000001,
    CALIB_STUB_BAND_DCS1800                     = 0x00000002,
    CALIB_STUB_BAND_PCS1900                     = 0x00000003,
    CALIB_STUB_BAND_QTY                         = 0x00000004
} CALIB_STUB_BAND_T;


// ============================================================================
// CALIB_NST_STAT_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef enum {
    NST_NO_STATE                                = 0x00000000,
    NST_IDLE_STATE                              = 0x00000001,
    NST_POWER_STATE                             = 0x00000002,
    NST_SYNC_STATE                              = 0x00000003,
    NST_OFFSET_STATE                            = 0x00000004,
    NST_RX_STATE                                = 0x00000005,
    NST_ACQUIRE_STATE                           = 0x00000006,
    NST_BER_CACULATION_STATE                    = 0x00000007,
    NST_STOP_RX_SYNC_STATE                      = 0x00000008,
    NST_SIMU_LOG_STATE                          = 0x00000009,
    NST_DISCONN_STATE                           = 0x0000000A
} CALIB_NST_STAT_T;


// ============================================================================
// CALIB_STUB_CMDS_T
// -----------------------------------------------------------------------------
/// Values used to define the contexts of the Calib Stub.
// =============================================================================
typedef enum {
    CALIB_STUB_NO_STATE                         = 0x00000000,
    CALIB_STUB_MONIT_STATE                      = 0x00000001,
    CALIB_STUB_FOF_STATE                        = 0x00000002,
    CALIB_STUB_TX_STATE                         = 0x00000003,
    CALIB_STUB_PA_STATE                         = 0x00000004,
    CALIB_STUB_AUDIO_OUT                        = 0x00000005,
    CALIB_STUB_AUDIO_IN                         = 0x00000006,
    CALIB_STUB_AUDIO_SIDE                       = 0x00000007,
    CALIB_STUB_SYNCH_STATE                      = 0x00000008,
    CALIB_STUB_IDLE_STATE                       = 0x00000009,
    CALIB_STUB_NST_STATE                        = 0x0000000A,
    CALIB_STUB_NSTREQ_STATE                     = 0x0000000B
} CALIB_STUB_CMDS_T;


// ============================================================================
// CALIB_STUB_AFC_BOUND_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef enum {
    CALIB_STUB_AFC_BOUND_CENTER                 = 0x00000000,
    CALIB_STUB_AFC_BOUND_NEG_FREQ               = 0x00000001,
    CALIB_STUB_AFC_BOUND_POS_FREQ               = 0x00000002,
    CALIB_STUB_AFC_BOUND_NO                     = 0x00000003
} CALIB_STUB_AFC_BOUND_T;

/// Value that defines the number of measure to do before the DC offset average is
/// considered valid.
#define CALIB_DCO_ACC_COUNT                     (32)
/// This magiv tag is used as a parameter to the boot loader to force is to run the
/// calibration stub
#define CALIB_MAGIC_TAG                         (0XCA1BCA1B)

// ============================================================================
// CALIB_COMMAND_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef enum {
/// Command used by the Calibration Embedded Stub to inform HST that the command
/// is done.
    CALIB_CMD_DONE                              = 0xCA11B042,
    CALIB_CMD_NOT_ACCESSIBLE                    = 0xCA11B043,
    CALIB_CMD_UPDATE                            = 0xCA11B044,
    CALIB_CMD_UPDATE_ERROR                      = 0xCA11B045,
    CALIB_CMD_PA_PROFILE_GSM                    = 0xCA11B046,
    CALIB_CMD_PA_PROFILE_DCSPCS                 = 0xCA11B047,
    CALIB_CMD_RF_FLASH_BURN                     = 0xCA11B048,
    CALIB_CMD_FLASH_ERASE                       = 0xCA11B049,
    CALIB_CMD_FLASH_ERROR                       = 0xCA11B04A,
    CALIB_CMD_RF_RESET                          = 0xCA11B04B,
    CALIB_CMD_AUDIO_RESET                       = 0xCA11B04C,
    CALIB_CMD_RESET                             = 0xCA11B04D,
    CALIB_CMD_AUDIO_FLASH_BURN                  = 0xCA11B04E,
    CALIB_CMD_FLASH_BURN                        = 0xCA11B04F,
    CALIB_CMD_CFP_BURN                          = 0xCA11B050
} CALIB_COMMAND_T;


// ============================================================================
// CALIB_PARAM_STATUS_T
// -----------------------------------------------------------------------------
/// Calibration parameter type identifier.
// =============================================================================
typedef enum {
    CALIB_PARAM_DEFAULT                         = 0xCA11B042,
    CALIB_PARAM_DEFAULT_RF_MIS                  = 0xCA11B043,
    CALIB_PARAM_INIT_ERROR                      = 0xCA10DEAD,
    CALIB_PARAM_RF_CALIBRATED                   = 0x007F0011,
    CALIB_PARAM_AUDIO_CALIBRATED                = 0x00A0D011,
    CALIB_PARAM_AUDIO_CALIBRATED_RF_MIS         = 0x00A0D043,
    CALIB_PARAM_CALIBRATED                      = 0x00DEF011
} CALIB_PARAM_STATUS_T;


// =============================================================================
//  TYPES
// =============================================================================

// ============================================================================
// CALIB_GLOBALS_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef struct {
} CALIB_GLOBALS_T; //Size : 0x0



// ============================================================================
// CALIB_GPADC_ALL_CH_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef UINT16 CALIB_GPADC_ALL_CH_T[CALIB_GPADC_CH_QTY];


// ============================================================================
// CALIB_VERSION_TAG_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef UINT32 CALIB_VERSION_TAG_T;


// ============================================================================
// CALIB_OP_INFO_T
// -----------------------------------------------------------------------------
/// Calib process method and date type.
// =============================================================================
typedef struct {
    UINT32                         date;                         //0x00000000
    CALIB_METHOD_T                 method;                       //0x00000004
} CALIB_OP_INFO_T; //Size : 0x8



// ============================================================================
// CALIB_XCV_TIMES_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef INT16 CALIB_XCV_TIMES_T[CALIB_XCV_TIME_QTY];


// ============================================================================
// CALIB_PA_TIMES_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef INT16 CALIB_PA_TIMES_T[CALIB_PA_TIME_QTY];


// ============================================================================
// CALIB_SW_TIMES_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef INT16 CALIB_SW_TIMES_T[CALIB_SW_TIME_QTY];


// ============================================================================
// CALIB_PAL_TIMES_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef INT16 CALIB_PAL_TIMES_T[CALIB_PAL_TIME_QTY];


// ============================================================================
// CALIB_XCV_PARAM_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef INT32 CALIB_XCV_PARAM_T[CALIB_XCV_PARAM_QTY];


// ============================================================================
// CALIB_PA_PARAM_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef INT32 CALIB_PA_PARAM_T[CALIB_PA_PARAM_QTY];


// ============================================================================
// CALIB_SW_PARAM_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef INT32 CALIB_SW_PARAM_T[CALIB_SW_PARAM_QTY];


// ============================================================================
// CALIB_RF_CHIP_NAME_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef UINT32 CALIB_RF_CHIP_NAME_T;


// ============================================================================
// CALIB_RXTX_FREQ_OFFSET_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef INT16 CALIB_RXTX_FREQ_OFFSET_T[CALIB_STUB_BAND_QTY];


// ============================================================================
// CALIB_RXTX_TIME_OFFSET_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef INT16 CALIB_RXTX_TIME_OFFSET_T;


// ============================================================================
// CALIB_RXTX_IQ_TIME_OFFSET_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef INT16 CALIB_RXTX_IQ_TIME_OFFSET_T;


// ============================================================================
// CALIB_DCO_CAL_TIME_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef INT16 CALIB_DCO_CAL_TIME_T;


// ============================================================================
// CALIB_XCV_PALCUST_T
// -----------------------------------------------------------------------------
/// XCV PAL custom types.
// =============================================================================
typedef struct {
    CALIB_RF_CHIP_NAME_T           name;                         //0x00000000
    CALIB_RXTX_FREQ_OFFSET_T       rxTxFreqOffset;               //0x00000004
    CALIB_RXTX_TIME_OFFSET_T       rxTxTimeOffset;               //0x0000000C
    CALIB_RXTX_IQ_TIME_OFFSET_T    rxIqTimeOffset;               //0x0000000E
    CALIB_RXTX_IQ_TIME_OFFSET_T    txIqTimeOffset;               //0x00000010
    CALIB_DCO_CAL_TIME_T           dcoCalTime;                   //0x00000012
    INT32                          spare[7];                     //0x00000014
} CALIB_XCV_PALCUST_T; //Size : 0x30



// ============================================================================
// CALIB_ARFCN_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef INT16 CALIB_ARFCN_T[2];


// ============================================================================
// CALIB_PCL2DBM_ARFCN_G_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef CALIB_ARFCN_T CALIB_PCL2DBM_ARFCN_G_T[CALIB_GSM_PCL_QTY];


// ============================================================================
// CALIB_PCL2DBM_ARFCN_D_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef CALIB_ARFCN_T CALIB_PCL2DBM_ARFCN_D_T[CALIB_DCS_PCL_QTY];


// ============================================================================
// CALIB_PCL2DBM_ARFCN_P_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef CALIB_ARFCN_T CALIB_PCL2DBM_ARFCN_P_T[CALIB_PCS_PCL_QTY];


// ============================================================================
// CALIB_PADAC_PROFILE_INTERP_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef UINT16 CALIB_PADAC_PROFILE_INTERP_T[CALIB_PADAC_PROF_INTERP_QTY];


// ============================================================================
// CALIB_PADAC_PROFILE_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef UINT16 CALIB_PADAC_PROFILE_T[CALIB_PADAC_PROF_QTY];


// ============================================================================
// CALIB_PADAC_PROFILE_EXTREM_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef INT16 CALIB_PADAC_PROFILE_EXTREM_T;


// ============================================================================
// CALIB_PADAC_RAMP_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef UINT16 CALIB_PADAC_RAMP_T[CALIB_PADAC_RAMP_QTY];


// ============================================================================
// CALIB_PADAC_RAMP_SWAP_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef UINT16 CALIB_PADAC_RAMP_SWAP_T;


// ============================================================================
// CALIB_PADAC_LOW_VOLT_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef UINT16 CALIB_PADAC_LOW_VOLT_T[CALIB_LOW_VOLT_QTY];


// ============================================================================
// CALIB_PADAC_LOW_DAC_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef UINT16 CALIB_PADAC_LOW_DAC_T[CALIB_LOW_VOLT_QTY];


// ============================================================================
// CALIB_PA_PALCUST_T
// -----------------------------------------------------------------------------
/// PA PAL custom types.
// =============================================================================
typedef struct {
    CALIB_RF_CHIP_NAME_T           name;                         //0x00000000
    CALIB_PCL2DBM_ARFCN_G_T        pcl2dbmArfcnG;                //0x00000004
    CALIB_PCL2DBM_ARFCN_D_T        pcl2dbmArfcnD;                //0x00000040
    CALIB_PCL2DBM_ARFCN_P_T        pcl2dbmArfcnP;                //0x00000084
    CALIB_PADAC_PROFILE_INTERP_T   profileInterpG;               //0x000000CC
    CALIB_PADAC_PROFILE_INTERP_T   profileInterpDp;              //0x000000EC
    CALIB_PADAC_PROFILE_T          profileG;                     //0x0000010C
    CALIB_PADAC_PROFILE_T          profileDp;                    //0x0000090C
    CALIB_PADAC_PROFILE_EXTREM_T   profileDbmMinG;               //0x0000110C
    CALIB_PADAC_PROFILE_EXTREM_T   profileDbmMinDp;              //0x0000110E
    CALIB_PADAC_PROFILE_EXTREM_T   profileDbmMaxG;               //0x00001110
    CALIB_PADAC_PROFILE_EXTREM_T   profileDbmMaxDp;              //0x00001112
    CALIB_PADAC_RAMP_T             rampLow;                      //0x00001114
    CALIB_PADAC_RAMP_T             rampHigh;                     //0x00001154
    CALIB_PADAC_RAMP_SWAP_T        rampSwapG;                    //0x00001194
    CALIB_PADAC_RAMP_SWAP_T        rampSwapDp;                   //0x00001196
    CALIB_PADAC_LOW_VOLT_T         lowVoltLimit;                 //0x00001198
    CALIB_PADAC_LOW_DAC_T          lowDacLimit;                  //0x000011A4
    INT32                          spare[8];                     //0x000011B0
} CALIB_PA_PALCUST_T; //Size : 0x11D0



// ============================================================================
// CALIB_SW_PALCUST_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef struct {
    CALIB_RF_CHIP_NAME_T           name;                         //0x00000000
    INT32                          spare[8];                     //0x00000004
} CALIB_SW_PALCUST_T; //Size : 0x24



// ============================================================================
// CALIB_AUDIO_VOC_EC_T
// -----------------------------------------------------------------------------
/// Echo Cancelling for VoC.
// =============================================================================
typedef struct {
    /// Enables Echo Canceller algorithm when >0.
    UINT8                          ecMu;                         //0x00000000
    /// Echo Canceller REL parameter (0,+16).
    UINT8                          ecRel;                        //0x00000001
    /// Echo Canceller MIN parameter (0, 32).
    UINT8                          ecMin;                        //0x00000002
    /// Enable Echo Suppressor algorithm (0,1).
    UINT8                          esOn;                         //0x00000003
    /// Double talk threshold for Echo Suppressor algo (0,32).
    UINT8                          esDtd;                        //0x00000004
    /// Donwlink vad threshold for Echo Suppressor algo (0,32).
    UINT8                          esVad;                        //0x00000005
    /// Enable for echo cancelling.
    UINT32                         enableField;                  //0x00000008
} CALIB_AUDIO_VOC_EC_T; //Size : 0xC



// ============================================================================
// CALIB_AUDIO_VOC_FILTERS_T
// -----------------------------------------------------------------------------
/// VoC anti-distortion filters.
// =============================================================================
typedef struct {
    /// VoC needs the MDF coeffs to be 32-bit aligned.
    UINT16                         mdfFilter[CALIB_VOC_MDF_QTY]; //0x00000000
    /// SDF coeffs must stay right after MDF.
    UINT16                         sdfFilter[CALIB_VOC_SDF_QTY]; //0x00000080
} CALIB_AUDIO_VOC_FILTERS_T; //Size : 0x100



// ============================================================================
// CALIB_AUDIO_IN_GAINS_T
// -----------------------------------------------------------------------------
/// Input (MIC) gains.
// =============================================================================
typedef struct {
    /// Input analog gain.
    INT8                           ana;                          //0x00000000
    /// Input ADC gain.
    INT8                           adc;                          //0x00000001
    /// Input algorithm gain.
    INT8                           alg;                          //0x00000002
    /// Reserved.
    INT8                           reserv;                       //0x00000003
} CALIB_AUDIO_IN_GAINS_T; //Size : 0x4



// ============================================================================
// CALIB_AUDIO_OUT_GAINS_T
// -----------------------------------------------------------------------------
/// Output gains.
// =============================================================================
typedef struct {
    /// Output voice gains for physical interfaces, or earpiece gains for application
    /// interfaces. Output analog gain.
    INT8                           voiceOrEpAna;                 //0x00000000
    /// Output DAC gain.
    INT8                           voiceOrEpDac;                 //0x00000001
    /// Output algorithm gain.
    INT8                           voiceOrEpAlg;                 //0x00000002
    /// Reserved.
    INT8                           reserv1;                      //0x00000003
    /// Output music gains for physical interfaces, or loudspeaker gains for application
    /// interfaces. Output analog gain.
    INT8                           musicOrLsAna;                 //0x00000004
    /// Output DAC gain.
    INT8                           musicOrLsDac;                 //0x00000005
    /// Output algorithm gain.
    INT8                           musicOrLsAlg;                 //0x00000006
    /// Reserved.
    INT8                           reserv2;                      //0x00000007
} CALIB_AUDIO_OUT_GAINS_T; //Size : 0x8



// ============================================================================
// CALIB_AUDIO_GAINS_T
// -----------------------------------------------------------------------------
/// Calib audio gain types.
// =============================================================================
typedef struct {
    /// MIC gains during a voice call.
    CALIB_AUDIO_IN_GAINS_T         inGainsCall;                  //0x00000000
    /// Output gains.
    CALIB_AUDIO_OUT_GAINS_T        outGains[CALIB_AUDIO_GAIN_QTY]; //0x00000004
    INT8                           sideTone[CALIB_AUDIO_GAIN_QTY]; //0x00000044
    /// MIC gains during a sound recording.
    CALIB_AUDIO_IN_GAINS_T         inGainsRecord;                //0x0000004C
    INT8                           reserv[20];                   //0x00000050
} CALIB_AUDIO_GAINS_T; //Size : 0x64



// ============================================================================
// CALIB_AUDIO_PARAMS_T
// -----------------------------------------------------------------------------
/// Audio calibration parameters.
// =============================================================================
typedef struct {
    UINT32                         reserv1;                      //0x00000000
    INT8                           AecEnbleFlag;                 //0x00000004
    INT8                           AgcEnbleFlag;                 //0x00000005
    INT8                           StrongEchoFlag;               //0x00000006
    INT8                           reserv2;                      //0x00000007
    INT8                           NoiseGainLimit;               //0x00000008
    INT8                           NoiseMin;                     //0x00000009
    INT8                           NoiseGainLimitStep;           //0x0000000A
    INT8                           AmpThr;                       //0x0000000B
    INT8                           HighPassFilterFlag;           //0x0000000C
    INT8                           NotchFilterFlag;              //0x0000000D
    INT8                           NoiseSuppresserFlag;          //0x0000000E
    INT8                           NoiseSuppresserWithoutSpeechFlag; //0x0000000F
    UINT32                         AudioParams[CALIB_AUDIO_PARAM_QTY-4]; //0x00000010
} CALIB_AUDIO_PARAMS_T; //Size : 0x20



// ============================================================================
// CALIB_AUDIO_ITF_T
// -----------------------------------------------------------------------------
/// Calibration of an audio interface. It gathers the audio gains and VoC calibrations
/// data
// =============================================================================
typedef struct {
    /// Echo Cancelling for VoC.
    CALIB_AUDIO_VOC_EC_T           vocEc;                        //0x00000000
    /// VoC anti-distortion filters.
    CALIB_AUDIO_VOC_FILTERS_T      vocFilters;                   //0x0000000C
    /// Calib audio gain types.
    CALIB_AUDIO_GAINS_T            audioGains;                   //0x0000010C
    /// Audio calibration parameters.
    CALIB_AUDIO_PARAMS_T           audioParams;                  //0x00000170
} CALIB_AUDIO_ITF_T; //Size : 0x190



// ============================================================================
// CALIB_GPADC_T
// -----------------------------------------------------------------------------
/// Calib GPADC analog type.
// =============================================================================
typedef struct {
    UINT16                         sensorGainA;                  //0x00000000
    UINT16                         sensorGainB;                  //0x00000002
} CALIB_GPADC_T; //Size : 0x4



// ============================================================================
// CALIB_RF_CRC_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef UINT32 CALIB_RF_CRC_T;


// ============================================================================
// CALIB_XCV_T
// -----------------------------------------------------------------------------
/// Transceiver calibration.
// =============================================================================
typedef struct {
    CALIB_XCV_TIMES_T              times;                        //0x00000000
    CALIB_XCV_PARAM_T              param;                        //0x00000028
    /// XCV PAL custom types.
    CALIB_XCV_PALCUST_T            palcust;                      //0x00000078
} CALIB_XCV_T; //Size : 0xA8



// ============================================================================
// CALIB_PA_T
// -----------------------------------------------------------------------------
/// Power Amplifier RF calibration.
// =============================================================================
typedef struct {
    CALIB_PA_TIMES_T               times;                        //0x00000000
    CALIB_PA_PARAM_T               param;                        //0x00000020
    /// PA PAL custom types.
    CALIB_PA_PALCUST_T             palcust;                      //0x0000005C
} CALIB_PA_T; //Size : 0x122C



// ============================================================================
// CALIB_SW_T
// -----------------------------------------------------------------------------
/// Switch calibration.
// =============================================================================
typedef struct {
    CALIB_SW_TIMES_T               times;                        //0x00000000
    CALIB_SW_PARAM_T               param;                        //0x00000020
    CALIB_SW_PALCUST_T             palcust;                      //0x0000005C
} CALIB_SW_T; //Size : 0x80



// ============================================================================
// CALIB_BB_T
// -----------------------------------------------------------------------------
/// Baseband calibration.
// =============================================================================
typedef struct {
    CALIB_PAL_TIMES_T              times;                        //0x00000000
    /// Audio calibration, for each interface
    CALIB_AUDIO_ITF_T              audio[CALIB_AUDIO_ITF_QTY];   //0x00000028
    /// Analog macros calibration: GPADC.
    CALIB_GPADC_T                  gpadc;                        //0x00000988
} CALIB_BB_T; //Size : 0x98C



// ============================================================================
// CALIB_BUFFER_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef struct {
    /// Information about this calib buffer.
    CALIB_VERSION_TAG_T            versionTag;                   //0x00000000
    /// Calib process method and date type.
    CALIB_OP_INFO_T                opInfo;                       //0x00000004
    /// Transceiver calibration.
    CALIB_XCV_T                    xcv;                          //0x0000000C
    /// Power Amplifier RF calibration.
    CALIB_PA_T                     pa;                           //0x000000B4
    /// Switch calibration.
    CALIB_SW_T                     sw;                           //0x000012E0
    /// Baseband calibration.
    CALIB_BB_T                     bb;                           //0x00001360
    /// Reserved for future use.
    UINT32                         reserved[2];                  //0x00001CEC
    /// Information for audio calibration data.
    CALIB_VERSION_TAG_T            audioVersionTag;              //0x00001CF4
    /// CRC value for RF calibration data.
    CALIB_RF_CRC_T                 rfCrc;                        //0x00001CF8
} CALIB_BUFFER_T; //Size : 0x1CFC



// ============================================================================
// NSTARFRSSI_T_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef struct {
    VOLATILE UINT16                Arfcn;                        //0x00000000
    VOLATILE UINT16                Rssi;                         //0x00000002
} NSTARFRSSI_T_T; //Size : 0x4



// ============================================================================
// NSTPOWERREQ_T_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef struct {
    VOLATILE UINT16                Nb;                           //0x00000000
    VOLATILE UINT16                Index;                        //0x00000002
    VOLATILE NSTARFRSSI_T_T        List[548];                    //0x00000004
} NSTPOWERREQ_T_T; //Size : 0x894



// ============================================================================
// CALIB_NSTCONNECTREQ_T1_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef struct {
    VOLATILE UINT16                bcchArfcn;                    //0x00000000
    VOLATILE UINT16                tchArfcn;                     //0x00000002
    VOLATILE UINT8                 band;                         //0x00000004
    VOLATILE UINT8                 monPower;                     //0x00000005
    VOLATILE UINT8                 nbPower;                      //0x00000006
    VOLATILE UINT8                 txPcl;                        //0x00000007
    VOLATILE UINT8                 tsc;                          //0x00000008
    VOLATILE UINT8                 tn;                           //0x00000009
    VOLATILE UINT8                 codec;                        //0x0000000A
    VOLATILE UINT8                 loopback;                     //0x0000000B
    VOLATILE UINT8                 syncPhase;                    //0x0000000C
} CALIB_NSTCONNECTREQ_T1_T; //Size : 0xE



// ============================================================================
// CALIB_BITINFO_T_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef struct {
    VOLATILE UINT16                num_bits;                     //0x00000000
    VOLATILE UINT16                num_errors;                   //0x00000002
} CALIB_BITINFO_T_T; //Size : 0x4



// ============================================================================
// CALIB_NSTCONFIGUREREQ_T_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef struct {
    VOLATILE UINT8                 pn_type;                      //0x00000000
    VOLATILE UINT8                 ber_mode;                     //0x00000001
    VOLATILE UINT8                 invert;                       //0x00000002
    VOLATILE UINT8                 pad;                          //0x00000003
    VOLATILE UINT16                acq_threshold;                //0x00000004
    VOLATILE UINT16                acq_lost_threshold;           //0x00000006
} CALIB_NSTCONFIGUREREQ_T_T; //Size : 0x8



// ============================================================================
// CALIB_NSTCOMMSTATUS_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef struct {
    VOLATILE UINT8                 rspcId;                       //0x00000000
    VOLATILE UINT8                 status;                       //0x00000001
} CALIB_NSTCOMMSTATUS_T; //Size : 0x2



// ============================================================================
// PRBS_CTX_T_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef struct {
    VOLATILE UINT16                poly;                         //0x00000000
    VOLATILE UINT16                RegLen;                       //0x00000002
    VOLATILE UINT8                 ber_mode;                     //0x00000004
    VOLATILE UINT8                 invert;                       //0x00000005
    VOLATILE UINT8                 acq_timeout;                  //0x00000006
    VOLATILE UINT16                acq_threshold;                //0x00000008
    VOLATILE UINT16                acq_lost_threshold;           //0x0000000A
    VOLATILE VOID*                 array;                        //0x0000000C
    VOLATILE VOID*                 array2pos;                    //0x00000010
    VOLATILE UINT32                PosRtAligned;                 //0x00000014
    VOLATILE UINT32                PegRtAligned;                 //0x00000018
} PRBS_CTX_T_T; //Size : 0x1C



// ============================================================================
// NST_MEASCFG_T_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef struct {
    VOLATILE UINT8                 NbMeas;                       //0x00000000
    VOLATILE UINT8                 NbMeasSub;                    //0x00000001
    VOLATILE UINT16                MeasCumul;                    //0x00000002
    VOLATILE UINT16                MeasCumulSub;                 //0x00000004
    VOLATILE UINT16                TotalBit;                     //0x00000006
    VOLATILE UINT16                TotalBitSub;                  //0x00000008
    VOLATILE UINT16                WrongBitCumul;                //0x0000000A
    VOLATILE UINT16                WrongBitCumulSub;             //0x0000000C
    VOLATILE UINT8                 RxLevFull;                    //0x0000000E
    VOLATILE UINT8                 RxLevSub;                     //0x0000000F
    VOLATILE UINT8                 RlaVal;                       //0x00000010
    VOLATILE UINT8                 RxQualFull;                   //0x00000011
    VOLATILE UINT8                 RxQualSub;                    //0x00000012
} NST_MEASCFG_T_T; //Size : 0x14



// ============================================================================
// CALIB_STUB_NST_CTX_T
// -----------------------------------------------------------------------------
///
// =============================================================================
typedef struct {
    VOLATILE UINT32                state;                        //0x00000000
    VOLATILE UINT32                nstreqstate;                  //0x00000004
    VOLATILE UINT32                nstreqcurrstate;              //0x00000008
    VOLATILE UINT8                 modeId;                       //0x0000000C
    VOLATILE UINT8                 loopback;                     //0x0000000D
    VOLATILE UINT8                 syncPhase;                    //0x0000000E
    VOLATILE UINT8                 codec;                        //0x0000000F
    VOLATILE UINT8                 order;                        //0x00000010
    VOLATILE UINT8                 logEnable;                    //0x00000011
    VOLATILE UINT8                 num_samples;                  //0x00000012
    VOLATILE UINT32                measuretimes;                 //0x00000014
    VOLATILE UINT32                num_bits;                     //0x00000018
    VOLATILE UINT32                num_errors;                   //0x0000001C
    VOLATILE UINT8                 pn_type;                      //0x00000020
    VOLATILE UINT8                 ber_mode;                     //0x00000021
    VOLATILE UINT8                 invert;                       //0x00000022
    VOLATILE UINT8                 pad;                          //0x00000023
    VOLATILE UINT16                acq_threshold;                //0x00000024
    VOLATILE UINT16                acq_lost_threshold;           //0x00000026
    VOLATILE UINT8                 rspcId;                       //0x00000028
    VOLATILE UINT8                 status;                       //0x00000029
    VOLATILE UINT16                bcchArfcn;                    //0x0000002A
    VOLATILE UINT16                tchArfcn;                     //0x0000002C
    VOLATILE UINT8                 band;                         //0x0000002E
    VOLATILE UINT8                 monPower;                     //0x0000002F
    VOLATILE UINT8                 nbPower;                      //0x00000030
    VOLATILE UINT8                 txPcl;                        //0x00000031
    VOLATILE UINT8                 tsc;                          //0x00000032
    VOLATILE UINT8                 tn;                           //0x00000033
    VOLATILE PRBS_CTX_T_T          prbs;                         //0x00000034
    VOLATILE NSTPOWERREQ_T_T       powerReq;                     //0x00000050
    VOLATILE NST_MEASCFG_T_T       ServMeasCfg;                  //0x000008E4
    VOLATILE UINT8                 ReorderOut[260];              //0x000008F8
    VOLATILE UINT8                 PrbsOut[260];                 //0x000009FC
    /// Structure used to configure VOC frame decode
    //VOLATILE HAL_SPEECH_DEC_IN_T   speech_dec;                   //0x00000B00
    /// Structure used to configure VOC frame encode
    //VOLATILE HAL_SPEECH_ENC_OUT_T  speech_enc;                   //0x00000B34
} CALIB_STUB_NST_CTX_T; //Size : 0xB60



// ============================================================================
// CALIB_STUB_CTX_T
// -----------------------------------------------------------------------------
/// Used to send calibration context change requests from the remote calibration
/// tools to the Calib Stub.
// =============================================================================
typedef struct {
    /// Commands from the remote calibration tools.
    VOLATILE CALIB_STUB_CMDS_T     state;                        //0x00000000
    VOLATILE BOOL                  firstFint;                    //0x00000004
    /// Subcommands from the remote calibration tools.
    VOLATILE INT32                 setXtalFreqOffset;            //0x00000008
    VOLATILE UINT8                 setAfcBound;                  //0x0000000C
    VOLATILE UINT8                 setChangeDACAfcBound;         //0x0000000D
    VOLATILE INT32                 setChangeDACAfcFreqOffset;    //0x00000010
    VOLATILE INT32                 setChangeDACAfcFreq;          //0x00000014
    VOLATILE INT32                 setAfcFreqOffset;             //0x00000018
    VOLATILE INT8                  setILossOffset;               //0x0000001C
    VOLATILE INT32                 setPAProfMeas;                //0x00000020
    VOLATILE INT8                  setCalibUpdate;               //0x00000024
    VOLATILE UINT8                 setRestartGpadcMeasure;       //0x00000025
    /// Cells information
    VOLATILE UINT16                arfcn[CALIB_NB_CELLS];        //0x00000026
    VOLATILE UINT8                 power[CALIB_NB_CELLS];        //0x00000030
    VOLATILE BOOL                  isPcs[CALIB_NB_CELLS];        //0x00000035
    VOLATILE UINT8                 bsic;                         //0x0000003A
    VOLATILE UINT32                fn;                           //0x0000003C
    VOLATILE UINT8                 t2;                           //0x00000040
    VOLATILE UINT8                 t3;                           //0x00000041
    VOLATILE UINT16                qbOf;                         //0x00000042
    VOLATILE UINT16                pFactor;                      //0x00000044
    VOLATILE INT32                 tOf;                          //0x00000048
    VOLATILE INT32                 fOf;                          //0x0000004C
    VOLATILE UINT16                snR;                          //0x00000050
    VOLATILE UINT8                 bitError;                     //0x00000052
    VOLATILE UINT8                 monPower;                     //0x00000053
    VOLATILE UINT8                 nbPower;                      //0x00000054
    VOLATILE UINT8                 monBitmap;                    //0x00000055
    VOLATILE INT32                 meanFOf;                      //0x00000058
    /// This is initialized by HST
    VOLATILE UINT8                 xtalCalibDone;                //0x0000005C
    /// This is initialized by HST
    VOLATILE UINT16                paProfNextDacVal;             //0x0000005E
    VOLATILE UINT8                 paProfCalibDone;              //0x00000060
    VOLATILE INT16                 dcoAverI;                     //0x00000062
    VOLATILE INT16                 dcoAverQ;                     //0x00000064
    /// Can go up to 2 * CT_CALIB_DCO_ACC_COUNT - 1.
    VOLATILE UINT8                 dcoAccCount;                  //0x00000066
    VOLATILE INT16                 dcoI[CALIB_DCO_ACC_COUNT];    //0x00000068
    VOLATILE INT16                 dcoQ[CALIB_DCO_ACC_COUNT];    //0x000000A8
    /// Status of the iloss calibration porcess. This is initialized by HST.
    UINT8                          iLossCalibDone;               //0x000000E8
    /// ARFCN for which to measure the insertion loss. This is not initialized.
    UINT16                         iLossNextArfcn;               //0x000000EA
    UINT16                         gpadcAver[CALIB_GPADC_CH_QTY]; //0x000000EC
    /// Can go up to 2*CALIB_GPADC_ACC_COUNT-1.
    UINT8                          gpadcAccCount;                //0x000000F4
    CALIB_GPADC_ALL_CH_T           gpadcAcc[CALIB_GPADC_ACC_COUNT_MAX]; //0x000000F6
    /// Parameters for Tx commands from the remote calibration tools.
    VOLATILE UINT16                txArfcn;                      //0x000004F6
    VOLATILE UINT8                 txPcl;                        //0x000004F8
    VOLATILE UINT16                txDac;                        //0x000004FA
    VOLATILE UINT8                 txBand;                       //0x000004FC
    VOLATILE UINT8                 txTsc;                        //0x000004FD
    /// Parameters for monitoring commands from the remote calibration tools.
    VOLATILE UINT16                monArfcn;                     //0x000004FE
    VOLATILE UINT8                 monBand;                      //0x00000500
    VOLATILE UINT8                 monExpPow;                    //0x00000501
    /// Parameters for audio commands from the remote calibration tools. This parameter
    /// is used to select the Audio Interface to calibrate
    VOLATILE UINT8                 itfSel;                       //0x00000502
    /// This field selects which input (microphone) is used on the Audio Interface
    /// defined by the itfSel field.
    VOLATILE UINT8                 inSel;                        //0x00000503
    VOLATILE UINT8                 inGain;                       //0x00000504
    VOLATILE UINT8                 inUart;                       //0x00000505
    /// This field selects which input (speaker) is used on the Audio Interface defined
    /// by the itfSel field.
    VOLATILE UINT8                 outSel;                       //0x00000506
    VOLATILE UINT8                 outGain;                      //0x00000507
    VOLATILE UINT8                 polyGain;                     //0x00000508
    VOLATILE UINT8                 sideGain;                     //0x00000509
    VOLATILE UINT16                outFreq;                      //0x0000050A
    VOLATILE UINT8                 outAmpl;                      //0x0000050C
    VOLATILE UINT8                 startAudioDictaphone;         //0x0000050D
    VOLATILE UINT8                 audioDictaphoneStatus;        //0x0000050E
    /// Command to start the custom calibration of the PMD. This value is given to
    /// the pmd_CustomCalibration() function. This is initialized by the stub and
    /// written by the HST.
    VOLATILE UINT8                 pmdCustomCalibStart;          //0x0000050F
    /// Status of the custom calibration of the PMD. This is initialized by the HST
    /// and returned by the stub.
    VOLATILE UINT32                pmdCustomCalibStatus;         //0x00000510
    /// Rx slot number on TCH.
    VOLATILE UINT16                tn;                           //0x00000514
} CALIB_STUB_CTX_T; //Size : 0x518



// ============================================================================
// CALIB_CALIBRATION_T
// -----------------------------------------------------------------------------
/// This struct will contain pointers to the calibration info and to the struct where
/// to put the calibration context requests. It also contains the address of the
/// calibration sector in flash.
// =============================================================================
typedef struct {
    CALIB_VERSION_TAG_T            codeVersion;                  //0x00000000
    CALIB_PARAM_STATUS_T           paramStatus;                  //0x00000004
    CALIB_COMMAND_T                command;                      //0x00000008
    CALIB_OP_INFO_T*               opInfo;                       //0x0000000C
    CALIB_XCV_T*                   xcv;                          //0x00000010
    CALIB_PA_T*                    pa;                           //0x00000014
    CALIB_SW_T*                    sw;                           //0x00000018
    CALIB_BB_T*                    bb;                           //0x0000001C
    VOLATILE CALIB_OP_INFO_T*      hstOpInfo;                    //0x00000020
    VOLATILE CALIB_XCV_T*          hstXcv;                       //0x00000024
    VOLATILE CALIB_PA_T*           hstPa;                        //0x00000028
    VOLATILE CALIB_SW_T*           hstSw;                        //0x0000002C
    VOLATILE CALIB_BB_T*           hstBb;                        //0x00000030
    VOLATILE CALIB_STUB_CTX_T*     stubCtx;                      //0x00000034
    CONST CALIB_BUFFER_T*          flash;                        //0x00000038
    VOLATILE CALIB_STUB_NST_CTX_T* stubNsftCtx;                  //0x0000003C
} CALIB_CALIBRATION_T; //Size : 0x40





//------------------------------------------------------------------------------
// Defines
//------------------------------------------------------------------------------

#define CALIB_MAJ_MASK(x) ((x >> 8) & 0xFF)
#define CALIB_MIN_MASK(x) (x & 0xFF)
#define CALIB_MARK_MASK(x) (x & 0xFFFF0000)
#define CALIB_VERSION(maj, min) (CALIB_MARK_VERSION | maj << 8 | min << 0)


//------------------------------------------------------------------------------
// Functions
//------------------------------------------------------------------------------

//=============================================================================
// calib_DaemonInit
//-----------------------------------------------------------------------------
/// At boot time, if the CALIB_TAG_CALIBRATED is in the validTag field of
/// the calibration flash sector, Calib uses the calibrated parameters
/// (i.e. the parameters present in the calib flash sector), else Calib
/// uses the default parameters.
/// @par
/// If the code has been compiled with the calibration mode flag set, at boot
/// time, this function also uses the remote parameters RAM buffer and copy
/// the default parameters in it.
/// @par
/// This must be called in the PAL initialization, after the initialization
/// of the RF drivers.
//=============================================================================
PUBLIC VOID calib_DaemonInit(VOID);

//=============================================================================
// calib_DaemonProcess
//-----------------------------------------------------------------------------
/// Execute the calibration commands received by the remote calib tools. This
/// will, usually, update the calibration buffers with new values provided by
/// the user controlling the calib tools.
/// @par
/// This must be called in the PAL start frame.
//=============================================================================
PUBLIC VOID calib_DaemonProcess(VOID);

//=============================================================================
// calib_GetPointers
//-----------------------------------------------------------------------------
/// Access to the calibration parameters.
///
/// @return The global pointers used by the code to access the calibrated
/// parameters. When the target's flash does not contain a flash sector,
/// the calib parameters are initialized with default parameters during
/// the calibration init. Also returns the pointers used by the remote
/// calibration tools to get the version number of the calibration and to
/// find the calibration buffers.
//=============================================================================
PUBLIC CALIB_CALIBRATION_T* calib_GetPointers(VOID);



//=============================================================================
// calib_SetStubContext
//-----------------------------------------------------------------------------
/// Used by the Calib Stub to define the calibration context structure that
/// the remote calibration tools must use to communicate with the Calib Stub.
///
/// @param ctx Pointer to the context where the remote calib tools must put
/// its calibration command to be executed by the Calib Stub.
//=============================================================================
PUBLIC VOID calib_SetStubContext(CONST CALIB_STUB_CTX_T *ctx);



//=============================================================================
// calib_SetXcvDefaults
//-----------------------------------------------------------------------------
/// Used by the transceiver RF driver to set its default calibration parameters
/// (see #calib_DaemonInit to know when they can be used). It must be called
/// during the RF transceiver driver initialization.
///
/// @param param Pointer to a structure containing the default values to be
/// used by this transceiver model.
//=============================================================================
PUBLIC VOID calib_SetXcvDefaults(CONST CALIB_XCV_T* param);



//=============================================================================
// calib_SetPaDefaults
//-----------------------------------------------------------------------------
/// Used by the PA RF driver to set its default calibration parameters
/// (see #calib_DaemonInit to know when they can be used). It must be called
/// during the RF PA driver initialization.
///
/// @param param Pointer to a structure containing the default values to be
/// used for this PA model.
//=============================================================================
PUBLIC VOID calib_SetPaDefaults(CONST CALIB_PA_T* param);



//=============================================================================
// calib_SetSwDefaults
//-----------------------------------------------------------------------------
/// Used by the switch RF driver to set the default calibration parameters
/// (see #calib_DaemonInit to know when they can be used). It must be called
/// during the RF switch driver initialization.
///
/// @param param Pointer to a structure containing the default values to be
/// used for this switch model.
//=============================================================================
PUBLIC VOID calib_SetSwDefaults(CONST CALIB_SW_T* param);



//=============================================================================
// calib_DaemonTracePrint
//-----------------------------------------------------------------------------
/// Display in the trace the current calibration status, used for debug.
//=============================================================================
PUBLIC VOID calib_DaemonTracePrint(VOID);



// =============================================================================
// calib_DaemonSetContext
// -----------------------------------------------------------------------------
/// Defines the context structure that HST and CES must use.
/// @param ctx Pointer to the context to use.
// =============================================================================
PUBLIC VOID calib_DaemonSetContext(VOID* ctx);



// =============================================================================
// calib_DaemonUsrDataProcess
// -----------------------------------------------------------------------------
/// Apply and burn HST calibration buffer.
/// @return TRUE if success, and FALSE otherwise.
// =============================================================================
PUBLIC BOOL calib_DaemonUsrDataProcess(VOID);



// =============================================================================
// calib_GetRfCalibStatus
// -----------------------------------------------------------------------------
/// Get the status of RF calibration data.
/// @return 0 if calibrated with good CRC, 1 if calibrated with bad CRC,
///         2 if not calibrated.
// =============================================================================
PUBLIC UINT8 calib_GetRfCalibStatus(VOID);



// =============================================================================
// calib_GetAudioCalibStatus
// -----------------------------------------------------------------------------
/// Get the status of audio calibration data.
/// @return 0 if calibrated, 2 if not calibrated.
// =============================================================================
PUBLIC UINT8 calib_GetAudioCalibStatus(VOID);



/// @} // end of calib group



#endif

