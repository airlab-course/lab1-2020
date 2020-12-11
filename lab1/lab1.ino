#include "pitches.h"
#include "button.h"
#include "buzzer.h"

#define PIN_BUTTON 5
#define PIN_BUZZER 6
#define R_OUT 7
#define G_OUT 8
#define B_OUT 9

Button button(PIN_BUTTON);
Buzzer buzzer(PIN_BUZZER);

int notes[] = {NOTE_G3};
double durations[] = {1};
int melodyLength = 1;

int r = 255;
int g = 0;
int b = 0;

void setup()
{
    pinMode(R_OUT, OUTPUT);
    pinMode(G_OUT, OUTPUT);
    pinMode(B_OUT, OUTPUT);
    buzzer.setMelody(notes, durations, melodyLength);
    buzzer.turnSoundOn();
}

void loop()
{
    if (button.wasPressed())
    {
        make_shot();
    }
}

void make_shot()
{
    buzzer.turnSoundOn();
    buzzer.playSound();
    set_rgb_led(r, g, b);
    delay(100);
    buzzer.turnSoundOff();
    set_rgb_led(0, 0, 0);
}

void set_rgb_led(int r, int g, int b)
{
    analogWrite(R_OUT, 255 - r);
    analogWrite(G_OUT, 255 - g);
    analogWrite(B_OUT, 255 - b);
}
