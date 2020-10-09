#include "pitches.h"
#include "button.h"
#include "buzzer.h"


#define PIN_BUTTON_1 1
Button button1(PIN_BUTTON_1);

#define PIN_BUTTON_2 2
Button button2(PIN_BUTTON_2);

#define PIN_BUTTON_3 3
Button button3(PIN_BUTTON_3);

#define PIN_BUTTON_4 4
Button button4(PIN_BUTTON_4);

#define PIN_BUTTON_5 5
Button button5(PIN_BUTTON_5);

#define PIN_BUTTON_6 6
Button button6(PIN_BUTTON_6);

#define PIN_BUTTON_7 7
Button button7(PIN_BUTTON_7);

#define PIN_BUTTON_8 8
Button button8(PIN_BUTTON_8);

#define PIN_BUZZER 9
Buzzer buzzer(PIN_BUZZER);


void setup() {

}
void playNote(int note) {
  int[] ns = {note}
  int[] ds = {1}
  buzzer.setMelody(ns, ds, 1)
  buzzer.turnSoundOn()
  buzzer.playSound()
}
void loop() {
    if (button1.wasPressed())
    {
      playNote(NOTE_C1)
    }
    if (button2.wasPressed())
    {
      playNote(NOTE_C2)
    }
    if (button3.wasPressed())
    {
      playNote(NOTE_C3)
    }
    if (button4.wasPressed())
    {
      playNote(NOTE_C4)
    }
    if (button5.wasPressed())
    {
      playNote(NOTE_C5)
    }
    if (button6.wasPressed())
    {
      playNote(NOTE_C6)
    }
    if (button7.wasPressed())
    {
      playNote(NOTE_C7)
    }
    if (button8.wasPressed())
    {
      playNote(NOTE_C8)
    }
    if (buttonOff.wasPressed())
    {
        buzzer.turnSoundOff();
    }
}
