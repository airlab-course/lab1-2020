#include <buzzer.h>
#include <button.h>
#include <pitches.h>

#define PIN_BUZZER 12  // пин с пищалкой
#define PIN_BUTTON_ONE 3
#define PIN_BUTTON_TWO 13
#define PIN_PLAYER_ONE 9
#define PIN_PLAYER_TWO 11

Buzzer buzzer(PIN_BUZZER);

int buttonPins[2] = {3, 13};
int ledPins[2] = {9, 11};
int randNumber;

int notes[] = {NOTE_A4, NOTE_G4, NOTE_G4, NOTE_A4};
double durations[] = {8, 1, 4, 1};
int melodyLength = 4;

unsigned long speeds[] = {25, 50, 100, 200, 400, 800};
int currentSpeed = 2;
int speedsLength = 6;

int notes2[] = {NOTE_C4, NOTE_C4, NOTE_C4, NOTE_DS8, NOTE_DS8, NOTE_DS8, NOTE_C4, NOTE_C4, NOTE_C4};
double durations2[] = {5, 5, 5, 30, 30, 30, 5, 5, 5};
int melodyLength2 = 9;

int notes_Start[] = {NOTE_A4};
double durations_Start[] = {8};
int melodyLengthStart = 1;

void setup()
{
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(3, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);

}
 
void loop()
{
  randNumber = random(2000,6000);
  delay(randNumber);
  buzzer.setMelody(notes_Start, durations_Start, melodyLengthStart);
  buzzer.turnSoundOn();
  for (int player = 0; ; player = (player + 1) % 2) {
    if (!digitalRead(buttonPins[player])) {
      digitalWrite(ledPins[player], HIGH);
      if (player == 0){
        buzzer.setMelody(notes, durations, melodyLength);
        buzzer.turnSoundOn();
      }
      else if (player == 1){
        buzzer.setMelody(notes2, durations2, melodyLength2);
        buzzer.turnSoundOn();
      }
      delay(2000);
      digitalWrite(ledPins[player], LOW);
      break;
    }
  }
}
