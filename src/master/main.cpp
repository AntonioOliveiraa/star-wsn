#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ESPmDNS.h>
#include <FS.h>
#include "SPIFFS.h"

const char* ssid = "ESP32_Master";
const char* password = "password_1234";

AsyncWebServer server(80);

String temperature1, temperature2, temperature3;

void setup() {
  Serial.begin(115200);

  // Initialize SPIFFS
  if(!SPIFFS.begin()){
    Serial.println("An error occurred while mounting SPIFFS");
    return;
  }
  
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
  
  // Start mDNS with the name "iot-laps.local"
  if (MDNS.begin("iot-laps")){
    Serial.println("mDNS started");
  }
  
  // Route to receive data from ESP32 Slave 1
  server.on("/data/esp32_slave1", HTTP_POST, [](AsyncWebServerRequest *request){
    temperature1 = request->arg("temperature");
    Serial.print("Received temperature from ESP32 Slave 1: ");
    Serial.println(temperature1);
    request->send(200);
  });

  // Route to receive data from ESP32 Slave 2
  server.on("/data/esp32_slave2", HTTP_POST, [](AsyncWebServerRequest *request){
    temperature2 = request->arg("temperature");
    Serial.print("Received temperature from ESP32 Slave 2: ");
    Serial.println(temperature2);
    request->send(200);
  });

  // Route to receive data from ESP32 Slave 3
  server.on("/data/esp32_slave3", HTTP_POST, [](AsyncWebServerRequest *request){
    temperature3 = request->arg("temperature");
    Serial.print("Received temperature from ESP32 Slave 3: ");
    Serial.println(temperature3);
    request->send(200);
  });

  server.on("/sensors", HTTP_GET, [](AsyncWebServerRequest *request){
    String json = "{";

    json += "\"temperature1\":" + String(temperature1) + ",";
    json += "\"temperature2\":" + String(temperature2) + ",";
    json += "\"temperature3\":" + String(temperature3);

    json += "}";
    request->send(200, "application/json", json);
    });

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", String(), false);
  });

  // Route to load highcharts.js file
  server.on("/highcharts.js", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/highcharts.js", "text/javascript");
  });

  server.begin();
}

void loop() {
}
