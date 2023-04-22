#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <Update.h>

#define ledPin 2

void setup(void) {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}
void loop(void) {
  
  digitalWrite(ledPin, HIGH);
  delay(500);
 
  digitalWrite(ledPin, LOW);
  delay(500);
}