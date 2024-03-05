#include "HX711.h"
#include "loadcell.h"
#include "app_config.h"
#include "flash.h"
#include "Arduino.h"

HX711 loadcell;

const int LOADCELL_DOUT_PIN = LOADCELL_DOUT_PIN_CFG;
const int LOADCELL_SCK_PIN = LOADCELL_SCK_PIN_CFG;

void loadcell_init();
void loadcell_tare();
void loadcell_calib();
int loadcell_get_mass_handle();

void loadcell_init(){
    loadcell.begin(LOADCELL_DOUT_PIN,LOADCELL_SCK_PIN);
    loadcell_calib();
    loadcell_tare();
}

void loadcell_tare(){
    loadcell.tare();
}

void loadcell_calib(){
    // uint32_t calib_coef;
    // if (flash_read_data(calib_coef, CALIB_COEFFICIENT_FLASH_ADD)){
    //     loadcell.set_scale(calib_coef); 
    // }
    loadcell.set_scale(CALIB_COEFFICIENT); 
}

int loadcell_get_mass_handle(){
    if(!loadcell.is_ready())
        return 0;
    int mass = (int) loadcell.get_units(1);
    return mass;
}

void loadcell_recalib(){
    delay(1000);
    long t1 = loadcell.read();
    delay(5000);
    long t2 = loadcell.read();
    uint32_t calib_coef = (t2-t1)/MASS_DEFAULT_FOR_CALIB;
    // (void) flash_write_data(calib_coef, CALIB_COEFFICIENT_FLASH_ADD);
    loadcell_calib();
}