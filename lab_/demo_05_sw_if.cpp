#include <Arduino.h>

int SW1 = 0;
int SW2 = 0;

void setup() 
{
   pinMode(8,INPUT);
   pinMode(9,INPUT);
   pinMode(5,OUTPUT);
}
void loop() 
{
   SW1 = digitalRead(8);
   SW2 = digitalRead(9);
 
   if(SW1 == HIGH)
   {
      digitalWrite(5,HIGH);
      delay(100);
   }

   if(SW2 == HIGH)
   {
      digitalWrite(5,LOW);
      delay(100);
   }
}
