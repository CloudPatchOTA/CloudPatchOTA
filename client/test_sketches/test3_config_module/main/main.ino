#include<SPIFFS.h>
#include <esp_system.h>
int LED_BUILTIN = 2;

void setup() {
  Serial.begin(115200);
  pinMode (LED_BUILTIN, OUTPUT);

  SPIFFS.format();
  SPIFFS.begin();

  long totalBytes = SPIFFS.totalBytes();
  long usedBytes = SPIFFS.usedBytes();

  Serial.println("Total bytes: " + String(totalBytes));
  Serial.println("Used bytes: " + String(usedBytes));

   size_t freeBytes = esp_get_free_heap_size();

  // Print out the number of free bytes in the heap.
  Serial.println("Free bytes: " + String(freeBytes));
}
void loop() {
  
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
