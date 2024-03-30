#include <Arduino.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//============== Pin ===============
#define pinBuzzer 8 // DT1
#define pinSw1 2    // CLK1
#define pinSw2 3    // CLK2

// #define EN_M 5   jumper GND
#define STEP_M 6
#define DIR_M 5

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

int SW1 = 0;
int SW2 = 0;
void setup()
{

  Serial.begin(9600);
  Serial.println("======= init SW1 Buzzer =======");
  pinMode(pinSw1, INPUT);
  pinMode(pinSw2, INPUT);

  // pinMode(EN_M, OUTPUT);   //   --> enable
  pinMode(STEP_M, OUTPUT); //   --> step
  pinMode(DIR_M, OUTPUT);  //   --> direction

  // digitalWrite(EN_M, LOW); // enable  6
  pinMode(pinBuzzer, OUTPUT);
  digitalWrite(pinBuzzer, HIGH); // Buzzer off

  lcd.init(); // initialize the lcd
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Hello, Arduion");
  lcd.setCursor(0, 1);
  lcd.print("Nano:");
}

void loop()
{



  digitalWrite(DIR_M, HIGH); // direction 4   LEFT
  Serial.println("======= RUN LEFT =======");
  tone(pinBuzzer, 1000, 100);
  lcd.setCursor(10, 1);
  lcd.print("LEFT  ");
  for (int Index = 0; Index < 400; Index++)
  {
    digitalWrite(STEP_M, HIGH); // 5
    delayMicroseconds(500);
    // delay(100);
    digitalWrite(STEP_M, LOW); // 5
    // delay(100);
    delayMicroseconds(500);
  }
  delay(1000);

  digitalWrite(DIR_M, LOW); // direction 4   LEFT
  Serial.println("======= RUN RIGHT =======");
  tone(pinBuzzer, 1000, 100);
  lcd.setCursor(10, 1);
  lcd.print("RIGHT  ");
  for (int Index = 0; Index < 400; Index++)
  {
    digitalWrite(STEP_M, HIGH); // 5
    delayMicroseconds(500);
    // delay(100);
    digitalWrite(STEP_M, LOW); // 5
    // delay(100);
    delayMicroseconds(500);
  }
  delay(1000);

}