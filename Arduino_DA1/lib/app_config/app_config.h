#ifndef APP_CONFIG_H
#define APP_CONFIG_H

/*Device configuration*/
#define DEVICE_ID                                   (String)"D002"

/*Wifi configuration*/
#define WIFI_SSID_CONFIG                            "BME"
#define WIFI_PASSWORD_CONFIG                        "12345678"
#define WIFI_SSID_MAX_LENGTH                        32
#define WIFI_PASSWORD_MAX_LENGTH                    32

/*MQTT configuration*/
#define MQTT_BROKER_ADDRESS                         "0.tcp.ap.ngrok.io"
#define MQTT_BROKER_PORT                            15013
#define MQTT_CLIENT_ID                              "D002"
#define MQTT_USER_NAME                              "mqtt_username"
#define MQTT_PASSWORD                               "mqtt_password"
#define MQTT_DATA_SUB_TOPIC                         (String)"Patient_Data"
#define MQTT_APP_CMD_TOPIC                          "App/command"
#define MQTT_MAIN_TOPIC                             (String)"ibme/device"

/*Loadcell configuration*/
#define LOADCELL_DOUT_PIN_CFG                       12  
#define LOADCELL_SCK_PIN_CFG                        13
#define MASS_TO_VOLUME_COEFFICIENT                  1015
#define MASS_DEFAULT_FOR_CALIB                      1000    //gam
#define CALIB_COEFFICIENT                           (uint32_t) 437

/*Other peripherals configuration*/
#define TARE_BUTTON_PIN                             14
#define CALIB_BUTTON_PIN                            6

/*Flash*/
#define MAX_FLASH                                   1024        //bytes 
#define WIFI_SSID_CONFIG_FLASH_ADD                  32
#define WIFI_PASSWORD_CONFIG_FLASH_ADD              64
#define WIFI_SSID_UPDATE_FLASH_ADD                  96
#define WIFI_PASSWORD_UPDATE_FLASH_ADD              128
#define MQTT_BROKER_FLASH_ADD                       160
#define DEVICE_ID_FLASH_ADD                         192
#define CALIB_COEFFICIENT_FLASH_ADD                 224



#endif 