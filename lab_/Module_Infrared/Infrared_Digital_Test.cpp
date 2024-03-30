
//============= Lib ===============
#include <Arduino.h>

//============== Pin ===============
#define pin_Sensor_1 5  // DT1

int SN_1 = 0;
int counter = 0;
void setup()
{
  Serial.begin(9600);
  Serial.println("===== SETUP Infared: ===");

  pinMode(pin_Sensor_1, INPUT);
  
}

void loop()
{

      SN_1 = digitalRead(pin_Sensor_1);

    if (SN_1 == LOW)
    {
       counter++;
        Serial.print("Counter:  ");
        Serial.println(counter);
        do
        {
          SN_1 = digitalRead(pin_Sensor_1);
        } while (SN_1 == LOW);

       
    }
    delay(200);
 
}

