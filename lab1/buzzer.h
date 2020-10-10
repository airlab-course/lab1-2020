#pragma once
#include <toneAC.h>
#include "pitches.h"

#define BUZZER_NOTE_DURATION 1000

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
        if (_note == NOTE_SILENCE)
            noToneAC();
        else 
            toneAC(_note);
    }

private:
    int _pin;
    int _note;
    unsigned long _note_started_ms;
    double _duration;
};
