#ifndef FLASH_H
#define FLASH_H

#include"stdlib.h"

uint8_t flash_write_data(uint32_t buffer, uint32_t address);
uint8_t flash_read_data(uint32_t buffer, uint32_t address);

#endif