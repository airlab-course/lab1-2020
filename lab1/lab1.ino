#include "pitches.h"
#include <Arduino.h>
#include <MD_TCS230.h>

#define  S0_OUT  2
#define  S1_OUT  3
#define  S2_OUT  4
#define  S3_OUT  5

#define Buzzer 7

int R;
int G;
int B;

MD_TCS230 colorSensor(S2_OUT, S3_OUT, S0_OUT, S1_OUT);

void setup()
{
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

  pinMode(Buzzer, OUTPUT);
}

void loop()
{
  colorData rgb;
  colorSensor.read();

  while (!colorSensor.available());

  colorSensor.getRGB(&rgb);
  R = rgb.value[TCS230_RGB_R];
  G = rgb.value[TCS230_RGB_G];
  B = rgb.value[TCS230_RGB_B];

  if (R > B && R > G)
  {
    tone(Buzzer, NOTE_C4);
  }
  
  else if (G > R && G > B)
  {
    tone(Buzzer, NOTE_D4);
  }
  
  else if (B > R && B > G)
  {
    tone(Buzzer, NOTE_E4);
  }
  
  else if (R == 0 && G == 0 && B == 0)
  {
    tone(Buzzer, NOTE_F4);
  }
  
  else if (R == 255 && G == 255 && B == 255)
  {
    tone(Buzzer, NOTE_G4);
  }
  
  else if (R > B && G > B)
  {
    tone(Buzzer, NOTE_A4);
  }
  
  else if (G > R && B > R)
  {
    tone(Buzzer, NOTE_B4);
  }
  
  else
  {
    tone(Buzzer, NOTE_C5);
  }
}
