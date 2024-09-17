// Forward declarations of question functions
#include <Arduino.h>
void question1();
void question2();
void question3();
void question4();
void question5();

void setup() {
  Serial.begin(9600);
  delay(1000);

  #if QUESTION == 1
  question1();
  #elif QUESTION == 2
  question2();
  #elif QUESTION == 3
  question3();
  #elif QUESTION == 4
  question4();
  #elif QUESTION == 5
  question5();
  #else
  Serial.println("No valid QUESTION defined.");
  #endif
}

void loop() {
  // Handle loop actions for the specific question here, if needed
}
