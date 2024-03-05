#ifndef MQTT_APP_H
#define MQTT_APP_H

#include "device_app.h"

void mqtt_app_init();
void mqtt_app_client_publish(device_app* p_app);
void mqtt_app_client_subcribe(device_app* p_app);
void mqtt_status_checking();

#endif