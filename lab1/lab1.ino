#include <Arduino.h>
#include <MD_TCS230.h>
#include "button.h"

#define  S0_OUT  2
#define  S1_OUT  3
#define  S2_OUT  4
#define  S3_OUT  5

#define R_OUT 6
#define G_OUT 7
#define B_OUT 8

#define BUTTON_R 9
Button buttonR(BUTTON_R)

#define BUTTON_G 10
Button buttonG(BUTTON_G)

#define BUTTON_B 11
Button buttonB(BUTTON_B)

MD_TCS230 colorSensor(S2_OUT, S3_OUT, S0_OUT, S1_OUT);

bool redOn = true
bool greenOn = true
bool blueOn = true

void setup()
{
    Serial.begin(115200);
    Serial.println("Started!");
// С калибровкой сложно, так как не собирал и не получал значения для белых и черных цветов, поэтому значения нулевые :(
    sensorData whiteCalibration;
    whiteCalibration.value[TCS230_RGB_R] = 0;
    whiteCalibration.value[TCS230_RGB_G] = 0;
    whiteCalibration.value[TCS230_RGB_B] = 0;

    sensorData blackCalibration;
    blackCalibration.value[TCS230_RGB_R] = 0;
    blackCalibration.value[TCS230_RGB_G] = 0;
    blackCalibration.value[TCS230_RGB_B] = 0;

    colorSensor.begin();
    colorSensor.setDarkCal(&blackCalibration);
    colorSensor.setWhiteCal(&whiteCalibration);

    pinMode(R_OUT, OUTPUT);
    pinMode(G_OUT, OUTPUT);
    pinMode(B_OUT, OUTPUT);
}

void loop() 
{
  colorData rgb;
  colorSensor.read();
  while (!colorSensor.available());
  colorSensor.getRGB(&rgb);
  
  if (buttonR.wasPressed()) {
    redOn = !redOn
  }
  if (buttonG.wasPressed()) {
    greenOn = !greenOn
  }
  if (buttonB.wasPressed()) {
    blueOn = !blueOn
  }
  if (!redOn) {
    rgb.value[TC230_RGB_R] = 0;
  }
  if (!greenOn) {
    rgb.value[TC230_RGB_G] = 0;
  }
  if (!blueOn) {
    rgb.value[TC230_RGB_B] = 0;
  }
  
  print_rgb(rgb);
  set_rgb_led(rgb);
}

void print_rgb(colorData rgb)
{
  Serial.print(rgb.value[TCS230_RGB_R]);
  Serial.print(" ");
  Serial.print(rgb.value[TCS230_RGB_G]);
  Serial.print(" ");
  Serial.print(rgb.value[TCS230_RGB_B]);
  Serial.println();
}
  
void set_rgb_led(colorData rgb)
{
    analogWrite(R_OUT, 255 - rgb.value[TCS230_RGB_R]);
    analogWrite(G_OUT, 255 - rgb.value[TCS230_RGB_G]);
    analogWrite(B_OUT, 255 - rgb.value[TCS230_RGB_B]);
}
