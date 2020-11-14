#ifndef _STRUTILS_HEADER_
#define _STRUTILS_HEADER_

#include <stdint.h>

#define STR_BUF_SIZE 128
char str_buf[STR_BUF_SIZE];

uint8_t strutils_str_to_u8(char *str);
uint16_t strutils_str_to_u16(char *str);
uint32_t strutils_str_to_u32(char *str);
void strutils_u8_to_str(char *str, uint8_t data);
void strutils_u16_to_str(char *str, uint16_t data);
void strutils_u32_to_str(char *str, uint32_t data);

#endif /* _STRUTILS_HEADER_ */