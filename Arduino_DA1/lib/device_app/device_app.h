#ifndef DEVICE_APP_H
#define DEVICE_APP_H

#include "Arduino.h"
#include <stdlib.h>
#include "loadcell.h"

struct patient_data_t{
    String patient_id;
    String name;
    uint8_t age;
    String bed_id;
    String room_id;
    bool is_new_data;

};

enum wifi_status {
    WIFI_DISCONNECTED = 0,
    WIFI_CONNECTED,
    WIFI_PRE_UPDATE,
    WIFI_UPDATING,
    WIFI_UPDATED,
    WIFI_UPDATE_FAIL
};

struct wifi_infor_t {
    enum wifi_status status;
    String ssid;
    String pass;
    uint8_t is_changed_req;
    String old_ssid;
    String old_pass;
    String new_ssid;
    String new_pass;
};


enum device_state {
    APP_SETUP = 0,
    APP_IDLE,
    APP_ACTIVE
};

typedef struct device_app_t{
    String device_id;
    patient_data_t patient_data;
    enum device_state state;
    String mqtt_rx_data;
    String mqtt_tx_data;
    LOADCELL loadcell;
    wifi_infor_t wifi;
    bool is_mqtt_data_new;
}device_app;

extern device_app ibme_app;

void device_app_init();
void device_app_update_mqtt_tx_data();
#endif