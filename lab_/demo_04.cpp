#include <Arduino.h>

void setup() 
{
   pinMode(4,OUTPUT);
   pinMode(5,OUTPUT);
}
void loop() 
{
   digitalWrite(4 ,LOW);
   delay(500);
   digitalWrite(4 ,HIGH);
   delay(500);
   digitalWrite(5 ,LOW);
   delay(500);
   digitalWrite(5 ,HIGH);
   delay(500);
}
