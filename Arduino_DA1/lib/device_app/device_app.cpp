#include "device_app.h"
#include "app_config.h"
#include "loadcell.h"
#include "ArduinoJson.h"

void device_app_init();


String buffer;

static void device_app_patient_data_init(){
    ibme_app.device_id = DEVICE_ID;
    ibme_app.patient_data.patient_id = "BN002";
    ibme_app.patient_data.name = "B.Viet.Anh";
    ibme_app.patient_data.age = 20;
    ibme_app.patient_data.bed_id = "4";
    ibme_app.patient_data.room_id = "302";
    ibme_app.is_mqtt_data_new = 0;

}

static void device_app_wifi_init(){
    ibme_app.wifi.ssid =  WIFI_SSID_CONFIG;
    ibme_app.wifi.pass = WIFI_PASSWORD_CONFIG;
    ibme_app.wifi.status =  WIFI_DISCONNECTED;
    ibme_app.wifi.is_changed_req = 0;
    ibme_app.wifi.new_ssid = WIFI_SSID_CONFIG;
    ibme_app.wifi.new_pass = WIFI_PASSWORD_CONFIG;
}

void device_app_update_mqtt_tx_data(){
    String mqtt_pub_string = "";
    DynamicJsonDocument doc(2048);
    // JsonObject DEVICE = doc.createNestedObject("device");
    // DEVICE["id"]            =  ibme_app.device_id;

    JsonObject PATIENT = doc.createNestedObject("patient");
    PATIENT["id"]           = ibme_app.patient_data.patient_id;
    PATIENT["name"]         = ibme_app.patient_data.name;
    PATIENT["age"]          = ibme_app.patient_data.age;
    PATIENT["bed"]          = ibme_app.patient_data.bed_id;
    PATIENT["room"]         = ibme_app.patient_data.room_id;

    // JsonObject WIFI = doc.createNestedObject("wifi");
    // WIFI["ssid"]            =    (String)ibme_app.wifi.ssid;
    // WIFI["pass"]            =    (String)ibme_app.wifi.pass;
    // WIFI["new_ssid"]        =    (String)ibme_app.wifi.new_ssid;
    // WIFI["new_pass"]        =    (String)ibme_app.wifi.new_pass;
    // WIFI["is_changed_req"]  =   ibme_app.wifi.is_changed_req;

    JsonObject LOADCELL = doc.createNestedObject("loadcell");
    LOADCELL["volume"]      =   ibme_app.loadcell.volume;
    // LOADCELL["scale_value"] =   ibme_app.loadcell.scale_value;
    // LOADCELL["is_calibed"]  =   (uint16_t)ibme_app.loadcell.is_calibrated;


    mqtt_pub_string = "";
    serializeJson(doc, mqtt_pub_string);

    ibme_app.mqtt_tx_data = mqtt_pub_string;
    Serial.print(ibme_app.mqtt_tx_data);
}

void device_app_init(){
    device_app_patient_data_init();
    device_app_wifi_init();
    ibme_app.loadcell.loadcell_get_mass = loadcell_get_mass_handle;
    device_app_update_mqtt_tx_data();
}