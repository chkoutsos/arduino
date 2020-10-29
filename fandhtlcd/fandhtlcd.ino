#include <dht.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <LCD.h>


#define DHT11_PIN 7


LiquidCrystal_I2C lcd(0x27, 2,1,0,4,5,6,7,3,POSITIVE);
dht DHT;
int relay1 = 11;

void setup(){
 
 pinMode(relay1, OUTPUT);
  Serial.begin(9600); 
  lcd.begin(16,2);
  lcd.clear();
  lcd.print("Temp is        C");
  lcd.setCursor ( 0, 1 );
  lcd.print("Fan status ~");
 
}

void loop()
{
 
 
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
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
