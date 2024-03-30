


//============= Lib ===============
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//============== Pin ===============
#define pinCLK 2  // DT1
#define pinDT 3   // CLK1
#define pinPush 4 // PushButton
#define LED_1 5   // LED
//============== object =============
LiquidCrystal_I2C lcd(0x27, 16, 2);
//============== gobal ==============
int Counter = 0; // teller
int State;       // เก็บค่าการเปลี่ยนแปลง
int LastState;   // เก็บค่าเริ่มต้น
int Counter_Max = 4;
int Counter_Min = 1;
// int LCD_Counter = 1;

int Menu_Select = 1; // tellermenu
String Menu_List[] = {"A:", "B:", "C:", "D:"};
String Menu_B[] = {"B1:", "B2:", "Exit"};
String Menu_D[] = {"D1:", "D2:", "Exit"};

bool B_Exit = false;
bool D_Exit = false;

bool Update_Node = true;
bool Update_Num = true;
bool LED_loop = false;
int LED_Delay = 100;

bool Num_status = false; // snelheidKiezen
int Num = 100;           // motorSnelheid
int Num_Max = 255;       // motorSnelheidMax
int Num_Min = 100;       // motorSnelheidMin

int SW = 0;

//============== Functions ============
void Encoder_Menu();
void PrintCounter();
void Push_Select();
void Encoder_Num();
//==============  Setup ===============

void setup()
{
  Serial.begin(9600);
  Serial.println("===== SETUP Rotary: ===");

  pinMode(pinCLK, INPUT);
  pinMode(pinDT, INPUT);
  pinMode(pinPush, INPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(13, OUTPUT);

  LastState = digitalRead(pinCLK);

  lcd.init();
  lcd.backlight();
  // lcd.setCursor(0,0);
  // lcd.print("Counter: ");
}

void loop()
{

  Encoder_Menu();
  PrintCounter();
  Push_Select();
}

void Push_Select()
{
  SW = digitalRead(pinPush);
  if (SW == 0)
  {
    switch (Menu_Select)
    {
    case 1:
      LED_loop = !LED_loop;
      Update_Node = true;
      delay(200);
      PrintCounter();
      break;
    case 2:
      Serial.println("===== B:Run ===== ");
      delay(200);

      do
      {

        SW = digitalRead(pinPush);
        Encoder_Num();
        if (Update_Num == true)
        {
          lcd.setCursor(12, 1);
          lcd.print(Num);
          Update_Num = false;
        }
      } while (SW == 1);
      Serial.println("========Exit :B =========");
      delay(200);


      break;

    case 3:
      Serial.println("===== C:Run ===== ");
      delay(200);

      break;
    case 4:
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print(Menu_D[0]);

      lcd.setCursor(2, 1);
      lcd.print(Menu_D[1]);

      lcd.setCursor(11, 1);
      lcd.print(Menu_D[2]);

      Menu_Select = 1;
      Serial.print("Meun: ");
      Serial.println(Menu_Select);

      lcd.setCursor(0, Menu_Select - 1);
      lcd.print(">");
      Menu_Select = 1;
      delay(1000);

      do
      {
        // Serial.print("Do Menu :");
        // Serial.println(Menu_Select);
        Encoder_Menu();
        if (Menu_Select > 2)
        {
          Menu_Select = 1;
          Serial.print("Control_Select: ");
          Serial.println(Menu_Select);
        }
        if ((Update_Node == true) && (Menu_Select <= 2))
        {
          Serial.println(" do update:");
          lcd.clear();
          lcd.setCursor(2, 0);
          lcd.print(Menu_D[0]);

          lcd.setCursor(2, 1);
          lcd.print(Menu_D[1]);

          lcd.setCursor(11, 1);
          lcd.print(Menu_D[2]);

          lcd.setCursor(0, Menu_Select - 1);
          lcd.print(">");
          Update_Node = false;
        }

        SW = digitalRead(pinPush);
        if (SW == 0)
        {
          if (Menu_Select == 1)
          {
            Serial.println("===== D1:Run ===== ");
            delay(200);
          }
          if (Menu_Select == 2)
          {
            D_Exit = true;
            Serial.print("D_Exit: ");
            Serial.println(D_Exit);
            Menu_Select = 4;
            delay(200);
          }
        }
        //(Menu_Select == 1) || (Menu_Select == 2)
      } while (!((Menu_Select > 1) && D_Exit == true));
      // Serial.println("B: Do Exit:");
      lcd.clear();
      delay(100);
      D_Exit = false;

      // Serial.print("B_Exit: ");
      // Serial.println(B_Exit);

      break;

    default:
      break;
    }

    Update_Node = true;
  }
}

void PrintCounter()
{
  // lcd.setCursor(10,0);
  // lcd.print(LCD_Counter);
  if (Update_Node == true)
  {
    if (Menu_Select <= 2)
    {

      //======= A  -  B ======
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print(Menu_List[0]);

      lcd.setCursor(2, 1);
      lcd.print(Menu_List[1]);


      lcd.setCursor(12, 1);
      lcd.print(Num);

      lcd.setCursor(0, Menu_Select - 1);
      lcd.print(">");
      //================Logic A-B ================//

      lcd.setCursor(12, 0);
      if (LED_loop == true)
      {
        lcd.print("ON ");
        digitalWrite(13, HIGH);
      }
      else
      {
        lcd.print("OFF");
        digitalWrite(13, LOW);
      }
    }
    else
    {
      //======= C  -  D ======
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print(Menu_List[2]);

      lcd.setCursor(2, 1);
      lcd.print(Menu_List[3]);

      lcd.setCursor(0, Menu_Select - 3);
      lcd.print(">");
    }

    Update_Node = false;
  }
}

void Encoder_Menu()
{
  State = digitalRead(pinCLK);
  if (State != LastState)
  {
    if (digitalRead(pinDT) != State)
    {
      Counter++;
      if (Counter > Counter_Max * 2)
      {
        Counter = Counter_Max * 2;
      }
    }
    else
    {
      Counter--;
      if (Counter < Counter_Min * 2)
      {
        Counter = Counter_Min * 2;
      }
    }
    Menu_Select = Counter / 2;
    Serial.print("Meun: ");
    Serial.println(Menu_Select);
    Update_Node = true;
  }
  LastState = State;
}

void Encoder_Num()
{
  State = digitalRead(pinCLK);
  if (State != LastState)
  {
    if (digitalRead(pinDT) != State)
    {
      Num++;
      if (Num > Num_Max)
      {
        Num = Num_Max;
      }
    }
    else
    {
      Num--;
      if (Num < Num_Min)
      {
        Num = Num_Min;
      }
    }
    Serial.print("Num: ");
    Serial.println(Num);
    Update_Num = true;
  }
  LastState = State;
}



