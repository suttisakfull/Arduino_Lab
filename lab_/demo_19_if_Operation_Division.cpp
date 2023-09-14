#include <Arduino.h>
void setup() 
{
  int A = 5; 
  float ans = 0.00;

  Serial.begin(9600); 
  Serial.println("===== Start Program: Comparsion =======");  
  if(A > 0)
  {
    ans = (A/2.0);
    Serial.print("( ");
    Serial.print(A);
    Serial.print(" ÷ 2 ) = ");
    Serial.println(ans);
  }
  Serial.println("============== End Program: ============");
}
void loop() 
{
  
}