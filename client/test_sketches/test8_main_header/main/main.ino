#include "C:\Users\kiran\OneDrive\Documents\GitHub\CloudPatchOTA\lib\CloudPatch.h"
//#include "C:\Users\kiran\OneDrive\Documents\GitHub\CloudPatchOTA\lib\Comms.h"
//#include "C:\Users\kiran\OneDrive\Documents\GitHub\CloudPatchOTA\lib\OTAUpdateModule.h"
//#include "C:\Users\kiran\OneDrive\Documents\GitHub\CloudPatchOTA\lib\secrets.h"

float firmware = 1.0;
#define ledPin 2

void blinkFunction()
{
  digitalWrite(ledPin, HIGH);
  delay(600); 
  for (int i = 0 ; i < 5 ; i++)
  {
    digitalWrite(ledPin, LOW);
    delay(100);
    digitalWrite(ledPin, HIGH);
    delay(100);
  }  
}

void printFunction()
{
  Serial.print("Firmware : ");
  Serial.println(firmware);
}

void setup()
{
  Serial.begin(115200);
  setupOTA(3000,3000);
  pinMode(ledPin, OUTPUT);
}
void loop()
{  
  checkMQTTIncomingMsg();
  blinkFunction();
  printFunction();

}