#include <Arduino.h>
int val = 0;
int dl = 0;

int led1 = 4;
int led2 = 5;
void setup() 
{
   pinMode(led1,OUTPUT);
   pinMode(5,OUTPUT);
   pinMode(A0,INPUT);
}
void loop() 
{
   val = analogRead(A0);
   dl = map(val, 0, 1023, 20, 1023);
   digitalWrite(led1 ,LOW);
   delay(dl);
   digitalWrite(led1 ,HIGH);
   delay(dl);
   digitalWrite(led2 ,LOW);
   delay(dl);
   digitalWrite(led2 ,HIGH);
   delay(dl);
}