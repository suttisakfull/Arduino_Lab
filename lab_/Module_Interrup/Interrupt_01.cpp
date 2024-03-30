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
        if (ledState == HIGH)
        {
            Serial.println("   ON");
        }
        else
        {
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
