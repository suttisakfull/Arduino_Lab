#include <Arduino.h>
void setup()
{
  pinMode(2,OUTPUT);  //A
  pinMode(3,OUTPUT);  //B
  pinMode(4,OUTPUT);  //C
  pinMode(5,OUTPUT);  //D
  pinMode(6,OUTPUT);  //E
  pinMode(7,OUTPUT);  //F
  pinMode(8,OUTPUT);  //G
  
  // LOW  => ON
  // HIGH => OFF
  
   //0
  digitalWrite(2, LOW);   //A
  digitalWrite(3, LOW);   //B
  digitalWrite(4, LOW);   //C
  digitalWrite(5, LOW);   //D
  digitalWrite(6, LOW);   //E
  digitalWrite(7, LOW);   //F
  digitalWrite(8, HIGH);   //G
  
  delay(500);
  //1
  digitalWrite(2, HIGH);  //A
  digitalWrite(3, LOW);   //B
  digitalWrite(4, LOW);   //C
  digitalWrite(5, HIGH);  //D
  digitalWrite(6, HIGH);  //E
  digitalWrite(7, HIGH);  //F
  digitalWrite(8, HIGH);  //G
  
  delay(500);
  //2
  digitalWrite(2, LOW);  
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  
  delay(500);
  //3
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  
  delay(500);
  //4
  digitalWrite(2, HIGH);   //A
  digitalWrite(3, LOW);   //B
  digitalWrite(4, LOW);   //C
  digitalWrite(5, HIGH);   //D
  digitalWrite(6, HIGH);  //E
  digitalWrite(7, LOW);  //F
  digitalWrite(8, LOW);   //G
  
  delay(500); 
  //5
  digitalWrite(2, LOW);   //A
  digitalWrite(3, HIGH);   //B
  digitalWrite(4, LOW);   //C
  digitalWrite(5, LOW);   //D
  digitalWrite(6, HIGH);  //E
  digitalWrite(7, LOW);   //F
  digitalWrite(8, LOW);   //G
  
   delay(500);
  //6
  digitalWrite(2, LOW);   //A
  digitalWrite(3, HIGH);   //B
  digitalWrite(4, LOW);   //C
  digitalWrite(5, LOW);   //D
  digitalWrite(6, LOW);   //E
  digitalWrite(7, LOW);   //F
  digitalWrite(8, LOW);   //G
  
  delay(500);
  //7
  digitalWrite(2, LOW);   //A
  digitalWrite(3, LOW);   //B
  digitalWrite(4, LOW);   //C
  digitalWrite(5, HIGH);   //D
  digitalWrite(6, HIGH);   //E
  digitalWrite(7, HIGH);   //F
  digitalWrite(8, HIGH);   //G
  
  delay(500);  
  //8
  digitalWrite(2, LOW);   //A
  digitalWrite(3, LOW);   //B
  digitalWrite(4, LOW);   //C
  digitalWrite(5, LOW);   //D
  digitalWrite(6, LOW);   //E
  digitalWrite(7, LOW);   //F
  digitalWrite(8, LOW);   //G
  
  delay(500);
  //9
  digitalWrite(2, LOW);   //A
  digitalWrite(3, LOW);   //B
  digitalWrite(4, LOW);   //C
  digitalWrite(5, LOW);   //D
  digitalWrite(6, HIGH);  //E
  digitalWrite(7, LOW);   //F
  digitalWrite(8, LOW);   //G

}

void loop()
{
 
}