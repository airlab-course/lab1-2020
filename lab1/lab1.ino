#include <Arduino.h>
#include "pitches.h"
#include "button.h"

#define PIN_BUTTON_RedUp 4
#define PIN_BUTTON_RedDown 5
#define PIN_BUTTON_GreenUp 6
#define PIN_BUTTON_GreenDown 7
#define PIN_BUTTON_BlueUp 8
#define PIN_BUTTON_BlueDown 9

#define R_OUT 1
#define G_OUT 2
#define B_OUT 3

int r = 255
int g = 255
int b = 255

void set_rgb_led(int r, int g, int b)
{
    analogWrite(R_OUT, r);
    analogWrite(G_OUT, g);
    analogWrite(B_OUT, b);
}

Button buttonRU(PIN_BUTTON_RedUp);
Button buttonRD(PIN_BUTTON_RedDown);
Button buttonGU(PIN_BUTTON_GreenUp);
Button buttonGD(PIN_BUTTON_GreenDown);
Button buttonBU(PIN_BUTTON_BlueUp);
Button buttonBG(PIN_BUTTON_BlueDown);

void setup()
{
    pinMode(R_OUT, OUTPUT);
    pinMode(G_OUT, OUTPUT);
    pinMode(B_OUT, OUTPUT);
}

void loop()
{
    set_rgb_led(r, g, b)
    if (buttonRU.wasPressed() && r <= 255)
    {
	r += 5
    }
    if (buttonRD.wasPressed() && r >= 0)
    {
	r -= 5
    }
    if (buttonGU.wasPressed() && g <= 0)
    {
	g += 5
    }
    if (buttonGD.wasPressed() && g >= 0)
    {
	g -= 5
    }
    if (buttonBU.wasPressed() && b <= 255)
    {
	b += 5
    }
    if (buttonBD.wasPressed() && b >= 0)
    {
	b -= 5
    }
}
