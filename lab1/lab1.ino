#include "pitches.h"
#include "button.h"
#include "buzzer.h"

#define PIN_FIRST_BUZZER 8
#define PIN_SECOND_BUZZER 9
#define PIN_THIRD_BUZZER 10
#define PIN_FOURTH_BUZZER 11

#define BUZZERS_COUNT = 4;
Buzzer firstBuzzer(PIN_FIRST_BUZZER);
Buzzer secondBuzzer(PIN_SECOND_BUZZER);
Buzzer thirdBuzzer(PIN_THIRD_BUZZER);
Buzzer fourthBuzzer(PIN_FOURTH_BUZZER);
Buzzer[] buzzers = {firstBuzzer, secondBuzzer, thirdBuzzer, fourthBazzer};

#define PIN_BUTTON_TOGGLE 5
Button buttonToggle(PIN_BUTTON_OFF);

int melodyLength = 1;
int notes[] = {NOTE_G3};
double durations[] = {50};

bool isAlarmOn = false;

void setup() {
    firstBuzzer.setMelody(notes, durations, melodyLength);
    secondBuzzer.setMelody(notes, durations, melodyLength);
    thirdBuzzer.setMelody(notes, durations, melodyLength);
    fourthBuzzer.setMelody(notes, durations, melodyLength);
}

void loop() {
    if (buttonToggle.wasPressed())
      isAlarmOn = !isAlarmOn;
    if (isAlarmOn) {
      for (int i = 0; i < BUZZERS_COUNT; i++) {
        buzzers[i].turnSoundOn();
        buzzers[i].playSound();
        buzzers[i].turnSoundOff();
        delay(250);
      }    
    }
}
