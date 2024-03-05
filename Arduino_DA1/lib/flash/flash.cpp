#include "flash.h"
#include "EEPROM.h"
#include "stdlib.h"

uint8_t flash_write_data(uint32_t buffer, uint32_t address);
uint8_t flash_read_data(uint32_t buffer, uint32_t address);

void flash_init(){
    EEPROM.begin(1024);
}

uint8_t flash_write_data(uint32_t buffer, uint32_t address){
    EEPROM.put(address, buffer);
    return EEPROM.commit();
}

uint8_t flash_read_data(uint32_t buffer, uint32_t address){
    EEPROM.get(address, buffer);
    return EEPROM.commit();
}
