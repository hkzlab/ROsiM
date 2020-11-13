#ifndef _SIPO_SHIFTER_HEADER_
#define _SIPO_SHIFTER_HEADER_

#include <stdint.h>

// Clears the shifters and enable their outputs
void sipo_shifter_init(void);

void sipo_shifter_set(uint8_t *data, uint8_t len);
void sipo_shifter_OE(uint8_t status);

#endif /* _SIPO_SHIFTER_HEADER_ */