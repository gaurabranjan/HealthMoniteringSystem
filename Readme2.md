In this code, we use the PulseSensorPlayground library for the heartbeat sensor, PulseSensor.h library for the pulse sensor, and Adafruit MLX90614 library for the body temperature sensor.

Replace 'YOUR_AUTH_TOKEN' with the authentication token obtained from the Blynk project. Also, replace 'YOUR_WIFI_SSID' and 'YOUR_WIFI_PASSWORD' with your Wi-Fi network credentials.

The setup() function initializes the serial communication, connects to the Wi-Fi network, and initializes the pulse sensor and body temperature sensor.

The loop() function reads the heart rate from the pulse sensor using pulseSensor.getBeatsPerMinute() and sends it to the Blynk app using Blynk.virtualWrite() for the heart rate virtual pin.

The loop() function also reads the body temperature from the MLX90614 sensor using mlx.readObjectTempC() and sends it to the Blynk app using Blynk.virtualWrite() for the body temperature virtual pin.

The data is also printed to the serial monitor for debugging purposes.

Make sure you have the necessary libraries installed in your Arduino IDE before uploading the code to the NodeMCU board.
