#include <Arduino.h>

void setup()
{
  Serial.begin(9600);  //19200,38400,57600,115200, 
  Serial.println("-------- Start program ---------");

  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);

  digitalWrite(5,HIGH);  //LED --- OFF ---
  digitalWrite(6,HIGH);  //LED --- OFF ---
  digitalWrite(7,HIGH);  //LED --- OFF ---
}

void loop() 
{ 
  if(Serial.available() > 0)
  {
    String val = Serial.readString();
    val.trim();
    if((val =="red")||(val =="green")||(val =="blue"))
    {
        if(val=="red")
          {
          Serial.println("LED_red: ON");
          digitalWrite(5,LOW);
          digitalWrite(6,HIGH);
          digitalWrite(7,HIGH);
          }  
        else if(val == "green")
         {
          Serial.println("LED_green: ON");  
          digitalWrite(5,HIGH);
          digitalWrite(6,LOW);
          digitalWrite(7,HIGH);   
         }
        else if(val == "blue")
        {
          Serial.println("LED_blue: ON"); 
          digitalWrite(5,HIGH);
          digitalWrite(6,HIGH);
          digitalWrite(7,LOW);
        }
    }
    else
    {
         digitalWrite(5,HIGH);
         digitalWrite(6,HIGH);
         digitalWrite(7,HIGH);
         Serial.println("========= don't key =======");
    }
  }
}