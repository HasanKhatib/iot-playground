/*
Write a program that changes the color of RGB Pixel LED, each time the button is pushed. The
colors should change between Red, Green, and Blue.
Use the example codes during lecture and make modifications where necessary.
*/
#include <Arduino.h>
#include <macros.h>
#include <stdint.h>

const int buttonPin = 3;
const int ledPin = 2;

int counter = 0;
bool buttonState = LOW;
bool lastButtonState = LOW;

void question3()
{
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // Initialize the RGB LED pins as outputs
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);

  // Turn off all RGB LEDs initially
  digitalWrite(LEDR, LOW);
  digitalWrite(LEDG, LOW);
  digitalWrite(LEDB, LOW);

  while (true)
  {
    buttonState = digitalRead(buttonPin);

    // Check if the button is pressed (HIGH) and was not pressed in the previous loop iteration
    if (buttonState == HIGH && lastButtonState == LOW)
    {
      // Increment the counter and wrap it around if it exceeds 2
      counter = (counter + 1) % 3;

      switch (counter)
      {
      case 0:
        digitalWrite(LEDR, HIGH);
        digitalWrite(LEDG, LOW);
        digitalWrite(LEDB, LOW);
        break;
      case 1:
        digitalWrite(LEDR, LOW);
        digitalWrite(LEDG, HIGH);
        digitalWrite(LEDB, LOW);
        break;
      case 2:
        digitalWrite(LEDR, LOW);
        digitalWrite(LEDG, LOW);
        digitalWrite(LEDB, HIGH);
        break;
      }
      // Update the last button state for the next iteration
      lastButtonState = buttonState;
    }
  }
}
