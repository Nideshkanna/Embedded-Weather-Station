#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Replace with your network credentials
const char* ssid = "CIT-Campus";
const char* password = "citchennai";

// OpenWeatherMap API credentials
const char* apiKey = "99ec45bbcb15da7d22a5fee3b039e420";
const char* city = "Nandambakkam";
const char* countryCode = "IN";

String apiUrl = String("http://api.openweathermap.org/data/2.5/weather?q=") + city + "," + countryCode + "&appid=" + apiKey + "&units=metric";

void setup() {
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Connecting to WiFi...");
  display.display();

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Connected to WiFi");
  display.display();
  delay(2000);
}

void loop() {
  if ((WiFi.status() == WL_CONNECTED)) {
    HTTPClient http;
    http.begin(apiUrl);
    int httpCode = http.GET();

    if (httpCode > 0) {
      String payload = http.getString();
      Serial.println(payload);
      
      DynamicJsonDocument doc(1024);
      deserializeJson(doc, payload);
      
      float temperature = doc["main"]["temp"];
      int humidity = doc["main"]["humidity"];
      float pressure = doc["main"]["pressure"];
      const char* weatherDescription = doc["weather"][0]["description"];

      display.clearDisplay();
      display.setCursor(0, 0);
      display.print("Temp: ");
      display.print(temperature);
      display.print(" C");
      display.setCursor(0, 10);
      display.print("Humidity: ");
      display.print(humidity);
      display.print(" %");
      display.setCursor(0, 20);
      display.print("Pressure: ");
      display.print(pressure);
      display.print(" hPa");
      display.setCursor(0, 30);
      display.print("Weather: ");
      display.print(weatherDescription);
      display.display();
    }

    http.end();
  } else {
    Serial.println("WiFi Disconnected");
  }

  delay(60000); // Update every 60 seconds
}
