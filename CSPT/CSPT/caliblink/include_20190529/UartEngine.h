/* Copyright (C) 2015 RDA Technologies Limited and/or its affiliates("RDA").
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

#ifndef __UART_ENGINE_H_INCLUDED__
#define __UART_ENGINE_H_INCLUDED__

#include <Windows.h>
#include <QMutex>
#include <QString>
#include <QStringList>
#include <stdint.h>
#include "NmeaParser.h"

#define RXP_LF_DATA         0x0A
#define RXP_CR_DATA         0x0D
#define RXP_START_NMEA      0x24

#define NMEA_ID_QUE_SIZE    0x0100
#define NMEA_RX_QUE_SIZE    0x1000
#define SKIP_BYTE_QUE_SIZE  0x0001000

typedef enum {
    RXS_PRM,                // receive preamble
    RXS_DAT,                // receive NMEA data
    RXS_ETX,                // End-of-packet
} RX_SYNC_STATE_T;

typedef union {                     /* instrumentation status data      */
    unsigned short  all;            /* all fields                       */
    struct {
        unsigned short  inst_ovfl  : 1;
        unsigned short  inst_avail : 1;
        unsigned short  :14;
    } f;
} rxp_inst_stat_type;

class CALIBLINK_API UartDataCtrl
{
public:
    UartDataCtrl() {}
    ~UartDataCtrl() {}

    bool rxp_init_pcrx(void);
    void rxp_exit_pcrx(void);
    bool rxp_inst_avail(short *inst_id, short *dat_idx, short *dat_siz);
    void rxp_get_inst(short idx, short size, void *data);
    void rxp_pcrx_nmea(unsigned char data);

private:
    struct {
        short   inst_id;  // 1 - NMEA
        short   dat_idx;
        short   dat_siz;
    } id_que[NMEA_ID_QUE_SIZE];

    unsigned char rx_que[NMEA_RX_QUE_SIZE];
    unsigned short id_que_head;
    unsigned short id_que_tail;
    unsigned short rx_que_head;
    RX_SYNC_STATE_T rx_state;
    unsigned short int u2PktLength;
    rxp_inst_stat_type inst_stat;

    unsigned int u4SyncPkt;
    unsigned int u4OverflowPkt;
    unsigned int u4PktInQueue;
    unsigned int u4SkipByte;
    unsigned int u4SkipCRLFByte;
    int i4Que_Skip_Idx;
    unsigned char Que_Skip[SKIP_BYTE_QUE_SIZE];
};


typedef struct {        //NMEA Format structure
    short int i2PacketType;  // 1: NMEA,  2: DEBUG, 3: HBD, 4: BIN
    short int i2PacketSize;
    NMEA_STN_T eType;
    char Data[NMEA_EX_LENGTH];
} NMEA_STN_DATA_T;

class CALIBLINK_API UartDataP
{
public:
    UartDataP() {}
    ~UartDataP() {}

    void ResetNmeaData();
    void DetermineStnType();
    void Invalid_Pre_STN_Data(NMEA_STN_T eThis_STN, NMEA_STN_T eLast_STN);
    void Invalid_Pre_GSV_Data(void);
    void GNGSA_Assign_From_GPGSA(GNSS_GSA_T *rgngsa, NMEA_GSA_T *rgpgsa);
    void GNGSA_Assign_From_QSA(GNSS_GSA_T *rgngsa, NMEA_QSA_T *rqsa);
    void GNGSV_Assign_From_GSV(GNSS_GSV_T *rgngsv, NMEA_GSV_T *rgsv);
    void ProcNmeaSentence();

    NMEA_STN_DATA_T rRawData;     //Output Sentence
    bool fgHasValidGSV;
    GNSS_GSV_T      rSGNGSV;

private:
    NMEA_GGA_T      rSGPGGA;
    NMEA_GLL_T      rSGPGLL;
    GNSS_GSA_T      rSGNGSA;
    NMEA_GSV_T      rsgpgsv;
    //GNSS_GSV_T        rSGNGSV;
    NMEA_RMC_T      rSGPRMC;
    NMEA_VTG_T      rSGPVTG;
    NMEA_STN_T m_eLastDecodedSTN;
};

//================== UartEngine ==================
class CALIBLINK_API UartEngine
{
public:
    UartEngine();
    ~UartEngine();

    int open(const QString& deviceName);
    int close();

    bool setBaudRate(int baud);
    bool setFlowCtrl(int flowCtrl);

    int getBaudRate() const {
        return mBaudRate;
    }
    int getFlowCtrl() const {
        return mFlowCtrl;
    }

    uint32_t getDefaultReadTimeout() {
        return mDefaultReadTimeoutMs;
    }
    uint32_t getDefaultWriteTimeout() {
        return mDefaultWriteTimeoutMs;
    }

    int read(void* data, size_t len, uint32_t timeoutMs);
    int write(const void* data, size_t len, uint32_t timeoutMs);
    int flush();

private:
    bool setState();

    HANDLE mComDev;
    OVERLAPPED mOsReader;
    OVERLAPPED mOsWriter;

    int mBaudRate;
    int mFlowCtrl;
    uint32_t mDefaultReadTimeoutMs;
    uint32_t mDefaultWriteTimeoutMs;

    QMutex mLock;
};

#endif
