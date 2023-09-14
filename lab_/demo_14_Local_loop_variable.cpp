#include <Arduino.h>

void setup()
{
  int num_L = 200;
  num_L = num_L + 1;
  Serial.begin(9600);  //19200,38400,57600,115200, 
  Serial.println("======== setup: =======");
  Serial.print("show num_G: ");
 // Serial.println(num_G);
  
 
}
void loop() 
{ 
  int num_L = 200;
  Serial.println("======== loop: =======");
  Serial.print("show num_G: ");
  Serial.println(num_L);
  while(1){}
  
}