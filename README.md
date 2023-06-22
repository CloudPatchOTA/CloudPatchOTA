# CloudPatchOTA

This project is a reusable library for FreeRTOS that provides functionality to download, verify, and apply firmware updates over the air (OTA) to embedded devices. The library, based on the BalenaOS reference design, can be seamlessly integrated into existing FreeRTOS projects.

# Installation
Configure the credentials in the ```secrets.h``` file.
Include ```CloudPatch.h``` in your project. Use the full path to the header file, or add the library to the libraries folder in your Arduino sketchbook directory. _(The sketchbook path can be found in the Arduino IDE under "File" -> "Preferences")_.

# Setting up and Updating
```setcMsgTimer(int newMsgTimer)```: sets the interval between each check for incoming update notifications. The interval is defined in milliseconds and stored in the checkMsgTimer variable.

```OTAUpdateCallback(char* topic, byte* payload, unsigned int length)```: the callback for when a message arrives on a subscribed MQTT topic. The function calls execOTA to execute the OTA update.

```setupOTA(int wifiTimer, int iotTimer)```: sets up the secure WiFi connection and the MQTT client. It tries to connect to WiFi with a given timeout (wifiTimer), subscribes the MQTT topic, sets the callback for incoming MQTT messages, and finally tries to connect to AWS IoT with another timeout (iotTimer).

```checkMQTTIncomingMsg()```: This function waits for the interval specified by checkMsgTimer, and then checks if any MQTT messages have arrived.

Force the device to update to the latest firmware version by calling ```void execOTA(WiFiClient client,String host,int port,String bin)``` from ```OTAUpdateModule```.

If the link to the s3 object is _bucket−name.s3.ap−south−1.amazonaws.com/sketch−name.ino.bin_ , then *_"bucket−name.s3.ap−south−1.amazonaws.com"_* is your host and _"/sketch−name.ino.bin"_ is your bin. Make sure to update the read permissions and CORS configurations for your bucket. 

# Dependencies
WiFiClientSecure
PubSubClient
FreeRTOS
