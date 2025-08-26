#ifndef __NMEAPSRSER_H__
#define __NMEAPSRSER_H__

#include "caliblink_export.h"

//---------------------------------------------------------------------------
#define MPS_TO_KNOTS    1.9438400f // m/s to knots
#define KNOTS_TO_MPS    0.5144456f // knots to m/s

//---------------------------------------------------------------------------
#define NMEA_STD_LENGTH     82
#define NMEA_EX_LENGTH      256  // In order to support YLS proprietary sentence
#define NMEA_MAX_GPS_ID     32
#define NMEA_MAX_GNSS_ID    254 // instead of 255, to remove warning
#define NMEA_MAX_ARG_NUM    72
#define NMEA_ARG_MAX_LENGTH 16

//---------------------------------------------------------------------------
#define YLS_DBG_FLAG_SIZE   32
#define YLS_DBG_I1_SIZE     8
#define YLS_DBG_R4_SIZE     6
#define YLS_DB2_U2_SIZE     8
#define YLS_DB2_R4_SIZE     8
#define NUM_PSEUDO_CHNL     32
#define NMEA_MAX_NUM_SVVIEW 32
//#define NMEA_MAX_NUM_SVUSED 12 // GPS only
#define NMEA_MAX_NUM_SVUSED 32 // GPS + GLONASS, two GNGSA sentences

//---------------------------------------------------------------------------
typedef enum {
    GNSS_TYPE_GPS     = 0,
    GNSS_TYPE_QZSS    = 1,
    GNSS_TYPE_GALILEO = 2,
    GNSS_TYPE_GLONASS = 3,
    GNSS_TYPE_BEIDOU  = 4,
    GNSS_TYPE_SBAS    = 5,
    GNSS_TYPE_GNSS    = 10
} GNSS_ID_TYPE_T;

typedef enum {
    STN_GGA = 0,
    STN_GLL = 1,
    STN_GSA = 2,
    STN_GSV = 3,
    STN_RMC = 4,
    STN_VTG = 5,
    STN_QSA = 6,
    STN_OTHER = 255,
} NMEA_STN_T;

//---------------------------------------------------------------------------
typedef struct {            //GPGGA -- Global Positioning System Fix Data
    unsigned short int u2UtcHour;
    unsigned short int u2UtcMin;
    float fUtcSec;
    double dfLatitude;
    short int i2LatDeg;
    short int i2LatMin;
    double dfLatSec;
    char cNS;
    double dfLongitude;
    short int i2LonDeg;
    short int i2LonMin;
    double dfLonSec;
    char cEW;
    unsigned short int u2PosFixQuality;
    unsigned short int u2SatUsed;
    float fHdop;
    float fAlt;
    float fGeoidal;
    float fDgpsAge;
    short int i2StationID;
} NMEA_GGA_T;


typedef struct {            //GPGLL -- Geographic Position - Latitude/Longitude
    short int i2LatDeg;
    double dfLatMin;
    char cNS;
    long int i2LonDeg;
    double dfLonMin;
    char cEW;
    char szUtcTime[16];
    char cStatus;
    char cMode;
} NMEA_GLL_T;


typedef struct {            //GPGSA -- GNSS DOP and Active Satellites
    GNSS_ID_TYPE_T eGnssType; // 0 - GPS, 1 - QZSS, 2 - GALILEO, 3 - GLONASS,4 - BEIDOU
    char cOpMode;
    char cFixMode;
    short int i2NumActive;
    unsigned short int u2SatID[NMEA_MAX_NUM_SVUSED];
    float fPDOP;
    float fHDOP;
    float fVDOP;
} NMEA_GSA_T;


typedef struct {            //GP/QZ QSA -- GNSS DOP and Active Satellites
    GNSS_ID_TYPE_T eGnssType; // 0 - GPS, 1 - QZSS
    char cGnssMode;  // 'S' = Single GNSS solution; 'M' = Multi-GNSS solution
    char cOpMode;
    char cFixMode;
    short int i2NumActive;
    unsigned short int u2SatID[NMEA_MAX_NUM_SVUSED];
    float fPDOP;
    float fHDOP;
    float fVDOP;
} NMEA_QSA_T;

typedef struct {            //GNSS GSA -- GNSS DOP and Active Satellites
#if 1
    short int i2NumGNSS;
    unsigned short int u2ActiveGNSS[4];
#endif
    char cOpMode;
    char cFixMode;
    short int i2NumActive;
    unsigned short int u2SatID[NMEA_MAX_NUM_SVUSED];
    GNSS_ID_TYPE_T eGnssType[NMEA_MAX_NUM_SVUSED];
    float fPDOP;
    float fHDOP;
    float fVDOP;
} GNSS_GSA_T;


typedef struct {
    unsigned short int u2SatID;
    short int i2Elv;
    short int i2Azi;
    short int i2SNR;
    GNSS_ID_TYPE_T eGnssType;
} GSV_SV_STATUS_T;

typedef struct {            //GPGSV -- GNSS Satellites in View
    GNSS_ID_TYPE_T eGnssType; // 0 - GPS, 1 - QZSS, 2 - GALILEO, 3 - GLONASS
    short int i2NumMsg;
    short int i2MsgSqn;
    short int i2SatView;
    short int i2MaxSNR;
    short int i2MinSNR;
    short int i2NumSVTrk;
    short int i2SatNum;
    GSV_SV_STATUS_T rSv[4];
} NMEA_GSV_T;

typedef struct {            //GNSS GSV -- GNSS Satellites in View
#if 1
    short int i2NumGNSS;
    GNSS_ID_TYPE_T eGnssType[4];
#endif
    short int i2MaxSNR;
    short int i2MinSNR;
    short int i2NumSVTrk;
    short int i2SatNum;
    GSV_SV_STATUS_T rSv[NMEA_MAX_NUM_SVVIEW];
} GNSS_GSV_T;

typedef struct {            //GPRMC -- Recommended Minimum Specific GNSS Data
    unsigned short int u2UtcHour;
    unsigned short int u2UtcMin;
    float fUtcSec;
    char cStatus;
    short int i2LatDeg;
    double dfLatMin;
    char cNS;
    long int i2LonDeg;
    double dfLonMin;
    char cEW;
    float fSpeed; // Speed over ground [knots]
    float fCourse;
    unsigned short int u2UtcYear;
    unsigned short int u2UtcMonth;
    unsigned short int u2UtcDay;
    float fMagVar;
    char cMagEW;
    char cmode;
} NMEA_RMC_T;


typedef struct {
    float fTrueHeading;
    float fMagHeading;
    float fHSpeedKnot;
    float fHSpeedKm;
    char cMode;
} NMEA_VTG_T;


//---------------------------------------------------------------------------
// Public Function
//---------------------------------------------------------------------------
CALIBLINK_API unsigned char fgNmeaCheckSum(char* pData, long int i4Size);
CALIBLINK_API unsigned char fgNmeaGPGGAParser(char* str, NMEA_GGA_T* gga);
CALIBLINK_API unsigned char fgNmeaGPGLLParser(char* str, NMEA_GLL_T* gll);
CALIBLINK_API unsigned char fgNmeaGPGSAParser(char* str, NMEA_GSA_T* gsa);
CALIBLINK_API unsigned char fgNmeaGPQSAParser(char* str, NMEA_QSA_T* qsa);
CALIBLINK_API unsigned char fgNmeaGPGSVParser(char* str, NMEA_GSV_T* gsv);
CALIBLINK_API unsigned char fgNmeaGPRMCParser(char* str, NMEA_RMC_T* rmc);
CALIBLINK_API unsigned char fgNmeaGPVTGParser(char* str, NMEA_VTG_T* vtg);
CALIBLINK_API long int i4FindSubField(char* str, char sub[][NMEA_ARG_MAX_LENGTH+1]);
CALIBLINK_API long int i4SplitNmeaFields(char* str, char* psub[NMEA_MAX_ARG_NUM]);

#endif
