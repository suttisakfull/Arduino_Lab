#include <Arduino.h>

void setup() 
{
  Serial.begin(9600);
  Serial.println("-------- Start program ---------");

  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);

  digitalWrite(5,HIGH);  //LED --- OFF ---
  digitalWrite(6,HIGH);  //LED --- OFF ---
  digitalWrite(7,HIGH);  //LED --- OFF ---
 
}
void loop() 
{

     digitalWrite(5,LOW);
     digitalWrite(6,HIGH);
     digitalWrite(7,HIGH);
     delay(1000);
     digitalWrite(5,HIGH);
     digitalWrite(6,LOW);
     digitalWrite(7,HIGH);
     delay(1000);
     digitalWrite(5,HIGH);
     digitalWrite(6,HIGH);
     digitalWrite(7,LOW);
     delay(1000);
 


}

