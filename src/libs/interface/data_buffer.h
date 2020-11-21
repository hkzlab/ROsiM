#ifndef _DATA_BUFFER_HEADER_
#define _DATA_BUFFER_HEADER_

#include <stdint.h>

#define SIPO_BUFFER_SIZE 5

void clear_sipo_buffer(void);
void address_to_sipo_buffer(uint32_t address);
void data_to_sipo_buffer(uint16_t data);
uint8_t *get_sipo_buffer(void);


#endif /* _DATA_BUFFER_HEADER_ */