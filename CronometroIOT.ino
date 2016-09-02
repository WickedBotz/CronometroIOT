#include <LiquidCrystal.h>
#include <Wire.h> 
#include "LiquidCrystal_I2C.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);
//Define os pinos que serão utilizados para ligação ao display
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
int sensorPinA0 = A0;    
int sensorPinA1 = A1;

int sensorValueA0 = 0;
int  sensorValueA1 = 0;

static unsigned long ult_tempo = 0;
boolean comecar = false;

boolean volta = true;


long seg = 0,
     minu = 0,
     hor = 0,
     mil = 0;
void setup() {
 // delay(500);
  Serial.begin(9600);
  lcd.begin();
}

void loop() {
  sensorValueA1 = analogRead(sensorPinA1);
  do
{
 if(sensorValueA1 >=30 && volta == true){
    comecarCronometro();
    comecar = true; 
    sensorValueA0 = analogRead(sensorPinA0);
   
    if(sensorValueA0 >=30){
      comecar = false;
      volta = false;
    }
  }
} while (comecar);
 

}

void comecarCronometro(){
  mil = millis();
   int tempo = millis();
  if(tempo - ult_tempo >= 1000) {
     ult_tempo = tempo;
     seg++;
}
  if(seg>=60) {
    seg = 0;
    minu++;
  }
  if(minu>=60) {
    minu = 0;
    hor++;
   }
  if(hor>=24) {
  hor=0;
  minu=0;
  }
  
  lcd.backlight();
  // define posicao statica do cursor.
  lcd.setCursor(0, 0);
  lcd.print(hor);
  lcd.print(":");
  lcd.print(minu);
  lcd.print(":");
  lcd.print(seg);
  lcd.print(":");
  mil=tempo%1000;
  lcd.println(mil);
 
  //delay(200);
}


/*
void comecarCronometro(){
  mil = millis();
   int tempo = millis();
  if(tempo - ult_tempo >= 1000) {
     ult_tempo = tempo;
     seg++;
}
if(mil>=999){
  mil =0;
}
  if(seg>=60) {
    seg = 0;
    minu++;
  }
  if(minu>=60) {
    minu = 0;
    hor++;
   }
  if(hor>=24) {
  hor=0;
  minu=0;
  }
  lcd.backlight();
  lcd.print(hor);
  lcd.print(":");
  lcd.print(minu);
  lcd.print(":");
  lcd.print(seg);
  lcd.print(":");
  lcd.println(mil);
 
  delay(200);
}
*/
