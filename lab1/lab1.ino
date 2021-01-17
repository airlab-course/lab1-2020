#define PIN_LED 12  // пин с пищалкой
#define PLAYER_COUNT 2   // количество игроков-ковбоев
// вместо перечисления всех пинов по-одному, мы объявляем пару
// списков: один с номерами пинов с кнопками, другой — со
// светодиодами. Списки также называют массивами (англ. array)
int buttonPins[PLAYER_COUNT] = {3, 13};
int ledPins[PLAYER_COUNT] = {9, 11};
int randomNumber;
void setup()
{
  pinMode(PIN_LED, OUTPUT);
  for (int player = 0; player < PLAYER_COUNT; ++player) {
    // при помощи квадратных скобок получают значение в массиве
    // под указанным в них номером. Нумерация начинается с нуля
    pinMode(ledPins[player], OUTPUT);
    pinMode(buttonPins[player], INPUT_PULLUP);
  }
}
 
void loop()
{
  // даём сигнал «пли!», выждав случайное время от 2 до 7 сек
  randomNumber = random(2000,6000);
  delay(randomNumber);
  digitalWrite(PIN_LED, HIGH);
 
  for (int player = 0; ; player = (player+1) % PLAYER_COUNT) {
    // если игрок номер «player» нажал кнопку...
    if (!digitalRead(buttonPins[player])) {
      // ...включаем его светодиод и сигнал победы на 1 сек
      digitalWrite(ledPins[player], HIGH);
      digitalWrite(PIN_LED, LOW);

      delay(1000);
      digitalWrite(ledPins[player], LOW);
      break; // Есть победитель! Выходим (англ. break) из цикла
    }
  }
}
