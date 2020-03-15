#include <dht.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHT11_PIN 7


LiquidCrystal_I2C lcd(0x27, 2,1,0,4,5,6,7,3,POSITIVE);
dht DHT;
int relay1 = 11;
int but1 = 13;
int butState = 0;
int relayS = 0;
int pushed = 0; 


void setup(){
 
 pinMode(relay1, OUTPUT);
  Serial.begin(9600); 
  lcd.begin(16,2);
  lcd.clear();
  lcd.print("Temp is        C");
  lcd.setCursor ( 0, 1 );
  lcd.print("Fan status ~");
  pinMode(but1,INPUT);
  pinMode(relay1,OUTPUT);
 
}


void loop(){
butState = digitalRead(but1);
  
  if(butState == LOW && relayS == LOW){
    pushed = 1-pushed;
    delay(100);
    
  }
  relayS = butState;
 if(pushed==LOW){
  Serial.println("on");
  digitalWrite(relay1,LOW);
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor ( 9, 0 );
  lcd.print(DHT.temperature);
  lcd.setCursor ( 13, 1 );  
  delay(5000);
  
  if(DHT.temperature > 20){
          digitalWrite(relay1, LOW);
          lcd.print("ON  ");}
          
 else{
      digitalWrite(relay1, HIGH);
      lcd.print("OFF");}
  
 }
  else{
    Serial.println("off");
    digitalWrite(relay1,HIGH);
  
  }

delay(150);
}
