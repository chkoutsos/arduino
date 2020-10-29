#include <LCD.h>
#include <dht.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
LiquidCrystal_I2C lcd(0x27, 2,1,0,4,5,6,7,3,POSITIVE);
dht DHT;

#define DHT11_PIN 7
int sensorValue;

void setup(){  
  Serial.begin(9600);                        
   lcd.begin(16,2); 
  
 }
 
void loop(){
   int chk = DHT.read11(DHT11_PIN);
  sensorValue = analogRead(0);       // read analog input pin 0
  Serial.print("AirQua=");
  Serial.print(sensorValue, DEC);               // prints the value read
  Serial.println(" PPM");
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  
  lcd.setCursor(0,0);
  lcd.print("Air ");
  lcd.print(sensorValue,DEC);
  lcd.print(" PPM ");
  lcd.setCursor (0,1);
  lcd.print("Temperature ");
  lcd.print(DHT.temperature);
  lcd.print(" C ");
  lcd.setCursor (21,1);
  lcd.print("Humidity ");
  lcd.print(DHT.humidity);
  lcd.print(" %");
  lcd.scrollDisplayLeft();
   
delay(1000);                                  
}
