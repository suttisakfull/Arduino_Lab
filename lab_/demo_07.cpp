#include <Arduino.h>
int val = 0;
int dl = 0;
void setup() 
{
   pinMode(4,OUTPUT);
   pinMode(5,OUTPUT);
   pinMode(A0,INPUT);
}
void loop() 
{
   val = analogRead(A0);
   dl = map(val, 0, 1023, 20, 1023);
   digitalWrite(4 ,LOW);
   delay(dl);
   digitalWrite(4 ,HIGH);
   delay(dl);
   digitalWrite(5 ,LOW);
   delay(dl);
   digitalWrite(5 ,HIGH);
   delay(dl);
}