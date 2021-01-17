#include <Arduino.h>
#include "button.h"

#define OUT1 2
#define OUT2 3
#define OUT3 4
#define OUT4 6
#define OUT5 7
#define OUT6 8
#define OUT7 9
#define OUT8 10

#define PIN_BUTTON 5

Button button(PIN_BUTTON);
const int SIZE = 8;
bool isWaveActive = false;
bool isUpDirection[SIZE] = { false, true, true, false, false, true, true, false };
int outputs[SIZE] = {2, 3, 4, 6, 7, 8, 9, 10};
int brightnesses[SIZE] = { 128, 1, 128, 255, 128, 1, 128, 255};

void setMode(int output, int brightness)
{
    analogWrite(output, brightness);
}

void doWaveAction()
{
    for (int i = 0; i < SIZE; i++) {
        setMode(outputs[i], brightnesses[i]);
        if (brightnesses[i] == 255 && isUpDirection[i] || brightnesses[i] == 0 && !isUpDirection[i])
        {
            isUpDirection[i] = !isUpDirection[i];
        }
        if (isUpDirection[i])
        {
            brightnesses[i] += 1;
        }
        else
        {
            brightnesses[i] -= 1;
        }
    }
    delay(10);
}

void setup()
{
    for (int i = 0; i < SIZE; i++)
    {
        pinMode(outputs[i], OUTPUT);
    }
}

void loop() 
{
    if (button.wasPressed())
    {
        isWaveActive = !isWaveActive;
    }

    if (isWaveActive)
    {
        doWaveAction();
    }
}
