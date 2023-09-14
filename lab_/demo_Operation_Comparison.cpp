#include <Arduino.h>

void setup() 
{
  int A = 0;
  int B = 0;
  Serial.begin(9600); 
  
  Serial.println("===== Start Program: =======");  
  A = 20;
  B = 10;
  Serial.print("A=");
  Serial.print(A);
  Serial.print("\t");
  Serial.print("B=");
  Serial.println(B);
  Serial.println("-------------------------------");
  Serial.println(" True: 1  , False: 0 ");
  Serial.println("-------------------------------");

  Serial.print("A == B : => " ); 
  Serial.println(A == B); 
  Serial.print("A != B : => " ); 
  Serial.println(A != B);
  Serial.print("A < B  : => " ); 
  Serial.println( A < B);
  Serial.print("A > B  : => " ); 
  Serial.println( A > B);
  Serial.print("A <= B : => " ); 
  Serial.println(A <= B);
  Serial.print("A >= B : => " ); 
  Serial.println(A >= B);
  Serial.println("===== End Program: =======");
}
void loop() 
{ 

}