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
   Start_p:
    int num = 0;
    Serial.println(" ---------- Menu ----------- ");
    Serial.println("| 1.Red                      |");
    Serial.println("| 2.Green                    |");
    Serial.println("| 3.Blue                     |");
    Serial.println("| 4.Exit                     |");
    Serial.println(" --------------------------- ");
    Serial.print("please key Again[ 1 - 4 ]:  ");
  
    do
    {
       if(Serial.available() > 0)
       {
           num  = Serial.parseInt();
           if((num == 1) || (num == 2) || (num == 3)|| (num == 4))
           {
               Serial.print("\n");
              // Serial.println("---- Key: Success -----");
           }
           else
           {
             Serial.print("\n");
             Serial.print("please key Again[ 1 - 3 ]:  ");
           }
       }
    }while((num != 1 ) && (num != 2) && (num != 3) && (num != 4));

    // Serial.println("====finish====");
    switch (num)
    {
      case 1: Serial.println("LED_red: Case 1");
              digitalWrite(5,LOW);
              digitalWrite(6,HIGH);
              digitalWrite(7,HIGH);
              break;
      case 2: Serial.println("LED_green: Case 2");  
              digitalWrite(5,HIGH);
              digitalWrite(6,LOW);
              digitalWrite(7,HIGH);
              break;
      case 3: Serial.println("LED_blue: Case 3"); 
              digitalWrite(5,HIGH);
              digitalWrite(6,HIGH);
              digitalWrite(7,LOW);
              break;
      case 4: Serial.println("Exit"); 
              while(1){};
              goto Start_p;
              break;
    
    default:
            break;
    }

   

}