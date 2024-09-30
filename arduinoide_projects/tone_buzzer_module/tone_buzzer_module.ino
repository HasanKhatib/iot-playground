#include <Arduino.h>

const int buzzerPin = 6;  // Set to 6 since this is where the signal is connected

// Frequencies for the notes (in Hz)
#define NOTE_C4 261
#define NOTE_D4 294
#define NOTE_E4 329
#define NOTE_F4 349
#define NOTE_G4 392
#define REST 0

void playNote(int frequency, float duration) {
  if (frequency == REST) {
    noTone(buzzerPin);
  } else {
    tone(buzzerPin, frequency);
  }

  delay(duration * 1000);
  noTone(buzzerPin);

  delay(10);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int melody[] = {
    NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4,
    NOTE_C4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, REST,
    NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4,
    NOTE_C4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_C4, REST
  };

  float noteLengths[] = {
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1.5, 0.5, 2, 2,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1.5, 0.5, 2, 2
  };

  int numNotes = sizeof(melody) / sizeof(melody[0]);
  for (int i = 0; i < numNotes; i++) {
    playNote(melody[i], noteLengths[i]);
  }
  delay(500);
}
