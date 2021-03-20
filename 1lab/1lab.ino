#include "button.h"
#define buttonPin 1

int q = 6;
int d = 1;
int t1 = 300;
int t2 = 100;
int t3 = 10;
int ledPins[] = {2,3,4,5,6,7};
int ledControle = 6;

Button buttonOn(buttonPin);

void setup() 
{
  for (int i=0; i<q; i++){ 
    pinMode(ledPins[i],OUTPUT);
    }
    pinMode(ledControle, OUTPUT);
}

void loop() {
  delay(10);
  button();
  }
void button() {
  if (buttonOn.wasPressed()) {
       d++;
       if (d>3) { 
        d=1;
       }
  }

switch (d) {
        
        case 1:
       
  for (int i=0; i<q; i++){
    digitalWrite(ledPins[i],HIGH);
    delay(t3);
    if (buttonOn.wasPressed()) {
       d++;
       break;
       }
    for (int i=0; i<q; i++){
    digitalWrite(ledPins[i],LOW);
    if (buttonOn.wasPressed()) {
       d++;
       break;
       }
  } 
  }
break;
        case 2:

    for (int i=0; i<q; i++){
    digitalWrite(ledPins[i],HIGH);
    delay(t1);
    if (buttonOn.wasPressed()) {
       d++;
       break;
       }
    for (int i=0; i<q; i++){
    digitalWrite(ledPins[i],LOW);
    if (buttonOn.wasPressed()) {
       d++;
       break;
       }
  } 
  }
break;

case 3:
for (int i=0; i<q-2; i++){
    digitalWrite(ledPins[i],HIGH);
    delay(t1);
    if (buttonOn.wasPressed()) {
       d++;
       break;
       }
       }
break;

}
}
