#include <WiFiNINA.h>

const char *ssid = "iot";
const char *password = "";
const char *red = "\033[31m";
const char *green = "\033[32m";
const char *reset = "\033[0m";

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  if (WiFi.status() == WL_NO_MODULE) {  //255
    Serial.println("WiFi not detected!");
    while (true)
      ;
  }

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.print(green);
  Serial.println("\n\nConnected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
}
