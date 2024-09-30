#include <WiFiNINA.h>

void question2()
{
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);

  while (true)
  {
    // Yellow (R + G)
    analogWrite(LEDR, 0);
    analogWrite(LEDG, 0);
    analogWrite(LEDB, 255);
    delay(2000);

    // Magenta (R + B)
    analogWrite(LEDR, 0);
    analogWrite(LEDG, 255);
    analogWrite(LEDB, 0);
    delay(2000);

    // Cyan (G + B)
    analogWrite(LEDR, 255);
    analogWrite(LEDG, 0);
    analogWrite(LEDB, 0);
    delay(2000);
  }
}
