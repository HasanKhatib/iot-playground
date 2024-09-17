#include <macros.h>
#include <stdint.h>

// Pin definition for the built-in LED
const int ledPin = LED_BUILTIN;

void question5()
{
  Serial.begin(9600);
  Serial.println("Setup is complete");
  pinMode(ledPin, OUTPUT);
}
