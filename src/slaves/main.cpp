#include <WiFi.h>
#include <HTTPClient.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4 // Sets the pin for OneWire communication
#define LED_PIN 2 // Sets the pin internal LED

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

const char* ssid = "ESP32_Master";
const char* password = "password_1234";

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    digitalWrite(LED_PIN, LOW); // Makes the GPIO LED blink indicating it is connecting to WiFi
    Serial.println("Connecting to WiFi..");
    delay(500);
    digitalWrite(LED_PIN, HIGH);
  }
  Serial.println("Connected to WiFi");
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0);
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  if (temperature != DEVICE_DISCONNECTED_C) {
    HTTPClient http;
    // Modify the route according to the Master IP and ESP32 Slave number
    // http.begin("http://ESP32_Master_IP:80/data/esp32_slave1"); // Default
    http.begin("http://192.168.4.1:80/data/esp32_slave3"); // Real
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    String postData = "temperature=" + String(temperature);
    int httpResponseCode = http.POST(postData);
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    http.end();
  }
  delay(2000); // Data collection interval
}
