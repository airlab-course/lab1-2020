#include <Arduino.h>
#include <MD_TCS230.h>
#include "pitches.h"
#include "buzzer.h"

#define  S0_OUT  2
#define  S1_OUT  3
#define  S2_OUT  4
#define  S3_OUT  5
#define PIN_BUZZER 6
#define COLOR_DELTA 10
#define MAX_RGB_VALUE 255-COLOR_DELTA

MD_TCS230 color_sensor(S2_OUT, S3_OUT, S0_OUT, S1_OUT);
buzzer buzzer(PIN_BUZZER);

struct RGB
{
    int red, green, blue;
    RGB(int r, int g, int b)
    {
      red = r;
      green = g;
      blue = b;
    }
};

struct note_color
{
  int note;
  RGB color;
};

note_color note_colors[] 
{
  {NOTE_C4, RGB(0, 0, 0)},
  {NOTE_D4, RGB(MAX_RGB_VALUE, MAX_RGB_VALUE, MAX_RGB_VALUE)},
  {NOTE_E4, RGB(MAX_RGB_VALUE, 0, 0)},
  {NOTE_F4, RGB(0, MAX_RGB_VALUE, 0)},
  {NOTE_G4, RGB(0, 0, MAX_RGB_VALUE)},
  {NOTE_A4, RGB(MAX_RGB_VALUE, MAX_RGB_VALUE, 0)},
  {NOTE_B4, RGB(MAX_RGB_VALUE, 0, MAX_RGB_VALUE)}
};
int note_colors_length = sizeof(note_colors) / sizeof(*note_colors);

void setup()
{
    Serial.begin(115200);
    Serial.println("Started!");

    sensorData whiteCalibration;
    whiteCalibration.value[TCS230_RGB_R] = 0;
    whiteCalibration.value[TCS230_RGB_G] = 0;
    whiteCalibration.value[TCS230_RGB_B] = 0;

    sensorData blackCalibration;
    blackCalibration.value[TCS230_RGB_R] = 0;
    blackCalibration.value[TCS230_RGB_G] = 0;
    blackCalibration.value[TCS230_RGB_B] = 0;

    color_sensor.begin();
    color_sensor.setDarkCal(&blackCalibration);
    color_sensor.setWhiteCal(&whiteCalibration);
}

void loop() 
{
    colorData rgb;
    color_sensor.read();
    buzzer.play_sound();
    
    while (!color_sensor.available()){}
    color_sensor.getRGB(&rgb);
    int note = get_note_by_color(rgb);
    buzzer.set_note_pitch(note);
    print_rgb(rgb);
}

int get_note_by_color(colorData rgb) 
{
  RGB sensor_color = color_data_to_rgb(rgb);
  for (int i = 0; i < note_colors_length; i++)
  {
    if (equal_colors(sensor_color, note_colors[i].color))
      return note_colors[i].note;
  }

  return NOTE_SILENCE;
}

RGB color_data_to_rgb(colorData rgb)
{
  int red = 255 - rgb.value[TCS230_RGB_R];
  int green = 255 - rgb.value[TCS230_RGB_G];
  int blue = 255 - rgb.value[TCS230_RGB_B];
  return RGB(red, green, blue);
}

bool equal_colors(RGB first, RGB second)
{
  if (!values_equal_with_delta(first.red, second.red))
    return false;
  if (!values_equal_with_delta(first.green, second.green))
    return false;
  if (!values_equal_with_delta(first.blue, second.blue))
    return false;
  return true;
}

bool values_equal_with_delta(int first, int second)
{
  return abs(first - second) <= COLOR_DELTA;
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
