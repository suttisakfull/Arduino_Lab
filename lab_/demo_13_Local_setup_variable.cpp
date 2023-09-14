#include <Arduino.h>

void setup()
{
  int num_L = 250;
  
  Serial.begin(9600);  //19200,38400,57600,115200, 
  Serial.println("======== setup: =======");
  Serial.print("show num_L: ");
  Serial.println(num_L);
  
 
}
void loop() 
{ 
  Serial.println("======== loop: =======");
  Serial.print("show num_L: ");
  //Serial.println(num_L);
  while(1){}
  
}