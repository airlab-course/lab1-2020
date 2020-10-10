#include "button.h"

#define PIN_BUTTON_R_IN_MORE 8
#define PIN_BUTTON_G_IN_MORE 9
#define PIN_BUTTON_B_IN_MORE 10

#define PIN_BUTTON_R_IN_LESS 11
#define PIN_BUTTON_G_IN_LESS 12
#define PIN_BUTTON_B_IN_LESS 13

#define R_OUT 2
#define G_OUT 3
#define B_OUT 4

Button buttonRedMore(PIN_BUTTON_R_IN_MORE);
Button buttonGreenMore(PIN_BUTTON_G_IN_MORE);
Button buttonBlueMore(PIN_BUTTON_B_IN_MORE);

Button buttonRedLess(PIN_BUTTON_R_IN_LESS);
Button buttonGreenLess(PIN_BUTTON_G_IN_LESS);
Button buttonBlueLess(PIN_BUTTON_B_IN_LESS);

void set_rgb_led(int Red, int Green, int Blue)
{
    analogWrite(R_OUT, 255 - Red);
    analogWrite(G_OUT, 255 - Green);
    analogWrite(B_OUT, 255 - Blue);
}

void setup() {
    pinMode(R_OUT, OUTPUT);
    pinMode(G_OUT, OUTPUT);
    pinMode(B_OUT, OUTPUT);
}

int R = 90, G = 90, B = 90;

void loop() {
    if (buttonRedMore.wasPressed() && R < 255)
        R += 15;
    if (buttonRedLess.wasPressed() && R > 0)
        R -= 15;
    if (buttonGreenMore.wasPressed() && G < 255)
        G += 15;
    if (buttonGreenLess.wasPressed() && G > 0)
        G -= 15;
    if (buttonBlueMore.wasPressed() && B < 255)
        B += 15;
    if (buttonBlueLess.wasPressed() && B > 0)
        B -= 15;
    set_rgb_led(R,G,B);
}
