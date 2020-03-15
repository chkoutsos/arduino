#include <dht.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2,1,0,4,5,6,7,3,POSITIVE);
dht DHT;

#define DHT11_PIN 7

void setup(){

  Serial.begin(9600); 
   lcd.begin(16,2);
  lcd.clear();
  lcd.print("Temp is        C");
 lcd.setCursor ( 0, 1 );
 lcd.print("Humid is       %");
 
}

void loop()
{
 
 
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  lcd.setCursor ( 9, 0 );
  lcd.print(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  lcd.setCursor ( 9, 1 );
  lcd.print(DHT.humidity);
  delay(5000);
  
  
  
}
