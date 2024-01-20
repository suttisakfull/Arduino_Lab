

//============= Lib ===============
#include <Arduino.h>

#define in_1 2
#define pwm1 3
#define in_2 4
#define pwm2 5
/*
   Forward
   100%  =>   255   
    75%  =>   191  
    50%  =>   127   
    25%  =>   64    
      0  =>   0
   Reward
     0%  =>   255   
    25%  =>   191  
    50%  =>   127   
    75%  =>   64    
   100%  =>   0

*/

void setup()
{
  Serial.begin(9600);
  Serial.println("===== SETUP MOTOR====");
 
  pinMode(in_1,OUTPUT);
  pinMode(pwm1,OUTPUT);
  pinMode(in_2,OUTPUT);
  pinMode(pwm2,OUTPUT);

  Serial.println("==== Forward 0% :0  M1 STOP: ====");
  digitalWrite(pwm1, HIGH);
  analogWrite(pwm1,0);
  digitalWrite(in_1,LOW);
  delay(2000);

  Serial.println("==== Ready M1 : ====");
  delay(2000);
  
}

void loop()
{
    //=========================== Forward ===================================//
    Serial.println("==== Forword 100% :255   ====");
    digitalWrite(pwm1, HIGH);
    analogWrite(pwm1,255);
    digitalWrite(in_1,LOW);
    delay(2000);

    Serial.println("==== Forward 75% :191  ====");
    digitalWrite(pwm1, HIGH);
    analogWrite(pwm1,191);
    digitalWrite(in_1,LOW);
    delay(2000);

    Serial.println("==== Forward 50% :127  ====");
    digitalWrite(pwm1, HIGH);
    analogWrite(pwm1,127);
    digitalWrite(in_1,LOW);
    delay(2000);

    Serial.println("==== Forward 25% :64  ====");
    digitalWrite(pwm1, HIGH);
    analogWrite(pwm1,64);
    digitalWrite(in_1,LOW);
    delay(2000);

    Serial.println("==== Forward 0% :0  ====");
    digitalWrite(pwm1, HIGH);
    analogWrite(pwm1,0);
    digitalWrite(in_1,LOW);
    delay(2000);
   //=========================== Reward ===================================//
    Serial.println("==== Reward 100% :0 ====");
    digitalWrite(pwm1, LOW);
    analogWrite(pwm1, 0);
    digitalWrite(in_1,HIGH);
    delay(2000);

    Serial.println("==== Reward 75% :64 ====");
    digitalWrite(pwm1, LOW);
    analogWrite(pwm1, 64);
    digitalWrite(in_1,HIGH);
    delay(2000);

    Serial.println("==== Reward 50% :127 ====");
    digitalWrite(pwm1, LOW);
    analogWrite(pwm1, 127);
    digitalWrite(in_1,HIGH);
    delay(2000);

    Serial.println("==== Reward 25% :191 ====");
    digitalWrite(pwm1, LOW);
    analogWrite(pwm1, 191);
    digitalWrite(in_1,HIGH);
    delay(2000);

    
    Serial.println("==== Reward 0% :255 ====");
    digitalWrite(pwm1, LOW);
    analogWrite(pwm1, 255);
    digitalWrite(in_1,HIGH);
    delay(2000);

}
