#include <Arduino.h>

void (* resetFunc) (void) = 0;
void setup() 
{
  Serial.begin(9600);
  Serial.println("-------- Start program ---------");
  Serial.print("Please input number: "); 
}
void loop() 
{
  if(Serial.available() > 0)
  {
      int num = Serial.parseInt();
      Serial.println(num);
  
      Serial.print(num);
      Serial.print(" x 1 : ");
      Serial.println(num * 1);

      Serial.print(num);
      Serial.print(" x 2 : ");
      Serial.println(num * 2);

      Serial.print(num);
      Serial.print(" x 3 : ");
      Serial.println(num * 3);

      Serial.println("-------- End program ---------"); 
      resetFunc();
  }
}

