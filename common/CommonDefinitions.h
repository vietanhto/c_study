#ifndef COMMON_COMMONDEFINITIONS_H_
#define COMMON_COMMONDEFINITIONS_H_

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef char                                    CHAR;
typedef short                                   WCHAR;
typedef uint8_t                                 UINT8;
typedef int8_t                                  INT8;
typedef uint16_t                                UINT16;
typedef int16_t                                 INT16;
typedef uint32_t                                UINT32;
typedef int32_t                                 INT32;
typedef uint64_t                                UINT64;
typedef int64_t                                 INT64;
typedef double                                  DOUBLE;
typedef float                                   FLOAT;
typedef UINT8                                   BYTE;
typedef INT32                                   BOOL;
typedef void                                    VOID;

typedef CHAR*                                   PCHAR;
typedef WCHAR*                                  PWCHAR;
typedef UINT8*                                  PUINT8;
typedef INT8*                                   PINT8;
typedef UINT16*                                 PUINT16;
typedef INT16*                                  PINT16;
typedef UINT32*                                 PUINT32;
typedef INT32*                                  PINT32;
typedef UINT64*                                 PUINT64;
typedef INT64*                                  PINT64;
typedef DOUBLE*                                 PDOUBLE;
typedef FLOAT*                                  PFLOAT;
typedef BYTE*                                   PBYTE;
typedef BOOL*                                   PBOOL;
typedef void*                                   PVOID;

#define COLOR_RESET                             "\x1B[0m"
#define COLOR_RED                               "\x1B[31m"
#define COLOR_GREEN                             "\x1B[32m"
#define COLOR_YELLOW                            "\x1B[33m"
#define COLOR_BLUE                              "\x1B[34m"
#define COLOR_MAGENTO                           "\x1B[35m"
#define COLOR_CYAN                              "\x1B[36m"
#define COLOR_WHITE                             "\x1B[37m"

#define STATUS                                  UINT32
#define STATUS_SUCCESS                          0x00000000
#define STATUS_BASE                             0x00000000
#define STATUS_NULL_ARG                         STATUS_BASE + 0x00000001
#define STATUS_INVALID_ARG                      STATUS_BASE + 0x00000002
#define STATUS_INVALID_ARG_LEN                  STATUS_BASE + 0x00000003

#define CHK(C ,E) do {if(!(C)) {retValue = E; goto CleanUp;}} while (0)

#endif // COMMON_COMMONDEFINITIONS_H_