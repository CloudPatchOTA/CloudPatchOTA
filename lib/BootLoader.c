#include <WiFi.h>
#include <HTTPClient.h>
#include <Update.h>

const char* ssid = "Pixel";
const char* password = "12345678";


//  server should return "no update" if no update available, or the binary file if an update is available
const char* update_server = "http://www.test.com/firmware";

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  delay(1000 * 60 * 60); // Wait for an hour between checks, you can adjust this delay as needed
  checkForUpdates();
}

void checkForUpdates() {
  HTTPClient http;

  http.begin(update_server); // Specify the URL
  int httpCode = http.GET(); // Make the request

  if (httpCode == 200) { // Check the returning code
    String payload = http.getString(); // Get the request response payload
    if (payload == "no update") {
      Serial.println("No update available.");
    } else {
      Serial.println("Update available. Updating...");
      // Run the OTA update
      execOTA(); // Insert the OTA update code here
    }
  } else {
    Serial.println("Error on HTTP request");
  }

  http.end(); // Free the resources
}

