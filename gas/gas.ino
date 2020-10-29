#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
LiquidCrystal_I2C lcd(0x27, 2,1,0,4,5,6,7,3,POSITIVE);

int sensorValue;

void setup(){  
  lcd.begin(16, 2);
Serial.begin(9600);                            // sets the serial port to 9600
 }
void loop(){sensorValue = analogRead(0);       // read analog input pin 0
Serial.print("AirQua=");
Serial.print(sensorValue, DEC);               // prints the value read
Serial.println(" PPM");
lcd.setCursor(0,0);
lcd.print("ArQ=");
lcd.print(sensorValue,DEC);
lcd.print(" PPM");
lcd.println("       "); 
lcd.print("  ");
delay(1000);                                   // wait 100ms for next reading
}
