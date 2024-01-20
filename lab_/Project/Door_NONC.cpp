//============= Lib ===============
#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//============== object =============//
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;
int dir_set = 6;
int Open = 100;
int SW1 = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("===== SETUP MOTOR SERVO====");
  pinMode(8, INPUT);
  pinMode(7, OUTPUT);

  pinMode(6, OUTPUT); // B
  pinMode(5, OUTPUT); // G
  pinMode(4, OUTPUT); // R

  digitalWrite(7, HIGH);
  digitalWrite(6, LOW); // OFF
  digitalWrite(5, LOW); // OFF
  digitalWrite(4, LOW); // OFF

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  // lcd.print("Demo_GOLF:");
  lcd.print("Status:");
  myservo.attach(9);

  lcd.setCursor(0, 1);
  lcd.print("Direct :");

  myservo.write(dir_set);
  lcd.setCursor(9, 1);
  lcd.print(dir_set);
}

void loop()
{
  // Serial.print("Diriced: ");
  // Serial.println(dir);
  // Serial.println("-----------------------");
  SW1 = digitalRead(8);
  if (SW1 == HIGH)
  {
    //=====  Buzzer ===
    digitalWrite(7, LOW);
    delay(80);
    digitalWrite(7, HIGH);
    delay(50);
    digitalWrite(7, LOW);
    delay(80);
    digitalWrite(7, HIGH);
    //===== LED =====
    digitalWrite(4, LOW);  // OFF
    digitalWrite(5, HIGH); // ON
    while (SW1 == HIGH)
    {
      SW1 = digitalRead(8);
      myservo.write(dir_set + Open);
      lcd.setCursor(9, 1);
      lcd.print(dir_set + Open);
      lcd.setCursor(9, 0);
      lcd.print("OPEN ");
    }
  }
  else
  {
    lcd.setCursor(9, 1);
    lcd.print("    ");
    //===== LED =====
    digitalWrite(4, HIGH); // ON
    digitalWrite(5, LOW);  // OFF
    myservo.write(dir_set);
    lcd.setCursor(9, 1);
    lcd.print(dir_set);
    lcd.setCursor(9, 0);
    lcd.print("CLOSE");
  }

  // myservo.write(dir);
  // //=================== cal ======================
  //     dir = dir + 10;
  // //=========================================
  // if(dir > 180)
  // {
  //   dir = 0;
  // }
}
