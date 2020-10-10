#include <toneAC.h>
#include "pitches.h"
#include <Arduino.h>
#include <MD_TCS230.h>

#define  S0_OUT  2
#define  S1_OUT  3
#define  S2_OUT  4
#define  S3_OUT  5

int delta = 10;

int R;
int G;
int B;

int white = 250; 

int R_blue = 31;
int G_blue = 106;
int B_blue = 174;

int R_red = 130;
int G_red = 14;
int B_red = 45;

int R_yellow = 247;
int G_yellow = 174;
int B_yellow = 73;

int R_orange = 208;
int G_orange = 49;
int B_orange = 29;

int R_green = 21;
int G_green = 58;
int B_green = 29;

int R_purple = 28;
int G_purple = 21;
int B_purple = 65;

int R_pink = 150;
int G_pink = 50; 
int B_pink = 97;

MD_TCS230 colorSensor(S2_OUT, S3_OUT, S0_OUT, S1_OUT);

void setup()
{
  sensorData whiteCalibration;
  whiteCalibration.value[TCS230_RGB_R] = 82880;
  whiteCalibration.value[TCS230_RGB_G] = 75110;
  whiteCalibration.value[TCS230_RGB_B] = 90870;

  sensorData blackCalibration;
  blackCalibration.value[TCS230_RGB_R] = 12800;
  blackCalibration.value[TCS230_RGB_G] = 11470;
  blackCalibration.value[TCS230_RGB_B] = 14920;

  Serial.begin(115200);

  colorSensor.begin();
  colorSensor.setDarkCal(&blackCalibration);
  colorSensor.setWhiteCal(&whiteCalibration);

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

  Serial.print(R);
  Serial.print(" ");
  Serial.print(G);
  Serial.print(" ");
  Serial.print(B);
  Serial.println();
  
  if (InRange(R, G, B, R_yellow, G_yellow, B_yellow))
  {
    Buzzer_play(NOTE_C4);
  }

  else if (InRange(R, G, B, R_red, G_red, B_red))
  {
    Buzzer_play(NOTE_E4);
  }

  else if (InRange(R, G, B, R_blue, G_blue, B_blue))  
  {
    Buzzer_play(NOTE_C5);
  }

  else if (InRange(R, G, B, R_purple, G_purple, B_purple))
  {
    Buzzer_play(NOTE_A4);
  }

  else if (InRange(R, G, B, R_orange, G_orange, B_orange))
  {
    Buzzer_play(NOTE_B4);
  }

  else if (InRange(R, G, B, R_green, G_green, B_green))
  {
    Buzzer_play(NOTE_B4);
  }

  else if (InRange(R, G, B, R_pink, G_pink, B_pink))
  {
    Buzzer_play(NOTE_F4);
  }

  else if (R >= white && G >= white && B >= white)
  {
    Buzzer_play(NOTE_G4);
  }

  else
  {
    noToneAC();
  }
}

void Buzzer_play(int Hz)
{
  toneAC(Hz);
  delay(1);
}

bool InRange(int R, int G, int B, int R_color, int G_color, int B_color)
{
  return (R_color - delta <= R && R <= R_color + delta) && (G_color - delta <= G && G <= G_color + delta) && (B_color - delta <= B && B <= B_color + delta);
}
