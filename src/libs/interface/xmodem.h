#ifndef _XMODEM_H_
#define _XMODEM_H_

#include <stdint.h>

typedef enum {
    BIN_8 = 0,
    BIN_16 = 1,
    BIN_16S = 2
} XMODEM_Dump_Type;

#define SOH     0x01
#define EOT     0x04
#define ACK     0x06
#define NACK    0x15
#define C_CHR   0x43

#define XMODEM_PKT_SIZE 133

static uint8_t packet_buf[XMODEM_PKT_SIZE];
static int16_t last_pkt = -1;

uint8_t xmodem_recv(XMODEM_Dump_Type dtype);

#endif /* _XMODEM_H_ */