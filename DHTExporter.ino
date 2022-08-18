
#include "Arduino.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <DHT.h>


#define DATAPIN 2
#define DHTTYPE DHT11     
DHT dht(DATAPIN, DHTTYPE);

const char* ssid = "WIFISSID";
const char* password = "PASSWORD?u";
 
ESP8266WebServer server(8663); //SEREVER ON PORT 8663

void metrics() {  
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
    server.send(200, "text", "\dhtexp_temperature\ "+String(temperature)+"\n"+"\dhtexp_humidity\ "+String(humidity));
}
 
void restServerRouting() {
    server.on("/", HTTP_GET, []() {
        server.send(200, F("text/html"),
            F("Get all data at /metrics"));
    });
    server.on(F("/metrics"), HTTP_GET, metrics);
}
 
 
void setup(void) {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  restServerRouting();
  server.begin();
  Serial.println("HTTP server started");
}
 
void loop(void) {
  server.handleClient();
}
