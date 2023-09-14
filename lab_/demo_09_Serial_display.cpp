#include <Arduino.h>

void setup()
{
  Serial.begin(9600);  //19200,38400,57600,115200, 
  Serial.println("Hello Arduino:");

  Serial.print("Hello Arduino: \n");
  Serial.print("abc\t");
  Serial.print("def");
  Serial.print("hij\r");
  Serial.print("klm");
  
}
void loop() 
{ 
 
}