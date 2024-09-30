#include <WiFiNINA.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Step 1: Set the color to Yellow (Red + Green) for 2 seconds
  analogWrite(LEDR, 0);
  analogWrite(LEDG, 0);
  analogWrite(LEDB, 255);
  delay(2000);

  // Step 2: Set the color to Magenta (Red + Blue) for 2 seconds
  analogWrite(LEDR, 0);
  analogWrite(LEDG, 255);
  analogWrite(LEDB, 0);
  delay(2000);

  // Step 3: Set the color to Cyan (Green + Blue) for 2 seconds
  analogWrite(LEDR, 255);
  analogWrite(LEDG, 0);
  analogWrite(LEDB, 0);
  delay(2000);
}
