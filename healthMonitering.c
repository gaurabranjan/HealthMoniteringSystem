#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_MLX90614.h>
#include <PulseSensorPlayground.h>

// WiFi credentials
char auth[] = "YOUR_AUTH_TOKEN";
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

// Blynk virtual pin numbers
#define HEART_RATE_VIRTUAL_PIN V1
#define BODY_TEMPERATURE_VIRTUAL_PIN V2

// Pulse sensor setup
const int pulseSensorPin = A0;
const int blinkPin = 13;

PulseSensorPlayground pulseSensor;
int heartRate;

// Body temperature sensor setup
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup()
{
  // Start the serial communication
  Serial.begin(9600);

  // Connect to the Wi-Fi network
  Blynk.begin(auth, ssid, pass);

  // Initialize the pulse sensor
  pulseSensor.analogInput(pulseSensorPin);
  pulseSensor.blinkOnPulse(blinkPin);
  pulseSensor.setThreshold(550);

  // Initialize the body temperature sensor
  mlx.begin();
}

void loop()
{
  Blynk.run();

  // Read heart rate from the pulse sensor
  if (pulseSensor.sawNewSample())
  {
    int heartRate = pulseSensor.getBeatsPerMinute();
    Blynk.virtualWrite(HEART_RATE_VIRTUAL_PIN, heartRate);
  }

  // Read body temperature from the MLX90614 sensor
  float bodyTemperature = mlx.readObjectTempC();
  Blynk.virtualWrite(BODY_TEMPERATURE_VIRTUAL_PIN, bodyTemperature);

  // Print data to the serial monitor
  Serial.print("Heart Rate: ");
  Serial.println(heartRate);
  Serial.print("Body Temperature: ");
  Serial.print(bodyTemperature);
  Serial.println(" °C");

  delay(10);
}