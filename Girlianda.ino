#include <EEPROM.h>
uint8_t mode=0;
uint16_t counter; 
uint8_t val=0; 
bool reverse=false; 
uint8_t cc=0; 
int addr = 0; 
#define pinLed 10 



void setup(){

  
  pinMode(pinLed, OUTPUT);
  



mode = EEPROM.read(0);


if(mode==11){EEPROM.write(addr, 0);}

else{
EEPROM.write(addr, mode+1);
}


  }







void fake_interrupt(){


digitalWrite(pinLed,HIGH);

delayMicroseconds(val);

digitalWrite(pinLed,LOW);

delayMicroseconds(val);


counter=0;
}








  void loop(){
 


switch(mode){

//Режим 1
case 0:

if(!reverse){

analogWrite(pinLed,val);
delay(9);
val++;

if(val==255){reverse=true;}
}

if(reverse){
  val--;
  if(val==0){reverse=false;return;}
  analogWrite(pinLed,val);
  delay(9);
  }
;break;


//Режим 2

case 1:
if(!reverse){
analogWrite(pinLed,val);
delay(1);
val++;
if(val==255){reverse=true;}
}


if(reverse){
  val--;
  if(val==0){reverse=false;return;}
  analogWrite(pinLed,val);
  delay(1);
  }

;break;

//Режим 3

case 2:
digitalWrite(pinLed,HIGH);
delay(500);
digitalWrite(pinLed,LOW);
delay(500);  

;break;

//Режим 4

case 3:
  digitalWrite(pinLed,HIGH);
  delay(20);
  digitalWrite(pinLed,LOW);
  delay(20);
;break;


//Режим 5
case 4:

counter++;

 if(counter>=512){fake_interrupt();delay(33);val++;}
  
  
;break;

//Режим 6
case 5:

for(int i=0;i<127;i++){
analogWrite(pinLed,i);
delay(10);
}

//Ждать 50 мс

analogWrite(pinLed,255);

delay(50);

for(int i=127;i>0;i--){
analogWrite(pinLed,i);
delay(10);
}

delay(50);
analogWrite(pinLed,0);
delay(50);


;break;

//Быстрое мигание
 case 6:
  digitalWrite(pinLed,HIGH);
  delay(55);
  digitalWrite(pinLed,LOW);
  delay(55);
;break;


//Ступенька
case 7:
analogWrite(pinLed,0);
delay(200);

analogWrite(pinLed,255);
delay(200);
analogWrite(pinLed,127);
delay(200);
analogWrite(pinLed,127);
delay(200);


analogWrite(pinLed,255);
delay(200);
analogWrite(pinLed,127);
delay(200);
analogWrite(pinLed,63);
delay(200);

break;


//Биение сердца
case 8:

analogWrite(pinLed,63);
delay(200);
analogWrite(pinLed,127);
delay(200);

analogWrite(pinLed,50);
delay(400);

analogWrite(pinLed,63);
delay(200);
analogWrite(pinLed,127);
delay(200);

break;

//Лампа с плохим контактом
case 9:

for(int i=0;i<94;i++){
  
analogWrite(pinLed,i);
delay(20);
}

analogWrite(pinLed,0);
delay(999);
break;

//Среднее переливание/волна
case 10:

for(int i=32;i<190;i++){
analogWrite(pinLed,i);
delay(15);
}



for(int i=190;i>32;i--){
analogWrite(pinLed,i);
delay(15);
}


break;

//Светодиод светиться 7 секунд, 7 секунд не светится
case 11:

analogWrite(pinLed,255);
delay(7000);

analogWrite(pinLed,0);
delay(7000);

break;

  }//switch

    
 }//loop
