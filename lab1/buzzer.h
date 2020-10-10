#pragma once
#include <toneAC.h>
#include "pitches.h"

#define BUZZER_NOTE_DURATION 100

class buzzer
{
public:
    buzzer(int pin, double note_duration = 1)
    {
        _pin = pin;
        pinMode(pin, OUTPUT);
        _note = NOTE_SILENCE;
        _duration = note_duration;
        _note_started_ms = 0;
    }

    void set_note_pitch(int note)
    {
        _note = note;
    }

    void play_sound()
    {
        unsigned long duration = round(BUZZER_NOTE_DURATION * _duration);
        if ((millis() - _note_started_ms) > duration)
        {
            if (_note == NOTE_SILENCE)
                noToneAC();
            else 
                toneAC(_note, 10, BUZZER_NOTE_DURATION);

            _note_started_ms = millis();
        }
    }

private:
    int _pin;
    int _note;
    unsigned long _note_started_ms;
    double _duration;
};
