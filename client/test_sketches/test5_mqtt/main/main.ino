#include "secrets.h"
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
//#include <ArduinoJson.h>
#include "WiFi.h"

 
//DHT dht(DHTPIN, DHTTYPE);
//   yt
WiFiClientSecure net = WiFiClientSecure();
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