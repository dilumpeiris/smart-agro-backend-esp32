#include "Network.h"
#include <WiFi.h>
#include <HTTPClient.h>
Network::Network(char *ssid, char *password): ssid(ssid), password(password)
{
}

 void Network::connect() {
    Serial.print("Connecting to WiFi...");
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
}

String Network::GET(const char* url){

    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        http.begin(url);
        int httpCode = http.GET();
        
        String payload = "";

        if (httpCode > 0) {
          Serial.printf("GET request to %s\n", url);
          Serial.printf("HTTP code: %d\n", httpCode);
          payload = http.getString();
        } else {
          Serial.printf("GET request failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end(); 
        return payload;
      } else {
        Serial.println("Error: WiFi not connected!");
        return "";
      }
}

String Network::POST(const char* url, const String& payload) {
      if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        http.begin(url);
        http.addHeader("Content-Type", "application/json");

        int httpCode = http.POST(payload);

        String response = "";
        if (httpCode > 0) {
          Serial.printf("POST request to %s\n", url);
          Serial.printf("HTTP code: %d\n", httpCode);
          response = http.getString();
        } else {
          Serial.printf("POST request failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
        return response;
      } else {
        Serial.println("Error: WiFi not connected!");
        return "";
      }
      }