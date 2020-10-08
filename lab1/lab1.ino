#define LED_128 0
#define LED_64 0
#define LED_32 0
#define LED_16 0
#define LED_8 0
#define LED_4 0
#define LED_2 0
#define LED_1 0


void setup()
{
  pinMode(LED_128, OUTPUT);
  pinMode(LED_64, OUTPUT);
  pinMode(LED_32, OUTPUT);
  pinMode(LED_16, OUTPUT);
  pinMode(LED_8, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_1, OUTPUT);
}

void loop() 
{
  int number = readInput();
  num_to_led(number);
}

int readInput()
{
    while (!Serial.available());
    return Serial.parseInt();
}

bool is_bit_set(int number, int bit)
{
  return number & 1 << bit;
}

void num_to_led(int num)
{
  digitalWrite(LED_128, is_bit_set(num, 7));
  digitalWrite(LED_64, is_bit_set(num, 6));
  digitalWrite(LED_32, is_bit_set(num, 5));
  digitalWrite(LED_16, is_bit_set(num, 4));
  digitalWrite(LED_8, is_bit_set(num, 3));
  digitalWrite(LED_4, is_bit_set(num, 2));
  digitalWrite(LED_2, is_bit_set(num, 1));
  digitalWrite(LED_1, is_bit_set(num, 0));
}
