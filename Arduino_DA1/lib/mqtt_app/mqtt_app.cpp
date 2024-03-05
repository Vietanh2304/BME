#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <MQTT.h>
#include "mqtt_app.h"
#include "LiquidCrystal_I2C.h"
#include "app_config.h"
#include "display_app.h"
#include "device_app.h"
#include <cstring>

const char ssid[] = WIFI_SSID_CONFIG;
const char pass[] = WIFI_PASSWORD_CONFIG;

WiFiClient net;
MQTTClient client;

// static char buffer[1024] = "";

void mqtt_app_init();
void mqtt_app_client_publish(device_app* p_app);
void mqtt_app_client_subcribe(device_app* p_app);

void wifi_connect(){
  Serial.print("Wifi...");
  display_text(0,0,"WIFI...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.print("\nWifi connected!");
  display_text(0,0,"WIFI connected!");
}

void mqtt_connect(){
  Serial.print("\nMQTT broker...");
  display_text(0,1,"MQTT broker...");
  while (!client.connect(MQTT_CLIENT_ID, MQTT_USER_NAME, MQTT_PASSWORD)) {
    Serial.print(".");
    delay(300);
  }
  Serial.print("\nMQTT connected!");
  display_text(0,1,"MQTT connected!");
}
void connect() {
  wifi_connect();
  delay(100);
  mqtt_connect();
  client.subscribe(MQTT_MAIN_TOPIC + "/" + DEVICE_ID);
}

void message_received_callback(String &topic, String &payload) {
  Serial.println(topic + " - " + payload);

  ibme_app.mqtt_rx_data = payload;
}

void mqtt_app_init(){
  WiFi.begin(ssid, pass);
  client.begin(MQTT_BROKER_ADDRESS, net);
  client.setHost(MQTT_BROKER_ADDRESS, MQTT_BROKER_PORT);
  client.onMessage(message_received_callback);
  connect();
}

void mqtt_app_client_publish(device_app* p_app){
  device_app_update_mqtt_tx_data();
  const char* tx_buffer =  p_app->mqtt_tx_data.c_str();
  Serial.println(tx_buffer);
  Serial.println(p_app->mqtt_tx_data.length());
  bool err = client.publish(MQTT_MAIN_TOPIC + "/" + DEVICE_ID, tx_buffer);
  Serial.println(err);
}

void mqtt_app_client_subcribe(device_app* p_app){

}

void mqtt_status_checking(){
  client.loop();
  delay(10);
  if (!client.connected()){
    connect();
  }
}

