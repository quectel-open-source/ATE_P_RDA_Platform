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

#ifndef __FLASH_PROGRAM_H_INCLUDED__
#define __FLASH_PROGRAM_H_INCLUDED__

#include "fplink_export.h"
#include "TargetConnection.h"
#include "ChipInfo.h"
#include <QList>
#include <QObject>
#include <stdint.h>

class LodData;

#ifndef FLASH_PROGRAM_INTERNAL
typedef void FLASH_PROG_MAP_ACCESS_T;
typedef void FPC_COMMAND_DATA_T;
#endif

class FPLINK_API FlashProgram: public QObject
{
    Q_OBJECT
public:
    FlashProgram(TargetConnection* conn, ChipInfo* chip, QObject* parent = nullptr);
    ~FlashProgram();

    int checkStart();
    int run(LodData* lod, bool checkBootFlag, bool NeedLodEnd, bool flashtest=false);
    int program(LodData* lod);
    int verify(LodData* lod, bool checkBootFlag, bool NeedLodEnd = true);
    int erase(uint32_t flashAddress, uint32_t size);
    int overwrite(uint32_t flashAddress, uint8_t* data, uint32_t size);
    int checkFcs(uint32_t flashAddress, uint32_t size, uint32_t fcs);
    int checkFcs(int num, uint32_t* flashAddress, uint32_t* size, uint32_t* fcs);

    int factRead(uint32_t flashAddress, void* data);
    int factWrite(uint32_t flashAddress, void* data);
    void stop() {
        mProgramStopReq = true;
    }

    void setWaitEventTimeout (uint32_t waitEventTimeout);
    void setPreferEraseProgramTime (uint32_t eraseProgramTime);

    int shutDownChip();
    int RestartChip();

Q_SIGNALS:
    void programProgress(int percent);
    void eraseProgramTimeTooLong();
    void eraseProgramTime(int time, bool sectorsize);

private:
    int getAccess();
    int lodProgram();
    int flashtestlodProgram();
    int lodVerify();
    int lodEnd();
    int checkBootMagic();
    int sendFpdCommand(FPC_COMMAND_DATA_T* cmd);
    int waitFpcCommandDone();

    LodData* mLod; // not hold by me
    TargetConnection* mConn; // not hold by me
    ChipInfo* mChip; // not hold by me

    target_address_t mAccessAddress;
    FLASH_PROG_MAP_ACCESS_T* mAccess;
    void* mFF2K;
    bool mUidEventAfterReady;
    uint32_t mEncryptUid;
    uint32_t mWaitStartTimeout;
    uint32_t mWaitEventTimeout;
    uint32_t mPreferEraseProgramTime;
    QList<uint32_t> mStartEvents;
    QList<uint32_t> mReadyEvents[2];

    int mCmdIndex;
    int mCmdPending;
    qint64 mStartMsec;

    volatile bool mProgramStopReq;
};

#endif
