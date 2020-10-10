#define ledsCount 6

void ledPin(int firstLed, int secondLed){
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    analogWrite(firstLed, fadeValue);
    analogWrite(secondLed, fadeValue);
    delay(30);
  }
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    analogWrite(firstLed, fadeValue);
    analogWrite(secondLed, fadeValue);
    delay(30);
  }
}

int leds[ledsCount] = {2, 3, 4, 5, 6, 7};
void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  for (int i = 0; i < 3; i++){
    ledPin(leds[i],leds[i+3]);
  }
}
