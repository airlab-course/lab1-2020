#pragma once

class Buzzer
{
public:
    Buzzer(int _pin)
    {
        pin = _pin;
        pinMode(pin, OUTPUT);

        isEnabled = false;
        currentNote = 0;
        noteStartedMs = 0;

        notes = 0;
        durations = 0;
        melodyLength = 0;
        noteDuration = 100;
    }

    void turnSoundOn()
    {
        isEnabled = true;
        currentNote = 0;
        noteStartedMs = 0;
    }

    void turnSoundOff()
    {
        isEnabled = false;
        currentNote = 0;
        noteStartedMs = 0;
        noTone(pin);
    }

    void setMelody(int _notes[], double _durations[], int _melodyLength)
    {
        notes = _notes;
        durations = _durations;
        melodyLength = _melodyLength;
    }

    void speedUp(double speedMultiplier)
    {
        double newNoteDuration = noteDuration / speedMultiplier;
        if (newNoteDuration >= 1)
        {
            noteDuration = newNoteDuration;
        }
    }

    void speedDown(double speedMultiplier)
    {
        noteDuration *= speedMultiplier;
    }

    void playSound()
    {
        if (!isEnabled)
            return;

        unsigned long duration = round(noteDuration*durations[currentNote]);
        if ((millis() - noteStartedMs) > duration)
        {
            int note = notes[currentNote];
            
            if (note == NOTE_SILENCE)
                noTone(pin);
            else 
                tone(pin, notes[currentNote]);

            noteStartedMs = millis();
            currentNote = (currentNote + 1)%melodyLength;
        }
    }

private:
    int pin;
    bool isEnabled;

    int currentNote;
    unsigned long noteStartedMs;

    int* notes;
    double* durations;
    int melodyLength;
    double noteDuration;
};
