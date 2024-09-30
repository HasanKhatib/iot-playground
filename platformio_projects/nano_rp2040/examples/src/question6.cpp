// Rookie mistake!
// Set the voltage on the Arduino Nano RP2040 Connect to 3.3V before uploading the code.

#include <macros.h>
#include <stdint.h>
#include <Arduino.h>
#include <WiFiNINA.h>

const char *ssid = "iot";
const char *password = "";

const char *red = "\033[31m";
const char *green = "\033[32m";
const char *reset = "\033[0m";

void question6()
{
  Serial.begin(9600);

  WiFi.begin(ssid, password);

  Serial.println("\nConnected to Wi-Fi!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}
