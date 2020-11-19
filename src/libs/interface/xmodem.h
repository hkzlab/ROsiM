#ifndef _XMODEM_H_
#define _XMODEM_H_

#include <stdint.h>

typedef enum {
    BIN_8 = 0,
    BIN_16 = 1,
    BIN_16S = 2
} XMODEM_Dump_Type;

uint8_t xmodem_xfor(XMODEM_Dump_Type dtype);

#endif /* _XMODEM_H_ */