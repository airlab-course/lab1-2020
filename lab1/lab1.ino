int LED[8] = {0, 0, 0, 0 ,0, 0, 0, 0}; // 1 2 4 8 16 32 64 128

void setup()
{
  for(int i = 0; i < 8; i++)
  {
    pinMode(LED[i], OUTPUT);
  }
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
  for(int i = 0; i < 8; i++)
  {
    digitalWrite(LED[i], is_bit_set(num, i));
  }
}
