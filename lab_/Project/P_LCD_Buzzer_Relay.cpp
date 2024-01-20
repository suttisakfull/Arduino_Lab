#include <Arduino.h>
//============== include =============//
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define Load1 2
#define Load2 3
#define Load3 4
#define Load4 5
#define Buzzer 6

//============== object =============//
LiquidCrystal_I2C diskplay(0x27, 16, 2);

//=============  variable Global ========//
int num = 1;

// int A = 0;
// int B = 0;
// int C = 0;
// int D = 0;

void setup()
{

  Serial.begin(9600); // Serial Monitor

  diskplay.init();
  diskplay.backlight();

  diskplay.setCursor(0, 0);
  diskplay.print("CT:    |A:B:C:D|");

  diskplay.setCursor(0, 1);
  diskplay.print("ST:    |0:0:0:0|");

  pinMode(Load1, OUTPUT);
  pinMode(Load2, OUTPUT);
  pinMode(Load3, OUTPUT);
  pinMode(Load4, OUTPUT);
  pinMode(Buzzer, OUTPUT);

  digitalWrite(Buzzer, HIGH);
}
void loop()
{
  num = num + 1;
  diskplay.setCursor(4, 0);
  diskplay.print(num);

  switch (num)
  {
  case 10:
    diskplay.setCursor(8, 1);
    diskplay.print("1");
    diskplay.setCursor(10, 1);
    diskplay.print("0");
    diskplay.setCursor(12, 1);
    diskplay.print("0");
    diskplay.setCursor(14, 1);
    diskplay.print("0");
    digitalWrite(Load1, HIGH);
    digitalWrite(Load2, LOW);
    digitalWrite(Load3, LOW);
    digitalWrite(Load4, LOW);

    digitalWrite(Buzzer, LOW);
    delay(200);
    digitalWrite(Buzzer, HIGH);
    delay(500);
    break;
  case 20:
    diskplay.setCursor(8, 1);
    diskplay.print("0");
    diskplay.setCursor(10, 1);
    diskplay.print("1");
    diskplay.setCursor(12, 1);
    diskplay.print("0");
    diskplay.setCursor(14, 1);
    diskplay.print("0");
    digitalWrite(Load1, LOW);
    digitalWrite(Load2, HIGH);
    digitalWrite(Load3, LOW);
    digitalWrite(Load4, LOW);
    digitalWrite(Buzzer, LOW);
    delay(200);
    digitalWrite(Buzzer, HIGH);
    delay(500);
    break;
  case 30:
    diskplay.setCursor(8, 1);
    diskplay.print("0");
    diskplay.setCursor(10, 1);
    diskplay.print("0");
    diskplay.setCursor(12, 1);
    diskplay.print("1");
    diskplay.setCursor(14, 1);
    diskplay.print("0");
    digitalWrite(Load1, LOW);
    digitalWrite(Load2, LOW);
    digitalWrite(Load3, HIGH);
    digitalWrite(Load4, LOW);
    digitalWrite(Buzzer, LOW);
    delay(200);
    digitalWrite(Buzzer, HIGH);
    delay(500);
    break;
  case 40:
    diskplay.setCursor(8, 1);
    diskplay.print("0");
    diskplay.setCursor(10, 1);
    diskplay.print("0");
    diskplay.setCursor(12, 1);
    diskplay.print("0");
    diskplay.setCursor(14, 1);
    diskplay.print("1");
    digitalWrite(Load1, LOW);
    digitalWrite(Load2, LOW);
    digitalWrite(Load3, LOW);
    digitalWrite(Load4, HIGH);
    digitalWrite(Buzzer, LOW);
    delay(200);
    digitalWrite(Buzzer, HIGH);
    delay(500);
    break;
  case 50:
    num = 0;
    diskplay.setCursor(8, 1);
    diskplay.print("0");
    diskplay.setCursor(10, 1);
    diskplay.print("0");
    diskplay.setCursor(12, 1);
    diskplay.print("0");
    diskplay.setCursor(14, 1);
    diskplay.print("0");
    digitalWrite(Load1, LOW);
    digitalWrite(Load2, LOW);
    digitalWrite(Load3, LOW);
    digitalWrite(Load4, LOW);
    diskplay.setCursor(4, 0);
    diskplay.print("  ");
    digitalWrite(Buzzer, LOW);
    delay(200);
    digitalWrite(Buzzer, HIGH);
    delay(50);
    digitalWrite(Buzzer, LOW);
    delay(200);
    digitalWrite(Buzzer, HIGH);
    delay(500);
    break;

  default:
    delay(500);
    break;
  }
  /*
    if (num <= 10)
    {
      diskplay.setCursor(8, 1);
      diskplay.print("1");
      diskplay.setCursor(10, 1);
      diskplay.print("0");
      diskplay.setCursor(12, 1);
      diskplay.print("0");
      diskplay.setCursor(14, 1);
      diskplay.print("0");
      digitalWrite(Load1, HIGH);
      digitalWrite(Load2, LOW);
      digitalWrite(Load3, LOW);
      digitalWrite(Load4, LOW);

      digitalWrite(Buzzer, LOW);
      delay(200);
      digitalWrite(Buzzer, HIGH);


    }
    else if (num == 20)
    {
      diskplay.setCursor(8, 1);
      diskplay.print("0");
      diskplay.setCursor(10, 1);
      diskplay.print("1");
      diskplay.setCursor(12, 1);
      diskplay.print("0");
      diskplay.setCursor(14, 1);
      diskplay.print("0");
      digitalWrite(Load1, LOW);
      digitalWrite(Load2, HIGH);
      digitalWrite(Load3, LOW);
      digitalWrite(Load4, LOW);
      digitalWrite(Buzzer, LOW);
      delay(200);
      digitalWrite(Buzzer, HIGH);

    }
    else if (num == 30)
    {
      diskplay.setCursor(8, 1);
      diskplay.print("0");
      diskplay.setCursor(10, 1);
      diskplay.print("0");
      diskplay.setCursor(12, 1);
      diskplay.print("1");
      diskplay.setCursor(14, 1);
      diskplay.print("0");
      digitalWrite(Load1, LOW);
      digitalWrite(Load2, LOW);
      digitalWrite(Load3, HIGH);
      digitalWrite(Load4, LOW);
      digitalWrite(Buzzer, LOW);
      delay(200);
      digitalWrite(Buzzer, HIGH);
    }
    else if (num == 40)
    {
      diskplay.setCursor(8, 1);
      diskplay.print("0");
      diskplay.setCursor(10, 1);
      diskplay.print("0");
      diskplay.setCursor(12, 1);
      diskplay.print("0");
      diskplay.setCursor(14, 1);
      diskplay.print("1");
      digitalWrite(Load1, LOW);
      digitalWrite(Load2, LOW);
      digitalWrite(Load3, LOW);
      digitalWrite(Load4, HIGH);
      digitalWrite(Buzzer, LOW);
      delay(200);
      digitalWrite(Buzzer, HIGH);
    }
    else if (num > 50)
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
      digitalWrite(Load1, LOW);
      digitalWrite(Load2, LOW);
      digitalWrite(Load3, LOW);
      digitalWrite(Load4, LOW);
      diskplay.setCursor(4, 0);
      diskplay.print("  ");
      digitalWrite(Buzzer, LOW);
      delay(200);
      digitalWrite(Buzzer, HIGH);
      delay(50);
      digitalWrite(Buzzer, LOW);
      delay(200);
      digitalWrite(Buzzer, HIGH);
    }else{
       delay(500);
    }
   
  */

  
}