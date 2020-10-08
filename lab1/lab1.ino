int LED[8] = {6, 7, 8, 9 ,10, 11, 12, 13}; // 1 2 4 8 16 32 64 128

void setup()
{
  Serial.begin(115200);
  for(int i = 0; i < 8; i++)
  {
    pinMode(LED[i], OUTPUT);
  }
}

void loop() 
{
  int number = readInput();
  Serial.println(number);
  num_to_led(number);
}

int readInput()
{
    while(!Serial.available());
    String input = Serial.readStringUntil('\n');
    return input.toInt();
}

bool is_bit_set(int number, int bit)
{
  return number & 1 << bit;
}

void num_to_led(int num)
{
  for(int i = 0; i < 8; i++)
  {
    digitalWrite(LED[i], 1 - is_bit_set(num, i));
  }
}
