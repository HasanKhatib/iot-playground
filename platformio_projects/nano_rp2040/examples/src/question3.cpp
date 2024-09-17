/*
Write a program that changes the color of RGB Pixel LED, each time the button is pushed. The
colors should change between Red, Green, and Blue.
Use the example codes during lecture and make modifications where necessary.
*/
#include <Arduino.h>
#include <macros.h>
#include <stdint.h>

const int buttonPin = 3; // Button connected to pin 3
const int ledPin = 2;    // External LED connected to pin 2

int counter = 0;            // Counter to track which color to display
bool buttonState = LOW;     // Current state of the button
bool lastButtonState = LOW; // Previous state of the button

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

      // Update the RGB LED based on the counter
      switch (counter)
      {
      case 0:
        digitalWrite(LEDR, HIGH); // Red on
        digitalWrite(LEDG, LOW);  // Green off
        digitalWrite(LEDB, LOW);  // Blue off
        break;
      case 1:
        digitalWrite(LEDR, LOW);  // Red off
        digitalWrite(LEDG, HIGH); // Green on
        digitalWrite(LEDB, LOW);  // Blue off
        break;
      case 2:
        digitalWrite(LEDR, LOW);  // Red off
        digitalWrite(LEDG, LOW);  // Green off
        digitalWrite(LEDB, HIGH); // Blue on
        break;
      }
    }

    // Update the last button state for the next iteration
    lastButtonState = buttonState;
  }
}
