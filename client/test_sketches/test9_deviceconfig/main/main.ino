#include "C:\Users\kiran\OneDrive\Documents\GitHub\CloudPatchOTA\lib\DeviceConfig.h"
//#include "C:\Users\kiran\OneDrive\Documents\GitHub\CloudPatchOTA\lib\Comms.h"
//#include "C:\Users\kiran\OneDrive\Documents\GitHub\CloudPatchOTA\lib\OTAUpdateModule.h"
//#include "C:\Users\kiran\OneDrive\Documents\GitHub\CloudPatchOTA\lib\secrets.h"

float firmware = 1.0;
void f1(){}
void f2(){}
void f3(){}

void setup()
{
  Serial.begin(115200);
  setupOTA(3000,3000);
}
void loop()
{
  
  checkMQTTIncomingMsg();
  Serial.print("Firmware : ");
  Serial.println(firmware);
}