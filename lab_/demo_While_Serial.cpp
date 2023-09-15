#include <Arduino.h>
int count  = 0;
int SW = 0;
String Str="";

void setup() 
{
   Serial.begin(9600);
   Serial.println("========  TEST SERIAL:: ========");
   pinMode(2,INPUT);
   
   while(!( Str == "start"|| (SW == HIGH)))
   {
        Str = Serial.readString();
        Str.trim();
        SW = digitalRead(2);
      //  Serial.println(SW);
   }
}
void loop() 
{
  Serial.print("Demo_: ");
  Serial.println(count);
  count++;
  delay(500);
}
