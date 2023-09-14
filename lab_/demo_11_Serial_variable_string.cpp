#include <Arduino.h>

void setup()
{
  String str1 = "Hello Arduino:";
  String str2 = "Uno";
  Serial.begin(9600);  //19200,38400,57600,115200, 
  Serial.print(str1+"\n");
  Serial.println(str1+str2);
  Serial.println(str1.substring(6,14));
  Serial.println(str1.indexOf('A'));
  Serial.println(str1.length());
}
void loop() 
{ 
 
}