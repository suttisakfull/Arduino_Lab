//============= Lib ===============
#include <Arduino.h>
#include <Wire.h>
//#include <LiquidCrystal_I2C.h>

//============== Pin ===============
#define pinCLK 2  //DT1
#define pinDT 3  //CLK1
//============== object =============
//LiquidCrystal_I2C lcd(0x27, 16, 2);
//============== gobal ==============
int counter = 0;
int State;            // เก็บค่าการเปลี่ยนแปลง
int LastState;        // เก็บค่าเริ่มต้น
int Max_Counter = 4;
int Min_Counter = 1;

void setup()
{
  Serial.begin(9600);
  Serial.println("===== SETUP Rotary: ===");

  pinMode(pinCLK,INPUT);
  pinMode(pinDT,INPUT);

  LastState = digitalRead(pinCLK);

  
}

void loop()
{
   State = digitalRead(pinCLK);
   if(State != LastState)
   {
    if(digitalRead(pinDT) != State)
    {
       counter ++;
       if(counter > Max_Counter * 2)
       {
        counter = Max_Counter * 2;
       }
    }
    else
    {
       counter --;
       if(counter > Min_Counter * 2)
       {
        counter = Min_Counter * 2;
       }
    }
    Serial.print("Position:  ");
    Serial.println(counter/2);
   }
   LastState = State;
}
