#include <Arduino.h>

void setup()
{
  Serial.begin(9600);  //19200,38400,57600,115200, 
  Serial.println("-------- Start program ---------");
  int A = 0;
 
  A = 20;
   Serial.print("A=");
  Serial.println(A);

  Serial.println("-------------------------------");
  Serial.println(" True: 1  , False: 0 ");
  Serial.println("-------------------------------");
/*
|==A==|==NOT==|
|  0  |   1   |
|  1  |   0   |
---------------
*/
  Serial.print("     ");
  Serial.println(A < 10);
  Serial.print(" (");
  Serial.print(A);
  Serial.print(" < 10) : => ");
  Serial.println((A < 10)); 

  Serial.print("!(");
  Serial.print(A);
  Serial.print(" < 10) : => ");
  Serial.println(!(A < 10)); 

 
  Serial.println("-------------------------------");

  Serial.print("     ");
  Serial.println(A < 30);
  Serial.print(" (");
  Serial.print(A);
  Serial.print(" < 30) : => ");
  Serial.println((A < 30)); 

  Serial.print("!(");
  Serial.print(A);
  Serial.print(" < 10) : => ");
  Serial.println(!(A < 30)); 
  Serial.println("-------------------------------");

  Serial.println("===== End Program: =======");
}

void loop() 
{ 
 
}