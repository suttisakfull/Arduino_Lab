#include <Arduino.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//============== Pin ===============
#define pinBuzzer 8 // DT1
#define pinSw1 2    // CLK1
#define pinSw2 3    // CLK2



LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

int SW1 = 0;
int SW2 = 0;
void setup()
{

  Serial.begin(9600);
  Serial.println("======= init SW1 Buzzer =======");
  pinMode(pinSw1, INPUT);
  pinMode(pinSw2, INPUT);


  // digitalWrite(EN_M, LOW); // enable  6
  pinMode(pinBuzzer, OUTPUT);
  digitalWrite(pinBuzzer, HIGH); // Buzzer off

  lcd.init(); // initialize the lcd
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Hello, Arduion");
  lcd.setCursor(0, 1);
  lcd.print("Nano: Buzzer");
}

void loop()
{

   SW1 = digitalRead(pinSw1);
   if (SW1 == HIGH)
   {
    /* code */
      tone(pinBuzzer, 1000, 100);
   }

      SW2 = digitalRead(pinSw2);
   if (SW2 == HIGH)
   {
    /* code */
      tone(pinBuzzer, 2000, 100);
   }
   
   


 

}