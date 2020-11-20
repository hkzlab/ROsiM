#ifndef _DATA_BUFFER_HEADER_
#define _DATA_BUFFER_HEADER_

#include <stdint.h>

#define SIPO_BUFFER_SIZE 5
uint8_t sipo_buffer[SIPO_BUFFER_SIZE];

void clear_sipo_buffer(void);

void address_to_sipo_buffer(uint32_t address);
void data_to_sipo_buffer(uint16_t data);


#endif /* _DATA_BUFFER_HEADER_ */