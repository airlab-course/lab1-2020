#define PIN_LED 12  
#define BUZZER_PIN_1 10 
#define BUZZER_PIN_2 8
#include "buzzer.h"

int buttonPin[2] = {3, 13};
int ledPin[2] = {9, 11};
int randomNumber;
void setup()
{
  pinMode(PIN_LED, OUTPUT);
  pinMode(BUZZER_PIN_1, OUTPUT);
  pinMode(BUZZER_PIN_2, OUTPUT);
  
  for (int player = 0; player < 2; ++player) {
    pinMode(ledPin[player], OUTPUT);
    pinMode(buttonPin[player], INPUT_PULLUP);
  }

}
 
void loop()
{
  randomNumber = random(2000,6000);
  delay(randomNumber);
  digitalWrite(PIN_LED, HIGH);
  for (int player = 0; ; player = (player+1) % 2) {
    if (!digitalRead(buttonPin[player])) {
      digitalWrite(ledPin[player], HIGH);
      if (player == 0)
      {
        tone(BUZZER_PIN_1, 4000, 1000); //играем мелодию игрока 1
      }
      else 
      {
        tone(BUZZER_PIN_2, 2000, 3000); //играем мелодию игрока 2
      }
      digitalWrite(PIN_LED, LOW);
      delay(1000);
      digitalWrite(ledPin[player], LOW);
    buzzer.playSound();
    if (buttonOff.wasPressed())
    {
        buzzer.turnSoundOff(); 
    }
      break; 
    }
  }
}
