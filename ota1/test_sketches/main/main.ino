#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <Update.h>




#include <WiFi.h>
#include <HTTPClient.h>
#include <Update.h>

#define ledPin 2

void DownloadAndApplyPatch(char* LinkToPatchBinary) {
  WiFiClient client;
  HTTPClient http;

  Serial.print("Downloading patch binary from ");
  Serial.println(LinkToPatchBinary);

  // Connect to the server
  if (http.begin(client, LinkToPatchBinary)) {
    // Send HTTP GET request
    int httpCode = http.GET();

    // Check for HTTP response code
    if (httpCode == HTTP_CODE_OK) {
      // Get the content length of the response
      int contentLength = http.getSize();

      if (contentLength > 0) {
        // Create a buffer to store the binary data
        uint8_t buffer[contentLength];

        // Read the response into the buffer
        int bytesRead = http.readBytes(buffer, contentLength);

        if (bytesRead == contentLength) {
          // Close the HTTP connection
          http.end();

          // Apply the patch binary using the ESP32's OTA library
          if (Update.begin(contentLength)) {
            Update.write(buffer, contentLength);
            if (Update.end()) {
              Serial.println("Patch binary installation successful");
              ESP.restart();
            } else {
              Serial.println("Patch binary installation failed");
            }
          } else {
            Serial.println("Patch binary installation failed to begin");
          }
        } else {
          Serial.println("Error reading patch binary");
        }
      } else {
        Serial.println("Content length is zero");
      }
    } else {
      Serial.print("HTTP GET request failed, error: ");
      Serial.println(http.errorToString(httpCode).c_str());
    }
  } else {
    Serial.println("Failed to connect to server");
  }
}

void setup(void)
{
  // Initialize serial port
  Serial.begin(115200);
  const char* ssid = "El-Dorado 2.4G";
const char* password = "savithabhabi";
  /*
  // Connect to WiFi network
  char* ssid = "your_ssid";
  char* password = "your_password";
  */
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  char* LinkToPatchBinary = "13.233.137.149/updated.bin";
  //DownloadAndApplyPatch(LinkToPatchBinary);
  // ...
}


void loop(void) {
  server.handleClient();
  
  digitalWrite(ledPin, HIGH);
  delay(1000);
 
  digitalWrite(ledPin, LOW);
  delay(1000);
}