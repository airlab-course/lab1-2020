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


MD_TCS230 color_sensor(S2_OUT, S3_OUT, S0_OUT, S1_OUT);
buzzer buzzer(PIN_BUZZER);

struct Color
{
    int red, green, blue;
    Color(int r, int g, int b)
    {
      red = r;
      green = g;
      blue = b;
    }

    
    bool equal(Color second)
    {
    if (equal_delta(red, second.red) &&
      equal_delta(green, second.green) &&
      equal_delta(blue, second.blue)){
        return true;
      }
    
    return false;
  }

  bool equal_delta(int col_1, int col_2)
  {
    return abs(col_1 - col_2) <= COLOR_DELTA;
  }
};

struct note_color
{
  int note;
  Color color;
};

note_color note_colors[] 
{
  {NOTE_C4, Color(0, 0, 0)},
  {NOTE_D4, Color(245, 245, 245)},
  {NOTE_E4, Color(245, 0, 0)},
  {NOTE_F4, Color(0, 245, 0)},
  {NOTE_G4, Color(0, 0, 245)},
  {NOTE_A4, Color(245, 245, 0)},
  {NOTE_B4, Color(245, 0, 245)}
};

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

int get_note_by_color(colorData color) 
{
  Color sensor_color = to_standard_rgb(color);
  
  int len = sizeof(note_colors) / sizeof(*note_colors);

  for (int i = 0; i < len; i++)
  {
    if (sensor_color.equal( note_colors[i].color))
      return note_colors[i].note;
  }

  return NOTE_SILENCE;
}

Color to_standard_rgb(colorData color)
{
  int red = 255 - color.value[TCS230_RGB_R];
  int green = 255 - color.value[TCS230_RGB_G];
  int blue = 255 - color.value[TCS230_RGB_B];
  return Color(red, green, blue);
}



void print_rgb(colorData color)
{
    Serial.print(color.value[TCS230_RGB_R]);
    Serial.print(" ");
    Serial.print(color.value[TCS230_RGB_G]);
    Serial.print(" ");
    Serial.print(color.value[TCS230_RGB_B]);
    Serial.println();
}
