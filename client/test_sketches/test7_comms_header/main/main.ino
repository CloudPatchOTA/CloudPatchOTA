//#include "secrets.h"
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
//#include <ArduinoJson.h>
#include "WiFi.h"
#include "Comms.h"



const float firmware_version = 1.0;
WiFiClientSecure net = WiFiClientSecure();  //client connection to server over secure SSL connection
PubSubClient client(net);

int OTAUpdateCallback(char* topic, byte* payload, unsigned int length) {
  
  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  Serial.println(message);
  //call execOTA here
  
}
void setup() {

  Serial.begin(115200);
  Serial.println("setup");


  connectWiFi(3000);
  connectAWSIoT(net, client, 3000);
  if (client.subscribe("update_init")) {
    Serial.println("subbed to topic");
  }
  client.setCallback(OTAUpdateCallback);
}
void loop()
{
  delay(1000);
  
  if (!client.connected() || WiFi.status() != WL_CONNECTED)
  {
    if (connectWiFi(3000))
    {
      Serial.println("connected again");
      connectAWSIoT(net , client , 3000);
      if (client.subscribe("update_init"))
      {
        Serial.println("subscribed to topic again");
      }
    }
  }
  else
  {
    client.loop();
  }
}


/*
WiFiClientSecure net = WiFiClientSecure(); //client connection to server over secure SSL connection
PubSubClient client(net);
 
void connectAWS()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);// creds in secrets.h 
  Serial.println("Connecting to Wi-Fi"); 
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
 
  // Configure WiFiClientSecure to use the AWS IoT device credentials
  net.setCACert(AWS_CERT_CA);
  Serial.println("CA cert validated");

  net.setCertificate(AWS_CERT_CRT);
  Serial.println("dev cert validated");

  net.setPrivateKey(AWS_CERT_PRIVATE);
  Serial.println("priv cert validated");

  // Connect to the MQTT broker on the AWS endpoint we defined earlier
  client.setServer(AWS_IOT_ENDPOINT, 8883);
 
  // Create a message handler
  //client.setCallback(messageHandler);
 
 
  Serial.println("Connecting to AWS IOT");
 
  while (!client.connect(THINGNAME))
  {
    //erial.print(".");
    Serial.println(client.state());
    delay(100);
  }
 
  if (!client.connected())
  {
    Serial.println("AWS IoT Timeout!");
    return;
  }
 
  // Subscribe to a topic
  //client.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);
 
  Serial.println("AWS IoT Connected!");
}

int OTAUpdateCallback(char* topic, byte* payload, unsigned int length) {
  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  // Parse and process the message as an integer
  //int command = message.toInt();
  Serial.println(message);
  //call execOTA here

}

void setup()
{
  Serial.begin(115200);
  connectAWS();
  
  Serial.println(client.subscribe("update_init"));
  client.setCallback(OTAUpdateCallback);
  //dht.begin();  
}
 
void loop()
{

  //Serial.println(client.state());
  //client.loop();
  delay(1000);
  client.loop();

}

*/

/*
bool connectWiFi(unsigned long timeoutMillis) {
    unsigned long startTime = millis();
    
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

void connectAWS(WiFiClientSecure &net, PubSubClient &client, unsigned long timeoutMillis)
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

*/
