#include "button.h"

#define R_OUT 2
#define G_OUT 3
#define B_OUT 4
#define R_INC_BT_PIN 5
#define G_INC_BT_PIN 6
#define B_INC_BT_PIN 7
#define R_DEC_BT_PIN 8
#define G_DEC_BT_PIN 9
#define B_DEC_BT_PIN 10
#define INC_VALUE 16
#define DEC_VALUE 16

int channels[] = {R_OUT, G_OUT, B_OUT};
int channel_values[] = {0, 0, 0};
Button channel_inc_buttons[] = {{R_INC_BT_PIN}, {G_INC_BT_PIN}, {B_INC_BT_PIN}};
Button channel_dec_buttons[] = {{R_DEC_BT_PIN}, {G_DEC_BT_PIN}, {B_DEC_BT_PIN}};

void setup()
{
  for (int i = 0; i < 3; i++)
    pinMode(channels[i], OUTPUT);
}

void loop()
{ 
  apply_actions();
  set_up_led();
}

void apply_actions()
{
  for (int i = 0; i < 3; i++)
  {
    int delta = 0;
    if (channel_inc_buttons[i].wasPressed())
      delta += INC_VALUE;
    if (channel_dec_buttons[i].wasPressed())
      delta -= DEC_VALUE;

    channel_values[i] += delta;
    if (channel_values[i] < 0)
      channel_values[i] = 256 + (channel_values[i] % 256);
    channel_values[i] %= 256;
  }
}

void set_up_led()
{
  for (int i = 0; i < 3; i++)
    analogWrite(channels[i], 255 - channel_values[i]);
}
