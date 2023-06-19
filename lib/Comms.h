#ifndef COMMS_H
#define COMMS_H

#include "secrets.h"
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include "WiFi.h"

bool connectWiFi(unsigned long timeoutMillis) {
    unsigned long startTime = millis();
    
    timeoutMillis = 3000;
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.println("Connecting to Wi-Fi");
    
    while (WiFi.status() != WL_CONNECTED) {
        if (millis() - startTime > timeoutMillis) {
            Serial.println("WiFi connection failed.");
            return false;
        }
        delay(500);
        Serial.print(".");
    }
    
    Serial.println("Connected to Wi-Fi!");
    return true;
}
//was connectAWS();
void connectAWSIoT(WiFiClientSecure &net, PubSubClient &client, unsigned long timeoutMillis)
{

  // Configure WiFiClientSecure to use the AWS IoT device credentials
  net.setCACert(AWS_CERT_CA);
  net.setCertificate(AWS_CERT_CRT);
  net.setPrivateKey(AWS_CERT_PRIVATE);

  // Connect to the MQTT broker on the AWS endpoint defined earlier
  client.setServer(AWS_IOT_ENDPOINT, 8883); 
  Serial.println("Connecting to AWS IOT");
  
  unsigned long startAttemptTime = millis();
  while (!client.connect(THINGNAME)) {
    Serial.println(client.state());
    delay(100);
    // If couldnt't connect within the specified timeout, break the loop
    if(millis() - startAttemptTime > timeoutMillis) {
      Serial.println("AWS IoT connection attempt timed out");
      return;
    }
  }
 
  if (!client.connected()) {
    Serial.println("AWS IoT Timeout!");
    return;
  }
 
  // Subscribe to a topic
  // client.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);
  
  // Create a message handler
  // client.setCallback(messageHandler);
 
  Serial.println("AWS IoT Connected!");
}

#endif