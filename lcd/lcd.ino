#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#include <Wire.h> 
LiquidCrystal_I2C lcd(0x3F, 2,1,0,4,5,6,7,3,POSITIVE);

void setup() {
  lcd.begin(16,2);
  lcd.clear();
  lcd.print("good-morning ");
  lcd.setCursor ( 0, 1 );
  lcd.print("good-night");
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
