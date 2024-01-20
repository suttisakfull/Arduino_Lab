#include <Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

//==================================
int DT1_PinA = 4;        // DT
int CLK1_PinA = 2;       // CLK
int DT1_Pos = 0;         // ค่าเริ่มต้น    
int PinA_Last1 = LOW;    // ค่าเริ่มต้น
int Encoder_1 = LOW;     // กำหนดค่า encoder_1 = 0

//==================================
int DT2_PinB = 8;        // DT
int CLK2_PinB = 7;       // CLK
int DT2_Pos = 0;         // ค่าเริ่มต้น    
int PinB_Last2 = LOW;    // ค่าเริ่มต้น
int Encoder_2 = LOW;     // กำหนดค่า encoder_2 = 0
//==================================


void setup()
{
  Serial.begin(9600);

  lcd.init();                      // initialize the lcd 
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("X = ");
  lcd.setCursor(0,1);
  lcd.print("Y = ");

  pinMode(DT1_PinA,INPUT);
  pinMode(CLK1_PinA, INPUT);

  pinMode(DT2_PinB,INPUT);
  pinMode(CLK2_PinB, INPUT);

}

void loop()
{
   Encoder_1 = digitalRead(DT1_PinA);
   if((PinA_Last1 == LOW) && (Encoder_1 == HIGH))
   {
      if(digitalRead(CLK1_PinA) == LOW){
         if(DT1_Pos >= 1)
           {
               DT1_Pos--;
           }
      }
      else
      {
        DT1_Pos++;
      }
      Serial.print("Encoder_1 =  ");
      Serial.println(DT1_Pos);
      lcd.setCursor(5, 0);
      lcd.print("      ");
      lcd.setCursor(5, 0);
      lcd.print(DT1_Pos);
   }
      PinA_Last1 = Encoder_1;

  //===========================================
   Encoder_2 = digitalRead(DT2_PinB);
   if((PinB_Last2 == LOW) && (Encoder_2 == HIGH))
   {
      if(digitalRead(CLK2_PinB) == LOW){
        DT2_Pos--;
      }
      else
      {
        DT2_Pos++;
      }
      Serial.print("Encoder_2 =  ");
      Serial.println(DT2_Pos);
      lcd.setCursor(5, 0);
      lcd.print("      ");
      lcd.setCursor(5, 0);
      lcd.print(DT2_Pos);
   }
      PinB_Last2 = Encoder_2;
}
