#include <WiFi.h>
#include <HTTPClient.h>
#include <SPIFFS.h>
#include <Update.h>

HTTPClient http;

void WritePatchToFlash(char* LinkToPatchBinary) {
  WiFi.begin("your_wifi_ssid", "your_wifi_password");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  if (!SPIFFS.begin(true)) {
    Serial.println("An error occurred while mounting SPIFFS");
    return;
  }

  http.begin(LinkToPatchBinary);
  int httpCode = http.GET();

  if (httpCode == HTTP_CODE_OK) {
    File file = SPIFFS.open("/patch.bin", "w");
    http.writeToStream(&file);
    file.close();

    if (Update.begin()) {
      Serial.println("Starting OTA update");
      Update.run();
      Serial.println("OTA update complete");
    } else {
      Serial.println("OTA update failed");
    }
  } else {
    Serial.println("Failed to download patch binary");
  }

  http.end();
  SPIFFS.end();
}
