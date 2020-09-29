#include "pitches.h"

#define PIN_BUTTON_A 3
#define PIN_BUTTON_B 4
#define PIN_BUTTON_C 5
#define PIN_BUTTON_D 6
#define PIN_BUTTON_E 7
#define PIN_BUTTON_F 8
#define PIN_BUTTON_G 9
#define PIN_BUTTON_H 10

#define PIN_BUZZER 11
#define LED 13

typedef struct { 
    int pin;
    int note;
} pinNote;

const pinNote pinToNote[] {
    {PIN_BUTTON_A, NOTE_A4},
    {PIN_BUTTON_B, NOTE_B4},
    {PIN_BUTTON_C, NOTE_C4},
    {PIN_BUTTON_D, NOTE_D4},
    {PIN_BUTTON_E, NOTE_E4},
    {PIN_BUTTON_F, NOTE_F4},
    {PIN_BUTTON_G, NOTE_G4}
};

void setup()
{
    pinMode(LED, OUTPUT);

    for(int i = 0; i < sizeof(pinToNote)/sizeof(pinNote); ++i) {
        int pin = pinToNote[i].pin;
        pinMode(pin, INPUT);
        digitalWrite(pin, HIGH);
    }

    digitalWrite(LED,LOW);
}

void loop()
{
    for(int i = 0; i < sizeof(pinToNote)/sizeof(pinNote); ++i) {
        pinNote pinNote = pinToNote[i];
        while(digitalRead(pinNote.pin) == LOW)
        {
            tone(PIN_BUZZER, pinNote.note);
            digitalWrite(LED, HIGH);
        }
        
    }

    noTone(PIN_BUZZER);
    digitalWrite(LED,LOW);
}
