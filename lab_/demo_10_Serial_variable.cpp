#include <Arduino.h>

void setup()
{
  int num = 250;
  float pi = 3.14;
  char ch = 'A';
  String str = "Hello Arduino:";
  bool state = true;

  Serial.begin(9600);  //19200,38400,57600,115200, 
  Serial.println("======== Start Program: =======");
  Serial.println(num);
  Serial.println(pi);
  Serial.println(ch);
  Serial.println(str);
  Serial.println(state);
   Serial.println("======== End Program: =======");
}
void loop() 
{ 
 
}