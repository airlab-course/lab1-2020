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
  colorData rgb;
  if (buttonOn.wasPressed()) {
    for (int i = 0; i < 5; i++) {
      set_red_color(rgb);
      delay(500);
      set_white_color(rgb);
      delay(100);
    }
    set_blue_color(rgb);
  }
}

//void print_rgb(colorData rgb)
//{
//  Serial.print(rgb.value[TCS230_RGB_R]);
//  Serial.print(" ");
//  Serial.print(rgb.value[TCS230_RGB_G]);
//  Serial.print(" ");
//  Serial.print(rgb.value[TCS230_RGB_B]);
//  Serial.println();
//}

void set_rgb_led(colorData rgb)
{
  analogWrite(R_OUT, 255 - rgb.value[TCS230_RGB_R]);
  analogWrite(G_OUT, 255 - rgb.value[TCS230_RGB_G]);
  analogWrite(B_OUT, 255 - rgb.value[TCS230_RGB_B]);
}

void set_rgb_color(colorData rgb, int r, int g, int b) {
  rgb.value[TCS230_RGB_R] = r;
  rgb.value[TCS230_RGB_G] = g;
  rgb.value[TCS230_RGB_B] = b;
}

void set_red_color(colorData rgb) {
  set_rgb_color(rgb, 255, 0, 0);
  set_rgb_led(rgb);
}

void set_white_color(colorData rgb) {
  set_rgb_color(rgb, 255, 255, 255);
  set_rgb_led(rgb);
}

void set_blue_color(colorData rgb) {
  set_rgb_color(rgb, 0, 0, 255);
  set_rgb_led(rgb);
}
