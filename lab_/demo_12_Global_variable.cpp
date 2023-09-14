#include <Arduino.h>
int num_G = 250;
void setup()
{

  
  Serial.begin(9600);  //19200,38400,57600,115200, 
  Serial.println("======== setup: =======");
  Serial.print("show num_G: ");
  Serial.println(num_G);
  
 
}
void loop() 
{ 
  Serial.println("======== loop: =======");
  Serial.print("show num_G: ");
  Serial.println(num_G);
  while(1){}
  
}