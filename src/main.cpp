#include <Arduino.h>
int count  = 0;
void setup() 
{
   Serial.begin(9600);
   Serial.println("========  TEST SERIAL ========");
}
void loop() 
{
  Serial.print("Demo_: ");
  Serial.println(count);
  count++;
  delay(500);
}
