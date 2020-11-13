#include <Arduino.h>
#include "button.h"

#define R_OUT 6
#define G_OUT 7
#define B_OUT 8

#define PIN_BUTTON_OFF 5

Button buttonOff(PIN_BUTTON_OFF);

void setup()
{
    Serial.begin(115200);
    Serial.println("Started!");

    pinMode(R_OUT, OUTPUT);
    pinMode(G_OUT, OUTPUT);
    pinMode(B_OUT, OUTPUT);
}

void loop() 
{
    if (buttonOff.wasPressed())
    {
        //
    }
}
