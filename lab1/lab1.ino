#include <Arduino.h>
#include "button.h"

#define R1_OUT 2
#define G1_OUT 3
#define B1_OUT 4

#define R2_OUT 6
#define G2_OUT 7
#define B2_OUT 8

#define R3_OUT 9
#define G3_OUT 10
#define B3_OUT 11

#define PIN_BUTTON 5

Button button(PIN_BUTTON);
bool isWaveActive = false;
int counters[3] = { 0, 2, 1 };

void setMode(int mode, int r, int g, int b)
{
  if (mode == 2)
  {
    digitalWrite(r, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(b, HIGH);
  }
  else if (mode == 1)
  {
    analogWrite(r, 127);
    analogWrite(g, 127);
    analogWrite(b, 127);
  }
  else
  {
    digitalWrite(r, LOW);
    digitalWrite(g, LOW);
    digitalWrite(b, LOW);
  }
}

void doWaveAction()
{
    setMode(counters[0], R1_OUT, G1_OUT, B1_OUT);
    setMode(counters[1], R2_OUT, G2_OUT, B2_OUT);
    setMode(counters[2], R3_OUT, G3_OUT, B3_OUT);
    for (int i = 0; i < 3; i++) {
        if (counters[i] == 2)
        {
            counters[i] = 0;
        }
        else
        {
            counters[i] += 1;
        }
    }
    delay(250);
}

void setup()
{
    pinMode(R1_OUT, OUTPUT);
    pinMode(G1_OUT, OUTPUT);
    pinMode(B1_OUT, OUTPUT);
    pinMode(R2_OUT, OUTPUT);
    pinMode(G2_OUT, OUTPUT);
    pinMode(B2_OUT, OUTPUT);
    pinMode(R3_OUT, OUTPUT);
    pinMode(G3_OUT, OUTPUT);
    pinMode(B3_OUT, OUTPUT);
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
