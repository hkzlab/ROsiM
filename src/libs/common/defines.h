#ifndef _AVR_DUPAL_DEFINES_
#define _AVR_DUPAL_DEFINES_

#define _NOP() do { __asm__ __volatile__ ("nop"); } while (0)

// token pasting
#define token_paste2_int(x, y) x ## y
#define token_paste2(x, y) token_paste2_int(x, y)
#define token_paste3_int(x, y, z) x ## y ## z
#define token_paste3(x, y, z) token_paste3_int(x, y, z)

#endif /* _AVR_DUPAL_DEFINES_ */
