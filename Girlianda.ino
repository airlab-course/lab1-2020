

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}
void loop() {
  //Первый эффект.
  digitalWrite(3, HIGH);
  delay(500);              
  digitalWrite(3, LOW);
  delay(500);              
  digitalWrite(4, HIGH); 
  delay(500);              
  digitalWrite(4, LOW); 
  delay(500);              
  digitalWrite(5, HIGH); 
  delay(500);              
  digitalWrite(5, LOW);  
  delay(500);              
  digitalWrite(6, HIGH); 
  delay(500);              
  digitalWrite(6, LOW);
  delay(500);              
  digitalWrite(7, HIGH);   
  delay(500);              
  digitalWrite(7, LOW);    
  delay(500);              
  
  //Второй эффект.
  digitalWrite(3, HIGH);   
  delay(200);              
  digitalWrite(4, HIGH);   
  delay(200);              
  digitalWrite(5, HIGH);   
  delay(200);              
  digitalWrite(6, HIGH);   
  delay(200);              
  digitalWrite(7, HIGH);   
  delay(200);              
  digitalWrite(7, LOW);   
  delay(200);              
  digitalWrite(6, LOW);   
  delay(200);              
  digitalWrite(5, LOW);   
  delay(200);              
  digitalWrite(4, LOW);   
  delay(200);              
  digitalWrite(3, LOW);   
  delay(200);             
 
  //Третий эффект.
  digitalWrite(3, HIGH);   
  digitalWrite(4, HIGH);   
  digitalWrite(5, HIGH);   
  digitalWrite(6, HIGH);  
  digitalWrite(7, HIGH);   
  delay(1000);              
  digitalWrite(3, LOW);    
  digitalWrite(4, LOW);   
  digitalWrite(5, LOW);    
  digitalWrite(6, LOW);    
  digitalWrite(7, LOW);    
  delay(1000);            
  digitalWrite(3, HIGH);   
  digitalWrite(4, HIGH);   
  digitalWrite(5, HIGH);   
  digitalWrite(6, HIGH);   
  digitalWrite(7, HIGH);   
  delay(1000);              
  digitalWrite(3, LOW);    
  digitalWrite(4, LOW);    
  digitalWrite(5, LOW);    
  digitalWrite(6, LOW);   
  digitalWrite(7, LOW);    
  delay(1000);             
  
   //Четвертый эффект.
  digitalWrite(3, HIGH);   
  delay(100);              
  digitalWrite(3, LOW);   
  delay(100);             
  digitalWrite(4, HIGH);   
  delay(100);              
  digitalWrite(4, LOW);    
  delay(100);              
  digitalWrite(5, HIGH);   
  delay(100);              
  digitalWrite(5, LOW);   
  delay(100);              
  digitalWrite(6, HIGH);   
  delay(100);              
  digitalWrite(6, LOW);    
  delay(100);              
  digitalWrite(7, HIGH);   
  delay(100);              
  digitalWrite(7, LOW);    
  delay(100);              
  digitalWrite(6, HIGH);   
  delay(100);              
  digitalWrite(6, LOW);    
  delay(100);              
  digitalWrite(5, HIGH);   
  delay(100);              
  digitalWrite(5, LOW);    
  delay(100);              
  digitalWrite(4, HIGH);   
  delay(100);              
  digitalWrite(4, LOW);    
  delay(100);              
  digitalWrite(3, HIGH);   
  delay(100);              
  digitalWrite(3, LOW);    
  delay(100);              
 
  //Пятый эффект.
  digitalWrite(3, HIGH);   
  digitalWrite(7, HIGH);  
  delay(200);              
  digitalWrite(4, HIGH);   
  digitalWrite(6, HIGH);   
  delay(200);              
  digitalWrite(5, HIGH);    
  delay(300);              
  digitalWrite(3, LOW);   
  digitalWrite(4, LOW);    
  digitalWrite(5, LOW);    
  digitalWrite(6, LOW);   
  digitalWrite(7, LOW);   
  delay(1000);             
}
