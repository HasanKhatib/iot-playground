/*
Hardware: Nano RP2040 + Buzzer Module
In some appliances there is a small melody being played after the program is finished. Washing
machines are a good example. Each brand has its unique end-program melody saying that the
laundry can be picked up. Surprisingly, no special electronics are needed, and the melody is played
through a simple buzzer!
Write a program that plays the below melody (The Finale of Beethoven's Ninth Symphony-first
part) with the right timing for each note with the buzzer
*/
#include <Arduino.h>

// Buzzer pin
const int buzzerPin = 6; // Set to 6 since this is where the signal is connected

// Frequencies for the notes (in Hz)
#define NOTE_C4 261
#define NOTE_D4 294
#define NOTE_E4 329
#define NOTE_F4 349
#define NOTE_G4 392
#define REST 0

void playNote(int frequency, float duration)
{
  if (frequency == REST)
  {
    noTone(buzzerPin);
  }
  else
  {
    tone(buzzerPin, frequency);
  }

  delay(duration * 1000);
  noTone(buzzerPin);

  delay(10);
}

//(E,1), (E,1), (F,1), (G,1), (G,1), (F,1), (E,1), (D,1), (C,1), (C,1), (D,1), (E,1), (E,1.5), (D,0.5), (D,2), (0,2)
//(E,1), (E,1), (F,1), (G,1), (G,1), (F,1), (E,1), (D,1), (C,1), (C,1), (D,1), (E,1), (D,1), (D,1.5), (C, 0.5), (C, 2), (0, 2)

void question4()
{
  pinMode(buzzerPin, OUTPUT);

  int melody[] = {
      NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4,
      NOTE_C4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, REST,
      NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4,
      NOTE_C4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_C4, REST};

  float noteLengths[] = {
      1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1.5, 0.5, 2, 2,
      1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1.5, 0.5, 2, 2};

  int numNotes = sizeof(melody) / sizeof(melody[0]);
  while (true)
  {
    for (int i = 0; i < numNotes; i++)
    {
      playNote(melody[i], noteLengths[i]);
    }
    delay(500);
  }

  noTone(buzzerPin);
}
