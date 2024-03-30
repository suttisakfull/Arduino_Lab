//============= Lib ===============
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//============== Pin ===============
#define pinCLK 2 // DT1
#define pinDT 3  // CLK1
//============== object =============
LiquidCrystal_I2C lcd(0x27, 16, 2);
//============== gobal ==============
int counter = 0; // teller
int State;       // เก็บค่าการเปลี่ยนแปลง
int LastState;   // เก็บค่าเริ่มต้น
int Max_Counter = 2;
int Min_Counter = 1;
//int LCD_Counter = 1;

int Meun_Select = 1; // tellermenu
String Menu_List[] = {"A:", "B:"};
bool Update_Node = true;

//============== Functions ============
void EncoderMenu();
void PrintCounter();

void setup()
{
  Serial.begin(9600);
  Serial.println("===== SETUP Rotary: ===");

  pinMode(pinCLK, INPUT);
  pinMode(pinDT, INPUT);

  LastState = digitalRead(pinCLK);

  lcd.init();
  lcd.backlight();
  // lcd.setCursor(0,0);
  // lcd.print("Counter: ");
}

void loop()
{
  EncoderMenu();
  PrintCounter();
}
void PrintCounter()
{
  // lcd.setCursor(10,0);
  // lcd.print(LCD_Counter);

  if (Update_Node == true)
  {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print(Menu_List[0]);

    lcd.setCursor(2, 1);
    lcd.print(Menu_List[1]);

    lcd.setCursor(0,Meun_Select - 1);
    lcd.print(">");
    Update_Node = false;
  }
}
void EncoderMenu()
{
  State = digitalRead(pinCLK);
  if (State != LastState)
  {
    if (digitalRead(pinDT) != State)
    {
      counter++;
      if (counter > Max_Counter * 2)
      {
        counter = Max_Counter * 2;
      }
    }
    else
    {
      counter--;
      if (counter > Min_Counter * 2)
      {
        counter = Min_Counter * 2;
      }
    }
    // Serial.print("Position:  ");
    // Serial.println(counter/2);
    // LCD_Counter = counter / 2;
    // Serial.println(LCD_Counter);
    Meun_Select = counter / 2;
    Serial.println(Meun_Select);
    Update_Node = true;
  }
  LastState = State;
}