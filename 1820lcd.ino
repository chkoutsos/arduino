#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>

#define ONE_WIRE_BUS 4

LiquidCrystal_I2C lcd(0x27, 2,1,0,4,5,6,7,3,POSITIVE);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);



void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
  lcd.print("Temp is        C");
  sensors.begin();
}

void loop() {
   sensors.requestTemperatures();
   Serial.print("Temperature is: ");
   lcd.setCursor ( 9, 0 );
   lcd.print(sensors.getTempCByIndex(0));
   
  Serial.println(sensors.getTempCByIndex(0));
delay(1000);
}
