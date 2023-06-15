

#include <WiFi.h>
#include <Update.h>
#include "OTAUpdateModule.h"


#define ledPin 2

WiFiClient client;
const char* SSID = "Pixel";
const char* PSWD = "87654321";

float firmware=1.1;
String host = "bucketwithota.s3.ap-south-1.amazonaws.com";
int port = 80;
String bin = "/updated.bin";


void setup() {
  //Begin Serial
  Serial.begin(115200);
  delay(10);

  Serial.println("Connecting to " + String(SSID));

  // Connect to provided SSID and PSWD
  WiFi.begin(SSID, PSWD);

  // Wait for connection to establish
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("."); // Keep the serial monitor lit!
    delay(500);
  }

  // Connection Succeed
  Serial.println("");
  Serial.println("Connected to " + String(SSID));

  // Execute OTA Update
  Serial.print("firmware number : ");
  Serial.println(firmware);
  //execOTA();
  execOTA( client,  host ,  bin , port);
  pinMode(ledPin, OUTPUT);
}

void loop(void) {
  
  digitalWrite(ledPin, HIGH);
  delay(600); 
  digitalWrite(ledPin, LOW);
  delay(100);
  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(ledPin, LOW);
  delay(100);
  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(ledPin, LOW);
  delay(100);
  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(ledPin, LOW);
  delay(100);
  digitalWrite(ledPin, HIGH);
  delay(100);
}
