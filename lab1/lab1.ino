#include "pitches.h"
#include "button.h"
#include "buzzer.h"

#define PIN_BUTTON_SPEED_UP 2
#define PIN_BUTTON_SPEED_DOWN 3
#define PIN_BUTTON_STEP_UP 4
#define PIN_BUTTON_STEP_DOWN 5
#define PIN_BUZZER 6

#define DEFAULT_SPEED_MULTIPLIER_VALUE 1.5
#define DEFAULT_SPEED_MULTIPLIER_STEP 0.5

Button buttonSpeedUp(PIN_BUTTON_SPEED_UP);
Button buttonSpeedDown(PIN_BUTTON_SPEED_DOWN);
Button buttonStepUp(PIN_BUTTON_STEP_UP);
Button buttonStepDown(PIN_BUTTON_STEP_DOWN);
Buzzer buzzer(PIN_BUZZER);

int notes[] = {NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,  NOTE_AS3, NOTE_AS4, 0,  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,  NOTE_AS3, NOTE_AS4, 0,  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,  NOTE_DS3, NOTE_DS4, 0,  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,  NOTE_DS3, NOTE_DS4, 0,  0,
  NOTE_DS4, NOTE_CS4, NOTE_D4, NOTE_CS4, NOTE_DS4, NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4, NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3, NOTE_AS3, NOTE_A3, NOTE_GS3, 0, 0, 0};
double durations[] = {12, 12, 12, 12, 12, 12, 6, 3,
  12, 12, 12, 12, 12, 12, 6, 3,
  12, 12, 12, 12, 12, 12, 6, 3,
  12, 12, 12, 12, 12, 12, 6,
  6, 18, 18, 18, 6, 6, 6, 6, 6, 6,
  18, 18, 18, 18, 18, 18, 10, 10, 10,
  10, 10, 10, 3, 3, 3};
int melodyLength = 56;

double speedMultiplier = DEFAULT_SPEED_MULTIPLIER_VALUE;

void setup()
{
    buzzer.setMelody(notes, durations, melodyLength);
    buzzer.turnSoundOn();
}

void loop()
{
    buzzer.playSound();

    if (buttonSpeedUp.wasPressed())
    {
        buzzer.speedUp(speedMultiplier);
    }

    if (buttonSpeedDown.wasPressed())
    {
        buzzer.speedDown(speedMultiplier);
    }

    if (buttonStepUp.wasPressed())
    {
        speedMultiplier += DEFAULT_SPEED_MULTIPLIER_STEP;
    }

    if (buttonStepDown.wasPressed())
    {
        speedMultiplier = max(speedMultiplier - DEFAULT_SPEED_MULTIPLIER_STEP, DEFAULT_SPEED_MULTIPLIER_VALUE);
    }
}
