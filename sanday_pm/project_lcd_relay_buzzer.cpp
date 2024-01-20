#include <Arduino.h>
//============== include =============//
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//============== object =============//
LiquidCrystal_I2C diskplay(0x27, 16, 2);

//=============  variable Global ========//
int num = 1;
int A = 0;
int B = 0;
int C = 0;
int D = 0;

int L1 = 5;
int L2 = 6;
int L3 = 7;
int L4 = 8;
int buzzer = 9;

void setup()
{

  Serial.begin(9600); // Serial Monitor

  diskplay.init();
  diskplay.backlight();

  diskplay.setCursor(0, 0);
  diskplay.print("CT:    |A:B:C:D|");
  diskplay.setCursor(0, 1);
  diskplay.print("ST:    |0:0:0:0|");
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(buzzer, HIGH);
}
void loop()
{
  num = num + 1;

  if (num == 10)
  {
    diskplay.setCursor(8, 1);
    diskplay.print("1");
    diskplay.setCursor(10, 1);
    diskplay.print("0");
    diskplay.setCursor(12, 1);
    diskplay.print("0");
    diskplay.setCursor(14, 1);
    diskplay.print("0");
    digitalWrite(L1, HIGH);
    digitalWrite(L2, LOW);
    digitalWrite(L3, LOW);
    digitalWrite(L4, LOW);

    digitalWrite(buzzer, LOW);
    delay(200);
    digitalWrite(buzzer, HIGH);
  }
  if (num == 20)
  {
    diskplay.setCursor(8, 1);
    diskplay.print("0");
    diskplay.setCursor(10, 1);
    diskplay.print("1");
    diskplay.setCursor(12, 1);
    diskplay.print("0");
    diskplay.setCursor(14, 1);
    diskplay.print("0");
    digitalWrite(L1, LOW);
    digitalWrite(L2, HIGH);
    digitalWrite(L3, LOW);
    digitalWrite(L4, LOW);
    digitalWrite(buzzer, LOW);
    delay(200);
    digitalWrite(buzzer, HIGH);
  }
  if (num == 30)
  {
    diskplay.setCursor(8, 1);
    diskplay.print("0");
    diskplay.setCursor(10, 1);
    diskplay.print("0");
    diskplay.setCursor(12, 1);
    diskplay.print("1");
    diskplay.setCursor(14, 1);
    diskplay.print("0");
    digitalWrite(L1, LOW);
    digitalWrite(L2, LOW);
    digitalWrite(L3, HIGH);
    digitalWrite(L4, LOW);
    digitalWrite(buzzer, LOW);
    delay(200);
    digitalWrite(buzzer, HIGH);
  }
  if (num == 40)
  {
    diskplay.setCursor(8, 1);
    diskplay.print("0");
    diskplay.setCursor(10, 1);
    diskplay.print("0");
    diskplay.setCursor(12, 1);
    diskplay.print("0");
    diskplay.setCursor(14, 1);
    diskplay.print("1");
    digitalWrite(L1, LOW);
    digitalWrite(L2, LOW);
    digitalWrite(L3, LOW);
    digitalWrite(L4, HIGH);
    digitalWrite(buzzer, LOW);
    delay(200);
    digitalWrite(buzzer, HIGH);
  }
  if (num > 50)
  {
    num = 0;
    diskplay.setCursor(8, 1);
    diskplay.print("0");
    diskplay.setCursor(10, 1);
    diskplay.print("0");
    diskplay.setCursor(12, 1);
    diskplay.print("0");
    diskplay.setCursor(14, 1);
    diskplay.print("0");
    digitalWrite(L1, LOW);
    digitalWrite(L2, LOW);
    digitalWrite(L3, LOW);
    digitalWrite(L4, LOW);
    diskplay.setCursor(4, 0);
    diskplay.print("  ");
    digitalWrite(buzzer, LOW);
    delay(200);
    digitalWrite(buzzer, HIGH);
    delay(50);
    digitalWrite(buzzer, LOW);
    delay(200);
    digitalWrite(buzzer, HIGH);
  }

  diskplay.setCursor(4, 0);
  diskplay.print(num);

  delay(500);
}