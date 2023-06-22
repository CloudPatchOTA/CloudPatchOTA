#include <CloudPatch.h>

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
  pinMode(ledPin, OUTPUT);

  // Call setupOTA inside void setup() to initialize the update service. 
  // Argument one is the timeout for wiFi connection attempt
  // Argument two is the timeout for AWS IoT connection attempt
  // Arguments are in milliseconds
  setupOTA(3000,3000);
  
  // Argument is in milliseconds
  setcMsgTimer(4000)
  

}
void loop()
{ 
  // Periodically poll for update notifications by running checkMQTTIncomingMsg().
  // Configure the time interval between successive polls using setcMsgTimer within void setup() 
  checkMQTTIncomingMsg();
  blinkFunction();
  printFunction();

}