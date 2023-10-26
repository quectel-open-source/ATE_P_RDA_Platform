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

#ifndef FPLINK_C_HEADER_H
#define FPLINK_C_HEADER_H

#include "fplink_export.h"


FPLINK_CAPI int fp_init(int port_num);
FPLINK_CAPI int fp_enter_calibration();
FPLINK_CAPI int fp_calib_mode_tx_pcl(unsigned int band, unsigned int arfcn, unsigned int pcl, unsigned int tsc);

FPLINK_CAPI int fp_read32(unsigned int address);
FPLINK_CAPI int fp_write32(unsigned int address, unsigned int value);
FPLINK_CAPI unsigned int fp_get_read_result();

#endif
