#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <Update.h>

#define ledPin 2

void loop(void) {
  server.handleClient();
  
  digitalWrite(ledPin, HIGH);
  delay(1000);
 
  digitalWrite(ledPin, LOW);
  delay(1000);
}