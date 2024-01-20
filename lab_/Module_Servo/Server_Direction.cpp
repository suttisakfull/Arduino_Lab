//============= Lib ===============
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16 ,2);
Servo myservo;
int dir = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("===== SETUP MOTOR SERVO====");

  myservo.attach(6);
  
}

void loop()
{
    Serial.print("Diriced: ");
    Serial.println(dir);
    Serial.println("-----------------------");
    myservo.write(dir);
    //=================== cal ======================
        dir = dir + 10;
    //=========================================
    if(dir > 180)
    {
      dir = 0;
    }
    delay(500);


}