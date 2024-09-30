// Rookie mistake!
// Set the voltage on the Arduino Nano RP2040 Connect to 3.3V before uploading the code.

#include <macros.h>
#include <stdint.h>
#include <Arduino.h>
#include <WiFiNINA.h>

// pins for the joystick
const int joystickX = A0;
const int joystickY = A1;

// Pin definition for the built-in LED
const int ledPin = LED_BUILTIN;

void question5()
{
  Serial.begin(9600);

  // led output
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  // Hint: Remember to turn off other outputs and only turn on the intended color in each if parts
  digitalWrite(LEDR, LOW);
  digitalWrite(LEDG, LOW);
  digitalWrite(LEDB, LOW);

  while (true)
  {
    // joystick readings
    // Hint2: The analog input of the thumb joystick is a variable between 250 – 750 for X and Y
    int xPosition = analogRead(joystickX);
    int yPosition = analogRead(joystickY);

    // debugging
    Serial.print("X: ");
    Serial.print(xPosition);
    Serial.print(" Y: ");
    Serial.println(yPosition);

    // reset
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDB, LOW);

    if (xPosition > 600)
    {
      // > Yellow (Red + Green)
      digitalWrite(LEDR, HIGH);
      digitalWrite(LEDG, HIGH);
    }
    else if (xPosition < 400)
    {
      // < Blue
      digitalWrite(LEDB, HIGH);
    }
    else if (yPosition > 600)
    {
      // v Red
      digitalWrite(LEDR, HIGH);
    }
    else if (yPosition < 400)
    {
      // ^ Green
      digitalWrite(LEDG, HIGH);
    }

    delay(100);
  }
}
