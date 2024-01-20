#include <Arduino.h>

int val = 0;
int dl  = 0;

void setup() 
{
  Serial.begin(9600);

  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);

}

void loop() 
{
  val = analogRead(A0);
  dl = map(val,  0,1023,  50,800);
  Serial.print("val: ");
  Serial.println(dl);

  digitalWrite(5,HIGH);
  delay(dl);
  digitalWrite(5,LOW);
  delay(dl);

  digitalWrite(6,HIGH);
  delay(dl);
  digitalWrite(6,LOW);
  delay(dl);

  digitalWrite(7,HIGH);
  delay(dl);
  digitalWrite(7,LOW);
  delay(dl);


}
