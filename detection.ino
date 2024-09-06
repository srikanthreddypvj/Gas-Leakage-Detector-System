#include <LiquidCrystal.h> 
int rs=7; 
int en=8; 
int d4=9; 
int d5=10; 
int d6=11; 
int d7=12; 
int buzz = 13; 
int gaspin = A0; 
int gasval; 
LiquidCrystal lcd(rs,en,d4,d5,d6,d7); 
void setup() 
{ 
  lcd.begin(16,2); 
  pinMode(buzz,OUTPUT); 
  pinMode(gaspin,INPUT); 
  Serial.begin(9600); 
} 
void loop() 
{ 
  lcd.setCursor(0,0); 
  gasval = (digitalRead(gaspin)); 
  if(gasval==1)
  { 
    lcd.print("Gas Leak"); 
    lcd.clear(); 
    Serial.println("Gas Leak"); 
    delay(2000); 
    digitalWrite(buzz,HIGH);
    delay(500); 
    digitalWrite(buzz,LOW); 
    } 
    else if(gasval==0)
    { 
      lcd.print("No gas detected"); 
      lcd.clear(); 
      Serial.println("no gas"); 
      delay(2000); 
    }  
}