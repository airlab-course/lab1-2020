int LED_128[] = {13, 12, 11};
int LED_64[] = {10, 9, 8};
int LED_32[] = {7, 6, 5};
int LED_16[] = {4, 3, 2};
int LED_8[] = {32, 30, 28};
int LED_4[] = {26, 24, 22};
int LED_2[] = {27, 25, 23};
int LED_1[] = {33, 31, 29};

int bin[8];

void setup()
{
  led_output(LED_128);
  led_output(LED_64);
  led_output(LED_32);
  led_output(LED_16);
  led_output(LED_8);
  led_output(LED_4);
  led_output(LED_2);
  led_output(LED_1);
}

void loop() 
{
  int number = readInput();
  convert_to_bin(number);
  bin_to_led();
}

void led_output(int led[])
{
  for(int i = 0; i < 3; i++)
  {
    pinMode(led[i], OUTPUT);
  }
}


int readInput()
{
    while (!Serial.available());
    return Serial.parseInt();
}

void convert_to_bin(int num)
{
  int index = 7;
  while (num > 0)
  {
    bin[index] = num%2;
    num /= 2;
    index--;
  }
}

void bin_to_led()
{
  set_led(LED_128, bin[0]);
  set_led(LED_64, bin[1]);
  set_led(LED_32, bin[2]);
  set_led(LED_16, bin[3]);
  set_led(LED_8, bin[4]);
  set_led(LED_4, bin[5]);
  set_led(LED_2, bin[6]);
  set_led(LED_1, bin[7]);
}

void set_led(int led[], bool on)
{
  for(int i = 0; i < 3; i++)
  {
    digitalWrite(led[i], 1*on);
  }
}
