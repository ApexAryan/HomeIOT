#include <DHT.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>

#define DHTPIN 2         // DHT11 connected to pin D2
#define DHTTYPE DHT11    // DHT 11 sensor

DHT dht(DHTPIN, DHTTYPE);

// WiFi credentials
const char* ssid = "your_wifi_ssid"; //hidden for my safety lol
const char* password = "your_wifi_password";

// Server URL
const char* serverURL = ""; //add your own server

void setup() {
  Serial.begin(115200);
  dht.begin();

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temp) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverURL);

    String jsonData = String("{\"temperature\":") + temp + ",\"humidity\":" + humidity + "}";
    http.addHeader("Content-Type", "application/json");

    int httpResponseCode = http.POST(jsonData);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println("Server Response: " + response);
    } else {
      Serial.println("Error in sending data");
    }

    http.end();
  }

  delay(60000);  //one min interval
}
