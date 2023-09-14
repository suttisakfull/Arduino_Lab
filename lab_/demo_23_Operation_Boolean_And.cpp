#include <Arduino.h>

void setup()
{

  int A = 0;
  int B = 0;
  Serial.begin(9600); 
  
  Serial.println("===== Start Program: =======");  
  A = 20;
  B = 40;
  Serial.print("A=");
  Serial.print(A);
  Serial.print("\t");
  Serial.print("B=");
  Serial.println(B);
  Serial.println("-------------------------------");
  Serial.println(" True: 1  , False: 0 ");
  Serial.println("-------------------------------");
/*
======== AND ========
|==A==|==B==|==AND==|
|  0  |  0  |   0   |
|  0  |  1  |   0   |
|  1  |  0  |   0   |
|  1  |  1  |   1   |
---------------------
*/
  Serial.print("     ");
  Serial.print(A < 10);
  Serial.print("     &&     ");
  Serial.println(B < 30);
  Serial.print(" (");
  Serial.print(A);
  Serial.print(" < 10) && (");
  Serial.print(B );
  Serial.print(" < 30) : => " );
  Serial.println((A < 10) && (B < 30)); 
  Serial.println("-------------------------------");

  Serial.print("     ");
  Serial.print(A < 10);
  Serial.print("     &&     ");
  Serial.println(B < 50);
  Serial.print(" (");
  Serial.print(A);
  Serial.print(" < 10) && (");
  Serial.print(B );
  Serial.print(" < 50) : => " );
  Serial.println((A < 10) && (B < 50)); 
  Serial.println("-------------------------------");

  Serial.print("     ");
  Serial.print(A < 30);
  Serial.print("     &&     ");
  Serial.println(B < 20);
  Serial.print(" (");
  Serial.print(A);
  Serial.print(" < 30) && (");
  Serial.print(B );
  Serial.print(" < 20) : => " );
  Serial.println((A < 30) && (B < 20)); 
  Serial.println("-------------------------------");

    Serial.print("     ");
  Serial.print(A < 30);
  Serial.print("     &&     ");
  Serial.println(B < 50);
  Serial.print(" (");
  Serial.print(A);
  Serial.print(" < 30) && (");
  Serial.print(B );
  Serial.print(" < 50) : => " );
  Serial.println((A < 30) && (B < 50)); 
  Serial.println("-------------------------------");

  Serial.println("===== End Program: =======");
}

void loop() 
{ 
 
}