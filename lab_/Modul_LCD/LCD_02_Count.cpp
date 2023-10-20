#include <Arduino.h>

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

int num = 0;

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{

  Serial.begin(9600);              // init Serial
  lcd.init();                      // initialize the lcd 
  
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("Arduino Nano:");
  lcd.setCursor(0,1);
  lcd.print("Count: ");
 
}

void loop()
{
  num+=1;

  Serial.print("Count: ");
  Serial.println(num);

  lcd.setCursor(8,1);
  lcd.print(num);

  delay(1000);
}
