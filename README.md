# Embedded-Weather-Station
An IoT weather station using ESP32
We can implement a basic weather station using the ESP32 without any physical sensors by fetching weather data from an online API. This approach uses the ESP32's WiFi capability to connect to the internet and retrieve weather data from a web service. Here's how you can do it:

Components Needed:
   ESP32 development board
   OLED display (SSD1306) or any other display
   Breadboard and jumper wires
   Power source (e.g., USB cable)
   Setting Up the Software
Install the Arduino IDE:
    Download and install the Arduino IDE from the official website.

Add ESP32 Board to Arduino IDE:

    Open Arduino IDE.
    Go to File > Preferences.
    In the "Additional Board Manager URLs" field, add this URL: https://dl.espressif.com/dl/package_esp32_index.json.
    Go to Tools > Board > Boards Manager.
    Search for "ESP32" and install the board package.
Install Required Libraries:

    Open Arduino IDE.
    Go to Sketch > Include Library > Manage Libraries.
Search for and install the following libraries:
    Adafruit SSD1306
    Adafruit GFX Library
    ArduinoJson 
    WiFi
    Wiring the Components
OLED Display:
    VCC to 3.3V
    GND to GND
    SCL to SCL (GPIO 22)
    SDA to SDA (GPIO 21)


Explanation:
 Setup Function: 
      Connects to WiFi and initializes the OLED display.
      
 Loop Function:
      Fetches weather data from OpenWeatherMap API, parses the JSON response, and displays the temperature, humidity, pressure, and weather description on the OLED.
      
Steps to Get Your OpenWeatherMap API Key:
      Sign up at OpenWeatherMap.
      After signing up, navigate to the API keys section of your account to generate a new API key.
      
Additional Features:
      We can expand the functionality by:

Adding More Data Points: 
      Fetch and display more data points like wind speed, visibility, etc.
      
Graphical Display: 
      Use icons to represent different weather conditions.
      
Data Logging: 
      Store the fetched data in a file or send it to a cloud service for long-term logging.

This setup allows you to create a weather station using the ESP32 without any physical sensors by leveraging online weather data. 
