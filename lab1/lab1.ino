#include <Arduino.h>
#include <MD_TCS230.h>

#define  S0_OUT  2
#define  S1_OUT  3
#define  S2_OUT  4
#define  S3_OUT  5

#define R_OUT 6
#define G_OUT 7
#define B_OUT 8
#define PIN_BUTTON_ON 9

Button buttonOn(PIN_BUTTON_ON);

MD_TCS230 colorSensor(S2_OUT, S3_OUT, S0_OUT, S1_OUT);

void setup()
{
  pinMode(R_OUT, OUTPUT);
  pinMode(G_OUT, OUTPUT);
  pinMode(B_OUT, OUTPUT);

}


void loop()
{
  if (buttonOn.wasPressed()) {
    for (int i = 0; i < 6; i++) {
      set_rgb_led(255, 0, 0);
      delay(4000);
      set_rgb_led(255, 255, 255);
      delay(1000);
    }
    set_rgb_led(0, 0, 255);
  }
}

void set_rgb_led(int r, int g, int b)
{
  analogWrite(R_OUT, 255 - r);
  analogWrite(G_OUT, 255 - g);
  analogWrite(B_OUT, 255 - b);
}
