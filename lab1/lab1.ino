#include <Arduino.h>
#include "button.h"

#define R1_OUT 6
#define G1_OUT 7
#define B1_OUT 8

#define R2_OUT 9
#define G2_OUT 10
#define B2_OUT 11

#define PIN_BUTTON 5

Button button(PIN_BUTTON);
bool isWaveActive = false;

void set_led_value(int r, int g, int b, int value)
{
    analogWrite(r, value);
    analogWrite(g, value);
    analogWrite(b, value);
    delay(250);
}

void createWave()
{
    set_led_value(R1_OUT, G1_OUT, B1_OUT, HIGH);
    set_led_value(R2_OUT, G2_OUT, B2_OUT, HIGH);
    set_led_value(R1_OUT, G1_OUT, B1_OUT, LOW);
    set_led_value(R2_OUT, G2_OUT, B2_OUT, LOW);
}

void setup()
{
    pinMode(R1_OUT, OUTPUT);
    pinMode(G1_OUT, OUTPUT);
    pinMode(B1_OUT, OUTPUT);
    pinMode(R2_OUT, OUTPUT);
    pinMode(G2_OUT, OUTPUT);
    pinMode(B2_OUT, OUTPUT);
}

void loop() 
{
    if (button.wasPressed())
    {
        isWaveActive = !isWaveActive;
    }

    if (isWaveActive)
    {
        createWave();
    }
}
