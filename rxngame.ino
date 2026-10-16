#include<LiquidCrystal_I2C.h>
#include<limits.h>
LiquidCrystal_I2C lcd(0x27,16,2);
unsigned long x;
int but=3;
int red=7;
unsigned long arr[3];
int green=8;
void setup(){
  lcd.backlight();
  lcd.init();
  Serial.begin(9600);
  pinMode(but,INPUT_PULLUP);
  pinMode(green,OUTPUT);
  pinMode(red,OUTPUT);

}

void getrxntime(){
  int i=0;
  while(i<3){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("wait");
    delay(100);
    digitalWrite(green,LOW);
    digitalWrite(red,LOW);
    bool check=false;
    x=random(1000,10000);
    unsigned long temp=millis();
    while(millis()-temp<x){
      if(digitalRead(but)==LOW){
        digitalWrite(red,HIGH);
        while(digitalRead(but)==LOW){
          digitalRead(but);
        }
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("too early");
        delay(500);
        check=true;
        break;
      }
    }
    if(check){
      continue;
    }
    lcd.clear();
    lcd.print("press");
    unsigned long begin=millis();
    while(1){
      if(digitalRead(but)==LOW){
        digitalWrite(green,HIGH);
         arr[i++]=millis()-begin;
        while(digitalRead(but)==LOW){
          digitalRead(but);
        }
        
        break;
      }
    }
  }
   unsigned long min=arr[0];
  unsigned long max=arr[0];
  for(int j=0;j<3;j++){
    if(arr[j]<min){
      min=arr[j];
    }
    if(arr[j]>max){
      max=arr[j];
    }
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("best:");
  lcd.print(min);
  lcd.setCursor(0,1);
    lcd.print("worst:");
  lcd.print(max);
 
  delay(2000);
}
  

void loop(){
  getrxntime();
}
