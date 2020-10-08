#include <MD_TCS230.h>

#define buzpin 9
#define button 10
#define  S0_OUT  2
#define  S1_OUT  3
#define  S2_OUT  4
#define  S3_OUT  5
MD_TCS230 ColorSensor(S2_OUT, S3_OUT, S0_OUT, S1_OUT);

struct RGB {
  int R, G, B;
  RGB(int r, int g, int b) {
    R = r;
    G = g;
    B = b;
  }
};

bool isAlarm = false;
void setup() {
  sensorData whiteCalibration;
  whiteCalibration.value[TCS230_RGB_R] = 120060;
  whiteCalibration.value[TCS230_RGB_G] = 117520;
  whiteCalibration.value[TCS230_RGB_B] = 157590;
  sensorData blackCalibration;
  blackCalibration.value[TCS230_RGB_R] = 11280;
  blackCalibration.value[TCS230_RGB_G] = 10270;
  blackCalibration.value[TCS230_RGB_B] = 13230;

  ColorSensor.begin();
  ColorSensor.setDarkCal(&blackCalibration);
  ColorSensor.setWhiteCal(&whiteCalibration);
}

void loop() {
  isAlarm = digitalRead(button) == LOW && checkColor();
  analogWrite(buzpin, isAlarm ? 255 : 0);
}

bool checkColor(){
  RGB color = getColor();
  return color.R > 240 && color.G < 10 && color.B < 10;
}

RGB getColor(){
  colorData rgb;
  ColorSensor.read();
  while (!ColorSensor.available())
      ;
  ColorSensor.getRGB(&rgb);
  return RGB(rgb.value[TCS230_RGB_R], rgb.value[TCS230_RGB_G], rgb.value[TCS230_RGB_B]);
}
