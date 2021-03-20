#include <EEPROM.h>

int qtd = 9;
int qtdSequencia = 10;
int led[] = { 2,3,4,5,6,7,8,9,10,};
int ledControle = 12;
int controle = 0;
 
void setup(){
  for (int i=0; i<qtd; i++){ 
    pinMode(led[i],OUTPUT);
  }
  pinMode(ledControle,OUTPUT); 
  LeEEPROM();
}
 
void loop(){
  delay(10);
  VerificaBotaoControle();
  if (controle == 0){
    
    for (int j=1; j<=qtdSequencia; j++){
      for (int i=0; i<5; i++){
        sequencia(j);
        if (controle != 0) break; 
      }
      if (controle != 0) break;   
    }
  }
  else{
    sequencia(controle);
  }
}
 
void VerificaBotaoControle(){
  if (analogRead(5) > 1000){
    ApagaTodos();
    delay(1000);
    controle++;
    if (controle > qtdSequencia){
      controle = 0;
    }
  }
  if (controle == 0){
    digitalWrite(ledControle,HIGH);
  }
  else{
    digitalWrite(ledControle,LOW);
  }
  GravaEEPROM();
}
 
void LeEEPROM(){
  controle = EEPROM.read(0);
}
 
void GravaEEPROM(){
  EEPROM.write(0,controle);
}
 
void AcendeTodos(){
  for (int i=0; i<qtd; i++){
    digitalWrite(led[i],HIGH);
  }
}
 
void ApagaTodos(){
  for (int i=0; i<qtd; i++){
    digitalWrite(led[i],LOW);
  }
}
 
void sequencia(int s){
  switch (s){
  case 1:
    s1();
    break;
  case 2:
    s2();
    break;
  case 3:
    s3();
    break;
  case 4:
    s4();
    break;
  case 5:
    s5();
    break;
  case 6:
    s6();
    break;
  case 7:
    s7();
    break;
  case 8:
    s8();
    break;
  case 9:
    s9();
    break;
  case 10:
    s10();
    break;
  }
}
 
void s1(){
  int t1 = 40;
  VerificaBotaoControle();
  ApagaTodos();
  for (int i=0; i<qtd; i++){
    digitalWrite(led[i],HIGH);
    delay(t1);
    VerificaBotaoControle();
  }
  for (int i=0; i<qtd; i++){
    digitalWrite(led[i],LOW);
    delay(t1);
    VerificaBotaoControle();
  }
}
 
void s2(){
  int t1 = 40;
  VerificaBotaoControle();
  ApagaTodos();
  for (int i=0; i<qtd; i++){
    digitalWrite(led[i],HIGH);
    delay(t1);
    VerificaBotaoControle();
  }
  for (int i=0; i<qtd-1; i++){
    digitalWrite(led[i],LOW);
    delay(t1);
    VerificaBotaoControle();
  }
  for (int i=qtd-1; i>=0; i--){
    digitalWrite(led[i],HIGH);
    delay(t1);
    VerificaBotaoControle();
  }
  for (int i=qtd-1; i>0; i--){
    digitalWrite(led[i],LOW);
    delay(t1);
    VerificaBotaoControle();
  }
}
 
void s3(){
  int t1 = 50;
  VerificaBotaoControle();
  ApagaTodos();
  for (int i=0; i<qtd/2; i++){
    digitalWrite(led[i],HIGH);
    digitalWrite(led[qtd-1-i],HIGH);
    delay(t1);
    VerificaBotaoControle();
  }
  for (int i=0; i<(qtd/2)-1; i++){
    digitalWrite(led[i],LOW);
    digitalWrite(led[qtd-1-i],LOW);
    delay(t1);
    VerificaBotaoControle();
  }
  for (int i=(qtd/2)-2; i>=0; i--){
    digitalWrite(led[i],HIGH);
    digitalWrite(led[qtd-1-i],HIGH);
    delay(t1);
    VerificaBotaoControle();
  }
  for (int i=(qtd/2)-1; i>0; i--){
    digitalWrite(led[i],LOW);
    digitalWrite(led[qtd-1-i],LOW);
    delay(t1);
    VerificaBotaoControle();
  }
}
 
void s4(){
  int t1 = 50;
  VerificaBotaoControle();
  ApagaTodos();
  for (int j=0; j<qtd/2; j++){
    for (int i=0; i<qtd/2; i++){
      digitalWrite(led[i],HIGH);
    }
    delay(t1);
    for (int i=0; i<qtd/2; i++){
      digitalWrite(led[i],LOW);
    }
    delay(t1);
    VerificaBotaoControle();
  }
  ApagaTodos();
  for (int j=0; j<qtd/2; j++){
    for (int i=qtd/2; i<qtd; i++){
      digitalWrite(led[i],HIGH);
    }
    delay(t1);
    for (int i=qtd/2; i<qtd; i++){
      digitalWrite(led[i],LOW);
    }
    delay(t1);
    VerificaBotaoControle();
  }
}
 
void s5(){
  int t1 = 50;
  int t2 = 300;
  VerificaBotaoControle();
  for (int i=0; i<qtd-1; i++){
    AcendeTodos();
    delay(t1);
    ApagaTodos();
    delay(t1);
    VerificaBotaoControle();
  }
  delay(t2);
}
 
void s6(){
  int t1 = 10;
  int t2 = 100;
  VerificaBotaoControle();
  ApagaTodos();
  for (int i=0; i<qtd; i++){
    digitalWrite(led[i],HIGH);
    delay(t1);
    digitalWrite(led[i],LOW);
    delay(t2);
    VerificaBotaoControle();
  }
}
 
void s7(){
  randomSeed(analogRead(0));  
  int t1 = 10;
  int t2 = 100;
  int p = random(qtd);
  VerificaBotaoControle();
  ApagaTodos();
  for (int i=0; i<15; i++){
    digitalWrite(led[p],HIGH);
    delay(t1);
    digitalWrite(led[p],LOW);
    delay(t2);
    p = random(qtd);
    VerificaBotaoControle();
  }
}
 
void s8(){
  int t1 = 10;
  VerificaBotaoControle();
  for (int i=0; i<2; i++){
    AcendeTodos();
    delay(t1);
    ApagaTodos();
    for (int x=0; x<100; x++){
      VerificaBotaoControle();
      delay(t1);
    }
  }
}
 
void s9(){
  int t1 = 60;
  VerificaBotaoControle();
  ApagaTodos();
  for (int i=1; i<qtd; i++){
    digitalWrite(led[i-2],LOW);
    digitalWrite(led[i-1],LOW);
    digitalWrite(led[i],HIGH);
    delay(t1);
    digitalWrite(led[i],LOW);
    digitalWrite(led[i-1],HIGH);
    delay(t1);
    VerificaBotaoControle();
  }
}
 
void s10(){
  int t1 = 150;
  VerificaBotaoControle();
  ApagaTodos();
  for (int x=0; x<3; x++){
    for (int i=0; i<qtd; i++){
      if (i%2 == 0){
        digitalWrite(led[i],HIGH);
      }
      else{
        digitalWrite(led[i],LOW);
      }
    }
    VerificaBotaoControle();
    delay(t1);
    for (int i=0; i<qtd; i++){
      if (i%2 == 0){
        digitalWrite(led[i],LOW);
      }
      else{
        digitalWrite(led[i],HIGH);
      }
    }
    VerificaBotaoControle();
    delay(t1);
  }
}
 
void s11(){
  int t1 = 40;
  int t2 = 300;
  VerificaBotaoControle();
  ApagaTodos();
  delay(t2);
  for (int i=0; i<qtd; i++){
    if (i != 0){
      digitalWrite(led[i-1],LOW);
    }
    digitalWrite(led[i],HIGH);
    delay(t1);
    VerificaBotaoControle();
  }
  for (int i=0; i<qtd-1; i++){
    if (i != 0){
      digitalWrite(led[i-1],LOW);
    }
    digitalWrite(led[i],HIGH);
    delay(t1);
    VerificaBotaoControle();
  }
  for (int i=0; i<qtd-2; i++){
    if (i != 0){
      digitalWrite(led[i-1],LOW);
    }
    digitalWrite(led[i],HIGH);
    delay(t1);
    VerificaBotaoControle();
  }
  for (int i=0; i<qtd-3; i++){
    if (i != 0){
      digitalWrite(led[i-1],LOW);
    }
    digitalWrite(led[i],HIGH);
    delay(t1);
    VerificaBotaoControle();
  }
  for (int i=0; i<qtd-4; i++){
    if (i != 0){
      digitalWrite(led[i-1],LOW);
    }
    digitalWrite(led[i],HIGH);
    delay(t1);
    VerificaBotaoControle();
  }
  for (int i=0; i<qtd-5; i++){
    if (i != 0){
      digitalWrite(led[i-1],LOW);
    }
    digitalWrite(led[i],HIGH);
    delay(t1);
    VerificaBotaoControle();
  }
  for (int i=0; i<qtd-6; i++){
    if (i != 0){
      digitalWrite(led[i-1],LOW);
    }
    digitalWrite(led[i],HIGH);
    delay(t1);
    VerificaBotaoControle();
  }
  for (int i=0; i<qtd-7; i++){
    if (i != 0){
      digitalWrite(led[i-1],LOW);
    }
    digitalWrite(led[i],HIGH);
    delay(t1);
    VerificaBotaoControle();
  }
  for (int i=0; i<qtd-8; i++){
    if (i != 0){
      digitalWrite(led[i-1],LOW);
    }
    digitalWrite(led[i],HIGH);
    delay(t1);
    VerificaBotaoControle();
  }
  delay(t1);
  VerificaBotaoControle();
  digitalWrite(led[0],HIGH);
  delay(t2);
  for (int i=0; i<qtd; i++){
    if (i != 0){
      digitalWrite(led[i-1],HIGH);
    }
    digitalWrite(led[i],LOW);
    delay(t1);
    VerificaBotaoControle();
  }
  for (int i=0; i<qtd-1; i++){
    if (i != 0){
      digitalWrite(led[i-1],HIGH);
    }
    digitalWrite(led[i],LOW);
    delay(t1);
    VerificaBotaoControle();
  }
  for (int i=0; i<qtd-2; i++){
    if (i != 0){
      digitalWrite(led[i-1],HIGH);
    }
    digitalWrite(led[i],LOW);
    delay(t1);
    VerificaBotaoControle();
  }
  for (int i=0; i<qtd-3; i++){
    if (i != 0){
      digitalWrite(led[i-1],HIGH);
    }
    digitalWrite(led[i],LOW);
    delay(t1);
    VerificaBotaoControle();
  }
  for (int i=0; i<qtd-4; i++){
    if (i != 0){
      digitalWrite(led[i-1],HIGH);
    }
    digitalWrite(led[i],LOW);
    delay(t1);
    VerificaBotaoControle();
  }
  for (int i=0; i<qtd-5; i++){
    if (i != 0){
      digitalWrite(led[i-1],HIGH);
    }
    digitalWrite(led[i],LOW);
    delay(t1);
    VerificaBotaoControle();
  }
  for (int i=0; i<qtd-6; i++){
    if (i != 0){
      digitalWrite(led[i-1],HIGH);
    }
    digitalWrite(led[i],LOW);
    delay(t1);
    VerificaBotaoControle();
  }
  for (int i=0; i<qtd-7; i++){
    if (i != 0){
      digitalWrite(led[i-1],HIGH);
    }
    digitalWrite(led[i],LOW);
    delay(t1);
    VerificaBotaoControle();
  }
  for (int i=0; i<qtd-8; i++){
    if (i != 0){
      digitalWrite(led[i-1],HIGH);
    }
    digitalWrite(led[i],LOW);
    delay(t1);
    VerificaBotaoControle();
  }
  delay(t1);
  VerificaBotaoControle();
  digitalWrite(led[0],LOW);
  delay(t1);
}
