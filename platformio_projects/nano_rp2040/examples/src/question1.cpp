// In many appliances and electronic devices an LED exist showing the programs started, being
// executed, or finished. An example would be the hard drive LED on your PC/Laptop flickering when
// the hard drive is working.
// Write a program mimicking this attribute of a hard drive LED using the Arduino built-in LED flashing
// on and off in the following way:
// LED off (3sec.) – LED on (1 sec.) – LED flickering (turning on/off) 3 times each, 6 times in total (0.3
// sec. each) – LED on (for the rest of the program)

#include <macros.h>
#include <stdint.h>

const int ledPin = LED_BUILTIN;

void question1()
{
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, LOW);
  delay(3000);

  digitalWrite(ledPin, HIGH);
  delay(1000);

  for (int i = 0; i < 6; i++)
  {
    digitalWrite(ledPin, HIGH);
    delay(300);
    digitalWrite(ledPin, LOW);
    delay(300);
  }

  while (true)
  {
    // keep the LED light on
    digitalWrite(ledPin, HIGH);
  }
}
