#include <Arduino.h>

void setup() 
{
  int ans1 = 0; int ans2 = 0; int ans3 = 0; int ans4 = 0;
  Serial.begin(9600); 
  Serial.println("===== Start Program: Arithmetic  =======");  
  ans1 = 10 * 20 + 15 / 5;
  Serial.println(" 10 * 20 + 15 / 5 = ? ");
  Serial.print("ผลลัพธ์ คือ : ");
  Serial.println(ans1);

  ans2 = 10 / 5 - 2 + 18 * 2;
  Serial.println(" 10 / 5 - 2 + 18 * 2 ");
  Serial.print("ผลลัพธ์ คือ : ");
  Serial.println(ans2);

  ans3 = 10 * (20 + 15) / 5;
  Serial.println(" 10 * (20 + 15) / 5 = ? ");
  Serial.print("ผลลัพธ์ คือ : ");
  Serial.println(ans3);

  ans4 = 10 / 5 - (2 + 18) * 2;
  Serial.println(" 10 / 5 - (2 + 18) * 2 ");
  Serial.print("ผลลัพธ์ คือ : ");
  Serial.println(ans4);
  Serial.println("============== End Program: ============");

}
void loop() 
{


}