#include "OTAUpdateModule.h"
#include "Comms.h"
//#include "secrets.h"

#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include "WiFi.h"

WiFiClientSecure net;
PubSubClient client;
int checkMsgTimer = 3000;
int port = 80;

void setcMsgTimer(int newMsgTimer)
{
    checkMsgTimer = newMsgTimer;
}

int OTAUpdateCallback(char* topic, byte* payload, unsigned int length) {
  
  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  Serial.println(message);
  //call execOTA here
  //check firmware version here
  execOTA( net, host ,  bin ,  port);
  
}

void setupOTA(int wifiTimer, int iotTimer )
{
    net = WiFiClientSecure();  //client connection to server over secure SSL connection
    client = PubSubClient(net);
    int port = 80;
    connectWiFi(wifiTimer);
    
    if (client.subscribe("update_init")) {
        Serial.println("subbed to topic");// move subscribe to inside connectAWSIoT
    }
    client.setCallback(OTAUpdateCallback);
    connectAWSIoT(net, client, iotTimer);


}

void checkMQTTIncomingMsg()
{
    delay(checkMsgTimer);
    //if (!client.connected() || WiFi.status() != WL_CONNECTED)
    //check connection status here
    client.loop();
}