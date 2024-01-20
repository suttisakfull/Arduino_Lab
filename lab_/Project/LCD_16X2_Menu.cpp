#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
// =======include========

// =======object========
LiquidCrystal_I2C lcd(0x27, 16, 2);
//========global=======
String Str = "";

void setup()
{
  // pinMode(sw1, INPUT);

  Serial.begin(9600);
  Serial.println("Connect");
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("DEPOSIT");
  lcd.setCursor(0, 1);
  lcd.print("NEXT");

  // while (!(Str == "DOWN"))
  // {
  //   Str = Serial.readString();
  //   Str.trim();
  //   SW = digitalRead(sw1);
  // }
}

void loop()
{

  if (Serial.available() > 0)
  {
    Str = Serial.readString();
    Str.trim();
    Serial.print("\n");
    Serial.print("Str: ");
    Serial.println(Str);

    if (Str == "D")
    {
      Str = "";
      Serial.print("DOWN SENT");
      Serial.print("\n");
      lcd.setCursor(9, 0);
      lcd.print("   ");
      delay(500);
      lcd.setCursor(9, 1);
      lcd.print(" < ");
      do
      {
         lcd.setCursor(9, 1);
         lcd.print("   ");
         delay(500);
         lcd.setCursor(9, 1);
         lcd.print(" < ");
         delay(500);


        if (Serial.available() > 0)
        {
          Str = Serial.readString();
          Str.trim();
          Serial.print("\n");
          Serial.print("Str: ");
          Serial.println(Str);
        }
      } while ((Str != "U"));
      // Serial.print("\n");
      Serial.print("UP SENT");
      Serial.print("\n");
      lcd.setCursor(9, 1);
      lcd.print("   ");
      
    }
  
  }
    lcd.setCursor(9, 0);
    lcd.print("   ");
    delay(500);
    lcd.setCursor(9, 0);
    lcd.print(" < ");
    delay(500);
}