#include <Arduino.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define pin_LED 13 // DT1
#define pin_Buzzer 8

LiquidCrystal_I2C lcd(0x27, 16, 2);

int counter = 0;
int CN = 0;
int SW1 = 0;
int SW2 = 0;
byte ledState = LOW;

void IR1(void);
void IR2(void);

void setup(void)
{
  Serial.begin(9600);
  Serial.println("======= init Interrupt =======");

  lcd.init(); // initialize the lcd
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Demo_Nano, ");
  lcd.setCursor(0, 1);
  lcd.print("Counter: ");

  pinMode(pin_LED, OUTPUT);
  pinMode(pin_Buzzer, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);

  digitalWrite(pin_Buzzer, HIGH); // Buzzer OFF
  digitalWrite(pin_LED, LOW);

  attachInterrupt(digitalPinToInterrupt(2), IR1, HIGH);
  attachInterrupt(digitalPinToInterrupt(3), IR2, HIGH);
}

void loop(void)
{
  lcd.setCursor(10, 1);
  lcd.print(counter);
  counter = counter + 1;

  delay(1000);
}

void IR1(void)
{
  SW1 = digitalRead(2);
  if (SW1 == HIGH)
  {
    ledState = (ledState == HIGH) ? LOW : HIGH;
    digitalWrite(pin_LED, ledState);

    CN++;
    Serial.print("CN: ");
    Serial.print(CN);
    if(ledState == HIGH){
     Serial.println("   ON");
    }else{
     Serial.println("   OFF");
    }

    do
    {
      SW1 = digitalRead(2);
    } while (SW1 == HIGH);
  }
  delay(200);
}

void IR2(void)
{

}

/*
#include <Arduino.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

//============== Pin ===============
#define pinBuzzer 8 // DT1
#define pinSw1 2    // CLK1
#define pinSw2 3    // CLK2

#define EN_M 5 // jumper GND
#define STEP_M 6
#define DIR_M 7 // 7

#define SV 9

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display
Servo myservo;

int dir = 0;
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

  digitalWrite(EN_M, LOW); // enable  6
  pinMode(pinBuzzer, OUTPUT);
  digitalWrite(pinBuzzer, HIGH); // Buzzer off

  myservo.attach(SV);
  myservo.write(dir);
  lcd.init(); // initialize the lcd
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Hello, Arduion");
  lcd.setCursor(0, 1);
  lcd.print("Nano:");
}

void loop()
{
  SW1 = digitalRead(pinSw1);
  if (SW1 == HIGH)
  {

    myservo.write(dir);
    digitalWrite(DIR_M, HIGH); // direction 4   LEFT
    Serial.println("======= RUN LEFT =======");
    tone(pinBuzzer, 1000, 100);
    lcd.setCursor(10, 1);
    lcd.print("LEFT  ");
    for (int Index = 0; Index < 200; Index++)
    {
      digitalWrite(STEP_M, HIGH); // 5
      delayMicroseconds(500);
      // delay(100);
      digitalWrite(STEP_M, LOW); // 5
      // delay(100);
      delayMicroseconds(500);
    }
    delay(100);
  }

  SW2 = digitalRead(pinSw2);
  if (SW2 == HIGH)
  {

    myservo.write(180);
    digitalWrite(DIR_M, LOW); // direction 4   LEFT
    Serial.println("======= RUN RIGHT =======");
    tone(pinBuzzer, 2000, 100);
    lcd.setCursor(10, 1);
    lcd.print("RIGHT  ");
    for (int Index = 0; Index < 200; Index++)
    {
      digitalWrite(STEP_M, HIGH); // 5
      delayMicroseconds(500);
      // delay(100);
      digitalWrite(STEP_M, LOW); // 5
      // delay(100);
      delayMicroseconds(500);
    }
    delay(100);
  }
}

*/

/*=====================================================================*/
//   digitalWrite(DIR_M, LOW);                 // direction 4  LIGHT
//   Serial.println("======= RUN RIGHT =======");
//   tone(pinBuzzer, 1000, 100);
//   lcd.setCursor(10, 1);
//   lcd.print("RIGHT  ");
//   for (int Index = 0; Index < 300; Index++) // 400
//   {
//     digitalWrite(STEP_M, HIGH); // 5
//     delayMicroseconds(600);
//     // delay(100);
//     digitalWrite(STEP_M, LOW); // 5
//     // delay(100);
//     delayMicroseconds(600);
//   }
//   delay(1000);
// }

/*
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
// =======include========
#define pinclk 2
#define pinDT 3
#define pinPush 4
#define LED1 5
#define LED2 6
#define LED3 7
#define LED4 8
// =======object========
LiquidCrystal_I2C lcd(0x27, 20, 4);
//========global=======
int Count = 0;
int state;     // เก็บค่าการเปลี่ยนแปลง
int laststate; // เก็บค่าเริ่มต้น

int Max_Count = 4;
int Min_Count = 1;

int Value = 0;
bool Update_Node = true;
int Menu_select = 1;
int SW = 0;
bool LED_loop1 = false;
bool LED_loop2 = false;
bool LED_loop3 = false;
bool LED_loop4 = false;
//======ENCODENUM FN
// bool Num_state = false;
int Num = 100;
int NUm_Max = 10000;
int Num_Min = 100;
bool Update_Num = true;
// int num_arry[] = {10,20,30,100,250};
String Menu_List[] = {"LED1", "LED2", "LED3", "LED4"};
//========FN=========
void Push_Select(void);
void FnprintCount(void);
void EncodermenuFN(void);
void EncodeNum(void) ;

void setup()
{
  Serial.begin(9600);
  Serial.print("Working");
  lcd.init();
  lcd.backlight();
  pinMode(pinclk, INPUT);
  pinMode(pinDT, INPUT);
  pinMode(pinPush, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  laststate = digitalRead(pinclk);
  // lcd.setCursor(0, 0);
  // lcd.print("Posittion:");
}

void loop()
{
  EncodermenuFN();
  FnprintCount();
  Push_Select();

  //  Serial.print("Array :") ;
  //  Serial.println(num_arry[4]) ;

  //  while (1)
  //  {
  //  }

  // while(1){}
}

// lcd.setCursor(10,0) ;
// lcd.print( Value) ;
void Lcd_Loop(void)
{
  //================1
  lcd.setCursor(12, 0);
  if (LED_loop1 == true)
  {
    lcd.print("ON ");
    digitalWrite(LED1, HIGH);
  }
  else
  {
    digitalWrite(LED1, LOW);
    lcd.print("OFF");
  }
  //=================2
  lcd.setCursor(12, 1);
  if (LED_loop2 == true)
  {
    lcd.print("ON ");
    digitalWrite(LED2, HIGH);
  }
  else
  {
    digitalWrite(LED2, LOW);
    lcd.print("OFF");
  }
  //=================3
  lcd.setCursor(12, 2);
  if (LED_loop3 == true)
  {
    lcd.print("ON ");
    digitalWrite(LED3, HIGH);
  }
  else
  {
    digitalWrite(LED3, LOW);
    lcd.print("OFF");
  }
  //==============4
  //     lcd.setCursor(12, 3);
  // if (LED_loop4 == true)
  // {
  //   lcd.print("ON ");
  //   digitalWrite(LED4, HIGH);
  // }
  // else
  // {
  //   digitalWrite(LED4, LOW);
  //   lcd.print("OFF");
  // }
  // //=====================
}
void FnprintCount(void)
{
  if (Update_Node == true)
  {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print(Menu_List[0]);

    lcd.setCursor(2, 1);
    lcd.print(Menu_List[1]);

    lcd.setCursor(2, 2);
    lcd.print(Menu_List[2]);

    lcd.setCursor(2, 3);
    lcd.print(Menu_List[3]);

    lcd.setCursor(0, Value - 1);
    lcd.print(">");
  }
  Lcd_Loop();
  Update_Node = false;
}

// if (Value <= 9)

// {
//   // lcd.setCursor(11, 0);
//   // lcd.print(" ");
//   // lcd.setCursor(12, 0);
//   // lcd.print(Value);
// }
// else
// {

//   lcd.setCursor(11, 0);
//   lcd.print(Value);
// }A

void EncodermenuFN(void)
{
  state = digitalRead(pinclk);
  if (state != laststate)
  {
    if (digitalRead(pinDT) != state)
    {
      Count++;
      if (Count > Max_Count * 2)
      {
        Count = Max_Count * 2;
      }
    }
    else
    {
      Count--;
      if (Count < Min_Count * 2)
      {
        Count = Min_Count * 2;
      }
    }
    Serial.print("Posittion: ");
    Value = Count / 2;
    Serial.println(Value);
    Menu_select = Value;
    Update_Node = true;
  }
}
void Push_Select(void)
{
  SW = digitalRead(pinPush);
  if (SW == 0)
  {
    switch (Menu_select)
    {
    case 1:
      Serial.println("You in A");
      delay(500);
      LED_loop1 = !LED_loop1;
      Update_Node = true;
      delay(200);
      FnprintCount();
      break;

    case 2:
      Serial.println("You in B");
      delay(500);
      LED_loop2 = !LED_loop2;
      Update_Node = true;
      delay(200);
      FnprintCount();
      break;

    case 3:
      Serial.println("You in C");
      LED_loop3 = !LED_loop3;
      Update_Node = true;
      delay(500);
      break;

    case 4:
      Serial.println("You in D");
      delay(500) ;
      do
      {
        SW = digitalRead(pinPush);
        EncodeNum();
        if (Update_Num == true)
        {
          lcd.setCursor(12, 3);
          lcd.print("        ") ;
          lcd.setCursor(12, 3);
          lcd.print(Num);
          Update_Num = false;
          Serial.println("in while") ;

        }

      }
       while (SW == 1);

      Serial.println("OUT") ;
          delay(500);

      break;

    default:
      break;
    }
  }
}
void EncodeNum(void)
{
  state = digitalRead(pinclk);
  if (state != laststate)
  {
    if (digitalRead(pinDT) != state)
    {
      Num=Num+100;
      if (Num > NUm_Max)
      {
        Num = NUm_Max;
      }
    }
    else
    {
      Num=Num-100;
      if (Num < Num_Min)
      {

        Num = Num_Min;
      }
    }
    Serial.print("Num: ");
    Serial.println(Num);
    Update_Num = true;
  }
}
// void






















*/

// #include <Arduino.h>

// void setup(void)
// {
//   Serial.begin(9600);                   //กำหนดค่าสือสารข้อมูลระหว่าง Arduino กับ คอมพิวเตอร์
//   Serial.println("Hello Arduino");  //คำสั่งให้ Arduino แสดงข้อความมาทาง Serial port

// }

// void loop(void)
// {
//    if (Serial.available() > 0)         //ตรวจสอบ Serial Port ว่าพร้อมรับส่งข้อมูลหรือไม่
//    {
//       int num = Serial.parseInt();     // รับค่าตัวเลขจาก keyboard
//       Serial.println();
//       Serial.print("SEND: ");
//       Serial.println(num);              //คำสั่งให้ Arduino แสดงข้อความมาทาง Serial port

//        if (num == 99)
//       {
//          Serial.println("=Success=");
//       }

//    }
// }
